#ifndef REMOVE_H
#define REMOVE_H

#include "Command.h"

class Remove : public Command {
public:
	Remove() = default;
	~Remove() = default;

	void Execute(const string& params);    
	void Helper();

};

#endif
