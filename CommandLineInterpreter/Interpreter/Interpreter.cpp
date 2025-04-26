#include "Interpreter.h"

Interpreter& Interpreter::Instance() 
{
    static Interpreter interpreter;
    return interpreter;
}

void Interpreter::Run() 
{
    string str;

    while (1) {
        cout << Interpreter::Instance().getSymbol() << " ";
        if (!getline(cin, str)) break;
        Interpreter::Instance().interpret(str);
        cin.clear();
    }
}

Interpreter::Interpreter() : symbol('$') 
{
    commands["wc"] = make_unique<WCCommand>();
    commands["echo"] = make_unique<Echo>();
    commands["prompt"] = make_unique<Prompt>();
    commands["time"] = make_unique<Time>();
    commands["date"] = make_unique<Date>();
    commands["touch"] = make_unique<Touch>();
    commands["truncate"] = make_unique<Truncate>();
    commands["rm"] = make_unique<Remove>();
    commands["batch"] = make_unique<Batch>();
    commands["head"] = make_unique<Head>();
    commands["tr"] = make_unique<Translate>();
    commands["-help"] = make_unique<Help>();
}


void Interpreter::interpret(const string& input, Reader* r) 
{
    if (input.empty()) return;
    vector<size_t> errorPositions;
    if (hasInvalidCharacters(input, errorPositions)) {
        printError(input, errorPositions);
        return;
    }
    vector<string> pipeCommand;
    splitPipeLine(input, pipeCommand);
    size_t n = pipeCommand.size();
    for (size_t i = 0; i < n; i++) {
        vector<string> args = parseInput(pipeCommand[i]);
        string commandName = args[0];

        if (commands.find(commandName) != commands.end()) {
            commands[commandName]->MainExecute(args[1], i == n - 1, r);
        }
        else {
            cerr << "Unknown command: " << commandName << '\n';
        }
    }
    cin.clear();
}

vector<string> Interpreter::parseInput(const string& input) 
{
    size_t spacePos = input.find(' ');

    vector<string> tokens;

    if (spacePos != string::npos) { // Check if there is a space
        tokens.push_back(input.substr(0, spacePos)); // command
        tokens.push_back(input.substr(spacePos + 1)); // rest
    }
    else {
        tokens.push_back(input);
        tokens.push_back("");
    }

    return tokens;
}

bool Interpreter::hasInvalidCharacters(const string& input, vector<size_t>& errorPositions) 
{
    bool err = false;

    bool count = true;

    for (size_t i = 0; i < input.size(); i++) {
        char c = input[i];
        if (c == '"') count = !count;
        if (count && valid_chars.find(c) == string::npos && !isspace(c)) {
            errorPositions.push_back(i);
            err = true;
        }
    }
    return err;
}

void Interpreter::printError(const string& input, const vector<size_t>& errorPositions) 
{
    cerr << "Error - unexpected characters:" << '\n';
    cerr << input << '\n';

    for (size_t i = 0; i < input.size(); i++) {
        if (find(errorPositions.begin(), errorPositions.end(), i) != errorPositions.end()) {
            cerr << "^";
        }
        else {
            cerr << " ";
        }
    }
    cerr << '\n';
}

void Interpreter::splitPipeLine(const string& input,vector<string>& pipeCommand) 
{
    stringstream ss(input);
    string segment;
    while (getline(ss, segment, '|')) {
        bool k = 0;//0 or 1
        if (isspace(segment[0]))
            k++;
        pipeCommand.push_back(segment.substr(k));
    }
}

char& Interpreter::getSymbol() 
{
    return this->symbol;
}