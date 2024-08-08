#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
bool compare(const pair<string,int>& a,const pair<string,int>& b){
    if(a.second!=b.second){
        return a.second<b.second;
    }
    return a.first<b.first;
}
vector<int> solution(vector<string> user,vector<int> duration){
    map<string,int> m;
    int N = user.size();
    //맵에 숫자 다 더하기
    for(int i=0;i<N;i++){
        m[user[i]]+=duration[i];
    }
    //맵을 백터로 변환한 후 정렬
    vector<pair<string,int>> v(m.begin(),m.end());
    sort(v.begin(),v.end(),compare);

    //백터 기준으로 돌면서 출력함
    vector<int> answer;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<N;j++){
            if(v[i].first==user[j]){
                answer.push_back(j);
            }
        }
    }
    return answer;

}
int main(){
    // vector<string> user = {"a","b","b","c"};
    // vector<int> duration = {400,100,100,100};

    vector<string> user = {"a","B","b","b","c"};
    vector<int> duration = {400,100,50,50,50};
    for(int n:solution(user,duration)){
        cout<<n<<" ";
    }cout<<endl;    
}