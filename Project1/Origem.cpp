#include<iostream>
#include<cstdlib>
#include <time.h>

using namespace::std;

void criarTabuleiro(int m[][10]);
void imprimirTabuleiro(int m[][10]);
int numero_Aleatorio(int menor, int maior);

void adicionar_Navio_Sub_HoriZontal(int m[][10]);
void adicionar_Navio_Contra_Torpedeiro_Horizontal(int m[][10]);
void adicionar_Navio_Tanque_Horizontal(int m[][10]);
void adicionar_Porta_Avioes_Horizontal(int m[][10]);

void adicionar_Navio_Sub_Vertical(int m[][10]);
void adicionar_Navio_Contra_Torpedeiro_Vertical(int m[][10]);
void adicionar_Navio_Tanque_Vertical(int m[][10]);
void adicionar_Porta_Avioes_Vertical(int m[][10]);

void atirar(int m[][10], int tiroPosiX, int tiroPosiY);

void inserirNavios_jogador_01(int m[][10]);

void jogador01();
void jogador02();


int main() {
	int tabuleiro[10][10];
	

	
	imprimirTabuleiro(tabuleiro);
	


	cout << "\n";
	imprimirTabuleiro(tabuleiro);

	return 0;

}


// Método para criar tabuleiro
void criarTabuleiro(int v[][10]) {
	int tamanhoTabuleiro = 10;
	for (int i = 0; i < tamanhoTabuleiro; i++) {
		for (int j = 0; j < tamanhoTabuleiro; j++) {
			v[i][j] = 0;
		}
	}
}

// Método para imprimir tabuleiro
void imprimirTabuleiro(int m[][10]) {
	int tamanhoTabuleiro = 10;
	for (int i = 0; i < tamanhoTabuleiro; i++) {
		for (int j = 0; j < tamanhoTabuleiro; j++) {
			cout << m[i][j] << " | ";
		}
		cout << "\n";
	}
}

// Método para criar números aleatórios
int numero_Aleatorio(int menor, int maior) {	
		srand((unsigned)time(0));
		return rand() % (maior - menor) + 1;	
}



// Métodos para inserir jogadores

void jogador01() {
	string nome;
	cout << "Digite seu nome: ";
	cin >> nome;
}

void jogador02() {
	string nome = "Computador";
}


// Métodos para adiciona embarcações na Horizontal
void adicionar_Navio_Sub_HoriZontal(int m[][10]) {
	//int submarino = 2;
	//int contra_Torpedeiro = 3;
	//int navio_tanque = 4;
	//int porta_avioes = 5;
	bool aprovado = false;
	int linha = numero_Aleatorio(0, 9);
	int coluna = numero_Aleatorio(0, 8);

	int i = linha;
	int j = coluna;
	// e inserir se pode inserir no tabuleiro o submarino
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
}

void adicionar_Navio_Contra_Torpedeiro_Horizontal(int m[][10]) {
	// e inserir se pode inserir no tabuleiro o contra_Torpedeiro
	bool aprovado = false;
	int linha = numero_Aleatorio(0, 9);
	int coluna = numero_Aleatorio(0, 7);

	int i = linha;
	int j = coluna;	
			do {
				if (m[i][j] == 0 && m[i][j + 1] == 0 && m[i][j + 2] == 0) {
					m[i][j] = 2;
					m[i][j + 1] = 2;
					m[i][j + 2] = 2;
					aprovado = true;
				}else {
					linha = numero_Aleatorio(0, 9);
					coluna = numero_Aleatorio(0, 7);
				}
			} while (aprovado == false);			
}

void adicionar_Navio_Tanque_Horizontal(int m[][10]) {
	// e inserir se pode inserir no tabuleiro o contra_Torpedeiro
	bool aprovado = false;
	int linha = numero_Aleatorio(0, 9);
	int coluna = numero_Aleatorio(0, 6);
	int i = linha;
	int j = coluna;	
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
	
}

void adicionar_Porta_Avioes_Horizontal(int m[][10]) {
	//  inserir no tabuleiro o Porta Aviões
	bool aprovado = false;
	int linha = numero_Aleatorio(0, 9);
	int coluna = numero_Aleatorio(0, 5);
	int i = linha;
	int j = coluna;
	do {
		if (m[i][j] == 0 && m[i][j + 1] == 0 && m[i][j + 2] == 0 && m[i][j + 3] == 0 && m[i][j + 4] == 0) {
			m[i][j] = 4;
			m[i][j + 1] = 4;
			m[i][j + 2] = 4;
			m[i][j + 3] = 4;
			m[i][j + 4] = 4;
			aprovado = true;
		}
		else {
			linha = numero_Aleatorio(0, 9);
			coluna = numero_Aleatorio(0, 6);
		}
	} while (aprovado == false);
}


// Métodos para adiciona embarcações na Vertical

