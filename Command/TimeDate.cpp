#include "TimeDate.h"

tm TimeDate::getTime(const string& arg) {
    this->FindOutputFile(arg);

    time_t now = time(0);
    tm local_time;
    localtime_s(&local_time, &now);

    return local_time;
}


void Time::Execute(const string& params) {
    tm local_time = getTime(params);

    strftime(buffer, sizeof(buffer), "%H:%M:%S", &local_time);

    this->Argument() = buffer;
}

void Time::Helper()
{
    CommandHelper h;
    h.TimeHelper();
}

void Date::Execute(const string& params) {
    tm local_time = getTime(params);

    strftime(buffer, sizeof(buffer), "%d.%m.%Y", &local_time);

    this->Argument() = buffer;
}

void Date::Helper()
{
    CommandHelper h;
    h.DateHelper();
}
