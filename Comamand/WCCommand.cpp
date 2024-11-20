#include "WCCommand.h"


WCCommand::WCCommand() {
	counters["-w"] = make_unique<WordCounter>();
	counters["-c"] = make_unique<CharCounter>();
}

WCCommand::~WCCommand(){}

void WCCommand::execute(const string& args, string& input) {
	//this->test() = "dasdasd";
	if (args.size() < 1) {
		cerr << "Missing options" << endl;
		return;
	}

	string opt = args.substr(0, 2);
	if (counters.find(opt) != counters.end()) {
		options = move(counters[opt]);
	}
	else {
		cerr << "Unknown options: " << opt << endl;
		return;
	}


	if (args.size() < 3) {
		MultipleLines(opt);
		return;
	}
	size_t pos1 = args.find('"');
	if (pos1 != string::npos){
		size_t pos2 = args.find('"',pos1 + 1);
		cout << options->count(args.substr(pos1 + 1, pos2 - pos1 - 1)) << endl;
	}
	else {
		FileInput("input.txt");
		//cout << "Fajl" << endl;
	}
}


void WCCommand::MultipleLines(const string& opt) {
	reader = new CommandReader();
	string s;
	while (!reader->endOfRead() && (s = reader->getNextLine()).size() != 0) {
		cout << options->count(s) << endl;
	}
}

void WCCommand::FileInput(const string& input) {
	reader = new FileReader(input);
	string s;
	int x = 0;
	while (!reader->endOfRead() && (s = reader->getNextLine()).size() != 0) {
		x += options->count(s);
	}
	cout << x << endl;
}

//size_t WCCommand::WorldCount(const string& input){
//	int x = 0;
//	istringstream stream(input);
//	string token;
//	while (stream >> token) {
//		x++;
//	}
//	return x;
//}
//
//size_t WCCommand::CharacterCount(const string& input){
//	return input.size();
//}

