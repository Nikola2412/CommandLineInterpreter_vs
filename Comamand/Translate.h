#ifndef TR_H
#define TR_H


#include "Command.h"

class Translate : public Command {
public:
	void execute(const string& parms, bool last);
};


#endif



