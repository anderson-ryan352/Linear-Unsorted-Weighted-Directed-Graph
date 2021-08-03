# Linear-Unsorted-Weighted-Directed-Graph
This is Part One of a multi-section series on the Big O performance of the graph data structure. In this specific case an O(n) approach is taken in all instances and sorting is not applied to any graph structure

At small sizes, this type of searching proves effective, but does not scale at larger sizes as well as a Hash table O(1) or a sorted, Binary Search approach O(log N)

The graph structure is built as follows:

					Vertex
					  |
				    	  v
					  A				B		C		D		<- vector<Vertex>
				/			\
		   	 vector<Edge>		    vertexName
				|
				v
		Edge->(destination, weight)
			     (A, 0.7)




#
Edge: double Weight, string DestinationVertex

Vertex: string originName, vector<Edges> EdgeList
#	
addEdge(vector<Vertex> graph, string originVert, double edgeWeight, string destVert)
	
	-Adds edge to graph; Update edge if it already exists
	
	-Linearly searches vertices, edgelist of vertice
	
	-O(a+b) = O(n) where a = number of vertices, b = number of edges in originVertex
#	
vector<Vertex> removeEdge(vector<Vertex> graph, string originVert, string destVert)
	
	-Removes edge from graph
	
	-Linearly searches vertices, then edgelist of vertice
	
	-O(a+b) = O(n) where a = number of vertices, b = number of edges in originVert
	
#	
vector<Vertex> addVertex(vector<Vertex> graph, string vertName)
	
	-Adds vertext vertName to graph structure. Verifies vertName does not already exist.
	
	-O(n) where n = number of vertices
	
#	
vector<Vertex> removeVertex(vector<Vertex> graph, string vertName)
	
	-Removes vertex from graph structure. First removes all edges where vertName is the destination. After all edges have been cleared, 	vertName node is erased
	
	-Linearly searches through vertices and edges
	
	-O(2a+b) = O(n) where a = number of vertices, b = total number of edges
	
#	
listEdges(vector<Vertex> graph, string vertName)
	
	-Lists all edges for origin node vertName
	
	-Linearly searches vertices for vertName index, outputs all edges where vertName---->X
	
	-O(n+b) = O(n) where n = number of vertices, b = number of edges in vertName
	
	
#
void listVertices(vector<Vertex> graph)
	
	-Lists all vertices in graph structure
	
	-Linear search through vertices
	
	-O(n) where n = number of vertices
#	
main()
	
	-creates graph, adds vertices, edges, and runs function tests
