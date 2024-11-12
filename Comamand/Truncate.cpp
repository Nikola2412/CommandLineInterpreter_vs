#include "Truncate.h"

void Truncate::execute(const std::string& args, std::string& input){
    std::ofstream outfile(args, std::ios::trunc);

    if (outfile.is_open()) {
        outfile.close();
    }
    else {
        std::cerr << "Error clearing file." << std::endl;
    }
}
