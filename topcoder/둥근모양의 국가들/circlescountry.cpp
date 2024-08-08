#include <iostream>
#include <vector>
using namespace std;
bool insidecheck(int r,int x,int y,int X,int Y){
    return (X-x)*(X-x)+(Y-y)*(Y-y)<r*r;
}
int solution(vector<int> X,vector<int> Y,vector<int> R,int x1,int y1,int x2,int y2){
    int n = X.size();
    int answer = 0;
    for(int i=0;i<n;i++){
        if(insidecheck(R[i],X[i],Y[i],x1,y1)!=insidecheck(R[i],X[i],Y[i],x2,y2))answer++;
    }
    return answer;
}
int main(){
    vector<int> X = {1,-3,2,5,-4,12,12};
    vector<int> Y = {1,-1,2,5,5,1,1};
    vector<int> R = {8,1,2,1,1,1,2};
    int x1 = 5,y1 = 1,x2 = 12, y2 = 1;
    cout<<solution(X,Y,R,x1,y1,x2,y2);
}