// pitch.h
//
// Pitch value class. Supports creation and setting via integer or
// duodecimal string representation. Has a value in the range 0-143.
#ifndef ___Vitamin_Pitch__
#define ___Vitamin_Pitch__

#include <string>

using namespace std;

class Pitch{
  public:
    typedef unsigned char t_pitch;

    Pitch(t_pitch value=0x48);
    Pitch(string value);

    t_pitch value() const;
    t_pitch value(const t_pitch new_value);
    t_pitch value(const string new_value);

    string to_string(bool upper=false) const;

  private:
    t_pitch val_;
};

#endif
