# Aprenda Algoritmos de Ordenação

Um projeto educativo abrangente para aprender e compreender diferentes algoritmos de ordenação através de implementações práticas em C++ e documentação visual.

## Visão Geral

Este projeto foi desenvolvido para ajudar estudantes e desenvolvedores a entenderem os fundamentos dos algoritmos de ordenação. Combina implementações práticas em C++ com documentação educativa detalhada para proporcionar uma experiência completa de aprendizado.

O projeto inclui:
- **Implementações em C++** de vários algoritmos de ordenação
- **Documentação visual** explicando como cada algoritmo funciona
- **Explicações passo a passo** com diagramas e exemplos
- **Materiais de aprendizado interativos** construídos com Writerside

## Começando

### Pré-requisitos

- **Compilador C++** (suportando C++14 ou posterior)
- **CMake** (versão 3.30 ou posterior)
- **Git** (para clonar o repositório)

## Instalando Compiladores C++

<details>
<summary><strong>Linux (Ubuntu/Debian)</strong></summary>

### Instalação do GCC/G++

1. **Atualize os repositórios:**
   ```bash
   sudo apt update
   ```

2. **Instale o compilador GCC/G++:**
   ```bash
   sudo apt install build-essential
   ```

3. **Verifique a instalação:**
   ```bash
   gcc --version
   g++ --version
   ```

### Instalação do CMake
```bash
sudo apt install cmake
```

### Instalação do Git
```bash
sudo apt install git
```

### Para outras distribuições Linux:

**Red Hat/Fedora/CentOS:**
```bash
sudo dnf install gcc gcc-c++ make cmake git
# ou para versões mais antigas:
sudo yum install gcc gcc-c++ make cmake git
```

**Arch Linux:**
```bash
sudo pacman -S gcc make cmake git
```

</details>

<details>
<summary><strong>Windows</strong></summary>

### Opção 1: MinGW-w64 (Recomendado para iniciantes)

