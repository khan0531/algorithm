#include <bits/stdc++.h>

using namespace std;

int n;
int d[100];

void manacher(int a[], int n){
    int r = 0, p = 0;
    for (int i = 0; i < n; i++) {
        if (r < i) d[i] = 0;
        else d[i] = min(r - i, d[2*p - i]);
        while(i - d[i] - 1 >= 0 && i + d[i] + 1 < n && a[i - d[i] - 1] == a[i + d[i] + 1])
        d[i]++;

        if (r < i + d[i]){
            r = i + d[i];
            p = i;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
}
