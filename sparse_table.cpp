#include <bits/stdc++.h>
using namespace std; 
double EPS = 1e-15;

class SparseTable {
public:
	vector<vector<int>> sparse;
	SparseTable(vector<int> &a) {
		int m = a.size();
		sparse.push_back(a); 
		int prev_j = 0; 
		for (int d = 2; d <= m; d*=2) {
			vector <int> tmp; 
			for (int i = 0; i <= m-d; i++) {
				tmp.push_back(max(sparse[prev_j][i], sparse[prev_j][i+d/2])); 
			}
			sparse.push_back(tmp);
			prev_j++; 
		}
	}
	int get_range(int l, int r) {
		int d = r-l+1; 
		double x = log2(d);
		if (abs(x - round(x)) < EPS) return sparse[(int)round(x)][l]; 
		int j = (int)log2(d); 
		int step = (int)pow(2,j); 
		return max(sparse[j][l], sparse[j][r-step+1]);
	}
};
