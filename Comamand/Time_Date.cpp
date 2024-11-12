#include <iostream>
#include <ctime>

#include "Time_Date.h"

tm Time_Date::getTime() {
    time_t now = time(0);

    tm local_time;
    localtime_s(&local_time, &now);
    
    return local_time;
}


void Time::execute(const std::string& args, std::string& input){

    tm local_time = getTime();
    
    char buffer[256];

    strftime(buffer, sizeof(buffer), "%H:%M:%S", &local_time);

    input = buffer;
}

void Date::execute(const std::string& args, std::string& input){
    tm local_time = getTime();

    char buffer[256];

    strftime(buffer, sizeof(buffer), "%d.%m.%Y", &local_time);

    input = buffer;
}

