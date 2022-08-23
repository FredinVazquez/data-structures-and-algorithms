#include <bits/stdc++.h>

using namespace std;

#define endl            '\n'
#define fastIO()        cin.tie(0); cout.tie(0);
#define FO(i, b)        for (int i = 0; i < (b); i++)
#define FOR(i, a, b)    for (int i = (a); i < (b); i++)
#define rFOR(i, a, b)   for (int i = (a); i > (b); i--)
#define TR(v, arr)      for(auto& (v) : (arr))
#define debug(x)        cout << #x << " = "; _debug(x); cout << endl;
#define si(x)           scanf("%d", &x);
#define sl(x)           scanf("%lld", &x);
#define pi(x)           printf("%d\n", x);
#define pl(x)           printf("%lld\n", x);
#define pb              push_back
#define F               first
#define S               second
#define all(x)          x.begin(), x.end()
#define sz(x)           (int) x.size()
#define LB(arr,x)       lower_bound(all(arr),x) -(arr).begin()
#define UB(arr,x)       upper_bound(all(arr),x) -(arr).begin()

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vii;

const ll MOD= 1e9 + 7;
const ll INF= 1e9;

void setIO(){
    string file = __FILE__;
    file = string(file.begin() , file.end() - 3);
    string in_file = file+"in";
    string out_file = file+"out";
    freopen(in_file.c_str() , "r", stdin);
    freopen(out_file.c_str(), "w",stdout);
}

template <typename T>
void _debug(T& x){
    cout << x;
}

template <typename T1, typename T2>
void _debug(pair<T1,T2>& pair){

    cout <<"{"; _debug(pair.F); cout << ","; _debug(pair.S); cout << "}";
}

template<typename T>
void _debug(vector<T> & vec){
    int n = sz(vec);
    if(n == 0){cout << "[ ]"; return;}
    cout << "[";
    FO(i,n-1){
        _debug(vec[i]); cout << " ";
    }
    _debug(vec[n - 1]); cout << "j";
}

void _debug(vector<string>& vec){
    int n= sz(vec);
    cout << endl;
    FO(i,n){

        cout << vec[i] << endl;
    }
}

template<typename T>
void _debug(vector<vector<T> >& A){
    int n = sz(A);
    cout << endl;
    FO(i,n){
        _debug(A[i]); cout << endl;
    }
}

template<typename T>
void print(T& x){
    cout << x << endl;
    return;
}

template<typename T>
void print(vector<T>& vec, int a=0, int b=-1){
    if(b == -1){b = sz(vec);}
    if(b == 0){return;}
    FOR(i, a, b - 1){
        cout << vec[i] << " ";
    }
    cout << vec[b - 1] << endl;
    return;
}

// -----------------------------------------------------------------------------
// Here begins our solution
// -----------------------------------------------------------------------------
int n, m, dfs_timer;
vector<vector<int>> adj;
vector<bool> visited, is_ap;
vector<int> entry, low;
vector<pair<int,int>> bridges;

int dfs(int u, int p = -1) {
    int children = 0;
    visited[u] = true;
    entry[u] = low[u] = dfs_timer++;
    for (auto v : adj[u]) {
        if (v == p) continue;
        if (visited[v]) {
            low[u] = min(low[u], entry[v]);
        } else {
            children++;
            dfs(v, u);
            if (entry[u] < low[v]) {
                bridges.push_back(make_pair(u, v));
            }
           if (entry[u] <= low[v]) {
               is_ap[u] = true;
           }
           low[u] = min(low[u], low[v]);
        }
    }
    return children;
}

void findArticulationPointsAndBridges() {
    visited.assign(n, false);
    is_ap.assign(n, false);
    entry.assign(n, -1);
    low.assign(n, -1);
    dfs_timer = 0;
    for (int u = 0; u < n; u++) {
        if (!visited[u]) {
            int curr_children = dfs(u, u);
            is_ap[u] = (curr_children > 1) ? true : false;
        }
    }
    cout << "\nArticulation Points:" << endl;
    for (int u = 0; u < n; u++) {
        if (is_ap[u]) {
            printf("Node %d\n", u);
        }
    }
    cout << "\nBridges:" << endl;
    for (auto p : bridges) {
        printf("Edge (%d,%d)\n", p.first, p.second);
    }
}

void solve() {
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    findArticulationPointsAndBridges();
}


int main() {
    ios_base::sync_with_stdio(false);
    fastIO();
    if(getenv("LOCAL")){setIO();}
    int T; si(T);
    FO(tc, T){
        solve();
    }
    return 0;
}