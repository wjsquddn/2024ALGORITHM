#include <iostream>
#include <vector>
using namespace std;
void dfs(vector<bool>& visited,int i,const vector<string>& roads){
    visited[i] = true;
    for(int j=0;j<roads.size();j++){
        if(roads[i][j]=='Y'&&visited[j]==false){
            dfs(visited,j,roads);
        }
    }
}
int solution(vector<string> roads){
    int connection[50] = {0};
    int n = roads.size();
    int alone = 0;
    int notalone = 0;
    for(int i=0;i<n;i++){
        int y=0;
        for(int j=0;j<n;j++){
            if(roads[i][j]=='Y'){
                y++;
                if(y>2)return 0;
            }
        }
        connection[i] = y;
    }
    vector<bool> visited (50,false);
    
    for(int i=0;i<n;i++){
        if(connection[i]==0){
            alone++;
            visited[i]=true;
        }
        else if (connection[i]==1&&visited[i]==false){
            dfs(visited,i,roads);
            notalone++;
        }
    }
    for(int i=0;i<n;i++){
        if(visited[i]==false)return 0;
    }
    int answer = 1;
    for(int i=1;i<=alone+notalone;i++){
        answer=(answer*i)%1000000007;
    }
    for(int i=0;i<notalone;i++){
        answer = (answer*2)%1000000007;
    }
    return answer;
}
int main(){
    vector<string> roads = {"NNNNNY","NNNNYN","NNNNYN","NNNNNN","NYYNNN","YNNNNN"};
    cout<<solution(roads)<<endl;
}