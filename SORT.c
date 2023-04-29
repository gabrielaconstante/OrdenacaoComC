//Gabriela Constante de Oliveira

#include <stdio.h> 
#include <time.h>

#define TAMANHO 10000 

// Prototipos de Função 


void geraNumero(int *vet, int op); 
void imprimirVetor(int *vet); 

//Bublue Sort
void bubbleSort(int *vet); 

//Insertion Sort
void insertionSort(int *vet);

//Merge Sort
void mergeSort(int *vet, int inicio, int fim, int *comparacoesMerge, int *trocasMerge, double *tempoMerge);
void merge(int *vet, int inicio, int meio, int fim, int *trocasMerge, int *comparacoesMerge);

//Quick Sort
void quickSort(int *vet, int esq, int dir, int *comparacoesQuick, int *trocasQuick);
int particiona(int *vet, int esq, int dir, int *comparacoesQuick, int *trocasQuick);



//Selection Sort
void selectionSort(int *vet); 

int main (void){ 

    // Variáveis 
    int vet1[TAMANHO]; 
    int vet2[TAMANHO]; 
    int vet3[TAMANHO]; 
    int vet4[TAMANHO]; 
    int vet5[TAMANHO]; 

    // Entrada de dados; 
    geraNumero(vet1,2); 
    geraNumero(vet2,2); 
    geraNumero(vet3,2); 
    geraNumero(vet4,2); 
    geraNumero(vet5,2); 
    
    int comparacoesQuick = 0;
    int trocasQuick = 0;
    int comparacoesMerge = 0;
    int trocasMerge = 0;
    double tempoMerge;

    printf(" Desordenado: \n\n"); 
    //imprimirVetor(vet1); 

    // Processamentos dos dados 
    bubbleSort(vet1); 
    insertionSort(vet2);
    selectionSort(vet3); 
    
    clock_t t_inicioQuick = clock();
    quickSort(vet4, 0, TAMANHO - 1, &comparacoesQuick, &trocasQuick);
    clock_t t_fimQuick = clock();
    
    double tempoQuick = (double)(t_fimQuick - t_inicioQuick) / CLOCKS_PER_SEC;
    printf("\n\n Quick Sort");
  	printf("\n Tempo de execucao: %lf segundos", tempoQuick);
  	printf("\n Numero de comparacoes: %d", comparacoesQuick);
  	printf("\n Numero de trocas: %d", trocasQuick);
  	
  	
  	clock_t t_inicioMerge = clock();
    mergeSort(vet5, 0, TAMANHO - 1, &comparacoesMerge, &trocasMerge, &tempoMerge);
    clock_t t_fimMerge = clock();

    tempoMerge = ((double)(t_fimMerge - t_inicioMerge)) / CLOCKS_PER_SEC;

	printf("\n\n Merge Sort");
    printf("\n Tempo de execucao: %lf segundos", tempoMerge);
    printf("\n Numero de comparacoes: %d", comparacoesMerge);
    printf("\n Numero de trocas: %d", trocasMerge);
    
    
    
    // Saída de dados 
    printf("\n\n Ordenado: \n\n"); 
    imprimirVetor(vet1); 

    return 0; 

} 

void geraNumero(int *vet, int op) { 

    int i, j;  

    switch (op) { 
        case 1: 
            // Ordenados 
            for (i = 0; i < TAMANHO; i++) { 
                vet[i] = i + 1; 
            } 
            break; 
        case 2: 
            //Invertidos 
            for (i = 0; i < TAMANHO; i++) { 
               vet[i] = TAMANHO-i; 
            } 
            break; 
        case 3: 
            // Aleatórios 
            for (i = 0; i < TAMANHO; i++) { 
                vet[i] = (int) (rand() % TAMANHO); 
            } 
            break; 
    } 
} 


// Função ordenação bubble sort 
void bubbleSort(int *vet){

    int n, troca, i, aux, qtd_trocas, qtd_comparacoes; 
    n = 1; 
    troca = 1; 
    qtd_trocas = 0; 
    qtd_comparacoes = 0; 

    // Ponto do algoritmo para iniciar o tempo de execução 
    float tempo_inicial = clock(); 
        while (n <= TAMANHO && troca == 1) { 
            troca = 0; 
            for (i = 0; i <= TAMANHO-2; i++) { 
                // Ponto do algoritmo para contar as comparações 
                qtd_comparacoes++; 
                if (vet[i] > vet[i + 1]) { 
                    // Ponto do algoritmo para contar as trocas 
                    qtd_trocas++; 
                    troca = 1; 
                    aux = vet[i]; 
                    vet[i] = vet[i + 1]; 
                    vet[i + 1] = aux; 
                } 
            } 
            n = n + 1; 
        } 

        // Ponto do algoritmo para calcular o tempo de execução 
        float tempo_final = clock() - tempo_inicial; 
        
        // Saída de dados 
        printf("\n\n Buble Sort");
        printf("\n Quantidade de comparacoes: %i\n",qtd_comparacoes); 
        printf(" Quantidade de trocas: %i\n",qtd_trocas); 
        printf(" Tempo de execucao do algoritmo: %.3f",tempo_final/1000); 

}

