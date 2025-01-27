#ifndef TRUNCATE_H
#define TRUNCATE_H

#include "Command.h"

class Truncate : public Command {
public:
	Truncate() = default;
	~Truncate() = default;

	void Execute(const string& params);
	void Helper();
};
#endif
