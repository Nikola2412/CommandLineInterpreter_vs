#ifndef Remove_H
#define Remove_H

#include "Command.h"

class Remove : public Command{
	void execute(const string& args, bool last);
	void executeBatch(const string& args, bool last, Reader* r = nullptr);
};

#endif
