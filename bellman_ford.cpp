#include <bits/stdc++.h>
using namespace std;
#define FOR(k,m,n) for(int(k)=(m);(k)<(n);(k)++)
#define REP(k,n) FOR((k),0,(n))
#define ALL(a) begin(a),end(a)
const int INF=numeric_limits<int>::infinity();
typedef vector<int> VI;
typedef struct{int from;int to;int cost;}Edge;
typedef vector<Edge> Graph;

void bellman_ford(Graph &g,int &s,VI &d)
{
  int E=g.size();
  while(true)
	{
	  bool update=false;
	  REP(i,E) 
		{
		  Edge e = g[i];
		  if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost)
			{
			  cout << e.from << " " << e.to << endl;
			  d[e.to] = d[e.from] + e.cost;
			  update = true;
			}
		}
	  if(!update) break;
	}
}

int main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int V,E;
  cin>>V>>E;
  Graph graph(E);
  REP(i,E) 
	{
	  int from,to,cost;
	  cin>>from>>to>>cost;
	  graph[i].from=from;
	  graph[i].to=to;
	  graph[i].cost=cost;
	}
  int s;
  cin >> s;
  VI d(V, INF);
  d[s]=0;
  bellman_ford(graph,s,d);
  REP(i,V)
	cout<<d[i]<<endl;
  return EXIT_SUCCESS;
}


