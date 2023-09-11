<div style="display: inline_block">
  <img align="center" alt="VS" src="https://img.shields.io/badge/Visual_Studio_Code-0078D4?style=for-the-badge&logo=visual%20studio%20code&logoColor=white" />
  <img align="center" alt="Linux" src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black" />
  <img align="center" alt="C++" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" />
</div><br>

# ⚠️ Apresentação do Problema 

<div align="justify">


</div>


# 💡 Solução do Problema 

## **Hash e Heap**

<div align="justify">

</div>

## **Árvore Binária**

<div align="justify">
  
</div>

## **Árvore AVL**

<div align="justify">
  
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
