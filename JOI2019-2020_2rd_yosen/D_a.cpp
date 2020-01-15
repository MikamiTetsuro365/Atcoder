#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919;

using namespace std;
//駄目
//テンキー
char mp[6][6] = {
    "#####",
    "#789#",
    "#456#",
    "#123#",
    "#0###",
    "#####"
};

ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {1, 0, -1, 0};

int main(){

    clock_t start = clock();

    int M;
    int R; 
    cin >> M >> R;

    //dp[i][j][k] 
    //あるマスを訪れた時の余りに対する操作の回数は当然ゼロ
    vector<vector<vector<int>>> dp(100019, vector<vector<int>>(10, vector<int>(10, INF)));
    //初期位置に対する余りは当然ゼロ
    dp[0][4][1] = 0;
    //操作回数と現在地(テンキーで)を格納する
    queue<vector<int > > que;
    que.push(vector<int >{0, 4, 1});
    
    //cout << 0 << endl;
    //BFSしながら今まで何回余りの候補が出現したか操作回数とお供に記録
    while(!que.empty()){
        //余りがnのときの現在地
        ll n = que.front()[0];
        ll y = que.front()[1];
        ll x = que.front()[2];
        cout << n << y << x << endl;
        que.pop();
        //余りがRと等しかったら終了
        if(n == R){
            cout << dp[n][y][x] << endl;
            break;
        }
        //次の余りは当然下の式
        ll next_n = (n * 10 + mp[y][x]-'0') % M;
        cout << next_n << endl;
        cout << dp[next_n][y][x]  << endl;
        if(dp[next_n][y][x] == INF){
            dp[next_n][y][x] = dp[n][y][x] + 1;
            vector<int > tmp;
            tmp.push_back(next_n);
            tmp.push_back(y);
            tmp.push_back(x);
            que.push(tmp);
            cout << "Yes" << endl;
        }

        

        for(ll i = 0; i < 4; i++){
            ll nx = x + dx[i];
            ll ny = y + dy[i];
            cout << dp[n][ny][nx] << endl;
            if(mp[ny][nx] == '#') continue;
            if(dp[n][ny][nx] < INF) continue;
            dp[n][ny][nx] = dp[n][y][x] + 1;
            vector<int > tmp;
            tmp.push_back(n);
            tmp.push_back(y);
            tmp.push_back(x);
            que.push(tmp);
            cout << 0 << endl;
        }

        cout << que.size() << endl;

    }


    //答え確認
    /*
    for(int i = 0; i < 16; i++){
        for(int k = 0; k < 10; k++){
            //cout << dp[16][r][k] << endl;
            ans = min(ans, dp[i][r][k]);
        }
    }
    */
    
    clock_t end = clock();

    double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;

    //cout << time << "[ms]" << endl;

}