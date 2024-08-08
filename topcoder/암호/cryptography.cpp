#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll solution(vector<int> num){
    ll answer = 1;
    int minnum = 1001;
    for(int i=0;i<num.size();i++){
        answer*=num[i];
        minnum = min(minnum,num[i]);
    }
    answer += answer/minnum;
    return answer;
}
int main(){
    vector<int> num = {1,2,3,1,1,3};
    cout<<solution(num);
    return 0;
}