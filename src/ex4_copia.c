/*
 * Exercício 4 - Cópia de Arquivo
 * 
 * OBJETIVO: Implementar programa de cópia usando syscalls
 * 
 * TAREFA: Complete todos os TODOs
 * 1. Compile: gcc src/ex4_copia.c -o ex4_copia
 * 2. Execute: ./ex4_copia
 * 3. Verifique: diff dados/origem.txt dados/destino.txt
 * 4. Analise: strace -e openat,read,write,close ./ex4_copia
 */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

#define BUFFER_SIZE 256

int main() {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_lidos, bytes_escritos;
    int fd_origem, fd_destino;
    long total_bytes = 0;
    int total_operacoes = 0;
    
    clock_t inicio = clock();
    
    printf("=== Exercício 4: Cópia de Arquivo ===\n");
    printf("Copiando: dados/origem.txt -> dados/destino.txt\n\n");
    
    /*
     * TODO 1: Abrir arquivo de origem para leitura
     */
    fd_origem = open("dados/origem.txt", O_RDONLY);
    
    if (fd_origem < 0) {
        perror("Erro ao abrir origem");
        return 1;
    }
    
    /*
     * TODO 2: Criar arquivo de destino para escrita
     * Use flags: O_WRONLY | O_CREAT | O_TRUNC
     * Permissões: 0644
     */
     fd_destino = open("dados/destino.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    
    if (fd_destino < 0) {
        perror("Erro ao criar destino");
        close(fd_origem);
        return 1;
    }
    
    /*
     * TODO 3: Implementar loop de cópia
     * read() do origem, write() no destino
     */
    while ((bytes_lidos = read(fd_origem, buffer, BUFFER_SIZE)) > 0) {
        total_operacoes++;
        
        /*
         * TODO 4: Escrever dados no destino
         */
        bytes_escritos = write(fd_destino, buffer, bytes_lidos);
        
        /*
         * TODO 5: Verificar se escreveu corretamente
         */
         if (bytes_escritos != bytes_lidos) {
            perror("Erro na escrita");
            break;
        }
        
        /*
         * TODO 6: Atualizar contador
         */
        /* TODO: total_bytes += ... */;
        total_bytes += bytes_escritos;
        
        if (total_operacoes % 20 == 0) {
            printf("Progresso: %ld bytes...\n", total_bytes);
        }
    }
    
    /*
     * TODO 7: Verificar erro de leitura
     */
    if (bytes_lidos == -1) {
        perror("Erro na leitura");
    }
    
    /*
     * TODO 8: Fechar ambos os arquivos
     */
    /* TODO: close() dos dois file descriptors */;    
    close(fd_origem);
    close(fd_destino);
    
    clock_t fim = clock();
    double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    
    printf("\n=== Estatísticas ===\n");
    printf("Bytes copiados: %ld\n", total_bytes);
    printf("Operações: %d\n", total_operacoes);
    printf("Tempo: %.6f segundos\n", tempo);
    
    if (tempo > 0) {
        printf("Throughput: %.2f KB/s\n", (total_bytes / 1024.0) / tempo);
    }
    
    printf("\nVerificação: diff dados/origem.txt dados/destino.txt\n");
    
    return 0;
}