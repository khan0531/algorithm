#include <bits/stdc++.h>

using namespace std;

int arr[1000001];
int arr2[1000001];
int ans[2000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    int i = 0, j = 0, k = 0;
    while(i < n && j < m){
        if (arr[i] <= arr2[j]){
            ans[k++] = arr[i++];
        }
        else if (arr[i] > arr2[j]){
            ans[k++] = arr2[j++];
        }
    }

    if (i == n) while(j < m) ans[k++] = arr2[j++];
    if (j == m) while(i < n) ans[k++] = arr[i++];

    for (int l = 0; l < m+n; l++)
    cout << ans[l]<<' ';
}