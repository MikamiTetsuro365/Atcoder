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
//奇数　Nは全てに辺が伸びる
//      
int main(){
    ll N;
    cin >> N;
    
    ll sum = 0;

    vector<pair <ll, ll > > ans;
    for(ll i = N; i > 0; i--){
        //ll conf = 0;
        for(ll j = i - 1; j > 0; j--){
            
            if(N % 2 == 1){
                //奇数のとき、Nに関しては全ての辺に辺を結ぶ
                if(i == N){
                    ans.push_back(make_pair(i, j));
                    continue;
                }
                //
                if((i + j) % N  != 0){
                    ans.push_back(make_pair(i, j));
                }
            }else{
                if((i + j) % N  != 1){
                    ans.push_back(make_pair(i, j));
                }                
            }



            
            //conf += j;
        }
        //cout << conf << endl;
    }

    cout << ans.size() << endl;
    for(ll i = 0; i < ans.size(); i++){
        cout << ans[i].first << " " << ans[i].second << endl;
    }

} 