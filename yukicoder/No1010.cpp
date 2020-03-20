#include "bits/stdc++.h"
 
using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

ll dp[1919][1919];

int main(void){
    
    double x, y, h;
    cin >> x >> y >> h;
    x *= 1000;
    y *= 1000;

    if(x <= h || y <= h){
        cout << 0 << endl;
        return 0;
    }

    ll ans = 0;
    
    while(x > h || y > h){
        //cout << x << " " << y << " " << h << endl;
        if(x <= y){
            if(x > h){
                x /= 2;
                h *= 2;
            }else{
                y /= 2;
                h *= 2;
            }

        }else if(x > y){
            if(y > h){
                y /= 2;
                h *= 2;
            }else{
                x /= 2;
                h *= 2;
            }
        }
        ans++;
    }

    cout << ans << endl;

}


