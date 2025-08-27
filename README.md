[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/suvYDXlm)
# 🔧 Laboratório 2 - Chamadas de Sistema

**Professor:** Lucas Figueiredo  
**Email:** lucas.figueiredo@mackenzie.br

Aprenda como programas se comunicam com o kernel Linux através de system calls, implementando operações fundamentais de I/O.

## 🚀 Quick Start

### ☁️ Opção 1: GitHub Codespaces (Recomendado ✅)
Use o ambiente cloud pré-configurado - sem necessidade de configuração!
Veja [`docs/guia_codespaces.md`](docs/guia_codespaces.md)

### 💻 Opção 2: Máquina Pessoal (Linux)
```bash
# Clone seu repositório (substitua SEU_USUARIO)
git clone https://github.com/disciplina-so/lab2-syscalls-SEU_USUARIO.git
cd lab2-syscalls-SEU_USUARIO

# Verifique as ferramentas
gcc --version && strace --version
```

⚠️ **APENAS para máquina pessoal**: Se precisar configurar autenticação Git/GitHub, veja [`docs/configuracao_git_maquina_pessoal.md`](docs/configuracao_git_maquina_pessoal.md)  
❌ **NUNCA** execute essa configuração em computadores do laboratório!

## 📚 O que Ler Primeiro

1. [`docs/introducao_syscalls.md`](docs/introducao_syscalls.md) - Entenda syscalls fundamentais
2. [`EXERCICIOS.md`](EXERCICIOS.md) - Instruções detalhadas dos exercícios
3. [`docs/guia_strace.md`](docs/guia_strace.md) - Como observar syscalls em ação
4. [`docs/printf_vs_write.md`](docs/printf_vs_write.md) - Diferença entre o printf e write

## 📁 Estrutura do Projeto

```
lab2-syscalls/
├── src/                    # Código dos exercícios
├── traces/                 # Saídas do strace
├── dados/                  # Arquivos de teste
├── docs/                   # Documentação completa
│   ├── introducao_syscalls.md
│   ├── guia_codespaces.md
│   ├── guia_strace.md
│   ├── guia_compilacao.md
│   ├── guia_git.md
│   ├── printf_vs_write.md
│   └── configuracao_git_maquina_pessoal.md
├── setup_github_token.sh   # Script para configurar autenticação (APENAS máquina pessoal!)
├── EXERCICIOS.md          # Instruções dos exercícios
├── RELATORIO_TEMPLATE.md  # Template do relatório
└── Makefile               # Automação de compilação
```

## 📖 Documentação

### 📋 Guias Principais
- [`docs/guia_codespaces.md`](docs/guia_codespaces.md) - Desenvolvimento na nuvem com Codespaces
- [`docs/guia_compilacao.md`](docs/guia_compilacao.md) - Compilando com GCC
- [`docs/guia_git.md`](docs/guia_git.md) - Comandos Git para submissão
- [`docs/guia_strace.md`](docs/guia_strace.md) - Rastreando system calls

### ⚙️ Configuração (Apenas Máquina Pessoal)
- [`docs/configuracao_git_maquina_pessoal.md`](docs/configuracao_git_maquina_pessoal.md) - Instruções para configurar Git/GitHub
- `setup_github_token.sh` - Script automatizado para configurar autenticação (⚠️ NÃO use em PCs compartilhados!)

## ⚡ Referência Rápida

### 🛠️ Compilação
```bash
gcc src/programa.c -o programa
gcc -Wall -g src/programa.c -o programa  # Com debug
```

### 🔍 strace Básico
```bash
strace ./programa                           # Todas syscalls
strace -e openat,read,write,close ./programa  # Syscalls específicas
strace -o traces/saida.txt ./programa       # Salvar em arquivo
```

## 📤 Submissão

Consulte [`EXERCICIOS.md`](EXERCICIOS.md) para detalhes completos da entrega.

```bash
git add .
git commit -m "Entrega laboratório 2"
git push
```

## ❓ Ajuda

- Problemas com ferramentas? Veja [`docs/guia_compilacao.md`](docs/guia_compilacao.md)
- Dúvidas sobre Git? Consulte [`docs/guia_git.md`](docs/guia_git.md)
- Limites do Codespaces? Leia [`docs/guia_codespaces.md`](docs/guia_codespaces.md)