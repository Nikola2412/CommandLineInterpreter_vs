#ifndef TR_H
#define TR_H


#include "Command.h"

class Translate : public Command {
public:
	void execute(const string& params, bool last);
};


#endif



