#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

#define MAX 1

int buffer[MAX];
int fill = 0;
int use  = 0;

int loops = 0;

sem_t empty;
sem_t full;
sem_t mutex; //Adding MUTEX

void put(int value) {
    buffer[fill] = value;
    fill = (fill + 1) % MAX;
}

int get() {
    int b = buffer[use];
    use = (use + 1) % MAX;
    return b;
}



void *producer(void *arg) {
    int i;
    for (i = 0; i < loops; i++) {
        sem_wait(&mutex); 
        sem_wait(&empty);
        put(i);
        sem_post(&full);
        sem_post(&mutex); 
    }
}

void *consumer(void *arg) {
    int i;
    for (i = 0; i < loops; i++) {
        sem_wait(&mutex); 
        sem_wait(&full);
		
		
        int b = get();
        sem_post(&empty);
        sem_post(&mutex); 
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

    sem_init(&empty, 0, MAX); // MAX buffers are empty to begin with...
    sem_init(&full, 0, 0);    // ... and 0 are full
    sem_init(&mutex, 0, 1);    // mutex = 1 since it a lock

    pthread_t pThread, cThread;
    pthread_create(&pThread, 0, producer, 0);
    pthread_create(&cThread, 0, consumer, 0);
    pthread_join(pThread, NULL);
    pthread_join(cThread, NULL);
    return 0;
}