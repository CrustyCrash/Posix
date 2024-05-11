#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;

void *func()
{
    for (int i = 0; i < 1000000; i++)
    {
        pthread_mutex_lock(&mutex);
        counter++;
        pthread_mutex_unlock(&mutex);
    }
}

int main()
{
    //pthread_mutex_init(&mutex, NULL);

    pthread_t threads[4];
    
    for(int i = 0; i<4; i++){
       pthread_create(&threads[i],NULL,func,NULL);
       printf("Starting thread %d \n",i); 
    }
    for(int i = 0; i<4; i++){
       pthread_join(threads[i],NULL);
       printf("Ending thread %d \n",i); 
    }
    printf("counter = %d\n",counter);
    //pthread_mutex_destroy(&mutex);
    return 0;
}