#ifndef TRUNCATE_H
#define TRUNCATE_H

#include "Command.h"

class Truncate : public Command {
	void execute(const string& params, bool last);
};
#endif
