#include <iostream>
#include <algorithm>

using namespace std;

#define INF 100000
using namespace std;
struct Node{
	int sum;
	Node(): sum(0){};
};

const int MaxN = 500000;
int q = 100000;
int a[MaxN];
Node tree[4*MaxN];

Node build (int v, int tl, int tr){
	if (tl == tr)  
	{
		tree[v].sum = a[tl];
		return tree[v];
	}

	else {
		int m = (tl+tr)/2;
		build (v*2, tl, m);
		build (v*2 + 1, m + 1, tr);
		tree[v].sum = tree[v*2].sum + tree[v*2 + 1].sum;
	}
	return tree[v];
}

int sum(int v, int tl, int tr, int l, int r)
{
	if (l > r) return 0;
	if (tl == l && tr == r) return tree[v].sum;
	else{
		int m = (tl + tr)/2;
		return sum (v*2, tl, m, l, min(m,r)) + sum (v*2 + 1, m + 1, tr, max(m+1, l), r);
	}
}

void update (int v, int tl, int tr, int pos, int value){
	if (tl == tr) {
		tree[v].sum = value;
		return;
	}
	else {
		int m = (tl + tr)/2;
		if (pos <= m) 
			update(2*v, tl, m, pos, value);
		else 
			update(2*v + 1, m + 1, tr, pos, value);
		tree[v].sum = tree[2*v].sum + tree[2*v + 1].sum;
	}

}
int main () 
{
	
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	build (1, 1, n);
	
	while (q--){
		char sym; 
		int a_, b_;
		cin >> sym >> a_ >> b_;
		if (sym == '=') 
			update (1, 1, n, a_, b_);
		else if (sym == '?') 
			cout << sum(1, 1, n, a_, b_) << endl;
	}
	
	return 0;
}

