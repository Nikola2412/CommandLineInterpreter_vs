#include <iostream>
#include <string>

using namespace std;

class CommandHelper
{
private:
	void print(const string& s);
	void printOPT(const string& s, const string& k);
	void BasicHelper();
public:
	void AllHelper();
	void EchoHelper();
	void PromptHelper();
	void TimeHelper();
	void DateHelper();
	void TouchHelper();
	void TruncateHelper();
	void RemoveHelper();
	void WCHelper();
	void TranslateHelper();
	void HeadHelper();
	void BatchHelper();
};

