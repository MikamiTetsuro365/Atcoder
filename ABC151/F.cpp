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

ll N;
double x[1919],y[1919];

double getR(double X, double Y){
    double ret = 0;
    
    for(int i = 0; i < N; i++){
        double tmpX = (X - x[i]) * (X - x[i]);
        double tmpY = (Y - y[i]) * (Y - y[i]);
        ret = max(ret, tmpX + tmpY);
    }
    
    return ret;
}

double searchY(double X){
    double lo = 0,hi = 10000;
    
    for(int it = 0;it < 500; it++){
        double a = (2 * lo + hi) / 3;
        double b = (lo + 2 * hi) / 3;
        
        double ra = getR(X,a);
        double rb = getR(X,b);
        
        if(ra < rb){
            hi = b;
        }else{
            lo = a;
        } 
    }
    
    return getR(X,lo);
}

double searchX(){
    double lo = 0,hi = 10000;
    
    for(int it = 0;it < 500; it++){
        double a = (2 * lo + hi) / 3;
        double b = (lo + 2 * hi) / 3;
        
        double ra = searchY(a);
        double rb = searchY(b);
        
        if(ra < rb){
            hi = b;
        }else{
            lo = a;
        } 
    }
    
    return searchY(lo);
}

int main(){

    cin >> N;
    
    for(ll i = 0; i < N; i++){
        double tx, ty; cin >> tx >> ty;
        x[i] = tx;
        y[i] = ty;

    }
    
    cout << fixed << setprecision(18) << sqrt(searchX())<< endl;
    
}