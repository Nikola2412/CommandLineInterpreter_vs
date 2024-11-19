#ifndef TR_H
#define TR_H


#include "Command.h"

class Tr : public Command {
	virtual void execute(const std::string& args, std::string& input);
};


#endif



