#include "Interpreter/Interpreter.h"

int main()
{
    Interpreter::Instance();

    string str;

    while (1) {
        cout << Interpreter::Instance().getSymbol() << " ";
        if (!getline(cin, str)) break;
        Interpreter::Instance().interpret(str);
        cin.clear();
    }
}
