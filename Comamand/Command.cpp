#include "Command.h"

string Command::getCommandLine()
{
    string str;
    getline(cin, str);
    //cout << str << endl;
    return str;
}
