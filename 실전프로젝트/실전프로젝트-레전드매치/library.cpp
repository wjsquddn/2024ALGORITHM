#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int solution(vector<int> v, int n) {
    int answer = 0;
    vector<int> check(n+1,0);
    vector<int> books(2 * n, 0);
    for(int i=0;i<v.size();i++){
        if(check[v[i]]==0){
            check[v[i]]=1;
            
        }
        else{
            continue;
        }
    }
    
    for (int i = 0; i < 2 * n; ++i) {
        int book = v[i];
        int idx = i;
        if (books[book] == 0) {
            answer += idx;
            books[book] = idx + 1;
        } else {
            int distance = idx - books[book] + 1;
            books[book] = idx + 1;
            answer += distance;
        }
    }

    return answer;
}
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> v;

        for (int j = 0; j < 2 * n; j++) {
            int cnt;
            cin >> cnt;
            v.push_back(cnt);
        }
        cout << solution(v, n);
    }
}
