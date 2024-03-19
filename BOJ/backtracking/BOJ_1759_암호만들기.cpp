#include <bits/stdc++.h>

using namespace std;

int l, c;
char ans[20];
char arr[20];
bool isused[20];
int cnt = 0, cnt2 = 0;

void func(int k){
    if (k == l){
        for(char i : ans){
            if (i == 'a' || i == 'e' || i == 'o' || i == 'u' || i == 'i') cnt ++;
            else cnt2 ++;
        }
        if (cnt >= 1 && cnt2 >= 2){
            cout << ans;
            cout <<'\n';
        }
        cnt = 0;
        cnt2 = 0;
        return;
    }

    for (int i = 0; i < c; i++) {
        if(isused[i] || ans[k - 1] > arr[i]) continue;
        ans[k] = arr[i];
        isused[i] = true;
        func(k + 1);
        isused[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> l >> c;
    for (int i = 0; i < c; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + c);
    func(0);
}