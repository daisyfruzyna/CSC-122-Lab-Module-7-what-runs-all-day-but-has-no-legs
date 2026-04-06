#include <string>

class Timer {
  enum state {
    STOPPED,
    RUNNING
  };

  time_t timeStart{};
  time_t timeEnd{};
  int elapsedTime;
  state state;

  public:
  Timer();
  void start();
  void stop();
  void pretty_print();
  int elapsed();

};