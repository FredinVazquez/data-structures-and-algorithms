```c++
#include <bits/stdc++.h>
using namespace std;


// Dinic Algorithm Implementation C++

// Arista que va unir u (vértice anterior) - v (vértice siguiente)
struct edge{
    int u,v,time;
    edge(int v, int u, int time) : v(v), u(u), time(time){}
};
// Arista con las características de flujo
struct flowEdge{
    int v,u;
    long long capacity, flow=0;
    flowEdge(int v, int u, long long capacity) : v(v), u(u), capacity(capacity) {}
};


// Dinic
struct Dinic{

  // Atributos para BFS:
  long long flow_inf = 1e18;
  vector<flowEdge> edges; // vector de Aristas
  vector<vector<int>> listAdj; // Lista de adyacencia de 2 dimensiones
  
  int n,m=0,s,t;
  vector<int> level,ptr;
  queue<int> q;
  
  Dinic(int n, int s, int t) : n(n), s(s), t(t) {
    listAdj.resize(n);
    level.resize(n);
    ptr.resize(n);
  }
  
  
  // Función para añadir arista:
  void addEdge(int v, int u, long long capacity){
    edges.emplace_back(v,u,capacity); // Es usada emplace_back para ir agregando tal que se hace realloc
    edges.emplace_back(u,v,0);        // De regreso - para bfs supongo
     
    listAdj[v].push_back(m);
    listAdj[u].push_back(m+1);
    
    m+=2;
  }
  
  // Construcción de level graph usando el graph residual con bfs
  bool bfs(){
    
    while(!q.empty()){
        int v = q.front();
        q.pop();
        
        // Ahora se revisa los vecinos del vértice 
        for(int id : listAdj[v]){
            // Se verifica la capacidad de flujo de la arista
            if(edges[id].capacity - edges[id].flow <=0) continue;
            
            //Se verifica si ya fue explorado o no
            if(level[edges[id].u] != -1) continue;
            
            level[edges[id].u] = level[v]+1;
            q.push(edges[id].u);
        }
    }
    return level[t] != -1;  // Si ya fue explorado o hasta el último vértice, o sea el target.
  }
  
  
  // Implementacion de DFS
  long long dfs(int v, long long pushed){
        if(pushed == 0) return 0;
        
        if(v==t) return pushed;
        
        for (int& cid = ptr[v]; cid < (int)listAdj[v].size(); cid++) {
            int id = listAdj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].capacity - edges[id].flow <= 0)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].capacity - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
   }
  
    // 
    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }               
        }
        return f;
    }
};

```