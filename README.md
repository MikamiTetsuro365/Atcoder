# Atcoder
**Atcoder関連はここにまとめます(精進).**

**以下のライブラリとかは課題が山積みなので自分以外がコピペして使うの非推奨です（糞）**

# 便利リンク
- 精進状況の把握 [https://kenkoooo.com/atcoder/](https://kenkoooo.com/atcoder/)

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

# 8近傍(2個飛ばしで4近傍)
```cpp
ll dy[8] = {1, 1, 1, 0, -1, -1, -1, 0};
ll dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
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
```cpp
ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}
```

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

# 直線交差判定
**役に立つときがくるかは...**
```cpp
bool check(ll x1, ll x2, ll y1, ll y2, ll tx1, ll tx2, ll ty1, ll ty2){
    ll ta = (x1-x2)*(ty1-y1)+(y1-y2)*(x1-tx1);
    ll tb = (x1-x2)*(ty2-y1)+(y1-y2)*(x1-tx2);

    if(ta * tb < 0){
        //交差してる
        return true;
    }else{
        //交差してない
        return false;
    }
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
vector<vector<pi > > G;
vector<bool > seen;
ll N, M;

void dfs(ll idx, ll from = -1){
    seen[idx] = true;

    for(ll i = 0; i < G[idx].size(); i++){
        //次の行き先は？
        ll to = G[idx][i].first;
        //探査済み
        if(seen[to] == true){
            continue;
        }
 
        dfs(to , idx);
    }
}

int main(){
    
    cin >> N >> M;
    //初期化
    G.assign(N, vector<pi >());
    seen.assign(N, false);
 
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

    dfs(0);
}
```

# BFS
**辺の重みが1の場合のみお手軽に最短経路を求めることができる**

**[ここ](https://atcoder.jp/contests/joi2011yo/submissions/8100295)**

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

# Binary Indexed Tree
**区間和やそれに対して任意の値に更新することがO(lngN)で高速に実行できる**

**[ARC043_B](https://atcoder.jp/contests/arc043/submissions/9053199)**

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

ll N;
//Binary Indexed Treeの本体
vector<ll > bit;

//要素の追加
void add(ll a, ll w){
    //区間の長さと現在追加しようとしている値の添字を足すと求めることができる
    //区間の長さは区間番号を２進数にした時,最も下位にある立ったビットで分かる
    //x & -xで最も下位の立ったbitが分かる
    for(ll i = a; i <= N; i += i & -i){
        bit[i] += w;
    }
}

//区間1~aの和の計算
ll intervalSum_1_a(ll a){
    //次にどこを足せばよいかは区間番号からその区間番号の長さを引くと求まる
    ll ret = 0;
    for(ll i = a; i > 0; i -= i & -i){
        ret += bit[i];
    }
    return ret;
}

//区間a~bの和の計算
ll intervalSum_a_b(ll a, ll b){
    return intervalSum_1_a(b) - intervalSum_1_a(a-1);
}

//

//転倒数
ll invNum(vector<ll > num){
    //BITに順番に数を追加していく.
    ll ans = 0;
    for(ll i = 0; i < N; i++){
        //数列の値を追加する前
        //num[i]が追加される前，intervalSum(num[i])でそれより小さい数がいくつ追加されているか調べる.
        //iは何個目にnum[i]がBITに追加されるか
        //つまりi - intervalSum(num[i])で実際の数列で左端から
        //数を転倒していったときi個目にいる自分が自身より大きい数と何回すれ違うかを表す.
        ans += i - intervalSum_1_a(num[i]);
        //最後にnum[i]を区間に足しておく.
        add(num[i], 1);
    }
    return ans;
}

//二分探査 累積和がw以上になる最小のx
/*
ll lowerBound(ll w){
    if(w <= 0) return 0;
    ll x = 0;
    ll k = 1;
    while(k * 2 <= N) k *= 2;
    for(ll i = k; i > 0; i /= 2){
        if(x + i <= N && bit[x + i] < w){
            w -= bit[x + i];
            x += i;
        }
    }
    return x + 1;
}
*/

int main() {    
    ll q;
    cin >> N;
    bit.assign(N+1, 0);

    //立っているビットが常に1つある状態にしたいので添字は1からスタート
    //構築
    for(ll i = 1; i <= N; i++){
        ll t = 0; cin >> t;
        add(i, t);
    }

    /*クエリの処理
    vector<ll > ans;
    for(ll i = 0; i < q; i++){
        ll com; cin >> com;
        ll x, y; cin >> x >> y; 
        if(com == 0){
            add(x, y);
        }else{
            ans.push_back(intervalSum(y) - intervalSum(x-1));
            //cout << intervalSum(y) - intervalSum(x-1) << endl;
        }
    }
    */
    
    //転倒数
    /*
    vector<ll > num(N, 0);
    for(ll i = 0; i < N; i++){
        cin >> num[i];
    }
    cout << invNum(num) << endl;
    */
}

```

# 尺取り法
**例1[ARC098_D](https://atcoder.jp/contests/abc098/submissions/8893613)**

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

int main() {

    ll N; cin >> N;
    vector<ll > A(N, 0);

    for(ll i = 0; i < N; i++){
        cin >> A[i];
    }

    //ll left = 0;
    ll right = 0;
    ll SUM = 0;
    ll XOR = 0;
    ll ans = 0;

    for(ll left = 0; left < N; left++){
        //rightがデータ数の最大を超えず 条件を満たし続ける限り右へ伸ばし続ける
        while(right < N && (SUM + A[right]) == (XOR ^ A[right])){
            SUM += A[right];
            XOR ^= A[right];
            right++;
        }

        //leftからrightまでの条件を満たす個数
        ans += right - left;
        
        //right側が条件を満たさない限りleftを右へ伸ばし続ける
        if(right == left){
            right++;
        }else{
            SUM -= A[left];
            //同じものをXORするともとに戻る
            XOR ^= A[left];
        }
    }

    cout << ans << endl;
}
```

# DP(思い出したときに書き足し)
**VectorでDPテーブルを作ってしまうと膨大なメモリ空間にアクセスする必要があるのでTLE必須→Mapで頑張った[ARC073_B](https://atcoder.jp/contests/abc060/tasks/arc073_b)**

**要素が2つあった[ABC054_D](https://atcoder.jp/contests/abc054/submissions/7929944)**

**挿入DP[CPSCO2019_Session3_F](https://atcoder.jp/contests/cpsco2019-s3/tasks/cpsco2019_s3_f)**

**要復習:木DP[ABC036_D](https://atcoder.jp/contests/abc036/submissions/9845462)**

**取捨選択[forでやる(好み)](https://atcoder.jp/contests/iroha2019-day1/submissions/9885896)[メモ化再帰]()**

**要復習：桁DP(使える数字使えない数字があって数を数える)[ABC007_D](https://atcoder.jp/contests/abc007/submissions/9521364)**



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

**[二分探査＋ダイクストラ](https://atcoder.jp/contests/abc020/submissions/8228615)**

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

## 条件を満たすような最小値を求める
**[ARC075_D](https://atcoder.jp/contests/arc075/tasks/arc075_b) [CPSCO2019_Session4_D](https://atcoder.jp/contests/cpsco2019-s4/tasks/cpsco2019_s4_d)**

**check関数にmidを満たすか確認する処理をかく**
```cpp
    //最小の値なのでngは当てはまらない数, okはずっと条件に当てはまる数
    ll ng = -1; ll ok = 100;
 
    //最小値を求める
    //rightを寄せていく
    while(ng + 1 < ok){
        ll mid = (ng + ok) / 2;
        if(check(mid)){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    //最小値
    cout << ok << endl;
```

## 条件を満たすような最大値を求める
```cpp
    //okはずっと条件が当てはまり続ける条件, ngは条件が当てはまらない条件
    ll ok = 0; ll ng = INF;
 
    //最小値を求める
    //rightを寄せていく
    while(ok + 1 < ng){
        ll mid = (ng + ok) / 2;
        if(check(mid)){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    //最小値
    cout << ok << endl;
```

**実数**

```cpp
    double ok = 0, ng = 1145141919;
    for(int i = 0; i < 5000; i++){
        double p = (ok + ng) * 0.5;
        //cout << p << endl;
        if(check(p))ok = p;
        else ng = p;
    }
```    

# 逆元
**ある数aにある数xをかけると1になる．この時，ある数xを「逆元」と言う．割り算を掛け算で表すために逆元を使う．つまり，割れる数数×割る数の逆元．**

## mod Pにおける逆元

**ある数aにある数xをかけてmod Pを取ると余りが1になる．この時，ある数xを「mod Pにおける逆元」という．**

**式で表すと，ax ≡ 1(mod P)が成立するような数xを選ぶと良い.**

**例えば，a=5 mod P=13の時，x=8のとき余りが1になる．式に書くと5×8=40で40/13は3余り1. これを1つの式にまとめると，5×8=13×3+1で移項して，13×(-3)+5×8=1**

**これはP×k+a×x=1と解くことに他ならない．よって，拡張ユークリッドの互除法[*1](http://arc360.info/algo/privatekey.html)[*2](http://www.tbasic.org/reference/old/ExEuclid.html)[*3](https://qnighy.hatenablog.com/entry/20091230/1262173513)[*4](http://noshi91.hatenablog.com/entry/2019/04/01/184957)[*5](https://gbb60166.jp/cipher/mathemat.htm)[*6](http://proofcafe.org/k27c8/math/math/group/page/identity_inverse/)でkとxを同時に求める．**

**二項係数を効率よく求めたいときにも逆元をうまく使うと良い**

**[いろはちゃんコンテストDay2](https://atcoder.jp/contests/iroha2019-day2/tasks/iroha2019_day2_e)**

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

//階乗
vector<ll>fact;
//逆元
vector<ll>inv;
//逆元階乗
vector<ll>finv;

pii extgcd(ll a, ll b){
    //前提：aとbが互いに素であること．
    pii x(make_pair(1,0), a);
    pii y(make_pair(0,1), b);

    ll div = 0;

    //終了条件:(GCD(a,b), 0)または(0,GCD(a,b))
    while(true){
        if(y.second == 0) return x;
        
        div = x.second / y.second;
        x.second = x.second  - div * y.second;
        x.first.first = x.first.first - div * y.first.first;
        x.first.second = x.first.second - div * y.first.second;

        if(x.second == 0) return y;

        div = y.second / x.second;
        y.second = y.second - div * x.second;
        y.first.first = y.first.first - div * x.first.first;
        y.first.second = y.first.second - div * x.first.second;
    }
}

ll modinv(ll a, ll m = MOD){
    //前提：aとmが互いに素であること．
    pii ans;
    ans = extgcd(a, m);

    ll invNum = 0;
    invNum = ans.first.first;
    invNum %= m;
    //C++特有の剰余がマイナスになってしまう対策
    if(invNum < 0) invNum += m;

    return invNum;
}

ll warizan_mod(ll warareru, ll waru, ll m = MOD){
    //割られる数に逆元をかけるだけ
    warareru %= m;
    return warareru * modinv(waru, m) % m;
}

//階乗と逆元を列挙
void combination(ll num, ll m = MOD){
    fact.assign(num + 1919, 0);
    finv.assign(num + 1919, 0);
    inv.assign(num  + 1919, 0);

    //初期化
    fact[0] = 1; inv[0] = 1;
    //テーブルに列挙
    for(ll i = 1; i < fact.size(); i++){
        fact[i] = fact[i - 1] * i % m;
        inv[i]  = modinv(fact[i]);
    }
}

//階乗 n!
ll factrial(ll n){
    return fact[n];
}

//順列 nPk n!/(n-k)!
ll nPk(ll n, ll k, ll m = MOD){
    if(n < 0 || k < 0 || n < k) return 0;
    return fact[n] * inv[n - k] % m;
}

//二項係数 nCk n!/(k!*(n-k)!)
ll nCk(ll n, ll k, ll m = MOD){
    if(n < 0 || k < 0 || n < k) return 0;
    return fact[n] * (inv[k] * inv[n - k] % m) % m;
}

//重複組み合わせ n+k-1Ck
ll nHk(ll n, ll k, ll m = MOD){
    return nCk(n+k-1, k);
}

int main(){

    pii ans;
    ll a, b; cin >> a >> b ;

    //extgcd確認
    ans = extgcd(a, b);
    cout << ans.first.first << " " << ans.first.second << endl;
    //modinv確認
    for (int i = 1; i < 13; ++i) {
        cout << i << " 's inv: " << modinv(i, 13) << endl;
    }
    //warizan_mod確認
    ll warareru = 12345678900000;
    ll waru = 100000;

    cout << warizan_mod(warareru, waru, MOD) << endl;

    //二項係数確認
    if(a < b) swap(a, b);
    combination(a + b);
    //cout << nCk(X, Y) << endl; 
    cout << nCk(a + b, a) << endl; 

}
```

# 何通り系の早見表
**いつもキレそうになる.**
## べき乗：pow(x, y)
## 階乗：factrial(n)
## 順列：nPk(n, k)
## 組み合わせ：nCk(n, k)
## 重複組み合わせ：nHk(n, k)
**髭男と刑務所をイメージする**

**[参考1(youtube)](https://www.youtube.com/playlist?list=PLd3yb0oVJ_W1wWsVpcQvuHwEea1SeVO_s) [参考2](https://www.risuuhakusyo.com/chouhuku-kumiawase)**


# あばばば
**概要**
```cpp

```