// Função ordenação insertion sort
void insertionSort(int *vet) {

  int qtd_trocas = 0, qtd_comparacoes = 0;
  clock_t tempo_inicio, tempo_fim;

  int i, j, temp;
  tempo_inicio = clock();
  for (i = 1; i < TAMANHO; i++) {
    temp = vet[i];
    j = i - 1;

    while ((j >= 0) && (temp < vet[j])) {
      vet[j + 1] = vet[j];
      j--;
      qtd_trocas++;
      qtd_comparacoes++;
    }

    vet[j + 1] = temp;
    qtd_trocas++;
    qtd_comparacoes++;
  }
  tempo_fim = clock();
  printf("\n\n Insertion Sort ");
  printf("\n Quantidade de comparacoes: %i\n", qtd_comparacoes);
  printf(" Quantidade de trocas: %i\n", qtd_trocas);
  printf(" Tempo de execucao do algoritmo: %f segundos\n", (double)(tempo_fim - tempo_inicio) / CLOCKS_PER_SEC);
}

void selectionSort(int *vet){

    int j, i, min,qtd_trocas,qtd_comparacoes; 
    qtd_trocas = 0; 
    qtd_comparacoes = 0; 

    // Ponto do algoritmo para iniciar o tempo de execução 
    float tempo_inicial = clock(); 

    for (i = 0; i < TAMANHO-1; i++) {
        min = i;
        for (j = i+1; j < TAMANHO; j++){
            qtd_comparacoes++;
            if (vet[j] < vet[min]) 
                    min = j; 
        }         
        int atual = vet[min];
        vet[min] = vet[i];
        vet[i] = atual;
        qtd_trocas++;
        
        }
        // Ponto do algoritmo para calcular o tempo de execução 
        float tempo_final = clock() - tempo_inicial; 
        // Saída de dados 
        printf("\n\n Selection Sort");
        printf("\n Quantidade de comparacoes: %i\n",qtd_comparacoes); 
        printf(" Quantidade de trocas: %i\n",qtd_trocas); 
        printf(" Tempo de execucao do algoritmo: %.3f",tempo_final/1000); 
    
}

void quickSort(int *vet, int esq, int dir, int *comparacoesQuick, int *trocasQuick) {
  if (esq < dir) {
    int p = particiona(vet, esq, dir, comparacoesQuick, trocasQuick);
    quickSort(vet, esq, p - 1, comparacoesQuick, trocasQuick);
    quickSort(vet, p + 1, dir, comparacoesQuick, trocasQuick);
  }
}

int particiona(int *vet, int esq, int dir, int *comparacoesQuick, int *trocasQuick) {
  int pivo = vet[dir];
  int i = esq - 1;
  int j;
  for ( j = esq; j < dir; j++) {
    (*comparacoesQuick)++;
    if (vet[j] <= pivo) {
      i++;
      (*trocasQuick)++;
      int temp = vet[i];
      vet[i] = vet[j];
      vet[j] = temp;
    }
  }
  (*trocasQuick)++;
  int temp = vet[i + 1];
  vet[i + 1] = vet[dir];
  vet[dir] = temp;
  return i + 1;
}

void mergeSort(int *vet, int inicio, int fim, int *compMerge, int *trocasMerge, double *tempoMerge) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergeSort(vet, inicio, meio, compMerge, trocasMerge, tempoMerge);
        mergeSort(vet, meio+1, fim, compMerge, trocasMerge, tempoMerge);
        merge(vet, inicio, meio, fim, compMerge, trocasMerge);
    }
}
void merge(int *vet, int inicio, int meio, int fim, int *trocasMerge, int *comparacoesMerge) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;
	int i, j;
    int L[n1], R[n2];
    for ( i = 0; i < n1; i++) {
        L[i] = vet[inicio + i];
        (*comparacoesMerge)++;
    }
    for (j = 0; j < n2; j++) {
        R[j] = vet[meio + 1 + j];
        (*comparacoesMerge)++;
    }

    i = 0;
	j = 0;
	int k = inicio;
    while (i < n1 && j < n2) {
        (*comparacoesMerge)++;
        if (L[i] <= R[j]) {
            vet[k] = L[i];
            i++;
        }
        else {
            vet[k] = R[j];
            j++;
        }
        (*trocasMerge)++;
        k++;
    }

    while (i < n1) {
        vet[k] = L[i];
        i++;
        (*trocasMerge)++;
        k++;
    }

    while (j < n2) {
        vet[k] = R[j];
        j++;
        (*trocasMerge)++;
        k++;
    }
}
 // Função impressão do vetor 
void imprimirVetor(int *vet){ 

    int i; 

    for(i=0;i<TAMANHO;i++){ 
        printf("%i, ",vet[i]); 
        if ((i+1)%14 == 0){ 
            printf("\n"); 
        } 
    } 
}  

