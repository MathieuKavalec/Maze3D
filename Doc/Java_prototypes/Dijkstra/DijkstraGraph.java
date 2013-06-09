import java.util.List;

public interface DijkstraGraph {

	public int size(); // The number of vertex in the graph

	public List<Edge> getNeighbors(int node); // Returns a list of all the outgoing edges from node
	
	public void addEdge(int source, int destination, int w); // Add an edge of weight w between source and destination; create the nodes if necessary
	
	void printGraph(); // prints the graph
	public List<Integer> getEdgeWeight(int source, int destination); // returns weight values of the edges that link a source and a destination vertex
}