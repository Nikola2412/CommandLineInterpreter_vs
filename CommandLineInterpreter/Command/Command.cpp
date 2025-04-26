#include "Command.h"


Command::Command() : reader(nullptr), writer(nullptr) {}

Command::~Command() 
{
    this->Argument().clear();
    if (reader) delete reader;
    if (writer) delete writer;
}

string& Command::Argument() 
{
    static string arg;
    return arg;
}

void Command::mainExecute(const string& params, bool last, Reader* r) 
{
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

//collect input string from console or file
bool Command::collectString() 
{
    if (reader && this->Argument().empty()) {
        if (testInput()) return false; //if input file does not exist
        string s;
        while (!reader->endOfRead()) {
            s = reader->getNextLine();
            if (_EOF && "EOF" == s) break;
            this->Append(s);
        }
    }
    return true;//returns that it is all ok
}

void Command::Append(const string& s) 
{
    auto& argument = this->Argument();
    if (!argument.empty())
        argument += '\n';
    argument += s;
}

void Command::Info(const string& input)
{
	cout << input << '\n';
}

void Command::Error(const string& input)
{
	cerr << input << '\n';
}

void Command::Print(const string& input)
{
    cout << input << '\n';
}


void Command::Set(const string& arg) 
{
    if (this->Argument().size() != 0) {  
        // pipline  
        setOutput(arg);
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
        setInput(arg);
    setOutput(arg);
}

//set input for command
void Command::setInput(const string& arg) 
{
    if (arg[0] == '>') { // if command is like "echo >output.txt" there is no argument or input file
        if(!reader) reader = new ConsoleReader();
        return;
    }

    if (arg[0] != '\"') {
        string s = string();
        for (auto& c : arg) {
            if (c == '<') continue;
			if (isspace(c)) break;
            s += c;
        }
        //cout << s << '\n';
        reader = new FileReader(s);
    }
}

//set output for command
void Command::setOutput(const string& arg) 
{
    if (!this->last) return;

    size_t end = arg.find_first_of('>');
    if (end == string::npos) {  //if ">" does not exist that means that output is console
        writer = new ConsoleWriter();
        return;
    }
    string s = string();
    bool append = 1;//bool is one bit and take less memory that int 
    for (auto& c : arg.substr(end)) {//collect all character after >
        if (c == '>') {
            //since there is two possibilities ">" and ">>".
            // if it is first that means append will be 0
            // if it is second that means append will be 1
            append = !append;
            continue;
        }
        if (isspace(c)) continue;
        s += c;
    }
    writer = new FileWriter(s, append);
}

bool Command::testInput() 
{
    if (!reader) return false;
    if (reader->endOfRead()) {
        //if input file does not exist
        this->Error("Input file does not exist");
        //skip output
        writer = nullptr;//does not input new line
    }
    return reader->endOfRead();
}

void Command::end() 
{
    if (this->last) {

        //if command is batch output of commands should be one output
		//if command is batch but command have file as output then output should be in that file
        if (writer && (!_Batch() || (_Batch() && dynamic_cast<FileWriter*>(writer))) ) {
            writer->writeLine(this->Argument());
            //if output then argument should be cleared
            clear = 1;
        }

        this->Reset();
    }
    reader = nullptr;
    writer = nullptr;
}

bool& Command::_Batch()
{
    static bool _BATCH = 0;
    return _BATCH;
}

void Command::Reset() 
{
    if(clear) this->Argument().clear();
    if (reader && !_EOF) delete reader;
    if (writer) delete writer;
    reader = nullptr;
    writer = nullptr;
}
