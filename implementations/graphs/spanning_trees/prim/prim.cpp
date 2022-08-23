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
//const ll INF= 1e9;

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

int n , m;
const int INF=1000000000;

vector<vector<int>> adj; 

struct Edge {
    int w = INF, to = -1;
};

// For dense graphs O(n ^ 2)
void prim() {
    int total_weight = 0;
    vector<bool> selected(n, false);
    vector<Edge> min_e(n);
    min_e[0].w = 0;

    for (int i=0; i<n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j) {
            if (!selected[j] && (v == -1 || min_e[j].w < min_e[v].w))
                v = j;
        }

        if (min_e[v].w == INF) {
            cout << "No MST!" << endl;
            exit(0);
        }

        selected[v] = true;
        total_weight += min_e[v].w;
        if (min_e[v].to != -1)
            cout << v << " " << min_e[v].to << endl;

        for (int to = 0; to < n; to++) {
            if (adj[v][to] < min_e[to].w){
                min_e[to] = {adj[v][to], v};
            }
        }
    }
    cout << total_weight << endl;
}

//For sparse grpahs O(mlogn)
// struct Edge_sparse {
//     int w = INF, to = -1;
//     bool operator<(Edge_sparse const& other) const {
//         return make_pair(w, to) < make_pair(other.w, other.to);
//     }
// };

// //Use this adj for sparse graphs
// vector<vector<Edge_sparse>> adj;

// void prim_sparse() {
//     int total_weight = 0;
//     vector<Edge_sparse> min_e(n);
//     min_e[0].w = 0;
//     set<Edge_sparse> q;
//     q.insert({0, 0});
//     vector<bool> selected(n, false);
//     for (int i = 0; i < n; ++i) {
//         if (q.empty()) {
//             cout << "No MST!" << endl;
//             exit(0);
//         }

//         int v = q.begin()->to;
//         selected[v] = true;
//         total_weight += q.begin()->w;
//         q.erase(q.begin());

//         if (min_e[v].to != -1)
//             cout << v << " " << min_e[v].to << endl;

//         for (Edge_sparse e : adj[v]) {
//             if (!selected[e.to] && e.w < min_e[e.to].w) {
//                 q.erase({min_e[e.to].w, e.to});
//                 min_e[e.to] = {e.w, v};
//                 q.insert({e.w, e.to});
//             }
//         }
//     }

//     cout << total_weight << endl;
// }


void solve() {

    int e;
    cin >> n >> e;

    adj.resize(n, vector<int>(n , INF));

    //For sparse graph
    //adj.resize(n)

    //dense graph
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w;
    }

    //For a sparse graph
    // for (int i = 0; i < m; i++) {
    //     int u, v, w;
    //     cin >> u >> v >> w;
    //     adj[u].push_back({w, v});
    //     adj[v].push_back({w, u});
    // }

    //prim();
    //prim_sparse()

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