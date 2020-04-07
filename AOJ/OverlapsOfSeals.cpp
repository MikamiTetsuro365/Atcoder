#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;
typedef pair<pair<double, double >, double > pdd;
typedef pair<double, double > pd;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

double calc_dist(double x1, double x2, double y1, double y2){
    double d = sqrt((x2-x1) * (x2-x1) + (y2-y1) * (y2-y1));
    return d;
}

vector<pd> calc_cross(pdd a, pdd b, double d){
    //共有点1つか2つか
    vector<pd> cc;
    if(d == (a.second + b.second) || d == (a.second - b.second)){
        cc.push_back(make_pair((a.first.first + b.first.first)/2, (a.first.second + b.first.second)/2));
    }else{
        //bcos 
        double rc = (d*d + a.second * a.second - b.second * b.second) / (2*d);   
        //中点への距離
        double rs = sqrt(a.second * a.second - rc * rc);
        double diffx = (b.first.first - a.first.first) / d;
        double diffy = (b.first.second - a.first.second) / d;
        
        pd cc1 = make_pair(a.first.first + diffx * rc, a.first.second + diffy * rs);
        pd cc2 = make_pair(a.first.first + diffx * rc, a.first.second + diffy * -rs);
        
        cc.push_back(cc1);
        cc.push_back(cc2);
    }

    return cc;
}

int main(){

    ll N;
    cin >> N;

    vector<pdd> C;
    for(ll i = 0; i < N; i++){
        double x, y;
        cin >> x >> y;
        C.push_back(make_pair(make_pair(x, y), 1));
    }

    ll ans = 1;
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < N; j++){
            if(i == j) continue;
            //距離
            double D = calc_dist(C[i].first.first, C[j].first.first, C[i].first.second, C[j].first.second);
            //2つの円同士に共有点がなければ調べない
            //内接は問題文的にないけど一応書いておく
            //D > r1 + r2 or D < r1 + r2
            if(D > (C[i].second + C[j].second) || D < (C[i].second - C[j].second)) continue;

            vector<pd > CC = calc_cross(C[i], C[j], D);

            cout << CC.size() << endl;
            for(ll k = 0; k < CC.size(); k++){
                cout << fixed << setprecision(15) << CC[k].first << " " << CC[k].second << endl;
            }
        }        
    }


}