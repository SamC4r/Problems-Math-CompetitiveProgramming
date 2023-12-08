#include<bits/stdc++.h>
using namespace std;

int nodes = 4;



int main(){

	/*
	
	Connections:
	
	Undiretected version:

	1 <--> 2
	1 <--> 3
	2 <--> 1 
	2 <--> 3
	3 <--> 1
	3 <--> 2
	4 to nothing. The graph in my notes

	Directed version:
	1 --> 2
	1 --> 3
	3 --> 2
	2 --> 4

	*/



// -----------------ADJACENCY LIST-----------------------------------------------------------------------------


	// Adjacency list for a digraph: Direceted graph
	vector<vector<int>> adjacency_list(nodes);

	adjacency_list[1].push_back(2);
	adjacency_list[1].push_back(3);

	adjacency_list[2].push_back(4);

	adjacency_list[3].push_back(2);
	
	//IF you have an undirected graph remember to add the other way paths.


	// IF you have weights do it as follows;
	//It contains a pair (b,w) every time that there is a connection to b with weight w.


	vector<vector<pair<int,int>>> undirected_version(nodes);

	undirected_version[1].push_back({2,3});//with weight 3


// ------------------------------MATRIX----------------------------------------------------------------



	//MATRIX

	vector<vector<int>> matrix_list(nodes,vector<int>(nodes));

	//matrix[i][j] --> i connected to j with weight being the number at such position

	matrix_list[1][2] = 1;
	matrix_list[1][3] = 3;// and so ON;



	//Backlash: Always at least a O(n^2) complexity and most of them are zeros.


// ------------------------------EDGE LIST----------------------------------------------------------



	//Edge list represenation. The way that I like the most!!

	// vector that contains a pair (a,b) which means that a is connected to b.

	vector<pair<int,int>> edge;


	//Undiretected version of the graph:
	//
	edge.push_back({1,2});
	edge.push_back({1,3});
	edge.push_back({3,2});
	edge.push_back({2,4});






}