#ifndef Truncate_h
#define Truncate_h

#include "Command.h"

class Truncate : public Command{
	void execute(const string& args, bool last);
	void executeBatch(Reader* r = nullptr, Writer* w = nullptr);

};
#endif
