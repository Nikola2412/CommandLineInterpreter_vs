#include "Remove.h"

void Remove::Execute(const string& params, bool last) {

    if (remove(params.c_str()) != 0) cerr << "Error deleting file" << endl;
    else cout << "File deleted" << endl;

    //end(last);
}
