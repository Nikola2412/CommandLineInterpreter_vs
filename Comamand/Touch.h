#ifndef TOUCH_H
#define TOUCH_H

#include "Command.h"

class Touch : public Command {
public:
	void execute(const string& params, bool last);
};

#endif