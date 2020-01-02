#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

ll INF = 114514191919119;

int main(){

    ll N, M;
    cin >> N >> M;
    ll X, Y;
    cin >> X >> Y;

    queue<ll > A;
    queue<ll > B;

    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        A.push(t);
    }

    //A.push(-1);

    for(ll i = 0; i < M; i++){
        ll t; cin >> t;
        B.push(t);
    }

    //B.push(-1);

    ll time = 0;
    ll ans = 0;

    ll f = 0;

    bool swi = true;
    while(true){
        //cout << f << endl;
        while(!A.empty()){

            if(A.front() >= time){
                time = A.front();
                time += X;
                A.pop();
                swi = false;
                break;
            }
            A.pop();
        }

        //Aで便がなくなってもBを確かめるまで確定できない
        if(A.empty() && swi == true) break;

        while(!B.empty()){
            if(B.front() >= time){
                time = B.front();
                time += Y;
                B.pop();
                ans++;
                swi = true;
                break;
            }
            B.pop();
        }

        //Aに戻る術がない
        if(B.empty()) break;
        
    }
    cout << ans << endl;
}