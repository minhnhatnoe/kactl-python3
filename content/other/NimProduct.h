typedef long long ll;

ll mul(ll a, ll b);

ll P[64][64];

// Compute the nim product of 2^a and 2^b
ll mul2(ll a, ll b) {
    if(a == 0 || b == 0) {
        return 1LL << (a + b);
    } else if(P[a][b]) {
        return P[a][b];
    } else {
        ll n = 1;
        while(2 * n <= max(a, b)) {
            n *= 2;
        }
        if (a >= n && b >= n) {
            return P[a][b] = mul((3ULL << (n - 1)), mul2(a - n, b - n));
        } else if (a >= n) {
            return P[a][b] = mul2(a - n, b) << n;
        } else {
            return P[a][b] = mul2(a, b - n) << n;
        }
    }
}

// Compute the nim product of a and b
ll mul(ll a, ll b) {
    ll ans = 0;
    ll A[64], B[64];
    ll sza = 0, szb = 0;
    for(ll i = 0; i < 64; i++) {
        if((a >> i) & 1) {
            A[sza++] = i;
        }
        if((b >> i) & 1) {
            B[szb++] = i;
        }
    }
    for(ll i = 0; i < sza; i++) {
        for(ll j = 0; j < szb; j++) {
            ans ^= mul2(A[i], B[j]);
        }
    }
    return ans;
}