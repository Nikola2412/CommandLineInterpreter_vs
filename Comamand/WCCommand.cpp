#include "WCCommand.h"


void WCCommand::execute(const string& args, string& input) {
	bool world = false;
	bool character = false;
	
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
	string str;
	while ((str = getCommandLine()).size() != 0) {
		if (opt == "-w") cout << WorldCount(str) << endl;
		else if (opt == "-c") cout << CharacterCount(str) << endl;
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

//#include <fstream>
//void WCCommand::WorldCount(const std::vector<std::string>& args) {
//	std::string input, output;
//
//	size_t cnt = 0;
//	bool to_count = false;
//	char c = args[0][0];
//
//	if (c != '"') {
//		if (c == '<') {
//			input = args[1];
//		}
//		else {
//			input = args[0];
//		}
//		std::ifstream inFile(input);
//		if (!inFile) {
//			std::cerr << "Error - file not found " << input << std::endl;
//			return;
//		}
//		std::string word;
//		while (inFile >> word) {
//			++cnt;
//		}
//		inFile.clear();
//		inFile.seekg(0);
//
//	}else{
//		for (auto x : args) {
//			++cnt;
//			if (x[x.size() - 1] == '"') break;
//		}
//		if (args[0][args[0].size() - 1] == '"' && args[0].size() - 1 == 1) cnt--;
//	}
//
//	if (args[args.size() - 2] == ">") {
//		output = args[args.size() - 1];
//		std::ofstream outFile(output);
//		if (!outFile) {
//			std::cerr << "Error - file not found " << output << std::endl;
//			return;
//		}
//		outFile << cnt<<"\n";
//	}
//	else
//	{
//		std::cout << cnt<<"\n";
//	}
//}
//
//void WCCommand::CharacterCount(const std::vector<std::string>& args) {
//	std::string input, output;
//
//	size_t cnt = -2;
//	bool to_count = false;
//	char c = args[0][0];
//
//	if (c != '"') {
//		if (c == '<') {
//			input = args[1];
//		}
//		else {
//			input = args[0];
//		}
//		std::ifstream inFile(input);
//		if (!inFile) {
//			std::cerr << "Error: Could not open input file " << input << std::endl;
//			return;
//		}
//		std::string word;
//		while (inFile >> word) {
//			cnt += word.size();
//		}
//		inFile.clear();
//		inFile.seekg(0);
//	}
//	else {
//		for (auto x : args) {
//			cnt += x.size();
//			if (x[x.size() - 1] == '"') break;
//		}
//	}
//
//	if (args[args.size() - 2] == ">") {
//		output = args[args.size() - 1];
//		std::ofstream outFile(output);
//		if (!outFile) {
//			std::cerr << "Error: Could not open output file " << output << std::endl;
//			return;
//		}
//		outFile << cnt << "\n";
//	}
//	else
//	{
//		std::cout << cnt << "\n";
//	}
//}