#ifndef HEAD_H
#define HEAD_H

#include "Command.h"

class Head : public Command {
public:
	~Head();
	void execute(const string& args, string& input);
};

#endif


