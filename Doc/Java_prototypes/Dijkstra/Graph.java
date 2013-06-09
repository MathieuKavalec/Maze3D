import java.util.*;

public class Graph implements DijkstraGraph {

	private int size; // number of vertexes in the graph
	private VertexHashTable[] vertex; // array (with a constant size) containing the edges of each vertex of the graph

	/* graph constructor */
	public Graph(int size) {
		this.size = size;
		vertex = new VertexHashTable[size];
		for (int i = 0; i < size; ++i) vertex[i] = new VertexHashTable(this.size);
	}
	
	/* returns the graph size */
	public int size() {
		return this.size;
	}
	
	/* returns all neighbors of a given vertex */
	public List<Edge> getNeighbors(int node) {
		return vertex[node].edges;
	}
	
	/* returns the weight between two vertexes (returns multiple values of weights if the vertexes are linked by multiple edges) */
	public List<Integer> getEdgeWeight(int source, int destination) {
		// this is done in constant time because of the hash table
		return vertex[source].getWeight(destination);
	}

	/* adds an edge to the graph with a specefied source, destination and weight */
	public void addEdge(int s, int d, int w) {	
		if ( s < 0 || s >= size || d < 0 || d >= size ) // the source or destination vertex is out of bounds
			throw new ArrayIndexOutOfBoundsException();
		
		vertex[s].insert(new Edge(s,d,w)); // add the new edge to the source's hash table
	}
	
	/* prints the graph */
	public void printGraph() {
		for (int i = 0; i < size; ++i) {
			System.out.print(i + " -> ");
			for (int j = 0; j < size; ++j) {
				if (vertex[i].array[j] != null && vertex[i].array[j].isActive)
					System.out.print(vertex[i].array[j].element.getDestination()+ "(" + vertex[i].array[j].element.getWeight() + ") ");
			}
			System.out.println();
		}
	}
	
	/* hash table containing all edges associated to a vertex */
	private static class VertexHashTable
	{
		private HashEntry[] array; // The array of elements
		private List<Edge> edges; // sequentially contains the edges that have been inserted in the table		
		private int currentSize; // The number of occupied cells
		
		/* constructor for the hash table
		 * size : desired size of the hash table */
		public VertexHashTable( int size ) {
			allocateArray( nextPrime(size) );
			edges = new ArrayList<Edge>();
			makeEmpty();
		}
		
		/* empty the hash table */
		private void makeEmpty( ) {
			edges.clear();
			for(int i = 0; i < array.length; i++ )
				array[ i ] = null;
		}
		
		/* verifiy if an edge is contained in the table */
		@SuppressWarnings("unused")
		public boolean contains( Edge x ) {
			int currentPos = findPos( x );
			return isActive( currentPos );
		}
		
		/* returns the weight values of the edges in the hash table that have the specified destination */
		public List<Integer> getWeight( Integer destination ) {
			List<Integer> list = new ArrayList<Integer>(); // will contain all values of weights found
			
			int offset = 1;
			
			// find the first possible position for the edge
			int currentPos = destination.hashCode(); 
			currentPos %= array.length;
			if( currentPos < 0 )
				currentPos += array.length;
			
			// go through the hash table to find the edges that have the specified destination
			while( array[currentPos] != null && destination == array[currentPos].element.getDestination() )
			{
				list.add(array[currentPos].element.getWeight());
					
				currentPos += offset; // Compute ith probe
				offset += 2;
				if(currentPos >= array.length)
					currentPos -= array.length;
			}
			
			return list;
		}
		
		/* insert a edge in the table */
		public void insert( Edge x ) {
			// Insert x as active
			int currentPos = findPos(x);
			if( isActive( currentPos ) )
				return;
			
			edges.add(x);
			
			array[ currentPos ] = new HashEntry(x, true);
			
			if( ++currentSize > array.length / 2 ) // rehash if the current size is larger than half the table size
				rehash( );
		}
		
		/* remove an edge from the table */
		@SuppressWarnings("unused")
		private void remove( Edge x ) {
			int currentPos = findPos( x );
			if( isActive( currentPos ) )
			{
				array[ currentPos ].isActive = false;
				edges.remove(x);
			}
		}
		
		/* class that define values that will be contained in the hash table */
		private static class HashEntry {
			public Edge element;// the element
			public boolean isActive;// false if marked deleted
			
			@SuppressWarnings("unused")
			public HashEntry( Edge e )
			{ 
				this(e, true);
			}
			
			public HashEntry( Edge e, boolean i ) 
			{ 
				element = e; isActive = i;
			}
		}
			
		/* allocated memory for the table */
		private void allocateArray( int arraySize ) {
			array = new HashEntry[ arraySize ];
		}
		
		/* verifies if the specified position in the hash table is active or not */
		private boolean isActive( int currentPos ) {
			return array[ currentPos ] != null && array[ currentPos ].isActive;
		}
		
		/* finds a position to insert a new edge using quadratic probing */
		private int findPos( Edge x ) {
			int offset = 1;
			int currentPos = myhash(x);
			
			while( array[currentPos] != null && !array[currentPos].element.equals(x) )
			{
				currentPos += offset; // Compute ith probe
				offset += 2;
				if(currentPos >= array.length)
					currentPos -= array.length;
			}
			return currentPos;
		}
		
		/* resize the table and reinsert the old content */
		private void rehash( ) {
			HashEntry[] oldArray = array; 
			allocateArray( nextPrime( 2 * oldArray.length ) ); // double (at least) the table size
			currentSize = 0;

			for(int i = 0; i < oldArray.length; i++ )
				if( oldArray[i] != null && oldArray[i].isActive )
					insert( oldArray[i].element );
		}
		
		/* finds a hash value for the specified edge */
		private int myhash( Edge x ) {
			int hashVal = x.hashCode();
			
			hashVal %= array.length;
			if( hashVal < 0 )
				hashVal += array.length;

			return hashVal;
		}
		
		/* finds the next prime number after the one specified */
		private static int nextPrime( int n ) {
			if( n % 2 == 0 )
				n++;
			for( ; !isPrime( n ); n += 2 );
			return n;
		}
		
		/* verifies if the specified number is prime or not */
		private static boolean isPrime( int n ) {
			if( n == 2 || n == 3 )
				return true;
			if( n == 1 || n % 2 == 0 )
				return false;
			for(int i = 3; i * i <= n; i += 2 )
				if( n % i == 0 )
					return false;
			return true;
		}
	}
}