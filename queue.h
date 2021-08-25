#ifndef queue_h
#define queue_h

#define MALLOC_ERROR_101 printf("ERROR ALLOCATING NEW NODE!!!!!\n");

typedef struct qnode
{
    void *data;
    struct qnode *next;
}QNODE;

typedef struct queue
{
    QNODE *front;
    QNODE *rear;
    void (*process)(void *data);
    int (*compare)(void *a, void *b);
    int count;
}QUEUE;


QUEUE *create_queue(int (*compare)(void *a, void *b), void (*process)(void *data))
{
    
    QUEUE *q = (QUEUE*)malloc(sizeof(QUEUE));
    if(!q)
    {
        MALLOC_ERROR_101;
        exit(101);
    }
    q->front = q->rear = NULL;
    q->process = process;
    q->compare = compare;
    q->count = 0;
    
    return q;

}

void enqueue(QUEUE *q, void *data_in)
{
    
    QNODE *qn = (QNODE*)malloc(sizeof(QNODE));
    qn->data = data_in;
    
    if(!qn)
    {
        MALLOC_ERROR_101;
        exit(101);
    }
    
    qn->next = NULL;
    if(!q->front)
        q->front = q->rear = qn;
    else
    {
        q->rear->next = qn;
        q->rear = qn;
    }
    q->count++;

}

void *dequeue(QUEUE *q)
{
    void *data_out;
    QNODE *del_data;
    
    if(!q->front)
        return NULL;
    else
    {
        del_data = q->front;
        q->front = q->front->next;
        data_out = del_data->data;
        free(del_data);
        q->count--;
    }
    if(q->count == 0)
        q->rear = NULL;
    return data_out;
}


bool is_queue_empty(QUEUE *q)
{
    return (q->count == 0)? true:false;
}

void delete_queue(QUEUE *q)
{
    if(q->count == 0)
    {
        free(q);
        return;
    }
    while(!is_queue_empty(q))
        dequeue(q);    
    free(q);
}
#endif /* queue_h */
