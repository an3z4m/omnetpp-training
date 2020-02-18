#include <string.h>
#include <omnetpp.h>

using namespace omnetpp;

class Player : public cSimpleModule{
protected:
    cMessage *timeOutEvent;
    void initialize(){
        if (strcmp("p1", getName()) == 0) {
            // create and send first message on gate "out". "tictocMsg" is an
            // arbitrary string which will be the name of the message object.
            cMessage *msg = new cMessage("pingPongMsg");
            send(msg, "out");
        }
        timeOutEvent = new cMessage("timeOutEvent");
    }
    void handleMessage(cMessage *msg){
        if(msg == timeOutEvent) {
            EV<<"timeout expired: send a new message!";
            send(new cMessage("pingPongMsg"), "out");
        }else{
            if (uniform(0, 1) < 0.1) {
                EV << "\"Losing\" message.\n";
                bubble("message lost");  // making animation more informative...
                delete msg;
            }else{
                send(msg, "out");
                cancelEvent(timeOutEvent);
                scheduleAt(simTime()+1.0, timeOutEvent);
            }
        }
        /*if (msg->isSelfMessage()){
            if (uniform(0, 1) < 0.1) {
                EV << "\"Losing\" message.\n";
                bubble("message lost");  // making animation more informative...
                delete msg;
            }else{
                send(msg, "out");
                scheduleAt(simTime()+1.0, msg);
            }
        }else{
            scheduleAt(simTime()+1.0, msg);
        }*/
    }
};

Define_Module(Player);
