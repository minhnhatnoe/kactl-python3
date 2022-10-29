void cdq(int l, int r) {
    if(l + 1 == r) return;
    int m = (l + r) >> 1;
    cdq(l, m); cdq(m, r);
    int a = l, b = m, sum = 0;
    // need to record the modifications on DS in order to reset it. The complexity will be $O(N^2)$ if we resetting it brute-forcely.
    vector<int> record;
    // temporary
    //two pointer process the effect of [l->m) to [m->r]
    vector<Pt> tmp;
    while(a < m && b < r) {

    }
    while(a < m)
    while(b < r)
    for(int i = l ; i < r ; ++i) v[i] = tmp[i - l];
    // reset DS
    for(auto i : record) bit.update(i, -1);
    // release used memory
    vector<int> ().swap(record);
    vector<Pt> ().swap(tmp);
}