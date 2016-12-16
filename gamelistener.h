#ifndef GAMELISTENER_H
#define GAMELISTENER_H

#include <Leap.h>

class GameListener : public Leap::Listener
{
public:
    virtual void onInit(const Leap::Controller&);
    virtual void onConnect(const Leap::Controller&);
    virtual void onDisconnect(const Leap::Controller&);
    virtual void onExit(const Leap::Controller&);
    virtual void onFrame(const Leap::Controller&);
    virtual void onFocusGained(const Leap::Controller&);
    virtual void onFocusLost(const Leap::Controller&);
};

#endif // GAMELISTENER_H
