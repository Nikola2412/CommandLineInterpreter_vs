#include "Command.h"


Command::Command() : reader(nullptr), writer (nullptr){}


void Command::MainExecute(const string& params, bool last, Reader* r) {
    this->reader = r;
    if (reader) _EOF = 1;
    this->execute(params, last);
}

Command::~Command() {
    if (reader) delete reader;
    if (writer) delete writer;
}

string& Command::Argument() {
    static string arg;
    return arg;
}

void Command::CollectString() {
    if (reader && this->Argument().empty()) {
        if (test_input()) return;
        string s;
        while (!reader->endOfRead()) {
            s = reader->getNextLine();
            if (_EOF && "EOF" == s) break;
            this->Append(s);
        }
    }
}

void Command::Append(const string s) {
    auto& argument = this->Argument();
    if (!argument.empty()) {
        argument += '\n';
    }
    argument += s;
}


void Command::set(const string arg) {
    if (this->Argument().size() != 0) {
        find_output_file(arg);
        return;
    }
    if (arg.size() == 0) {
        if (!reader) reader = new ConsoleReader();
        writer = new ConsoleWriter();
        return;
    }
    if (arg[0] == '\"') {
        size_t end = arg.find('\"', 1);
        string s = arg.substr(1, end - 1);
        this->Argument() = s;
    }
    else
        find_input_file(arg);
    find_output_file(arg);
}

void Command::find_input_file(const string arg) {
    if (arg[0] == '>') {
        reader = new ConsoleReader();
        return;
    }
    size_t end = arg.find(".txt");
    if (arg[0] == '<') {
        size_t k = 1;
        if (isspace(arg[k])) k++;
        string s = "";
        if (end != string::npos) {
            s = arg.substr(k, end + 4 - k);
        }
        else {
            s = arg.substr(k);
        }
        reader = new FileReader(s);
    }
    else if (arg[0] != '\"') {
        string s = arg.substr(0, end + 4);
        reader = new FileReader(s);
    }
}

void Command::find_output_file(const string arg) {
    size_t end = arg.find_last_of('>');
    if (end == string::npos) {
        writer = new ConsoleWriter();
        return;
    }
    bool append = false;
    if (end > 0 && arg[end - 1] == '>') append = true;
    size_t k = 1;
    if (isspace(arg[end + k])) k++;
    string s = arg.substr(end + k);
    writer = new FileWriter(s, append);
}

bool Command::test_input() {
    if (!reader) return 0;
    if (reader->endOfRead()) cerr << "Input file does not exist" << endl;
    return reader->endOfRead();
}

void Command::end(bool last) {
    _EOF = 0;
    if (last) {
        if (writer) writer->writeLine(this->Argument());
        this->reset();
    }
    reader = nullptr;
    writer = nullptr;
}

void Command::reset() {
    reader = nullptr;
    writer = nullptr;
    this->Argument().clear();
}
