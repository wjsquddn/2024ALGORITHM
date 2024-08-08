#include <iostream>
#include <vector>
using namespace std;

vector<double> prob = {0.25,0.25,0.25,0.25};
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int check[101][101] = {false};
double dfs(int x,int y,int n){
    if(check[y][x])return 0;
    if(n==0)return 1;
    check[y][x]=1;
    double ret = 0.0;
    for(int i=0;i<4;i++){
        ret+=dfs(x+dx[i],y+dy[i],n-1)*prob[i];
    }
    check[y][x]=0;
    return ret;
}
double solution(int n){
    
    return dfs(50,50,n);
}
int main(){
    int n = 14;
    cout<<solution(n)<<endl;
}