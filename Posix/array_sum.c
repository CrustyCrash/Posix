#include <stdio.h>
#include <pthread.h>

int array [10] = {1,2,3,4,5,6,7,8,9,10};
int sum = 0;

void* arr_sum(){
   if(pthread_self() == 4)
   {
    printf("Thread %d is working \n",pthread_self());
    for(int i = 0; i < 5; i++)
    {
        sum=sum+array[i];
    }
   }
   else
   {
    printf("Thread %d is working \n",pthread_self());
    for(int i = 5; i < 10; i++)
    {
        sum=sum+array[i];
    }
   }
}

int main()
{
    pthread_t t1,t2;
    pthread_create(&t1,NULL,&arr_sum,NULL);
    pthread_create(&t2,NULL,&arr_sum,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    printf("Sum is : %d \n",sum);
    return 0;
}