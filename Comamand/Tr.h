#ifndef TR_H
#define TR_H


#include "Command.h"

class Tr : public Command {
public:
	void execute(const string& args, bool last);
	void executeBatch(Reader* r = nullptr, Writer* w = nullptr);
};


#endif



