#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 1

int buffer[MAX];
int fill = 0;
int use  = 0;
int loops = 0;

sem_t empty;
sem_t full;
//sem_t mutex; //Adding MUTEX
pthread_mutex_t mutex;
int first_cycle = 0;

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
		sem_wait(&empty);
		
		//sem_wait(&mutex);
		//pthread_mutex_lock(&mutex);
        put(i);
		printf("Data Set from %s, Data=%d\n", (char*) arg, i);
        //sem_post(&mutex);
		//pthread_mutex_unlock(&mutex);
		
		sem_post(&full);
    }
}

void *consumer(void *arg) {
    int i;
    for (i = 0; i < loops; i++) {
        sem_wait(&full);
		
		//sem_wait(&mutex);
		//pthread_mutex_lock(&mutex);
        int b = get();
		printf("Data recieved from %s, %d\n", (char*) arg, b);
		//printf("%d\n", b);
		//sem_post(&mutex);
		//pthread_mutex_unlock(&mutex);
		
        sem_post(&empty);
        
    }
}

int main(int argc, char *argv[])
{
    if(argc < 2 ){
        printf("Needs 2nd arg for loop count variable.\n");
        return 1;
    }

    loops = atoi(argv[1]);

    sem_init(&empty, 0, 3); 
    sem_init(&full, 0, 0);    
	//sem_init(&mutex, 0, 1);
	pthread_mutex_init(&mutex, NULL);

	pthread_t pThreads[3];
	pthread_t cThreads[3];
	
	
	pthread_create(&cThreads[0], 0, consumer, (void*)"Consumer1");
	pthread_create(&cThreads[1], 0, consumer, (void*)"Consumer2");
	pthread_create(&cThreads[2], 0, consumer, (void*)"Consumer3");
	
	//Passing the name of the thread as paramter, Ignore attr
    pthread_create(&pThreads[0], 0, producer, (void*)"Producer1");
	pthread_create(&pThreads[1], 0, producer, (void*)"Producer2");
	pthread_create(&pThreads[2], 0, producer, (void*)"Producer3");
	

    pthread_join(pThreads[0], NULL);
	pthread_join(pThreads[1], NULL);
	pthread_join(pThreads[2], NULL);
	
    pthread_join(cThreads[0], NULL);
	pthread_join(cThreads[1], NULL);
	pthread_join(cThreads[2], NULL);
    
	return 0;
}