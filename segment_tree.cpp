#include <bits/stdc++.h>
using namespace std; 
 
class STnode {
public:
	int l; 
	int r;
	int val;
	STnode* left;
	STnode* right;
	STnode(int _l, int _r, int _val) {
		l = _l; r = _r; val = _val;
		left = nullptr; right = nullptr;
	}
};
 
STnode* make_node(vector <int> &a, int l, int r) {
	if (l==r) return new STnode(l, r, a[l]);
	STnode* left = make_node(a, l, (l+r)/2);
	STnode* right = make_node(a, (l+r)/2+1, r);
	//STnode* cur = new STnode(l, r, type? max(left->val, right->val) : min(left->val, right->val));
	STnode* cur = new STnode(l, r, max(left->val, right->val));
	cur->left = left; cur->right = right;
	return cur; 
}
 
int get_range(STnode* cur, int l, int r) {
	if (cur->l == l and cur->r == r) return cur->val; 
	int mid = (cur->l + cur->r)/2; 
	if (l >= cur->l and r <= mid) return get_range(cur->left, l, r);
	if (l >= mid+1 and r <= cur->r) return get_range(cur->right, l, r);
	int left_res = get_range(cur->left, l, mid);
	int right_res = get_range(cur->right, mid+1, r); 
	//return type? max(left_res, right_res) : min(left_res, right_res); 
	return max(left_res, right_res); 
}
