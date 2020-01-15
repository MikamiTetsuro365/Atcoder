#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919;

using namespace std;

/*
bool check(ll A){
    if(A % 400 == 0 || (A % 4 == 0 && A % 100 != 0)){
        return true;
    }
    return false;
}
*/

int main(){

    ll A, B;
    cin >> A >> B;

    ll ans = 0;
    
    ans += B / 4 - A / 4;
    //境界ピッタリの時
    if(A % 4 == 0){
        ans+=1;
    }

    ans -= B / 100 - A / 100;
    if(A % 100 == 0){
        ans-=1;
    }

    ans += B / 400 - A / 400;
    if(A % 400 == 0){
        ans+=1;
    }

    cout << ans << endl;

    

}