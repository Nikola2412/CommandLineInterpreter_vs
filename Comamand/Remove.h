#ifndef Remove_H
#define Remove_H

#include "Command.h"

class Remove : public Command{
	virtual void execute(const std::string& args, std::string& input);
};

#endif
