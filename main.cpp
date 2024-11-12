#include "Interpreter/Interpreter.h"

int main()
{
    //Interpreter interpreter;
    ios_base::sync_with_stdio(false);

    string str;

    while (1) {
        cout << Interpreter::Instance().getSymbol() << " ";
        if (!getline(std::cin, str) || str == "exit") break;
        Interpreter::Instance().interpret(str);
    }

    /*char str[512];

    while (1) {
        std::cout << interpreter.getSymbol() << " ";
        std::cin >> str;
        if (str == "exit") break;
        interpreter.interpret(str);
    }*/

    return 0;
}
