#ifndef ___Vitamin_Note__
#define ___Vitamin_Note__

#include <string>
#include "pitch.h"
#include "velocity.h"
#include "pan.h"
#include "delay.h"

using namespace std;

class Note{

    public:

        typedef unsigned char
            t_delay;

        Note(
                Pitch::t_pitch pitch=0x00,
                Velocity::t_velocity velocity=0x00,
                Pan::t_pan pan=0x70,
                t_delay delay=0x00,
                int editor_fx_cmd=0x00);

        Note(
                string pitch,
                Velocity::t_velocity velocity=0x00,
                Pan::t_pan pan=0x70,
                t_delay delay=0x00,
                int editor_fx_cmd=0x00);

        Note(
                Pitch pitch,
                Velocity::t_velocity velocity=0x00,
                Pan::t_pan pan=0x70,
                t_delay delay=0x00,
                int editor_fx_cmd=0x00);

        Pitch& pitch();
        Pitch& pitch(Pitch new_pitch);
        Pitch& pitch(Pitch::t_pitch new_pitch);
        Pitch& pitch(string new_pitch);

        Velocity& velocity();
        Velocity& velocity(Velocity new_velocity);
        Velocity& velocity(unsigned char new_velocity);
        Velocity& velocity(string new_velocity);

        Pan& pan();
        Pan& pan(Pan new_pan);
        Pan& pan(unsigned char new_pan);
        Pan& pan(string new_pan);

        t_delay delay();
        t_delay delay(unsigned char new_delay);

        int editor_fx_cmd();  // change this to EditorFXCmd later
        int editor_fx_cmd(int new_cmd);

        string editor_fx_cmd_str(bool upper=true);

    private:
        Pitch _pitch;
        Velocity _velocity;
        Pan _pan;
        t_delay _delay;
        int _editor_fx_cmd;  // change this to EditorFXCmd later
};

#endif
