//
// Created by joaquin on 04/09/18.
//

#ifndef LEAPGESTURES_STATE_H
#define LEAPGESTURES_STATE_H
enum states{
    Begin,
    Principal,
    Free,
    sxhkd
};
extern enum states currentState;
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
