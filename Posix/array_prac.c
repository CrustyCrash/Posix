#include <stdio.h>
#include <pthread.h>
#define N 10
int array [10] = {1,2,3,4,5,6,7,8,9,10};

void* arr_func(void *i){
    int index = (int)i;
    printf("Thread %d: %d\n", index, array[index]);
    return (void*)array[index];
}

int main(){
    pthread_t threads[N];
    int* var;
    for(int i = 0; i < 10; i++){
        pthread_create(&threads[i],NULL,&arr_func,(void*)i);
    }
    for(int i = 0; i < 10; i++){
        pthread_join(threads[i],(void**)&var);
        int result = (int)var;
        printf("Value returned from function is : %d \n",result);
    }
    return 0;
}