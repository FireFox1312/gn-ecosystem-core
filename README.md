# gn-ecosystem-core

Núcleo lógico e algorítmico do ecossistema Growth Nest. Desenvolvido em C como Prova de Conceito (PoC) e base arquitetural, este repositório mapeia as regras de negócio, banco de dados e estruturas que guiarão a stack de produção definitiva da startup.

## 📌 Sobre o Repositório e a Visão do Projeto

O **gn-ecosystem-core** é a fundação lógica e estrutural do Growth Nest, um hub estratégico pensado para conectar desenvolvedores, projetos e a comunidade da indústria de jogos.

> ⚠️ **Nota de Arquitetura:** Este repositório é construído em **C puro**. Ele não representa a linguagem final de produção do Growth Nest (que utilizará stacks modernas de web/mobile), mas serve como o **laboratório arquitetural definitivo** da startup. É aqui que estamos validando e modelando a complexidade do sistema em baixo nível.

Nascido de um escopo acadêmico para o aprofundamento em Estruturas de Dados, este núcleo implementa:

- A engenharia de requisitos e regras de negócio essenciais (CRUD de catálogos e gestão de usuários).
- A modelagem lógica e relacional que futuramente alimentará a base de dados em produção.
- A matemática por trás dos diferenciais do produto, como os algoritmos do Milestone Tracker (rastreio de conquistas), Sorteador Inteligente e Radar de Portfólio.

Ao desenvolver a lógica bruta em C usando Tipos Abstratos de Dados (TADs) e alocação dinâmica, garantimos um mapeamento de domínio sólido e extremamente otimizado antes da migração para a infraestrutura definitiva.

## 📂 Estrutura do Projeto

```text
gn-ecosystem-core/
├── src/            # Código-fonte (.c)
│   └── main.c      # Entry point
├── include/        # Headers (.h)
├── build/          # Artefatos compilados (não versionado)
├── .vscode/        # Configurações do editor (tasks, debug, IntelliSense)
├── Makefile        # Sistema de build
├── .gitignore
├── LICENSE
└── README.md
```

## 🛠️ Configuração do Ambiente de Desenvolvimento

### Pré-requisitos

| Ferramenta | Versão Mínima | Descrição |
|:--|:--|:--|
| [MSYS2](https://www.msys2.org/) | — | Ambiente de desenvolvimento para Windows com gerenciador de pacotes |
| GCC | 13+ | Compilador C/C++ |
| GDB | 14+ | Debugger |
| GNU Make | 4+ | Automação de build |
| [VS Code](https://code.visualstudio.com/) | 1.80+ | Editor de código |

### 1. Instalar o MSYS2

1. Baixe o instalador em **https://www.msys2.org/** e execute.
2. Instale no caminho padrão: `C:\msys64`.
3. Ao finalizar, feche o terminal que abrir automaticamente.

### 2. Instalar o Toolchain C (GCC, GDB, Make)

Abra o **MSYS2 UCRT64** (procure no Menu Iniciar) e execute:

```bash
pacman -S --noconfirm mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-gdb mingw-w64-ucrt-x86_64-make
```

### 3. Adicionar ao PATH do Sistema

1. Abra o Menu Iniciar e pesquise **"Variáveis de Ambiente"**.
2. Clique em **"Editar as variáveis de ambiente do sistema"** → **"Variáveis de Ambiente..."**.
3. Na seção **"Variáveis do sistema"**, selecione `Path` e clique em **"Editar..."**.
4. Clique em **"Novo"** e adicione:
   ```
   C:\msys64\ucrt64\bin
   ```
5. Clique em **OK** em todas as janelas.
6. **Reinicie o terminal/VSCode** para as mudanças surtirem efeito.

**Verificação** — abra um novo PowerShell e execute:

```powershell
gcc --version
gdb --version
mingw32-make --version
```

Os três comandos devem retornar suas respectivas versões.

### 4. Extensões do VS Code (Recomendadas)

Instale via terminal ou pela aba de extensões do VS Code:

```powershell
code --install-extension ms-vscode.cpptools
code --install-extension ms-vscode.cpptools-extension-pack
code --install-extension jeff-hykin.better-c-syntax
code --install-extension streetsidesoftware.code-spell-checker
code --install-extension streetsidesoftware.code-spell-checker-portuguese-brazilian
```

| Extensão | Finalidade |
|:--|:--|
| `ms-vscode.cpptools` | IntelliSense, debug com GDB, Go to Definition |
| `ms-vscode.cpptools-extension-pack` | Pack completo (inclui CMake Tools e themes) |
| `jeff-hykin.better-c-syntax` | Syntax highlighting aprimorado para C |
| `streetsidesoftware.code-spell-checker` | Spell checker para comentários e docs |

### 5. Compilar e Executar

```powershell
# Clonar o repositório
git clone https://github.com/FireFox1312/gn-ecosystem-core.git
cd gn-ecosystem-core

# Compilar
mingw32-make all

# Executar
mingw32-make run

# Limpar artefatos
mingw32-make clean
```

Atalhos no VS Code (com as tasks já configuradas no `.vscode/`):

| Ação | Atalho |
|:--|:--|
| Compilar | `Ctrl + Shift + B` |
| Debugar | `F5` |

## 📄 Licença

Este projeto está sob a licença MIT — veja o arquivo [LICENSE](LICENSE) para detalhes.
