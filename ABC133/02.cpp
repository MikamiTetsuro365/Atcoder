#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>
#include <sstream>
#include <istream>
#include <iomanip>
#include <typeinfo>
#include <stack>

using namespace std;
typedef long long ll;
ll N;

int main(){
    //ll P , Q , R;
    //cin >> P >> Q  >> R;
    ll N, D;
    cin >> N >> D;
    vector<vector<ll >> vec(N, vector<ll >(D, 0));
    //vector<ll > vec(N, )
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < D; j++){
            cin >> vec[i][j];
        }
    } 

    ll cnt = 0;
    for(ll i = 0; i < N - 1; i++){
        for(ll k = i + 1; k < N; k++){
            double ans = 0;
            for(ll j = 0; j < D; j++){
                ans += pow(vec[i][j] - vec[k][j], 2);
            }
            ans = sqrt(ans);
            if(ceil(ans) != floor(ans)){

            }else{
                cnt++;
            }
            //cout << ans << endl;
        }
    }

    cout << cnt << endl;




} 