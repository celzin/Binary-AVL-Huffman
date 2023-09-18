<div style="display: inline_block">
  <img align="center" alt="VS" src="https://img.shields.io/badge/Visual_Studio_Code-0078D4?style=for-the-badge&logo=visual%20studio%20code&logoColor=white" />
  <img align="center" alt="Linux" src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black" />
  <img align="center" alt="C++" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" />
</div><br>

# ⚠️ Apresentação do Problema 

<div align="justify">
Neste trabalho, o objetivo é criar um sistema que possibilite a funcionalidade de autocompletar e oferecer sugestões de palavras aos usuários de maneira rudimentar. Para atingir essa finalidade, adotaremos a
estrutura da árvore binária como base. A seguir, é apresentado os passos necessários para a implementação.

1. Iniciamos solicitando ao usuário um arquivo denominado "input.data" (inserido na pasta "dataset"), contendo uma lista de 'palavras de pesquisa'. Cada palavra nesse arquivo será considerada como termo de pesquisa para o sistema. As palavras serão separadas por linhas, sendo uma 'palavras de pesquisa' por linha.

2. Utilize a implementação anterior (Heap e Hash) para encontrar a frequência de cada 'palavra de pesquisa' dentre a coleção de textos dentro da pasta "dataset". Mais a frente, o programa deverá mostrar a palavra, sua frequência e o texto que se encontra.

3. Crie um conjunto de árvores binárias a partir do textos previamente fornecidos na pasta "dataset". O objetivo é estabelecer uma relação entre as palavras do texto e as 'palavras de pesquisa'. Essa abordagem consistirá em três etapas diferentes:

	3.1 Árvore Binária Padrão: Implemente uma árvore binária tradicional, selecionando as palavras mais relevantes (top K palavras) e relacionadas à pesquisa feita pela "Heap e Hash" em cada texto. A relevância de uma palavra será determinada por sua frequência e (proximidade à) 'palavra de pesquisa'.
	
	3.2 Árvore AVL: Implemente uma árvore AVL e repita o processo de análise exemplificado com as devidas adaptações da estrutura.
	
	3.3 Codificação de Huffman: Implemente uma estutura de código de Huffman para otimizar a ideia de árvore binária padrão. Calcule códigos para cada palavra e reorganize a estrutura da árvore com base nesses códigos. 

4. Ao final deve ser gerado um arquivo "output.txt" (dentro da pasta "dataset") contendo a pré-ordem de cada umas das 3 estruturas geradas, a 'palavra de pesquisa' juntamente com sua frequência e o texto em que aparece.

5. Compare o (tempo médio de processamento) entre a construção da estrutura e a geração de saída (Huffman) em comparação com as abordagens binária e AVL.

</div>

# 💡 Solução do Problema 

## Funcionamento Geral

<div align="justify">
	
- **Carregamento das Palavras-Chave**: A função `load_search_terms` é responsável por carregar as palavras-chave de um arquivo. O nome do arquivo é passado como argumento e a função retorna um vetor de strings contendo as palavras. Ela usa a biblioteca de E/S de arquivos do C++ `(<fstream>)` para ler o arquivo linha por linha e armazenar cada linha (palavra) em um vetor.

- **Processamento do Conjunto de Dados**: A função `process_dataset_files` é a espinha dorsal do programa. Ela é responsável por processar cada arquivo no diretório de conjuntos de dados. Para fazer isso, ela usa a função opendir para abrir o diretório e `readdir` para ler cada arquivo no diretório. Dentro deste loop, para cada arquivo, uma tabela hash e uma heap são inicializadas. A tabela hash provavelmente armazena a frequência de cada palavra e a heap é usada para armazenar as palavras mais frequentes (top-k palavras).

- **Tratando Top-k+1 Palavras**: Dentro da função `process_dataset_files`, há um tratamento especial para garantir que a palavra pesquisada não apareça nas top-k palavras, mesmo que seja uma das palavras mais frequentes. Para fazer isso, a função primeiro obtém as top-k palavras usando `heap.get_top_k()`. Se a palavra pesquisada estiver entre elas, ela é removida e a próxima palavra mais frequente é adicionada, garantindo que ainda haja k palavras no vetor. Esta lógica garante que a palavra pesquisada não seja contabilizada duas vezes.

