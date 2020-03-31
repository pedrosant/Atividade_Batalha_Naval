#include<iostream>
#include <ctime>

using namespace::std;

void criarTabuleiro(int m[][10]);
void imprimirTabuleiro(int m[][10]);
void adicionar_Navio_Sub_HoriZontal(int m[][10]);
void adicionar_Navio_Contra_Torpedeiro_Horizontal(int m[][10]);
void adicionar_Navio_Navio_Tanque_Horizontal(int m[][10]);

void jogador01();
void jogador02();


int main() {
	int tabuleiro[10][10];
	

	criarTabuleiro(tabuleiro);
	imprimirTabuleiro(tabuleiro);
	adicionar_Navio_Sub_HoriZontal(tabuleiro);
	adicionar_Navio_Contra_Torpedeiro_Horizontal(tabuleiro);
	adicionar_Navio_Navio_Tanque_Horizontal(tabuleiro);

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
	srand((unsigned)time(NULL));
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



void adicionar_Navio_Sub_HoriZontal(int m[][10]) {
	//int submarino = 2;
	//int contra_Torpedeiro = 3;
	//int navio_tanque = 4;
	//int porta_avioes = 5;
	bool aprovado = false;
	int linha = numero_Aleatorio(0, 9);
	int coluna = numero_Aleatorio(0, 8);
	// e inserir se pode inserir no tabuleiro o submarino
	for (int i = linha; i < linha + 1; i++) {
		for (int j = coluna; j < coluna + 1; j++) {
			do {
				if (m[i][j] == 0 && m[i][j + 1] == 0) {
					m[i][j] = 1;
					m[i][j + 1] = 1;
					aprovado = true;
				}
				else {
					linha = numero_Aleatorio(0, 9);
					coluna = numero_Aleatorio(0, 8);
				}
			} while (aprovado == false);
			break;
		}
	}
}

void adicionar_Navio_Contra_Torpedeiro_Horizontal(int m[][10]) {
	// e inserir se pode inserir no tabuleiro o contra_Torpedeiro
	bool aprovado = false;
	int linha = numero_Aleatorio(0, 9);
	int coluna = numero_Aleatorio(0, 7);
	for (int i = linha; i < linha + 1; i++) {
		for (int j = coluna; j < coluna + 1; j++) {
			do {
				if (m[i][j] == 0 && m[i][j + 1] == 0 && m[i][j + 2] == 0) {
					m[i][j] = 2;
					m[i][j + 1] = 2;
					m[i][j + 2] = 2;
					aprovado = true;
				}
				else {
					linha = numero_Aleatorio(0, 9);
					coluna = numero_Aleatorio(0, 7);
				}
			} while (aprovado == false);
			break;
		}
	}
}

void adicionar_Navio_Navio_Tanque_Horizontal(int m[][10]) {
	// e inserir se pode inserir no tabuleiro o contra_Torpedeiro
	bool aprovado = false;
	int linha = numero_Aleatorio(0, 9);
	int coluna = numero_Aleatorio(0, 6);
	for (int i = linha; i < linha + 1; i++) {
		for (int j = coluna; j < coluna + 1; j++) {
			do {
				if (m[i][j] == 0 && m[i][j + 1] == 0 && m[i][j + 2] == 0 && m[i][j + 3] == 0) {
					m[i][j] = 3;
					m[i][j + 1] = 3;
					m[i][j + 2] = 3;
					m[i][j + 3] = 3;
					aprovado = true;
				}
				else {
					linha = numero_Aleatorio(0, 9);
					coluna = numero_Aleatorio(0, 6);
				}
			} while (aprovado == false);
			break;
		}
	}
}

void adicionar_Navio_Na_Horizontal() {

}