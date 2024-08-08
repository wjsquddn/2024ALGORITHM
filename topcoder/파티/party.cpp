#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int solution(vector<string> first,vector<string> second){
    int answer = 0;
    map<string,int> m;
    int n = first.size();
    for(int i=0;i<n;i++){
        auto it1 = m.find(first[i]);
        auto it2 = m.find(second[i]);
        if(it1==m.end()){
            m[first[i]] = 1;
        }else{
            m[first[i]]++;
        }
        if(it2==m.end()){
            m[second[i]] = 1;
        }else{
            m[second[i]]++;
        }
        int imsi = max(m[first[i]],m[second[i]]);
        answer = max(answer,imsi);
    }
    return answer;
}
int main(){
    vector<string> first = {"s","pr","c","m"};
    vector<string> second = {"p","p","a","p"};
    cout<<solution(first,second)<<endl;
    return 0;
}