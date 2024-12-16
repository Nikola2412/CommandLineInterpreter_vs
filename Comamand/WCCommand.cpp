#include "WCCommand.h"


WCCommand::WCCommand() {
	counters["-w"] = make_unique<WordCounter>();
	counters["-c"] = make_unique<CharCounter>();
}

WCCommand::~WCCommand() {}

void WCCommand::execute(const string& args, bool last) {
	//cout << last << endl;
	if (args.size() < 2) {
		cerr << "Missing options" << endl;
		return;
	}

	string opt = args.substr(0, 2);
	if (counters.find(opt) != counters.end()) {
		options = counters[opt];
	}

	string s = "";
	if (args.size() > 2)
		s = args.substr(3);
	this->set(s);
	

	if (reader) {
		Input();
		return;
	}

	int x = counters[opt]->count(this->Argument());
	this->Argument() = to_string(x);
	end(last);
}

void WCCommand::Input() {
	string s;
	int x = 0;
	while (!reader->endOfRead() && (s = reader->getNextLine()).size() != 0) {
		x += options->count(s);
	}
	writer->writeLine(to_string(x));
}
