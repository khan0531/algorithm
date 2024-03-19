#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> boss, vector<int> skill) {
        int answer = 0x7f7f7f7f;
        vector<int> order;
        for (int i = 0; i < n; i++) {
            order.push_back(i);
        }
        do {
            int cur_skill = 0;
            int mn = 0;
            for (int i : order) {
                int time = boss[i] < cur_skill ? 0 : boss[i] - cur_skill;
                mn += time;
                cur_skill = skill[i];
            }
            answer = min(mn, answer);
        } while(next_permutation(order.begin(), order.end()));
        return answer;
    }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> v;
    
}
