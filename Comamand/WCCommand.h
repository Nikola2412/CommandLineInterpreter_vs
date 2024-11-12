// WCCommand.h
#ifndef WCCommand_h
#define WCCommand_h

#include "Command.h"


class WCCommand : public Command {
public:
    virtual void execute(const string& args, string& input);
private:
    size_t WorldCount(const string&);
    size_t CharacterCount(const string&);
};
#endif