struct Node{
	int l, r, val;
};
 
int n, cur;
int a[100005], pos[100005], root[100005];
Node segtree[2400005];
 
int build(int l, int r) {
	int id = ++cur;
	if (l == r) segtree[id].val = 1;
	else {
		int m = (l + r)/2;
		int idL = build(l, m), idR = build(m + 1, r);
		segtree[id].val = segtree[idL].val + segtree[idR].val;
		segtree[id].l = idL; segtree[id].r = idR;
	}
	return id;
}
 
int update(int id, int l, int r, int pos) {
	int idN = ++cur;
	if (l == r) segtree[idN].val = 0;
	else {
		int m = (l + r)/2;
		if (pos <= m) {
			int idL = update(segtree[id].l, l, m, pos), idR = segtree[id].r;
			segtree[idN].val = segtree[idL].val + segtree[idR].val;
			segtree[idN].l = idL; segtree[idN].r = idR;
		}
		else {
			int idL = segtree[id].l, idR = update(segtree[id].r, m + 1, r, pos);
			segtree[idN].val = segtree[idL].val + segtree[idR].val;
			segtree[idN].l = idL; segtree[idN].r = idR;
		}
	}
	return idN;
}
 
pii query(int id, int l, int r, int pos, int val) {
	if (r < pos) return {-1, 0};
	if (l >= pos) {
		if (segtree[id].val < val) return {-1, segtree[id].val};
		while (l != r) {
			int m = (l + r)/2;
			if (segtree[segtree[id].l].val >= val) {
				id = segtree[id].l;
				r = m;
			}
			else {
				val -= segtree[segtree[id].l].val;
				id = segtree[id].r;
				l = m + 1;
			}
		}
		return {l, 0};
	}
 
	int m = (l + r)/2;
	auto p1 = query(segtree[id].l, l, m, pos, val);
	if (p1.first != -1) return p1;
	auto p2 = query(segtree[id].r, m + 1, r, pos, val - p1.second);
	if (p2.first != -1) return p2;
	return {-1, p1.second + p2.second};
}