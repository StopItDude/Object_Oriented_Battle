#include <iostream>
#include <vector>
#include <ctime>
#include <numeric>
#include <math.h>
#include <string>
#include <time.h>

using namespace std;

class Warrior{
private: //private fields
    string name;
    double health;
    double attack;
    double defense;

public: //public fields
    string GetName(){return name;}
    void SetName(string name){this->name = name;}
    double GetHealth(){return health;}
    void SetHealth(double health){this->health = health;}
    double GetAttack(){return attack;}
    void SetAttack(double attack){this->attack = attack;}
    double GetDefense(){return defense;}
    void SetDefense(double defense){this->defense = defense;}

    Warrior(string, double, double, double); //constructor

    Warrior(); //overload constructor

    ~Warrior(); //destructor
};

Warrior::Warrior(string name, double health, double attack, double defense){ //constructor
    this->name = name;
    this->health = health;
    this->attack = attack;
    this->defense = defense;
}

Warrior::Warrior(){ //overload constructor
    this->name = "";
    this->health = 0;
    this->attack = 0;
    this->defense = 0;
}

Warrior::~Warrior(){ //destructor
}

class Battle{
public:
    static void StartFight(Warrior warrior1, Warrior warrior2){
        int dispAttack; //saves randomly generated attack value to display

        srand((unsigned)time(NULL));
        while(warrior1.GetHealth() > 0 && warrior2.GetHealth() > 0){
            dispAttack = floor((warrior2.GetAttack()-warrior1.GetDefense())+(10*(float)rand()/RAND_MAX)); //generate random attack value
            warrior1.SetHealth(warrior1.GetHealth()-dispAttack); //sets new health value based on random attack value

            if(warrior1.GetHealth()<0){ //if health is negative, set health to 0
                warrior1.SetHealth(0);
            }

            cout << warrior2.GetName() << " attacks " << warrior1.GetName() << " for " << dispAttack << endl; //display attack outcome to the user

            cout << warrior1.GetName() <<  " has " << warrior1.GetHealth() << " health remaining" << endl;

            if(warrior1.GetHealth()==0){ //if health is 0, end the fight
                break;
            }

            dispAttack = floor((warrior1.GetAttack()-warrior2.GetDefense())+(10*(float)rand()/RAND_MAX)); //generate random attack value
            warrior2.SetHealth(warrior2.GetHealth()-dispAttack); //sets new health value based on random attack value

            if(warrior2.GetHealth()<0){ //if health is negative, set health to 0
                warrior2.SetHealth(0);
            }

            cout << warrior1.GetName() << " attacks " << warrior2.GetName() << " for " << dispAttack << endl; //display attack outcome to the user

            cout << warrior2.GetName() <<  " has " << warrior2.GetHealth() << " health remaining" << endl;

            if(warrior2.GetHealth()==0){ //if health is 0, end the fight
                break;
            }
        }

        if(warrior1.GetHealth()==0){
            cout << warrior2.GetName() << " Wins!" << endl;
        }
        else if(warrior2.GetHealth()==0){
            cout << warrior1.GetName() << " Wins!" << endl;
        }
    }

    Battle(); //overload constructor

};

Battle::Battle(){ //overload constructor
}

int main()
{

    Warrior thor("Thor", 100, 30, 15);
    Warrior hulk("Hulk", 135, 25, 10);

    Battle::StartFight(thor, hulk);

    return 0;
}
