#ifndef Remove_H
#define Remove_H

#include "Command.h"

class Remove : public Command{
	void execute(const string& parms, bool last);
	void executeBatch(const string& parms, bool last, Reader* r = nullptr);
};

#endif
