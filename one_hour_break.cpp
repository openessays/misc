/*
 * have a break every one hour during [9:00 AM, 6:00 PM]
 * g++ -std=c++14 -s -static -O2 -mwindows one_hour_break.cpp -o one_hour_break.exe
 *
 * date: 2022-12-27
 */

#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <thread>
using namespace std;
using namespace std::chrono_literals;

int main(int argc, char *argv[]) {
    while(true) {
        system("shutdown -s -f -t 3600");
        // check 1 minute earlier
        this_thread::sleep_for(59min);
        time_t now_ = std::chrono::system_clock::to_time_t(chrono::system_clock::now());
        struct tm *now = localtime(&now_);
        // [0, 23]
        int hour = now->tm_hour;
        if(hour < 9 || hour > 18) {
            break;
        }
        system("shutdown -a");
    }

    return 0;
}
