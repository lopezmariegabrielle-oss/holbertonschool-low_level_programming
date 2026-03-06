#include <stdio.h>
#include <time.h>

#define DATASET_SIZE 50000
#define SEED_VALUE 42u

static int dataset[DATASET_SIZE];

static unsigned int next_value(unsigned int *state)
{
    *state = (*state * 1103515245u) + 12345u;
    return *state;
}

static void build_dataset(void)
{
    unsigned int state;
    int i;

    state = SEED_VALUE;

    for (i = 0; i < DATASET_SIZE; i++)
        dataset[i] = (int)(next_value(&state) % 100000);
}

static void process_dataset(void)
{
    int i;
    int v;

    for (i = 0; i < DATASET_SIZE; i++)
    {
        v = dataset[i];
        v = (v * 3) + (v / 7) - (v % 11);
        if (v < 0)
            v = -v;
        dataset[i] = v;
    }
}

static unsigned long reduce_checksum(void)
{
    unsigned long sum;
    int i;

    sum = 0;
    for (i = 0; i < DATASET_SIZE; i++)
        sum = (sum * 131ul) + (unsigned long)dataset[i];

    return sum;
}

int main(void)
{

clock_t start_total, end_total;
clock_t start_step, end_step;
double total_t, build_t, process_t, reduce_t;
unsigned long checksum;
/*chrono global pour tout mesurer*/
start_total = clock();

/*Mesure de la phase BUILD*/
start_step = clock();
build_dataset();
end_step = clock();
build_t = (double)(end_step - start_step) / CLOCKS_PER_SEC;

/* Mesure de la phase PROCESS*/
start_step = clock();
process_dataset();
end_step = clock();
process_t = (double)(end_step - start_step) / CLOCKS_PER_SEC;

/*Mesure de la phase REDUCE*/
start_step = clock();
checksum = reduce_checksum();
end_step = clock();
reduce_t = (double)(end_step - start_step) / CLOCKS_PER_SEC;

/*Arrêt du chrono total*/
end_total = clock();
total_t = (double)(end_total - start_total) / CLOCKS_PER_SEC;

(void)checksum;

/*Resultat*/
printf("TOTAL seconds: %.6f\n", total_t);
printf("BUILD_DATA seconds: %.6f\n", build_t);
printf("PROCESS seconds: %.6f\n", process_t);
printf("REDUCE seconds: %.6f\n", reduce_t);

    /* Required output (exact format, no extra lines):
     * TOTAL seconds: <float>
     * BUILD_DATA seconds: <float>
     * PROCESS seconds: <float>
     * REDUCE seconds: <float>
     */

    return 0;
}