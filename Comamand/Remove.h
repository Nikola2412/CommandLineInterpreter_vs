#ifndef Remove_H
#define Remove_H

#include "Command.h"

class Remove : public Command{
	void execute(const string& params, bool last);
};

#endif
