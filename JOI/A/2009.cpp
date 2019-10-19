#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

int main(){

    vector<vector<ll > > data(3, vector<ll >(6, 0));
    for(ll i = 0; i < 3; i++){
        cin >> data[i][0] >> data[i][1] >> data[i][2] >> data[i][3]  >> data[i][4]  >> data[i][5];
    }

    for(ll i = 0; i < 3; i++){
        if(data[i][5] - data[i][2] < 0){
            data[i][5] += 60;
            if(data[i][4] == 0){
                data[i][4] = 59;
            }else{
                data[i][4] -= 1;
            }
        }

        ll sec = data[i][5] - data[i][2];

        if(data[i][4] - data[i][1] < 0){
            data[i][4] += 60;
            data[i][3] -= 1;
        }

        ll minu = data[i][4] - data[i][1];
        ll hour = data[i][3] - data[i][0];

        cout << hour << " " <<  minu << " " << sec << endl;

    }

}