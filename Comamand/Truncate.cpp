#include "Truncate.h"

void Truncate::execute(const string& args, bool last){
    ofstream outfile(args, ios::trunc);

    if (outfile.is_open()) {
        outfile.close();
    }
    else {
        cerr << "Error clearing file." << endl;
    }
}

void Truncate::executeBatch(const string& args, bool last, Reader* r)
{
    this->execute(args, last);
}
