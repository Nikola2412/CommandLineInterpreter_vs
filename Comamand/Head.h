#ifndef HEAD_H
#define HEAD_H

#include "Command.h"

class Head : public Command {
public:
	virtual void execute(const string& args, bool last);
};

#endif


