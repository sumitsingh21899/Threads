#include<stdio.h>
#include<pthread.h>
#include<sys/time.h>
#include<stdlib.h>
//long long int max_ele=0;
#define arrSize 1000
#define Th_max 4
unsigned char a[arrSize];
long long int max_num[Th_max]={0};
int thread_no = 0;
void *maximum(void* arg)
{
    int i,num=thread_no++;
    int maxs = 0;

    for(i=(num*arrSize)/Th_max;i<((num+1)*arrSize)/Th_max;i++){
    if(a[i]>maxs)
    maxs=a[i];
    }
max_num[num]=maxs;
}
int main()
{
long long int maxs = 0;
long long int i;

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
for (i = 0; i < Th_max; i++) {
        if (max_num[i] > maxs)
            maxs = max_num[i];

}
printf("\n\n");
gettimeofday(&final_tv,NULL);

printf("Total time Taken=%ld\n",final_tv.tv_sec-ini_tv.tv_sec);
printf("Maximun Element is : %lld\n\n", maxs);

    return 0;
}
