#include <unordered_map>

#include "../Comamand/Commands.h"

class Interpreter {
public:

    static Interpreter& Instance();

    void interpret(const string& args);

    string& getSymbol();


private:
    Interpreter();

    string symbol;

    unordered_map<string, unique_ptr<Command>> commands;

    vector<string> parseInput(const string& args);

    const string valid_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789<>\"""-.:|";

    bool hasInvalidCharacters(const string& input, vector<int>& errorPositions);

    void printError(const string& input, const vector<int>& errorPositions);

    vector<string> splitPipeline(const string& input);

};
