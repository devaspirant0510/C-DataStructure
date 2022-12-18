#include <iostream>
#include <cstdlib>
#include <cstring>

#define MAX_SIZE 200
using namespace std;

class Graph{
	public:
		void init_graph();
		int insert_graph(int,int,int);
		int remove_grpah(int,int);
		void print();
	private:
		int vsize=0;
		int adj[MAX_SIZE][MAX_SIZE];
		char vdata[MAX_SIZE];
};

void Graph::init_graph(){
	memset(&adj,0,sizeof(adj));
}

void Graph::print(){
	for(int i=0; i<vsize; i++){
		for (int j=0; j<vsize; j++){
			cout << adj[i][j] << " " ;
		}
		cout << endl;
	}
}