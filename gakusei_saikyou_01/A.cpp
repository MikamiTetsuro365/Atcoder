#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

int main(){

    ll N, M;
    cin >> N >> M;

    vector<bool > w(2 * pow(10,6) + 1, false);
    map<ll, vector<pair<ll, ll> > > mp;
    

    vector<ll > A(N, 0);
    vector<ll > B(M, 0);

    for(ll i = 0; i < N; i++){
        cin >> A[i];
    }

    for(ll i = 0; i < M; i++){
        cin >> B[i];
    }

    //重複削除(しない)たかだか10^6以下しか残らない
    //sort(A.begin(), A.end());
    //sort(B.begin(), B.end());
    //A.erase(unique(A.begin(), A.end()), A.end());
    //B.erase(unique(B.begin(), B.end()), B.end());

    for(ll i = 0; i < A.size(); i++){
        for(ll j = 0; j < B.size(); j++){
            //mp[A[i] * B[i]].push_back(make_pair(A[i], B[i]));
            //cout << A[i] + B[j] << endl;
            ll t_w = A[i] + B[j];
            if(w[t_w] == true){
                mp[t_w].push_back(make_pair(i, j));
                cout << mp[t_w][0].first << " " << mp[t_w][0].second << " ";
                cout << mp[t_w][1].first << " " << mp[t_w][1].second << endl;
                //cout << i << " " << j << endl;
                return 0;
            }else{
                mp[t_w].push_back(make_pair(i, j));
                w[t_w] = true;
            }

        }
    }

    cout << "-1" << endl;


}