//sos[i] = sum of all submasks of i
//Time complexity: n*(2^n)

vector<ll> sos(vector<ll> A){
    vector<ll> re = A;
    for(int i = 0; i<(1<<n); ++i)re[i] = A[i];
        for(int i = 0;i < n; ++i) for(int mask = 0; mask < (1<<n); ++mask){
            if(mask & (1<<i)){
            re[mask] += re[mask^(1<<i)];
            re[mask]%=MOD;
        }
    }
    return re;
}
