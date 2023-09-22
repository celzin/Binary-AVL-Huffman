<div align="center" style="display: inline_block">
  <img align="center" alt="VS" src="https://img.shields.io/badge/Visual_Studio_Code-0078D4?style=for-the-badge&logo=visual%20studio%20code&logoColor=white" />
  <img align="center" alt="Linux" src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black" />
  <img align="center" alt="C++" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" />
</div>

<h1 align="center">
    <a>
        <img alt="Banner" title="#Banner" style="object-fit: fill; height:200px;" src="imgs/header-image.png" />
    </a>
</h1>

# 📌 Sumário

>1. [⚠️ Apresentação do Problema ](#%EF%B8%8F-apresentação-do-problema)
>2. [💡 Solução do Problema ](#-solu%C3%A7%C3%A3o-do-problema)
>		* [Hash e Heap](#hash-e-heap)
>		* [Carregamento das Palavras-de-Pesquisa](#carregamento-das-palavras-de-pesquisa)
>		* [Árvore Binária](#%C3%A1rvore-bin%C3%A1ria)
>		* [Árvore AVL](#%C3%A1rvore-avl)
>		* [Codificação de Huffman](#codifica%C3%A7%C3%A3o-de-huffman)
>		* [Processamento do Conjunto de Dados](#processamento-do-conjunto-de-dados)
>4. [🔬 Experimentação](#-experimenta%C3%A7%C3%A3o)
>5. [🎯 Conclusão](#-conclus%C3%A3o)
>6. [🔄 Compilação e execução](#-compila%C3%A7%C3%A3o-e-execu%C3%A7%C3%A3o)
>7. [📞 Contato](#-contato)

# ⚠️ Apresentação do Problema 

<div align="justify">
Neste trabalho, o objetivo é criar um sistema que possibilite a funcionalidade de autocompletar e oferecer sugestões de palavras aos usuários de maneira rudimentar. Para atingir essa finalidade, adotaremos a estrutura da árvore binária como base. A seguir, é apresentado os passos necessários para a implementação.

- Iniciamos solicitando ao usuário um arquivo denominado `input.data` (inserido na pasta `dataset`), contendo uma lista de _'palavras de pesquisa'_. Cada palavra nesse arquivo será considerada como termo de pesquisa para o sistema. As palavras serão separadas por linhas, sendo uma _'palavras de pesquisa'_ por linha.

- Utilize a implementação anterior (`Heap` e `Hash`) para encontrar a frequência de cada _'palavras de pesquisa'_ dentre a coleção de textos dentro da pasta `dataset`. Mais a frente, o programa deverá mostrar a palavra, sua frequência e o texto que se encontra.

- Crie um conjunto de árvores binárias a partir do textos previamente fornecidos na pasta `dataset`. O objetivo é estabelecer uma relação entre as palavras do texto e as _'palavras de pesquisa'_. Essa abordagem consistirá em três etapas diferentes:

	- **Árvore Binária Padrão**: Implemente uma árvore binária tradicional, selecionando as palavras mais relevantes (top K palavras) e relacionadas à pesquisa feita pela "Heap e Hash" em cada texto. A relevância de uma palavra será determinada por sua frequência e "proximidade" à _'palavras de pesquisa'_.
	
 	- **Árvore AVL**: Implemente uma árvore AVL e repita o processo de análise exemplificado com as devidas adaptações da estrutura.
	
	- **Codificação de Huffman**: Implemente uma estutura de código de Huffman para otimizar a ideia de árvore binária padrão. Calcule códigos para cada palavra e reorganize a estrutura da árvore com base nesses códigos. 

- Ao final deve ser gerado um arquivo `output.txt` (dentro da pasta `dataset`) contendo a pré-ordem de cada umas das 3 estruturas geradas, a _'palavras de pesquisa'_ juntamente com sua frequência e o texto em que aparece.

- Compare o (tempo médio de processamento) entre a construção da estrutura e a geração de saída (Huffman) em comparação com as abordagens binária e AVL.

</div>

# 💡 Solução do Problema 

## **Hash e Heap**

<div align="justify">
	
As estruturas de Tabela `Hash` e `Heap` adotadas permaneceram práticamente inaltaredas em relação a [implementação anterior](https://github.com/celzin/Top-K-Itens), com algumas alterações para resolução do escopo do problema. As alterações na estrutura `Heap` consistem na inserção dos _'top-k+1 elementos'_ na _heap_ e da adição da função `get_top_k_words_with_removal`. Esta função obtém os _'top-k+1 elementos'_ do _heap_ e verifica se a _'palavra-pesquisada'_ está entre eles. Se estiver, ela é removida. Caso contrário, o último elemento (que seria o _'top-k+1'_) é removido. O vetor resultante com as top-k palavras é retornado. 

</div>

## Carregamento das Palavras-de-Pesquisa

<div align="justify">
	
A função `load_search_terms` é responsável por carregar as _palavras-chave_ de um arquivo. O nome do arquivo é passado como argumento e a função retorna um vetor de strings contendo as palavras. Ela usa a biblioteca de E/S de arquivos do C++ `(<fstream>)` para ler o arquivo linha por linha e armazenar cada linha (palavra) em um vetor

</div>

## **Árvore Binária**

<div align="justify">
	
A árvore binária é uma estrutura de dados hierárquica que possui um elemento central chamado de raiz, a partir do qual se desdobram dois possíveis subárvores, comumente chamadas de subárvore da esquerda e subárvore da direita. Cada elemento da árvore é armazenado em um "nó". O nó tem um valor e dois ponteiros, um para o nó à esquerda e outro para o nó à direita.

Neste código, cada nó armazena um par de valores - uma `string` e um `int`. A organização dos nós na árvore é determinada pelo valor `int` do par. Se dois pares tiverem o mesmo valor `int`, a ordenação é então determinada pela `string`.

</div>

### Construtor:

<div align="justify">
	
Ao construir um objeto da classe `BinaryTree`, a raiz da árvore é inicialmente definida como nula (`nullptr`), indicando que a árvore está vazia.

</div>

### Inserção:

<div align="justify">
	
O método de inserção permite adicionar um novo par `(string, int)` à árvore. A lógica de inserção verifica o valor `int` do par para determinar se o novo nó deve ser posicionado à esquerda ou à direita do nó atual:

**Política de Inserção**:

- Se o valor `int` do novo par for menor (ou igual e a `string` for alfabeticamente menor), ele é posicionado à esquerda.
- Se o valor `int` do novo par for maior, ele é posicionado à direita.

A inserção é uma operação recursiva, o que significa que o método chama a si mesmo até encontrar a posição correta para inserir o novo nó.

</div>

### Travessias:

<div align="justify">

As travessias são métodos que percorrem todos os nós da árvore em uma ordem específica. Existem três métodos de travessia apresentados:

**Pré-ordem**(`pre_order`): Neste método, visitamos primeiro a raiz, depois a subárvore da esquerda e, finalmente, a subárvore da direita. Ou seja, o nó atual é processado antes de seus descendentes.

**Em ordem**(`in_order`): Nesta travessia, visitamos primeiro a subárvore da esquerda, depois a raiz e, finalmente, a subárvore da direita. Para uma árvore binária de busca, isso resulta em processar os valores em ordem crescente.

**Pós-ordem**(`post_order`): Aqui, visitamos primeiro a subárvore da esquerda, depois a subárvore da direita e, por fim, a raiz. Ou seja, o nó atual é processado após seus descendentes.

Em todos os métodos de travessia, a lógica é implementada recursivamente, assim como a inserção. Para cada método de travessia, há duas funções: uma que serve como ponto de entrada (e retorna os valores em um `vector`) e uma função auxiliar recursiva que faz o trabalho real de travessia.

</div>

### Custos Computacionais

- Inserção: Depende diretamente da estrutura da árvore no momento. No pior caso, ela se comporta linearmente, O(n), se a árvore degrada para uma lista encadeada.

- Travessias (`pre_order`, `in_order`, `post_order`): Visitam todos os nós uma vez, resultando em um custo O(n).

## **Árvore AVL**

<div align="justify">
	
Uma árvore AVL é uma árvore binária de busca auto-balanceada. Em qualquer ponto de inserção ou remoção, a árvore AVL garante que a diferença de alturas entre as subárvores esquerda e direita (chamada de fator de balanceamento) de qualquer nó não exceda 1.

</div>

### Estrutura do Nó AVL (`AVLNode`):

<div align="justify">
	
Quando a árvore AVL é inicialmente criada, ela não possui raiz (`root` é `nullptr`).

</div>

### Altura:

<div align="justify">
	
A função `get_height` retorna a altura de um determinado nó. Se o nó for nulo, retorna 0.

</div>

### Balanceamento:

<div align="justify">
	
A função `get_balance` retorna o fator de balanceamento de um nó, que é a diferença de altura entre a subárvore esquerda e a subárvore direita.

**Política de Balanceamento**:

1. Prioridade ao `int`: O valor inteiro (data.second) tem a prioridade primária na determinação da posição do nó. Se o valor inteiro do novo nó é menor que o do nó atual, ele vai para a esquerda; se é maior, vai para a direita.
2. Desempate com `string`: Se os valores inteiros são iguais (data.second é o mesmo para ambos os nós), a decisão é tomada com base na string (data.first). Se a string do novo nó é lexicograficamente menor que a do nó atual, ele vai para a esquerda; se é maior, vai para a direita.

</div>

### Rotações:

<div align="justify">

Existem quatro cenários possíveis que requerem rotações para manter a árvore balanceada:

1. **Rotação à direita** (`rotate_right`): É realizada quando uma subárvore se torna pesada à esquerda (left-heavy). O nó pesado à esquerda (`y`) é deslocado para baixo e para a direita, enquanto o filho esquerdo desse nó (`x`) é deslocado para cima e se torna a nova raiz da subárvore rotacionada.
   
2. **Rotação à esquerda** (`rotate_left`):: É realizada quando uma subárvore se torna pesada à direita (right-heavy). O nó pesado à direita (`x`) é deslocado para baixo e para a esquerda, enquanto o filho direito desse nó (`y`) se desloca para cima e se torna a nova raiz da subárvore rotacionada.
   
3. **Rotação à esquerda e depois à direita** (`rotate_left` **+** `rotate_right`): É aplicada quando a subárvore esquerda se torna right-heavy. Primeiro, a subárvore esquerda é rotacionada à esquerda para transformar o problema em um cenário left-heavy. Em seguida, é aplicada uma rotação à direita na raiz.
   
4. **Rotação à direita e depois à esquerda** (`rotate_right` **+** `rotate_left`): É aplicada quando a subárvore direita se torna left-heavy. Primeiro, a subárvore direita é rotacionada à direita para transformar o problema em um cenário right-heavy. Depois, é aplicada uma rotação à esquerda na raiz.

Essas rotações garantem que a árvore permaneça balanceada após cada operação de inserção, mantendo assim a eficiência das operações.

</div>

### Inserção:

O processo de inserção na AVL começa como uma inserção padrão de árvore binária de busca (BST). Após a inserção, a árvore pode se tornar desbalanceada. Assim, o código verifica o fator de balanceamento para decidir que tipo de rotação é necessário.

Após a inserção padrão BST, a altura do nó é atualizada. O fator de balanceamento é então calculado e, com base nele, a árvore é balanceada usando uma das rotações mencionadas acima.

<div align="justify">

</div>

### Travessia Pré-ordem:

<div align="justify">
	
Assim como na árvore binária tradicional, a travessia pré-ordem visita a raiz, depois a subárvore esquerda e, por fim, a subárvore direita. Ela retorna os nós em um vetor na ordem em que foram visitados.

Em resumo, a AVLTree é uma estrutura de dados que garante que a árvore permaneça balanceada após cada operação de inserção ou remoção. Isso é importante porque garante que as operações na árvore (como inserção, exclusão e busca) ocorram em tempo logarítmico, tornando-a eficiente.

</div>

### Custos Computacionais

- Inserção: A AVL garante que a árvore permaneça balanceada, portanto, o custo da inserção (incluindo possíveis rotações) é O(logn).

- Travessia (`pre_order`): Semelhante à Árvore Binária de Busca, a travessia visita todos os nós uma vez, levando a um custo O(n).

## **Codificação de Huffman**

<div align="justify">
	
É, basicamente, uma árvore especializada para compressão de dados. Seu objetivo não é suportar operações de inserção ou busca eficientes, mas sim representar dados de forma compacta.

</div>

### Estrutura do Nó de Huffman

<div align="justify">

`Huffman Node` é a estrutura básica para representar um nó na Árvore de Huffman. Ela tem:

- `word`: Uma palavra ou caractere a ser codificado.
- `frequency`: A frequência da palavra ou caractere nos dados.
- `left` e `right`: Ponteiros para os nós filhos.

Cada nó tem uma `word` (palavra), uma `frequency` (frequência da palavra), e ponteiros para seus filhos `left` e `right`. Há um construtor para inicializar o nó com uma palavra e frequência e um destrutor que deleta os filhos do nó. O destrutor (`~HuffmanNode`) garante que, quando um nó é destruído, seus nós filhos também são destruídos, evitando vazamentos de memória.

</div>

### Estrutura de Comparação:

<div align="justify">
	
A estrutura `Compare` é definida para criar um critério de comparação para os nós. É usada para garantir que o nó com menor frequência seja sempre o topo do min-heap. Se dois nós tiverem a mesma frequência, o operador de comparação não define explicitamente qual virá primeiro.

</div>

### Construção da Árvore de Huffman:

<div align="justify">
	
A função `build_huffman_tree` constrói a Árvore de Huffman usando um min-heap.

1. **Min-Heap**: A função inicia com a criação de um min-heap, uma estrutura que mantém o elemento de menor valor no topo. Neste contexto, usamos frequências para determinar essa ordem.

2. **Preenchendo o Min-Heap**: Para cada par palavra-frequência na lista `top_k`, cria-se um nó de Huffman e insere-o no min-heap.

3. **Construção da Árvore**:
	- Enquanto houver mais de um nó no min-heap:
		- Retira-se os dois nós de menor frequência (nós `left` e `right`).
		- Se tiverem a mesma frequência, mas a palavra do `left` for lexicograficamente maior que a do `right`, eles são trocados.
		- Cria-se um novo nó `merged`, cuja frequência é a soma das frequências de `left` e `right`, e define-se `left` e `right` como seus filhos.
		- Insere-se o nó `merged` de volta no min-heap.
	- O processo se repete até sobrar apenas um nó, a raiz da Árvore de Huffman.

**Resultado**: A função retorna a raiz da Árvore de Huffman construída.

</div>

### Geração dos Códigos de Huffman:

<div align="justify">
	
`generate_huffman_codes` é uma função recursiva que gera códigos Huffman para cada palavra ou caractere na Árvore de Huffman.

Ela navega pela árvore, adicionando "0" ao código quando vai para a esquerda e "1" quando vai para a direita.

Quando chega a um nó folha (um nó que tem uma palavra/caractere), ela associa o código gerado a essa palavra no mapa huffmanCodes.

</div>

### Travessia em Pré-ordem na Árvore de Huffman:

<div align="justify">
	
A função `pre_order_huffman` coleta as palavras e seus códigos de Huffman em uma travessia em pré-ordem da árvore.
O resultado é um vetor de pares, onde o primeiro elemento do par é uma palavra e o segundo é o código de Huffman correspondente.

</div>

### Tempos Computacionais

- Construção: Usa um min-heap, e cada inserção ou remoção do min-heap pode ser feita em O(logn). Como a árvore é construída inserindo e removendo dois elementos do heap em cada iteração até que o heap contenha apenas um elemento (a raiz da Árvore de Huffman), o custo total é O(nlogn).

- Geração de Códigos: A geração de códigos percorre todos os nós da árvore exatamente uma vez, resultando em um custo O(n).
  
## **Processamento do Conjunto de Dados** 

<div align="justify">
	
A função `process_dataset_files` é a espinha dorsal do programa. Ela é responsável por processar cada arquivo no diretório de conjuntos de dados. Para fazer isso, ela usa a função opendir para abrir o diretório e `readdir` para ler cada arquivo no diretório. Dentro deste loop, para cada arquivo, uma tabela hash e uma heap são inicializadas.

- **Inicializa** estruturas: **tabela hash**, **heap**, árvores **binária**, **AVL** e **Huffman**.
- **Processa** cada arquivo no diretório, atualizando a tabela hash com palavras e frequências.
- **Extrai** as palavras mais frequentes para o heap e ajusta esse heap removendo os termos de pesquisa, se presentes.
- **Preenche** as três árvores com as palavras mais frequentes.
- **Registra** no arquivo de saída: termo de pesquisa, frequência, palavras frequentes, percurso de pré-ordem para cada árvore e tempos de inserção.
- **Medição de Tempo**: Durante o processamento das árvores, o tempo de inserção é medido e registrado.

</div>

# 🔬 Experimentação 

<div align="justify">

- **Obs.**: Utilizou-se o acervo de `stopwords` (palavras que são ignoradas ao processar o texto) fornecidos pelo arquivo [`stopwords.txt`]().

- Analisando o texto **"filosofia.txt"** com ênfase na `palavra de pesquisa` **"teoria"** e buscando as **top 10 palavras mais relevantes** no arquivo obteve-se a seguinte saída no terminal:

</div>

<p align="center">
<img src="imgs/teoria.png" width="600"/> 
</p>
<p align="center">
<em>Imagem 1: . </em>
</p>

- A frente será mostrada a confirmação da saída resultante esperada dada a entrada fornecida. 

## Conferindo a travessia das Árvores:

### Inserção das 'top-k-palavras'

Segue o vetor de **palavras** e suas respectivas **frequências** na ordem em que serão inseridos nas árvores:

```C
|-------------------------- Top-k-Palavras --------------------------|
{sentido(111), sobre(114), modo(129), sistema(119), segundo(114), 
sujeito(154), condição(133), mundo(144), priori(144), pensamento(115)}
```
<p align="center">
<em>Trecho 1: Output resultante das Top-10-palavra mais relevantes do texto.</em>
</p>

### Árvore Binária

```C
|------------------ Pré-Ordem-Binária -----------------|
{sentido (111), sobre (114), segundo (114), modo (129), sistema (119), 
pensamento (115), sujeito (154), condição (133), mundo (144), priori (144)}
```
<p align="center">
<em>Trecho 2: Output resultante da Pré-Ordem para Árvore Binária.</em>
</p>

Montando a estrutura de Àrvoré Binária "à mão" para conferir a coerência do output.

<p align="center">
<img src="imgs/arvoreb.png" width="400"/> 
</p>
<p align="center">
<em>Imagem 1: Montagem esquemática da Árvore Binária resultante. </em>
</p>

### Árvore AVL

```C
|------------------- Pré-Ordem-AVL --------------------|
{modo (129), sobre (114), sentido (111), segundo (114), sistema (119), 
pensamento (115), mundo (144), condição (133), sujeito (154), priori (144), }
```
<p align="center">
<em>Trecho 3: Output resultante da Pré-Ordem para Árvore AVL.</em>
</p>

Montando estrutura de Àrvoré AVL "à mão" com 3 inserções por vez para conferir a coerência do output.

<p align="center">
<img src="imgs/insertavl1.png" width="400"/> 
</p>
<p align="center">
<em>Imagem 2: Montagem esquemática da Árvore AVL resultante. </em>
</p>

<p align="center">s
<img src="imgs/insertavl2.png" width="500"/> 
</p>
<p align="center">
<em>Imagem 3: Montagem esquemática da Árvore AVL resultante. </em>
</p>

### Codificação de Huffman

Utilizando o site [Huffman Calculator](planetcalc.com/24811/) para montar e gerar a estrutura de Huffman, a fim de conferir o funcionamento da codifição de Huffman implementada.

<p align="center">
<img src="imgs/huffman1.png" width="900"/> 
</p>
<p align="center">
<em>Imagem 4: Inserção de nome e valor para codifição de huffman </em>
</p>

<p align="center">
<img src="imgs/huffman2.png" width="900"/> 
</p>
<p align="center">
<em>Imagem 5: Tabela de codificação resultante com os valores dos códigos a sua respectiva palavra </em>
</p>

```C
|----------------- Códigos de Huffman -----------------|
        | sistema -> 000
        | modo -> 001
        | condição -> 010
        | priori -> 011
        | mundo -> 100
        | sujeito -> 101
        | sentido -> 1100
        | sobre -> 1101
        | segundo -> 1110
        | pensamento -> 1111
```
<p align="center">
<em>Trecho 4: Output resultante da Pré-Ordem para Árvore AVL.</em>
</p>

### Tempos das Estruturas

```C
( Tempo Binária: 72 microssegundos )
( Tempo AVL: 76 microssegundos )
( Tempo Huffman: 135 microssegundos )
```
<p align="center">
<em>Trecho 5: Output resultante dos Tempos de execução de cada estrutura</em>
</p>

1. Árvore **Binária** de Busca (BST):
	- Tempo de Execução: 72 microssegundos
	- Análise: Rápida, mas sua eficiência pode variar com base na ordem de inserção.

2. Árvore **AVL**:
	- Tempo de Execução: 76 microssegundos
	- Análise: Ligeiramente mais lenta que a BST devido ao balanceamento automático após cada inserção.

3. Árvore de **Huffman**:
	- Tempo de Execução: 135 microssegundos
	- Análise: Mais demorada porque constrói com base em frequências e gera códigos únicos para cada palavra.

# 🎯 Conclusão 

## Árvore Binária de Busca 

<div align="justify">
	
Permite buscas rápidas, inserções e deleções em um conjunto ordenado de itens. As operações têm um tempo de execução médio bastante eficiente, especialmente se os dados estiverem bem distribuídos. Porém, se os dados forem inseridos de maneira não balanceada (por exemplo, em ordem crescente), a árvore pode se degenerar em uma lista vinculada, tornando as operações ineficientes.

</div>

## Árvore AVL

<div align="justify">
	
Supera a principal desvantagem da BST, garantindo que a árvore esteja sempre balanceada. Assim como a BST, inclui inserção, busca e deleção. Devido ao seu auto-balanceamento, a AVL garante que as operações sejam realizadas em tempo logarítmico, independentemente da ordem de inserção dos dados. Porém as operações de inserção e deleção podem ser ligeiramente mais lentas do que em uma BST padrão devido ao custo de rotações adicionais e lógica de balanceamento..

</div>

## Árvore de Huffman:

<div align="justify">
	
Tem como objetivo a compressão de dados. A ideia central é codificar dados frequentes com códigos mais curtos e dados menos frequentes com códigos mais longos.
Operações Típicas: construção da árvore e geração de códigos. Fornece uma codificação eficiente, reduzindo o tamanho do dado codificado. Porém a eficiência da compressão depende da distribuição de frequência dos dados.

</div>

## Desfecho e Custos

<div align="justify">
	
A **BST** tem uma implementação simples, mas sua eficiência pode ser comprometida se a árvore se tornar desbalanceada. Isso pode levar a operações de inserção e busca menos eficientes no pior caso.

A **AVL**, embora ligeiramente mais lenta que a BST para inserções, garante tempos de busca consistentemente rápidos devido ao seu balanceamento, mantendo suas operações eficientes (em termos logarítmicos), porém, essa eficiência vem ao custo de rotações adicionais e lógica de balanceamento.

A **Huffman** é especializada na codificação de informações com base na frequência, e, como resultado, é mais demorada em termos de construção. No entanto, o benefício é uma representação compacta das palavras, o que pode ser valioso em aplicações de compressão. O custo computacional para construí-la, na implementação atual, é predominantemente dominado pela construção do _min-heap_.

Assim, a escolha entre essas estruturas depende fortemente do problema específico que você está tentando resolver e das garantias de desempenho que você precisa.

</div>

# 🔄 Compilação e Execução 

## 1. Arquivos de Leitura

<div align="justify">

O programa foi projetado para processar um conjunto de arquivos de texto (.txt) contidos na pasta (`dataset`). Então, para o correto funcionamento do programa:

- Certifique-se de incluir os arquivos preferencialmente no formato <code>textoN.txt</code> dentro da pasta (`dataset`).
-  Ateste que os arquivos de texto estejam no formato correto (por exemplo, .txt) e que não contenham caracteres inválidos ou não reconhecidos.

</div>

## 2. Arquivo de Entrada - 'Palavras de Pesquisa' (`input.data`)

<div align="justify">

É também essencial que o usuário inclua um arquivo denominado `input.data` (dentre a coleção de textos inserida na pasta (`dataset`), contendo uma lista de _'palavras de pesquisa'_.

 - Cada palavra nesse arquivo será considerada como termo de pesquisa para o sistema.
 
 - As palavras serão separadas por linhas, sendo uma _'palavras de pesquisa'_ por linha.

</div>

## 3. Stopwords

<div align="justify">

O programa também faz uso de um arquivo (`stopwords.txt`). Este arquivo contém palavras que são comumente usadas, mas que geralmente são ignoradas ao processar texto (por exemplo, "e", "o", "de" etc.).

  - Certifique-se de que o arquivo `stopwords.txt` esteja localizado no diretório (`dataset`).

</div>

## 4. Top K elementos

<div align="justify">

Para alterar o valor de k, para por exemplo, obter as Top 20 palavras mais frequentes basta alterar a seguinte [linha de código](https://github.com/celzin/Binary-AVL-Huffman/blob/main/src/include/constants.hpp#L7):

```C
// Aqui, é possivel alterar o valor de k, por exemplo, top 20 palavras
const int TOP_K = 20;
```

</div>


## 5. Execução

<div align="justify">

Por fim, esse programa possui um arquivo (`Makefile`) e um (`CMakeLists`), os quais realizam todo o procedimento de compilação e execução. Para tanto, cabe ao usuário escolher o de sua preferência, porém se atente ao fato de que para cada um temos as seguintes diretrizes de execução:

</div>

### Makefile

<table align="center">
  <tr>
    <th>Comando</th>
    <th>Função</th>
  </tr>
  <tr>
    <td>make clean</td>
    <td>Apaga a última compilação realizada contida na pasta build</td>
  </tr>
  <tr>
    <td>make</td>
    <td>Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build</td>
  </tr>
  <tr>
    <td>make run</td>
    <td>Executa o programa da pasta build após a realização da compilação</td>
  </tr>
</table>
	
### CMake

<table align="center">
  <tr>
    <th>Comando</th>
    <th>Função</th>
  </tr>
  <tr>
    <td>cmake -B ./build</td>
    <td>Cria as instâncias da pasta build necessárias para execução do programa</td>
  </tr>
  <tr>
    <td>cmake --build ./build</td>
    <td>Executa a compilação do programa utilizando o cmake, e o resultado vai para a pasta build</td>
  </tr>
  <tr>
    <td>./build/app</td>
    <td>Executa o programa da pasta build após a realização da compilação</td>
  </tr>
</table>

# 📞 Contato

<table align="center">
  <tr>
    <th>Participante</th>
    <th>Contato</th>
  </tr>
  <tr>
    <td>Celso</td>
    <td><a href="https://t.me/celso_vsf"><img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/> </td>
  </tr>
</table>
