#define _USE_MATH_DEFINES
#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

int main(){

    double a,b,x; cin >> a >> b >> x;

    double hight = x / (a * a);

    //cout << hight << endl;
    //cout << 2 * hight * a / (b * b) << endl;

    double ans1 = 0;
    if(hight <= b / 2){
        ans1 = 90 - atan(2 * hight * a / (b * b)) * (180 / M_PI);
    }else{
        ans1 = 90 - atan(a /( 2 * (b - hight))) * (180 / M_PI);
    }
    

    cout << fixed << setprecision(10) << ans1 << endl;

}