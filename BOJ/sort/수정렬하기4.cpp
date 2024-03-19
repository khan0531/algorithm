#include <bits/stdc++.h>

using namespace std;

int a[10000005];
bool cmp(int a, int b){
    if (a > b) return true;

    return false;  

    // return a > b;
}

// bool cmp2(int a, int b){ //greater<int>()
//     return (a > b);
// }


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << a[i] << '\n';
    }
}