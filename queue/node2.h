#include <iostream>
#ifndef node2_h
#define node2_h
using namespace std;
class NODE2{
     int data,duration; //attack type
    NODE2 *nextPtr;
public:
    NODE2(int);
    ~NODE2();
    void set_next(NODE2*);
    NODE2* get_next();
    int get_value();
    void DeDuration(){ duration--; }
    int get_duration(){ return duration; }
};
typedef NODE2* NodePtr2;


NODE2::NODE2(int x){
    data=x;
    switch(x){
        case 1: duration=3; cout<<"@ Thanos called Air Strike! | Casting in 3 rounds"<<endl; break; //aoe damage all by 5 HP
        case 2: duration=2; cout<<"@ Thanos called Medical Aid | Casting in 2 rounds"<<endl; break; //heal himself for 30*scaling HP
        case 3: duration=4; cout<<"@ Thanos called Strengthen! | Casting in 4 rounds"<<endl; break; //Buff his scaling for 1 round by *2
        default: break; //discard
    }
    nextPtr=NULL;
    //pPtr =NULL; not using doubly
}
NODE2* NODE2::get_next(){
    return nextPtr;

}

int NODE2::get_value(){
    int x = data;
    return x;
}

void NODE2::set_next(NODE2 *t){
     nextPtr=t;

}
NODE2::~NODE2(){
     //cout<<"deleting "<<data<<endl;
}

#endif
