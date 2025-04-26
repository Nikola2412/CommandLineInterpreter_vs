#include "Helper.h"

void CommandHelper::newLine()
{
	cout << endl;
}

void CommandHelper::print(const string& s)
{
	cout << s << endl;
}

void CommandHelper::printOPT(const string& s, const string& k)
{
	cout << "	" << s << "	" << k << endl;
}

void CommandHelper::BasicHelper()
{
	print("Basics:");
	print("[argument] means optional");
	print("argument means must");
}
void CommandHelper::AllHelper()
{
	BasicHelper();
	newLine();
	EchoHelper();
	newLine();
	PromptHelper();
	newLine();
	TimeHelper();
	newLine();
	DateHelper();
	newLine();
	TouchHelper();
	newLine();
	TruncateHelper();
	newLine();
	RemoveHelper();
	newLine();
	WCHelper();
	newLine();
	TranslateHelper();
	newLine();
	HeadHelper();
	newLine();
	BatchHelper();
	newLine();
}

void CommandHelper::EchoHelper()
{
	print("echo [argument]");
	print("Passes characters from its input stream to its output stream without any modification");
}

void CommandHelper::PromptHelper()
{
	print("prompt argument");
	print("Changes (sets) the character indicating that the interpreter is ready to load a new command line (command prompt) to the string specified by the argument enclosed in quotes");
}

void CommandHelper::TimeHelper()
{
	print("time");
	print("It prints the current time on the system real-time clock to its output stream.");
}

void CommandHelper::DateHelper()
{
	print("date");
	print("It prints the current date on the system real-time clock to its output stream.");
}

void CommandHelper::TouchHelper()
{
	print("touch filename");
	print("Creates a file with the given name and empty content in the current directory.If the file already exists, it prints an error message and has no other effect.");
}

void CommandHelper::TruncateHelper()
{
	print("truncate filename");
	print("deletes the contents of the file with the given name from the current directory.");
}

void CommandHelper::RemoveHelper()
{
	print("rm filename");
	print("Deletes the file with the given name (removes the file from the file system) from the current directory.");
}

void CommandHelper::WCHelper()
{
	print("wc -opt [argument]");
	print("Counts the words or all characters in the text read from the input character stream and prints the number to its output stream.");
	printOPT("-w", "Count words");
	printOPT("-c", "Count characters");
}

void CommandHelper::TranslateHelper()
{
	print("tr [argument] what [with]");
	print("In the text read from the input stream, it finds all occurrences of the string whatenclosed in quotes by the string with enclosed in quotes and prints the resulting text to its output stream.If the string with is not specified, occurrences of the string what are simply removed from the input text.");
}

void CommandHelper::HeadHelper()
{
	print("head -ncount [argument]");
	print("It transfers the first few lines of text read from the input stream to its output stream, and ignores the remaining content of the input stream.");
}

void CommandHelper::BatchHelper()
{
	print("batch [argument]");
}

