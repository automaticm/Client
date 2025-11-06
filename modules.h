#include "main.h"
#include <vector>

class Module{
    public:
    std::string name;
    int key_code;
    bool enabled;
    virtual void init(){}
    virtual void toggle(){}
    virtual void on_enable(){}
    virtual void on_disable(){}
    Module(){
        // Initializing here
    }
};

extern std::vector<Module*> mods;

class Fly : public Module{

};