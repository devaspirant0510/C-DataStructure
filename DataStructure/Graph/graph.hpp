#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>

#define MAX_SIZE 200

using namespace std;

class Graph{
	public:
		void init_graph();
		int insert_edge(int,int,int);
		int insert_edge2(int,int,int);
		int insert_vertex(char);
		int remove_edge(int,int);
		int find_connected_component(int );
		int is_full();
		void DFS(int);
		void BFS(int);
		void print();
	private:
		int vsize=0;
		int adj[MAX_SIZE][MAX_SIZE];
		char vdata[MAX_SIZE];
		int visitied[MAX_SIZE] = {0,};
};

int Graph::find_connected_component(int val ){
	for(int i=0; i<vsize; i++){
		if(visitied[i]==0){
			BFS(i);
			cout << endl;
		}
	}

}

void Graph::DFS(int v){
	visitied[v] = 1;
	cout << vdata[v] << endl;
	for(int i=0; i<vsize; i++){
		// 방문할 그래프에 값이 있고, 방문한적이 없는 경우
		//cout << "[ logging ] : " << "adj[v][i] = "<<adj[v][i]  << "\t visitied[i] = "<<visitied[i] << endl;
		if(adj[v][i]!=0 && visitied[i]==0){
			DFS(i);
		}
	}
}
void Graph::BFS(int val){
	queue<int> qu;
	qu.push(val);
	visitied[val] = 1;
	cout << vdata[val] << endl;
	while(qu.empty()!=1){
		int p = qu.front();
		qu.pop();
		for (int i=0; i<vsize; i++){
			if(adj[p][i]!=0 && visitied[i]==0 ){
				visitied[i] = 1;
				cout << vdata[i] << endl;
				qu.push(i);
			}
		}
	}
}
int Graph::is_full(){
	return vsize==MAX_SIZE;
}

int Graph::insert_vertex(char val){
	if(is_full()){
		return 0;
	}
	vdata[vsize++] = val;
	return 1;
}

int Graph::insert_edge(int width,int height,int val){
	adj[height][width] = val;
}
int Graph::insert_edge2(int width,int height,int val){
	adj[height][width] = adj[width][height] = val;
}

void Graph::init_graph(){
	memset(&adj,0,sizeof(adj));
	memset(&visitied,0,sizeof(visitied));
}

void Graph::print(){
	cout << "  ";
	for (int i=0;i<vsize; i++){
		cout << vdata[i] << " ";
	}
	cout << endl;
	for(int i=0; i<vsize; i++){
		cout << vdata[i] << " ";
		for (int j=0; j<vsize; j++){
			cout << adj[i][j] << " " ;
		}
		cout << endl;
	}
}