#include <iostream>
#define MAX 10000

using namespace std;

// Essa é potencia longa, onde eu uso arrays para fazer calculos de potenciação com números grande


// multiplica vai ser a função responsavel por multiplicar o array pelo balor da base
int multiplica (int b, int vetor[], int tamanho_vetor) { 

	int resto = 0, prod;

	// esse loop multiplica digito por digito do vetor pela base
	for (int i = 0; i <= tamanho_vetor; i++){
		prod = vetor[i]*b + resto; 
		vetor[i] = prod % 10;
		resto = prod / 10;
	}
	
	// e esse loop aumenta o "tamanho" do vetor para acomodar mais digitos 
	while (resto){
		tamanho_vetor++;
		vetor[tamanho_vetor] = resto % 10;
		resto = resto / 10;
	}

	return tamanho_vetor;
}

// essa função só faz printar os dígitos do vetor
void printvetor (int vetor[], int tamanho_vetor){
	
	for (int i = tamanho_vetor; i >= 0; i--){
		cout << vetor[i];
	}
		
}

// essa é onde a mágica acontece, ela cria o vetor e chama todas as outras funções para fazer a potencição
void potencialonga (int b, int e) {	
	
	// crio o vetor e começo o seu tamanho, aux sera usado para passar os valores da base para o vetor
	int vetor[MAX], tamanho_vetor = 0, aux;
	
	// caso a base esteja sendo elevada a 0, retornar 1 idependente da base
	if (e == 0) {
		cout << "1" << endl;
		return;
	}
	
	// caso a base esteja sendo elevada por 1, retornar a base
	if (e == 1){
		cout << b << endl;
		return;
	}
	
	// transfiro o valor de b para aux e de aux para o vetor, aumentando o tamanho vetor no preocesso
	aux = b;

	while (aux != 0 ) {
		vetor[tamanho_vetor] = aux % 10;
		tamanho_vetor ++;
		aux = aux / 10;
	}

	// aqui eu vou chamar a função multiplica quantas vezes forem especificadas pelo exponencial
	for (int i = 2; i <= e; i++){
		tamanho_vetor = multiplica (b, vetor, tamanho_vetor);
	}

	// printo o vetor
	printvetor (vetor, tamanho_vetor);
	
}


int main() {
	
int b, e;
cin >> b >> e;

potencialonga (b, e);

}	
