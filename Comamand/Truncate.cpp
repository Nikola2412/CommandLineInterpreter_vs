#include "Truncate.h"

void Truncate::execute(const string& args, bool last){
    std::ofstream outfile(args, std::ios::trunc);

    if (outfile.is_open()) {
        outfile.close();
    }
    else {
        std::cerr << "Error clearing file." << std::endl;
    }
}
