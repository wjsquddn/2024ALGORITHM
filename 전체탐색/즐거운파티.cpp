#include <iostream>
#include <map>
#include <vector>
using namespace std;
int solution(vector<string> first, vector<string> second) {
    int answer = 0;
    map<string, int> m;
    for (int i = 0; i < first.size(); i++) {
        if (m.find(first[i]) == m.end()) {
            m.insert({first[i], 1});
        } else {
            m[first[i]]++;
        }
        if (m.find(second[i]) == m.end()) {
            m.insert({second[i], 1});
        } else {
            m[second[i]]++;
        }
        int plus = max(m[first[i]], m[second[i]]);
        if (answer < plus) {
            answer = plus;
        }
    }

    return answer;
}
int main() {
    vector<string> first = {"fishing", "python", "smoking", "smoking"};
    vector<string> second = {"python", "fishing", "fishing", "fishing"};
    cout << solution(first, second) << endl;
}