#include "Truncate.h"

void Truncate::Execute(const string& params) 
{
    ofstream outfile(params, ios::trunc);

    if (outfile.is_open())
        outfile.close();
    else
        cerr << "Error clearing file." << '\n';
}

void Truncate::Helper()
{
    CommandHelper h;
    h.TruncateHelper();
}
