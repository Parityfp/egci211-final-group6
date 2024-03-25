#include <iostream>
#include <random>
using namespace std;

#include "thanos.h"
#include "monster.h"
#include "stack.h"
#define DELAY 1
const float e = 2.71828182845904523536;

void target(int,int);

int main(int argc, char* argv[]) {
  Thanos T;
  Stack s;
    int i,n,j=1,HpDebuff=0;
    random_device rd;

    uniform_int_distribution<> distrib(1, 4);

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
      int rand = distrib(rd);
      switch (rand){
        case 1:
          m[i+5] = new monster(1, 5, 0, 1, 20, "Support Agent " + to_string(j) + " (debuffer)");
          break;
        default:
          m[i+5] = new monster("Support Agent " + to_string(j), 15, 5, 0, 1);
          break;
      }
	j++;
  }

  //----------main game----------
  cout<<endl<<"Thanos Available Actions (type corresponding numbers):"<<endl;
  cout<<"1 Punch: deal atk damage to a targeted hero"<<endl;
  cout<<"2 Steal auto: auto steal HP of the top 5 highest hp heroes"<<endl;
  cout<<"3 Steal target: target steal HP of a targeted hero"<<endl;
  cout<<"4 Snap Finger (need 6 stones): half every hero HP"<<endl;
  cout<<"6 Cleanse all debuffs"<<endl;
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
    int original_hp = T.get_hp(), original_atk = T.get_atk();
    for(i=0;i<n+5;i++){
      if(m[i]!=nullptr){
        // inner if is probably not needed, delete later.
        if(m[i]->getHp()>0){
          if(m[i]->getHp()<=10) m[i]->heal();
          else {
            switch(m[i]->getType()){
              case 1:
                cout << m[i]->getName() << " debuff! | ";
                s.push(1/pow(e, 0.05*(s.get_size()+1)));
                cout<<s.peek()<<endl;
                HpDebuff = (1-s.peek())*original_hp;
                T.set_hp(s.peek()*original_hp);
                T.set_atk(s.peek()*original_atk);
                break;
              default:
                cout<<left<<setw(15)<<m[i]->getName()<<" attack! | ", T.damaged(m[i]->get_atk());
                break;
            }
          }
          //cout<<left<<setw(15)<<m[i]->getName()<<" attack! | ", T.damaged(m[i]->get_atk());
        }
      }
    }

    if(s.get_size() > 0){
    cout<<endl<<endl;
    cout << "Thanos Debuffs (atk & hp): -" << fixed << setprecision(1) << 100 * (1 - s.peek()) << "% (" << s.get_size() << " stacks)"<<endl;
    cout << "HP: " << T.get_hp() << " (-" << HpDebuff << ")"<<endl;
    cout << "ATK: " << T.get_atk() << " (-" << floor((1-s.peek())*T.get_atk()) << ")"<<endl;
    cout << endl;
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
        case 6:
          cout<<"Thanos has been cleansed (+ "<<HpDebuff<<" HP, "<< floor((1-s.peek())*T.get_atk()) << " ATK)"<<endl;
          T.set_hp(T.get_hp()+HpDebuff);
          HpDebuff = 0;
          T.set_atk(T.get_atk()+floor((1-s.peek())*T.get_atk()));
          s.cleanse();
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
