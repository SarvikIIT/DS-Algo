#include<bits/stdc++.h>
#include "Hero.cpp"
using namespace std;

int main(){
    
    //Object Creation
    Hero Sarvik(70);



    //Statically Allocated
    Sarvik.SetHealth(50);
    cout<<Sarvik.GetHealth()<<endl;
    cout<<&Sarvik<<endl; //This keyword point to the object as can be seen using this and pointer of object comparision



    //Uses Pragma Packing and Greedy Alignment(Unlinke Pragma in C, tries for minimum padding)
    cout<<sizeof(Sarvik)<<endl;




    //Dymaic Allocation(Struct using malloc equivalent in C)
    Hero* Sinu =new Hero(100);
    cout<<Sinu->GetHealth()<<endl;
    Sinu->SetHealth(50);
    cout<<Sinu->GetHealth()<<endl;

    //Copy Constructor
    Hero Reena(Sarvik); //Copied the object
    Reena.print();


}