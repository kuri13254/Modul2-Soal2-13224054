#include <stdio.h>
#include <stdbool.h>

#define MAX 1000

typedef struct {
    int listTertutup[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

bool isEmpty(Queue *q) {
    return (q->front == q->rear);
}

void enqueue(Queue *q, int Tinggi) {
    q->listTertutup[q->rear++] = Tinggi;
    q->rear++;
}

void bungaTertutup(Queue *q){
    if (isEmpty(q))
    {
        printf("NONE\n");
        return;
    }

    for (int i = q->front; i < q->rear; i++)
    {
        printf("%d", q->listTertutup[i]);
    }
    printf("\n");
}

int main(){
    Queue q;
    initQueue(&q);
    int listBunga[MAX];

    printf("Input data Tinggi: \n");
    scanf("%d", listBunga);
    int length = sizeof(listBunga);

    for(int i = 2; i<length-1; i++){
        if(listBunga[i]<listBunga[i-1] && listBunga[i]<listBunga[i+1]){
            enqueue(&q, listBunga[i]);
        }
    }
    bungaTertutup(&q);

    return 0;
}
