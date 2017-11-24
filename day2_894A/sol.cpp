#include <iostream>
#include <string>

using namespace std;

void solve(string s){
	int len = s.length();
	int i,j,k,ans;
	ans = 0;
	for(i=0;i<len;i++){
		if (s[i] == 'Q'){
			for(j=i+1;j<len;j++){
				if (s[j] == 'A'){
					for(k=j+1;k<len;k++){
						if (s[k] == 'Q'){
							ans++;
						}
					}
				}
			}
		}
	}
	cout << ans << endl;
}
int main(void){
	string s;
	getline(cin, s);
	solve(s);
}
