#ifndef TRANSLATE_H
#define TRANSLATE_H

#include "Command.h"

class Translate : public Command {
public:
	Translate() = default;
	~Translate() = default;
	void Execute(const string& params, bool last);
};


#endif



