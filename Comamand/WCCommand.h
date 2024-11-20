// WCCommand.h
#ifndef WCCommand_h
#define WCCommand_h


#include "Command.h"
#include "../Comamand/Options/Counter.h"

#include <unordered_map>


class WCCommand : public Command {
public:
    WCCommand();
    ~WCCommand();
    virtual void execute(const string& args, string& input);
private:
    void MultipleLines(const string& input);

    void FileInput(const string& input);

    //size_t WorldCount(const string&);
    //size_t CharacterCount(const string&);
    unordered_map<string,unique_ptr<Counter>> counters;
    
    unique_ptr<Counter> options;
};

#endif