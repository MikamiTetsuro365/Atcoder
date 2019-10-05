#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

int main(){

    ll N, M;
    cin >> N >> M;

    vector<ll > day(N + 1, -1);

    for(ll i = 0; i < M; i++){
        ll d, p;
        cin >> d >> p;
        day[d] = p;
    }

    ll value = 0;
    //vector<vector<ll > > dp(N + 1, vector<ll >(3, value));
    //0日目から初めて　メニュー0 = 前日は何も食べていない
    vector<vector<vector<ll > > > dp(N + 1, vector<vector<ll > >(4, vector<ll >(4, 0)));
    //経過日数、前々日、前日
    dp[0][0][0] = 1;

    for(ll today = 0; today < N; today++){
        //前々日
        for(ll day2ago = 0; day2ago < 4; day2ago++){
            //前日
            for(ll day1ago = 0; day1ago < 4; day1ago++){
                for(ll menu = 1; menu <= 3; menu++){
                    //翌日
                    ll tommorow = today + 1;
                    //翌日のメニューが決まっていたら
                    if(day[tommorow] != -1 && menu != day[tommorow]) continue;
                    //前々日と前日で同じメニューが続いていたら
                    if(day2ago == day1ago && day1ago == menu) continue;
                    //翌日を更新
                    //前日のメニューを前々日へ
                    dp[tommorow][day1ago][menu] = (dp[tommorow][day1ago][menu] + dp[today][day2ago][day1ago]) % 10000;
                }
            }
        }
    }  

    //合計取る
    ll sum = 0;
    for(ll i = 0; i < 4; i++){
        for(ll j = 0; j < 4; j++){
            sum = (sum + dp[N][i][j]) % 10000 ;
        }        
    }

    cout << sum << endl;

}