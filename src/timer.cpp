#include <string>
#include <ctime>
#include "timer.hpp"

#include <algorithm>
#include <iostream>
using namespace std;
Timer::Timer() {
   state = STOPPED;
   elapsedTime = 0;
}

void Timer::start() {
   if (state == STOPPED) {
      state = RUNNING;
      time(&timeStart);
   }
}
void Timer::stop() {
   if (state == RUNNING) {
      state = STOPPED;
      time(&timeEnd);
   }
}
int Timer::elapsed() {
   if (state == STOPPED) {
      state = STOPPED;
      time(&timeEnd);
   }
   return difftime(timeEnd, timeStart);
}

void Timer::pretty_print() {
   int time = elapsed();
   bool useHas = true;
   if (time == 0) {
      std::cout << "No time ";
      useHas = true;
   } else {
      bool useAnd = false;
      if (time - 3600 >= 0) {
         useHas = (time / 3600 == 1);
         cout << time / 3600 << (useHas ? " hour " : " hours ");
         useAnd = true;
      }
      if (time - 60 >= 0 && time % 3600 >= 60) {
         if (useAnd) cout << " and ";
         useHas = (time % 3600 / 60 == 1);
         cout << (time % 3600) / 60 << (useHas ? " minute " : " minutes ");
         useAnd = true;
      }
      if (time % 60 > 0) {
         if (useAnd) cout << " and ";
         useHas = (time % 60 == 1);
         cout << time % 60 << (useHas ? " second " : " seconds ");
      }
   }
   if (useHas) {
      cout << "has passed.";
   } else {
      cout << "have passed.";
   }
   std::cout << std::endl;
}