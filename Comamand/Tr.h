#ifndef TR_H
#define TR_H


#include "Command.h"

class Tr : public Command {
public:
	~Tr();
	virtual void execute(const string& args);
};


#endif



