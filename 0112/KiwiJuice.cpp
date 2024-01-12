#include <iostream>
#include <vector>
using namespace std;
vector<int> solution(vector<int> capacities, vector<int> bottles, vector<int> fromId, vector<int> toId) {
    // 반복은 fromId의 개수만큼 반복해준다.
    for (int i = 0; i < toId.size(); i++) {
        // 경우의 수 물을 채울때 toId의 양이 넘칠때
        // 넘친경우 -> bottles[toId]+(capcities[toId]-bottles[toId]),from은 -임

        // 안넘칠때 -> bottles[fromId]-bottles[fromId],bottles[toId]+bottles[fromId]
        // 결국 bottles[fromId]랑 toId의 남은 공간 중 min 값을 -+ 해주면 된다.
        int vol = min(capacities[toId[i]] - bottles[toId[i]], bottles[fromId[i]]);
        bottles[toId[i]] += vol;
        bottles[fromId[i]] -= vol;
    }
    return bottles;
}
int main() {
    vector<int> capacities = {30, 20, 10};
    vector<int> bottles = {10, 5, 5};
    vector<int> fromId = {0, 1, 2};
    vector<int> toId = {1, 2, 0};
    vector<int> answer = solution(capacities, bottles, fromId, toId);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
}