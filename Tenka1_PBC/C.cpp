#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
ll N;

int main(){

    ll N;
    cin >> N;

    vector<ll > A(N, 0);

    for(ll i = 0; i < N; i++){
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    if(N == 2){
        cout << A[1]-A[0] << endl;
        return 0;
    }else{
        ll t1 = 0;
        ll t2 = 0;
        if(N % 2 == 0){
            for(ll i = 0; i < N / 2; i++){
                t1 += A[i];
            }
            for(ll i = N / 2; i < N; i++){
                t2 += A[i];
            }
            //cout << t1 << " " << t2 << endl;
            t1 *= 2;
            t2 *= 2;
            //ll ans = max(, t2 - t1 + A[N/2-1]);
            cout << (t2 - A[N/2]) - (t1 - A[N/2-1])  << endl;

        }else{
            //どっちで分割すると良さそうか
            for(ll i = 0; i <= N / 2; i++){
                t1 += A[i];
            }
            for(ll i = N / 2 + 1; i < N; i++){
                t2 += A[i];
            }
            //cout << t1 << " " << t2 << endl;
            t1 *= 2;
            t2 *= 2;

            ll ans = t2 - (t1 - A[N/2] - A[N/2-1]);

            t1 = 0;
            t2 = 0;

            for(ll i = 0; i < N / 2; i++){
                t1 += A[i];
            }
            for(ll i = N / 2; i < N; i++){
                t2 += A[i];
            }

            t1 *= 2;
            t2 *= 2;

            ans = max(ans, (t2 - A[N/2] - A[N/2+1]) - t1);

            cout << ans << endl;

            //cout << t2 - (t1 - A[N/2] - A[N/2-1])  << endl;
        }
    }

}
