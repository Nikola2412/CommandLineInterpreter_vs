#ifndef Remove_H
#define Remove_H

#include "Command.h"

class Remove : public Command{
	void execute(const string& args, bool last);
	void executeBatch(Reader* r = nullptr, Writer* w = nullptr);
};

#endif
