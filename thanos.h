#ifndef thanos_h
#define thanos_h

#include "monster.h"
#include <cstdlib> //for rand
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

class Thanos {
private:
	int stones;
	float scaling;
	int hp,atk,team;
	// int n;
public:
	Thanos();
	~Thanos();
	void damaged(int d=1);
	void snap_finger(monster*[], int); 
	void punch(monster* &m);
	void steal_hp(monster *m[], int n);
	void steal_hp(monster* &m1);
	void operator++(); // increase the stone;
	void sort_hp(monster *m[], int n);
	int get_atk(){
		return atk;
	}
	int get_hp(){
		return hp;
	}
};


Thanos::Thanos() {
	cout<<"Thanos Scaling: ";
	cin>>scaling;
	stones = 0;
	hp = 300*scaling;
	atk=10*scaling;
	team=1;
}

Thanos::~Thanos() {
	cout << "Thanos have left to farm his potatoes" << endl;
}

void Thanos::operator++() {
	stones++;
	cout << "Thanos +1 stone!, now has " << stones << " stones" << endl;
}

void Thanos::damaged(int d){
	hp-= d;
	cout<<"Thanos -"<<setw(3)<<d<<"hp"<<" | Current hp:"<<hp<<endl;
}

void Thanos::punch(monster* &m) {
	(*m).damaged(atk);
}

//auto suck top 4 highest hp heros
void Thanos::steal_hp(monster *m[], int n){ 
	this_thread::sleep_for(std::chrono::milliseconds(500));
	cout<<endl<<"<==== Stealing HP ====>"<<endl;
	monster **sorted = new monster*[n]; 
	int j=0;
	for (int i = 0; i < n; i++) {
		if(m[i]!=nullptr)
		sorted[j] = m[i],j++;
	}
	sort_hp(sorted, j);
	for(int i = 0; i < 5; i++) {
		if(sorted[i]!=nullptr){
			hp += (*sorted[i]).getHp()-((*sorted[i]).getHp()-(atk/10));
			cout << "Thanos has consumed " << (*sorted[i]).getName() << "'s hp. +" << (*sorted[i]).getHp()-((*sorted[i]).getHp()-(atk/10)) << " (" << hp << ")" << endl;
			(*sorted[i]).setHp((*sorted[i]).getHp()-(atk/10));
		}
	}
	cout<<endl;
	delete [] sorted;
}

//steal hp from target
void Thanos::steal_hp(monster* &m1) {
	hp += ((*m1).getHp() - ((*m1).getHp() - (atk/2.5)));
	cout << "Thanos has consumed " << (*m1).getName() << "'s hp. +" << (*m1).getHp() - ((*m1).getHp() - (atk/2.5)) << " (" << hp << ")" << endl;
	(*m1).setHp((*m1).getHp() - (atk/2.5));
}


void Thanos::snap_finger(monster *m[], int n) {
	#include <iostream>

	if (stones >= 6) {
		cout << endl << endl;
		cout << "I..." << endl << endl;
		this_thread::sleep_for(chrono::milliseconds(1500));
		cout << "am..." << endl << endl;
		this_thread::sleep_for(chrono::milliseconds(1500));
		cout << "INEVITABLE! ██████ ██ ███" << endl << endl;
		this_thread::sleep_for(chrono::milliseconds(1500));
		for (int i = 0; i < 1000; i++) {
			cout << "████████████████████████████████████████████████████████████████";
			this_thread::sleep_for(chrono::milliseconds(1));
		}
		
		this_thread::sleep_for(chrono::milliseconds(1500));
		cout << endl << endl;
		// #ifdef _WIN32
		// system("cls");
		// #else
		//system("clear");
		// #endif
		for (int i = 0; i < n; i++) {
			if (m[i] != nullptr) {
				m[i]->PA();
				(*m[i]).setHp((*m[i]).getHp() / 2);
			}
		}
		cout << endl<<"↓↓↓↓↓↓↓↓↓↓↓ The Universe is now balanced ↓↓↓↓↓↓↓↓↓↓↓" << endl << endl;
		for (int i = 0; i < n; i++) {
			if (m[i] != nullptr) {
				m[i]->PA();
			}
		}
		cout << endl;
		stones -= 6;
	}
	else {
		cout << "Not enough stones" << endl;
	}

}

void Thanos::sort_hp(monster *m[], int n) {
	#include <iostream>

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if ((*m[j]).getHp() < (*m[j + 1]).getHp()) {
				monster *temp = m[j];
				m[j] = m[j + 1];
				m[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << (*m[i]).getName() << ": " << (*m[i]).getHp() << endl;
	}
}

#endif
