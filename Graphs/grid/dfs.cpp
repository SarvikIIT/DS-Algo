#include<bits/stdc++.h>
using namespace std;

#define GridSize 10

bool vis[GridSize][GridSize];
int grid [GridSize][GridSize];



bool isPossible(int x,int y){
	
	 if(x>=0 && x< GridSize){
			if(y>=0 && y< GridSize){
			if(vis[x][y]==true)return false;
			else
			return true;
		}
	}
	 return false;
}

int Dx[]={1 , 0 , -1 , 0};
int Dy[]={0 , 1 , 0 , -1};


void dfs(int x,int y){
	vis[x][y]=true;

	for(int i=0;i<4;++i){

		if(isPossible(x+Dx[i],y+Dy[i])){

			dfs(x+Dx[i],y+Dy[i]);
		}
	}	
}
int main(){

	for (int i = 0; i < GridSize; ++i)
        for (int j = 0; j < GridSize; ++j)
            cin >> grid[i][j];


	dfs(0,0);

	return 0;
}