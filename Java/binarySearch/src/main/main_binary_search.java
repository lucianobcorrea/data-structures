package main;

public class main_binary_search {

	public static void main(String[] args) {
		int temp;
		int[] nros_primos = { 2, 3, 5, 6, 11, 13, 17, 19, 23, 29, 31, 37 };
		int[] array_des = {10, 0, 2, 40, 20, 15, 11, 31, 42};	

		System.out.println("Array desordenado");
		for(int i = 0; i < array_des.length - 1; i++){
			System.out.print(array_des[i] + ", ");
		}
		System.out.println();

		for(int i = 1; i < array_des.length; i++){
			for(int j = 0; j < i; j++){
				if(array_des[j] > array_des[i]){
				temp = array_des[j];
				array_des[j] = array_des[i];
				array_des[i] = temp;
				}
			}
		}
		System.out.println("Array ordenado");
		for(int i = 0; i < array_des.length - 1; i++){
			System.out.print(array_des[i] + ", ");
		}
		System.out.println();

		for(int i = 1; i < array_des.length; i++){
			for(int j = 0; j < i; j++){
				if(array_des[i] > array_des[j]){
				temp = array_des[i];
				array_des[i] = array_des[j];
				array_des[j] = temp;
				}
			}
		}

		System.out.println("Array decrescente");
		for(int i = 0; i < array_des.length - 1; i++){
			System.out.print(array_des[i] + ", ");
		}
		System.out.println();
		System.out.println();
		
		int resultado_recursiva = recursive_binary_search(nros_primos, 38, 0, nros_primos.length - 1);
		int resultado_iterativa = iterative_binary_search(nros_primos, 3);
		System.out.println("### ITERATIVA ###");
		System.out.println();
		if (resultado_iterativa == -1) {
			System.out.println("Numero Invalido");
		} else {
			System.out.println("O Numero esta no Index: " + resultado_iterativa);
		}
		System.out.println();
		System.out.println("### RECURSIVA ###");
		System.out.println();
		if (resultado_recursiva == -1) {
			System.out.println("Numero Invalido");
		} else {
			System.out.println("O Numero esta no Index: " + resultado_recursiva);
		}
	}

	public static int iterative_binary_search(int[] array, int objetivo) {
		int inicio = 0;
		int fim = array.length - 1;
		int meio;
		while (inicio <= fim) {
			meio = (inicio + fim) / 2;
			if (objetivo == array[meio]) {
				return meio;
			}
			if (array[meio] < objetivo) {
				inicio = meio + 1;
			} else {
				fim = meio - 1;
			}

		}
		return -1;
	}

	public static int recursive_binary_search(int[] array, int objetivo, int inicio, int fim) {
		int meio = (inicio + fim) / 2;
		if (inicio <= fim) {
			if (objetivo == array[meio]) {
				return meio;
			}
			if (array[meio] < objetivo) {
				return recursive_binary_search(array, objetivo, inicio = meio + 1, fim);
			} else {
				return recursive_binary_search(array, objetivo, inicio, fim = meio - 1);
			}
		}
		return -1;
		}
	}

