#include <bits/stdc++.h>

using namespace std;

int n, k;
pair<int, int>p[105];
int a[105];
bool func(int x){
    

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> p[i].second >> p[i].first;
    }
    sort(p, p + n);
    a[p[0].first] = p[0].second;
    for (int i = 1; i < n; i++) {
        if(p[i].first == p[i - 1].first) continue;
        a[p[i].first] = p[i].second;
    }

}