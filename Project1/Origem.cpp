#include<iostream>
#include<cstdlib>
#include <stdlib.h>
#include <ctime>

using namespace::std;

void matrizAuxiliar(int m[][10]);
void criarTabuleiro(int m[][10]);
void imprimirTabuleiro(int m[][10]);
int numero_Aleatorio(int menor, int maior);



//metodos jogador 01
void adicionar_Navio_Sub_HoriZontal(int m[][10]);
void adicionar_Navio_Contra_Torpedeiro_Horizontal(int m[][10]);
void adicionar_Navio_Tanque_Horizontal(int m[][10]);
void adicionar_Porta_Avioes_Horizontal(int m[][10]);

void adicionar_Navio_Sub_Vertical(int m[][10]);
void adicionar_Navio_Contra_Torpedeiro_Vertical(int m[][10]);
void adicionar_Navio_Tanque_Vertical(int m[][10]);
void adicionar_Porta_Avioes_Vertical(int m[][10]);



// Metodos jogador 02
void adicionar_Navio_Sub_Horizontal_jogador_02(int m[][10], int v[][10]);
void adicionar_Navio_Contra_Torpedeiro_Horizontal_jogador_02(int m[][10], int v[][10]);
void adicionar_Navio_Tanque_Horizontal_jogador_02(int m[][10], int v[][10]);
void adicionar_Porta_Avioes_Horizontal_jogador_02(int m[][10], int v[][10]);

void adicionar_Navio_Sub_Vertical_jogador_02(int m[][10], int v[][10]);
void adicionar_Navio_Contra_Torpedeiro_Vertical_jogador_02(int m[][10], int v[][10]);
void adicionar_Navio_Tanque_Vertical_jogador_02(int m[][10], int v[][10]);
void adicionar_Porta_Avioes_Vertical_jogador_02(int m[][10], int v[][10]);




int tiro_jogador_01(int m[][10], int v[][10], int tiroPosiX, int tiroPosiY);

int tiro_jogador_02(int m[][10], int v[][10], int tiroPosiX, int tiroPosiY);

void inserirNavios_jogador_01(int m[][10]);
void inserirNavios_jogador_02(int m[][10], int v[][10]);

void jogador01();
void iniciar_Partida(int m[][10], int v[][10]);

int pontosJogador1;
int pontosJogador2;

int main() {

	
	int tabuleiro[10][10];
	int matriz[10][10];
	
	criarTabuleiro(tabuleiro);
	criarTabuleiro(matriz);
	inserirNavios_jogador_01(tabuleiro);
	inserirNavios_jogador_02(tabuleiro, matriz);

	cout << "\n";
	imprimirTabuleiro(tabuleiro);
	iniciar_Partida(tabuleiro,matriz);

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
			cout << m[i][j] << "  |  ";
		}
		cout << "\n";
	}
}

void matrizAuxiliar(int v[][10]) {
	int tamanhoTabuleiro = 10;
	for (int i = 0; i < tamanhoTabuleiro; i++) {
		for (int j = 0; j < tamanhoTabuleiro; j++) {
			v[i][j] = 0;

		}
	}
}
	
// Método para criar números aleatórios
int numero_Aleatorio(int menor, int maior) {
	int t;
	for (int i = 0; i < maior; i++){	
		t = (int) menor + (rand() % (maior - menor + 1));
	}	
	return t;	
}



// Métodos para inserir jogadores

void jogador01() {
	string nome;
	cout << "Digite seu nome: ";
	cin >> nome;
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
					adicionar_Navio_Contra_Torpedeiro_Horizontal(m);
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
					adicionar_Navio_Tanque_Horizontal(m);
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
			adicionar_Porta_Avioes_Horizontal(m);
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
			adicionar_Navio_Sub_Vertical(m);
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
			adicionar_Navio_Contra_Torpedeiro_Vertical(m);
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
			adicionar_Navio_Tanque_Vertical(m);
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
			adicionar_Porta_Avioes_Vertical(m);
		}
	} while (aprovado == false);
}




// Método para inserir todos os navios no tabuleiro do Jogador02 => Que é o Computador (Não serão mostrados na matriz); 



