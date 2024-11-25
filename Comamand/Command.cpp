#include "Command.h"


Command::Command(){}

Command::~Command() {
    if (reader) delete reader;
    if (writer) delete reader;
}

string& Command::Argument() {
    static string arg;
    return arg;
}

void Command::set(const string arg) {
    if (arg.size() == 0) {
        reader = new ConsoleReader();
        return;
    }
    if (arg[0] == '\"') {
        size_t end = arg.find_last_of('\"');
        string s = arg.substr(1, end - 1);
        //cout << s << endl;
        this->Argument() = s;
    }
    else
        find_input_file(arg);
    find_output_file(arg);
}

void Command::find_input_file(const string arg) {
    size_t end = arg.find('>');
    if (arg[0]=='<') {
        size_t k = 1;
        if (isspace(arg[k])) k++;
        string s = "";
        if (end != string::npos) {
            s = arg.substr(k, end - 1 - k);
        }
        else {
            s = arg.substr(k);
        }
        reader = new FileReader(s);
    }
    else if (arg[0] != '\"') {
        string s = arg.substr(0, end - 1);
        //cout << s << endl;
        reader = new FileReader(s);
    }
}

void Command::find_output_file(const string arg) {
    
    size_t end = arg.find('>');
    if (end == string::npos) {
        writer = new ConsoleWriter();
        return;
    }
    size_t k = 1;
    if (isspace(arg[end + k])) k++;
    string s = arg.substr(end + k);
    //cout << s << endl;

    writer = new FileWriter(s);
}

void Command::reset(){
    reader = nullptr;
    writer = nullptr;
    this->Argument().clear();
}
