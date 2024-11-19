#ifndef Batch_h 
#define Batch_h

#include "Command.h"
class Batch : public Command {
public:
	~Batch();
	virtual void execute(const std::string& args, std::string& input);
};

#endif
