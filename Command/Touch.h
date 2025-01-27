#ifndef TOUCH_H
#define TOUCH_H

#include "Command.h"

class Touch : public Command {
public:
	Touch() = default;
	~Touch() = default;

public:
	void Execute(const string& params);
	void Helper();

};

#endif