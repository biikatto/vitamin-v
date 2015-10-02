#include "pan.h"

using namespace std;

Pan::Pan(t_pan value){
  this->value(value);
}

Pan::Pan(string value){
  this->value(value);
}

Pan::t_pan Pan::value() const{
  return val_;
}

Pan::t_pan Pan::value(t_pan new_value){
  // Set the pan via t_pan value.
  val_ = min(new_value, (unsigned char)0xe0);
  return val_;
}

Pan::t_pan Pan::value(string new_value){
  // Set the value via hexadecimal string representation.
  Pan::value(stoi(new_value, 0, 16));
  return val_;
}

string Pan::to_string(bool upper) const{
  // Return the hexadecimal representation of the pan value.
  char result[2];

  if(upper){
    sprintf(result, "%X", val_);
  }else{
    sprintf(result, "%x", val_);
  }

  return result;
}

const Pan::t_pan Pan::HARD_LEFT = 0x00;
const Pan::t_pan Pan::HALF_LEFT = 0x38;
const Pan::t_pan Pan::CENTER = 0x70;
const Pan::t_pan Pan::HALF_RIGHT = 0xa8;
const Pan::t_pan Pan::HARD_RIGHT = 0xe0;

