#include <iostream>
using namespace std;

class Command {
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
    virtual void undo() = 0;
};

class Light {
private:
    string location;
public:
    Light(string location) : location(location) {}
    void on() {
        cout << "Light is on at " << location << endl;
    }

    void off() {
        cout << "Light is off at " << location << endl;
    }

};

class LightOnCommand : public Command {
private:
    Light* light;
public:
    LightOnCommand(Light* light) : light(light){}

    void execute() override{
        light->on();
    }

    void undo() override {
        light->off();
    }
};



class LightOffCommand : public Command {
private:
    Light* light;
public:
    LightOffCommand(Light* light) : light(light) {}

    void execute() override {
        light->off();
    }

    void undo() override {
        light->on();
    }
};


class RemoteControll {
private:
    Command* command;
public:
    void setCommand(Command* cmd) {
        command = cmd;
    }

    void pressButton() {
        if (command) {
            command->execute();
        }
    }

    void pressUndo() {
        if (command) {
            command->undo();
        }
    }

};



int main()
{
    Light* livivngRoomLight = new Light("Living Room");
    LightOnCommand* lightOn = new LightOnCommand(livivngRoomLight);
    LightOffCommand* lightOff = new LightOffCommand(livivngRoomLight);
    RemoteControll* remote = new RemoteControll();
    remote->setCommand(lightOn);
    remote->pressButton();





}
