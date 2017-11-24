#include <iostream>
#include <string>

using namespace std;

void solve(string s){
	int len = s.length();
	int sum[100] = {0};
	int ans = 0;
	sum[0] = (s[0] == 'Q')? 1 : 0;
	for(int i=1; i<len; i++){
		sum[i] = sum[i-1] + (s[i] == 'Q'? 1 : 0);
	}
	for(int i=1; i<len; i++){
		ans += (s[i] == 'A')? sum[i] * (sum[len-1] - sum[i]) : 0;
	}
	cout << ans << endl;
}

int main(void){
	string s;
	getline(cin, s);
	solve(s);
}