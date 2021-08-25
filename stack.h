#ifndef stack_h
#define stack_h

typedef struct snode
{
    void *data;
    struct snode *next;
    
}SNODE;


typedef struct stack
{
    SNODE *top;
    int (*compare)(void *arg1, void *arg2);
    void (*process)(void *data);
    int count;
}STACK;

#define STACK_MEMORY_ALLOC_ERR printf("ERROR ALLOCATING NEW NODE FOR STAC");

//5:20
STACK *create_stack(int (*compare)(void *arg1, void *arg2), void (*process)(void *data))
{
    STACK *s = (STACK*)malloc(sizeof(STACK));
    
    if(!s)
    {
        STACK_MEMORY_ALLOC_ERR;
        exit(101);
    }
    s->top = NULL;
    s->compare = compare;
    s->process = process;
    
    return s;
}


bool is_stack_empty(STACK *s)
{
    return (s->count == 0) ? true: false;
}


void push(STACK *s, void *data_in)
{
    SNODE *new_node = (SNODE*)malloc(sizeof(SNODE));
    
    if(!new_node)
    {
        STACK_MEMORY_ALLOC_ERR;
        exit(101);
    }
    
    new_node->data = data_in;
    new_node->next = NULL;
    
    if(!s->top)
        s->top = new_node;
    else
    {
        new_node->next = s->top;
        s->top = new_node;
    }
    s->count++;
    
}

void *pop(STACK *s)
{
    SNODE *del_node;
    void *data_out;
    
    if(!s->top)
        return NULL;
    
    del_node = s->top;
    data_out = del_node->data;
    s->top = s->top->next;
    free(del_node);
    s->count--;
    return data_out;
    
}

void free_stack(STACK *s)
{
    while(!is_stack_empty(s))
        pop(s);
    free(s);
}

#endif /* stack_h */
