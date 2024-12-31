#include <unordered_map>

#include "../Comamand/Commands.h"

class Interpreter {
public:

    static Interpreter& Instance();

    void interpret(const string&);
    void interpretBatch(Reader *r,const string&);

    string& getSymbol();


private:
    Interpreter();

    string symbol;

    unordered_map<string, unique_ptr<Command>> commands;

    vector<string> parseInput(const string& input);

    const string valid_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789<>\"""-.:|";

    bool hasInvalidCharacters(const string& input, vector<size_t>& errorPositions);

    void printError(const string& input, const vector<size_t>& errorPositions);

    vector<string> splitPipeline(const string& input);

};
