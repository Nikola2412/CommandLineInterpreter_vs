#include "Tr.h"
#include <algorithm>

Tr::~Tr(){}

void Tr::execute(const string& args, bool last){
	this->set(args);
	int n = this->Argument().size();
	char c1 = args[n + 4];
	char c2 = args[n + 8];
	std::replace(this->Argument().begin(), this->Argument().end(), c1, c2);
	if (last) {
		writer->writeLine(this->Argument());
		this->reset();
	}
}
