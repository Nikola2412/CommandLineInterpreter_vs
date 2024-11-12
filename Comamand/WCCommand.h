// WCCommand.h
#ifndef WCCommand_h
#define WCCommand_h

#include "Command.h"


class WCCommand : public Command {
public:
    virtual void execute(const std::string& args, std::string& input);
private:
    void WorldCount(const std::vector<std::string>&);
    void CharacterCount(const std::vector<std::string>&);
};
#endif