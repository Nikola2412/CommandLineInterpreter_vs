#include "Batch.h"
#include <fstream>

#include "../Interpreter/Interpreter.h"

void Batch::execute(const std::string& args, std::string& input){
    std::ifstream file(args);
    std::string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            Interpreter::Instance().interpret(line);
        }
        file.close();
    }
}
