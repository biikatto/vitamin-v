#include "note.h"

using namespace std;

Note::Note(
    Pitch::t_pitch pitch,
    Velocity::t_velocity velocity,
    Pan::t_pan pan,
    t_delay delay,
    int editor_fx_cmd){
  this->pitch(pitch);
  this->velocity(velocity);
  this->pan(pan);
  this->delay(delay);
  this->editor_fx_cmd(editor_fx_cmd);
}

Note::Note(
    string pitch,
    Velocity::t_velocity velocity,
    Pan::t_pan pan,
    t_delay delay,
    int editor_fx_cmd){
  this->pitch(pitch);
  this->velocity(velocity);
  this->pan(pan);
  this->delay(delay);
  this->editor_fx_cmd(editor_fx_cmd);
}

Note::Note(
    Pitch pitch,
    Velocity::t_velocity velocity,
    Pan::t_pan pan,
    t_delay delay,
    int editor_fx_cmd){
  this->pitch(pitch);
  this->velocity(velocity);
  this->pan(pan);
  this->delay(delay);
  this->editor_fx_cmd(editor_fx_cmd);
}


Pitch& Note::pitch(){
  return _pitch;
}

Pitch& Note::pitch(Pitch new_pitch){
  _pitch = new_pitch;
  return _pitch;
}

Pitch& Note::pitch(Pitch::t_pitch new_pitch){
  _pitch.value(new_pitch);
  return _pitch;
}

Pitch& Note::pitch(string new_pitch){
  _pitch.value(new_pitch);
  return _pitch;
}


Velocity& Note::velocity(){
  return _velocity;
}

Velocity& Note::velocity(Velocity new_velocity){
  _velocity = new_velocity;
  return _velocity;
}

Velocity& Note::velocity(unsigned char new_velocity){
  _velocity.value(new_velocity);
  return _velocity;
}


Pan& Note::pan(){
  return _pan;
}

Pan& Note::pan(unsigned char new_pan){
  // pan is kinda funny cause we want a nice center value,
  // nice end values, and a way to represent it with 2 
  // hexadecimal digits.
  //
  // our solution is to constrain pan to 0 >= pan >= 0xe0, so
  // hard left is 0x00, middle is 0x70, and hard right is 0xe0.
  if(new_pan < 0xe0){
    _pan = new_pan;
  }else{
    _pan = 0xe0;
  }
  return _pan;
}


Note::t_delay Note::delay(){
  return _delay;
}

Note::t_delay Note::delay(unsigned char new_delay){
  _delay = new_delay;
  return _delay;
}


int Note::editor_fx_cmd(){
  // this one is going to be changed later
  return _editor_fx_cmd;
}

int Note::editor_fx_cmd(int new_editor_fx_cmd){
  _editor_fx_cmd = new_editor_fx_cmd;
  return _editor_fx_cmd;
}


string Note::editor_fx_cmd_str(bool upper){
  // this will change later, when editor fx cmds are implemented.
  char result[2];
  if(upper){
    sprintf(result, "%X", _editor_fx_cmd);
  }else{
    sprintf(result, "%x", _editor_fx_cmd);
  }

  return result;
}
