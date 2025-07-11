#include<bits/stdc++.h>
using namespace std;
class Hero{

    /*
        Access Modifier
        Public -->Kahi bhi
        Private -->Sirf Class me (Default)-->To change use getter setter
        Protected -->Child Class me
    */

    public:
    string name;

     //Getter
     int GetHealth(){
        return health;
    }
    //Setter
    void SetHealth(int hp){
        health=hp;
    }
    bool GodMode;


    private:
    int health=1;
    bool KeepSecret;

    //Constructor & Parameterised Constructor  ***Multiple Constructor can be created but jo sabse upar wala suitable hai wo chalega***
    //Ek bhi custom constructor kills the default one 
    public:
    Hero(){}
    Hero(int health){
        cout<<"Constuctor Called \n"<<"This points to: "<<this<<endl;
        
        this->health=health;  /* if variable is named health and I say health=health, due to variable scoping the health of class isn't
                    seen and the same variable is reassigned to it hence for sam name we use this keyword */
    }

    /* Hero(int health){
        cout<<"Constuctor Called \n";               
                                                            //This is wrong implementation as health of 
                                                            class isnt being accessed but the variable
        health=health;};
        */



    void print(){
        cout<<this->health<<endl;
    }
    
    
    //Custom Copy Constructor
    Hero(Hero &temp){  /*Amperhesand kyuki if not passed function called by value... 
                        ab jab call by value to copy constructor on hoga jo fir same infinite loop me aa jayega hence pass
                        by reference is only allowed*/
        this->health=temp.health;
        cout<<"Custom Called"<<endl;
    }

};