#ifndef monster_h
#define monster_h
#include <iomanip>


class monster{
private:
	string name;
	int hp,atk,def,potion,ss;
	static int alive;
public:
	void damaged(int d=1);
    void heal();
	monster(string="default",int=0,int=0,int=0,int=0);
	~monster();

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
		cout<<left<<setw(15)<<name<<" | HP "<<setw(3)<<hp<<" | ATK "<<setw(3)<<atk<<" | DEF "<<setw(3)<<def<<" | POT "<<setw(3)<<potion<<endl;
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
	cout<<left<<setw(15)<<n<<" entered! | HP "<<setw(3)<<hp<<" | ATK "<<setw(3)<<atk<<" | DEF "<<setw(3)<<def<<" | POT "<<setw(3)<<potion<<endl;
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

#endif

