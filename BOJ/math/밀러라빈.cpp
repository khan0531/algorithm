#include <bits/stdc++.h> // 헤더 파일을 한 번에 포함하기 위한 헤더
using namespace std;
using ull = unsigned long long; // 부호 없는 long long 정수형을 ull로 정의

// a^d % n 을 계산하는 함수
ull power(ull a, ull d, ull n) {
    ull result = 1;
    a %= n;
    while (d) {
        if (d % 2 == 1)
            result = (result * a) % n;
        a = (a * a) % n;
        d /= 2;
    }
    return result;
}

// 밀러-라빈 소수 판별법
bool millerRabin(ull n, ull a) {
    if (n <= 1)
        return false; // 1 또는 0인 경우는 소수가 아님
    if (n <= 3)
        return true; // 2 또는 3인 경우는 소수임
    if (n % 2 == 0)
        return false; // 짝수는 소수가 아님
    if (a % n == 0) 
        return true; // a가 n의 배수인 경우, n은 합성수가 아닌 것으로 간주

    ull x = n - 1;
    while(true) {
        ull tmp = power(a, x, n); // a^x mod n을 계산
        if (tmp == n - 1) return true; // 조건이 만족할 때 소수일 가능성이 높음
        if (x%2 == 1) return (tmp == 1 || tmp == n - 1); // x가 홀수일 때 조건을 만족할 때 소수일 가능성이 높음
        x /= 2; // x가 짝수인 경우, 다음 지수를 계산하기 위해 x를 2로 나눔
    }
}

// 주어진 수가 소수인지 판별하는 함수
bool isPrime(ull n) {
    // 소수 판별을 위한 테스트 수
    vector<ull> bases = {2, 7, 61};

    // 모든 테스트 수에 대해 판별
    for (ull a : bases) {
        if (!millerRabin(n, a))
            return false; // 하나의 테스트에서라도 합성수라면 n은 합성수임
    }
    return true; // 모든 테스트를 통과하면 소수일 가능성이 높음
}

int main() {
    ull n;
    cin >> n; // 사용자로부터 입력 받음
    if (isPrime(n))
        cout << n << " is probably prime." << endl; // 소수일 가능성이 높음
    else
        cout << n << " is composite." << endl; // 합성수임
    return 0;
}
