#ifndef Batch_h 
#define Batch_h

#include "Command.h"
class Batch : public Command {
public:
	~Batch();
	virtual void execute(const string& args, bool last);
	void Do(const string arg);
};

#endif
