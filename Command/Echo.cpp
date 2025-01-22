#include "Echo.h"

void Echo::Execute(const string& params) {
    this->Set(params);
    CollectString();
}
