#include<iostream>

#include "graph.hpp"

using namespace std;

int main(){
	Graph graph;
	graph.init_graph();
	graph.insert_vertex('a');
	graph.insert_vertex('b');
	graph.insert_vertex('c');
	graph.insert_vertex('d');
	graph.insert_vertex('e');
	graph.insert_vertex('f');

	//graph.insert_edge2(0,1,1);//a-b
	graph.insert_edge2(2,0,5);//c-a
	graph.insert_edge2(1,2,1);//b-c
	//graph.insert_edge2(3,2,5);//d-c
	graph.insert_edge2(4,3,11);//e-d
	graph.insert_edge2(4,5,-3);//e-f
	//graph.insert_edge2(5,1,2);//f-b
	
	graph.print();
	graph.find_connected_component(0);
}