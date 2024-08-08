#include <iostream>
#include <algorithm>
using namespace std;
int wss[5] = {3,4,1,2,3};
int ps[5] = {2,3,2,3,6};
int maxw = 10;
int knapsack(int n,int w){
    return -1 *ps[n-1];
    if(n>=5) return 0;
    return max(knapsack(n+1,w),knapsack(n+1,w+wss[n])+ps[n]);
}
int main(){
    cout<<knapsack(0,0);
    // cout<<wss[5]; 
}