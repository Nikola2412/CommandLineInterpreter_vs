#ifndef Batch_h 
#define Batch_h

#include "Command.h"
class Batch : public Command {
public:
	void execute(const string& parms, bool last);
	void executeBatch(const string& parms, bool last, Reader* r = nullptr);
private:
	void Do(const string arg);
};

#endif
