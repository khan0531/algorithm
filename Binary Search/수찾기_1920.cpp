#include <bits/stdc++.h>

using namespace std;

int a[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    int m; cin >> m;
    while(m--){
        bool exist = false;
        int k; cin >> k;
        int st = 0;
        int en = n - 1;

        while(en >= st){
            int mid = (st + en) / 2;
            if(k == a[mid]) {
                exist = true;
                break;
            }
            else if(k > a[mid]){
                st = mid + 1;
            }
            else en = mid - 1;         
        }
            cout << exist << '\n';
    }
}
