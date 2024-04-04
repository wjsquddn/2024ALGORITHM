#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;
long long solution(vector<int> player,int a,int b){
    long long answer = 0;
    vector<int> differnce((a/2)+1,0);
    
    //내림차순 정렬 후 숫자가 같은것이 있다면 우선권 안쓰고 차이가 난다면 배열에 넣어둠
    //배열에 넣어둔 후 차이가 많이 나는것을 우선권 개수만큼 더해줌
    sort(player.begin(),player.end(),greater<>());
    for(int i=0;i<a;){
        if(i==a-1){
            differnce.push_back(player[i]);break;
        }
        if(player[i]==player[i+1]){
            answer+=player[i];
            i=i+2;
            continue;
        }
        else{
            answer+=min(player[i],player[i+1]);
            differnce.push_back(abs(player[i]-player[i+1]));
            i=i+2;
            continue;
        }
    }
    sort(differnce.begin(),differnce.end(),greater<>());
    
    for(int i=0;i<b;i++){
        answer+=differnce[i];
    }

    return answer;
}
int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int a,b;cin>>a>>b;
        vector<int> player(a,0);
        for(int j=0;j<a;j++){
            cin>>player[j];
        }
        cout<<solution(player,a,b)<<endl;
    }
    return 0;
}