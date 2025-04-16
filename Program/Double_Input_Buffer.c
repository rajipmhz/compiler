#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024  // Read 1KB at a time

char buffer1[BUFFER_SIZE], buffer2[BUFFER_SIZE];  // Two buffers
int activeBuffer = 1;  // Track which buffer is being used
int dataAvailable = 0;  // Flag to indicate data availability

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

// Function to simulate log file processing
void processLog(char *data) {
    char *line = strtok(data, "\n");
    while (line) {
        printf("[Processed] %s\n", line);  // Process each line
        line = strtok(NULL, "\n");
    }
}

// Producer thread: Reads data from file into buffer
void *readData(void *file) {
    FILE *fp = (FILE *)file;
    while (1) {
        pthread_mutex_lock(&mutex);
        
        char *targetBuffer = (activeBuffer == 1) ? buffer1 : buffer2;
        size_t bytesRead = fread(targetBuffer, 1, BUFFER_SIZE - 1, fp);
        targetBuffer[bytesRead] = '\0'; // Null-terminate the string

        if (bytesRead == 0) {  // EOF reached
            dataAvailable = -1;
            pthread_cond_signal(&cond);
            pthread_mutex_unlock(&mutex);
            break;
        }

        dataAvailable = 1; // Mark data as available
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);

        activeBuffer = (activeBuffer == 1) ? 2 : 1; // Switch buffer
        usleep(100000); // Simulate reading delay
    }
    return NULL;
}

// Consumer thread: Processes data from the buffer
void *processData(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex);

        while (dataAvailable == 0) {  // Wait until data is available
            pthread_cond_wait(&cond, &mutex);
        }

        if (dataAvailable == -1) {  // EOF reached
            pthread_mutex_unlock(&mutex);
            break;
        }

        char *processingBuffer = (activeBuffer == 1) ? buffer2 : buffer1;
        printf("\n[Processing Buffer %d]\n", (activeBuffer == 1) ? 2 : 1);
        processLog(processingBuffer);

        dataAvailable = 0; // Mark as processed
        pthread_mutex_unlock(&mutex);

        usleep(200000); // Simulate processing delay
    }
    return NULL;
}

int main() {
    FILE *file = fopen("server.log", "r");
    if (!file) {
        perror("Failed to open log file");
        return 1;
    }

    pthread_t readerThread, processorThread;
    
    // Create threads
    pthread_create(&readerThread, NULL, readData, file);
    pthread_create(&processorThread, NULL, processData, NULL);

    // Wait for threads to finish
    pthread_join(readerThread, NULL);
    pthread_join(processorThread, NULL);

    fclose(file);
    return 0;
}

