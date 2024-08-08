#include <iostream>
#include <cmath>
using namespace std;
int solution(string s){
    int cnt = 0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='Y'){
            cnt+=pow(2,s.size()-1-i);
        }
    }
    return 16-cnt;
}
int main(){
    string s = "YNYY";
    cout<<solution(s);
}