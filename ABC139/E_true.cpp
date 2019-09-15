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
#include <queue>

using namespace std;
typedef long long ll;
//試合した人だけが次の日試合できる可能性があるのでO(N^2)のはず...
//前日試合していない人が次の日試合できるなら前日試合しているはずという矛盾
int main(){

    ll N;
    cin >> N;

    vector<vector<ll > > vec(N, vector<ll >(N - 1, 0));

    //どこまで確認したか
    vector<ll > p(N, 0);  
    //p更新用のキュー  
    queue<ll > p_que;
    //前日試合をした人を格納するキュー 初日は全員該当
    queue<ll > yesterday_que;
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < N - 1; j++){
            ll in;
            cin >> in;
            vec[i][j] = in - 1;
        }
        yesterday_que.push(i);
    }

    ll ans = 0;
    
    //最大回数試合をさせて残っている選手がいれば-1する方針
    ll day = 0;
    bool fin_flg = false;
    while(day <= N * (N - 1) / 2){
        //cout << "day" << day + 1 << " size" << yesterday_que.size() << endl;
        ll loop = yesterday_que.size();
        fin_flg = false;

        for(ll j = 0; j < loop; j++){
            
            ll i = yesterday_que.front();
            yesterday_que.pop();

            //cout << i << endl;
            //cout << "1" << endl;
            if(p[i] >= N - 1) continue;
            if(vec[i][p[i]] == -1) continue;

            if(i == vec[vec[i][p[i]]][p[vec[i][p[i]]]] ){
                
                //更新準備
                p_que.push(i);
                p_que.push(vec[i][p[i]]);
                //前日試合したリストに追加
                yesterday_que.push(i);
                yesterday_que.push(vec[i][p[i]]);

                //不要なので-1格納
                vec[vec[i][p[i]]][p[vec[i][p[i]]]] = -1;
                vec[i][p[i]] = -1;
                
                //試合したのでフラグ更新
                fin_flg = true;
            }

            ans++;

        }
        
        //各人どこまで試合をしたか更新
        while(!p_que.empty()){
            p[p_que.front()]++;
            p_que.pop();
        }


        //確認
        
        /* 
        for(ll j = 0; j < N; j++){
            for(ll k = 0; k < N - 1; k++){
                cout << vec[j][k] << " ";
            }
            cout << p[j] <<  endl;
        }
        */
        
        //連日試合が開催されていなければ終わり
        if(fin_flg == false){
            break;
        }
        
        day++;

    }

    //全試合終わっているか?

    for(ll k = 0; k < N; k++){
       if(p[k] != N - 1){
           cout << "-1" << endl;
           return 0;
       }
    }
    cout << day << endl;

}