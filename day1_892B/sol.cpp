#include <iostream>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

void solve(int n, int *l){
	int i, cnt, ans;
	ans = 1;
	cnt = n - 1 - l[n-1];
	for(i=n-1; i>=0; i--){
		if (cnt <= 0) break;
		if (i < cnt) ans++;
		cnt = min(cnt, i - l[i]);
	}
	cout << ans << endl;
}

int main(void){
	int i,n;
	cin >> n;
	int l[n];
	REP(i,n){
		scanf("%d", &l[i]);
	}
	solve(n, l);	
	return 0;
}

