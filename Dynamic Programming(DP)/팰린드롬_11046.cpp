#include <bits/stdc++.h>

using namespace std;

int d[2000005];
int arr[2000005];
int temp[2000005];

void manacher(int s[], int n){
    int r = 0;
    int p = 0;
    for (int i = 0; i < n; i++) {
        if(i > r) d[i] = 0;
        else d[i] = min(r - i, d[2*p - i]);
        while(i - d[i] - 1 >= 0 && i + d[i] + 1 < n && s[i - d[i] - 1] == s[i + d[i] + 1])
        d[i]++;
        if(r < i + d[i]){
            r = i + d[i];
            p = i;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    temp[0] = -1;
    for (int i = 1; i <= n; i++) {
        temp[2*i - 1] = arr[i];
        temp[2*i] = -1;
    }
    int temp_sz = 2*n + 1;
    manacher(temp, temp_sz);
    int m; cin >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        int aa = 2*a - 1;
        int bb = 2*b - 1;
        int c = (aa + bb)/2;
        cout << (c+ d[c] >= bb ? "1\n" : "0\n");
    }
}