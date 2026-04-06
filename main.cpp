#include <iostream>

#include "src/timer.hpp"
#include <ctime>
#include <iostream>
#include <xmmintrin.h>
#include <bits/atomic_base.h>

using namespace std;

int main() {
  // Your driver program goes here


  bool useHas = false;
  int time = 3661;
  bool useAnd = false;
  if (time - 3600 >= 0) {
    useHas = (time / 3600 == 1);
    cout << time / 3600 << (useHas ? " hour " : " hours ");
    useAnd = true;
  }
  if (time - 60 >= 0 && time % 3600 >= 60) {
    if (useAnd) cout << "and ";
    useHas = (time % 3600 / 60 == 1);
    cout << (time % 3600) / 60 << (useHas ? " minute " : " minutes ");
    useAnd = true;
  }
  if (time % 60 > 0) {
    if (useAnd) cout << "and ";
    useHas = (time % 60 == 1);
    cout << time % 60 << (useHas ? " second " : " seconds ");
  }



  cout << endl;
  string userStr;
  Timer timer;
  timer.start();
  cout << "hi" << endl;
  // cin >> userStr;
  timer.stop();
  cout << timer.elapsed() << endl;
}