// Inserir os navios do jogador 2

// Métodos para adiciona embarcações na Horizontal
void adicionar_Navio_Sub_Horizontal_jogador_02(int m[][10], int v[][10]) {
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
		if ((m[i][j] == 0 && m[i][j + 1] == 0) && (v[i][j] == 0 && v[i][j + 1] == 0)) {
			v[i][j] = 1;
			v[i][j + 1] = 1;
			aprovado = true;
		}
		else {
			linha = numero_Aleatorio(0, 9);
			coluna = numero_Aleatorio(0, 8);
		}
	} while (aprovado == false);
}

void adicionar_Navio_Contra_Torpedeiro_Horizontal_jogador_02(int m[][10], int v[][10]) {
	// e inserir se pode inserir no tabuleiro o contra_Torpedeiro
	bool aprovado = false;
	int linha = numero_Aleatorio(0, 9);
	int coluna = numero_Aleatorio(0, 7);

	int i = linha;
	int j = coluna;
	do {
		if ((m[i][j] == 0 && m[i][j + 1] == 0 && m[i][j + 2] == 0) && (v[i][j] == 0 && v[i][j + 1] == 0 && v[i][j + 2] == 0)) {
			v[i][j] = 2;
			v[i][j + 1] = 2;
			v[i][j + 2] = 2;
			aprovado = true;
		}
		else {
			adicionar_Navio_Contra_Torpedeiro_Horizontal_jogador_02(m,v);
		}
	} while (aprovado == false);
}

void adicionar_Navio_Tanque_Horizontal_jogador_02(int m[][10], int v[][10]) {
	// e inserir se pode inserir no tabuleiro o contra_Torpedeiro
	bool aprovado = false;
	int linha = numero_Aleatorio(0, 9);
	int coluna = numero_Aleatorio(0, 6);
	int i = linha;
	int j = coluna;
	do {
		if ((m[i][j] == 0 && m[i][j + 1] == 0 && m[i][j + 2] == 0 && m[i][j + 3] == 0) && (v[i][j] == 0 && v[i][j + 1] == 0 && v[i][j + 2] == 0 && v[i][j + 3] == 0)) {
			v[i][j] = 3;
			v[i][j + 1] = 3;
			v[i][j + 2] = 3;
			v[i][j + 3] = 3;
			aprovado = true;
		}
		else {
			adicionar_Navio_Tanque_Horizontal_jogador_02(m,v);
		}
	} while (aprovado == false);

}

void adicionar_Porta_Avioes_Horizontal_jogador_02(int m[][10], int v[][10]) {
	//  inserir no tabuleiro o Porta Aviões
	bool aprovado = false;
	int linha = numero_Aleatorio(0, 9);
	int coluna = numero_Aleatorio(0, 5);
	int i = linha;
	int j = coluna;
	do {
		if ((m[i][j] == 0 && m[i][j + 1] == 0 && m[i][j + 2] == 0 && m[i][j + 3] == 0 && m[i][j + 4] == 0) && (v[i][j] == 0 && v[i][j + 1] == 0 && v[i][j + 2] == 0 && v[i][j + 3] == 0 && v[i][j + 4] == 0)) {
			v[i][j] = 4;
			v[i][j + 1] = 4;
			v[i][j + 2] = 4;
			v[i][j + 3] = 4;
			v[i][j + 4] = 4;
			aprovado = true;
		}
		else {
			linha = numero_Aleatorio(0, 9);
			coluna = numero_Aleatorio(0, 6);
			adicionar_Porta_Avioes_Horizontal_jogador_02(m,v);
		}
	} while (aprovado == false);
}


// Métodos para adiciona embarcações na Vertical

void adicionar_Navio_Sub_Vertical_jogador_02(int m[][10], int v[][10]) {
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
		if ((m[i + 1][j] == 0 && m[i][j] == 0) && (v[i + 1][j] == 0 && v[i][j] == 0)) {
			v[i][j] = 1;
			v[i + 1][j] = 1;
			aprovado = true;
		}
		else {
			adicionar_Navio_Sub_Vertical_jogador_02(m,v);
		}
	} while (aprovado == false);
}

