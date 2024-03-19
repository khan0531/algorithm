#include <bits/stdc++.h>

using namespace std;

int n, tmp;
int a[1005];
int aa[1005];
vector<int> v;
bool isused[1005];
void permutation(int k){
    if (k == n){
        int cur = 0;
        int k = 1;
        int j = 1;
        while(j < n){
            k *= 10;
            j++;
        }
        for (int i = 0; i < n; i++) {
            cur += aa[i]*k;
            k /= 10;
        }
        v.push_back(cur);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (isused[i]) continue;
        isused[i] = true;
        aa[k] = a[i];
        permutation(k + 1);
        isused[i] = false;
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int k = 1;
    int j = 1;
    while(j < n){
        k *= 10;
        j++;
    }

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        tmp += a[i]*k;
        k /= 10;
    }

    sort(a, a + n);
    permutation(0);

    int idx;
    for(int i = 0; i < v.size(); i++){
        if (v[i] == tmp) {
            if (i == 0) idx = i;
            else idx = i - 1;
            break;
        }
    }

    vector<int> ans;
    int l = v[idx];
    while(l > 0){
        ans.push_back(l%10);
        l /= 10;
    }
    for (int i = ans.size() - 1; i >= 0; i --) cout << ans[i] << ' ';
}
