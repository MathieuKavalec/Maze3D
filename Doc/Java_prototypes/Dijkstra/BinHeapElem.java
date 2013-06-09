public class BinHeapElem<T> implements Comparable<BinHeapElem<T>>
{
	public T elem; // element 
	private Integer distance; // distance de l'element
	
	public BinHeapElem(T e, Integer d) {
		elem = e;
		distance = d;
	}

	@Override
	public int compareTo(BinHeapElem<T> o) { // sucharge de la methode compareTo
		if (distance > o.distance)
			return 1;
		else if (distance == o.distance)
			return 0;
		else
			return -1;
	}
}