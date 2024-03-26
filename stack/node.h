//
//  linkedlist.h
//  LinkedList_simple
//
//  Created by Mingmanas Sivaraksa
//

#ifndef node_h
#define node_h
class NODE{
     float data;
    NODE *nextPtr;
public:
    NODE(float);
    ~NODE();
    void set_next(NODE*);
    NODE* get_next();
    float get_value();
};
typedef NODE* NodePtr;


NODE::NODE(float x){
    data=x;
    nextPtr=nullptr;
    //pPtr =nullptr; not using doubly
}
NODE* NODE::get_next(){
    return nextPtr;

}

#include <iostream>

float NODE::get_value(){
    
    return data;
}

void NODE::set_next(NODE *t){
    nextPtr = t;
}

NODE::~NODE(){
    // std::cout << "deleting " << data << std::endl;
}






#endif
