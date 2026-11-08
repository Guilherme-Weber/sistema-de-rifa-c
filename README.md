# Sistema de Rifa em C

Sistema de rifa executado no terminal, desenvolvido em linguagem C como trabalho acadêmico para o Projeto Integrador I do Centro Universitário UNIFACEAR (2020).

**Autores:** Guilherme da Luz Weber (Sistemas de Informação) e Érick Alan da Silva (Análise e Desenvolvimento de Sistemas)

**Orientador:** Prof. Rodrigo Bevilacqua Marcondes

A documentação completa do projeto está disponível em [docs/documentacao-projeto-integrador.docx](docs/documentacao-projeto-integrador.docx).

## Descrição

As plataformas de rifa existentes funcionam apenas online e cobram taxas sobre cada transação, o que pode inviabilizar rifas de valores mais baixos. O sistema proposto oferece uma alternativa simples e intuitiva, com gerenciamento local, que depende apenas de um computador: os administradores cadastram os prêmios e realizam o sorteio, enquanto os compradores se cadastram e escolhem os números que desejam comprar ou reservar.

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
- Dev-C++ (ambiente de desenvolvimento)
- Bibliotecas padrão: `stdio.h`, `stdlib.h`, `string.h`, `time.h`, `locale.h`
- API do Windows: `windows.h` (controle do cursor no console) e `conio.h` (leitura do teclado)

## Documentação

O documento em [docs/documentacao-projeto-integrador.docx](docs/documentacao-projeto-integrador.docx) apresenta o processo completo de desenvolvimento: PM Canvas, análise de concorrência, requisitos, regras de negócio, diagrama de casos de uso e protótipo das telas.
