#include "Command.h"


Command::Command() : reader(nullptr), writer(nullptr) {}

Command::~Command() {
    this->Argument().clear();
    if (reader) delete reader;
    if (writer) delete writer;
}

string& Command::Argument() {
    static string arg;
    return arg;
}

void Command::MainExecute(const string& params, bool last, Reader* r) {
    if (params == "-help") {
        this->Helper();
        return;
    }
    this->last = last;
    this->reader = r;
    if (reader) _EOF = 1;
    this->Execute(params);
    end();
    _EOF = 0;
}

void Command::Helper()
{
    this->Print("Working on it");
}

bool Command::CollectString() {
    if (reader && this->Argument().empty()) {
        if (TestInput()) return 0;
        string s;
        while (!reader->endOfRead()) {
            s = reader->getNextLine();
            if (_EOF && "EOF" == s) break;
            this->Append(s);
        }
    }
    return 1;
}

void Command::Append(const string& s) {
    auto& argument = this->Argument();
    if (!argument.empty()) {
        argument += '\n';
    }
    argument += s;
}

void Command::Info(const string& input)
{
	cout << input << endl;
}

void Command::Error(const string& input)
{
	cerr << input << endl;
}

void Command::Print(const string& input)
{
    cout << input << endl;
}


void Command::Set(const string& arg) {
    if (this->Argument().size() != 0) {
        FindOutputFile(arg);
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
        FindInputFile(arg);
    FindOutputFile(arg);
}

void Command::FindInputFile(const string& arg) {
    if (arg[0] == '>') {
        if(!reader) reader = new ConsoleReader();
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

void Command::FindOutputFile(const string& arg) {
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

bool Command::TestInput() {
    if (!reader) return 0;
    if (reader->endOfRead()) this->Error("Input file does not exist");
    return reader->endOfRead();
}

void Command::end() {
    if (this->last) {
        if (writer && !_Batch()) writer->writeLine(this->Argument());
        this->reset();
    }
    reader = nullptr;
    writer = nullptr;
}

bool& Command::_Batch(){
    static bool _BATCH = 0;
    return _BATCH;
}

void Command::reset() {
    if (reader && !_EOF) delete reader;
    if (writer) delete writer;
    reader = nullptr;
    writer = nullptr;
    if(!_Batch())this->Argument().clear();
}
