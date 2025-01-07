#include "Echo.h"

void Echo::Execute(const string& params, bool last) {
    this->Set(params);

    CollectString();

    end(last);
}
