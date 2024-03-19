#include <bits/stdc++.h>

using namespace std;

long long func(int N) {
    if (N <= 10) return N < 10 ? N : -1; // 0부터 9까지는 자기 자신이 감소하는 수
    
    queue<long long> q;
    for (int i = 1; i < 10; i++) q.push(i); // 초기 값 설정
    
    int count = 9; // 0부터 9까지 이미 10개 포함
    
    while (!q.empty()) {
        long long num = q.front();
        q.pop();
        
        int lastDigit = num % 10;
        for (int nextDigit = 0; nextDigit < lastDigit; nextDigit++) {
            long long newNum = num * 10 + nextDigit;
            q.push(newNum);
            count++;
            if (count == N) return newNum;
        }
    }
    
    return -1; // N번째 감소하는 수가 존재하지 않는 경우
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    if (N <= 10) {
        cout << N << "\n"; // 0번째부터 10번째 감소하는 수는 자기 자신.
        return 0;
    }

    queue<long long> q;
    for (int i = 1; i <= 9; i++) {
        q.push(i);
    }

    int count = 9; // 0부터 9까지 이미 10개가 존재
    while (!q.empty()) {
        long long num = q.front();
        q.pop();
        int lastDigit = num % 10;
        for (int nextDigit = 0; nextDigit < lastDigit; nextDigit++) {
            long long newNum = num * 10 + nextDigit;
            q.push(newNum);
            count++;
            if (count == N) {
                cout << newNum << "\n";
                return 0;
            }
        }
    }

    cout << -1 << "\n"; // N번째 감소하는 수가 존재하지 않는 경우
    return 0;
}
