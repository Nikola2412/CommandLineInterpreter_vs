#include "WCCommand.h"


WCCommand::WCCommand() {
	counters["-w"] = make_unique<WordCounter>();
	counters["-c"] = make_unique<CharCounter>();
}



void WCCommand::Execute(const string& params) {
	string opt;
	if (!check(params, opt)) return;
	string s = "";
	if (params.size() > 2)
		s = params.substr(3);
	this->Set(s);

	if(!CollectString()) return;

	size_t x = counters[opt]->count(this->Argument());

	this->Argument() = to_string(x);
}

void WCCommand::Helper()
{
	CommandHelper h;
	h.WCHelper();
}

bool WCCommand::check(const string& params, string& opt) {
	if (params.size() < 2) {
		this->Error("Option error");
		return 0;
	}

	opt = params.substr(0, 2);
	if (counters.find(opt) != counters.end()) {
		return 1;
	}
	else {
		this->Error("Option error");
		return 0;
	}
}
