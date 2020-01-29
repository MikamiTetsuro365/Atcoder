#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<double, double > pi;  
typedef pair<pair<double, double >, double > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

ll N, M;

vector<pii > A;
vector<pi > B;

bool check(double p){

    for(ll i = 0; i < B.size(); i++){
        for(ll j = 0; j < A.size(); j++){
            double d = sqrt(pow(B[i].first-A[j].first.first, 2) + pow(B[i].second-A[j].first.second, 2));
            //cout << d << " " << p + A[j].second << endl;
            if(d <= p + A[j].second){
                return false;
            }
        }
    }

    for(ll i = 0; i < B.size(); i++){
        for(ll j = 0; j < B.size(); j++){
            if(i == j) continue;
            double d = sqrt(pow(B[i].first-B[j].first, 2) + pow(B[i].second-B[j].second, 2));
            //cout << d << " " << p + p << endl;
            if(d <= p + p){
                return false;
            }
        }        
    }

    return true;
}

int main() {

    cin >> N >> M;

    double mn = 1145141919;
    for(ll i = 0; i < N; i++){
        double x, y, r;
        cin >> x >> y >> r;
        A.push_back(make_pair(make_pair(x, y), r));
        mn = min(r, mn);
    }
    for(ll i = 0; i < M; i++){
        double x, y;
        cin >> x >> y;
        B.push_back(make_pair(x, y));
    }

    double ok = 0, ng = 1145141919;
    for(int i = 0; i < 5000; i++){
        double p = (ok + ng) * 0.5;
        //cout << p << endl;
        if(check(p))ok = p;
        else ng = p;
    }
    
    cout << fixed << setprecision(15) << min(mn, ok) << endl;

}