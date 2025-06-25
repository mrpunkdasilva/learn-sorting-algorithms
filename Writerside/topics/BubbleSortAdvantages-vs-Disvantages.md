# Vantagens vs. Disvantagens

## Vantagens

* ✅ **Simples de implementar e entender**
* ✅ **Estável**: Mantém a ordem relativa de elementos iguais
* ✅ **In-place**: Não requer memória adicional
* ✅ **Adaptivo**: Com otimização pode detectar arrays já ordenados
* ✅ **Funciona bem com arrays pequenos**
* ✅ **Detecta facilmente se o array já está ordenado**

## Desvantagens

* ❌ **Complexidade O(n²)**: Ineficiente para arrays grandes
* ❌ **Muitas trocas**: Pode fazer até O(n²) trocas no pior caso
* ❌ **Lento na prática**: Mesmo entre algoritmos O(n²)
* ❌ **Não recomendado para dados em produção**
* ❌ **Elementos pequenos "borbulham" lentamente para o início**