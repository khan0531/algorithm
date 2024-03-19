#include <bits/stdc++.h>

using namespace std;

int n;
int a[4005];
int b[4005];
int c[4005];
int d[4005];
long long cnt;
vector<int> absum;
vector<int> cdsum;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            absum.push_back(a[i] + b[j]);
            cdsum.push_back(c[i] + d[j]);
        }
    }
    sort(absum.begin(), absum.end());
    for(long long i : cdsum){
        long long cur = upper_bound(absum.begin(), absum.end(), -i) - lower_bound(absum.begin(), absum.end(), -i);
        cnt += cur;
    }
    cout << cnt;
}