void adicionar_Navio_Sub_Vertical(int m[][10]) {
	//int submarino = 2;
	//int contra_Torpedeiro = 3;
	//int navio_tanque = 4;
	//int porta_avioes = 5;
	bool aprovado = false;
	int linha = numero_Aleatorio(0, 8);
	int coluna = numero_Aleatorio(0, 9);

	int i = linha;
	int j = coluna;
	
	do {
		if (m[i + 1][j] == 0 && m[i][j] == 0) {
			m[i][j] = 1;
			m[i + 1][j] = 1;
			aprovado = true;
		}
		else {
			linha = numero_Aleatorio(0, 8);
			coluna = numero_Aleatorio(0, 9);
		}
	} while (aprovado == false);
}

void adicionar_Navio_Contra_Torpedeiro_Vertical(int m[][10]) {
	// e inserir se pode inserir no tabuleiro o contra_Torpedeiro
	bool aprovado = false;
	int linha = numero_Aleatorio(0, 7);
	int coluna = numero_Aleatorio(0, 9);

	int i = linha;
	int j = coluna;
	do {
		if (m[i][j] == 0 && m[i + 1][j] == 0 && m[i + 2][j] == 0) {
			m[i][j] = 2;
			m[i + 1][j] = 2;
			m[i + 2][j] = 2;
			aprovado = true;
		}
		else {
			linha = numero_Aleatorio(0, 7);
			coluna = numero_Aleatorio(0, 9);
		}
	} while (aprovado == false);
}

void adicionar_Navio_Tanque_Vertical(int m[][10]) {
	// e inserir se pode inserir no tabuleiro o contra_Torpedeiro
	bool aprovado = false;
	int linha = numero_Aleatorio(0, 6);
	int coluna = numero_Aleatorio(0, 9);
	int i = linha;
	int j = coluna;
	do {
		if (m[i][j] == 0 && m[i + 1][j] == 0 && m[i + 2][j] == 0 && m[i + 3][j] == 0) {
			m[i][j] = 3;
			m[i + 1][j] = 3;
			m[i + 2][j] = 3;
			m[i + 3][j] = 3;
			aprovado = true;
		}
		else {
			linha = numero_Aleatorio(0, 6);
			coluna = numero_Aleatorio(0, 9);
		}
	} while (aprovado == false);

}

void adicionar_Porta_Avioes_Vertical(int m[][10]) {
	//  inserir no tabuleiro o Porta Aviões
	bool aprovado = false;
	int linha = numero_Aleatorio(0, 5);
	int coluna = numero_Aleatorio(0, 9);
	int i = linha;
	int j = coluna;
	do {
		if (m[i][j] == 0 && m[i + 1][j] == 0 && m[i + 2][j] == 0 && m[i + 3][j] == 0 && m[i + 4][j] == 0) {
			m[i][j] = 4;
			m[i + 1][j] = 4;
			m[i + 2][j] = 4;
			m[i + 3][j] = 4;
			m[i + 4][j] = 4;
			aprovado = true;
		}
		else {
			linha = numero_Aleatorio(0, 5);
			coluna = numero_Aleatorio(0, 9);
		}
	} while (aprovado == false);
}


// Método para dar tiro

void atirar(int m[][10],int tiroPosiX, int tiroPosiY) {
	if (m[tiroPosiX][tiroPosiY]){
		m[tiroPosiX][tiroPosiY] = -1;
		cout << "BUMMMMM !!!!!";
		cout << "ACERTOU !!!!!";
	}
}

// Método para inserir todos os navios no tabuleiro do Jogador01 => Que jogará contra a máquina
void inserirNavios_jogador_01(int m[][10]) {
	// Número aleatório para inserir navio na Vertical ou na Horizontal
	// Inserindo Submarino
	int num = numero_Aleatorio(0, 1);
	if (num == 0){
		adicionar_Navio_Sub_HoriZontal(m);
	}else {
		adicionar_Navio_Sub_Vertical(m);
	}

	// Inserindo Contra Torpedeiro
	num = numero_Aleatorio(0, 1);
	if (num == 0) {
		adicionar_Navio_Contra_Torpedeiro_Horizontal(m);
	}
	else {
		adicionar_Navio_Contra_Torpedeiro_Vertical(m);
	}

	// Inserindo Navio Tanque
	num = numero_Aleatorio(0, 1);
	if (num == 0) {
		adicionar_Navio_Tanque_Horizontal(m);
	}
	else {
		adicionar_Navio_Tanque_Vertical(m);
	}

	// Inserindo Porta Aviões
	num = numero_Aleatorio(0, 1);
	if (num == 0) {
		adicionar_Porta_Avioes_Horizontal(m);
	}
	else {
		adicionar_Porta_Avioes_Vertical(m);
	}
}

// Método para inserir todos os navios no tabuleiro do Jogador02 => Que é o Computador (Não serão mostrados na matriz); 

void inserirNavios_jogador_02() {

}