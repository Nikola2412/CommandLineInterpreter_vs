#include "Touch.h"

void Touch::execute(const std::string& args){

    std::ifstream file(args);

    if (file.is_open()) {
        std::cerr << "Error - file \"" << args << "\" exist" << "\n";
        file.close(); // Close the file
    }
    else {
        std::ofstream outfile(args);
    }
}
