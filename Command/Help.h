#ifndef HELP_H
#define HELP_H

#include "Command.h"

class Help : public Command {
public:
	Help() = default;
	~Help() = default;

	void Execute(const string& params);
};

#endif