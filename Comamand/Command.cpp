#include "Command.h"

string Command::getCommandLine(){
    string str;
    getline(cin, str);
    //cout << str << endl;
    return str;
}

string Command::CommandInput(){
    string value = "";
    char c;
    while (std::cin.get(c)) {
        if (c == '\x1a') break;
        value += c;
    }
    return value;
}
