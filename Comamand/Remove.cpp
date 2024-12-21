#include "Remove.h"

void Remove::execute(const std::string& args, bool last){
    int status = remove(args.c_str());

    if (status != 0) {
        cerr << "Error deleting file" << endl;
    }
}
