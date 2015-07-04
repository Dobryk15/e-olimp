#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1000000000

typedef long long ll;

struct Node {
	ll max;
	Node():  max(-INF){}
};
 
const ll MaxN = 500000;
ll n = 500000;
ll a[MaxN];

Node tree[4*MaxN];
void build (ll v, ll l, ll r){
	if (l == r) 
		tree[v].max = a[l]; 
	else {
		ll m = (l + r) / 2;
		build (v * 2, l, m);
		build (v * 2 + 1, m + 1, r);
		tree[v].max = max(tree[2*v].max, tree[2*v+1].max);
	}
}

int func (ll v, ll tl, ll tr, ll l, ll r){
	if (l > r) return Node().max;
	if (tl == l && tr == r) return tree[v].max;

	ll m = (tl + tr)/2;
	tree[v*2].max =  func (2*v, tl, m, l, min(m, r));
	tree[v*2 + 1].max = func (2*v+1, m+1, tr, max(l, m+1), r);
	Node ans;
	ans.max = max(tree[v*2].max, tree[v*2+1].max);
	return ans.max;
}

int main() {
	ll n_, m, x, y;
	cin >> n_;
	for (int i = 1; i <= n_; ++i)
	{
		cin >> a[i];
	}
	
	build(1, 1, n);
	cin >> m;
	while (m--){
		cin >> x >> y;
			Node t;
			t.max = func(1, 1, n, x, y);
			cout << t.max << endl;
	}
	system ("pause");
	return 0;
}
