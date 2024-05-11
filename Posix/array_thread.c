#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int array [10] = {2,3,5,7,11,13,17,19,23,29};

void *arr_func(void* i){
    int index = *(int*)i;
    printf("The value of the array at index %d is %d\n",index,array[index]);
    free(i);
    return NULL;
}

int main(){
    pthread_t array_threads[10];
    for(int i = 0; i < 10; i++)
    {
        int *a = malloc(sizeof(int));
        *a = i;
        pthread_create(&array_threads[i],NULL,&arr_func,a);
    }
    for(int i = 0; i < 10; i++)
    {
        pthread_join(array_threads[i],NULL);
    }

    return 0;
}