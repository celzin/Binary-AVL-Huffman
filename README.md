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
	
Quando falamos de uma árvore em ciência da computação, estamos nos referindo a uma estrutura de dados hierárquica. Imagine uma árvore genealógica: cada pessoa tem um pai e uma mãe (nós acima) e pode ter vários filhos (nós abaixo). Na árvore binária, cada nó tem, no máximo, dois "filhos": um à esquerda e um à direita.

</div>

### **Estrutura `Node`**

<div align="justify">
	
É a representação de cada pessoa nessa árvore genealógica. Cada `Node` tem informações sobre si mesmo (`data`) e sobre seus filhos à esquerda e à direita. Ele nos permite construir a árvore, formando as conexões entre os nós.

</div>

### **Classe `BinaryTree`**

<div align="justify">
	
É a representação da árvore como um todo. Segue abaixo suas **funções principais** e seu **funcionamento**.

- **`insert`**:

**Objetivo**: Adicionar um novo `Node` (uma nova pessoa) à nossa árvore.

**Funcionamento:** Ao receber um par de dados (nome e número) para ser inserido, ele começa pelo topo da árvore (a `root`). Se a `root` estiver vazia, o novo nó se torna a raiz. Se não, ele decide, com base no valor do número, se deve ir para a esquerda (valores menores) ou direita (valores maiores). Ele repete essa decisão até encontrar o local correto para inserção.

- **Travessias**:

**Objetivo**: "Caminhar" pela árvore e listar os nós em uma ordem específica.

- **`pre_order`**: Imagine que você está dando um passeio na árvore. Primeiro, você olha para onde está (`root`), em seguida, visita a parte esquerda da árvore e, depois, a parte direita.
- **`in_order`**: Nesse passeio, primeiro você visita toda a parte esquerda, depois olha para onde está (`root`) e, por último, visita a parte direita.
- **`post_order`**: Aqui, você começa visitando toda a parte esquerda, depois a direita, e só então olha para o nó em que está.

Essas travessias são como diferentes rotas de passeio pela árvore. Em cada rota, você observa os nós em uma sequência específica. Essa estrutura de árvore binária é como uma árvore genealógica. Cada nó (pessoa) sabe sobre seus "filhos". E temos várias maneiras de passear por essa árvore, vendo os nós em diferentes ordens, graças às travessias. E o método `insert` nos permite adicionar novos membros a essa árvore de forma organizada. O conjunto do código proporciona uma forma visual e estruturada de organizar e acessar dados.

</div>

## **Árvore AVL**

<div align="justify">
A peculiaridade de uma árvore AVL é que, para qualquer nó, as alturas das duas subárvores filho diferem em no máximo uma unidade. Se, em algum momento durante uma inserção (ou remoção), a árvore se torna desequilibrada, ela é automaticamente rebalanceada usando rotações.
</div>

### Detalhes das Funções

<div align="justify">
	
**`AVLNode`**:  Representa um nó na árvore AVL. Cada nó contém um par de dados (uma string e um int), uma altura, e ponteiros para seus nós filhos (esquerdo e direito).
O construtor de `AVLNode` inicializa o nó com os dados fornecidos, configura a altura inicial como 1 e define ambos os filhos como `nullptr`.
	
- `AVLTree`: Representa a árvore AVL.
  
- Construtor de AVLTree: Inicializa a árvore com o nó raiz definido como `nullptr`.

- `get_height`: Retorna a altura de um nó. A altura é usada para determinar o balanceamento da árvore.
  
- `get_balance`: Retorna o fator de balanceamento de um nó, que é a diferença entre as alturas de sua subárvore esquerda e direita. Este valor é usado para decidir se um nó está desbalanceado e que tipo de rotação é necessário.

- **`insert`**: É a interface para inserir um valor na árvore. Ela invoca a versão privada de insert no nó raiz da árvore.

- **`pre_order`**: Realiza uma travessia em pré-ordem, que visita o nó atual primeiro, seguido por sua subárvore esquerda e, finalmente, sua subárvore direita.

**rotate_right e rotate_left**:

As rotações são a essência do rebalanceamento na árvore AVL.

- **`rotate_right`** (Rotação à Direita): Usado quando a subárvore esquerda de um nó torna-se mais alta do que a subárvore direita por mais de uma unidade. Basicamente, a subárvore esquerda torna-se a nova raiz da subárvore, e o nó original move-se para a direita.
- **`rotate_left`** (Rotação à Esquerda): O oposto da rotação à direita. É usado quando a subárvore direita de um nó é significativamente mais alta que a esquerda.

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
