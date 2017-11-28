#include<iostream>
#include<set>

using namespace std;
const int nmax = 300005;
const int mmax = 300005;

void solve(int n, int m){
	int ans[nmax], tmp[nmax], l,r,x;
	set<int> s;
	for(int i=1; i<=n; i++){
		s.insert(i);
	}

	for(int i=0; i<m; i++){
		cin >> l >> r >> x;
		int cnt = 0;
		for(set<int>::iterator it = s.lower_bound(l); it!=s.end() && (*it)<=r; it++){
			if (*it != x){
				ans[*it] = x; // loser
				tmp[cnt++] = *it;
			} else {
				ans[*it] = 0; // winner
			}
		}
		// erase the losers
		for(int j=0; j<cnt; j++)	s.erase(tmp[j]);
	}

	for(int i=1; i<=n; i++){
		printf("%d ", ans[i]);
	}
	putchar('\n');
}

int main(){
	int n,m;
	cin >> n >> m;
	solve(n,m);
}