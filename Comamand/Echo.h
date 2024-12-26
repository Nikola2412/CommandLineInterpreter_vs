#ifndef Echo_h
#define Echo_h

#include "Command.h"

class Echo : public Command{
public:
    virtual void execute(const string& args, bool last);
};

#endif