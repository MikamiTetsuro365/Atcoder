# Atcoder
Atcoder関連はここにまとめます(精進)

# テンプレ
**bitsフォルダをコピペして以下を貼り付け**
```cpp
#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

int main(){

}
```

# 多次元ベクター(下は二次元)
```cpp
ll n_rows = 5;
ll n_cols = 5;
ll value = 0;
vector<vector<ll > > vec(n_rows, vector<ll >(n_cols, value));
```

# map全列挙
```cpp

map<ll, ll> mp;
//ここになにか入力
auto begin = mp.begin(), end = mp.end();
for (auto iter = begin; iter != end; iter++) {
    cout << iter -> first << " " <<  iter -> second << endl;
}

```

# Priority queue(優先度付きQueue)
```cpp
priority_queue<ll > que;
//昇順にしたい時
//priority_queue<ll ,vector<ll >, greater<ll > > que;

que.push(1);
que.push(2);
que.push(3);

while(!que.empty()){
    cout << que.top() << endl;
    que.pop()
}
```

# 最大公倍数
**N個の最大公倍数=最大公倍数の最大公倍数の最大公倍数(ry**
```cpp
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
```

```cpp
ll gcd(ll a, ll b){
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}
```
**どちゃくそくそバカでかい数字同士のGCDを取れと言われたら？多言語(Pythonとか)を使うか,考察がんばるか...[No442和と積](https://yukicoder.me/problems/no/442)**


# 最小公倍数

# 立っているビットをカウント
**GCCの__builtin関数[ここ](https://qnighy.hatenablog.com/entry/20090921/1253551047)**
```cpp
ll n;
cin >> n;
ll bit_count = __builtin_popcount(n);
```
# ビット全探査
**全探査が楽(ほんまか?)**
```cpp
ll N; cin >> N;
for(ll i = 0; i <= (1<<N); i++){
    //ビットの位置を数える
    for(ll j = 0; j < N; j++){
        //右シフトして最下位で立っているかどうか判定
        if((i >> j) & 1 == 1){
            //jがビットが立っている位置
        }
    }
}
```

# 約数
**約数を返します**
```cpp
vector<ll > divisor(ll n) {
  vector< ll > div;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      div.push_back(i);
      //重複許すマジ
      if(i * i != n) div.push_back(n / i);
    }
  }
  sort(div.begin(), div.end());
  return (div);
}
```


# 木やグラフ
**辺に重みも設定できます**
```cpp
//to (行き先), weight の順で設定
vector<vector<pair<ll, ll > > > G;
vector<ll > ans;
int main(){
    ll N;
    cin >> N;
    
    //初期化
    G.assign(N, vector<pair<ll, ll > >());
    ans.assign(N, 0);
 
    //グラフ入力
    for(ll i = 0; i < N-1; i++){
        ll u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        //双方向に貼りましょうね
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }
}
```

# dfs
**グラフや木を作って実行してくれい.[ABC070_D](https://atcoder.jp/contests/abc070/tasks/abc070_d) [ABC_067_D](https://atcoder.jp/contests/abc067/tasks/arc078_b)[ABC054_C](https://atcoder.jp/contests/abc054/tasks/abc054_c)←忘れた頃にもう一度解け**
```cpp
#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  

void dfs(vector<vector<pi > > G, vector<bool > seen, ll idx, ll from = -1){
    seen[idx] = true;

    for(ll i = 0; i < G[idx].size(); i++){
        //次の行き先は？
        ll to = G[idx][i].first;
        //探査済み
        if(seen[to] == true){
            continue;
        }
 
        dfs(G, seen ,to , idx);
    }
}

int main(){
    ll N, M;
    cin >> N >> M;
    //初期化
    vector<vector<pi > > G;
    G.assign(N, vector<pi >());
    vector<bool > seen(N, false);
 
    //グラフ入力
    for(ll i = 0; i < M; i++){
        ll u, v, w;
        w = 0;
        cin >> u >> v;
        u--;
        v--;
        //双方向に貼りましょうね
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }

    dfs(G ,seen ,0);
}
```

# BFS
**辺の重みが1の場合のみお手軽に最短経路を求めることができる**

```cpp
#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

ll ans = INFINITY;
ll N;

vector<ll > bfs(vector<vector<ll > > G, ll start){
    start;
    //距離を初期化
    vector<ll > dist(G.size(), -1);
    queue<ll > que;

    //始点start 初期化
    dist[start] = 0;
    que.push(start);

    while(!que.empty()){
        ll from = que.front();
        que.pop();

        for(ll i = 0; i < G[from].size(); i++){
            ll to = G[from][i];
            //すでに探査済み
            if(dist[to] != -1) continue;

            dist[to] = dist[from] + 1;
            que.push(to);
        }
    }

    return dist;

}
int main(){


    cin >> N >> M;

    vector<vector<ll > > G;
    G.assign(N, vector<ll >());

    for(ll i = 0; i < M; i++){
        //入力
    }

    vector<ll > dist = bfs(G, 0);
    cout << dist[N] << endl;
}
```

# 橋
**とてもわかり易い説明.特に6段目がよさみあふれる[ここ1](http://kagamiz.hatenablog.com/entry/2013/10/05/005213) [ここ２](https://ei1333.github.io/luzhiled/snippets/graph/lowlink.html) [ここ3](https://www.slideshare.net/chokudai/arc045)**

# 累積和
**基本的なイメージはここよぉ[paiza](https://paiza.hatenablog.com/entry/2015/01/21/%E3%80%90%E7%B4%AF%E7%A9%8D%E5%92%8C%E3%80%81%E3%81%97%E3%82%83%E3%81%8F%E3%81%A8%E3%82%8A%E6%B3%95%E3%80%91%E5%88%9D%E7%B4%9A%E8%80%85%E3%81%A7%E3%82%82%E8%A7%A3%E3%82%8B%E3%82%A2%E3%83%AB%E3%82%B4)**

## まとめる(圧縮)処理
**たまに数列とかを同じ者同士でまとめる必要があるので**

```cpp
for(ll i = 0; i < s.size();){
    ll j = i;
    //一緒の間ループを回し続けて，切れ目を探す
    while(j < s.size() && s[j] == s[i]){
        ++j;
    }
    vec.push_back(j - i);
    //次の始点へすっ飛ばす
    i = j;
}
```

## 累積和のメイン処理
**合計を順番にとっていく,leftとrightを操作しながらある区間の合計を取っていく**
```cpp
//先頭は必ず0からスタート
vector<ll > sum(vec.size() + 1, 0);
for(ll i = 0; i < vec.size(); i++){
    //1つ前との合計を取っていく
    sum[i + 1] = sum[i] + vec[i];
}

//累積和メイン
ll ans = 0;
for(ll left = 0; left < sum.size(); left += 2){
    //K * 2 + 1の部分を合計を取りたい任意の区間の要素数に合わせる
    ll right = left + K * 2 + 1;
    //バグらせ防止, rightが伸びきったらもう動かさない終端でleftが上がってくるのを待つ
    if(right >= sum.size()){
        right = sum.size() - 1;
    }
    //sum[right] - sum[left]である区間の合計がわかります.
    ans = max(ans, sum[right] - sum[left]);
}
```

# 尺取り法
**ニョキニョキ**
```cpp

```

# 気持ちの良いDP
**VectorでDPテーブルを作ってしまうと膨大なメモリ空間にアクセスする必要があるのでTLE必須→Mapで頑張った[ARC073_B](https://atcoder.jp/contests/abc060/tasks/arc073_b)**
**要素が2つあった[ABC054_D](https://atcoder.jp/contests/abc054/submissions/7929944)**

# 整数と小数の判定
**クソどうでも良いけど...ceil(切り上げ)とfloor(切り捨て)で同じだと整数(少数ではない)**
```cpp
double ans;
cin >> ans;
//cout << ans << endl;
if(ceil(ans) != floor(ans)){
    cout << "No" << endl;
}else{
    cout << "Yes" << endl;
}
```

# next_permutation
**順列を生成する便利な奴[アルゴリズム](https://scrapbox.io/ganariya/%E8%BE%9E%E6%9B%B8%E5%BC%8F%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0%E3%81%AB%E3%81%A4%E3%81%84%E3%81%A6)**
**この考え方が役に立った問題[AGC022_A](https://atcoder.jp/contests/agc022/tasks/agc022_a)**
```cpp
ll N;
cin >> N;
//数列入力
vector<ll > A(N, 0);
for(ll i = 0; i < N; i++){
    cin >> A[i];  
}

do{
    for(ll i = 0; i < A.size(); i++){
        cout << A[i];
    }
    cout << endl;
}while(next_permutation(A.begin(), A.end()));

```

# エラトステネスの篩
**高速に素数を求める[ABC084-D](https://atcoder.jp/contests/abc084/submissions/7647316)**
```cpp
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
ll N;

vector<bool > prime;

//primeListには素数は入ってません
void isPrime(ll N){
    prime[0] = false;
    prime[1] = false;

    //ルートN以下まで繰り返す
    for(ll i = 2; i < ceil(sqrt(N)) ; i++){
        //素数になりえないとき
        //cout << i << endl;
        if(!prime[i]) continue;
        
        //Nまでのi(素数)の倍数を斑入り落とす
        for(ll j = i * i; j <= N; j += i){
            prime[j] = false;
        }    
    }
}

int main(){

    cin >> N;
    prime.assign(N + 1, true);
    isPrime(N);

    for(ll i = 0; i < prime.size(); i++){
        cout << prime[i] << endl;
    }
} 
```

# 素因数分解
**素因数分解の気持ち[ABC052-C](https://atcoder.jp/contests/abc052/submissions/7931860)**
```cpp
#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

map<ll, ll> primeFactor(ll num){

    //素因数と指数部の並び
    map<ll, ll > PF;

    ll i = 2;

    while(num >= i * i){
        if(num % i == 0){
            PF[i]++;
            num /= i;
        }else{
            i++;
        }
    }
    //1は素因数分解できない
    if(num != 1){
        PF[num]++;
    }
    
    return PF;
}

int main(){

    ll num;
    cin >> num;

    map<ll, ll> PF = primeFactor(num);

    auto begin = PF.begin(), end = PF.end();
    for (auto iter = begin; iter != end; iter++) {
        //ここで出力
    }
}
```

# 高速な累乗計算
**早い.べき数を半分に分けてまとめていく気持ち**
```cpp
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll mod = 1e9 + 7;

ll fast_pow(ll a, ll n){
    if(n == 0) return 1;
    //べき数nが奇数, aを前にだして, a^n-1の気持ちに
    if(n % 2 == 1){
        return a * fast_pow(a, n - 1) % mod;
    }else{
        //べき数nが偶数のとき，べき数を半分にして, aをまとめる. べき数を半分にする
        return fast_pow(a * a % mod, n / 2) % mod;
    }
}

int main(){
    ll A, N;
    cin >> A >> N;
    fast_pow(A, N)
    cout << fast_pow(A, N) << endl;
} 
```

# ダイクストラ法
**ある頂点から他の頂点までの最短経路を求める．ただし辺の長さ(重み)は正に限る．計算量はヒープを使ってO((V+E)logV)**
```cpp
#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;
ll N, M, L;
ll ans = 0;

vector<vector<pair<ll, ll> > > G;
vector<ll > prever;
 
vector<ll > dijkstra(ll start){
    //準備
    vector<bool > used(N, false);
    vector<ll > dist(N, INFINITY);
    prever.assign(N, -1);
    priority_queue<pair<ll, ll > , vector<pair<ll, ll > >, greater<pair<ll, ll > > > que;
    //初期化
    que.push(make_pair(0, start));
 
    //cout << que.top().first << endl;
 
    while(!que.empty()){
        //距離
        ll d = 0;
        //次の頂点
        ll t_v = 0;
        d = que.top().first;
        t_v = que.top().second;
        //topから削除
        que.pop();
        //探査済みなら処理しない
        if(used[t_v] == true) continue;
        //探査済みにする
        used[t_v] = true;
        //キューの上には既に最小距離が来ているので
        dist[t_v] = d;
        
        //次探査する頂点はt_vなのでt_vから更に次にの頂点の繋がりをキューにいれる
        for(ll i = 0; i < G[t_v].size(); i++){
            //もし探査済みの頂点で，そこまでの累積距離より今更新しようとしている距離が
            //大きいときは更新しない
            ll to = G[t_v][i].first;
            ll cost = d+G[t_v][i].second;
            if(dist[to] <= cost) continue;
            prever[to] = t_v;
            //累積距離と次の頂点
            que.push(make_pair(cost, to));
            //仮dist
            dist[to] = cost;
        }
        //cout << endl;
    }   
    
    return dist;
 
}

vector<ll > get_path(ll t){
    vector<ll > path;
    for(; t != -1; t = prever[t]){
        //cout << prever[t] << endl;
        path.push_back(t);
    }
    //reverse(path.begin(), path.end());
    return path;
}
 
 
int main() {
    //頂点数
    cin >> N >> M >> L;

    G.assign(N, vector<pair<ll, ll > >());
 
    for(ll i = 0; i < M; i++){   
        ll u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        //双方向に貼りましょうね
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));    
    }

    dijkstra(0);
    //頂点0からget_path(ある頂点)までの経路
    vector<ll > ans = get_path(4);
    for(ll i=0; i < ans.size();i++){
        cout << ans[i]+1 << endl;
    }
}
```

# ベルマンフォワード法
**負の辺があってもよい．負の閉路が検出できる．**
```cpp
#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 114514191945;
ll N, M; 
vector<vector<pi > > G;
vector<ll > dist;

//ベルマンフォード
bool bellman(ll start){
    //準備
    //vector<ll > dist(N, INF);
    //初期化
    dist[start] = 0;
    
    for(ll i = 0; i < N; i++){
        for(ll from = 0; from < N; from++){
            for(ll j = 0; j < G[from].size(); j++){
                ll to = G[from][j].first;
                ll cost = G[from][j].second;
                if(dist[from] != INF && dist[to] > dist[from] + cost){
                    dist[to] = dist[from] + cost;
                    if(i == N-1){
                        //負の経路が会って頂点の数以上にループが回ってしまう
                        return false;
                    }
                }
            }       
        }
    }

    //確認
    /*
    for(ll i = 0; i < N; i++){
        if(dist[i] == INF){
            cout << "INF" << endl;
        }else{
            cout << dist[i] << endl;
        }
    }
    */

   return true;
}

int main() {
    //探査開始点
    ll S;
    cin >> N >> M >> S;

    G.assign(N, vector<pi >());
    dist.assign(N, INF);

    for(ll i = 0; i < M; i++){   
        ll u, v, w;
        cin >> u >> v >> w;
        //u--;
        //v--;
        //双方向に貼りましょうね
        G[u].push_back(make_pair(v, w));
        //G[v].push_back(make_pair(u, w)); 
    }
    
    if(bellman(S) == false){
        cout << "NEGATIVE CYCLE" << endl;
    }
}
```

# ワーシャルフロイド法
**あらかじめ全ての頂点間の最短距離を求めておく 計算量O(V^3) 負の辺があってもOK**

**[ABC143_E](https://atcoder.jp/contests/abc143/submissions/8052276)**

**[ABC061_D](https://atcoder.jp/contests/abc061/submissions/8058997)遠回りになるような経路を選んでいく.普段のminをmaxに，INFはMIN_INFに**

**下のコードは制限が厳しいとき用，多重辺，自己ループ，距離が超巨大になる，負の辺がある，負の辺の閉路がある**

```cpp
#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = INFINITY;
ll N, M; 

vector<vector<ll > > G;
vector<vector<ll > > path;

bool warshall(){
    //中継点に関して
    for(ll reley = 0; reley < N; reley++){
        for(ll from = 0; from < N; from++){
            for(ll to = 0; to < N; to++){
                //中継した方がコストがかからないか否か
                //小さい順からコストが自明に決まっていく
                if(G[from][to] > G[from][reley] + G[reley][to]){
                    //負の辺対策 INFINITY＋INFINITYはマイナスになるので
                    //たまに最短距離を更新してしまう. 
                    if(G[from][reley] != INF && G[reley][to] != INF){
                        G[from][to] = G[from][reley] + G[reley][to];
                        //fromからtoへ到達する最短経路上のfromの1つ前の位置
                        path[from][to] = path[from][reley];
                    }
                }
            }

            //負の閉路がある時
            if(G[from][from] < 0){
                cout << "NEGATIVE CYCLE" << endl;
                return false;
            }
        }
    }

    return true;
}

vector<ll > get_path(ll start, ll end){
    vector<ll > ans;
    //endに向けて進んでいく中継地があれば拾っていく
    for(ll i = start; i != end; i = path[i][end]){
        cout << i << endl;
        ans.push_back(i);
    }
     ans.push_back(end);
    return ans;
}

int main(){

    //頂点数と辺の数
    cin >> N >> M;

    G.assign(N, vector<ll >());
    path.assign(N, vector<ll >());
    
    //初期化
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < N; j++){
            if(i == j){
                //自分から自分へ
                G[i].push_back(0);
            }else{
                G[i].push_back(INF);
            }
            path[i].push_back(j);
        }       
    }
    //cout << G.size() << " " << G[0].size() << endl;
    //辺入力
    for(ll i = 0; i < M; i++){   
        ll u, v, w;
        cin >> u >> v >> w;
        //適宜揃える
        //u--;
        //v--;
        //有向か無向かでコメントアウト　多重辺も防止
        G[u][v] = min(G[u][v], w);
        //G[v][u] = min(G[v][u], w);
    }

    //実行
    if(warshall() == false){
        return 0;
    }

    //確認
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < N; j++){
            if(G[i][j] == INF){ 
                cout <<  ( j ? " " : "" ) << "INF"; 
            }else{
                cout <<  ( j ? " " : "" ) <<  G[i][j]; 
            }
            
        }       
        cout << endl;
    }

    get_path(2, 0);
    get_path(0, 3);
}
```

**制限が厳しくないとき用**
```cpp
vector<vector<ll > > warshall(vector<vector<ll > > GRAPH){
    //中継点に関して
    for(ll reley = 0; reley < N; reley++){
        for(ll from = 0; from < N; from++){
            for(ll to = 0; to < N; to++){
                //中継した方がコストがかからないか否か
                //小さい順からコストが自明に決まっていく
                GRAPH[from][to] = min(GRAPH[from][to], GRAPH[from][reley] + GRAPH[reley][to]);
            }
        }
    }

    return GRAPH;
}
```

# 二分探査
**完全にメモ**

## lower_bound()
**指定した値__以上__の要素の内，最左の位置を返す**

## upper_bound()
**指定した値__超過__の要素の内，最左の位置を返す**

**先頭イテレータや末尾イテレータを引くことで任意の区間の個数を求められる**

```cpp
#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;
//本番は問題に応じてバグらせないよう番兵を入れる
int main(){
    ll N, K; cin >> N >> K;
    vector<ll > vec(N, 0);
    for(ll i = 0; i < N; i++){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    //インデックス
    //以上(の最大)
    ll ijo = lower_bound(vec.begin(), vec.end(), K) - vec.begin();
    //未満(の最大)
    ll miman = ijo - 1;
    //超過(の最小))
    ll choka = upper_bound(vec.begin(), vec.end(), K) - vec.begin();
    //以下（の最大）
    ll ika = choka - 1;
}
```


# あばばば
**概要**
```cpp

```


