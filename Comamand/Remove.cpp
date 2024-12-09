#include "Remove.h"

void Remove::execute(const std::string& args, bool last){
    int status = remove(args.c_str());

    if (status != 0) {
        perror("Error deleting file\n");
    }
}
