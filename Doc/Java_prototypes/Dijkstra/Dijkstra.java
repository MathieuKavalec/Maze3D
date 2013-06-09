import java.util.List;
import java.util.ListIterator;
import java.util.PriorityQueue;
import java.util.Random;

public class Dijkstra {

	public static void fiboHeapDijkstra(DijkstraGraph graph, int source, int[] distance) {

		FibonacciHeap<Integer> fHeap = new FibonacciHeap<Integer>(); // monceau de fibonacci

		for (int i = 0; i < graph.size(); i++) { // remplir toutes les valeurs de distance avec une grande valeur
			distance[i] = Integer.MAX_VALUE;
		}
		distance[source] = 0; // mettre la distance de la source a 0
		
		for (Integer i = 0; i < graph.size(); ++i) // remplir le monceau avec les valeurs du graph
			fHeap.insert(i, distance[i]);
		
		Integer v; // noeud adjacent a u
		Integer w; // point de l'arrete u-v
		Integer u; // noeud minimal
		List<Edge> adjU; // liste des noeuds adjacents
		
		while(!fHeap.isEmpty())
		{
			u = fHeap.extractMin(); // obtenir le noeud minimal du monceau
			adjU = graph.getNeighbors(u);
	
			for(Edge e : adjU)
			{
				v = e.getDestination();  // v est un noeud adjacent a u
				w = e.getWeight(); // w est le point de l'arrete u-v
				if (distance[u] != Integer.MAX_VALUE && distance[v] > distance[u] + w) // verifier si la distance v est superieure a la distance de u + le poid de l'arrete
				{
					distance[v] = distance[u] + w; // changer la distance v
					fHeap.decreaseKey(v, distance[v]);
				}
			}
		}
	}

	public static void binHeapDijkstra(DijkstraGraph graph, int source, int[] distance) {
		PriorityQueue<BinHeapElem<Integer>> pQueue = new PriorityQueue<BinHeapElem<Integer>>(); 
		
		for (int i = 0; i < graph.size(); i++) {
			distance[i] = Integer.MAX_VALUE;
		}
		distance[source] = 0;
		
		for (Integer i = 0; i < graph.size(); ++i)
			pQueue.offer(new BinHeapElem<Integer>(i,distance[i]));
		
		Integer v; // noeud adjacent a u
		Integer w; // point de l'arrete u-v
		Integer u; // noeud minimal
		List<Edge> adjU;
		
		while(!pQueue.isEmpty()) 
		{
			u = pQueue.remove().elem; // obtenir le noeud minimal du monceau
			adjU = graph.getNeighbors(u);
			
			for(Edge e : adjU)
			{
				v = e.getDestination();  // v est un noeud adjacent a u
				w = e.getWeight(); // w est le point de l'arrete u-v
				if (distance[u] != Integer.MAX_VALUE && distance[v] > distance[u] + w) // verifier si la distance v est superieure a la distance de u + le poid de l'arrete
				{
					pQueue.remove(new BinHeapElem<Integer>(v,distance[v]));
					distance[v] = distance[u] + w; // changer la distance v
					pQueue.offer(new BinHeapElem<Integer>(v,distance[v]));
				}
			}
		}
	}

	public static void printPath(DijkstraGraph graph, int source, int destination) {
		FibonacciHeap<Integer> fHeap = new FibonacciHeap<Integer>(); // monceau de fibonacci
		Integer[] distance = new Integer[graph.size()];
		String[] chemin = new String[graph.size()];
		for (int i = 0; i < graph.size(); ++i)
			chemin[i] = source + " ";
		
		
		for (int i = 0; i < graph.size(); i++) {
			distance[i] = Integer.MAX_VALUE;
		}
		distance[source] = 0;
		
		for (Integer i = 0; i < graph.size(); ++i)
			fHeap.insert(i, distance[i]);
		
		Integer v; // noeud adjacent a u
		Integer w; // point de l'arrete u-v
		Integer u; // noeud minimal
		Edge e; // arretes de u
		
		fini : while(!fHeap.isEmpty())
		{
			u = fHeap.extractMin(); // obtenir le noeud minimal du monceau
	
			ListIterator<Edge> it = graph.getNeighbors(u).listIterator();
			while (it.hasNext()) // iterer a travers les noeuds adjacents a u
			{
				e = it.next(); // arrete de u
				v = e.getDestination();  // v est un noeud adjacent a u
				w = e.getWeight(); // w est le point de l'arrete u-v
				if (distance[u] != Integer.MAX_VALUE && distance[v] > distance[u] + w) // verifier si la distance v est superieure a la distance de u + le poid de l'arrete
				{
					distance[v] = distance[u] + w; // changer la distance v
					fHeap.decreaseKey(v, distance[v]);
					chemin[v] = chemin[u] + "-(" + e.getWeight() + ")-> " + v + " ";
					if (v == destination) // arreter de boucler
						break fini;
				}
			}
		}
		System.out.println(chemin[destination]);
	}
	
	public static void main(String[] args) {
		
		Random random = new Random();
		int size = 4000;
		DijkstraGraph graph = new Graph(size);
		 
		for (int i = 0; i < size; i++) { 
			for (int j = 0; j < size; j++) { 
				if (i != j) { 
					double rdm = random.nextDouble();
					if (rdm > 0.99)
						graph.addEdge(i,j,random.nextInt(100)); 
				}
			} 
		}
		int[] dist = new int[graph.size()];
	
		long start = System.currentTimeMillis();
		fiboHeapDijkstra(graph, 0, dist);
		long end = System.currentTimeMillis();

		System.out.println("Time for FIBO: "+ (end-start) + "ms");

		System.out.println();
		
		dist = new int[graph.size()];

		start = System.currentTimeMillis();
		binHeapDijkstra(graph, 0, dist);
		end = System.currentTimeMillis();

		System.out.println("Time for BIN: "+ (end-start) + "ms"); 
		
		Graph g = new Graph(5);
		g.addEdge(0,1,3); g.addEdge(0,2,4); g.addEdge(0,3,2); g.addEdge(1,4,3); g.addEdge(2,4,2); g.addEdge(3,4,1); g.addEdge(4, 1, 4);
		System.out.println();
		g.printGraph();
		System.out.println("voisins de 1 : " + g.getNeighbors(1));
		dist = new int[g.size()];
		System.out.print("fibo : ");
		fiboHeapDijkstra(g, 0, dist);
		for (int i = 0; i < g.size(); ++i)
			System.out.print(0+"->"+i+" d=" + dist[i] + " | ");
		System.out.println();
		System.out.print("bin  : ");
		binHeapDijkstra(g, 0, dist);
		for (int i = 0; i < g.size(); ++i)
			System.out.print(0+"->"+i+" d=" + dist[i] + " | ");
		System.out.println();
		System.out.print("printpath de 0 a 4 : ");
		printPath(g,0,4);
	}
}
