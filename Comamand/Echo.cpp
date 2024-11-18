#include "Echo.h"


//void Echo::execute(const std::vector<std::string>& args, std::string* input) {
//    if (!args.empty()) {
//        *input = args[0];
//    }
//}


void Echo::execute(const std::string& args, std::string& input){
    //std::cout << args << "\n";

    if (args.empty()) {
        //cout << CommandInput() << endl;
        reader = new CommandReader();
        vector<string> v;
        while(!reader->endOfRead())
            v.push_back(reader->getNextLine());
        for (auto x : v)
            cout << x << endl;
        return;
    }

    size_t n = args.size();
    if (args[0] == '"' && args[n - 1] == '"')
        std::cout << args.substr(1, n - 2) << std::endl;
    else
    {
        /*std::ifstream file(args);
        std::string line;

        if (file.is_open()) {
            while (getline(file, line)) {
                std::cout << line << std::endl;
            }
            file.close();
        }*/
        reader = new FileReader(args);
        while (!reader->endOfRead())
            cout << reader->getNextLine() << endl;

    }
}
