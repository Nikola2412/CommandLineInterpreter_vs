#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>
#include <vector>
#include <sstream>
#include <fstream>

#include "../Comamand/Commands.h"

class Interpreter {
public:

    static Interpreter& Instance();

    void interpret(const std::string& args);

    std::string getSymbol();

private:
    Interpreter();

    std::string symbol;

    std::unordered_map<std::string, std::unique_ptr<Command>> commands;

    std::vector<std::string> parseInput(const std::string& args);

    const std::string valid_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789<>\"""-.:|";

    bool hasInvalidCharacters(const std::string& input, std::vector<int>& errorPositions);

    void printError(const std::string& input, const std::vector<int>& errorPositions);

};
