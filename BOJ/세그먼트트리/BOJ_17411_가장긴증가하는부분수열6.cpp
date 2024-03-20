#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define all(v) (v).begin(), (v).end()
#define Compress(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define IDX(v, x) (lower_bound(all(v), x) - (v).begin())

constexpr int MOD = 1e9 + 7;

template<typename T = int64_t, size_t sz = 17, typename F = plus<T>>
struct SegTree {
	vector<T> tree; T t; F f{};
	SegTree(T t = T()) : tree(1 << sz + 1, t), t(t) {}
	explicit SegTree(T t, const F& f) : tree(1 << sz + 1, t), t(t), f(f) {}

	void Update(int i, T val) {
		--i |= 1 << sz, tree[i] = val;
		while (i >>= 1) tree[i] = f(tree[i << 1], tree[i << 1 | 1]);
	}
	T Query(int l, int r) {
		T L = t, R = t; --l |= 1 << sz, --r |= 1 << sz;
		while (l <= r) {
			if (l & 1) L = f(L, tree[l++]);
			if (~r & 1) R = f(tree[r--], R);
			l >>= 1, r >>= 1;
		}
		return f(L, R);
	}
};

struct Node { int DP[2]{ 0, 1 }; };

struct F {
	Node operator() (const Node& a, const Node& b) const {
		if (a.DP[0] ^ b.DP[0]) return a.DP[0] > b.DP[0] ? a : b;
		if (a.DP[0]) return { a.DP[0], (a.DP[1] + b.DP[1]) % MOD };
		return { 0, 1 };
	}
};

int main() {
	fastio;
	int n; cin >> n;
	vector<int> v(n), I(n);
	for (int i = 0; i < n; i++) cin >> v[i], I[i] = v[i]; Compress(I);
	for (int i = 0; i < n; i++) v[i] = IDX(I, v[i]) + 1;

	SegTree<Node, 20, F> ST;
	for (int i = 0; i < n; i++) {
		auto p = ST.Query(1, v[i] - 1);
		auto c = ST.Query(v[i], v[i]);
		if (p.DP[0] + 1 < c.DP[0]) continue;
		if (p.DP[0] + 1 == c.DP[0]) ST.Update(v[i], Node{ c.DP[0], (c.DP[1] + p.DP[1]) % MOD });
		else ST.Update(v[i], Node{ p.DP[0] + 1, p.DP[1] });
	}

	int mx = ST.Query(1, I.size()).DP[0], cnt = 0;
	for (int i = 0; i < I.size(); i++) {
		if (ST.tree[1 << 20 | i].DP[0] == mx)
			cnt = (cnt + ST.tree[1 << 20 | i].DP[1]) % MOD;
	}
	cout << mx << ' ' << cnt << '\n';
}