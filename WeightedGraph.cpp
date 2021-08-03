#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

/** Linear Unsorted Weighted Directed Graph Structure
* Ryan Anderson
* 7-15-2021
* 
* This data structure was built unsorted to show the Big O performance of a linear searching algorithm
* 
* Linear searching becomes much slower at a larger graph size.
* Graph consists of Vertices that have weighted, directed edges
*
* A great efficiency improvement that can be made is the sorting of the graph. By sorting vertice and edge vectors alphabetically
* binary search can then be applied to all vertex and edge functions to give an average performance of O(log N)
* This is "Part ONE: Linear" of a comparison on the efficiencies of search/removal/adding algorithms inside a graph structure
*


  Graph:
					Vertex
					  |
				      v
					  A				B		C		D		<- vector<Vertex>
				/			\
		vector<Edge>		vertexName
				|
				v
	Edge->(destination, weight)
			 (A, 0.7)

**/



class Edge {
	private: string destName;
			 double weight;

public: Edge(string destinationVert, double edgeWeight){
			destName = destinationVert;
			weight = edgeWeight;
		}
	string getDestination() {
		  return destName;
	  }
	double getWeight() {
		return weight;
	}
	void setWeight(double edgeWeight) {
		weight = edgeWeight;
	}
};

class Vertex {
	private:
		string originName;
		vector<Edge> edges;
	public: Vertex(string vertName, vector<Edge> edgeList) {
		originName = vertName;
		edges = edgeList;
	}
		  void setOrigin(string origin) {
			  originName = origin;
		  }
		  string getOrigin() {
			  return originName;
		  }
		  void setEdges(vector<Edge> edgeNames) {
			  edges = edgeNames;
		  }
		  vector<Edge> getEdges() {
			  return edges;
		  }
		  
};


//Adds edge to graph
//Linearly searches vertices, edgelist of vertice
//O(a+b) = O(n) where a = number of vertices, b = number of edges in originVertex
vector<Vertex> addEdge(vector<Vertex> graph, string originVert, double edgeWeight, string destVert) {
	Edge * nextEdge = new Edge(destVert, edgeWeight);//creates new edge

	vector<Edge> testEdges; 

	for (int i = 0; i < graph.size(); i++) {//search graph for vertex name, then add edge to the originVerts edge list
		if (originVert == graph[i].getOrigin()) {

			for (int k = 0; k < graph[i].getEdges().size(); k++) {//Checking for existing edge
				if (graph[i].getEdges()[k].getDestination() == destVert){//Edge exists and must be updated
					cout << "Updating Edge: "<< originVert<<"--->"<<destVert<<"\n \n";

					testEdges = graph[i].getEdges();

					testEdges[k].setWeight(edgeWeight);

					graph[i].setEdges(testEdges);

					return graph;
				}
			}
			//If edge does not exist, new edge is created
			testEdges = graph[i].getEdges();

			testEdges.push_back(*nextEdge);

			cout << "New Edge: "<< originVert<<"--->"<<destVert<<"\n \n";

			graph[i].setEdges(testEdges);
			return graph;
		}
	}


	return graph;
}

//Removes edge from graph
//Linearly searches vertices, then edgelist of vertice
//O(a+b) = O(n) where a = number of vertices, b = number of edges in originVert
vector<Vertex> removeEdge(vector<Vertex> graph, string originVert, string destVert) {

	vector<Edge> edgeList;


	for (int j = 0; j < graph.size(); j++) {//Searching graph for originVert
		if(originVert == graph[j].getOrigin())
			for (int i = 0; i < graph[i].getEdges().size(); i++) {//Searching originVert's edges for edge
														  
				if (destVert == graph[j].getEdges()[i].getDestination()) {

					edgeList = graph[j].getEdges();
					edgeList.erase(edgeList.begin() + j);

					graph[j].setEdges(edgeList);
				}
			}
	}
	return graph;
}

//Adds vertext vertName to graph structure. Verifies vertName does not already exist.
//O(n) where n = number of vertices (only if it searches)
vector<Vertex> addVertex(vector<Vertex> graph, string vertName) {
	vector<Edge> edgeList;
	Vertex * nextVert = new Vertex(vertName,edgeList);//Creates new vertex

	for (int i = 0; i < graph.size(); i++) {//Error check for existing vertex with same name
		if (vertName == graph[i].getOrigin()) {
			cout << "Error: Vertex '"<< vertName << "' already exists! \n";
			return graph;
		}
	}

	//Vertex is new, add and return
	graph.push_back(*nextVert);//Vertex Added
	cout << "Added vertext: ";
	cout << graph.back().getOrigin() << "\n";

	return graph;

}


