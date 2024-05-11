#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

void *dice(){
   long res = (rand()%6) + 1;
   return (void*)res;
}

int main(){
    srand(time(NULL));
    int *result;
    int sum = 0 ;
    pthread_t thread[4];
    for(int i = 0; i < 4; i++){
        pthread_create(&thread[i],NULL,&dice,NULL);
    }
    for(int i = 0; i < 4; i++){
        pthread_join(thread[i],(void**)&result);
        printf("%d\n",(int)result);
        sum = sum + (int)result;
    }
    printf("%d",sum);
}