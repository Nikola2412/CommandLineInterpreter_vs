#include <iostream>
#include <ctime>

#include "Time_Date.h"


tm Time_Date::getTime(const string& arg) {
    this->find_output_file(arg);

    time_t now = time(0);
    tm local_time;
    localtime_s(&local_time, &now);

    return local_time;
}


void Time::execute(const string& params, bool last) {
    tm local_time = getTime(params);

    strftime(buffer, sizeof(buffer), "%H:%M:%S", &local_time);

    this->Append(buffer);

    end(last);
}

void Date::execute(const string& params, bool last) {
    tm local_time = getTime(params);

    strftime(buffer, sizeof(buffer), "%d.%m.%Y", &local_time);

    this->Append(buffer);

    end(last);
}

