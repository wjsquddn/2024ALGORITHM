#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<string> v){
    int answer = 0;
    for(int i=0;i<v.size();i++){
        int cnt = 0;
        for(int j=0;j<v.size();j++){
            if(i==j)continue;
            if(v[i][j]=='Y')cnt++;
            else{
                for(int k=0;k<v.size();k++){
                    if(v[i][k]=='Y'&&v[j][k]=='Y'){
                        cnt++;break;
                    }
                }
            }
        }
        answer = max(answer,cnt);
    }
    return answer;
}
int main(){
    vector<string> v = {"NYNNN","YNYNN","NYNYN","NNYNY","NNNYN"};
    cout<<solution(v);
}