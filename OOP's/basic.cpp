#include<bits/stdc++.h>
#include "Hero.cpp"
using namespace std;

int main(){
    
    //Object Creation
    Hero Sarvik;

    //Statically Allocated
    Sarvik.SetHealth(50);
    cout<<Sarvik.GetHealth()<<endl;

    //Uses Pragma Packing and Greedy Alignment(Unlinke Pragma in C tries for minimum padding)
    cout<<sizeof(Sarvik)<<endl;


    //Dymaic Allocation(Struct using malloc equivalent)

    Hero* Sinu =new Hero;
    cout<<Sinu->GetHealth()<<endl;
    Sinu->SetHealth(50);
    cout<<Sinu->GetHealth()<<endl;

}