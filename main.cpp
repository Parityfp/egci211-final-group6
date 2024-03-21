#include <iostream>
// #include <
using namespace std;

#include "thanos.h"
#include "monster.h"
#define DELAY 1

void target(int,int);

int main(int argc, char* argv[]) {
  Thanos T;
    int i,n,j=1;
    cout<<"How many Sheilds Agent supports: ";
    cin>>n;

    //story
    cout<<endl<<endl<<"---------------------------------------------------------------"<<endl;
    cout<<"Once upon a time..."<<endl;
    cout<<"In Jeffery's back yard"<<endl;
    cout<<"There is a battle brewing, of the finale between a long decade of conflicts, between the IRS officers, and the potato farmer";
    cout<<" Thanos!"<<endl<<endl;
    cout<<"Thanos has been evading taxes for decades, this time, the officers have had enough! They decide to end this here and now!"<<endl;
    cout<<"And thus, the fighting commence!"<<endl;
    cout<<"---------------------------------------------------------------"<<endl;
    int con;
    cout<<"-----------------Input any number to continue ";
    cin>>con;
    cout<<endl;
    

    monster **m = new monster*[n+5]; 

    //(name, hp, atk, def, potion)
    cout<<"The IRS Heroes team:"<<endl;
    m[0] = new monster("Joe",25,5,5,2);
    m[1] = new monster("Copper man",30,5,20,1);
    m[2] = new monster("Dr. Normal",25,10,0,5);
    m[3] = new monster("Gecko man",20,20,0,3);
    m[4] = new monster("Captain Britain",40,1,5,2);

  for(int i = 0; i < n; i++){
       m[i+5] = new monster("Sheild Agent " + to_string(j), 15, 5, 0, 1);
	j++;
  }

  //----------main game----------
  cout<<endl<<"Thanos Available Actions (type corresponding numbers):"<<endl;
  cout<<"1 punch: deal atk damage to a targeted hero"<<endl;
  cout<<"2 steal auto: auto steal HP of the top 5 highest hp heroes"<<endl;
  cout<<"3 steal target: target steal HP of a targeted hero"<<endl;
  cout<<"4 Snap Finger (need 6 stones): half every hero HP"<<endl;
  cout<<endl<<endl;
  int x,A,LO,Halive,round=1;

  cout<<"-----------------Input any number to start the fight ";
    cin>>con;
    cout<<endl<<endl;

  do{
    bool wiped=1;
    Halive=n+5;
    cout<<endl<<"-------ROUND "<<round<<"!-------"<<endl;
    cout<<endl<<"H|------Heroes Turn!------"<<endl<<endl;
    for(i=0;i<n+5;i++){
      if(m[i]!=nullptr){
        // inner if is probably not needed, delete later.
        if(m[i]->getHp()>0){
          if(m[i]->getHp()<=10) m[i]->heal();
          else cout<<left<<setw(15)<<m[i]->getName()<<" attack! | ", T.damaged(m[i]->get_atk());
        }
      }
    }

    if(T.get_hp()<=0) break;
    cout<<endl<<"T|------Thanos Turn!------"<<endl<<endl;
    for(i=0;i<2;i=i){
      cout<<"Input Action: ";
      cin>>A;
      switch(A){
        case 1:
          for(j=0;j<n+5 ;j++) if(m[j]!=nullptr)cout<<j<<". ", m[j]->PA();
          cout<<"Target Number: ";
          cin>>x;
          cout<<endl;
          if(m[x]!=nullptr)T.punch(m[x]);
          else cout<<"You just punched a corpse!"<<endl;
          cout<<endl;
          for(j=0;j<n+5;j++){
            if(m[j]!=nullptr){
              if(m[j]->getHp()<=0) {
                cout<<m[j]->getName()<<" just DIED!"<<endl, ++T;
                Halive--;
                delete m[j];
                m[j]=nullptr;
              } 
            }
          }
          i++;
          this_thread::sleep_for(std::chrono::milliseconds(1000));
          break;
        case 2:
          cout<<endl;
          T.steal_hp(m,n+5);
          cout<<endl;
          i++;
          break;
        case 3:
          for(j=0;j<n+5 ;j++) if(m[j]!=nullptr)cout<<j<<". ", m[j]->PA();
          cout<<"Target Number: ";
          cin>>x;
          cout<<endl;
          T.steal_hp(m[x]);
          i++;
          break;
        case 4:
          T.snap_finger(m,n+5);
          i++;
          break;
        default:
          cout<<"Action not recognised"<<endl, LO=1;
      }
    }

    for(i=0;i<n+5;i++){
      if(m[i]!=nullptr) wiped=0;
    }
    if(wiped==1) break;
    round++;
  }while(Halive > 0 && T.get_hp() > 0);


  cout<<endl<<"---------------------------------"<<endl<<endl;
  if (T.get_hp()<=0) cout<<"HEROES WIN!!! Thanos is deafeated! He now need to pay the taxes!"<<endl;
  else cout<<"THANOS WIN!!! Heroes are deafeated!"<<endl;
  cout<<endl<<"---------------------------------"<<endl;


  for(i=0;i<n+5;i++) delete m[i]; 

}
