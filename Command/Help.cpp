#include "Help.h"

void Help::Execute(const string& params) {
	this->writer = new ConsoleWriter();

	this->Append("[arg] means optional");
	this->Append("arg means must");
	this->Append("echo [argument]");
	this->Append("prompt argument -> change symbol $ to argument");
	this->Append("time");
	this->Append("date");
	this->Append("touch filename -> create file");
	this->Append("truncate filename -> resets file");
	this->Append("rm filename -> deletes file");
	this->Append("wc -opt [argument]");
	this->Append("	-w -> count words in argument");
	this->Append("	-c -> count characters in argument");
	this->Append("tr [argument] what [with]");
	this->Append("head -nC [argument] -> outputs C lines");
	this->Append("batch [argument]");
	this->Append("pipe example: time | wc -c");
}
