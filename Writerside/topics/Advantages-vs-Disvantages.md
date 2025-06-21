# Vantagens vs. Disvantagens

## Vantagens

* ✅ **Simples de implementar e entender**
* ✅ **Poucas trocas**: Máximo de n-1 trocas
* ✅ **In-place**: Não requer memória adicional
* ✅ **Funciona bem com arrays pequenos**
* ✅ **Eficiente quando operações de escrita são caras**

## Desvantagens

* ❌ **Complexidade O(n²)**: Ineficiente para arrays grandes
* ❌ **Não é estável**: Pode alterar a ordem relativa de elementos iguais
* ❌ **Não é adaptivo**: Não aproveita arrays parcialmente ordenados
* ❌ **Sempre faz n-1 passadas**: Mesmo que o array já esteja ordenado