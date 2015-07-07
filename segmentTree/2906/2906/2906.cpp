#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1000000000

typedef long long ll;

struct Node {
	ll max_sum, pref, suf, sum;
	Node(): max_sum(-INF), pref(0), suf(0), sum(0){}
};
 
const ll MaxN = 50000;
ll n = 50000;
void build (Node* tree,ll*a, ll v, ll tl, ll tr){
	if (tl == tr) 
		tree[v].max_sum = tree[v].max_sum = tree[v].pref = tree[v].suf = tree[v].sum = a[tl]; 
	else {
		ll m = (tl + tr) / 2;
		build (tree, a, v * 2, tl, m);
		build (tree, a, v * 2 + 1, m + 1, tr);

		tree[v].sum = tree[2*v].sum + tree[2*v + 1].sum;
		tree[v].pref = max(tree[2*v].pref, tree[2*v + 1].pref + tree[2*v].sum);
		tree[v].suf = max(tree[2*v + 1].suf, tree[2*v].suf + tree[2*v + 1].sum);
		tree[v].max_sum = max(max(tree[2*v].max_sum, tree[2*v + 1].max_sum), tree[2*v].suf + tree[2*v + 1].pref);
	}
}

int func (Node* tree, ll *a, ll v, ll tl, ll tr, ll l, ll r){
	if (l > r) 
	{
		return INF;
	}
	if (tl == l && tr == r) return tree[v].max_sum;

	ll m = (tl + tr)/2;
	tree[v*2].max_sum =  func (tree, a, 2*v, tl, m, l, min(m, r));
	tree[v*2 + 1].max_sum = func (tree, a, 2*v+1, m+1, tr, max(l, m+1), r);

		tree[v].sum = tree[2*v].sum + tree[2*v + 1].sum;
		tree[v].pref = max(tree[2*v].pref, tree[2*v + 1].pref + tree[2*v].sum);
		tree[v].suf = max(tree[2*v + 1].suf, tree[2*v].suf + tree[2*v + 1].sum);
		tree[v].max_sum = max(max(tree[2*v].max_sum, tree[2*v + 1].max_sum), tree[2*v].suf + tree[2*v + 1].pref);
	return tree[v].max_sum;
}

void update(Node* tree, ll *a, ll v, ll tl, ll tr, ll value, ll pos){
	if (tl == tr) tree[v].max_sum = tree[v].pref = tree[v].suf = tree[v].sum = value;
	else{
		ll m = (tl + tr)/2;
		if (m >= pos) update(tree, a, 2*v, tl, m, value, pos);
		else update(tree, a, 2*v + 1, m+1, tr, value, pos);

		tree[v].sum = tree[2*v].sum + tree[2*v + 1].sum;
		tree[v].pref = max(tree[2*v].pref, tree[2*v + 1].pref + tree[2*v].sum);
		tree[v].suf = max(tree[2*v + 1].suf, tree[2*v].suf + tree[2*v + 1].sum);
		tree[v].max_sum = max(max(tree[2*v].max_sum, tree[2*v + 1].max_sum), tree[2*v].suf + tree[2*v + 1].pref);
	}
}

int main() {
Node tree[4*MaxN];
ll a[MaxN];

	ll n_, k, x, y;
	int sym;

	cin >> n_;
	for (int i = 1; i <= n_; ++i)
	{
		cin >> a[i];
	}

	cin >> k;
	build(tree,a,1, 1, n);

	while (k--){
		cin >> sym >> x >> y;
		if(sym == 1){ 
			Node t;
			t.max_sum = func(tree, a, 1, 1, n, x, y);
			cout << t.max_sum << endl;
		}
		else if(sym == 0) update(tree, a, 1, 1, n, y, x);
	}
	return 0;
}