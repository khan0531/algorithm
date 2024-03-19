#include <bits/stdc++.h>

using namespace std;
int a[1000005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> v;
    v.push_back(a[0]);  //v[i]가 의미하는 것은 배열의 길이가 (i + 1)일 때 가장 뒤에 오는 원소의 값의 최소값이다.
    for (int i = 1; i < n; i++) {
        if(a[i] > v.back()) v.push_back(a[i]);
        else {
            int st = 0;
            int en = v.size() - 1;
            while(st < en){
                int mid = (st + en)/2;
                if(a[i] > v[mid]) st = mid + 1;
                else en = mid;
            }
            v[st] = a[i];
        }
    }
    cout << v.size();
}