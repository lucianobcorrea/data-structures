import java.util.Scanner;

public class Lista {

	private Data cabeca;

	public Lista() {
		this.cabeca = null;
	}

	public Data getCabeca() {
		return cabeca;
	}

	public void setCabeca(Data cabeca) {
		this.cabeca = cabeca;
	}

	public void lerData(Data data) {
		Scanner sc = new Scanner(System.in);
		Integer dia, mes, ano;
		System.out.print("Dia: ");
		data.setDia(dia = sc.nextInt());
		System.out.print("Mês: ");
		data.setMes(mes = sc.nextInt());
		System.out.print("Ano: ");
		data.setAno(ano = sc.nextInt());
	}

	public void inserirInicio(Data data, Lista lista) {
		data.setProximo(lista.getCabeca());
		lista.setCabeca(data);
	}

	public void imprimirLista() {
		for (Data paux = cabeca; paux != null; paux = paux.getProximo()) {
			System.out.printf("Data: %d/%d/%d", paux.getDia(), paux.getMes(), paux.getAno());
			System.out.println();
		}
	}

	public int tamanhoLista() {
		Data paux = cabeca;
		Integer s = 0;
		while(paux != null) {
			paux = paux.getProximo();
			s++;
		}
		return s;
	}

	public Data buscarLista(Integer dia) {
		for (Data paux = cabeca; paux != null; paux = paux.getProximo()) {
			if (dia == paux.getDia()) {
				return paux;
			}
		}
		return null;
	}

	public void removerData(Integer dia) {
		Data pontAux = cabeca;
		Data anterior = null;		
		if(cabeca.getDia() == dia) {
			cabeca = cabeca.getProximo();
			System.out.printf("Data Removida: %d/%d/%d\n", pontAux.getDia(), pontAux.getMes(), pontAux.getAno());
		}else {
			while(pontAux != null && pontAux.getDia() != dia) {
				anterior = pontAux;
				pontAux = pontAux.getProximo();
			}
			if(pontAux != null) {
				anterior.setProximo(pontAux.getProximo());
				System.out.printf("Data Removida: %d/%d/%d\n", pontAux.getDia(), pontAux.getMes(), pontAux.getAno());
			}
		}
	}
}
