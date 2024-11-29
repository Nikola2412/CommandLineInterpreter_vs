#include "WCCommand.h"


WCCommand::WCCommand() {
	counters["-w"] = make_unique<WordCounter>();
	counters["-c"] = make_unique<CharCounter>();
}

WCCommand::~WCCommand() {}

void WCCommand::execute(const string& args) {
	if (args.size() < 1) {
		cerr << "Missing options" << endl;
		return;
	}

	string opt = args.substr(0, 2);
	if (counters.find(opt) != counters.end()) {
		options = counters[opt];
	}
	
	//if (this->Argument().size() == 0) {
	string s = "";
	if (args.size() > 2)
		s = args.substr(3);
	this->set(s);
	//}

	if (dynamic_cast<ConsoleReader*>(reader)) {
		MultipleLines();
		return;
	}
	if (dynamic_cast<FileReader*>(reader)) {
		FileInput();
		return;
	}
	int x = counters[opt]->count(this->Argument());
	writer->writeLine(to_string(x));
	
}


void WCCommand::MultipleLines() {
	string s;
	int x = 0;
	while (!reader->endOfRead() && (s = reader->getNextLine()).size() != 0) {
		x += options->count(s);
	}
	writer->writeLine(to_string(x));
}

void WCCommand::FileInput() {
	string s;
	int x = 0;
	while (!reader->endOfRead() && (s = reader->getNextLine()).size() != 0) {
		x += options->count(s);
	}
	writer->writeLine(to_string(x));
}

