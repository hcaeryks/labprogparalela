#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

int primo(long int n) {
    long int i;
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (i = 3; i <= (long int)(sqrt(n)); i += 2)
        if (n % i == 0)
            return 0;
    return 1;
}

int main(int argc, char *argv[]) {
    double t_inicio, t_fim;
    long int i, n, total = 0;

    if (argc < 2) {
        printf("Valor inválido! Entre com o valor do maior inteiro\n");
        return 0;
    } else {
        n = strtol(argv[1], (char **) NULL, 10);
    }

    t_inicio = omp_get_wtime();

    #pragma omp parallel num_threads(4) shared(n, total) private(i)
    {
        int tid = omp_get_thread_num();
        long int local_total = 0;

        for (i = 3 + 2 * tid; i <= n; i += 2 * omp_get_num_threads()) {
            if (primo(i)) {
                local_total++;
            }
        }

        #pragma omp atomic
        total += local_total;
    }

    total += 1; // Acrescenta o dois, que também é primo

    t_fim = omp_get_wtime();
    printf("Quant. de primos entre 1 e %ld: %ld\n", n, total);
    printf("Tempo de execução: %f\n", t_fim - t_inicio);

    return 0;
}