void adicionar_Navio_Contra_Torpedeiro_Vertical_jogador_02(int m[][10], int v[][10]) {
	// e inserir se pode inserir no tabuleiro o contra_Torpedeiro
	bool aprovado = false;
	int linha = numero_Aleatorio(0, 7);
	int coluna = numero_Aleatorio(0, 9);

	int i = linha;
	int j = coluna;
	do {
		if ((m[i][j] == 0 && m[i + 1][j] == 0 && m[i + 2][j] == 0) && (v[i][j] == 0 && v[i + 1][j] == 0 && v[i + 2][j] == 0)) {
			v[i][j] = 2;
			v[i + 1][j] = 2;
			v[i + 2][j] = 2;
			aprovado = true;
		}
		else {
			adicionar_Navio_Contra_Torpedeiro_Vertical_jogador_02(m,v);
		}
	} while (aprovado == false);
}

void adicionar_Navio_Tanque_Vertical_jogador_02(int m[][10], int v[][10]) {
	// e inserir se pode inserir no tabuleiro o contra_Torpedeiro
	bool aprovado = false;
	int linha = numero_Aleatorio(0, 6);
	int coluna = numero_Aleatorio(0, 9);
	int i = linha;
	int j = coluna;
	do {
		if ((m[i][j] == 0 && m[i + 1][j] == 0 && m[i + 2][j] == 0 && m[i + 3][j] == 0) && (v[i][j] == 0 && v[i + 1][j] == 0 && v[i + 2][j] == 0 && v[i + 3][j] == 0)) {
			v[i][j] = 3;
			v[i + 1][j] = 3;
			v[i + 2][j] = 3;
			v[i + 3][j] = 3;
			aprovado = true;
		}
		else {
			adicionar_Navio_Tanque_Vertical_jogador_02(m,v);
		}
	} while (aprovado == false);

}

void adicionar_Porta_Avioes_Vertical_jogador_02(int m[][10], int v[][10]) {
	//  inserir no tabuleiro o Porta Aviões
	bool aprovado = false;
	int linha = numero_Aleatorio(0, 5);
	int coluna = numero_Aleatorio(0, 9);
	int i = linha;
	int j = coluna;
	do {
		if ((m[i][j] == 0 && m[i + 1][j] == 0 && m[i + 2][j] == 0 && m[i + 3][j] == 0 && m[i + 4][j] == 0) && (v[i][j] == 0 && v[i + 1][j] == 0 && v[i + 2][j] == 0 && v[i + 3][j] == 0 && v[i + 4][j] == 0)) {
			v[i][j] = 4;
			v[i + 1][j] = 4;
			v[i + 2][j] = 4;
			v[i + 3][j] = 4;
			v[i + 4][j] = 4;
			aprovado = true;
		}
		else {
			adicionar_Porta_Avioes_Vertical_jogador_02(m,v);
		}
	} while (aprovado == false);
}




 
// Método para dar tiro

int tiro_jogador_01(int m[][10],int v[][10] ,int tiroPosiX, int tiroPosiY) {
	if (v[tiroPosiX][tiroPosiY] == 1 || v[tiroPosiX][tiroPosiY] ==  2 || v[tiroPosiX][tiroPosiY] ==  3 || v[tiroPosiX][tiroPosiY] ==  4) {
		m[tiroPosiX][tiroPosiY] = -1;
		cout << "BUMMMMM !!!!!" << ::endl;
		cout << "ACERTOU !!!!!" << ::endl;
		pontosJogador1++;
		if (pontosJogador1 == 14){
			cout << "Parabéns você venceu !" << ::endl;
		}
	}
	else {
		cout << " VC ERROU !!!!!" << ::endl;
	}
	return pontosJogador1;
}

