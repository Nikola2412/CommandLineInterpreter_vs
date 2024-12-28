#ifndef HEAD_H
#define HEAD_H

#include "Command.h"

class Head : public Command {
public:
	void execute(const string& args, bool last);
	void executeBatch(Reader* r = nullptr, Writer* w = nullptr);
};

#endif


