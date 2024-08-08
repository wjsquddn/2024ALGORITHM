#include <iostream>
#include <vector>
using namespace std;
int solution(string s){
    //전체탐색
    for(int i=s.size();;i++){
        bool flag = true;
        for(int j=0;j<s.size();j++){
            if(i-j-1<s.size()&&s[j]!=s[i-j-1]){
                flag = false;
                break;
            }
        }
        if(flag)return i;
    }
    
}
int main(){
    string s = "qwerty";
    cout<<solution(s);
}