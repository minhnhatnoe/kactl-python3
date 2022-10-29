// Number of different xor sums: 2^(basis size)
bool insertVector(int msk) {
    for1(i,0,n - 1) if (msk & (1 << i)) {
        if (!basis[i]) {
            basis[i] = msk;
            return 1;
        }
        msk ^= basis[i];
    }
    return 0;
}