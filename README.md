# C04 - Algoritmos 3 | Inatel

Repositório para armazenar os códigos desenvolvidos durante a disciplina **C04 - Algoritmos 3** do Instituto Nacional de Telecomunicações (Inatel).

---

## Conteúdo da disciplina

### 1. Estratégia de projetos de algoritmos
Revisão de análise de complexidade e técnicas clássicas de projeto:
- força bruta
- estratégia gulosa
- divisão e conquista
- programação dinâmica

---

### 2. Grafos
Definições, terminologia e formas de representação:
- matriz de adjacência
- lista de adjacência

Algoritmos estudados:
- percurso em largura (bfs)
- percurso em profundidade (dfs)
- ordenação topológica 
- árvore geradora mínima (PRIM -> MST)
- caminho mínimo (Dijkstra)

#### Tipos de Grafos
- Direcionados ou não direcionados
- Conexo ou disconexo
- Cíclico ou acíclico
- Simples ou multigrafo
- Completo ou incompleto
- Bipartido, planar, euleriano ou hamiltoniano
- DAG -> Grafo direcionado aciclico (AIRFLOW)

#### Aplicações de Grafos
- Algoritmos de busca
- Análise de redes complexas
- Planejamento de tarefas
- Análise de DNA
- Análise de redes de proteínas
- Simulação de sistemas físicos
- Análise de mercados e fluxo de capital
- Recomendações
- Planejamento de rotas

---

### 3. Árvore
Conceitos e estruturas de dados.

#### Podem ser classificadas em:
- lineares ou não lineares
- homogêneas ou heterogêneas
- estáticas ou dinâmicas

#### Tipo de buscas
    Busca sequencial
        - Nessa estratégia, cada elemento da estrutura de dados é visitado de 
        maneira sequencial (de acordo com a ordem de inserção, por 
        exemplo).
        - Exemplo: Buscar uma carta em um baralho embaralhado.
        - Complexidade: O(n), onde n é a quantidade de elemento

    Busca binária
        - Nessa estratégia, os elementos devem estar previamente ordenados.
        - A busca começa por um elemento central.
        - Caso o elemento buscado seja maior que o elemento central, a busca 
        começa novamente considerando apenas a metade superior da estrutura, ou a metade inferior, caso o elemento seja menor.
        - Exemplo: Buscar uma carta em um baralho ordenado.
        - Complexidade: O(log2 n), onde n é o número de elementos.

    Buscas em estruturas de dados dinâmicas
        - Diferente das estruturas de dados estáticas, as estruturas de dados 
        dinâmicas não são necessariamente lineares.
        - Mesmo quando são lineares (as listas encadeadas, por exemplo),na 
        prática essas estruturas podem dificultar a indexação por posição.
        - Por exemplo, pode ser difícil saber qual é o elemento central.
        - Para isso outras estruturas dinâmicas podem ser usadas para 
        melhorar a eficiência das buscas

#### Árvore
    - É um tipo de estrutura de dados não linear e dinâmica.
    - É um Grafo Acíclico e Direcionado.
    - Armazena os dados de forma hierárquica.

#### Conceitos extras
    - Nó pai, Nó filho
    - Níveis da árvore, ALtura da árvore
    - Nó raiz, Nó internos, Nó folhas
    - Subárvore

#### Árvore Binária
    - É um tipo de árvore onde os nós podem ter no máximo dois filhos 
    (filho da esquerda e filho da direita).
    - É muito utilizada para otimização de buscas.

    - Árvore binária incompleta.
    - Árvore binária quase completa (Nós com menos de dois filhos ficam no último e penúltimo nível da árvore e os nós do último nível ficam o mais à esquerda possível).
    - Árvore binária completa (Nós com menos de dois filhos ficam no último nível da árvore).

#### Árvore Binária de Busca
    - É um tipo de árvore binária que é construída com uma estratégia para facilitara busca binária.

    - A estratégia é já construir a estrutura de maneira ordenada:
        Ao inserir um novo nó, ele é comparado com os nós já existentes; 
        Começando da raiz, se o nó a ser inserido tem valor menor que o nó visitado, ele continua a verificação para a esquerda, senão para a direita;
        Se o nó visitado for um nó folha, o novo nó é inserido à esquerda se o valor for maior, ou à direita se for menor.

    - Complexidade da busca: O(h), onde h é a altura da árvore

#### Complexidade da Árvore Binária de Busca
    - Pode-se perceber que, no pior caso, a complexidade de busca vai ser igual ao número de elementos, ou seja, O(n).

    - Dessa forma, é necessário um mecanismo para garantir a construção da árvore de maneira a se aproximar ao máximo da complexidade da busca binária, ou seja, O(log2 n).

    - As árvores balanceadas são soluções para esse problema.

#### Percursos
    - O algoritmo de varredura em uma árvore binária de busca, assim como em um grafo qualquer, pode ser uma BFS ou uma DFS.

    - Porém, como nessa estrutura de dados temos no máximo dois nós adjacentes (filho da direita e filho da esquerda) temos algumas particularidades em cada um desses algoritmos.

    Percurso em profundidade
        - Nessa varredura, os nós descendentes de um determinado nó são visitados antes do próximo filho de um nó.
        - Pode ocorrer de três formas:
            Pré-ordem;
            Em-ordem;
            Pós-ordem;

#### Operações
    - inserção
    - pesquisa
    - remoção de elementos

#### Percursos
    - em profundidade (dfs)
    - em largura (bfs)

Também inclui:
- destruição de árvores

#### Principais aplicações de árvores
    - Organização hierárquica de dados
        Quando existe relação de “pai → filho”.
        Ex:
        pastas do computador
        organograma de empresa
        árvore genealógica

    - Busca rápida
        Estruturas como Árvore Binária de Busca (BST) permitem buscar, inserir e remover elementos eficientemente (média O(log2 n)).
        Banco de dados / índices (index)
        Bancos usam B-Tree e B+ Tree para indexar dados e acelerar consultas (SELECT, WHERE, etc.).

    - Compiladores
        Código fonte vira uma Árvore Sintática Abstrata (AST) para o compilador interpretar expressões.

---

### 4. Algoritmos geométricos
Introdução à geometria computacional e algoritmo de fecho convexo.