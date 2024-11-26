#include "Tr.h"
#include <algorithm>

Tr::~Tr(){}

void Tr::execute(const string& args){
	this->set(args);
	std::replace(this->Argument().begin(), this->Argument().end(), ':', '.');
	writer->writeLine(this->Argument());
}
