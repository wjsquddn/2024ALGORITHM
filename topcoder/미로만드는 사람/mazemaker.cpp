#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int board[50][50];

int solution(vector<string> v,int sy,int sx,vector<int> movey,vector<int> movex){
    int sizex=v[0].size();
    int sizey = v.size();
    for(int i=0;i<50;i++){
        for(int j=0;j<50;j++){
            board[i][j] = -1;
        }
    }
    board[sy][sx] = 0;
    queue <pair<int,int>> q;
    q.push(make_pair(sx,sy));
    while(!q.empty()){
        pair<int,int> cp = q.front();
        q.pop();
        int nextx,nexty;
        for(int i=0;i<movey.size();i++){
            nextx = cp.first+movex[i];
            nexty = cp.second+movey[i];
            if(nextx>=0&&nextx<sizex&&nexty>=0&&nexty<sizey&&board[nexty][nextx]==-1&&v[nexty][nextx]=='.'){
                q.push(make_pair(nextx,nexty));
                board[nexty][nextx] = board[cp.second][cp.first]+1;
            }
        }
    }

    int answer = -1;
    for(int i=0;i<sizey;i++){
        for(int j=0;j<sizex;j++){
            cout<<board[i][j]<<" ";
            
            if(v[i][j]=='.'){
                if(board[i][j]==-1){
                    return -1;
                }
                answer = max(answer,board[i][j]);
            }

        }
        cout<<endl;
    }
    return answer;
}
int main(){
    vector<string> v = {".......","x.x.x..","xxx...x","....x..","x....x.","......."};
    int sy = 5;
    int sx = 0;
    vector<int> movey = {1,0,-1,0,-2,1};
    vector<int> movex = {0,-1,0,1,3,0};
    cout<<solution(v,sy,sx,movey,movex)<<endl; 
}