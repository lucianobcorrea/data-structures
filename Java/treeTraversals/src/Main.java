
public class Main {

	public static void main(String[] args) {
		
		//Aqui é necessário ir montando a árvore manualmente
		BinaryTree tree = new BinaryTree();
		
		//Nodos da primeira camada da árvore, a raiz e seus filhos
        tree.root = new Node("*"); //Raiz
        tree.root.left = new Node("+");
        tree.root.right = new Node("-");
        
        //Aqui são os filhos de "+"
        tree.root.left.left = new Node("a"); //Folha
        tree.root.left.right = new Node("/");
        
        //Filhos de "-"
        tree.root.right.left = new Node("d"); //Folha
        tree.root.right.right = new Node("*");
        
        //Filhos de "/"
        tree.root.left.right.left = new Node("b"); //Folha
        tree.root.left.right.right = new Node("c"); //Folha
        
        //Filhos de "*"
        tree.root.right.right.left = new Node("e"); //Folha
        tree.root.right.right.right = new Node("f"); //Folha
        
        System.out.println("Pré Ordem: "); 
        //Chamamos a função para imprimir a partir do nodo raiz
        tree.printPreOrder(tree.root);
 
        System.out.println("\nEm Ordem: ");
        //Chamamos a função para imprimir a partir do nodo raiz
        tree.printInOrder(tree.root);
 
        System.out.println("\nPós Ordem: ");
        //Chamamos a função para imprimir a partir do nodo raiz
        tree.printPostOrder(tree.root);
	}

}
