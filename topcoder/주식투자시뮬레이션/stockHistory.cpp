#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <algorithm>
using namespace std;
vector<int> changeStoI(string s){
    int num;
    vector<int> v;
    istringstream iss(s);
    while(iss>>num){
        v.push_back(num);
    }
    return v;
}
int solution(int init,int mon,vector<string> v){
    double answer = 0;
    vector<vector<int>> num;
    for(int i=0;i<v.size();i++){
        num.push_back(changeStoI(v[i]));
    }
    vector<bool> checkbuy(v.size()-1);
    vector<double> maxincrease(v.size()-1);
    vector<int> end = num[v.size()-1];
    double mx = 1.0;
    for(int i=v.size()-2;i>=0;i--){
        double plus = 1.0;
        for(int j=0;j<end.size();j++){
            double cnt;
            plus = max(plus,(double)end[j]/(double)num[i][j]);
        }
        if(plus == 1.0){
            checkbuy[i]=false;
            continue;
        }
        if(mx<plus){
            mx = plus;
            checkbuy[i] = true;
        }
        else{
            checkbuy[i] = false;
        }
        maxincrease[i] = mx;
    }
    int balance = init;
    int usedmoney = 0;
    for(int i=0;i<v.size()-1;i++){
        if(checkbuy[i]){
            answer+=maxincrease[i]*balance;
            usedmoney+=balance;
            balance=0;

        }
        balance+=mon;
    }
    answer = answer-usedmoney;
    answer = (int)round(answer);
    return answer;
}
int main(){
    int init = 100;
    int mon = 20;
    vector<string> v = {
        "40 50 60",
        "37 48 50",
        "100 48 50",
        "105 48 47",
        "110 50 52",
        "110 50 52",
        "110 51 54",
        "109 49 53"
    };
    cout<<solution(init,mon,v);
}