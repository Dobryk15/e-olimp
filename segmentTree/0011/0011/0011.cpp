#include <iostream>

using namespace std;

int main(){
	string s;
	int m, n, k, v;
	int arr[1000];
	cin >> m >> n >> k;
	v = m - ((m / n) * n);
	cout << m / n << '.';
	for (; k > 0; --k)
		if (v != 0)
		{
			int i = 0;
			arr[i] = (v * 10) / n;
			cout << arr[i];
			v = (v * 10 - n * arr[i]);
		}
		else 
			cout << 0;
	cout << endl;
	
return 0;
}