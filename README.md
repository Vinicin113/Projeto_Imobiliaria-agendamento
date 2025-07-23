# Imobiliária - Agendamento de Avaliações

Projeto final da disciplina de **Linguagem de Programação 1**.
O objetivo é implementar um sistema capaz de gerar automaticamente uma agenda de avaliações de imóveis, distribuindo-os entre corretores avaliadores de forma eficiente e organizada.

---

##  Descrição

O programa:

- Lê informações de corretores, clientes e imóveis da entrada padrão.
- Distribui os imóveis entre os avaliadores de forma **round-robin**.
- Gera a agenda de cada corretor considerando:
- Sua localização inicial.
- O tempo de deslocamento (cálculo com a fórmula de Haversine).
- A duração da visita (1h por imóvel).
- Exibe a agenda de avaliações formatada corretamente.

---

##  Como funciona

###  Entrada esperada

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

###  Saída esperada

A agenda dos corretores avaliadores, no formato:

```
Corretor [ID]
HH:MM Imóvel [ID]
...
```

---

##  Compilação

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

##  Requisitos Atendidos

- [x] Código modularizado (.h/.cpp)
- [x] Makefile funcional
- [x] Leitura da entrada via `cin`
- [x] Escrita exata no formato da especificação
- [x] Algoritmo de vizinho mais próximo
- [x] IDs autoincrementais
- [x] Formato de hora `HH:MM` com zero à esquerda

---

 ## Projeto desenvolvido por:

- Vinicius Marques de Almeida
- Disciplina: **Linguagem de Programação 1**
- Curso: Tecnologia da Informação 
