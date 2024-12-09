#include "Tr.h"
#include <algorithm>

Tr::~Tr(){}

void Tr::execute(const string& args){
	this->set(args);
	int n = args.size();
	char c1 = args[n - 6];
	char c2 = args[n - 2];
	std::replace(this->Argument().begin(), this->Argument().end(), c1, c2);
	writer->writeLine(this->Argument());
}
