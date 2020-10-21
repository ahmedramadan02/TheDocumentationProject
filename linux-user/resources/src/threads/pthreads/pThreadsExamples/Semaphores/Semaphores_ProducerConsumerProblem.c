#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 100

int buffer[MAX];
int fill = 0;
int use  = 0;
int loops = 0;

void put(int value) {
    buffer[fill] = value;     
    fill = (fill + 1) % MAX;  
}

int get() {
    int tmp = buffer[use];    
    use = (use + 1) % MAX;    
    return tmp;
}

void *producer(void *arg)
{
    int i;
    for (i = 0; i < loops; i++) {
        put(i);
		usleep(1);
    }
}

void *consumer(void *arg) {
    int i;
    for (i = 0; i < loops; i++) {
        int b = get();
        printf("%d\n", b);
    }
}

int main(int argc, char *argv[])
{

    if(argc < 2 ){
        printf("Needs 2nd arg for loop count variable.\n");
        return 1;
    }

    loops = atoi(argv[1]);

    pthread_t pThread, cThread;
    pthread_create(&pThread, 0, producer, 0);
    pthread_create(&cThread, 0, consumer, 0);
    pthread_join(pThread, NULL);
    pthread_join(cThread, NULL);
    return 0;
}