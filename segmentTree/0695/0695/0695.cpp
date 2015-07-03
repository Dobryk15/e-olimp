#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1000000000

typedef long long ll;

struct Node {
	ll max, min;
	Node(): min(INF), max(-INF){}
};
 
const ll MaxN = 101000;
ll n = 100000;

Node tree[4*MaxN];
void build (ll v, ll l, ll r){
	if (l == r) 
		tree[v].max = tree[v].min = (l % 12345) * (l % 12345) % 12345 + (l % 23456) * (l % 23456) * (l % 23456) % 23456;
	else {
		ll m = (l + r) / 2;
		build (v * 2, l, m);
		build (v * 2 + 1, m + 1, r);
		tree[v].min = min(tree[2*v].min, tree[2*v+1].min);
		tree[v].max = max(tree[2*v].max, tree[2*v+1].max);
	}
}

Node func (ll v, ll tl, ll tr, ll l, ll r){
	if (l > r) return Node();
	if (tl == l && tr == r) return tree[v];

	ll m = (tl + tr)/2;
	Node left = func (2*v, tl, m, l, min(m, r));
	Node right = func (2*v+1, m+1, tr, max(l, m+1), r);
	Node ans;
	ans.max = max(left.max, right.max);
	ans.min = min(left.min, right.min);
	return ans;
}

void update(ll v, ll tl, ll tr, ll value, ll pos){
	if (tl == tr) tree[v].max = tree[v].min = value;
	else{
		ll m = (tl + tr)/2;
		if (m >= pos) update (2*v, tl, m, value, pos);
		else update (2*v + 1, m+1, tr, value, pos);
		tree[v].min = min(tree[2*v].min, tree[2*v+1].min);
		tree[v].max = max(tree[2*v].max, tree[2*v+1].max);
	}
}

int main() {
	ll k, x, y;
	cin >> k;
	build(1, 1, n);

	while (k--){
		cin >> x >> y;
		if(x > 0){ 
			Node t = func(1, 1, n, x, y);
			cout << t.max - t.min << endl;
		}
		else if(x < 0) update(1, 1, n, y, -x);
	}
	return 0;
}