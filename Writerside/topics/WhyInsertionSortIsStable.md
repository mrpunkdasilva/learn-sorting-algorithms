# Por que o Insertion Sort é Estável?

Um algoritmo de ordenação é considerado **estável** se ele mantém a ordem relativa de elementos com valores iguais. Em outras palavras, se dois elementos têm o mesmo valor, e um aparece antes do outro no array original, eles devem aparecer na mesma ordem no array ordenado.

O Insertion Sort é um algoritmo de ordenação estável. Isso ocorre devido à forma como ele lida com elementos duplicados durante o processo de inserção:

Quando um elemento `key` é comparado com os elementos já ordenados à sua esquerda, a condição para deslocar um elemento para a direita é `array[j] > key`. Se `array[j]` for **igual** a `key`, o loop `while` para, e `key` é inserido **após** `array[j]`. Isso garante que elementos com o mesmo valor mantenham sua ordem original.

## Exemplo:

Considere o array: `[5a, 3, 5b, 2]` (onde `5a` e `5b` são instâncias distintas do valor 5)

1.  **[5a, 3, 5b, 2]**
    *   `key = 3`. `3` é menor que `5a`. Desloca `5a` para a direita.
    *   Array: `[3, 5a, 5b, 2]`

2.  **[3, 5a, 5b, 2]**
    *   `key = 5b`. Compara `5b` com `5a`. `5a` não é maior que `5b` (são iguais). O loop para.
    *   `5b` é inserido após `5a`.
    *   Array: `[3, 5a, 5b, 2]` (a ordem relativa de `5a` e `5b` é mantida)

3.  **[3, 5a, 5b, 2]**
    *   `key = 2`. `2` é menor que `5b`. Desloca `5b` para a direita.
    *   Array: `[3, 5a, 5b, 2]` (temporário)
    *   `2` é menor que `5a`. Desloca `5a` para a direita.
    *   Array: `[3, 5a, 5b, 2]` (temporário)
    *   `2` é menor que `3`. Desloca `3` para a direita.
    *   Array: `[3, 5a, 5b, 2]` (temporário)
    *   Insere `2` no início.
    *   Array: `[2, 3, 5a, 5b]`

Como pode ser visto no passo 2, quando `key` (`5b`) é comparado com `5a`, a condição `array[j] > key` é falsa (pois `5a` não é *maior* que `5b`). Isso faz com que `5b` seja inserido imediatamente após `5a`, preservando sua ordem original. É essa característica que garante a estabilidade do Insertion Sort.