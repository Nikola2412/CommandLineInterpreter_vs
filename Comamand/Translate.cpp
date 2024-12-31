#include "Translate.h"
#include <algorithm>

void Translate::execute(const string& parms, bool last){
	this->set(parms);
	int n = parms.size();
	char c1 = parms[n - 6];
	char c2 = parms[n - 2];
	replace(this->Argument().begin(), this->Argument().end(), c1, c2);
	end(last);
}

void Translate::executeBatch(const string& parms, bool last, Reader* r)
{
}
