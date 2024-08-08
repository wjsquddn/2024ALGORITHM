#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp1[40];
int dp2[40];
int solution(vector<int> v){
    int answer = 0;
    int answer2 = 0;
    //첫번째 집
    for(int i=0;i<v.size()-1;i++){
        dp1[i] = v[i];
        if(i==0)answer = dp1[i];
        if(i==1){
            dp1[i] = max(dp1[i],dp1[i-1]);
        }
        else{
            dp1[i] = max(dp1[i]+dp1[i-2],dp1[i-1]);
        }
        answer = max(answer,dp1[i]);
    }
    //두번째 집
    for(int i=1;i<v.size();i++){
        dp2[i] = v[i];
        if(i==1)answer2 = dp2[i];
        if(i==2){
            dp2[i] = max(dp2[i],dp2[i-1]);
        }
        else{
            dp2[i] = max(dp2[i]+dp2[i-2],dp2[i-1]);
        }
        answer2 = max(answer2,dp2[i]);
    }
    answer2 = max(answer2,answer);
    return answer2;
}
int main(){
    vector<int> v = {1,2,3,4,5,1,2,3,4,5};
    cout<<solution(v)<<endl;
}