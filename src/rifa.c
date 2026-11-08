/**
 * @file rifa.c
 * @brief Sistema de rifa executado no terminal do Windows.
 *
 * Projeto Integrador I - Centro Universitário UNIFACEAR (2020).
 *
 * Permite o cadastro de usuários, a reserva e a compra de números em uma
 * cartela de 108 números (6 linhas por 18 colunas), o cadastro de até cinco
 * prêmios pelo administrador e o sorteio aleatório dos vencedores.
 *
 * Toda a navegação é feita pelo teclado (setas e Enter). As telas são
 * desenhadas com printf() e o cursor é posicionado com gotoxy(), que usa a
 * API do console do Windows. Os dados ficam apenas em memória e são perdidos
 * ao encerrar o programa.
 *
 * @authors Guilherme da Luz Weber, Érick Alan da Silva
 * @note O arquivo está codificado em Windows-1252 (ANSI) para exibir
 *       corretamente os acentos no console com setlocale().
 */

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>

/** Capacidade máxima dos vetores de pessoas (também é a quantidade de números da cartela). */
#define TAM 108

/**
 * @name Códigos das setas do teclado
 * Valores retornados por getch() após o prefixo das teclas especiais.
 * @{
 */
#define ACIMA 72
#define ABAIXO 80
#define DIREITA 77
#define ESQUERDA 75
/** @} */

/**
 * @brief Dados de um administrador.
 * @note Estrutura reservada para o cadastro de administradores, ainda não
 *       utilizada pelo fluxo do programa.
 */
struct Pessoa
{
	int codigo;
	char nomeadm[100];
	char emailadm[100];
	char senhaadm[100];
};

/** Vetor de administradores cadastrados (não utilizado). */
struct Pessoa ADM[TAM];
/** Administrador autenticado (não utilizado). */
struct Pessoa pessoaADM;
/** Próxima posição livre no vetor ADM (não utilizado). */
int posicaoAtual2 = 0;

/**
 * @brief Dados de um usuário (comprador) da rifa.
 */
struct gente
{

	int codigo;
	char email[100];
	char nome[100];
	char senha[100];
	int matrizpessoal[6][18];
	int pessoaAtual;
};

/**
 * @brief Dados digitados na tela de cadastro (não utilizado).
 */
struct dadosdecadastro
{

	char email[100];
	char nome[100];
	char senha[100];
};

/** Número sorteado (não utilizado). */
int numero_sort = 0;

/**
 * @brief Indicadores de erro na validação do cadastro.
 * @note Usado apenas pela validação que está comentada em main().
 */
struct errocadastro
{

	int erro1;
	int erro2;
	int erro3;
};

/** Usuários cadastrados, na ordem de cadastro. */
struct gente pessoas[TAM];
/** Cópia dos dados do usuário autenticado no momento. */
struct gente pessoaLogada;
/** Vetor auxiliar de usuários (não utilizado). */
struct gente temp[108];

/**
 * @brief Nome de uma pessoa (não utilizado).
 */
struct NDP
{

	char nomepessoa[108];
};

/** Nomes associados aos números da cartela (não utilizado). */
struct NDP nomedapossoa[108];

/** Estado da validação do cadastro (ver errocadastro). */
struct errocadastro errcad;

/** Dados temporários do cadastro (não utilizado). */
struct dadosdecadastro dadocada;

/** Quantidade de usuários cadastrados; também é o índice do próximo cadastro em pessoas. */
int posicaoAtual = 0;

/**
 * @brief Posiciona o cursor do console.
 *
 * @param x Coluna (0 é a borda esquerda).
 * @param y Linha (0 é o topo).
 */
void gotoxy(int x, int y)
{
	COORD p = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

/**
 * @brief Autentica um usuário pelo e-mail e pela senha.
 *
 * Procura o e-mail no vetor pessoas. Se a senha conferir, copia os dados do
 * usuário para pessoaLogada.
 *
 * @param email E-mail digitado na tela de login.
 * @param senha Senha digitada na tela de login.
 * @return 1 se o e-mail e a senha conferem; 0 caso contrário.
 */
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

/**
 * @brief Exibe a mensagem de dado inválido no cadastro.
 * @note Chamada apenas pela validação que está comentada em main().
 */
void errocadastro()
{
	printf("O que foi colocado nï¿½o ï¿½ oque foi pedido");
}

/**
 * @brief Desenha a moldura vazia usada para mensagens e para a cartela.
 */
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

/**
 * @brief Desenha a tela de cadastro de administrador.
 * @note Tela pronta, mas ainda não chamada pelo programa.
 */
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
	printf("*    Entre com as informaï¿½ï¿½es necessï¿½rias para fazer o cadastro de ADM:      *\n");
	printf("*                                                                            *\n");
	printf("* Digite o seu Nome (Somente Letras)  [                           ]          *\n");
	printf("*                                                                            *\n");
	printf("* Digite o seu Email                  [                           ]          *\n");
	printf("*                                                                            *\n");
	printf("* Crie uma senha (Somente nï¿½meros)           [             ]                 *\n");
	printf(" **************************************************************************** \n");
}

