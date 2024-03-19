#include <bits/stdc++.h>

using namespace std;

// bool cmp(tuple<string, int, int, int> a, tuple<string, int, int, int> b){
//     if (get<1>(a) > get<1>(b)) return true;
//     else if (get<1>(a) == get<1>(b)) {
//         if (get<2>(a) < get<2>(b)) return true;
//         else if (get<2>(a) == get<2>(b)){
//             if (get<3>(a) > get<3>(b)) return true;
//             else if (get<3>(a) == get<3>(b)){
//                 if (get<0>(a) < get<0>(b)) return true;
//             }
//         }
//     }
//     return false;
// }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector<tuple<int, int, int, string>> v;

    for (int i = 0; i < n; i++) {
        string s;
        int a, b, c;
        cin >> s >> a >> b >> c;
        v.push_back({-a, b, -c, s});
    }

    sort(v.begin(), v.end());
    for(auto cur : v) cout << get<3>(cur)<<'\n';
}