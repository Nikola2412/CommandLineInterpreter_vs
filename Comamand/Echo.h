#ifndef Echo_h
#define Echo_h

#include "Command.h"

class Echo : public Command{
public:
    void execute(const string& parms, bool last);
};

#endif