#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
ll N;

int main(){

    ll N, K;

    cin >> N >> K;

    string S;

    cin >> S;

    S[K-1] = S[K-1] + 0x20;

    cout << S << endl;

} 