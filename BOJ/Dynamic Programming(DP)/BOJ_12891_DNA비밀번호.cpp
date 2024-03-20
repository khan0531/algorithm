#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m, check, ans;
string s;
vector<int> a(4), cnt(4);

void add(char c) {
    int idx = string("ACGT").find(c);
    cnt[idx]++;
    if (cnt[idx] == a[idx]) check++;
}

void remove(char c) {
    int idx = string("ACGT").find(c);
    if (cnt[idx] == a[idx]) check--;
    cnt[idx]--;
}

int main() {
    cin >> n >> m >> s;
    for (int i = 0; i < 4; i++) {
        cin >> a[i];
        if (a[i] == 0) check++;
    }

    for (int i = 0; i < m; i++) add(s[i]);
    if (check == 4) ans++;

    for (int i = m; i < n; i++) {
        add(s[i]);
        remove(s[i - m]);
        if (check == 4) ans++;
    }

    cout << ans << endl;
    return 0;
}
