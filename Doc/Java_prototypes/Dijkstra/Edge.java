public class Edge {
	private Integer source;
	private Integer destination;
	private Integer weight;

	public Edge(Integer source, Integer destination, Integer weight) {
		super();
		this.source = source;
		this.destination = destination;
		this.weight = weight;
	}

	public String toString() {
		return "(" + source + ", " + destination + ", " + weight + ")";
	}

	public Integer getSource() {
		return source;
	}

	public Integer getDestination() {
		return destination;
	}

	public Integer getWeight() {
		return weight;
	}

	// override equals method
	public Boolean equals(Edge e) {
			return source == e.source && destination == e.destination && weight == e.weight; // verifies if both edges are equal
	}

	// override hashcode method
	public int hashCode() {
		return destination.hashCode(); // the hashcode is determined by the destination
	}

}
