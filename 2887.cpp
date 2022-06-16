/*
민지혜
https://www.acmicpc.net/problem/2887 (행성 터널)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int parent[100001];
vector <pair<int, int>> X;
vector <pair<int, int>> Y;
vector <pair<int, int>> Z;
vector <pair<int, pair<int, int>>> route; // distance, planet1, planet2


int find(int u) {
	if(parent[u] == u) return u;

	return parent[u] = find(parent[u]);
}


bool union_node(int u, int v) {
	u = find(u);
	v = find(v);

	if(u == v) // cycle
		return false;
	else {
		parent[u] = v;
		return true;
	}
}


int main() {

	int answer = 0;
	
	scanf("%d", &N);

	for(int i=0; i<N; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		X.push_back({x, i});
		Y.push_back({y, i});
		Z.push_back({z, i});

		parent[i] = i;
	}

	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	sort(Z.begin(), Z.end());

	for(int i=0; i<N-1; i++){
		route.push_back({X[i+1].first-X[i].first, {X[i].second, X[i+1].second}});
		route.push_back({Y[i+1].first-Y[i].first, {Y[i].second, Y[i+1].second}});
		route.push_back({Z[i+1].first-Z[i].first, {Z[i].second, Z[i+1].second}});
	}
	
	sort(route.begin(), route.end());

	
	for(int i=0; i<int(route.size()); i++) {
		int distance = route[i].first;
		int planet1 = route[i].second.first;
		int planet2 = route[i].second.second;

		// union success
		if(union_node(planet1, planet2))
			answer += distance;

	}
	
	printf("%d", answer);
}