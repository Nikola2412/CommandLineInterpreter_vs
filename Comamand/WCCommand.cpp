#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <memory>

#include "WCCommand.h"


void WCCommand::execute(const std::string& args, std::string& input) {
	bool world = false;
	bool character = false;
	
	if (args.size() < 1) {
		std::cerr << "u stupid" << "\n";
		return;
	}
	input = "u stupiddd";
	//if (args[0] == "-w") WorldCount({args.begin() + 1, args.end()});
	//else if (args[0] == "-c") CharacterCount({ args.begin() + 1, args.end() });
	//else std::cerr << "" << std::endl;
}

#include <fstream>
void WCCommand::WorldCount(const std::vector<std::string>& args) {
	std::string input, output;

	size_t cnt = 0;
	bool to_count = false;
	char c = args[0][0];

	if (c != '"') {
		if (c == '<') {
			input = args[1];
		}
		else {
			input = args[0];
		}
		std::ifstream inFile(input);
		if (!inFile) {
			std::cerr << "Error - file not found " << input << std::endl;
			return;
		}
		std::string word;
		while (inFile >> word) {
			++cnt;
		}
		inFile.clear();
		inFile.seekg(0);

	}else{
		for (auto x : args) {
			++cnt;
			if (x[x.size() - 1] == '"') break;
		}
		if (args[0][args[0].size() - 1] == '"' && args[0].size() - 1 == 1) cnt--;
	}

	if (args[args.size() - 2] == ">") {
		output = args[args.size() - 1];
		std::ofstream outFile(output);
		if (!outFile) {
			std::cerr << "Error - file not found " << output << std::endl;
			return;
		}
		outFile << cnt<<"\n";
	}
	else
	{
		std::cout << cnt<<"\n";
	}
}

void WCCommand::CharacterCount(const std::vector<std::string>& args) {
	std::string input, output;

	size_t cnt = -2;
	bool to_count = false;
	char c = args[0][0];

	if (c != '"') {
		if (c == '<') {
			input = args[1];
		}
		else {
			input = args[0];
		}
		std::ifstream inFile(input);
		if (!inFile) {
			std::cerr << "Error: Could not open input file " << input << std::endl;
			return;
		}
		std::string word;
		while (inFile >> word) {
			cnt += word.size();
		}
		inFile.clear();
		inFile.seekg(0);
	}
	else {
		for (auto x : args) {
			cnt += x.size();
			if (x[x.size() - 1] == '"') break;
		}
	}

	if (args[args.size() - 2] == ">") {
		output = args[args.size() - 1];
		std::ofstream outFile(output);
		if (!outFile) {
			std::cerr << "Error: Could not open output file " << output << std::endl;
			return;
		}
		outFile << cnt << "\n";
	}
	else
	{
		std::cout << cnt << "\n";
	}
}