#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,m,cnt;
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>cnt;
        v.push_back(cnt);
    }
    cin>>m;

    vector<vector<int>> palindrom(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        palindrom[i][i]=1;
    }
    for(int i=0;i<n-1;i++){
        if(v[i]==v[i+1])palindrom[i][i+1]=1;
    }
    for(int start = n-3;start>=0;start--){
        for(int end = start+2;end<n;end++){
            if(v[start]==v[end]&&palindrom[start+1][end-1]==1){
                palindrom[start][end]=1;
            }
        }
    }
    int S,E;
    for(int i=0;i<m;i++){
        cin>>S>>E;
        cout<<palindrom[S-1][E-1]<<'\n';
    }
}
//그래프를 그리고 그래프에 충족하는 조건을 탐색하기 위해서는 우상단 삼각형으로 탐색을 해야했음
// 그러기 위해 for 문의 조건 설정하는데 시간이 꽤 오래 걸림