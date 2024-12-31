#include "Remove.h"

void Remove::execute(const string& parms, bool last){
    int status = remove(parms.c_str());

    if (status != 0) {
        cerr << "Error deleting file" << endl;
    }

    end(last);
}
