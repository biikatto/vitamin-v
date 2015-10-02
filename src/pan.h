// pan.h
//
// Pan value class. Supports creation and setting via integer or
// hexadecimal string representation. Has a value in the range 0-0xff.
#ifndef ___Vitamin_Pan__
#define ___Vitamin_Pan__

#include <string>
#include <algorithm>

using namespace std;

class Pan{
  public:
    typedef unsigned char t_pan;

    Pan(t_pan value=0x70);
    Pan(string value);

    t_pan value() const;
    t_pan value(const t_pan new_value);
    t_pan value(const string new_value);

    string to_string(bool upper=false) const;

    static const t_pan HARD_LEFT;
    static const t_pan HALF_LEFT;
    static const t_pan CENTER;
    static const t_pan HALF_RIGHT;
    static const t_pan HARD_RIGHT;

  private:
    t_pan val_;
};

#endif
