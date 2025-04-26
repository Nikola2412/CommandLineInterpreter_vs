#include "Translate.h"

#include <algorithm>
#include <regex>

void Translate::Execute(const string& params) {
	regex rgx;
	int k = 1;
	if (!this->Argument().empty()) {
		rgx = regex(R"("([^ \"]+)\"(?: \"([^\"]+)\")?$)");
	}
	else {
		rgx = regex(R"(^(\S+) \"([^ \"]+)\"(?: \"([^\"]+)\")?$)");
		k = 2;
	}
	this->Set(params);
	CollectString();
	smatch matches;
	if (regex_search(params, matches, rgx)) {
		c1 = matches[k].str()[0];
		if (matches[k + 1].matched) {
			c2 = matches[k + 1].str()[0];
		}
		else {
			c2 = NULL;
		}
	}
	auto& arg = this->Argument();
	if (c2)
		replace(arg.begin(), arg.end(), c1, c2);
	else {
		string str = "";
		for (char c : arg)
			if (c != c1)
				str += c;

		arg = str;
	}

}

void Translate::Helper()
{
	CommandHelper h;
	h.TranslateHelper();
}

