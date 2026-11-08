#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>

#define TAM 108

#define ACIMA 72
#define ABAIXO 80
#define DIREITA 77
#define ESQUERDA 75

struct Pessoa
{
	int codigo;
	char nomeadm[100];
	char emailadm[100];
	char senhaadm[100];
};

struct Pessoa ADM[TAM];
struct Pessoa pessoaADM;
int posicaoAtual2 = 0;

struct gente
{

	int codigo;
	char email[100];
	char nome[100];
	char senha[100];
	int matrizpessoal[6][18];
	int pessoaAtual;
};

struct dadosdecadastro
{

	char email[100];
	char nome[100];
	char senha[100];
};

int numero_sort = 0;

struct errocadastro
{

	int erro1;
	int erro2;
	int erro3;
};

struct gente pessoas[TAM];
struct gente pessoaLogada;
struct gente temp[108];

struct NDP
{

	char nomepessoa[108];
};

struct NDP nomedapossoa[108];

struct errocadastro errcad;

struct dadosdecadastro dadocada;

int posicaoAtual = 0;

void gotoxy(int x, int y)
{
	COORD p = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

int autenticarPessoa(char email[], char senha[])
{
	int i = 0;
	int igual = -1;	 // se for 0 , ? igual
	int retorno = 0; // 0-Senha/Usuario invalido  1-Senha/Usuario valido
	for (i = 0; i < TAM; i++)
	{
		igual = strcmp(pessoas[i].email, email);
		if (igual == 0)
		{ // achou o apelido igual ao digitado no vetor
			igual = strcmp(pessoas[i].senha, senha);
			if (igual == 0)
			{				 // achou a senha igual
				retorno = 1; // ok, deu certo.
				pessoaLogada.codigo = pessoas[i].codigo;
				strcpy(pessoaLogada.nome, pessoas[i].nome);
				strcpy(pessoaLogada.email, pessoas[i].email);
				strcpy(pessoaLogada.senha, pessoas[i].senha);
				pessoaLogada.pessoaAtual = pessoas[i].pessoaAtual;
			}
			break; // parar o loop(for)
		}
	}
	return retorno; // 0-Senha/Usuario invalido  1-Senha/Usuario valido
}

void errocadastro()
{
	printf("O que foi colocado n�o � oque foi pedido");
}

void Telavasia()
{
	printf(" **************************************************************************** \n");
	printf("**                                                                          **\n");
	printf("*                                                                            *\n");
	printf("*                                                                            *\n");
	printf("*                                                                            *\n");
	printf("*                                                                            *\n");
	printf("*                                                                            *\n");
	printf("*                                                                            *\n");
	printf("*                                                                            *\n");
	printf("*                                                                            *\n");
	printf("*                                                                            *\n");
	printf("*                                                                            *\n");
	printf("*                                                                            *\n");
	printf("*                                                                            *\n");
	printf("*                                                                            *\n");
	printf("*                                                                            *\n");
	printf("*                                                                            *\n");
	printf("**                                                                          **\n");
	printf(" **************************************************************************** \n");
}

void TelaCadastroADM()
{
	printf(" **************************************************************************** \n");
	printf("**                                                                          **\n");
	printf("*             @@@@@@@@@@@     @@@(   ,@@@@@@@@@      @@@@@@                  *\n");
	printf("*             @@@@    ,@@@,   @@@(   ,@@@           @@@  @@@                 *\n");
	printf("*             @@@@   (@@@@    @@@(   ,@@@          @@@    @@@                *\n");
	printf("*             @@@@@@@@@(      @@@(   ,@@@@@@@@@   @@@      @@@               *\n");
	printf("*             @@@@   #@@@.    @@@(   ,@@@        @@@@@@@@@@@@@@              *\n");
	printf("*             @@@@    (@@@*   @@@(   ,@@@       @@@          @@@             *\n");
	printf("*             &@@#     *@@@   @@@(   ,@@@      @@@            @@@            *\n");
	printf("*                                                                            *\n");
	printf("*                                                                            *\n");
	printf("*                                                                            *\n");
	printf("*                              Bem-Vindo!....                                *\n");
	printf("*    Entre com as informa��es necess�rias para fazer o cadastro de ADM:      *\n");
	printf("*                                                                            *\n");
	printf("* Digite o seu Nome (Somente Letras)  [                           ]          *\n");
	printf("*                                                                            *\n");
	printf("* Digite o seu Email                  [                           ]          *\n");
	printf("*                                                                            *\n");
	printf("* Crie uma senha (Somente n�meros)           [             ]                 *\n");
	printf(" **************************************************************************** \n");
}

void TelaCadastro()
{
	printf(" **************************************************************************** \n");
	printf("**                                                                          **\n");
	printf("*             @@@@@@@@@@@     @@@(   ,@@@@@@@@@      @@@@@@                  *\n");
	printf("*             @@@@    ,@@@,   @@@(   ,@@@           @@@  @@@                 *\n");
	printf("*             @@@@   (@@@@    @@@(   ,@@@          @@@    @@@                *\n");
	printf("*             @@@@@@@@@(      @@@(   ,@@@@@@@@@   @@@      @@@               *\n");
	printf("*             @@@@   #@@@.    @@@(   ,@@@        @@@@@@@@@@@@@@              *\n");
	printf("*             @@@@    (@@@*   @@@(   ,@@@       @@@          @@@             *\n");
	printf("*             &@@#     *@@@   @@@(   ,@@@      @@@            @@@            *\n");
	printf("*                                                                            *\n");
	printf("*                                                                            *\n");
	printf("*                                                                            *\n");
	printf("*                                                                            *\n");
	printf("*    Entre com as informa��es necess�rias para realizar o cadastro:          *\n");
	printf("*                                                                            *\n");
	printf("* Digite o seu email [                         ]                             *\n");
	printf("*                                                                            *\n");
	printf("* Digite o seu nome  [                         ]                             *\n");
	printf("*                                                                            *\n");
	printf("**Crie uma senha n�merica [                    ]                            **\n");
	printf(" **************************************************************************** \n");
}

void TelaLogin()
{
	printf(" **************************************************************************** \n");
	printf("**                                                                          **\n");
	printf("*             @@@@@@@@@@@     @@@(   ,@@@@@@@@@      @@@@@@                  *\n");
	printf("*             @@@@    ,@@@,   @@@(   ,@@@           @@@  @@@                 *\n");
	printf("*             @@@@   (@@@@    @@@(   ,@@@          @@@    @@@                *\n");
	printf("*             @@@@@@@@@(      @@@(   ,@@@@@@@@@   @@@      @@@               *\n");
	printf("*             @@@@   #@@@.    @@@(   ,@@@        @@@@@@@@@@@@@@              *\n");
	printf("*             @@@@    (@@@*   @@@(   ,@@@       @@@          @@@             *\n");
	printf("*             &@@#     *@@@   @@@(   ,@@@      @@@            @@@            *\n");
	printf("*                                                                            *\n");
	printf("*                                                                            *\n");
	printf("*                                                                            *\n");
	printf("*                                                                            *\n");
	printf("*    Entre com as informa��es necess�rias para realizar o login:             *\n");
	printf("*                                                                            *\n");
	printf("* Digite o seu email[                         ]                              *\n");
	printf("*                                                                            *\n");
	printf("**Digite sua senha  [                         ]                             **\n");
	printf(" **************************************************************************** \n");
}

void TelaLoginCadastro()
{
	printf(" **************************************************************************** \n");
	printf("**                                                                          **\n");
	printf("*             @@@@@@@@@@@     @@@(   ,@@@@@@@@@      @@@@@@                  *\n");
	printf("*             @@@@    ,@@@,   @@@(   ,@@@           @@@  @@@                 *\n");
	printf("*             @@@@   (@@@@    @@@(   ,@@@          @@@    @@@                *\n");
	printf("*             @@@@@@@@@(      @@@(   ,@@@@@@@@@   @@@      @@@               *\n");
	printf("*             @@@@   #@@@.    @@@(   ,@@@        @@@@@@@@@@@@@@              *\n");
	printf("*             @@@@    (@@@*   @@@(   ,@@@       @@@          @@@             *\n");
	printf("*             &@@#     *@@@   @@@(   ,@@@      @@@            @@@            *\n");
	printf("*                                                                            *\n");
	printf("*                                                                            *\n");
	printf("*                        Digite a op��o desejada                             *\n");
	printf("*                                                                            *\n");
	printf("*                           [ ] Login                                        *\n");
	printf("*                           [ ] Cadastro                                     *\n");
	printf("*                           [ ] Exit                                         *\n");
	printf("*                                                                            *\n");
	printf("**  Use as [setas] do teclado para se movimenar e [enter] para selecionar   **\n");
	printf(" **************************************************************************** \n");
}

void TelaInicio()
{
	system("cls");
	printf(" **************************************************************************** \n");
	printf("**                                                                          **\n");
	printf("*             @@@@@@@@@@@     @@@(   ,@@@@@@@@@      @@@@@@                  *\n");
	printf("*             @@@@    ,@@@,   @@@(   ,@@@           @@@  @@@                 *\n");
	printf("*             @@@@   (@@@@    @@@(   ,@@@          @@@    @@@                *\n");
	printf("*             @@@@@@@@@(      @@@(   ,@@@@@@@@@   @@@      @@@               *\n");
	printf("*             @@@@   #@@@.    @@@(   ,@@@        @@@@@@@@@@@@@@              *\n");
	printf("*             @@@@    (@@@*   @@@(   ,@@@       @@@          @@@             *\n");
	printf("*             &@@#     *@@@   @@@(   ,@@@      @@@            @@@            *\n");
	printf("*                                                                            *\n");
	printf("*                                                                            *\n");
	printf("*          Por favor selecione a op��o que se refere a quem voce e:          *\n");
	printf("*                                                                            *\n");
	printf("*                           [ ] Administrador                                *\n");
	printf("*                           [ ] Usuario                                      *\n");
	printf("*                                                                            *\n");
	printf("*                                                                            *\n");
	printf("**  Use as [setas] do teclado para se movimenar e [enter] para selecionar   **\n");
	printf(" **************************************************************************** \n");
}

void TelaADM1()
{
	system("cls");
	printf(" **************************************************************************** \n");
	printf("**                                                                          **\n");
	printf("*             @@@@@@@@@@@     @@@(   ,@@@@@@@@@      @@@@@@                  *\n");
	printf("*             @@@@    ,@@@,   @@@(   ,@@@           @@@  @@@                 *\n");
	printf("*             @@@@   (@@@@    @@@(   ,@@@          @@@    @@@                *\n");
	printf("*             @@@@@@@@@(      @@@(   ,@@@@@@@@@   @@@      @@@               *\n");
	printf("*             @@@@   #@@@.    @@@(   ,@@@        @@@@@@@@@@@@@@              *\n");
	printf("*             @@@@    (@@@*   @@@(   ,@@@       @@@          @@@             *\n");
	printf("*             &@@#     *@@@   @@@(   ,@@@      @@@            @@@            *\n");
	printf("*                                                                            *\n");
	printf("*                                                                            *\n");
	printf("*      Ol� Administrador! Por favor, Selecione o que deseja realizar...      *\n");
	printf("*                                                                            *\n");
	printf("*                           [ ] Cadastrar Pr�mios                            *\n");
	printf("*                           [ ] Sortear Vencedores                           *\n");
	printf("*                           [ ] Sair                                         *\n");
	printf("*                                                                            *\n");
	printf("**  Use as [setas] do teclado para se movimenar e [enter] para selecionar   **\n");
	printf(" **************************************************************************** \n");
}

void telacomosnumeros()
{
	system("cls");
	int cont = 0;
	int cont18 = 1;
	printf(" **************************************************************************** \n");
	printf("**                                                                          **\n");
	printf("*                                                                            *\n");
	printf("*                                                                            *\n");
	printf("*                                                                            *\n");
	printf("*                                                                            *\n");
	printf("*                                                                            *\n");
	printf("*                                                                            *\n");
	printf("*                                                                            *\n");
	printf("*                                                                            *\n");
	printf("*            Use as [setas] do teclado para se movimentar                    *\n");
	printf("*                                                                            *\n");
	printf("*                                                                            *\n");
	printf("*                                                                            *\n");
	printf("*                                                                            *\n");
	printf("*                                                                            *\n");
	printf("*                                                                            *\n");
	printf("**                                                                          **\n");
	printf(" **************************************************************************** \n");

	gotoxy(0, 2);

	for (cont = 1; cont <= 108; cont++)
	{
		if (cont18 == 1)
		{
			printf("*  ");
		}
		if (cont < 10)
		{
			printf("00%i ", cont);
		}
		else if (cont < 100)
		{
			printf("0%i ", cont);
		}
		else
		{
			printf("%i ", cont);
		}
		if (cont18 == 18)
		{
			printf("\n");
			cont18 = 0;
		}
		cont18++;
	} // for
	gotoxy(8, 8);

	printf("\n*\tDigite: [1] para reservar [2] para compra e [0] para sair");

} // telacomosnumeros

void telaCadastroPremios(char pre1[], char pre2[], char pre3[], char pre4[], char pre5[])
{
}

int primeiroMenu()
{
	int tecla = 0;
	int linha = 13;
	int coluna = 29;

	while (tecla != 13)
	{
		system("cls");

		TelaInicio(); // Tela Inicial

		gotoxy(coluna, linha);
		printf("%c", 64);

		tecla = getch();

		if (tecla == ESQUERDA)
		{
			coluna--;
			if (coluna < 29)
			{
				coluna = 29;
			}
			gotoxy(coluna, linha);
		}
		if (tecla == DIREITA)
		{
			coluna++;
			if (coluna > 29)
			{
				coluna = 29;
			}
			gotoxy(coluna, linha);
		}
		if (tecla == ABAIXO)
		{
			linha++;
			if (linha > 14)
			{
				linha = 14;
			}
			gotoxy(coluna, linha);
		}
		if (tecla == ACIMA)
		{
			linha--;
			if (linha < 13)
			{
				linha = 13;
			}
			gotoxy(coluna, linha);
		}
	} // while
	return linha;
} // primeiroMenu

int menu2Admin()
{
	int linha = 13;
	int coluna = 29;
	int tecla = 0;
	while (tecla != 13)
	{
		TelaADM1();
		gotoxy(coluna, linha);
		printf("%c", 64);

		tecla = getch();

		if (tecla == ESQUERDA)
		{
			coluna--;
			if (coluna < 29)
			{
				coluna = 29;
			}
			gotoxy(coluna, linha);
		}
		if (tecla == DIREITA)
		{
			coluna++;
			if (coluna > 29)
			{
				coluna = 29;
			}
			gotoxy(coluna, linha);
		}
		if (tecla == ABAIXO)
		{
			linha++;
			if (linha > 15)
			{
				linha = 15;
			}
		}
		if (tecla == ACIMA)
		{
			linha--;
			if (linha < 13)
			{
				linha = 13;
			}
			gotoxy(coluna, linha);
		}
	}
	return linha;
}

main()
{

	system("color f0");
	setlocale(LC_ALL, "portuguese");

	int menuvolta = 0;
	int menuvolta2 = 0;
	int menuinicial = 0;
	int i = 0;
	int tecla, linha, coluna, autenticado;
	char email[100];
	char nome[100];
	char senha[100];
	char pre1[100];
	char pre2[100];
	char pre3[100];
	char pre4[100];
	char pre5[100];
	int cadpremio = 0;						 // novo
	int linhasort, colunasort, contsort = 0; // novo
	tecla = linha = coluna = autenticado = 0;
	int menuadmsair = 0;

	int contcoluna = 0;
	int contlinha = 0;
	int menucompra = 0;
	int menunumend = 0;
	int OK1 = 0;
	int OK2 = 0;
	int menufinalsair = 0;

	int um = 1;
	int dois = 2;

	linha = 13; /// revisar del
	coluna = 29;

	int matriztests[6][18];
	int matrizstats[6][18];

	int vetorDP[108];
	int vetorb[5];

	int continside = 1;
	int linh = 0;
	int colun = 0;

	for (linh = 0; linh < 6; linh++)
	{
		for (colun = 0; colun < 18; colun++)
		{

			matriztests[linh][colun] = continside;
			continside++;
		}
	}

	for (linha = 0; linha < 6; linha++)
	{
		for (coluna = 0; coluna < 18; coluna++)
		{

			matrizstats[linha][coluna] = 0;
		}
	}

	for (i = 0; i < 108; i++)
	{

		vetorDP[i] = 0;
	}

	for (i = 0; i < 5; i++)
	{

		vetorb[i] = 0;
	}

	for (i = 0; i < TAM; i++)
	{

		for (linha = 0; linha < 6; linha++)
		{
			for (coluna = 0; coluna < 18; coluna++)
			{

				pessoas[i].matrizpessoal[linha][coluna] = 0;
			}
		}
	}

	do
	{ // volta do menu de numeros

		do
		{ // sair do menu usuario
			do
			{ // sair do adm
				menuadmsair = 0;

				// primeiro menu
				linha = primeiroMenu();

				tecla = 0;

				// menu de adm
				if (linha == 13)
				{ // menu de adm

					linha = 0; // linhatela
					coluna = 29;

					linha = menu2Admin();

					if (linha == 13)
					{ // selecionou cad premio

						gotoxy(0, 0);

						printf(" **************************************************************************** \n");
						printf("**                                                                          **\n");
						printf("*                                                                            *\n");
						printf("*                                                                            *\n");
						printf("*                             *****************                              *\n");
						printf("*                            *Cadastrar Pr�mios*                             *\n");
						printf("*                             *****************                              *\n");
						printf("*                                                                            *\n");
						printf("*                                                                            *\n");
						printf("*                                                                            *\n");
						printf("* Digite o 1� Pr�mio � Cadastrar:                                            *\n");
						printf("*                                                                            *\n");
						printf("* Digite o 2� Pr�mio � Cadastrar:                                            *\n");
						printf("*                                                                            *\n");
						printf("* Digite o 3� Pr�mio � Cadastrar:                                            *\n");
						printf("*                                                                            *\n");
						printf("* Digite o 4� Pr�mio � Cadastrar:                                            *\n");
						printf("*                                                                            *\n");
						printf("* Digite o 5� Pr�mio � Cadastrar:                                            *\n");
						printf(" **************************************************************************** \n");

						gotoxy(33, 10);
						fflush(stdin);
						gets(pre1);

						gotoxy(33, 12);
						fflush(stdin);
						gets(pre2);

						gotoxy(33, 14);
						fflush(stdin);
						gets(pre3);

						gotoxy(33, 16);
						fflush(stdin);
						gets(pre4);

						gotoxy(33, 18);
						fflush(stdin);
						gets(pre5);

						system("cls");

						gotoxy(0, 0);

						Telavasia();

						gotoxy(8, 8);
						printf("\n Os premios cadastrados foram: 1� %s\n, \t\t\t       2� %s\n, \t\t\t       3� %s\n, \t\t\t       4� %s\n, \t\t\t       5� %s", pre1, pre2, pre3, pre4, pre5);
						sleep(3);
						cadpremio = 1; // novo
						menuadmsair = 1;
					}
					if (linha == 14)
					{ // sortear os numeros

						int cont = 0;
						int cont18 = 1;

						system("cls");
						Telavasia();
						gotoxy(0, 2);

						for (cont = 1; cont <= 108; cont++)
						{
							if (cont18 == 1)
							{
								printf("*  ");
							}
							if (cont < 10)
							{
								printf("00%i ", cont);
							}
							else if (cont < 100)
							{
								printf("0%i ", cont);
							}
							else
							{
								printf("%i ", cont);
							}
							if (cont18 == 18)
							{
								printf("\n");
								cont18 = 0;
							}
							cont18++;
						}

						// sorteio

						int numer1 = 0;
						int numer2 = 0;

						int OK = 1;
						int c = 0;
						int v = 0;
						char temporario[100];
						int sort = 0;
						int li = 0;
						int co = 0;

						srand(time(NULL));
						contsort = 0;
						while (contsort < 5)
						{

							sort = (rand() % 108);

							OK = 1;

							for (li = 0; li < 6; li++)
							{

								for (co = 0; co < 18; co++)
								{

									if (sort == matriztests[li][co])
									{

										numer1 = li;
										numer2 = co;
									}
								}
							}

							for (c = 0; c < 5; c++)
							{

								if (vetorb[c] == matriztests[numer1][numer2])
								{

									OK = 0;
								}
							}

							if (OK == 1)
							{

								if (matrizstats[numer1][numer2] == 2)
								{

									vetorb[contsort] = matriztests[numer1][numer2];

									v = matriztests[numer1][numer2] - 1;

									c = vetorDP[v] - 1;

									sleep(1);

									if (cadpremio == 1)
									{
										if (contsort == 0)
										{
											gotoxy(5, 10);
											printf("\n* 1� Pr�mio: %s - N�mero Sorteado: [%i] Vencedor [%s]", pre1, matriztests[numer1][numer2], pessoas[c].nome);
										}
										if (contsort == 1)
										{
											gotoxy(5, 11);
											printf("\n* 2� Pr�mio: %s - N�mero Sorteado: [%i] Vencedor [%s]", pre2, matriztests[numer1][numer2], pessoas[c].nome);
										}
										if (contsort == 2)
										{
											gotoxy(5, 12);
											printf("\n* 3� Pr�mio: %s - N�mero Sorteado: [%i] Vencedor [%s]", pre3, matriztests[numer1][numer2], pessoas[c].nome);
										}
										if (contsort == 3)
										{
											gotoxy(5, 13);
											printf("\n* 4� Pr�mio: %s - N�mero Sorteado: [%i] Vencedor [%s]", pre4, matriztests[numer1][numer2], pessoas[c].nome);
										}
										if (contsort == 4)
										{
											gotoxy(5, 14);
											printf("\n* 5� Pr�mio: %s - N�mero Sorteado: [%i] Vencedor [%s]", pre5, matriztests[numer1][numer2], pessoas[c].nome);
										}
									}

									if (cadpremio == 0)
									{
										if (contsort == 0)
										{
											gotoxy(5, 10);
											printf("\n* 1� N�mero Sorteado: [%i] Vencedor [%s]", matriztests[numer1][numer2], pessoas[c].nome);
										}
										if (contsort == 1)
										{
											gotoxy(5, 11);
											printf("\n* 2� N�mero Sorteado: [%i] Vencedor [%s]", matriztests[numer1][numer2], pessoas[c].nome);
										}
										if (contsort == 2)
										{
											gotoxy(5, 12);
											printf("\n* 3� N�mero Sorteado: [%i] Vencedor [%s]", matriztests[numer1][numer2], pessoas[c].nome);
										}
										if (contsort == 3)
										{
											gotoxy(5, 13);
											printf("\n* 4� N�mero Sorteado: [%i] Vencedor [%s]", matriztests[numer1][numer2], pessoas[c].nome);
										}
										if (contsort == 4)
										{
											gotoxy(5, 14);
											printf("\n* 5� N�mero Sorteado: [%i] Vencedor [%s]", matriztests[numer1][numer2], pessoas[c].nome);
										}
									}
									contsort++;
								}
							}
						}

						printf("\n");

						getch();

						menuadmsair = 1;
					}
					if (linha == 15)
					{

						menuadmsair = 1;
					}
				}

			} while (menuadmsair == 1);

			do // menu de login e cadastro
			{

				tecla = 0;

				if (linha == 14)
				{
					linha = 13;
					coluna = 29;

					while (tecla != 13)
					{

						system("cls");

						TelaLoginCadastro(); // Tela com as op��es de loguin e cadastro

						gotoxy(coluna, linha);
						printf("%c", 64);

						tecla = getch();

						if (tecla == ESQUERDA)
						{
							coluna--;
							if (coluna < 29)
							{
								coluna = 29;
							}
							gotoxy(coluna, linha);
						}
						if (tecla == DIREITA)
						{
							coluna++;
							if (coluna > 29)
							{
								coluna = 29;
							}
							gotoxy(coluna, linha);
						}
						if (tecla == ABAIXO)
						{
							linha++;
							if (linha > 15)
							{
								linha = 15;
							}
							gotoxy(coluna, linha);
						}
						if (tecla == ACIMA)
						{
							linha--;
							if (linha < 13)
							{
								linha = 13;
							}
							gotoxy(coluna, linha);
						}
					}

					if (linha == 13)
					{

						system("cls");

						TelaLogin(); // Tela de login

						gotoxy(21, 15);
						gets(email);

						gotoxy(21, 17);
						gets(senha);

						autenticado = autenticarPessoa(email, senha);

						if (autenticado == 0)
						{ // NAO DEU CERTO apelido e senha
							system("cls");
							printf("DADOS INVALIDOS ");
							getch();

							menuvolta = 1;
							linha = 14;
						}
						else
						{

							menuvolta = 0;
						}
					}

					else if (linha == 14)
					{

						//	do{// erro senha

						//	do{// erro nome

						//	do{// erro email

						//	errcad.erro1=0;
						//	errcad.erro2=0;
						//	errcad.erro3=0;

						system("cls");

						TelaCadastro(); // Tela de cadastro

						char palav[100];

						int conta = 0;

						gotoxy(22, 15);
						fflush(stdin);
						gets(palav);

						//	while (conta<60 && errcad.erro1 == 0){

						//	    if(((palav[conta] > 64 || palav[conta] < 90)) && ((palav[conta] > 97) || (palav[conta] < 122)) && ((palav[conta] > 48) || (palav[conta] < 57))){

						//		}
						//		else{

						//			errcad.erro1=1;

						//		}

						//	conta++;

						//	}

						//	if (errcad.erro1 != 0){

						//		errocadastro();

						//		system("pause");

						//	}
						//	else{

						strcpy(pessoas[posicaoAtual].email, palav);

						//	}

						//	}while(errcad.erro1!=0);

						gotoxy(22, 17);
						fflush(stdin);
						gets(palav);

						//	while (conta<60 && errcad.erro2 == 0){

						//	if(((palav[conta] > 65 || palav[conta] < 90)) && ((palav[conta] > 97) || (palav[conta] < 122))){

						//	}
						//	else{

						//		errcad.erro2=1;

						//	}

						//	conta++;

						//	}

						//	conta=0;

						//	if (errcad.erro2 != 0){

						//		errocadastro();
						//		system("pause");

						//	}
						//	else{

						strcpy(pessoas[posicaoAtual].nome, palav);

						//	}

						//	}while(errcad.erro2!=0);

						gotoxy(27, 19);
						fflush(stdin);
						gets(palav);

						//	while (conta<60 && errcad.erro3 == 0){

						//		if((palav[conta] > 48) || (palav[conta] < 57)){

						//		}
						//		else{

						//			errcad.erro3=1;

						//		}

						//	conta++;

						//	}

						//	if (errcad.erro3 != 0){

						//		errocadastro();

						//		system("pause");

						//	}
						//	else{

						strcpy(pessoas[posicaoAtual].senha, palav);

						//	}

						//	}while(errcad.erro3!=0);

						//	int confirmar = 0;

						//	gotoxy(14,8);
						//	scanf("%i", &confirmar);
						//
						//	if (confirmar == 1){

						pessoas[posicaoAtual].pessoaAtual = posicaoAtual;

						posicaoAtual = posicaoAtual + 1;

						//		//py(pessoas[posicaoAtual].nome, var_nome);

						//	}

						menuvolta = 1;
						menuinicial = 0;
					}
					else if (linha == 15)
					{

						menuinicial = 1;
						menuvolta = 0;
					}
				}

			} while (menuvolta == 1); // menu cadastro login

		} while (menuinicial == 1); // volta pro primeiro menu

		tecla = 0;

		coluna = 4;
		linha = 2;
		contcoluna = 0;
		contlinha = 0;

		do
		{ // enquanto n pedir pra sair ele roda

			do
			{ // while (tecla != 49 || tecla != 50 || tecla != 48)

				tecla = 0;

				menunumend = 0;
				menufinalsair = 0;
				menucompra = 0;

				telacomosnumeros();

				gotoxy(coluna, linha);

				tecla = getch();

				if (tecla == ESQUERDA)
				{
					coluna--;
					coluna--;
					coluna--;
					coluna--;
					if (coluna < 4)
					{
						coluna = 4;
					}
					gotoxy(coluna, linha);

					contcoluna--;
					if (contcoluna < 0)
					{
						contcoluna = 0;
					}
					menucompra = 0;
				}
				if (tecla == DIREITA)
				{
					coluna++;
					coluna++;
					coluna++;
					coluna++;
					if (coluna > 72)
					{
						coluna = 72;
					}
					gotoxy(coluna, linha);

					contcoluna++;
					if (contcoluna > 17)
					{
						contcoluna = 17;
					}
					menucompra = 0;
				}
				if (tecla == ABAIXO)
				{
					linha++;

					if (linha > 7)
					{
						linha = 7;
					}
					gotoxy(coluna, linha);

					contlinha++;
					if (contlinha > 5)
					{
						contlinha = 5;
					}

					menucompra = 0;
				}
				if (tecla == ACIMA)
				{
					linha--;

					if (linha < 2)
					{
						linha = 2;
					}
					gotoxy(coluna, linha);

					contlinha--;
					if (contlinha > 0)
					{
						contlinha = 0;
					}

					menucompra = 0;
				}
				if (tecla == 48)
				{

					menucompra = 1;
				}
				if (tecla == 49)
				{

					menucompra = 1;
				}
				if (tecla == 50)
				{

					menucompra = 1;
				}

			} while (menucompra == 0);

			// while (tecla != 49 || tecla != 50 || tecla != 48)

			if (tecla == 49)
			{ // alugar

				OK1 = 0;
				OK2 = 0;

				if (pessoas[pessoaLogada.pessoaAtual].matrizpessoal[contlinha][contcoluna] == 0)
				{

					OK1 = 1;
				}
				if (matrizstats[contlinha][contcoluna] == 0)
				{

					OK2 = 1;
				}

				if ((OK1 == 1) && (OK2 == 1))
				{

					system("cls");

					Telavasia();

					gotoxy(8, 8);

					printf("Numero Reservado com Sucesso");

					pessoas[pessoaLogada.pessoaAtual].matrizpessoal[contlinha][contcoluna] = 1;

					sleep(1);
				}
				else
				{

					system("cls");

					Telavasia();

					gotoxy(8, 8);

					printf("ERRO, o numero selecionado n�o esta disponivel ou ja foi alugado por voc�");

					sleep(1);
				}

				menufinalsair = 0;
				menunumend = 0;
			}
			if (tecla == 50)
			{ // comprar

				OK1 = 0;
				OK2 = 0;

				if ((pessoas[pessoaLogada.pessoaAtual].matrizpessoal[contlinha][contcoluna] == 0) && (matrizstats[contlinha][contcoluna] == 0))
				{

					OK1 = 1;
					OK2 = 1;
				}

				if ((pessoas[pessoaLogada.pessoaAtual].matrizpessoal[contlinha][contcoluna] == 1) && (matrizstats[contlinha][contcoluna] == 1))
				{

					OK1 = 1;
					OK2 = 1;
				}

				if (((pessoas[pessoaLogada.pessoaAtual].matrizpessoal[contlinha][contcoluna] == 1) || (pessoas[pessoaLogada.pessoaAtual].matrizpessoal[contlinha][contcoluna] == 0) && (matrizstats[contlinha][contcoluna] == 0)))
				{

					OK1 = 1;
					OK2 = 1;
				}

				if ((OK1 == 1) && (OK2 == 1))
				{

					system("cls");

					Telavasia();

					gotoxy(8, 8);

					printf("Numero Comprado com Sucesso");

					pessoas[pessoaLogada.pessoaAtual].matrizpessoal[contlinha][contcoluna] = 2;

					vetorDP[matriztests[contlinha][contcoluna] - 1] = posicaoAtual;

					sleep(1);
				}
				else
				{

					system("cls");

					Telavasia();

					gotoxy(8, 8);

					printf("ERRO, o numero selecionado n�o esta disponivel");

					sleep(1);
				}

				menufinalsair = 0;
				menunumend = 0;
			}
			if (tecla == 48)
			{

				menufinalsair = 0;
				menunumend = 1;

				int clinha = 0;
				int ccoluna = 0;

				for (clinha = 0; clinha < 6; clinha++)
				{

					for (ccoluna = 0; ccoluna < 18; ccoluna++)
					{

						if ((matrizstats[clinha][ccoluna] == 0) || (matrizstats[clinha][ccoluna] == 1))
						{

							matrizstats[clinha][ccoluna] = pessoas[pessoaLogada.pessoaAtual].matrizpessoal[clinha][ccoluna];
						}
					}
				}
			}

		} while (menunumend == 0);

	} while (menufinalsair == 0);
}
