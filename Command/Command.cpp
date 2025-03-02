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
    if (arg[0] != '\"') {
        string s = "";
        for (auto& c : arg) {
            if (c == '<') continue;
			if (isspace(c)) break;
            s += c;
        }
        //cout << s << endl;
        reader = new FileReader(s);
    }
}

void Command::FindOutputFile(const string& arg) {
    size_t end = arg.find_first_of('>');
    if (end == string::npos) {
        writer = new ConsoleWriter();
        return;
    }
    string s = "";
    bool append = 1;
    for (auto& c : arg.substr(end)) {
        if (c == '>') {
            append = !append;
            continue;
        }
        if (isspace(c)) continue;
        s += c;
    }
    writer = new FileWriter(s, append);
}

bool Command::TestInput() {
    if (!reader) return 0;
    if (reader->endOfRead()) 
    {
        //if input file does not exist
        this->Error("Input file does not exist");
        //skip output
        writer = nullptr;
    }
    return reader->endOfRead();
}

void Command::end() {
    if (this->last) {

        //if command is batch output of commands should be one output
		//if command is batch but command have file as output then output should be in that file
        if (writer && (!_Batch() || (_Batch() && dynamic_cast<FileWriter*>(writer))) ) {
            writer->writeLine(this->Argument());
            //if output then argument should be cleared
            clear = 1;
        }

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
    if(clear) this->Argument().clear();
    if (reader && !_EOF) delete reader;
    if (writer) delete writer;
    reader = nullptr;
    writer = nullptr;
}
