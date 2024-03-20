#include <bits/stdc++.h>

using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n), b(n); // 오름차순으로 정렬할 배열 a와 치환된 값을 기록할 배열 b
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a[temp - 1] = i; // 첫 번째 수열의 값 위치를 기록
    }

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        b[i] = a[temp - 1]; // 두 번째 수열을 첫 번째 수열의 위치 정보로 변환
    }

    vector<int> LIS; // 가장 긴 증가하는 부분 수열을 저장할 벡터

    for (int i = 0; i < n; i++) {
        auto it = lower_bound(LIS.begin(), LIS.end(), b[i]); // b[i]를 삽입할 위치 탐색
        if (it == LIS.end()) LIS.push_back(b[i]); // LIS의 끝에 도달했다면, 새로운 요소 추가
        else *it = b[i]; // 삽입 위치에 b[i] 값을 업데이트
    }

    cout << LIS.size() << '\n'; // 가장 긴 증가하는 부분 수열의 길이 출력
    return 0;
}   