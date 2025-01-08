#ifndef BATCH_H
#define BATCH_H

#include "Command.h"

class Batch : public Command {
public:
	Batch() = default;
	~Batch() = default;
	void Execute(const string& params, bool last);
private:
	void Do(const string arg);
};

#endif
