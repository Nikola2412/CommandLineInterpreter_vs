#ifndef HELP_H
#define HELP_H

#include "Command.h"
class Help : public Command
{
	void Execute(const string& params);
};

#endif
