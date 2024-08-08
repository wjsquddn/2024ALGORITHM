#include <iostream>
#include <vector>

using namespace std;
int dp[101][101][50];
int mx[16] = {0,1,1,1,0,-1,-1,-1,1,2,2,1,-1,-2,-2,-1}; 
int my[16] = {1,1,0,-1,-1,-1,0,1,2,1,-1,-2,-2,-1,1,2}; 
int solution(int size,int numMoves,vector<int> start,vector<int> end){
    dp[start[0]][start[1]][0] = 1;
    for(int i=1;i<=numMoves;i++){
        for(int j=0;j<size;j++){
            for(int k=0;k<size;k++){
                if(dp[j][k][i-1]==0)continue;
                int nx,ny;
                for(int l=0;l<16;l++){
                    nx = k+mx[l];
                    ny = j+my[l];
                    if(nx>=0&&nx<size&&ny>=0&&ny<size){
                        dp[ny][nx][i]+=dp[j][k][i-1];
                    }
                }
            }
        }
    }
    return dp[end[0]][end[1]][numMoves];
}
int main(){
    int size = 3,numMoves = 2;
    vector<int> start = {0,0},end={2,2};
    cout<<solution(size,numMoves,start,end)<<endl;
}