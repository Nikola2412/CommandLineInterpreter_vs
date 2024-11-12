#ifndef Batch_h 
#define Batch_h

#include "Command.h"
class Batch : public Command {
	virtual void execute(const std::string& args, std::string& input);

};

#endif
