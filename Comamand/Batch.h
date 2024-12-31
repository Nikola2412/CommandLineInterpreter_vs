#ifndef Batch_h 
#define Batch_h

#include "Command.h"
class Batch : public Command {
public:
	void execute(const string& parms, bool last);
private:
	void Do(const string arg);
};

#endif
