#include <bits/stdc++.h>

using namespace std;

int N;
int a[101];
int cal[12]; // cal[i]가 0: 덧셈, 1: 뺄셈, 2: 곱셈, 3: 나눗셈 
int mn = 1000000001;
int mx = -1000000001;
int sum;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int k = 0;
    for (int i = 0; i < 4; i++) {
        int j;
        cin >> j;
        while(j--){
            cal[k++] = i;
        }
    }
     
    int n = N - 1; 
    do{
        int sum = a[0];
        for (int i = 0; i <= n; i++) {
            if(cal[i] == 0) sum += a[i + 1];
            else if (cal[i] == 1) sum -= a[i+ 1];
            else if (cal[i] == 2) sum *= a[i + 1];
            else if (cal[i] == 3) sum /= a[i + 1];
        }
        mn = min(mn, sum);
        mx = max(mx, sum);

    }while(next_permutation(cal, cal + n));

    cout << mx << '\n' << mn;
}