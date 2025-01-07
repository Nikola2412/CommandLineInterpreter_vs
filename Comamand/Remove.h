#ifndef REMOVE_H
#define REMOVE_H

#include "Command.h"

class Remove : public Command {
	void Execute(const string& params, bool last);
};

#endif
