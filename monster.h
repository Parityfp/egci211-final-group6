#ifndef monster_h
#define monster_h
#include <iomanip>
#include "thanos.h"


class monster{
private:
	string name;
	int hp,atk,def,potion,ss,type;
	static int alive;
public:
	void damaged(int d=1);
    void heal();
	monster(string="default",int=0,int=0,int=0,int=0);
	monster(int=1,int=0,int=0,int=0,int=0, string="default");
	~monster();

	void action(monster *m, Thanos *T);
	void operator++(){
		ss++;
	}//ss is to memorised if the hero is dead or not

	int get_ss(){
		return ss;
	}

	void setHp(int h){
		hp=h;
	}
	int getHp(){
		return hp;
	}
	int get_atk(){
		return atk;
	}
		
	void setName(string n){
		name=n;
	}
	string getName(){
		return name;
	}
	void PA(){
		cout<<left<<setw(30)<<name<<" | HP "<<setw(3)<<hp<<" | ATK "<<setw(3)<<atk<<" | DEF "<<setw(3)<<def<<" | POT "<<setw(3)<<potion<<endl;
	}

};

monster::~monster(){
	// cout<<"A monster "<<name<<" With hp "<<hp<<" is dead"<<endl;
}

monster::monster(string n, int h, int a, int d, int p){
	name=n;
	hp=h;
	atk=a;
	def=d;
	potion=p;
	ss=0;
	cout<<left<<setw(30)<<n<<" entered! | HP "<<setw(3)<<hp<<" | ATK "<<setw(3)<<atk<<" | DEF "<<setw(3)<<def<<" | POT "<<setw(3)<<potion<<endl;
}
monster::monster(int t, int a, int d, int p, int h, string n){
	name=n;
	hp=h;
	atk=a;
	def=d;
	potion=p;
	ss=0;
	type=t;
	cout<<left<<setw(30)<<n<<" entered! | HP "<<setw(3)<<hp<<" | ATK "<<setw(3)<<atk<<" | DEF "<<setw(3)<<def<<" | POT "<<setw(3)<<potion<<endl;
}


void monster::damaged(int d){
	int true_dmg = (d*(100-def))/100; //reduced damage (from monster defense)
	hp-= true_dmg;
	if(hp>=0) cout<<name<<" -"<<true_dmg<<"hp"<<" | Current hp: "<<hp<<endl;
	else cout<<name<<" -"<<true_dmg<<"hp"<<" | Current hp: 0"<<endl;
}

void monster::heal(){
	if(potion>0){
		hp+=10;
		potion--;
	}
	cout<<left<<setw(15)<<name<<" healed! | ";
	cout<<" hp = "<<setw(3)<<hp;
	cout<<" / "<<" potion = "<<setw(3)<<potion;
	cout<<endl;
}

// void monster::action(monster *m, Thanos *T){
// 	if(type==1){
// 		int target = rand()%5;
// 		T->damaged(atk);
// 	}
// 	else if(type==2){
// 		int target = rand()%5;
// 		m[target]->damaged(atk);
// 	}
// 	else if(type==3){
// 		int target = rand()%5;
// 		m[target]->damaged(atk);
// 	}
// 	else if(type==4){
// 		for(int i=0;i<5;i++){
// 			m[i]->damaged(atk);
// 		}
// 	}
// }

#endif

