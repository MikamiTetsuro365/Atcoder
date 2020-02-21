#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main() {

    ll A, B, C, K;
    cin >> A >> B >> C >> K;
    // A, B, C -> A+x , A, Bとして考える
    //常に締め出される変数はxこれがA側B側のどちらかで必ず1つ締め出される

    if(K % 2 == 0){
        cout << A - B << endl;
    }else{
        cout << B - A << endl;
    }

}