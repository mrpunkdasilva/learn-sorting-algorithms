# Por que o Bubble Sort É Estável?

## O que significa "Estabilidade" em algoritmos de ordenação?

Um algoritmo de ordenação é **estável** quando mantém a **ordem relativa** dos elementos que possuem valores iguais. Ou seja, se dois elementos têm o mesmo valor, aquele que aparece primeiro no array original deve aparecer primeiro no array ordenado.

## Exemplo Prático de Estabilidade

Considere um array de cartas onde cada carta tem um valor e um naipe:

**Array inicial:** `[5♠, 3♦, 5♥, 2♣, 3♠]`

Vamos ordenar por **valor numérico** apenas, ignorando o naipe:

### ✅ Bubble Sort (estável):
`[2♣, 3♦, 3♠, 5♠, 5♥]`
- Note que `3♦` vem antes de `3♠` (mantém ordem original)
- E `5♠` vem antes de `5♥` (mantém ordem original)

## Por que o Bubble Sort mantém a estabilidade?

O Bubble Sort mantém a estabilidade porque:

1. **Compara apenas elementos adjacentes**
2. **Só troca elementos se o da esquerda for MAIOR que o da direita**
3. **Nunca troca elementos iguais**

### Demonstração com números simples:

**Array:** `[4, 2a, 2b, 1]` (onde 2a e 2b têm o mesmo valor, mas origens diferentes)

**Iteração 1:**
- Compara 4 e 2a: `4 > 2a` → Troca: `[2a, 4, 2b, 1]`
- Compara 4 e 2b: `4 > 2b` → Troca: `[2a, 2b, 4, 1]`
- Compara 4 e 1: `4 > 1` → Troca: `[2a, 2b, 1, 4]`

**Iteração 2:**
- Compara 2a e 2b: `2a == 2b` → **Sem troca** (preserva ordem!)
- Compara 2b e 1: `2b > 1` → Troca: `[2a, 1, 2b, 4]`

**Iteração 3:**
- Compara 2a e 1: `2a > 1` → Troca: `[1, 2a, 2b, 4]`

**Resultado final:** `[1, 2a, 2b, 4]` ✅ Ordem original mantida!

## Exemplo Prático com Dados Reais

```cpp
struct Pessoa {
    string nome;
    int idade;
    int numeroChegada; // Para identificar ordem original
};

// Array inicial (ordenado por chegada):
// 1. João, 25 anos
// 2. Maria, 30 anos  
// 3. Pedro, 25 anos
// 4. Ana, 20 anos

// Após Bubble Sort por idade:
// 1. Ana, 20 anos
// 2. João, 25 anos     <- João mantém prioridade sobre Pedro
// 3. Pedro, 25 anos    <- Pedro vem depois (ordem original preservada)
// 4. Maria, 30 anos
```

## Importância da Estabilidade

A estabilidade é crucial quando:

- **Ordenação múltipla**: Primeiro por um campo, depois por outro
- **Preservação de contexto**: Manter informações sobre ordem original
- **Interfaces de usuário**: Comportamento previsível para o usuário
- **Dados com metadados**: Timestamps, IDs, etc.

## Comparação com Algoritmos Instáveis

| Algoritmo | Estável? | Motivo |
|-----------|----------|--------|
| **Bubble Sort** | ✅ Sim | Só troca adjacentes se forem diferentes |
| **Selection Sort** | ❌ Não | Troca elementos distantes |
| **Insertion Sort** | ✅ Sim | Insere mantendo ordem |
| **Quick Sort** | ❌ Não | Particionamento pode alterar ordem |
| **Merge Sort** | ✅ Sim | Merge preserva ordem quando iguais |

## Implementação que Garante Estabilidade

```cpp
void stableBubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // CRUCIAL: usar > e não >=
            if (arr[j] > arr[j + 1]) {  // Não troca elementos iguais!
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
```

<note>

🔑 **Ponto-chave:** Use `>` (maior que) e nunca `>=` (maior ou igual) na condição de troca para manter a estabilidade!

</note>
