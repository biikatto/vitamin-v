#include "editorfxcmd.h"

using namespace std;

EditorFxCmd::EditorFxCmd(string cmd){
    this->cmd(cmd);

    cmds.push_back("ZTxx"); // Tempo
    cmds.push_back("ZLxx"); // Lines per beat
    cmds.push_back("ZKxx"); // Ticks per line
    cmds.push_back("ZGxx"); // Groove toggle
    cmds.push_back("ZBxx"); // Break pattern
    cmds.push_back("ZDxx"); // Delay pattern playback
}
