#include "Remove.h"

void Remove::Execute(const string& params, bool last) {
    int status = remove(params.c_str());

    if (status != 0) {
        cerr << "Error deleting file" << endl;
    }

    //end(last);
}
