# Sistema de Rifa em C

Projeto Integrador desenvolvido como trabalho acadêmico. Consiste em um sistema de rifa executado no terminal, escrito em linguagem C.

**Autores:** Guilherme da Luz Weber e Erick Alan da Silva

## Descrição

O sistema permite o cadastro de administradores e usuários, a reserva e compra de números em uma cartela de 108 números e o sorteio de vencedores para até cinco prêmios.

### Funcionalidades

- Cadastro e autenticação de usuários (nome, e-mail e senha numérica)
- Cadastro de administrador
- Cartela com 108 números (6 linhas por 18 colunas)
- Reserva e compra de números
- Cadastro de até cinco prêmios pelo administrador
- Sorteio aleatório dos vencedores, com exibição do número sorteado, do prêmio e do ganhador
- Navegação pelos menus com as setas do teclado

## Estrutura do repositório

```
src/rifa.c                                 Código-fonte
bin/rifa.exe                               Executável compilado para Windows
docs/documentacao-projeto-integrador.docx  Documentação do projeto
```

## Requisitos

- Sistema operacional Windows (o código utiliza as bibliotecas `windows.h` e `conio.h`)
- Compilador C, como GCC (MinGW-w64)

## Execução

Executável pré-compilado:

```
bin\rifa.exe
```

Compilação a partir do código-fonte:

```
gcc src/rifa.c -o rifa.exe
rifa.exe
```

O código-fonte está codificado em Windows-1252 (ANSI).

## Utilização

1. Na tela inicial, selecione **Administrador** ou **Usuário** com as setas do teclado e confirme com Enter.
2. **Administrador:** realize o cadastro, registre os prêmios e execute o sorteio dos vencedores.
3. **Usuário:** realize o cadastro e o login. Na cartela de números, digite `1` para reservar, `2` para comprar ou `0` para sair.

## Tecnologias

- Linguagem C
- Bibliotecas padrão: `stdio.h`, `stdlib.h`, `string.h`, `time.h`, `locale.h`
- API do Windows: `windows.h` (controle do cursor no console) e `conio.h` (leitura do teclado)
