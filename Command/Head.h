#ifndef HEAD_H
#define HEAD_H

#include "Command.h"

class Head : public Command {
public:
	Head() = default;
	~Head() = default;

	void Execute(const string& params, bool last);
};

#endif


