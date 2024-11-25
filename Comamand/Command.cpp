#include "Command.h"


Command::~Command() {
    if (reader) delete reader;
}
string& Command::test() {
    static string in;
    return in;
}
