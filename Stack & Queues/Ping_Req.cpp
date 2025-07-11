#include<bits/stdc++.h>
using namespace std;
queue<int>q;
    int ping(int x){
        q.push(x);
        if(q.back()+3000<=x){
            q.pop();
        }
        return q.size()
    }


int main(){
        





}