#include <iostream>
#include <vector>
using namespace std;

int dp[51];
int getsalary(int x,vector<string> s){
    if(dp[x]!=0){
        return dp[x];
    }
    bool check = true;
    
    int cnt = 0;
    for(int i=0;i<s.size();i++){
        if(s[x][i]=='Y'){
            cnt+=getsalary(i,s);
            check = false;
        }
    }
    if(check)return dp[x]=1;
    return dp[x] = cnt;
}
int solution(vector<string> v){
    int n = v.size();
    int answer = 0;
    for(int i=0;i<n;i++){
        answer+=getsalary(i,v);
    }
    return answer;
}
int main(){
    vector<string> v = {"NNNNNN","YNYNNY","YNNNNY","NNNNNN","YNYNNN","YNNYNN"};
    // vector<string> v = {"NNYN","NNYN","NNNN","NYYN"};
    cout<<solution(v)<<endl;
    for(int i=0;i<6;i++){
        cout<<dp[i]<<" ";
    }cout<<endl;
}