#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  

int main(){

    ll N, M; cin >> N >> M;
    vector<string > A;
    vector<string > B;

    for(ll i = 0; i < N; i++){
        string s; cin >> s;
        A.push_back(s);
    }

    for(ll i = 0; i < M; i++){
        string s; cin >> s;
        B.push_back(s);
    }

    //例外そうなパターンは一応入れておく！
    if(N == M){
        if(A[0] == B[0]) cout << "Yes" << endl;
        else cout << "No" << endl;
        return 0;
    }

    for(ll i = 0; i < N - M; i++){
        for(ll j = 0; j < N - M; j++){
            bool f = true;
            for(ll row = 0; row < M; row++){
                for(ll col = 0; col < M; col++){
                    if(A[i+row][j+col] != B[row][col]){
                        f = false;
                        break;
                    }
                }
                if(f == false){
                    break;
                }
            }
            if(f == true){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

}