# List (Lista)

Uma lista é um Tipo Abstrato de Dados (ADT) que:
- Permite armazenar elementos de qualquer tipo de dado
- Permite inserir um elemento em uma posição específica
- Permite ler um elemento de uma posição específica
- Permite remover um elemento de uma posição específica
- Permite atualizar um elemento em uma posição específica

Uma implementação concreta deste ADT é um Array, onde:
- Os elementos do array podem ser de qualquer tipo de dado
- Todas as operações mencionadas acima são possíveis

Exemplo de declaração e uso de um array em C:

```c
int A[10];  // Declara um array de inteiros com 10 elementos

A[0] = 10;  // Atribui o valor 10 ao primeiro elemento do array

printf("%d", A[0]);  // Imprime o valor do primeiro elemento do array
```

As funcionalidades básicas de uma lista podem ser resumidas como:

```
List
|__ Criação de uma lista vazia (tamanho inicial 0)
|__ Inserção de elementos
|__ Remoção de elementos
|__ Contagem de elementos
|__ Leitura/modificação de elementos em posições específicas
|__ Especificação do tipo de dado dos elementos
```

Estas operações podem ser visualizadas na seguinte imagem:

![Exemplificação de operações de uma lista](Exemplificação de operações de uma lista)

Nota: Quando um array está cheio, uma implementação típica cria um novo array maior, copia os elementos do array antigo para o novo, e libera a memória do array antigo.

Complexidade das operações principais:

1. **Acesso**: Ler/Escrever um elemento em um índice específico → tempo constante, Big O notation: O(1)
2. **Inserção**: O tempo é proporcional à quantidade de elementos → O(n)
3. **Remoção**: O tempo é proporcional à quantidade de elementos → O(n)
4. **Adição**: O tempo é proporcional à quantidade de elementos → O(n)
