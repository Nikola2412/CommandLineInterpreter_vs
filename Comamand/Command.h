#ifndef Command_h
#define Command_h

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>


using namespace std;

class Command {
public:
    //virtual void execute(const std::vector<std::string>& args, std::string* input) = 0;
    virtual void execute(const std::string& args, std::string& input) = 0;
protected:
    string getCommandLine();
};
#endif // !Command_h
