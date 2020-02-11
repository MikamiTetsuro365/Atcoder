#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<double > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main() {

    ll N;
    cin >> N;
    
    vector<ll > A(N, 0);
    vector<ll > B(N, 0);
    vector<bool > f(N, false);
    priority_queue<pi > Takahashi;
    priority_queue<pi > Aoki;
    priority_queue<pi > Takahashi2;
    priority_queue<pi > Aoki2;

    for(ll i = 0; i < N; i++){
        cin >> A[i] >> B[i];
        //差分
        Takahashi.push(make_pair(B[i]-A[i], i));
        Aoki.push(make_pair(A[i]-B[i], i));
        //単純に大きい順の値
        Takahashi2.push(make_pair(A[i], i));
        Aoki2.push(make_pair(B[i], i));
    }

    ll T_sum = 0;
    ll A_sum = 0;

    for(ll i = 0; i < N; i++){
        if(i % 2 == 0){
            while(true){
                if(f[Takahashi.top().second] == false){
                    break;
                }
                Takahashi.pop();
            }
            while(true){
                if(f[Takahashi2.top().second] == false){
                    break;
                }
                Takahashi2.pop();
            }

            if(Takahashi.top().first > Takahashi2.top().first){
                f[Takahashi.top().second] = true;
                T_sum += A[Takahashi.top().second];
                Takahashi.pop();
            }else{
                f[Takahashi2.top().second] = true;
                T_sum += A[Takahashi2.top().second];
                Takahashi2.pop();
            }
     
        }else{
            while(true){
                if(f[Aoki.top().second] == false){
                    break;
                }
                Aoki.pop();
            }

            while(true){
                if(f[Aoki2.top().second] == false){
                    break;
                }
                Aoki2.pop();
            }

            if(Aoki.top().first > Aoki2.top().first){
                f[Aoki.top().second] = true;
                A_sum += B[Aoki.top().second];
                Aoki.pop();
            }else{
                f[Aoki2.top().second] = true;
                A_sum += B[Aoki2.top().second];
                Aoki2.pop();
            }

        }
    }    

    cout << T_sum - A_sum << endl;

}