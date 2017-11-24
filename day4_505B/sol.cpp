#include<iostream>
#include<vector>
using namespace std;

typedef struct {
	vector<int> neighbors;
  vector<int> colors;
} Node;

const int mmax = 101;
const int nmax = 101;

Node adjList[nmax];

void printG(){
	for (int i=1; i<nmax; i++){
		if (!adjList[i].neighbors.size()){
			continue;
		}
		printf("[%d]: ", i);
		for(int j=0; j<adjList[i].neighbors.size(); j++){

			printf("(%d, %d)", adjList[i].neighbors.at(j), adjList[i].colors.at(j));
			if (j < adjList[i].neighbors.size() - 1){
				printf(" -> ");
			}
		}
		printf("\n");
	}
}

void dfs(int v, int c, int dest, int* visited, int* cnt){
	visited[v] = 1; // mark u as visited
	if (v == dest){
		*cnt += 1;
		return;
	}
	for(int i=0; i<adjList[v].neighbors.size(); i++){
		if (!visited[adjList[v].neighbors.at(i)] && adjList[v].colors.at(i) == c){
			dfs(adjList[v].neighbors.at(i), c, dest, visited, cnt);
		}
	}
}

int start_dfs(int u, int v){
	int cnt = 0;
	int used_color[mmax] = {0};
	for(int i=0; i<adjList[u].colors.size(); i++){
		int color = adjList[u].colors.at(i);
		if (!used_color[color]){
			int visited[nmax] = {0};
			dfs(u, color, v, visited, &cnt);
			used_color[color] = 1;
		}
	}
	return cnt;
}

void solve(int n, int m){
	// printG();
	int q,u,v,ans;
	cin >> q;
	for(int i=0; i<q; i++){
		cin >> u >> v;
		ans = start_dfs(u,v);
		cout << ans << endl;
	}
}

int main(void){
	int n,m,a,b,c;
	// init adjList
	for(int i=1; i<nmax; i++){
		adjList[i] = Node();
	}
	cin >> n >> m;

	for(int i=0; i<m; i++){
		cin >> a >> b >> c;
		adjList[a].neighbors.push_back(b);
		adjList[a].colors.push_back(c);
		adjList[b].neighbors.push_back(a);
		adjList[b].colors.push_back(c);
	}

	solve(n,m);
}