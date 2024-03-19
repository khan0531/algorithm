#include <bits/stdc++.h>

using namespace std;

int arr[1001];
int num[1001];
int cnt[1001];

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b){
    if (get<2>(a) > get<2>(b)) return true;
    else if (get<2>(a) == get<2>(b)){
        if (get<1>(a) < get<1>(b)) return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, c;
    cin >> n >> c;

    tuple<int, int, int> t[1001] = {}; // 받는 숫자, 처음 등장 숫자, 등장 횟수 {arr[i], cnt, }

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        get <0> (t[i]) = arr[i];
        for (int j = 0; j < i; j++) {
            if(arr[i] == arr[j]){
                num[i] = j;
                break;
            }
            else num[i] = i;
        }
        get<1>(t[i]) = num[i];
    }

    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if(arr[i] == arr[j]) cnt ++;
        }
        get<2>(t[i]) = cnt;
    }

    stable_sort(t, t + n, cmp);
    
    for (int i = 0; i < n; i++) {
        cout << get<0>(t[i]) << ' ';
    }
}
