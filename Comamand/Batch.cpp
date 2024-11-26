#include "Batch.h"

#include "../Interpreter/Interpreter.h"

Batch::~Batch(){}

void Batch::execute(const std::string& args){
    /*std::ifstream file(args);
    std::string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            Interpreter::Instance().interpret(line);
        }
        file.close();
    }*/
    reader = new FileReader(args);
    while (!reader->endOfRead())
        Interpreter::Instance().interpret(reader->getNextLine());
}
