// WCCommand.h
#ifndef WCCommand_h
#define WCCommand_h


#include "Command.h"
#include "Counter.h"

#include <unordered_map>


class WCCommand : public Command {
public:
    WCCommand();
    ~WCCommand();
    virtual void execute(const string& args, string& input);
private:
    void MultipleLines(const string&);
    size_t WorldCount(const string&);
    size_t CharacterCount(const string&);
    std::unordered_map<std::string, std::unique_ptr<Counter>> counters;
};

#endif