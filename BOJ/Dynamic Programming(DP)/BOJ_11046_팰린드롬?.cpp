#include <bits/stdc++.h>

using namespace std;

int d[4000005]; // 팰린드롬 반지름을 저장할 배열
int arr[2000005]; // 입력받은 원래의 수열
int temp[4000005]; // 변형된 수열(원소 사이에 구분자 삽입)

// 수열을 받아 매니처 알고리즘을 적용하는 함수
void manacher(const vector<int>& s, int n) {
    int temp_sz = 0;
    temp[temp_sz++] = -1; // 시작 구분자 삽입
    for (int i = 0; i < n; i++) {
        temp[temp_sz++] = s[i];
        temp[temp_sz++] = -1; // 각 원소 사이에 구분자 삽입
    }

    int r = 0; // 현재까지 발견된 팰린드롬의 오른쪽 끝
    int p = 0; // r에 대응하는 팰린드롬의 중심
    for (int i = 0; i < temp_sz; i++) {
        if (i <= r) {
            d[i] = min(d[2 * p - i], r - i); // 대칭 위치의 값을 이용해 초기 추정
        } else {
            d[i] = 0; // i가 r을 넘어서면 초기화
        }
        // 팰린드롬 확장 시도
        while (i - d[i] - 1 >= 0 && i + d[i] + 1 < temp_sz && temp[i - d[i] - 1] == temp[i + d[i] + 1]) {
            d[i]++;
        }
        // r과 p 업데이트
        if (i + d[i] > r) {
            r = i + d[i];
            p = i;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    manacher(s, n); // 매니처 알고리즘 적용

    int m;
    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        a = 2 * a - 1; // 원래 위치를 변형된 수열의 인덱스로 변환
        b = 2 * b - 1;
        int mid = (a + b) / 2;
        // 쿼리 결과 출력
        cout << (d[mid] >= b - mid ? "1\n" : "0\n");
    }
}
