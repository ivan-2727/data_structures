#include <bits/stdc++.h>
using namespace std; 
double EPS = 1e-15;

class SparseTable {
public:
	vector<vector<int>> sparse;
	SparseTable(vector<int> &a) {
		int n = a.size();
		sparse.push_back(a); 
		int prev_j = 0; 
		for (int d = 2; d <= n; d*=2) {
			vector <int> tmp; 
			for (int i = 0; i <= n-d; i++) {
				tmp.push_back(max(sparse[prev_j][i], sparse[prev_j][i+d/2])); 
			}
			sparse.push_back(tmp);
			prev_j++; 
		}
	}
	int get_range(int l, int r) {
		double j = log2(r-l+1); 
		if (abs(round(j) - j) < EPS) return sparse[(int)j][l];
		return max(sparse[(int)j][l], sparse[(int)j][l+(int)pow(2,j)]);
	}
};
