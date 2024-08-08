#include <iostream>
using namespace std;
int dp[101][101];
int solution(int h,int w){
    for(int i=0;i<=h;i++){
        for(int j=0;j<=w;j++){
            if(i==0||j==0){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
    }
    return dp[h][w];
}
int main(){
    int h=4,w=5;
    cout<<solution(h,w)<<endl;
}