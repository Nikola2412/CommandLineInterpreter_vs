#include "Translate.h"
#include <algorithm>

void Translate::Execute(const string& params, bool last) {
	this->Set(params);
	size_t n = params.size();
	char c1 = params[n - 6];
	char c2 = params[n - 2];
	replace(this->Argument().begin(), this->Argument().end(), c1, c2);

	end(last);
}

