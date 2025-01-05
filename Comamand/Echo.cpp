#include "Echo.h"

void Echo::execute(const string& params, bool last) {
    this->set(params);

    CollectString();

    end(last);
}
