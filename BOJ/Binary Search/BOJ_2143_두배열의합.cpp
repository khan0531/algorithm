#include <bits/stdc++.h>

using namespace std;

int t, n, m;
long long cnt;
int a[1005];
int b[1005];
vector<int> asum;
vector<int> bsum;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    //배열의 합을 벡터에 넣을 때 삼중 for문을 돌지 않고, 이중 for문을 돌도록 최적화를 하는게 좋은 코드
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += a[j];
            asum.push_back(sum);
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < m; i++) {
        int sum = 0;
        for(int j = i; j < m; j++){
            sum += b[j];
            bsum.push_back(sum);
        }
    }

    sort(asum.begin(), asum.end());

    for(int i : bsum){
        long long cur = upper_bound(asum.begin(), asum.end(), t - i) - lower_bound(asum.begin(), asum.end(), t - i);
        cnt += cur;
    }
    cout << cnt;
}