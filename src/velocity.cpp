#include "velocity.h"

using namespace std;

Velocity::Velocity(t_velocity value){
  this->value(value);
}

Velocity::Velocity(string value){
  this->value(value);
}

Velocity::t_velocity Velocity::value() const{
  return val_;
}

Velocity::t_velocity Velocity::value(t_velocity new_value){
  // Set the velocity via t_velocity value.
  val_ = new_value;
  return val_;
}

Velocity::t_velocity Velocity::value(string new_value){
  // Set the value via hexadecimal string representation.
  val_ = min(stoi(new_value, 0, 16), 0xff);
  return val_;
}

string Velocity::to_string(bool upper) const{
  // Return the hexadecimal representation of the velocity value.
  char result[2];

  if(upper){
    sprintf(result, "%X", val_);
  }else{
    sprintf(result, "%x", val_);
  }

  return result;
}
