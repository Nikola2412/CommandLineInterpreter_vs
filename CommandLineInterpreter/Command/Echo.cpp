#include "Echo.h"

void Echo::Execute(const string& params) 
{
    this->Set(params);
	if (!CollectString()) return;
}

void Echo::Helper()
{
	CommandHelper h;
	h.EchoHelper();
}
