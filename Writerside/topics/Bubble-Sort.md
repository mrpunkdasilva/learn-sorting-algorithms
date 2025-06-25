# Bubble Sort

## O que é Bubble Sort?

O **Bubble Sort** é um algoritmo de ordenação simples que funciona comparando elementos adjacentes e trocando-os se estiverem na ordem errada. O nome vem do fato de que os elementos menores "borbulham" para o início da lista, assim como bolhas de ar sobem para a superfície da água.

## Como funciona?

O algoritmo funciona da seguinte forma:

1. **Compara** elementos adjacentes no array
2. **Troca** os elementos se estiverem na ordem errada (o maior vai para a direita)
3. **Repete** o processo para todos os pares adjacentes
4. **Continua** as iterações até que nenhuma troca seja necessária

## Diagramação

![bubbleSort_annotated.png](bubbleSort_annotated.png)

## Exemplo Visual

Considerando o array: `[64, 34, 25, 12, 22, 11, 90]`

**Iteração 1:**
- Compara 64 e 34: `64 > 34` → Troca: `[34, 64, 25, 12, 22, 11, 90]`
- Compara 64 e 25: `64 > 25` → Troca: `[34, 25, 64, 12, 22, 11, 90]`
- Compara 64 e 12: `64 > 12` → Troca: `[34, 25, 12, 64, 22, 11, 90]`
- Compara 64 e 22: `64 > 22` → Troca: `[34, 25, 12, 22, 64, 11, 90]`
- Compara 64 e 11: `64 > 11` → Troca: `[34, 25, 12, 22, 11, 64, 90]`
- Compara 64 e 90: `64 < 90` → Sem troca: `[34, 25, 12, 22, 11, 64, 90]`
- **Resultado:** O maior elemento (90) está na posição correta

**Iteração 2:**
- Compara 34 e 25: `34 > 25` → Troca: `[25, 34, 12, 22, 11, 64, 90]`
- Compara 34 e 12: `34 > 12` → Troca: `[25, 12, 34, 22, 11, 64, 90]`
- Compara 34 e 22: `34 > 22` → Troca: `[25, 12, 22, 34, 11, 64, 90]`
- Compara 34 e 11: `34 > 11` → Troca: `[25, 12, 22, 11, 34, 64, 90]`
- Compara 34 e 64: `34 < 64` → Sem troca
- **Resultado:** Os dois maiores elementos estão nas posições corretas

**Iteração 3:**
- Compara 25 e 12: `25 > 12` → Troca: `[12, 25, 22, 11, 34, 64, 90]`
- Compara 25 e 22: `25 > 22` → Troca: `[12, 22, 25, 11, 34, 64, 90]`
- Compara 25 e 11: `25 > 11` → Troca: `[12, 22, 11, 25, 34, 64, 90]`
- Compara 25 e 34: `25 < 34` → Sem troca

O processo continua até que nenhuma troca seja necessária, resultando em: `[11, 12, 22, 25, 34, 64, 90]`
