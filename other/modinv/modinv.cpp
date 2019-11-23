#include <iostream>
using namespace std;

long long extGCD(long long a, long long b, long long &x, long long &y) {
    cout << a << " " << b  << endl;  
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    
    long long d = extGCD(b, a%b, y, x); // 再帰的に解く
    cout << a << " " <<  b << " " <<  x << " " << y  << endl;  
    y -= a / b * x;
    
    return d;
}

// mod. m での a の逆元 a^{-1} を計算する
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    cout << u << " " << v << endl;
    return u;
}

// a ÷ b mod. MOD を計算してみる
int main() {

    //割り算MOD
    //割り算は掛け算で表せる
    //つまり割る数の逆元を割られる数にかける
    //

    const int MOD = 1000000007;

    long long a = 12345678900000;
    long long b = 100000;

    long long x, y;
    extGCD(a, b, x, y);
    cout << x << " " << y << endl;

    // a を 10000000007 で割ってから b の逆元をかけて計算
    a %= MOD;
    cout << a * modinv(b, MOD) % MOD << endl;

    /*
    for (int i = 1; i < 13; ++i) {
        cout << i << " 's inv: " << modinv(i, 13) << endl;
    }
    */

}