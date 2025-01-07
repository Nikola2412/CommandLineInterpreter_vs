#ifndef HEAD_H
#define HEAD_H

#include "Command.h"

class Head : public Command {
public:
	void Execute(const string& params, bool last);
};

#endif


