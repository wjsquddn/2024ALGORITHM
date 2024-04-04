#include <iostream>
#include <vector>
using namespace std;
char arr[201][201];
void printarr(int a, int b) {
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < a * 2 - 1; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }
    return;
}
int solution(int a, int b, int c) {
    int answer;
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < a * 2 - 1; j++) {
            cin >> arr[i][j];
        }
    }
    printarr(a, b);
    int start = c * 2 - 2;
    // for(int i=b-1;i>=0;i--){
    //     start
    // }

    return answer;
}
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << solution(a, b, c);
    }
}