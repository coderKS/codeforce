#include <iostream>
using namespace std;

void solve(int n, int m){
	int day, height, prev_day, prev_height, ans = 0;
	cin >> day >> height;
	ans = max(ans, height + day - 1); // assuming height keep decreasing from first day
	prev_day = day;
	prev_height = height;

	for(int i=1; i<m; i++){
		cin >> day >> height;
		if (abs(height - prev_height) > day - prev_day){ 
			// height difference > day difference => impossible to connect two end
			cout << "IMPOSSIBLE" << endl;
			return;
		}
		int remaining_day = (day-prev_day) - abs(height - prev_height);
		ans = max(ans, max(height, prev_height) + (remaining_day / 2));
		prev_day = day;
		prev_height = height;
	}

	ans = max(ans, height + n - day); // assuming height keep increasing since last record
	cout << ans << endl;
}	

int main(void){
	int n,m,day,height;
	cin >> n >> m;
	solve(n, m);
}