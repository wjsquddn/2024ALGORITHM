#include <iostream>
using namespace std;
int dp[101];
int solution(int n){
    int nn = n/2;
    if(n==2)return 1;
    dp[0] = 1;
    dp[1] = 1;
    
    for(int i=2;i<=nn;i++){
        for(int j=0;j<i;j++){
            dp[i]+=dp[j]*dp[i-j-1];
        }
    }
    return dp[nn];
}
int main(){
    int n=10;
    cout<<solution(n)<<endl;
}