#include "WCCommand.h"


WCCommand::WCCommand() {
	counters["-w"] = make_unique<WordCounter>();
	counters["-c"] = make_unique<CharCounter>();
}


void WCCommand::execute(const string& args, bool last) {
	if (args.size() < 2) {
		cerr << "Missing options" << endl;
		return;
	}

	string opt = args.substr(0, 2);
	if (counters.find(opt) != counters.end()) {
		options = counters[opt];
	}
	else{
		cerr << "Not supported option" << endl;
		return;
	}

	string s = "";
	if (args.size() > 2)
		s = args.substr(3);
	this->set(s);
	
	int x = 0;
	if (reader) {
		if (test_input()) return;
		string s;
		while (!reader->endOfRead() && (s = reader->getNextLine()).size() != 0) {
			x += options->count(s);
		}
	}
	else{
		x = counters[opt]->count(this->Argument());
	}

	this->Argument() = to_string(x);

	end(last);
}
