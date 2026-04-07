#include <iostream>
#include <vector>
using namespace std;

int find(int x, vector<int>& parent, vector<int>& d) {
	if (parent[x] != x) {
		int root = find(parent[x], parent, d);
		d[x] += d[parent[x]];
		parent[x] = root;
	}
	return parent[x];
}

void merge(int x, int y, vector<int>& parent, vector<int>& d) {
	int rx = find(x, parent, d);
	int ry = find(y, parent, d);
	parent[rx] = ry;
	
}

int main()
{

}