#ifndef Command_h
#define Command_h

#include <string>
#include <vector>

using namespace std;

class Command {
public:
    //virtual void execute(const std::vector<std::string>& args, std::string* input) = 0;
    virtual void execute(const std::string& args, std::string& input) = 0;
protected:
    Command(string v = "");
    string value;
};
#endif // !Command_h