/**
 * @brief Desenha a tela de cadastro de usuário (e-mail, nome e senha).
 */
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
	printf("*    Entre com as informaï¿½ï¿½es necessï¿½rias para realizar o cadastro:          *\n");
	printf("*                                                                            *\n");
	printf("* Digite o seu email [                         ]                             *\n");
	printf("*                                                                            *\n");
	printf("* Digite o seu nome  [                         ]                             *\n");
	printf("*                                                                            *\n");
	printf("**Crie uma senha nï¿½merica [                    ]                            **\n");
	printf(" **************************************************************************** \n");
}

/**
 * @brief Desenha a tela de login do usuário (e-mail e senha).
 */
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
	printf("*    Entre com as informaï¿½ï¿½es necessï¿½rias para realizar o login:             *\n");
	printf("*                                                                            *\n");
	printf("* Digite o seu email[                         ]                              *\n");
	printf("*                                                                            *\n");
	printf("**Digite sua senha  [                         ]                             **\n");
	printf(" **************************************************************************** \n");
}

/**
 * @brief Desenha o menu do usuário com as opções Login, Cadastro e Exit.
 *
 * As opções ficam nas linhas 13, 14 e 15 do console, na coluna 29.
 */
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
	printf("*                        Digite a opï¿½ï¿½o desejada                             *\n");
	printf("*                                                                            *\n");
	printf("*                           [ ] Login                                        *\n");
	printf("*                           [ ] Cadastro                                     *\n");
	printf("*                           [ ] Exit                                         *\n");
	printf("*                                                                            *\n");
	printf("**  Use as [setas] do teclado para se movimenar e [enter] para selecionar   **\n");
	printf(" **************************************************************************** \n");
}

/**
 * @brief Limpa o console e desenha a tela inicial (Administrador ou Usuário).
 *
 * As opções ficam nas linhas 13 e 14 do console, na coluna 29.
 */
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
	printf("*          Por favor selecione a opï¿½ï¿½o que se refere a quem voce e:          *\n");
	printf("*                                                                            *\n");
	printf("*                           [ ] Administrador                                *\n");
	printf("*                           [ ] Usuario                                      *\n");
	printf("*                                                                            *\n");
	printf("*                                                                            *\n");
	printf("**  Use as [setas] do teclado para se movimenar e [enter] para selecionar   **\n");
	printf(" **************************************************************************** \n");
}

/**
 * @brief Limpa o console e desenha o menu do administrador.
 *
 * As opções Cadastrar Prêmios, Sortear Vencedores e Sair ficam nas linhas
 * 13, 14 e 15 do console, na coluna 29.
 */
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
	printf("*      Olï¿½ Administrador! Por favor, Selecione o que deseja realizar...      *\n");
	printf("*                                                                            *\n");
	printf("*                           [ ] Cadastrar Prï¿½mios                            *\n");
	printf("*                           [ ] Sortear Vencedores                           *\n");
	printf("*                           [ ] Sair                                         *\n");
	printf("*                                                                            *\n");
	printf("**  Use as [setas] do teclado para se movimenar e [enter] para selecionar   **\n");
	printf(" **************************************************************************** \n");
}

/**
 * @brief Limpa o console e desenha a cartela com os 108 números.
 *
 * Os números são exibidos com três dígitos, em 6 linhas de 18 colunas, a
 * partir da linha 2 do console. Cada número ocupa 4 colunas, começando na
 * coluna 4. Abaixo da cartela são exibidas as opções de reserva, compra e
 * saída.
 */
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

/**
 * @brief Tela de cadastro de prêmios (não implementada).
 *
 * O cadastro de prêmios é feito diretamente em main().
 *
 * @param pre1 Descrição do 1º prêmio.
 * @param pre2 Descrição do 2º prêmio.
 * @param pre3 Descrição do 3º prêmio.
 * @param pre4 Descrição do 4º prêmio.
 * @param pre5 Descrição do 5º prêmio.
 */
void telaCadastroPremios(char pre1[], char pre2[], char pre3[], char pre4[], char pre5[])
{
}

/**
 * @brief Exibe a tela inicial e aguarda a escolha do perfil.
 *
 * O cursor (@) é movido com as setas para cima e para baixo; Enter confirma.
 *
 * @return Linha selecionada: 13 para Administrador ou 14 para Usuário.
 */
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

/**
 * @brief Exibe o menu do administrador e aguarda a escolha de uma opção.
 *
 * O cursor (@) é movido com as setas para cima e para baixo; Enter confirma.
 *
 * @return Linha selecionada: 13 para Cadastrar Prêmios, 14 para Sortear
 *         Vencedores ou 15 para Sair.
 */
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

