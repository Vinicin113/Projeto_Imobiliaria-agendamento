# 🏢 Imobiliária - Agendamento de Avaliações

Projeto final da disciplina de **Linguagem de Programação 1**. O objetivo é implementar um sistema capaz de gerar automaticamente uma agenda de avaliações de imóveis, distribuindo-os entre corretores avaliadores de forma eficiente e organizada.

---

## 📋 Descrição

O programa:

- Lê informações de corretores, clientes e imóveis da entrada padrão.
- Distribui os imóveis entre os avaliadores de forma **round-robin**.
- Gera a agenda de cada corretor considerando:
  - Sua localização inicial.
  - O tempo de deslocamento (cálculo com a fórmula de Haversine).
  - A duração da visita (1h por imóvel).
- Exibe a agenda de avaliações formatada corretamente.

---

## 💡 Como funciona

### ✔️ Entrada esperada

Redirecionamento via terminal:

```bash
./imobiliaria < entrada.txt
```

Formato da entrada:
1. Número de corretores
2. Lista de corretores
3. Número de clientes
4. Lista de clientes
5. Número de imóveis
6. Lista de imóveis

### ✔️ Saída esperada

A agenda dos corretores avaliadores, no formato:

```
Corretor [ID]
HH:MM Imóvel [ID]
...
```

---

## 🔧 Compilação

O projeto pode ser compilado com `g++` 11 ou superior:

### Usando o Makefile:

```bash
make
```

Isso irá gerar o executável chamado:

```
./imobiliaria
```

### Limpar arquivos compilados:

```bash
make clean
```

---

## 🗂️ Estrutura dos Arquivos

```
imobiliaria/
├── corretor.h / .cpp      # Classe Corretor
├── cliente.h / .cpp       # Classe Cliente
├── imovel.h / .cpp        # Classe Imóvel
├── agenda.h / .cpp        # Lógica de agendamento
├── main.cpp               # Leitura da entrada e chamada do sistema
└── Makefile               # Compilação automatizada
```

---

## 📎 Exemplos de Execução

```bash
./imobiliaria < teste1_entrada.txt > minha_saida.txt
diff minha_saida.txt teste1_saida.txt
```

Se o comando `diff` não retornar nada, a saída está correta ✅.

---

## 🧪 Testes

Você pode usar os arquivos de teste fornecidos pelo professor:

- `teste1_entrada.txt`
- `teste2_entrada.txt`
- `teste3_entrada.txt`

E compará-los com as respectivas saídas esperadas:

```bash
diff minha_saidaX.txt testeX_saida.txt
```

---

## ✅ Requisitos Atendidos

- [x] Código modularizado (.h/.cpp)
- [x] Makefile funcional
- [x] Leitura da entrada via `cin`
- [x] Escrita exata no formato da especificação
- [x] Algoritmo de vizinho mais próximo
- [x] IDs autoincrementais
- [x] Formato de hora `HH:MM` com zero à esquerda

---

## 👨‍💻 Autoria

Projeto desenvolvido por:

- [Seu Nome Aqui]
- Disciplina: **Linguagem de Programação 1**
- Curso: Tecnologia da Informação / Ciência da Computação
