#include<stdio.h>
#include<pthread.h>
#include<sys/time.h>
#include<stdlib.h>
int max_ele=0;
#define arrSize 1000000
#define Th_max 1
int a[arrSize];
int thread_no = 0;
void *maximum(void* arg)
{
    int i,num=thread_no++;
    int maxs = 0;

    for(i=(num*arrSize)/Th_max;i<((num+1)*arrSize)/Th_max;i++){
    if(a[i]>max_ele)
    max_ele=a[i];
    }
}
int main()
{
int i;
struct timeval ini_tv,final_tv;

pthread_t threads[Th_max];
for(i=0;i<arrSize;i++)
{
a[i]=i;
}
gettimeofday(&ini_tv,NULL);
for(i=0;i<Th_max;i++)
    pthread_create(&threads[i],NULL,maximum, (void*)NULL);
for(i=0;i<Th_max;i++)
pthread_join(threads[i],NULL);

gettimeofday(&final_tv,NULL);

printf("Total time Taken=%ld\n",final_tv.tv_sec-ini_tv.tv_sec);
printf("Maximun Element is : %d", max_ele);

    return 0;
}
