
public class BinaryTree {

	protected Node root;

	//Construtor para inicializar a raiz vazia
	public BinaryTree() {
		this.root = null;
	}

	//Preordem(r,e,d)
	public void printPreOrder(Node node) {
		
		//Se n�o tiver nada no nodo, ele somente retorna, n�o faz nada
		if (node == null) {
			return;
		}
		System.out.print(node.value + " ");
		printPreOrder(node.left);
		printPreOrder(node.right);
	}
	
	//Emordem(e,r,d)
	public void printInOrder(Node node) {
		
		//Se n�o tiver nada no nodo, ele somente retorna, n�o faz nada
		if (node == null) {
			return;
		}
		printInOrder(node.left);
		System.out.print(node.value + " ");
		printInOrder(node.right);
	}
	
	//Posordem(e,d,r)
	public void printPostOrder(Node node) {
		
		//Se n�o tiver nada no nodo, ele somente retorna, n�o faz nada
		if (node == null) {
			return;
		}
		printPostOrder(node.left);
		printPostOrder(node.right);
		System.out.print(node.value + " ");
	}
}
