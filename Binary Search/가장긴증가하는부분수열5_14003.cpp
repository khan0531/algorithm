#include <bits/stdc++.h>

using namespace std;

int n, mxi, mxst; // mxi는 v[i]의 인덱스 중 가장 큰거
int a[1000010];
vector<int> v; // v[i]는 i+1크기의 배열의 마지막 원소 중 최소값
vector<int> vi; // 배열을 구성하는 i의 값들.
vector<pair<int, int>> p;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    v.push_back(a[0]);
    vi.push_back(0);
    for (int i = 1; i < n; i++) {
        if(v.back() < a[i]){
            v.push_back(a[i]);
            vi.push_back(v.size() - 1);
        }
        else{
            int st = 0;
            int en = v.size() - 1;
            while(st < en){
                int mid = (st + en)/2;
                if(a[i] > v[mid]) st = mid + 1;
                else en = mid;
            }
            v[st] = a[i];
            vi.push_back(st);
        }
    }
    int sz = v.size();
    cout << sz << '\n';
    int idx = sz - 1;
    deque<int> ans;
    for(int i = n - 1; i >= 0; i--){
        if(vi[i] == idx){
            ans.push_front(a[i]);
            idx--;
        }
    }
    for(int i : ans) cout << i << ' ';
}