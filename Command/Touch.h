#ifndef TOUCH_H
#define TOUCH_H

#include "Command.h"

class Touch : public Command {
public:
	Touch() = default;
	~Touch() = default;
	void Execute(const string& params, bool last);
};

#endif