1. **Baixe o MSYS2:**
   - Acesse [https://www.msys2.org/](https://www.msys2.org/)
   - Baixe e execute o instalador

2. **Instale o MinGW-w64:**
   ```bash
   pacman -S mingw-w64-ucrt-x86_64-gcc
   pacman -S mingw-w64-ucrt-x86_64-cmake
   pacman -S git
   ```

3. **Adicione ao PATH:**
   - Adicione `C:\msys64\ucrt64\bin` às variáveis de ambiente
   - Reinicie o terminal

4. **Verifique a instalação:**
   ```cmd
   gcc --version
   g++ --version
   cmake --version
   ```

### Opção 2: Visual Studio Community (Completo)

1. **Baixe o Visual Studio Community:**
   - Acesse [https://visualstudio.microsoft.com/vs/community/](https://visualstudio.microsoft.com/vs/community/)
   - Baixe e execute o instalador

2. **Selecione os componentes:**
   - ✅ Desktop development with C++
   - ✅ CMake tools for Visual Studio
   - ✅ Git for Windows

3. **Configure o ambiente:**
   - Use o "Developer Command Prompt" ou "Developer PowerShell"
   - Compilador: `cl.exe`

### Opção 3: Code::Blocks (IDE Completa)

1. **Baixe o Code::Blocks:**
   - Acesse [http://www.codeblocks.org/downloads](http://www.codeblocks.org/downloads)
   - Escolha a versão com MinGW incluído

2. **Instale normalmente:**
   - Siga o assistente de instalação
   - O compilador MinGW já vem incluso

### Instalação do Git no Windows

**Opção A - Git for Windows:**
- Baixe em [https://git-scm.com/download/win](https://git-scm.com/download/win)
- Execute o instalador com configurações padrão

**Opção B - Através do Chocolatey:**
```powershell
# Instale o Chocolatey primeiro, depois:
choco install git
```

</details>



<details>
<summary><strong>Testando a Instalação</strong></summary>

### Teste Rápido do Compilador

1. **Crie um arquivo de teste:**
   ```cpp
   // teste.cpp
   #include <iostream>
   using namespace std;
   
   int main() {
       cout << "Compilador C++ funcionando!" << endl;
       return 0;
   }
   ```

2. **Compile e execute:**
   ```bash
   # Linux/macOS/Windows (MinGW)
   g++ -o teste teste.cpp
   ./teste
   
   # Windows (cmd)
   g++ -o teste.exe teste.cpp
   teste.exe
   ```

3. **Saída esperada:**
   ```
   Compilador C++ funcionando!
   ```

### Teste do CMake

1. **Crie um CMakeLists.txt simples:**
   ```cmake
   cmake_minimum_required(VERSION 3.10)
   project(TesteCompilador)
   set(CMAKE_CXX_STANDARD 14)
   add_executable(teste teste.cpp)
   ```

2. **Compile com CMake:**
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   # ou no Windows com Visual Studio:
   # cmake --build .
   ```

</details>

### Instalação

1. **Clone o repositório:**
   ```bash
   git clone <url-do-repositorio>
   cd learn-sorting-algorithms
   ```

2. **Compile o projeto:**
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

3. **Execute os algoritmos:**
   ```bash
   # Para Bubble Sort
   ./Domus/Domus-1/bubbleSort

   # Para Selection Sort
   ./Domus/Domus-1/selectionSort
   ```

## Algoritmos Implementados

### 1. Bubble Sort (Ordenação por Bolha)
- **Localização:** `Domus/Domus-1/bubbleSort.cpp`
- **Complexidade de Tempo:** O(n²)
- **Complexidade de Espaço:** O(1)
- **Descrição:** Compara elementos adjacentes e os troca se estiverem na ordem errada

### 2. Selection Sort (Ordenação por Seleção)
- **Localização:** `Domus/Domus-1/selectionSort.cpp`
- **Complexidade de Tempo:** O(n²)
- **Complexidade de Espaço:** O(1)
- **Descrição:** Encontra o elemento mínimo e o coloca no início da lista

## Documentação

O projeto inclui documentação abrangente construída com **JetBrains Writerside**:

- **Tutoriais interativos** explicando conceitos de algoritmos de ordenação
- **Diagramas visuais** mostrando a execução passo a passo dos algoritmos
- **Exemplos de código** com explicações detalhadas
- **Suporte completo em português** para conteúdo educacional

### Acessando a Documentação

1. **Documentação Local:** Abra `docs/index.html` no seu navegador
2. **Arquivos Fonte:** Verifique `Writerside/topics/` para documentação em markdown

## Recursos Educacionais

### Aprendizado Visual
- Visualização passo a passo dos algoritmos
- Diagramas comparativos mostrando a troca de elementos
- Detalhamento iteração por iteração

### Estrutura do Código
Cada implementação de algoritmo inclui:
- Nomenclatura clara de variáveis
- Comentários detalhados
- Funções separadas para operações principais (troca, exibição, ordenação)
- Dados de teste com demonstração da saída

### Caminho de Aprendizado
1. **Entenda a teoria** através da documentação
2. **Estude as implementações** do código
3. **Execute os programas** para ver os resultados
4. **Experimente** com diferentes dados de entrada

## Contribuindo

Contribuições são bem-vindas! Veja como você pode ajudar:

1. **Adicionar novos algoritmos** (Quick Sort, Merge Sort, Heap Sort, etc.)
2. **Melhorar a documentação** com mais exemplos e explicações
3. **Adicionar casos de teste** para melhor validação
4. **Traduzir conteúdo** para outros idiomas
5. **Corrigir bugs** ou melhorar a qualidade do código

### Diretrizes de Contribuição

1. Faça um fork do repositório
2. Crie uma branch para sua feature (`git checkout -b feature/novo-algoritmo`)
3. Commit suas mudanças (`git commit -am 'Adiciona novo algoritmo de ordenação'`)
4. Push para a branch (`git push origin feature/novo-algoritmo`)
5. Crie um Pull Request

## Licença

Este projeto está licenciado sob a **Licença MIT** - veja o arquivo [LICENSE](LICENSE) para detalhes.


## Tópicos Relacionados

- Estruturas de Dados
- Análise de Complexidade de Algoritmos
- Otimização de Performance
- Estudos Comparativos de Algoritmos

## Suporte

Se você tiver dúvidas ou precisar de ajuda:
- Crie uma [issue](../../issues) no repositório
- Consulte a documentação na pasta `docs/`
- Revise os exemplos em `Writerside/topics/`

---

**Bom Aprendizado!** Comece com o básico e vá evoluindo para algoritmos mais complexos.