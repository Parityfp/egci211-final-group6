#ifndef queue_h
#define queue_h
#include "node2.h"
class Queue {
	NodePtr2 headPtr,tailPtr;
	int size;
public:
    void enqueue(int);
    //int dequeue();
    int qsize();
    int qminus();
    Queue();
    ~Queue();
};

int Queue::qsize(){
  return size;
}

int Queue::qminus(){
    int value=0;
    if(headPtr!=NULL){
        NodePtr2 t=headPtr;
        t->DeDuration();
        if(t->get_duration() < 1){
            headPtr=headPtr->get_next();
            if(headPtr==NULL) tailPtr=NULL;
            size--;
    
            value=t->get_value();
            delete t;
            return value;
        }else{
            value=t->get_value();
            switch(value){
                case 1: cout<<"@ Thanos Air Strike! | In "; break;
                case 2: cout<<"@ Thanos Medical Aid | In "; break; 
                case 3: cout<<"@ Thanos Strengthen! | In "; break; 
                default: break; //discard
            }
            cout<<t->get_duration()<<" Rounds!"<<endl;
            return 0;
        }
    }
    else{
        cout<<"@0 No Call Action Activate this round"<<endl;
        return 0;
    } 
}

void Queue::enqueue(int x){
  NodePtr2 new_node= new NODE2(x);
  if(new_node){ 
    /* Add head and tail for me please */
    /*1. connect & Change tail
    2. (may be) change head  when the queue is empty*/
    if(size>0) tailPtr->set_next(new_node);
    else headPtr=new_node;
    tailPtr=new_node;
    size++;
  }
}

/*int Queue::dequeue(){
  if(headPtr!=NULL){
    NodePtr t=headPtr;
    int value= t->get_value();
    headPtr=headPtr->get_next();
    if(headPtr==NULL) tailPtr=NULL;
    size--;
    
    delete t;
    return value;
  }
  cout<<"Empty queue"<<endl;
  return -1;
}*/


Queue::Queue(){
    headPtr=NULL;
    tailPtr=NULL;
    size=0;    
}
Queue::~Queue(){
    cout<<endl<<endl<<"Q destructing"<<endl; //testing only
    int x;
    while(size>0){
      x=qminus();
    }
}


#endif
