#include <bits/stdc++.h>
using namespace std;

int n; 
int a[1'005]; 
vector<int> v, p, prev_idx; // v: LIS를 구성하는 값 저장, p: LIS를 구성하는 요소의 인덱스, prev_idx: 각 요소의 이전 요소 인덱스

// idx에서 시작하는 LIS를 출력하는 함수
void printLIS(int idx) {
    if (idx == -1) return; // 기저 조건: -1이면 역추적을 마침
    printLIS(prev_idx[idx]); // 재귀적으로 이전 요소를 출력
    cout << a[idx] << " ";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    v.push_back(a[0]); // 첫 번째 요소로 LIS 시작
    p.push_back(0); // 첫 번째 요소의 인덱스 저장
    prev_idx.resize(n, -1); // 각 요소의 이전 요소 인덱스를 -1로 초기화

    for (int i = 1; i < n; i++) {
        if (a[i] > v.back()) { // 현재 요소가 LIS의 마지막 요소보다 크면 LIS에 추가
            prev_idx[i] = p.back(); // 현재 요소의 이전 요소 인덱스를 업데이트
            v.push_back(a[i]); // v에 현재 요소 추가
            p.push_back(i); // 현재 요소의 인덱스 저장
        } else { // 현재 요소가 LIS의 마지막 요소보다 작거나 같으면
            int idx = lower_bound(v.begin(), v.end(), a[i]) - v.begin(); // 삽입 위치 탐색
            v[idx] = a[i]; // 찾은 위치에 현재 요소를 업데이트
            p[idx] = i; // 찾은 위치의 인덱스를 현재 요소의 인덱스로 업데이트
            if (idx > 0) prev_idx[i] = p[idx - 1]; // 찾은 위치가 처음 위치가 아니면 이전 요소 인덱스 업데이트
        }
    }

    cout << v.size() << "\n";
    printLIS(p.back());
    cout << "\n";
}
