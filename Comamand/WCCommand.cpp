#include "WCCommand.h"


WCCommand::WCCommand() {
	counters["-w"] = make_unique<WordCounter>();
	counters["-c"] = make_unique<CharCounter>();
	counters["-l"] = make_unique<LineCounter>();
}

WCCommand::~WCCommand(){}

void WCCommand::execute(const string& args, string& input) {
	//this->test() = "dasdasd";
	bool world = false;
	bool character = false;
	//string c = "-c";
	//cout << counters[c]->count("das as da sd") << endl;
	//return;
	if (args.size() < 1) {
		cerr << "u stupid" << "\n";
		return;
	}
	string opt = args.substr(0, 2);
	if (args.size() < 3) {
		MultipleLines(opt);
		return;
	}
	size_t pos1 = args.find('"');
	size_t x = 0;
	if (pos1 != string::npos){
		size_t pos2 = args.find('"',pos1 + 1);
		if (opt == "-w") x = WorldCount(args.substr(pos1 + 1, pos2 - pos1 - 1));
		else if (opt == "-c") x = CharacterCount(args.substr(pos1 + 1, pos2 - pos1 - 1));
		else cerr << "Error" << endl;
	}
	else {
		//fajl
		cout << "Fajl" << endl;
	}
	cout << x << endl;
}


void WCCommand::MultipleLines(const string& opt){
	//string str;
	//while ((str = getCommandLine()).size() != 0) {
	//	if (opt == "-w") cout << WorldCount(str) << endl;
	//	else if (opt == "-c") cout << CharacterCount(str) << endl;
	//}
	reader = new CommandReader();
	string s;
	while (!reader->endOfRead() && (s = reader->getNextLine()).size() != 0) {
		if (opt == "-w") cout << WorldCount(s) << endl;
		else if (opt == "-c") cout << CharacterCount(s) << endl;
	}
}

size_t WCCommand::WorldCount(const string& input){
	int x = 0;
	istringstream stream(input);
	string token;
	while (stream >> token) {
		x++;
	}
	return x;
}

size_t WCCommand::CharacterCount(const string& input){
	return input.size();
}

