
public class Node {
	
	//Filho do lado esquerdo do nodo
	protected Node left;
	
	//Filho do lado direito do nodo
	protected Node right;
	
	//Valor contido no nodo atual
	protected String value;
	
	//Construtor para inicializar os filhos vazios
	public Node(String value) {
		this.left = null;
		this.right = null;
		this.value = value;
	}
}