//Removes vertex from graph structure. First removes all edges where vertName is the destination. After all edges have been cleared, vertName node is erased
//Linearly searches through vertices and edges
//O(2a+b) = O(n) where a = number of vertices, b = total number of edges
vector<Vertex> removeVertex(vector<Vertex> graph, string vertName) {
	cout << "Removing Vertex: " << vertName << "\n";
	vector<Edge> edgeList;

	for (int j = 0; j < graph.size(); j++) {//O(a) search through whole graph for edges to deleted vertex
		for (int h = 0; h < graph[j].getEdges().size(); h++) {
			if (vertName == graph[j].getEdges()[h].getDestination()) { //O(b)   origin --> vertName exists, removes edge

				edgeList = graph[j].getEdges();
				cout << "Removing Edge: "<<graph[j].getOrigin()<<"--" <<edgeList[h].getWeight()<<"->"<< edgeList[h].getDestination() << "\n";

				edgeList.erase(edgeList.begin() + h);

				graph[j].setEdges(edgeList);

			}
		}
	}


	for (int i = 0; i < graph.size(); i++) {//O(a)
		if (vertName == graph[i].getOrigin()) {//Origin vertex found, removes from graph
			graph.erase(graph.begin() + i);
		}
	}

	return graph;
}

//Lists all edges for origin node vertName
//Linearly searches vertices for vertName index, outputs all edges where vertName---->X
//O(n+b) = O(n) where n = number of vertices, b = number of edges in vertName
void listEdges(vector<Vertex> graph, string vertName) {
	int p;

	for (int i = 0; i < graph.size(); i++) {//O(n)
		if (vertName == graph[i].getOrigin()) {
				cout << vertName << " Edges: \n";

				for (int h = 0; h < graph[i].getEdges().size(); h++) {//O(b)
					p = h;
					cout << p + 1 << ".   " << vertName << "--" << graph[i].getEdges()[h].getWeight() << "-->" << graph[i].getEdges()[h].getDestination() << "\n";
				}
		}
	}
	cout << "\n";
}

//Lists all vertices in graph structure
//Linear serach through vertices
//O(n) where n = number of vertices
void listVertices(vector<Vertex> graph) {

	cout << "Vertices: ";
	for (int i = 0; i < graph.size(); i++) {//O(n)
		cout << graph[i].getOrigin() << " ";
	}
	cout << "\n \n";
}

int main() {
	
	vector<Vertex> *weightedGraph = new vector<Vertex>;

	/////////////////////////ADDING VERTICES////////////////////////////////////////
	*weightedGraph = addVertex(*weightedGraph, "first");
	cout << "Graph size after add: " << weightedGraph->size() << "\n \n";

	*weightedGraph = addVertex(*weightedGraph, "second");
	cout << "Graph size after add: " << weightedGraph->size() << "\n \n"; 

	*weightedGraph = addVertex(*weightedGraph, "second");//Test for duplicate vertex
	cout << "Graph size after duplicate test: " << weightedGraph->size() << "\n \n";

	*weightedGraph = addVertex(*weightedGraph, "third");
	cout << "Graph size after add: " << weightedGraph->size() << "\n \n";

	*weightedGraph = addVertex(*weightedGraph, "4th");
	cout << "Graph size after add: " << weightedGraph->size() << "\n \n";

	*weightedGraph = addVertex(*weightedGraph, "5th");
	cout << "Graph size after add: " << weightedGraph->size() << "\n \n";

	*weightedGraph = addVertex(*weightedGraph, "6th");
	cout << "Graph size after add: " << weightedGraph->size() << "\n \n";

	*weightedGraph = addVertex(*weightedGraph, "7th");
	cout << "Graph size after add: " << weightedGraph->size() << "\n \n";

	*weightedGraph = addVertex(*weightedGraph, "8th");
	cout << "Graph size after add: " << weightedGraph->size() << "\n \n";

	/////////////////////////Adding Edges///////////////////////////////
	*weightedGraph = addEdge(*weightedGraph, "first", 0.2, "second");
	*weightedGraph = addEdge(*weightedGraph, "second", 5, "first");
	*weightedGraph = addEdge(*weightedGraph, "second", 5, "4th");
	*weightedGraph = addEdge(*weightedGraph, "first", 9, "third");
	*weightedGraph = addEdge(*weightedGraph, "first", 1, "first");
	*weightedGraph = addEdge(*weightedGraph, "first", 1886, "4th");
	////////////////////////////////////////////////////////////////////


	listEdges(*weightedGraph, "first");
	*weightedGraph = addEdge(*weightedGraph, "first", 6, "second");//Test for updating edge
	listEdges(*weightedGraph, "first");


	//////////////Vertice Removal testing/////////
	listVertices(*weightedGraph);
	*weightedGraph = removeVertex(*weightedGraph, "first");
	cout << "Vertices left after remove: " << weightedGraph->size() << "\n \n";
	listVertices(*weightedGraph);
	listEdges(*weightedGraph, "second");

	*weightedGraph = removeVertex(*weightedGraph, "second");
	cout << "Vertices left after remove: " << weightedGraph->size() << "\n \n";

	*weightedGraph = removeVertex(*weightedGraph, "third");
	cout << "Vertices left after remove: " << weightedGraph->size() << "\n \n";

	listVertices(*weightedGraph);

	return 0;
}