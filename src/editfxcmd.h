#include <string>
#include <map>

using namespace std;

class EditorFXCmd{

    public:
        EditorFXCmd(string cmd);

        string cmd();
        string cmd(string new_cmd);

    private:
        string _cmd;
        map<string, > cmds;
