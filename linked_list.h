#ifndef linked_list_h
#define linked_list_h

typedef struct ll_node
{
    void *data;
    struct ll_node *next;
    
}LL_NODE;

typedef struct list
{
    LL_NODE *front;
    int (*compare)(void *a, void *b);
    void (*process)(void *data);
    int count;
    
}LIST;

LIST *create_linked_list(int (*compare)(void *a, void *b), void (*process)(void *data))
{
    LIST *list = (LIST*)malloc(sizeof(LIST));
    if(!list)
    {
        exit(101);
    }
    list->front = NULL;
    list->compare = compare;
    list->process = process;
    list->count = 0;
    return list;
}

bool search_linked_list(LIST *list, void *target, LL_NODE **pre, LL_NODE **cur)
{
    *pre = NULL;
    
    if(!list->front)
        return false;
    
    *cur = list->front;
    while(*cur && list->compare((*cur)->data, target) < 0)
    {
        *pre = *cur;
        *cur = (*cur)->next;
    }
    
    if(*cur && list->compare((*cur)->data, target) == 0)
        return true;
    
    return false;
    
}

bool insert_to_linked_list(LIST *list, void *data_in)
{
    LL_NODE *pre, *cur, *new_node;
    
    if(search_linked_list(list, data_in, &pre, &cur))
        return false;//no duplicates
    
    new_node = (LL_NODE*)malloc(sizeof(LL_NODE));
    if(!new_node)
        return false;
    
    new_node->data = data_in;
    
    if(!pre)//empty or at start
    {
        new_node->next = list->front;
        list->front = new_node;
    }
    else
    {
        new_node->next = pre->next;
        pre->next = new_node;
    }
    list->count++;
    return true;
    
}

bool remove_from_linked_list(LIST *list, void **data_out)
{
    LL_NODE *pre, *cur;
    
    
    if(!search_linked_list(list, data_out, &pre, &cur))
        return false;//not found
    
    *data_out = cur->data;
    if(!pre)
        list->front = list->front->next;
    else
        pre->next = cur->next;//NULL
    free(cur);
    list->count--;
    return true;
}

void free_linked_list(LIST *list)
{
    LL_NODE *cur, *next;
    
    cur = list->front;
    while(cur)
    {
        next= cur->next;
        free(cur);
        cur = next;
    }
    list->count = 0;
    list->front = NULL;    
}

void traverse_linked_list(LIST *list)
{
    
    for(LL_NODE *mov = list->front; mov; mov = mov->next)
    {
        //process method... app specific
        list->process(mov->data);
    }
    
}

#endif /* linked_list_h */
