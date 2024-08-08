#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
double solution(int price,int monthlyPayment,int loanTerm){
    double balance;
    double high = 100,low = 0,mid = 0;
    while((high-low)>1e-9){
        balance = price;
        mid = (high+low)/2;
        for(int i=0;i<loanTerm;i++){
            balance*=((mid+1200)/1200);
            balance-=monthlyPayment;
        }
        if(balance>0)high=mid;
        else{
            low=mid;
        }
    }
    return mid;
}
int main(){
    int price = 2000;
    int monthlyPayment = 510;
    int loanTerm = 4;
    cout<<solution(price,monthlyPayment,loanTerm);
}