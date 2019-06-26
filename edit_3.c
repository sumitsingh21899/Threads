#include<stdio.h>
#include<pthread.h>
#include<sys/time.h>
#include<stdlib.h>
unsigned long long  maxs=0;
#define arrSize 1000000
#define Th_max 1
unsigned long long a[arrSize];
unsigned long long max_num[Th_max]={0};
int thread_no = 0;
void *maximum(void* arg)
{
    unsigned long long i,num=thread_no++;


    for(i=(num*arrSize)/Th_max;i<((num+1)*arrSize)/Th_max;i++){
    if(a[i]>maxs)
    maxs=a[i];
    }
    max_num[num]=maxs;
}
int main()
{
unsigned long long i,maxs=0;
struct timeval ini_tv,final_tv;

pthread_t threads[Th_max];
for(i=0;i<arrSize;i++)
{
//a[i]=i;
a[i]=rand()%100007;
}
gettimeofday(&ini_tv,NULL);
for(i=0;i<Th_max;i++)
    pthread_create(&threads[i],NULL,maximum, (void*)NULL);
for(i=0;i<Th_max;i++)
pthread_join(threads[i],NULL);
for (i = 0; i < Th_max; i++) {
        if (max_num[i] > maxs)
            maxs = max_num[i];
}

gettimeofday(&final_tv,NULL);

printf("Total time Taken=%ld\n",final_tv.tv_sec-ini_tv.tv_sec);
printf("Maximun Element is : %llu", maxs);

    return 0;
}
