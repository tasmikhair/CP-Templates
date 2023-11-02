void build(int node, int l, int r){
    if(l == r){
        tree[node] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(node << 1, l, mid);
    build(node << 1 | 1, mid + 1, r);
    tree[node] = tree[node << 1] + tree[node << 1 | 1];
}

ll query(int node, int ns, int ne, int q) {
	if (ns == ne) return tree[node];
	int mid = (ns + ne) / 2;
	if (q <= mid) {
		return tree[node] + query(2 * node, ns, mid, q);
	}
	else return tree[node] + query(2 * node + 1, mid + 1, ne, q);
}
void update(int node, int ns, int ne, int qs, int qe, ll add) {
	if (qe < ns || qs > ne) return;
	if (qs <= ns && ne <= qe) {
		tree[node] += add;
		return;
	}
	else {
		int mid = (ns + ne) / 2;
		update(2 * node, ns, mid, qs, qe, add);
		update(2 * node + 1, mid + 1, ne, qs, qe, add);
	}
}