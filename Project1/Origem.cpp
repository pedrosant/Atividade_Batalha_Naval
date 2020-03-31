#include<iostream>
#include <ctime>

using namespace::std;

void criarTabuleiro(int m[][10]);
void imprimirTabuleiro(int m[][10]);
void adicionar_Navio_Na_Vertical(int m[][10]);

void jogador01();
void jogador02();


int main() {
	int tabuleiro[10][10];

	criarTabuleiro(tabuleiro);
	imprimirTabuleiro(tabuleiro);
	adicionar_Navio_Na_Vertical(tabuleiro);
	cout << "\n";
	imprimirTabuleiro(tabuleiro);

	return 0;
}


void criarTabuleiro(int v[][10]) {
	int tamanhoTabuleiro = 10;
	for (int i = 0; i < tamanhoTabuleiro; i++) {
		for (int j = 0; j < tamanhoTabuleiro; j++) {
			v[i][j] = 0;
		}
	}
}

void imprimirTabuleiro(int m[][10]) {
	int tamanhoTabuleiro = 10;
	for (int i = 0; i < tamanhoTabuleiro; i++) {
		for (int j = 0; j < tamanhoTabuleiro; j++) {
			cout << m[i][j] << " | ";
		}
		cout << "\n";
	}
}

int numero_Aleatorio(int menor, int maior) {
	srand((unsigned)time(0));
	return rand() % (maior - menor + 1) + menor;
}






void jogador01() {
	string nome;
	cout << "Digite seu nome: ";
	cin >> nome;

}

void jogador02() {
	string nome = "Computador";
}



void adicionar_Navio_Na_Vertical(int m[][10]) {
	//int submarino = 2;
	//int contra_Torpedeiro = 3;
	//int navio_tanque = 4;
	//int porta_avioes = 5;
	bool aprovado = false;
	int linha = numero_Aleatorio(0, 9);
	int coluna = numero_Aleatorio(0, 9);
	// e inserir se pode inserir no tabuleiro o submarino
	for (int i = linha; i < linha + 1; i++) {
		if (coluna > 8) {
			coluna = coluna - 1;
		}
		for (int j = coluna; j < coluna + 1; j++) {
			do {
				if ((m[i][j] && m[i][j + 1]) == 0) {
					m[i][j] = 1;
					m[i][j + 1] = 1;
					aprovado = true;
				}
				else {
					linha = numero_Aleatorio(0, 9);
				}
			} while (aprovado == false);

		}
	}
	// e inserir se pode inserir no tabuleiro o contra_Torpedeiro




}

void adicionar_Navio_Na_Horizontal() {

}