int tiro_jogador_02(int m[][10], int v[][10], int tiroPosiX, int tiroPosiY) {
	if (m[tiroPosiX][tiroPosiY] == 1 || m[tiroPosiX][tiroPosiY] == 2 || m[tiroPosiX][tiroPosiY] == 3 || m[tiroPosiX][tiroPosiY] == 4) {
		m[tiroPosiX][tiroPosiY] = -1;
		cout << "BUMMMMM !!!!!" << ::endl;
		cout << "A MAQUINA ACERTOU !!!!!" << ::endl;
		pontosJogador2++;
		if (pontosJogador2 == 14) {
			cout << "Você perdeu a maquina ganhou ! " << ::endl;
		}
	}
	else {
		cout << "A MAQUINA ERROU !!!!!" << ::endl;
	}
	return pontosJogador2;
}
// Método para inserir todos os navios no tabuleiro do Jogador01 => Que jogará contra a máquina
void inserirNavios_jogador_01(int m[][10]) {
	// Número aleatório para inserir navio na Vertical ou na Horizontal

	// Inserindo Submarino
	int num = numero_Aleatorio(0, 4);
	if (num == 0 || num == 2 || num == 4) {
		adicionar_Navio_Sub_HoriZontal(m);
	}
	else {
		adicionar_Navio_Sub_Vertical(m);
	}

	// Inserindo Contra Torpedeiro
	num = numero_Aleatorio(0, 4);
	if (num == 0 || num == 2 || num == 4) {
		adicionar_Navio_Contra_Torpedeiro_Horizontal(m);
	}
	else {
		adicionar_Navio_Contra_Torpedeiro_Vertical(m);
	}

	// Inserindo Navio Tanque
	num = numero_Aleatorio(0, 4);
	if (num == 0 || num == 2 || num == 4) {
		adicionar_Navio_Tanque_Horizontal(m);
	}
	else {
		adicionar_Navio_Tanque_Vertical(m);
	}

	// Inserindo Porta Aviões
	num = numero_Aleatorio(0, 4);
	if (num == 0 || num == 2 || num == 4) {
		adicionar_Porta_Avioes_Horizontal(m);
	}
	else {
		adicionar_Porta_Avioes_Vertical(m);
	}
}


// Método para inserir todos os navios no tabuleiro do Jogador02 => Que é a máquina
void inserirNavios_jogador_02(int m[][10], int v[][10]) {
	// Número aleatório para inserir navio na Vertical ou na Horizontal

	// Inserindo Submarino
	int num = numero_Aleatorio(0, 4);
	if (num == 0 || num == 2 || num == 4) {
		adicionar_Navio_Sub_Horizontal_jogador_02(m,v);
	}
	else {
		adicionar_Navio_Sub_Vertical_jogador_02(m,v);
	}

	// Inserindo Contra Torpedeiro
	num = numero_Aleatorio(0, 4);
	if (num == 0 || num == 2 || num == 4) {
		adicionar_Navio_Contra_Torpedeiro_Horizontal_jogador_02(m, v);
	}
	else {
		adicionar_Navio_Contra_Torpedeiro_Vertical_jogador_02(m,v);
	}

	// Inserindo Navio Tanque
	num = numero_Aleatorio(0, 4);
	if (num == 0 || num == 2 || num == 4) {
		adicionar_Navio_Tanque_Horizontal_jogador_02(m,v);
	}
	else {
		adicionar_Navio_Tanque_Vertical_jogador_02(m,v);
	}

	// Inserindo Porta Aviões
	num = numero_Aleatorio(0, 4);
	if (num == 0 || num == 2 || num == 4) {
		adicionar_Porta_Avioes_Horizontal_jogador_02(m,v);
	}
	else {
		adicionar_Porta_Avioes_Vertical_jogador_02(m,v);
	}
}

void iniciar_Partida(int m[][10], int v[][10]) {
	int l;
	int c;
	do{
		cout << "Digite as coordenadas do seu tiro"<<::endl;
		cout << "Qual linha ?" << ::endl;
		cin >> l;
		cout << "Qual coluna ?" << ::endl;
		cin >> c;

		cout << "Tiro nas coordenadas: " << l << " | "<< c << ::endl;
		system("cls");
		tiro_jogador_01(m, v, l, c);
		int linha = numero_Aleatorio(0,9);
		int coluna = numero_Aleatorio(0,9);
		tiro_jogador_02(m, v, linha, coluna);
		
		imprimirTabuleiro(m);
	} while ((pontosJogador1 < 14) || (pontosJogador2 < 14));
	
}