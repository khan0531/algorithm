#include <bits/stdc++.h>

using namespace std;

int n;
bool isused[10005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int tmp = 0;
    while(1){
        tmp = 0;
        while(n > 0){
            tmp += (n%10)*(n%10);
            n /= 10;
        }
        if (tmp == 1 || isused[tmp]) break;
        isused[tmp] = true;
        cout << tmp <<'\n';
        n = tmp;
    }

    if (tmp == 1) cout << "true";
    else cout << "false";
}
