# Selection Sort

## O que é Selection Sort?

O **Selection Sort** é um algoritmo de ordenação simples e intuitivo que funciona dividindo o array em duas partes:
- **Parte ordenada**: Localizada no início do array (inicialmente vazia)
- **Parte não ordenada**: Localizada no final do array (inicialmente todo o array)

## Como funciona?

O algoritmo funciona da seguinte forma:

1. **Encontra o menor elemento** da parte não ordenada
2. **Troca** esse elemento com o primeiro elemento da parte não ordenada
3. **Expande** a parte ordenada em uma posição
4. **Repete** o processo até que todo o array esteja ordenado

## Diagramação {collapsible="true"}

![selectionSort_anotado.svg](selectionSort_anotado.svg)

### Exemplo Visual

Considerando o array: `[64, 25, 12, 22, 11]`

**Iteração 1:**
- Parte ordenada: `[]`
- Parte não ordenada: `[64, 25, 12, 22, 11]`
- Menor elemento: `11` (posição 4)
- Troca: `11` ↔ `64`
- Resultado: `[11, 25, 12, 22, 64]`

**Iteração 2:**
- Parte ordenada: `[11]`
- Parte não ordenada: `[25, 12, 22, 64]`
- Menor elemento: `12` (posição 2)
- Troca: `12` ↔ `25`
- Resultado: `[11, 12, 25, 22, 64]`

**Iteração 3:**
- Parte ordenada: `[11, 12]`
- Parte não ordenada: `[25, 22, 64]`
- Menor elemento: `22` (posição 3)
- Troca: `22` ↔ `25`
- Resultado: `[11, 12, 22, 25, 64]`

**Iteração 4:**
- Parte ordenada: `[11, 12, 22]`
- Parte não ordenada: `[25, 64]`
- Menor elemento: `25` (já na posição correta)
- Sem troca necessária
- Resultado: `[11, 12, 22, 25, 64]`

