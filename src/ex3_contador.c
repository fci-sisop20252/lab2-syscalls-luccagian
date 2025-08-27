/*
 * Exercício 3 - Contador de Linhas com Loop
 * 
 * OBJETIVO: Implementar loop de leitura e analisar múltiplas syscalls
 * 
 * TAREFA: Complete os TODOs para implementar o loop
 * 1. Compile: gcc src/ex3_contador.c -o ex3_contador
 * 2. Execute: ./ex3_contador
 * 3. Analise: strace -c ./ex3_contador
 * 4. Observe: strace -e read ./ex3_contador
 */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

#define BUFFER_SIZE 64   // Buffer pequeno para forçar múltiplas leituras

int main() {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_lidos;
    int fd;
    int total_linhas = 0;
    int total_caracteres = 0;
    int total_reads = 0;
    
    clock_t inicio = clock();
    
    printf("=== Exercício 3: Contador de Linhas ===\n");
    printf("Buffer: %d bytes\n\n", BUFFER_SIZE);
    
    fd = open("dados/teste2.txt", O_RDONLY);
    if (fd < 0) {
        perror("Erro ao abrir dados/teste2.txt");
        return 1;
    }
    
    /*
     * TODO 1: Implementar loop de leitura
     * Loop até read() retornar 0 (fim do arquivo)
     */
    while ((bytes_lidos = read(fd, buffer, BUFFER_SIZE)) > 0) {
        total_reads++;
        
        /*
         * TODO 2: Contar caracteres '\n' no buffer
         */
        for (int i = 0; i < bytes_lidos; i++) {
            if (buffer[i] == '\n') {
                total_linhas++;
            }
            /* TODO: verificar '\n' e incrementar total_linhas */
        }
        
        /*
         * TODO 3: Somar total de caracteres
         */
        /* TODO: total_caracteres += ... */;

        total_caracteres += bytes_lidos;
        
        if (total_reads % 10 == 0) {
            printf("Processadas %d chamadas read()...\n", total_reads);
        }
    }
    
    /*
     * TODO 4: Verificar se houve erro na leitura
     */
    if (bytes_lidos == -1) {
        perror("Erro na leitura");
        close(fd);
        return 1;
    }
    
    close(fd);
    
    clock_t fim = clock();
    double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    
    printf("\n=== Resultados ===\n");
    printf("Linhas: %d\n", total_linhas);
    printf("Caracteres: %d\n", total_caracteres);
    printf("Chamadas read(): %d\n", total_reads);
    printf("Tempo: %.6f segundos\n", tempo);
    
    if (total_reads > 0) {
        printf("Média bytes/read: %.1f\n", 
               (double)total_caracteres / total_reads);
    }
    
    printf("\nExecute: strace -c ./ex3_contador\n");
    
    return 0;
}

/*
 * Experimente mudar BUFFER_SIZE para 16, 256, 1024
 * e compare o número de syscalls vs tempo de execução
 */