#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1000000
typedef long long ll;

struct Node {
	ll pref, suf, sum, max_s;
	Node(): pref(0), suf(0), sum(0), max_s(-INF) {};
	
};

const int MaxN = 500000;
ll a[MaxN];
Node tree[MaxN];
int n = 500000;

void build(int v, ll tl, ll tr){
	if (tl == tr)
		tree[v].pref = tree[v].suf = tree[v].sum = tree[v].max_s = a[tl];
	else {
		int m = (tl + tr) / 2;
		build (v*2, tl, m);
		build (v*2 + 1, m+1, tr);

		tree[v].sum = tree[2*v].sum + tree[2*v + 1].sum;
		tree[v].pref = max(tree[2*v].pref, tree[2*v + 1].pref + tree[2*v].sum);
		tree[v].suf = max(tree[2*v + 1].suf, tree[2*v].suf + tree[2*v + 1].sum);
		tree[v].max_s = max(tree[2*v].max_s, max(tree[2*v + 1].max_s, tree[2*v].suf + tree[2*v + 1].pref));
	}
}


int func (ll v, ll tl, ll tr, ll l, ll r){
	if (l > r) 
	{
		return INF;
	}
	if (tl == l && tr == r) return tree[v].max_s;

	ll m = (tl + tr)/2;
	tree[v*2].max_s =  func (2*v, tl, m, l, min(m, r));
	tree[v*2 + 1].max_s = func (2*v+1, m+1, tr, max(l, m+1), r);

		tree[v].sum = tree[2*v].sum + tree[2*v + 1].sum;
		tree[v].pref = max(tree[2*v].pref, tree[2*v + 1].pref + tree[2*v].sum);
		tree[v].suf = max(tree[2*v + 1].suf, tree[2*v].suf + tree[2*v + 1].sum);
		tree[v].max_s = max (max (tree[2*v].max_s, tree[2*v + 1].max_s), tree[2*v].suf + tree[2*v + 1].pref);
	return tree[v].max_s;
}

void update(ll v, ll tl, ll tr, ll value, ll pos){
	if (tl == tr) tree[v].max_s = tree[v].pref = tree[v].suf = tree[v].sum = value;
	else{
		ll m = (tl + tr)/2;
		if (m >= pos) update(2*v, tl, m, value, pos);
		else update(2*v + 1, m+1, tr, value, pos);

		tree[v].sum = tree[2*v].sum + tree[2*v + 1].sum;
		tree[v].pref = max(tree[2*v].pref, tree[2*v + 1].pref + tree[2*v].sum);
		tree[v].suf = max(tree[2*v + 1].suf, tree[2*v].suf + tree[2*v + 1].sum);
		tree[v].max_s = max(max(tree[2*v].max_s, tree[2*v + 1].max_s), tree[2*v].suf + tree[2*v + 1].pref);
	}
}


int main(){
	ll n_, k, x, y;
	int sym;

	cin >> n_;
	for (int i = 1; i <= n_; ++i)
	{
		cin >> a[i];
	}

	cin >> k;
	build(1, 1, n_);
	
	while (k--){
		cin >> sym >> x >> y;
		if(sym == 1){ 
			Node t;
			t.max_s = func(1, 1, n, x, y);
			cout << t.max_s << endl;
		}
		else if(sym == 0) update(1, 1, n, y, x);
	}
	
	system ("pause");
	return 0;
}