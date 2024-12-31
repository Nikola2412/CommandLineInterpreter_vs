#ifndef HEAD_H
#define HEAD_H

#include "Command.h"

class Head : public Command {
public:
	void execute(const string& parms, bool last);
	void executeBatch(const string& parms, bool last, Reader* r = nullptr);
};

#endif


