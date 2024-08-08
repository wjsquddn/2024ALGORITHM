#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solution(vector<int> capacities,vector<int> bottles,vector<int> fromId,vector<int> toId){
    vector<int> answer;
    int n = toId.size();
    for(int i=0;i<n;i++){
        int x = min(capacities[toId[i]]-bottles[toId[i]],bottles[fromId[i]]);
        bottles[fromId[i]]-=x;
        bottles[toId[i]]+=x;
    }
    answer = bottles;    
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }
    cout<<endl;
    return;
}
int main(){
    // vector<int> capacities = {20,20};
    // vector<int> bottles = {5,8};
    // vector<int> fromId = {0};
    // vector<int> toId = {1};

    vector<int> capacities = {30,20,10};
    vector<int> bottles = {10,5,5};
    vector<int> fromId = {0,1,2};
    vector<int> toId = {1,2,0};
    solution(capacities,bottles,fromId,toId);
    return 0;
}