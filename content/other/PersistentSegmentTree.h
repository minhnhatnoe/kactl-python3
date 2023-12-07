struct SegTree
{
    struct Node
    {
        ll l=0, r=0, sum=0;
        Node(){}
        Node(ll l, ll r, ll sum): l(l), r(r), sum(sum) {}
    };

    vector <ll> ver;
    vector <Node> St;

    SegTree (ll n)
    {
        ver.pb(build(1, n));
    }

    ll build(ll Start, ll End)
    {
        if (Start==End)
        {
            St.emplace_back(0, 0, 0);
            return St.size()-1;
        }
        ll mid=(Start+End)/2;
        ll L=build(Start, mid), R=build(mid+1, End);
        St.emplace_back(L, R, 0);
        return St.size()-1;
    }

    ll update(ll i, ll Start, ll End, ll idx, ll val)
    {
        if (Start==End)
        {
            ll sum=St[i].sum^val;
            St.emplace_back(0, 0, sum);
            return St.size()-1;
        }
        ll mid=(Start+End)/2, L, R; 
        if (idx<=mid)
        {
            L=update(St[i].l, Start, mid, idx, val);
            R=St[i].r;
        }
        else
        {
            L=St[i].l;
            R=update(St[i].r, mid+1, End, idx, val);
        }
        ll sum=St[L].sum^St[R].sum;
        St.emplace_back(L, R, sum);
        return St.size()-1;
    }

    ll query(ll i, ll Start, ll End, ll l, ll r)
    {
        if (Start>r || End<l) return 0;
        if (Start>=l && End<=r) return St[i].sum;
        ll mid=(Start+End)/2;
        ll q1=query(St[i].l, Start, mid, l, r), q2=query(St[i].r, mid+1, End, l, r);
        return q1^q2;
    }

    void Update(ll n, ll l, ll r, ll val)
    {
        ll idx=update(ver.back(), 1, n, r, val); ver.pb(idx);
        if (l>1) idx=update(ver.back(), 1, n, l-1, val), ver.pb(idx);
    }

    ll Query(ll n, ll v, ll idx)
    {
        if (idx==0) return 0;
        return query(v, 1, n, idx, n);
    }
};
