// delay.h
//
// Delay value class. Supports creation and setting via integer or
// hexadecimal string representation. Has a value in the range 0-0xff.
#ifndef ___Vitamin_Delay__
#define ___Vitamin_Delay__

#include <string>

using namespace std;

class Delay{
  public:
    typedef unsigned char t_delay;

    Delay(t_delay value=0xc0);
    Delay(string value);

    t_delay value() const;
    t_delay value(const t_delay new_value);
    t_delay value(const string new_value);

    string to_string(bool upper=false) const;

  private:
    t_delay val_;
};

#endif
