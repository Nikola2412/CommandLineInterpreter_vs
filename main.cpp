#include "Interpreter/Interpreter.h"

int main()
{
    //Interpreter interpreter;
    //ios_base::sync_with_stdio(false);

    string str;

    while (1) {
        cout << Interpreter::Instance().getSymbol() << " ";
        if (!getline(cin, str)) break;
        Interpreter::Instance().interpret(str);
        cin.clear();
    }

    /*char str[512];

    while (1) {
        cout << interpreter.getSymbol() << " ";
        cin >> str;
        if (str == "exit") break;
        interpreter.interpret(str);
    }*/

    return 0;
}
