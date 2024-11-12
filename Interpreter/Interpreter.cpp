#include "Interpreter.h"

Interpreter& Interpreter::Instance()
{
    static Interpreter interpreter;
    return interpreter;
}

Interpreter::Interpreter() : symbol("$") {
    commands["wc"] = make_unique<WCCommand>();
    commands["echo"] = make_unique<Echo>();
    commands["prompt"] = make_unique<Prompt>();
    commands["time"] = make_unique<Time>();
    commands["date"] = make_unique<Date>();
    commands["touch"] = make_unique<Touch>();
    commands["truncate"] = make_unique<Truncate>();
    commands["rm"] = make_unique<Remove>();
    commands["batch"] = make_unique<Batch>();
    //commands["head"] = make_unique<Head>();
}


void Interpreter::interpret(const string& input){
    vector<int> errorPositions;
    string pipe_input = "";
    auto args = parseInput(input);
    if (args.empty()) return;

    if (hasInvalidCharacters(input, errorPositions)) {
        printError(input, errorPositions);
        return;
    }

    string commandName = args[0];

    if (commands.find(commandName) != commands.end()) {
        commands[commandName]->execute({ args[1] },pipe_input);
        if (commandName == "prompt") {
            this->symbol = pipe_input;
            return;
        }
    }
    else {
        cerr << "Unknown command: " << commandName << endl;
        return;
    }
    if (pipe_input == "") return;
    cout << pipe_input << endl;
}

vector<string> Interpreter::parseInput(const string& input)
{
    /*istringstream stream(input);
    vector<string> tokens;
    string token;
    while (stream >> token) {
        tokens.push_back(token);
    }
    return tokens;*/

    size_t spacePos = input.find(' ');

    vector<string> tokens;

    if (spacePos != string::npos) { // Check if there is a space
        tokens.push_back(input.substr(0, spacePos)); // command
        tokens.push_back(input.substr(spacePos + 1)); // rest
    }
    else
    {
        tokens.push_back(input);
        tokens.push_back("");
    }


    return tokens;
}

bool Interpreter::hasInvalidCharacters(const string& input, vector<int> &errorPositions) {
    bool err = false;

    bool count = true;

    for (int i = 0; i < input.size(); ++i) {
        char c = input[i];
        if (c == '"') count = !count;
        if (count && valid_chars.find(c) == string::npos && !isspace(c)) {
            errorPositions.push_back(i);
            err = true;
        }
    }
    return err;
}

void Interpreter::printError(const string& input, const vector<int>& errorPositions) {
    cerr << "Error - unexpected characters:\n";
    cerr << input << endl;

    for (int i = 0; i < input.size(); i++) {
        if (find(errorPositions.begin(), errorPositions.end(), i) != errorPositions.end()) {
            cerr << "^";
        }
        else {
            cerr << " ";
        }
    }
    cerr << endl;
}

string Interpreter::getSymbol(){
    return this->symbol;
}