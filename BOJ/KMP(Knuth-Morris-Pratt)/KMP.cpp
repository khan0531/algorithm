#include <bits/stdc++.h>

using namespace std;

// 실패 함수를 계산하는 함수
vector<int> failure(string& s) {
    vector<int> f(s.size()); // 실패 함수를 저장할 벡터, 문자열 s의 각 인덱스에 대한 값을 저장
    int j = 0; // 패턴 내에서의 비교 위치를 추적
    for (int i = 1; i < s.size(); i++) { // 문자열 s의 각 인덱스에 대해
        while(j > 0 && s[i] != s[j]) j = f[j - 1]; // 현재 문자가 일치하지 않으면, 실패 함수를 이용해 이동
        if (s[i] == s[j]) f[i] = ++j; // 현재 문자가 일치하면, 실패 함수의 값을 갱신
    }
    return f; // 계산된 실패 함수를 반환
}

// KMP 알고리즘을 이용한 문자열 검색 함수
bool kmp(string& s, string& p) {
    vector<int> f = failure(p); // 패턴 p에 대한 실패 함수 계산
    int j = 0; // 패턴 내에서의 비교 위치를 추적
    for (int i = 0; i < s.size(); i++) { // 주어진 문자열 s의 각 인덱스에 대해
        while(j > 0 && s[i] != p[j]) j = f[j - 1]; // 현재 문자가 일치하지 않으면, 실패 함수를 이용해 패턴 내에서 이동
        if (s[i] == p[j]) j++; // 현재 문자가 일치하면, 패턴 내에서 다음 문자로 이동
        if (j == p.size()) { // 패턴 p가 문자열 s 내에서 완전히 일치하는 경우
            return true; // 일치함을 반환
        }
    }
    return false; // 문자열 s 내에서 패턴 p가 발견되지 않은 경우
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s, p;
    cin >> s >> p;

    cout << kmp(s, p);
}
