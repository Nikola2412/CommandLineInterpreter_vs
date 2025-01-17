#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <unordered_map>

#include "../Command/Commands.h" //includes all commands

class Interpreter {
public:
    Interpreter();
    ~Interpreter() = default;

public:
    static Interpreter& Instance();
    void Run();
    void interpret(const string& input, Reader* r = nullptr);
    char& getSymbol();

private:
    char symbol;
    unordered_map<string, unique_ptr<Command>> commands;
    vector<string> parseInput(const string& input);
    const string valid_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789<>\"""-.:|";

private:
    bool hasInvalidCharacters(const string& input, vector<size_t>& errorPositions);
    void printError(const string& input, const vector<size_t>& errorPositions);
    void splitPipeLine(const string& input, vector<string>& pipeCommand);
};


#endif // !INTERPRETER_H