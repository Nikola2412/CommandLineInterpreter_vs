#include "Remove.h"

void Remove::Execute(const string& params) {

    if (remove(params.c_str()) != 0) cerr << "Error deleting file" << endl;
    else cout << "File deleted" << endl;
}

void Remove::Helper()
{
    CommandHelper h;
    h.RemoveHelper();
}
