#include<bits/stdc++.h>
#include <iomanip>
using namespace std;

#define GridSize 10

bool vis[GridSize][GridSize];
int grid[GridSize][GridSize];
queue<pair<int,int>> q; 
int dis[GridSize][GridSize];
int Dx[] = {1 , 1 , 1 , 0 , 0 , -1 , -1 , -1 };
int Dy[] = {-1 , 0 , 1 , 1 , -1 , 1 , 0 , -1 };

bool isPossible(int x,int y){
    if(x >= GridSize || x < 0 || y >= GridSize || y < 0 || vis[x][y] == true || grid[x][y] == 0)
        return false;
    return true;
}

void bfs(int x,int y){

// Fixed for calling multiple times:
    while(!q.empty()) q.pop();
    memset(vis,false,sizeof(vis));
    for(int i=0;i<GridSize;i++)
        for(int j=0;j<GridSize;j++)
            dis[i][j] = -1;


// Code starts from here:

    q.push({x,y});
    dis[x][y] = 0;
    vis[x][y] = true;

    while(!q.empty()){
        int curr_x = q.front().first;
        int curr_y = q.front().second;
        q.pop();
        for(int i=0;i<8;i++){
            int nx = curr_x + Dx[i];
            int ny = curr_y + Dy[i];
            if(isPossible(nx,ny)){
                dis[nx][ny] = dis[curr_x][curr_y] + 1;
                vis[nx][ny] = true;
                q.push({nx,ny});
            }
        }
    }
}

int main(){
    for(int i=0;i<GridSize;i++)
        for(int j=0;j<GridSize;j++)
            grid[i][j] = 1;

    int start_x = 3, start_y = 3;

    bfs(start_x,start_y);

    cout<<"Distance grid from ("<<start_x<<","<<start_y<<"):\n";
    for(int i=0;i<GridSize;i++){
        for(int j=0;j<GridSize;j++){
            if(dis[i][j]==-1)
                cout<<setw(3)<<" -";
            else
                cout<<setw(3)<<dis[i][j];
        }
        cout<<"\n";
    }

    return 0;
}
