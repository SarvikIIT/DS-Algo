#include<bits/stdc++.h>
using namespace std;

#define GridSize 10

bool vis[GridSize][GridSize];
int grid [GridSize][GridSize];
int count;


bool isPossible(int x,int y){
	
	 if(x>=0 && x< GridSize){
			if(y>=0 && y< GridSize){
			if(grid[x][y] == 0 || vis[x][y] == true )return false;
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


	for(int i=0;i<GridSize;++i){
		for(int j=0;j<GridSize;++j){
			if(isPossible(i,j){
				if(vis[i][j]==false){
					count++;
					dfs(i,j);
				}

			}
		}
	}

	cout<<"Number of connected components in the Grid are: "<<count<<endl;

	return 0;
}