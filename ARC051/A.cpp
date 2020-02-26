#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

ll grid[500][500];

int main(){

    double x1, y1, r;
    cin >> x1 >> y1 >> r;

    double x2, y2, x3, y3;
    cin >> x2 >> y2 >> x3 >> y3;

    double r1 = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
    double r2 = sqrt(pow(x3-x1, 2) + pow(y3-y1, 2));
    double r3 = sqrt(pow(x2-x1, 2) + pow(y3-y1, 2));
    double r4 = sqrt(pow(x3-x1, 2) + pow(y2-y1, 2));

    // cout << x1 - r << endl;
    // cout << x1 + r << endl;
    // cout << y1 - r << endl;
    // cout << y1 + r << endl;
    if(x1 - r >= x2 && x1 + r <= x3 && y2 <= y1 - r && y3 >= y1 + r){
        //長方形が円を食った
        cout << "NO" << endl;
        cout << "YES" << endl;
        return 0;
    }
    
    if(r1 <= r && r2 <= r && r3 <= r && r4 <= r){
        cout << "YES" << endl;
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    cout << "YES" << endl;


}