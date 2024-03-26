
#ifndef stack_h
#define stack_h
#include "node.h"
class Stack {
	NodePtr top;
	int size;
public:
    void push(float);
    float pop();
    Stack();
    ~Stack();
    void cleanse();
    float peek();
    int get_size(){
        return size;
    }
};


#include <iostream>

void Stack::push(float x){
    NodePtr new_node=new NODE(x);
    if(new_node){
        new_node->set_next(top);
        top=new_node;
        size++;
     }
     else std::cout<<"Stack overflow"<<std::endl;
}

float Stack::pop(){
        NodePtr t=top;
        float value = 0;
        if(size>0){
            value=t->get_value();
            top=t->get_next();
            delete t;
            size--;
        }
        return value;
	//be careful of the empty stack!!!
    }

float Stack::peek(){
    if(size>0) {
        return top->get_value();
    }
    else {
        return 1;
    }
}

Stack::Stack() {
    top = NULL;
    size = 0;
}

Stack::~Stack(){
    NodePtr t=top;
    std::cout<<"Clearing stack"<<std::endl;
    while(size>0)pop();
}

void Stack::cleanse(){
    NodePtr t=top;
    while(size>0)pop();
}


#endif
