//
// Created by joaquin on 04/09/18.
//

#ifndef LEAPGESTURES_STATE_H
#define LEAPGESTURES_STATE_H
#include <map>
#include <vector>
using namespace std;

enum states{
//    InterfaceOne,
//    InterfaceTwo,
    Begin, // When process begi
    Principal, // when interacts with principal window(to select, create gestures among others)
    Free, // when grab gestures to bind with commands
    Binder, // to bind command with gesture
    sxhkd
};
extern enum states currentState;
extern vector< map<string,string> > bindMap;
//
//class State{
//public:
//    enum states{
//        Begin,
//        Principal,
//        Free
//    };
//    void setCurrentState(states newState){
//        currentState = newState;
//    }
//    int getCurrentState(){
//        return currentState;
//    }
//    states currentState;
//};
#endif //LEAPGESTURES_STATE_H
