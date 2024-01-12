#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
long long solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end());
    long long answer = numbers[0] + 1;
    for (int i = 1; i < numbers.size(); i++) {
        answer *= numbers[i];
    }
    return answer;
}
int main() {
    vector<int> numbers = {1, 2, 3};
    cout << solution(numbers) << endl;
}