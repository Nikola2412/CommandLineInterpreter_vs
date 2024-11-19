#ifndef Echo_h
#define Echo_h

#include "Command.h"

class Echo : public Command{
public:
    ~Echo();
    virtual void execute(const std::string& args, std::string& input);
};

#endif