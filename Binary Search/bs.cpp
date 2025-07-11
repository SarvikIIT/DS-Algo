#include<bits/stdc++.h>
using namespace std;

    int lowerbound(vector<int>&v,int target){
        int lo=0,hi=v.size()-1,mid;
        while(hi-lo>1){
            mid=(hi+lo)/2;
            if(v[mid]<target)lo=mid+1;
            else hi=mid;
        }
        //cout<<lo<<" "<<hi<<endl;
        if(v[lo]>=target)return lo;
        else if(v[hi]>=target)return hi;
        else return -1;
    }


    int upperbound(vector<int>&v,int target){
        int lo=0,hi=v.size()-1,mid;
        while(hi-lo>1){
            mid=(hi+lo)/2;
            if(v[mid]<=target)lo=mid+1;
            else hi=mid;
        }
        //cout<<lo<<" "<<hi<<endl;
        if(v[lo]>target)return lo;
        else if(v[hi]>target)return hi;
        else return -1;
    }



int main(){
   int n,target;
   cin>>n;
   cin>>target;
   vector<int> v(n);
   for(int i=0;i<n;++i)cin>>v[i];

    cout<<lowerbound(v,target)<<endl;
    cout<<upperbound(v,target)<<endl;
    
}