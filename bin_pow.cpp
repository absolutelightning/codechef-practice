//
// Created by Ashesh Vidyut on 07/07/24.
//

class BinPow {
    long long bin_pow(long long a, long long b, long long mod) {
        if (a == 1 || b == 0) {
            return 1;
        }
        long long res = bin_pow(a, b >> 1, mod);
        res = res * res;
        res %= mod;
        if (b & 1) {
            res = res * a;
        }
        return res % mod;
    }

    long long bin_pow(long long a, long long b) {
        if (a == 1 || b == 0) {
            return 1;
        }
        long long res = bin_pow(a, b >> 1);
        res = res * res;
        if (b & 1) {
            res = res * a;
        }
        return res;
    }

};