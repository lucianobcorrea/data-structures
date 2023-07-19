
public class Programa {

	public static void main(String[] args) {
		Lista lista = new Lista();
		for (int i = 0; i < 4; i++) {
			Data data = new Data();
			lista.lerData(data);
			lista.inserirInicio(data, lista);
		}
		System.out.println("\nImprimindo Lista...");
		lista.imprimirLista();
		System.out.println("Tamanho da Lista: " + lista.tamanhoLista());
		Data busca = lista.buscarLista(12);
		if(busca != null) {
			System.out.printf("Data Encontrada: %d/%d/%d\n", busca.getDia(), busca.getMes(), busca.getAno());
		}else {
			System.out.println("Data Não Encontrada!\n");
		}
		lista.removerData(12);
		lista.removerData(13);
		lista.imprimirLista();
		System.out.println("Tamanho da Lista: " + lista.tamanhoLista());
	}
}
