#ifndef HELP_H
#define HELP_H

#include "Command.h"

class Help : public Command {
public:
	void execute(const string& params, bool last);
};

#endif