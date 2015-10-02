#include "pitch.h"

using namespace std;

Pitch::Pitch(t_pitch value){
  this->value(value);
}

Pitch::Pitch(string value){
  this->value(value);
}

Pitch::t_pitch Pitch::value() const{
  return val_;
}

Pitch::t_pitch Pitch::value(t_pitch new_value){
  // Set the pitch via t_pitch value.
  val_ = new_value;
  if(val_ > 143){ val_ = 143; }
  return val_;
}

Pitch::t_pitch Pitch::value(string new_value){
  // Set the value via duodecimal string representation.
  unsigned char pitch_value = 0;
  try{
    pitch_value += stoi(new_value.substr(0,1), nullptr, 12) * 12;
  }
  catch(const invalid_argument& ia){
    pitch_value += 110;
  }
  try{
    pitch_value += stoi(new_value.substr(1,1), nullptr, 12);
  }
  catch(const invalid_argument& ia){
    pitch_value += 11;
  }
  val_ = pitch_value;
  return val_;
}

string Pitch::to_string(bool upper) const{
  // Return the duodecimal representation of the pitch value.
  char result[2];

  if(upper){
    sprintf(result, "%X%X", val_ / 12, val_ % 12);
  }else{
    sprintf(result, "%x%x", val_ / 12, val_ % 12);
  }

  return result;
}
