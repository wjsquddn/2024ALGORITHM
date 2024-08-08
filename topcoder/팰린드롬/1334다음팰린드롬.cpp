#include<iostream>
#include <vector>
using namespace std;
bool check9(string s){
    for(int i=0;i<s.size();i++){
        if(s[i]!='9')return false;
    }
    return true;
}
void solution(string s){
    if(s.size()==1){
        if(s=="9"){
            cout<<"11"<<endl;
        }else{
            s[0]+=1;
            cout<<s<<endl;return;
        }
    }
    if(check9(s)){
        
    }
}
int main(){
    string s;
    cin>>s;
    solution(s)
}