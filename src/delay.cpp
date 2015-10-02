#include "delay.h"

using namespace std;

Delay::Delay(t_delay value){
  this->value(value);
}

Delay::Delay(string value){
  this->value(value);
}

Delay::t_delay Delay::value() const{
  return val_;
}

Delay::t_delay Delay::value(t_delay new_value){
  // Set the delay via t_delay value.
  val_ = new_value;
  return val_;
}

Delay::t_delay Delay::value(string new_value){
  // Set the value via hexadecimal string representation.
  val_ = min(stoi(new_value, 0, 16), 0xff);
  return val_;
}

string Delay::to_string(bool upper) const{
  // Return the hexadecimal representation of the delay value.
  char result[2];

  if(upper){
    sprintf(result, "%X", val_);
  }else{
    sprintf(result, "%x", val_);
  }

  return result;
}
