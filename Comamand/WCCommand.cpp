#include "WCCommand.h"


WCCommand::WCCommand() {
	counters["-w"] = make_unique<WordCounter>();
	counters["-c"] = make_unique<CharCounter>();
}



void WCCommand::Execute(const string& params, bool last) {
	string opt;
	if (!check(params, opt)) return;
	string s = "";
	if (params.size() > 2)
		s = params.substr(3);
	this->Set(s);

	CollectString();

	size_t x = counters[opt]->count(this->Argument());

	this->Argument() = to_string(x);

	end(last);
}

bool WCCommand::check(const string& params, string& opt) {
	if (params.size() < 2) {
		cerr << "Missing options" << endl;
		return 0;
	}

	opt = params.substr(0, 2);
	if (counters.find(opt) != counters.end()) {
		return 1;
	}
	else {
		cerr << "Not supported option" << endl;
		return 0;
	}
}
