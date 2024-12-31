#include "WCCommand.h"


WCCommand::WCCommand() {
	counters["-w"] = make_unique<WordCounter>();
	counters["-c"] = make_unique<CharCounter>();
}


void WCCommand::execute(const string& parms, bool last) {
	string opt;
	if (!check(parms,opt)) return;
	string s = "";
	if (parms.size() > 2)
		s = parms.substr(3);
	this->set(s);
	
	int x = 0;
	if (reader) {
		if (test_input()) return;
		string s;
		while (!reader->endOfRead()) {
			s = reader->getNextLine();
			x += options->count(s);
		}
	}
	else{
		x = counters[opt]->count(this->Argument());
	}

	this->Argument() = to_string(x);

	end(last);
}

void WCCommand::executeBatch(const string& parms, bool last, Reader* r)
{
	this->reader = r;
	string opt;
	if (!check(parms,opt)) return;

	string s = "";
	if (parms.size() > 2)
		s = parms.substr(3);
	this->set(s);

	int x = 0;
	if (reader) {
		string s;
		while (!reader->endOfRead()) {
			s = reader->getNextLine();
			if ("EOF" == s) break;
			x += options->count(s);
		}
	}
	else {
		x = counters[opt]->count(this->Argument());
	}

	this->Argument() = to_string(x);

	end(last);
}

bool WCCommand::check(const string& parms,string &opt){
	if (parms.size() < 2) {
		cerr << "Missing options" << endl;
		return 0;
	}

	opt = parms.substr(0, 2);
	if (counters.find(opt) != counters.end()) {
		options = counters[opt];
	}
	else {
		cerr << "Not supported option" << endl;
		return 0;
	}
}
