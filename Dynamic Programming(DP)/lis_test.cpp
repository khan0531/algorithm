#include <bits/stdc++.h>

using namespace std;

string a, b, ans;

void LCS(int l1, int r1, int l2, int r2) {
	if (l1 > r1) return;
	if (l1 == r1) {
		for (int i = l2; i <= r2; i++) if (b[i] == a[l1]) { ans.push_back(b[i]); break; }
		return;
	}

	int mid = l1 + r1 >> 1;
	vector<int> LCS1(r2 - l2 + 3), LCS2(r2 - l2 + 3), Prv(r2 - l2 + 3);
	for (int i = l1; i <= mid; i++) {
		for (int j = l2; j <= r2; j++) {
			if (a[i] == b[j]) LCS1[j - l2 + 1] = Prv[j - l2] + 1;
			else LCS1[j - l2 + 1] = max(LCS1[j - l2], Prv[j - l2 + 1]);
		}
		Prv = LCS1;
	}
	fill(Prv.begin(), Prv.end(), 0);
	for (int i = r1; i > mid; i--) {
		for (int j = r2; j >= l2; j--) {
			if (a[i] == b[j]) LCS2[j - l2 + 1] = Prv[j - l2 + 2] + 1;
			else LCS2[j - l2 + 1] = max(LCS2[j - l2 + 2], Prv[j - l2 + 1]);
		}
		Prv = LCS2;
	}

	int mx = -1, idx = 0;
	for (int i = l2; i <= r2 + 1; i++) {
		if (mx < LCS1[i - l2] + LCS2[i - l2 + 1])
			mx = LCS1[i - l2] + LCS2[i - l2 + 1], idx = i;
	}
	LCS(l1, mid, l2, idx - 1);
	LCS(mid + 1, r1, idx, r2);
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> a >> b;
	LCS(0, a.size() - 1, 0, b.size() - 1);
	cout << ans.size() << '\n' << ans << '\n';
}