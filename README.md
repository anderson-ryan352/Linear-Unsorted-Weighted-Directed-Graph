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
