//Flores Anzurez Marco Antonio 
//4CV1 Quicksort
#include <stdio.h>
#include <stdlib.h>

// Función para intercambiar dos elementos
void swap(int* a, int* b) 
{
    int t = *a;
    *a = *b;
    *b = t;
}

// Función para particionar el arreglo
int partition (int arr[], int low, int high) 
{
    int pivot = arr[high]; // Seleccionamos el pivote
    int i = (low - 1);
    int j;

    for (j = low; j <= high- 1; j++) 
    {
        // Si el elemento es menor o igual al pivote
        if (arr[j] <= pivot) 
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Función para ordenar el arreglo utilizando quicksort
void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        // Particionamos el arreglo
        int pi = partition(arr, low, high);

        // Ordenamos recursivamente las dos mitades
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() 
{
    FILE *file;
    file = fopen("nums.txt", "r");
    
    // Verificamos si se pudo abrir el archivo
    if (file == NULL) 
    {
        perror("Error al abrir el archivo nums.txt");
        return -1;
    }

    unsigned num_elements;
    
    // Leemos el número de elementos del archivo
    fscanf(file,"%u\n",&num_elements);
    
    // Reservamos memoria para el arreglo
    int *arr=malloc(num_elements*sizeof(int));
    
    unsigned int i;

    // Leemos los elementos del archivo y los guardamos en el arreglo
    for(i=0; i<num_elements; i++)
    {
       fscanf(file,"%d\n",&arr[i]);
    }

    fclose(file);

    // Ordenamos el arreglo utilizando quicksort
    quickSort(arr, 0,num_elements-1);
     
    // Imprimimos el arreglo ordenado en la consola
    for(i=0; i<num_elements; i++)
    {
        printf("%d\n",arr[i]);
    }

    // Abrimos el archivo sorted.txt para escribir los resultados
    file=fopen("sorted.txt","w");
    
     // Verificamos si se pudo abrir el archivo
     if (file == NULL) 
     {
        perror("Error al abrir el archivo sorted.txt");
        return -1;
     }
     
     // Escribimos los resultados en el archivo sorted.txt
     fprintf(file,"Numero de elementos a ordenar: %u\n\n",num_elements);
     fprintf(file,"Elementos ordenados:\n");

     for(i=0; i<num_elements; i++)
     {
        fprintf(file,"%d\n",arr[i]);
     }

     fclose(file);

     free(arr);

     return 0;
}