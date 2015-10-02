// velocity.h
//
// Velocity value class. Supports creation and setting via integer or
// hexadecimal string representation. Has a value in the range 0-0xff.
#ifndef ___Vitamin_Velocity__
#define ___Vitamin_Velocity__

#include <string>

using namespace std;

class Velocity{
  public:
    typedef unsigned char t_velocity;

    Velocity(t_velocity value=0xc0);
    Velocity(string value);

    t_velocity value() const;
    t_velocity value(const t_velocity new_value);
    t_velocity value(const string new_value);

    string to_string(bool upper=false) const;

  private:
    t_velocity val_;
};

#endif
