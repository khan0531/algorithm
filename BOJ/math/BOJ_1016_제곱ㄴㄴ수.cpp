#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll min, max;
    cin >> min >> max;
    ll cnt = 0; // 최소 제곱수의 배수가 아닌 수의 개수를 저장할 변수
    vector<bool> a(max - min + 1, false); // 범위 내 각 숫자가 최소 제곱수의 배수인지 여부를 표시하는 배열

   
    for (ll i = 2; i*i <= max; i++) {
        ll ii = i*i; 
        ll st = 0; 
        // min이 ii로 나누어 떨어지지 않는 경우, min/ii의 다음 정수를 시작 지점으로 설정
        if (min % ii != 0) st = (min / ii + 1);
        else st = min / ii; // min이 ii로 나누어 떨어지는 경우, min/ii를 시작 지점으로 설정

        // st부터 시작하여 ii를 곱한 값이 max 이하인 모든 j에 대해 반복
        for(ll j = st; j*ii <= max; j++) {
            a[j*ii - min] = true;
        }
    }

    
    for (int i = 0; i < a.size(); i++) {
        if (!a[i]) cnt++;
    }
    cout << cnt << endl;

    return 0;
}
