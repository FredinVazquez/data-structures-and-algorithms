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

struct edge {
    int u, v;
    double weight;
};

const double INF=1e18;
int n , m;

void BellmanFord(int s, vector<double> & dist, vector<int> & pred, 
    vector<int> &cycle, const vector<edge> &edges) {
        
    dist.assign(n, INF);
    pred.assign(n, -1);
    int node_x;

    dist[s] = 0;
    for (int i = 0; i < n; i++) {
        node_x = -1; 
        for (int j = 0; j < m; j++) {
            auto edge = edges[j];
            auto u = edge.u, v = edge.v;
            auto weight = edge.weight;
            
            if (dist[v] < INF) {
                if (dist[u] + weight < dist[v]) {
                    dist[v] = max(-INF, dist[u] + weight);
                    pred[v] = u;
                    node_x = v;
                }
            }
        }
    }
    
    if (node_x == -1) {
        cycle = {};
    } else {
        int w = node_x;
        for (int i = 0; i < n; i++)
            w = pred[w];
        
        cycle.push_back(w);
        auto par = pred[w];
        while (par != w) {
            cycle.push_back(par);
            par = pred[par];
        }
        cycle.push_back(w);
        reverse(cycle.begin(), cycle.end());
    }
}

void solve() {
    cin >> n >> m;
    vector<edge> edges;
    for (int i = 0; i < m; i++) {
        int u, v; double w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int source = 2;
    vector<double> distance;
    vector<int> predecessor;
    vector<int> cycle;
    // BellmanFord(source, distance, predecessor, cycle, edges);

    // if (cycle.empty()) {
    //     cout << "No negative cycle found" << endl;
    // } else {
    //     cout << "Negative cycle: ";
    //     for (auto p : cycle) cout << p << ' ';
    //     cout << endl;
    // }
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