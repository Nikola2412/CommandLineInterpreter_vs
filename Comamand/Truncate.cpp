#include "Truncate.h"

void Truncate::execute(const string& parms, bool last){
    ofstream outfile(parms, ios::trunc);

    if (outfile.is_open()) {
        outfile.close();
    }
    else {
        cerr << "Error clearing file." << endl;
    }
}

void Truncate::executeBatch(const string& parms, bool last, Reader* r)
{
    this->execute(parms, last);
}
