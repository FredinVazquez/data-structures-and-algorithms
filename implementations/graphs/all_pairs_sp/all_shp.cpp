#include <bits/stdc++.h>
using namespace std; 

#define endl                        '\n'
#define fastIO()                    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FO(i, b)                    for (int i = 0; i < (b); i++)
#define FOR(i, a, b)                for (int i = (a); i < (b); i++)
#define rFOR(i, a, b)               for (int i = (a); i > (b); i--)
#define TR(v, arr)                  for (auto& (v) : (arr))
#define debug(x)                    cout << #x << " = "; _debug(x); cout << endl;
#define pb                          push_back
#define mp                          make_pair
#define F                           first
#define S                           second
#define all(x)                      x.begin(), x.end() 
#define sz(x)                       (int) x.size()
#define LB(arr, x)                  lower_bound(all(arr), x)-(arr).begin()
#define UB(arr, x)                  upper_bound(all(arr), x)-(arr).begin()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void setIO(){
    string file = __FILE__;
    file = string(file.begin(), file.end()-3);
    string in_file = file+"in";
    string out_file = file+"out";

    FILE *exist_in_file;
    exist_in_file = freopen(in_file.c_str(), "r", stdin);
    if(!exist_in_file){
        exist_in_file = freopen(in_file.c_str(), "w", stdout);
        fclose(exist_in_file);
    }

    freopen(in_file.c_str(), "r", stdin);
    freopen(out_file.c_str(), "w", stdout);
}

template <typename T>
void _debug(T& x){
    cout << x;
}

template <typename T1, typename T2>
void _debug(pair<T1, T2>& pair){
    cout << "{"; _debug(pair.F); cout << ","; _debug(pair.S); cout << "}";  
}

template <typename T>
void _debug(vector<T>& vec){
    int n = sz(vec);
    if(n == 0){cout << "[ ]"; return;}
    cout << "[";
    FO(i, n-1){
        _debug(vec[i]); cout << " ";
    }
    _debug(vec[n-1]); cout << "]";
}

void _debug(vector<string>& vec){
    int n = sz(vec);
    cout << endl;
    FO(i, n){
        cout << vec[i] << endl;
    }
}

template <typename T>
void _debug(vector<vector<T>>& A){
    int n = sz(A);
    cout << endl;
    FO(i, n){
        _debug(A[i]); cout << endl;
    }
}

template <typename T>
void print(T& x){
    cout << x;
    return;
}

template <typename T>
void print(vector<T>& vec, int a=0, int b=-1){
    if(b == -1){b = sz(vec);}
    if(b == 0){return;}
    FOR(i, a, b-1){
        print(vec[i]); cout << " ";
    }
    print(vec[b-1]); cout << endl;
    return; 
}

const int N = 1e5;

void solve(){
    int n; cin >> n;
    vector<vector<int>> adj(n+1, vector<int>(n+1, INF));
    int m; cin >> m;
    int u, v, w;
    FO(i, m){
        cin >> u >> v >> w;
        adj[u][v] = w;
    }

    vector<vector<int>> d(n+1, vector<int>(n+1, 0));
    vector<vector<int>> p(n+1, vector<int>(n+1, 0));
    FOR(i, 1, n+1){
        FOR(j, 1, n+1){
            d[i][j] = adj[i][j];
            p[i][j] = i;
        }
    }
    
    FOR(k, 1, n+1){
        FOR(i, 1, n+1){
            FOR(j, 1, n+1){
                if(d[i][k]+d[k][j] < d[i][j]){
                    d[i][j] = d[i][k]+d[k][j];
                    p[i][j] = p[k][j]; 
                }
            }
        }
    }
    
    // find negative cycle
    bool neg_cycle = false;
    FOR(i, 1, n+1){
        if (d[i][i] < 0){
            neg_cycle = true;
            break;
        }
    }
    cout << "has negative cycle: " << neg_cycle << endl; 
    
    // // find diameter
    // int diameter = 0;
    // FOR(i, 1, n+1){
    //     FOR(j, 1, n+1){
    //         if(d[i][j] != INF){
    //             diameter = max(diameter, d[i][j]);
    //         }
    //     }
    // }
    // cout << "graph diameter: " << diameter << endl;

    // recover path
    int start = 2;
    int target = 4;
    int curr = target;
    vector<int> path;
    while (curr != start){
        path.pb(curr);
        curr = p[start][curr];
    }
    path.pb(start);
    reverse(all(path));
    cout << "path from " << start << " to " << target << ": ";
    print(path);
}

int main()
{
    fastIO();
    if(getenv("LOCAL")){setIO();}
    int T=1;
    FO(tc, T){
        // cout << "Case #" << tc+1 << ":";
        solve();
    }	
    return 0;
}