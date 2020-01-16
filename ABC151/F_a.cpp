#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

using namespace std;

double N;
double x[1919],y[1919];
//円の中心付近を出して
//そこから遠い点に向かって徐々に寄せていき本当の中心を割り出す
//山登り法っぽい発想らしい

double dist(double a, double b){
    return a*a + b*b;
}

int main(){

    cin >> N;
    double X = 0;
    double Y = 0;

    for(ll i = 0; i < N; i++){
        cin >> x[i] >> y[i];
        X += x[i];
        Y += y[i];
    }

    //平均を取る．円の中心付近になる
    X /= N;
    Y /= N;

    //ループ回数を増やすと精度が上がる
    double P = 0.1;
    double d = 0;
    for(ll i = 0; i < 30000; i++){
        ll idx = 0;
        d = dist(X-x[0], Y-y[0]);
        for(ll j = 1; j < N; j++){
            //仮の中心から各座標への距離を求める
            double t_d = dist(X-x[j], Y-y[j]);
            if(d < t_d){
                d = t_d;
                idx = j;
            }
        }
        //cout << fixed << setprecision(18) << d << endl;
        //遠いところへ仮の座標を少しだけずらす
        X += (x[idx] - X) * P;
        Y += (y[idx] - Y) * P;
        //cout <<  fixed << setprecision(18) << X << " " << Y << endl;
        //ずらし量を徐々に減らしていく
        //ここでも精度が変わる
        P *= 0.999;
    }

    cout << fixed << setprecision(15) << sqrt(d) << endl;
    
}