#ifndef Touch_h
#define Touch_h

#include "Command.h"

class Touch : public Command{
public:
	void execute(const string& args, bool last);
	void executeBatch(Reader* r = nullptr, Writer* w = nullptr);
};

#endif