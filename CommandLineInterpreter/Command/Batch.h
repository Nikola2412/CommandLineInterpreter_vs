#ifndef BATCH_H
#define BATCH_H

#include "Command.h"

class Batch : public Command {
public:
	Batch() = default;
	~Batch() = default;
	void Execute(const string& params);
	void Helper();
private:
	void Do(const string arg);
	string output = "";
};

#endif
