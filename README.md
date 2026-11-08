# 🎟️ Sistema de Rifa em C

Sistema de rifa via terminal desenvolvido em **linguagem C** como **Projeto Integrador (PI)**.
Permite cadastrar administradores e usuários, reservar ou comprar números de uma cartela de 108 números e sortear vencedores para até 5 prêmios.

> Autores: **Guilherme da Luz Weber** e **Erick Alan da Silva**

---

## ✨ Funcionalidades

- **Cadastro e login** de usuários (nome, e-mail e senha numérica)
- **Cadastro de administrador** (ADM)
- **Cartela com 108 números** (6 linhas × 18 colunas) exibida no console
- **Reserva** ou **compra** de números pelo usuário
- **Cadastro de até 5 prêmios** pelo administrador
- **Sorteio aleatório** dos vencedores, exibindo número sorteado, prêmio e nome do ganhador
- **Navegação pelos menus com as setas do teclado** e `Enter` para selecionar

## 📁 Estrutura do repositório

```
pi-rifa_em_c/
├── src/
│   └── rifa.c                              # Código-fonte do sistema
├── bin/
│   └── rifa.exe                            # Executável compilado para Windows
├── docs/
│   └── documentacao-projeto-integrador.docx  # Documentação do Projeto Integrador
└── README.md
```

## 🛠️ Requisitos

O programa usa bibliotecas exclusivas do Windows (`windows.h` e `conio.h`), portanto **roda apenas no Windows**.

- Windows
- Compilador C — por exemplo [MinGW-w64 (GCC)](https://www.mingw-w64.org/) ou o compilador do [Dev-C++ / Code::Blocks](https://www.codeblocks.org/)

## ▶️ Como executar

### Opção 1 — Executável pronto

Execute o arquivo [`bin/rifa.exe`](bin/rifa.exe) com dois cliques ou pelo terminal:

```bash
bin\rifa.exe
```

### Opção 2 — Compilar a partir do código-fonte

```bash
gcc src/rifa.c -o rifa.exe
rifa.exe
```

> 💡 O código-fonte usa a codificação **Windows-1252 (ANSI)** para os acentos. Abra-o no editor com essa codificação para que os caracteres apareçam corretamente.

## 🎮 Como usar

1. Na tela inicial, escolha **Administrador** ou **Usuário** usando as setas `↑` `↓` e `Enter`.
2. **Administrador:** faça o cadastro de ADM, cadastre os prêmios e, quando quiser, escolha **Sortear Vencedores**.
3. **Usuário:** faça o **Cadastro** e depois o **Login**. Na cartela de números:
   - `1` → reservar um número
   - `2` → comprar um número
   - `0` → sair
4. No sorteio, o sistema mostra cada prêmio, o número sorteado e o nome do vencedor.

## 🧰 Tecnologias

- Linguagem **C**
- Bibliotecas padrão: `stdio.h`, `stdlib.h`, `string.h`, `time.h`, `locale.h`
- APIs do Windows: `windows.h` (posicionamento do cursor no console) e `conio.h` (leitura de teclas)

## 👥 Autores

| Nome | GitHub |
|------|--------|
| Guilherme da Luz Weber | [@Guilherme-Weber](https://github.com/Guilherme-Weber) |
| Erick Alan da Silva | — |

---

Projeto desenvolvido para fins acadêmicos.