/**
 * @brief Ponto de entrada: inicializa a cartela e executa o fluxo de menus.
 *
 * Fluxo principal:
 * 1. Tela inicial: escolha entre Administrador e Usuário.
 * 2. Administrador: cadastra até cinco prêmios ou sorteia os vencedores e
 *    volta à tela inicial.
 * 3. Usuário: faz o cadastro ou o login. Depois do login, navega pela cartela
 *    com as setas e digita 1 para reservar, 2 para comprar ou 0 para sair.
 *
 * Estruturas de dados locais:
 * - matriztests: número da rifa (1 a 108) em cada posição da cartela.
 * - matrizstats: situação de cada número para todos os usuários
 *   (0 = livre, 1 = reservado, 2 = comprado). É atualizada com as escolhas
 *   do usuário quando ele digita 0 para sair da cartela.
 * - pessoas[i].matrizpessoal: escolhas de cada usuário, com os mesmos códigos.
 * - vetorDP: para cada número comprado, a posição do comprador mais 1.
 *   Observação: grava posicaoAtual (total de cadastrados), e não o índice do
 *   usuário logado.
 * - vetorb: os cinco números sorteados.
 *
 * O sorteio considera apenas números comprados (situação 2) e não repete
 * números.
 */
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
						printf("*                            *Cadastrar Prï¿½mios*                             *\n");
						printf("*                             *****************                              *\n");
						printf("*                                                                            *\n");
						printf("*                                                                            *\n");
						printf("*                                                                            *\n");
						printf("* Digite o 1ï¿½ Prï¿½mio ï¿½ Cadastrar:                                            *\n");
						printf("*                                                                            *\n");
						printf("* Digite o 2ï¿½ Prï¿½mio ï¿½ Cadastrar:                                            *\n");
						printf("*                                                                            *\n");
						printf("* Digite o 3ï¿½ Prï¿½mio ï¿½ Cadastrar:                                            *\n");
						printf("*                                                                            *\n");
						printf("* Digite o 4ï¿½ Prï¿½mio ï¿½ Cadastrar:                                            *\n");
						printf("*                                                                            *\n");
						printf("* Digite o 5ï¿½ Prï¿½mio ï¿½ Cadastrar:                                            *\n");
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
						printf("\n Os premios cadastrados foram: 1ï¿½ %s\n, \t\t\t       2ï¿½ %s\n, \t\t\t       3ï¿½ %s\n, \t\t\t       4ï¿½ %s\n, \t\t\t       5ï¿½ %s", pre1, pre2, pre3, pre4, pre5);
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
											printf("\n* 1ï¿½ Prï¿½mio: %s - Nï¿½mero Sorteado: [%i] Vencedor [%s]", pre1, matriztests[numer1][numer2], pessoas[c].nome);
										}
										if (contsort == 1)
										{
											gotoxy(5, 11);
											printf("\n* 2ï¿½ Prï¿½mio: %s - Nï¿½mero Sorteado: [%i] Vencedor [%s]", pre2, matriztests[numer1][numer2], pessoas[c].nome);
										}
										if (contsort == 2)
										{
											gotoxy(5, 12);
											printf("\n* 3ï¿½ Prï¿½mio: %s - Nï¿½mero Sorteado: [%i] Vencedor [%s]", pre3, matriztests[numer1][numer2], pessoas[c].nome);
										}
										if (contsort == 3)
										{
											gotoxy(5, 13);
											printf("\n* 4ï¿½ Prï¿½mio: %s - Nï¿½mero Sorteado: [%i] Vencedor [%s]", pre4, matriztests[numer1][numer2], pessoas[c].nome);
										}
										if (contsort == 4)
										{
											gotoxy(5, 14);
											printf("\n* 5ï¿½ Prï¿½mio: %s - Nï¿½mero Sorteado: [%i] Vencedor [%s]", pre5, matriztests[numer1][numer2], pessoas[c].nome);
										}
									}

									if (cadpremio == 0)
									{
										if (contsort == 0)
										{
											gotoxy(5, 10);
											printf("\n* 1ï¿½ Nï¿½mero Sorteado: [%i] Vencedor [%s]", matriztests[numer1][numer2], pessoas[c].nome);
										}
										if (contsort == 1)
										{
											gotoxy(5, 11);
											printf("\n* 2ï¿½ Nï¿½mero Sorteado: [%i] Vencedor [%s]", matriztests[numer1][numer2], pessoas[c].nome);
										}
										if (contsort == 2)
										{
											gotoxy(5, 12);
											printf("\n* 3ï¿½ Nï¿½mero Sorteado: [%i] Vencedor [%s]", matriztests[numer1][numer2], pessoas[c].nome);
										}
										if (contsort == 3)
										{
											gotoxy(5, 13);
											printf("\n* 4ï¿½ Nï¿½mero Sorteado: [%i] Vencedor [%s]", matriztests[numer1][numer2], pessoas[c].nome);
										}
										if (contsort == 4)
										{
											gotoxy(5, 14);
											printf("\n* 5ï¿½ Nï¿½mero Sorteado: [%i] Vencedor [%s]", matriztests[numer1][numer2], pessoas[c].nome);
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

						TelaLoginCadastro(); // Tela com as opï¿½ï¿½es de loguin e cadastro

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

					printf("ERRO, o numero selecionado nï¿½o esta disponivel ou ja foi alugado por vocï¿½");

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

					printf("ERRO, o numero selecionado nï¿½o esta disponivel");

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