</div>

## **Hash e Heap**

<div align="justify">
	
As duas estruturas adotadas seguem a mesma implementação do [trabalho anterior](https://github.com/celzin/Top-K-Itens) com algumas pequenas alterações na estrutura da heap para pegar as "top-K+1-palavras". 

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
	
- Se o valor `int` do novo par for menor (ou igual e a `string` for alfabeticamente menor), ele é posicionado à esquerda.
- Se o valor `int` do novo par for maior, ele é posicionado à direita.

A inserção é uma operação recursiva, o que significa que o método chama a si mesmo até encontrar a posição correta para inserir o novo nó.
</div>

### Travessias:

<div align="justify">
As travessias são métodos que percorrem todos os nós da árvore em uma ordem específica. Existem três métodos de travessia apresentados:

**Pré-ordem**: Neste método, visitamos primeiro a raiz, depois a subárvore da esquerda e, finalmente, a subárvore da direita. Ou seja, o nó atual é processado antes de seus descendentes.

**Em ordem** (In-Order): Nesta travessia, visitamos primeiro a subárvore da esquerda, depois a raiz e, finalmente, a subárvore da direita. Para uma árvore binária de busca, isso resulta em processar os valores em ordem crescente.

**Pós-ordem**: Aqui, visitamos primeiro a subárvore da esquerda, depois a subárvore da direita e, por fim, a raiz. Ou seja, o nó atual é processado após seus descendentes.

Em todos os métodos de travessia, a lógica é implementada recursivamente, assim como a inserção. Para cada método de travessia, há duas funções: uma que serve como ponto de entrada (e retorna os valores em um `vector`) e uma função auxiliar recursiva que faz o trabalho real de travessia.
</div>

## **Árvore AVL**

<div align="justify">
	
A peculiaridade de uma árvore AVL é que, para qualquer nó, as alturas das duas subárvores filho diferem em no máximo uma unidade. Se, em algum momento durante uma inserção (ou remoção), a árvore se torna desequilibrada, ela é automaticamente rebalanceada usando rotações. É uma árvore binária de pesquisa auto-balanceada, o que significa que a cada inserção ou remoção de um nó, ela garante que a altura das subárvores de cada nó diferem em no máximo 1, mantendo assim a árvore aproximadamente balanceada.

</div>

### Classes e Estruturas

- **`AVLNode`**: Representa um nó na árvore AVL.
	- **`data`**: Um par contendo uma string e um inteiro.
	- **`height`**: Altura do nó na árvore.
	- **`left`** e right: Ponteiros para os nós filhos esquerdo e direito, respectivamente.

- **`AVLTree`**: Representa a árvore AVL.
	- **`root`**: Ponteiro para o nó raiz da árvore.

### Funções e Métodos

<div align="justify">
	
- **`AVLNode()`**: Construtor que inicializa o nó com os dados fornecidos e define a altura inicial como 1.

- **`AVLTree()`**: Construtor que inicializa a árvore AVL com a raiz sendo nullptr.

- **`get_height()`**: Retorna a altura de um nó. Se o nó for nullptr, retorna 0.

- **`get_balance()`**: Retorna o fator de balanceamento de um nó, que é a diferença de altura entre a subárvore esquerda e a subárvore direita.

- **`rotate_right()`** e **rotate_left()**: Estas são funções de rotação que são usadas para manter a árvore balanceada. A rotação é realizada com base no fator de balanceamento de um nó.

- **`insert()`**: Esta é a função de inserção recursiva que primeiro realiza uma inserção padrão de árvore binária de pesquisa (BST). Após a inserção, atualiza a altura do nó atual e obtém seu fator de balanceamento. Dependendo do fator de balanceamento, pode ser necessário realizar rotações para balancear a árvore.

- **`pre_order()`**: Uma função recursiva para realizar a travessia pre-order e preencher o vetor resultante com os dados dos nós em ordem pre-order.

</div>

### Funcionamento

<div align="justify">
	
O principal recurso deste código é manter a árvore AVL balanceada a cada inserção. Se a árvore ficar desequilibrada após uma inserção (ou seja, o fator de balanceamento de qualquer nó é maior que 1 ou menor que -1), então uma das quatro rotações (right, left, left-right, right-left) é realizada para rebalancear a árvore.

Resumindo, este código implementa uma árvore AVL com capacidade de inserção e travessia pre-order. O equilíbrio da árvore é mantido através de rotações após cada inserção. O código usa recursividade para inserção e travessias. A complexidade de tempo da inserção em uma árvore AVL é O(log n), onde n é o número de nós.

</div>

## **Codificação de Huffman**

<div align="justify">
  
</div>

# 🔬 Experimentação 

<div align="justify">
	
Testando o funcionamento do programa para o **Top 20 palavras mais frequentes** através da leitura dos arquivos [`input1.txt`](https://github.com/celzin/Top-K-Itens/blob/main/dataset/input1.txt) e [`input2.txt`](https://github.com/celzin/Top-K-Itens/blob/main/dataset/input2.txt) com o acervo de `stopwords` (palavras que são ignoradas ao processar o texto) fornecidos pelo arquivo [`stopwords.txt`](https://github.com/celzin/Top-K-Itens/blob/main/dataset/stopwords.txt) obteve-se a seguinte saída no terminal.

</div>

<p align="center">
<img src="imgs/terminal.png" width="250"/> 
</p>
<p align="center">
<em>Imagem 1: Saída no terminal para os Top 20 elementos mais frequentes. </em>
</p>
	
# 🎯 Conclusão 
	
## Árvore Binária

<div align="justify">

</div>

## Árvore AVL

<div align="justify">

</div>

## Codificação de Huffman

<div align="justify">

</div>

## Funcionamento Geral e Custos Computacionais

<div align="justify">

</div>

# 🔄 Compilação e Execução 

## 1. Arquivos de Leitura

<div align="justify">

O programa foi projetado para processar um conjunto de arquivos de texto (.txt) contidos na pasta [`dataset`](https://github.com/celzin/Top-K-Itens/tree/main/dataset). Então, para o correto funcionamento do programa:

- Certifique-se de incluir os arquivos preferencialmente no formato <code>textoN.txt</code> dentro da pasta [<code>dataset</code>](https://github.com/celzin/Top-K-Itens/tree/main/dataset).
-  Ateste que os arquivos de texto estejam no formato correto (por exemplo, .txt) e que não contenham caracteres inválidos ou não reconhecidos.

</div>

## 2. Arquivo de Entrada (input.data)

<div align="justify">


</div>

## 3. Stopwords

<div align="justify">

O programa também faz uso de um arquivo [`stopwords.txt`](https://github.com/celzin/Top-K-Itens/blob/main/dataset/stopwords.txt). Este arquivo contém palavras que são comumente usadas, mas que geralmente são ignoradas ao processar texto (por exemplo, "e", "o", "de" etc.).

  - Certifique-se de que o arquivo `stopwords.txt` esteja localizado no diretório [`dataset`](https://github.com/celzin/Top-K-Itens/tree/main/dataset).

</div>

## 4. Top K elementos

<div align="justify">

Para alterar o valor de k, para por exemplo, obter as Top 20 palavras mais frequentes basta alterar a seguinte [linha de código](https://github.com/celzin/Top-K-Itens/blob/main/src/main.cpp/#L8):

```C
// Aqui, é possivel alterar o valor de k, por exemplo, top 20 palavras
const int TOP_K = 20;
```

</div>


## 5. Execução

<div align="justify">

Por fim, esse programa possui um arquivo [`Makefile`](https://github.com/celzin/Top-K-Itens/blob/main/Makefile) e um [`CMakeLists`](https://github.com/celzin/Top-K-Itens/blob/main/CMakeLists.txt), os quais realizam todo o procedimento de compilação e execução. Para tanto, cabe ao usuário escolher o de sua preferência, porém se atente ao fato de que para cada um temos as seguintes diretrizes de execução:

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
