#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>


using namespace std;
typedef long long ll;

ll N, M = 0;

int main(){

    cin >> N >> M;

    vector<pair<ll, ll> > T;
    //入力
    ll A, B = 0;
    for(int i = 0; i < N; i++){
        cin >> A >> B;
        T.push_back(make_pair(A, B));
    }

    ll yen = 0;

    sort(T.begin(), T.end());

    ll num = 0;
    ll i = 0;
    for(;;){
        if(num == M){
            break;
        }

        if(T[i].second == 0){
            i++;
        }else{
            yen += T[i].first;
            T[i].second --;
            num++;
        }
    }

    cout << yen << endl;
    
}