// graph algorithms implementation
//1. dfs using recursion
//2. bfs using queue
//3. cycle detection algorithm
//4. path search using dfs
//5. connected component

#include<iostream>
#include<list>
#include<stack>
#include<set>


using namespace std;
class graph{
	int nV;
	int nE;
	list <int > *adjList;
	public:
		graph(int v, int e);
		void addEdge(int , int);
		void dfs(); 
		void dfs_search(int, bool *);
		void bfs(int v);
		bool isCycle(int v);
		bool cycle(int , bool *, bool * );
		bool path_search(int , int , bool *, stack <int > *);
		void getPath(int , int );
		list<list <int>> scc(int v);
};

list<list <int>> graph::scc(int v){
	list< list <int>> components;
	set visited;
	
	for(int i=0; i<nV; i++){
		
	}
	
}
graph:: graph(int v, int e){
	nV=v;
	nE=e;
	adjList =new list<int >[nV];
}

void graph:: addEdge(int u, int v){
	adjList[u].push_back(v);
}

void graph:: dfs(){// dfs implementation using recursion
	bool visited[nV];	
	for(int i=0; i<nV; i++){
		visited[i]=false;
	}
	for(int i=0; i<nV; i++){
		if(visited[i]==false)
		dfs_search(i, visited);
	}
}

void graph ::dfs_search(int v, bool *visited){
	visited[v]=true;
	cout<<v<<" ";
	list <int > :: iterator it;
	for(it=adjList[v].begin(); it!=adjList[v].end(); it++){
		if(visited[*it]==false)
			dfs_search(*it, visited);
	}
}
///////////////////////////////////////////////////////////////////////
void graph ::bfs(int v){
	list <int >:: iterator it,it1;
	list <int > q;
	bool visited[nV];
	for(int i=0;i<nV; i++){
		visited[i]=false;
	}
	q.push_back(v);	
	visited[v]=true;
	while(!q.empty()){				
		v=q.front();
		cout<<v<<" ";	
		q.pop_front();	
		for(it=adjList[v].begin();it!=adjList[v].end();it++){
			if(visited[*it]==false){
				q.push_back(*it);
				visited[*it]=true;
			}				
		}		
	}
}
//cycle detection algorithm 
bool graph :: isCycle(int v){
	 bool * visited=new bool[nV];
	 bool *cycleStck=new bool [nV];
	 for(int i=0; i<nV; i++){
		 visited[i]=false;
		 cycleStck[i]=false;
	 }
	 for(int i=0; i<nV; i++){
		 if(cycle(i, visited, cycleStck)){  return true; }
	 }
	return false;
}

bool graph:: cycle(int v, bool visited[], bool * cycleStck){
	if(visited[v]==false){
				
		visited[v]=true;
		cycleStck[v]=true;
		list<int> :: iterator it;
		
		for(it=adjList[v].begin(); it!=adjList[v].end(); it++){			 
			if(!visited[*it] && cycle(*it, visited, cycleStck) ){
				return true;
			}
			else if( cycleStck[*it]==true){				
				return true;				
			}
		}
				
	}	
	cycleStck[v]=false;
	return false;
}


// path finding algorithm
void graph:: getPath(int u, int v){
	bool visited[nV];	
	stack <int > s;
	for(int i=0; i<nV; i++){
		visited[i]=false;
	}		
	s.push(u);
	
	if(path_search(u, v, visited, &s)){
		while(!s.empty()){			
			cout<<s.top()<<" ";
			s.pop();
		}
	}		
}

bool graph ::path_search(int u, int v, bool *visited, stack <int > *s){
	if(u==v){return 1;}	
	visited[u]=true;
	
	list <int > :: iterator it;
	for(it=adjList[u].begin(); it!=adjList[u].end(); it++){
		if(visited[*it]==false){
			s->push(*it);
			if(path_search(*it, v, visited, s)) return true;			
		}
	}
	s->pop();
	return false;
}


int main(){
	int v, e, x, y;
	cout<<"Enter v e\n";
	cin>>v>>e;
	graph G(v,e);
	
	cout<<"Enter Edges v u\n";
	while(e--){
		cin>>x>>y;
		G.addEdge(x,y);		
	}
	G.getPath(1,3);
	return 0;
}
