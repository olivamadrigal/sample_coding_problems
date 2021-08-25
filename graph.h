#ifndef graph_h
#define graph_h
#include "stack.h"
#include "queue.h"

//ADJACENCY LIST VERSION
typedef struct arc
{
    struct vertex *dest;
    struct arc *next;
    int weight;
    bool in_mst;
}ARC;

typedef struct vertex
{
    void *data;
    struct vertex *next;
    ARC *adj_list;
    int in_degree;
    int out_degree;
    int degree;
    int processed;//traversals and mst same as in_mst

}VERTEX;

typedef struct graph
{
    VERTEX *source;//source
    int (*compare)(void *arg1, void *arg2);
    void (*process)(void *data);
    int count;
    int arc_count;
}GRAPH;

GRAPH *create_graph(int (*compare)(void *arg1, void *arg2), void (*process)(void *data))
{
    GRAPH *g = (GRAPH*)malloc(sizeof(GRAPH));
    
    g->source = NULL;
    g->compare = compare;
    g->process = process;
    g->count = 0;
    g->arc_count = 0;
    return g;
}


bool insert_to_graph(GRAPH *g, void *data_in)
{
    VERTEX *v_new, *loc, *pre;
    bool success = false;
    
    v_new = (VERTEX*)malloc(sizeof(VERTEX)); //use wrappers Malloc
    v_new->data = data_in;
    v_new->next = NULL;
    v_new->adj_list = NULL;
    v_new->in_degree = 0;
    v_new->out_degree  = 0;
    v_new->degree = 0;
    g->count++;
    
    //look for correct location in list
    loc = g->source;
    if(!loc)
    {
        g->source = v_new;
        success = true;
    }
    else
    {   //SEARCH THE LIST
        pre = NULL;
        while(loc && g->compare(data_in, loc->data) > 0)
        {
            pre = loc;
            loc = loc->next;
        }
        if(!pre)
        {
            v_new->next = g->source;
            g->source = v_new;
        }
        else
        {
            v_new->next = pre->next;
            pre->next = v_new;
        }
        success = true;
    }
    return success;
}

int delete_from_graph(GRAPH *g, void *target)
{
    VERTEX *pre, *loc;
    
    if(g->count ==0)
        return 0;//empty graph
    
    //LOCATE TARGET
    pre = NULL;
    loc = g->source;
    while(loc && (g->compare(target, loc->data) > 0))
    {
        pre = loc;
        loc = loc->next;
    }
    if(!loc || g->compare(target, loc->data) != 0)
        return -1;//not found
    if(loc->degree != 0)
        return -2;//cannot remove vertext with non-zero degree
    if(!pre)
        g->source = g->source->next;//del at front
    else
        pre->next = pre->next->next;
    g->count--;
    free(loc);
    return +1;
}

int add_arc_to_list(GRAPH *g, void *from, void *to, int weight)
{
    ARC *a_new, *pre, *loc;
    VERTEX *src, *dst;
    
    //locate the from vertex
    src = g->source;
    while(src && g->compare(from, src->data) > 0)
        src = src->next;
    if(!src || (g->compare(from, src->data) !=0))
        return -1;//from vertext not found
    
    //locate dst vertex
    dst = g->source;
    while(dst && g->compare(to, dst->data) > 0)
        dst = dst->next;
    if(!dst || (g->compare(to, dst->data) !=0 ))
        return -2;//to vertext not found
    
    //create new arc
    a_new = (ARC*)malloc(sizeof(ARC));
    if(!a_new)
    {
        //malloc err message
        return -3;
    }
    a_new->dest = dst;//destination vertex
    a_new->weight = weight;
    // now insert @ correct location in the source vertex's adj list
    loc = src->adj_list;
    if(!loc) //IF adj list empty
    {
        src->adj_list = a_new;
        a_new->next = NULL;
    }
    else
    {//SEARCH FOR CORRECT LOCATION
        pre = NULL;
        //compare all arcs in this adj list
        while(loc && g->compare(to, loc->dest->data) > 0)
        {
            pre = loc;
            loc = loc->next;
        }
        if(!pre)
            src->adj_list = a_new;
        else
            pre->next = a_new;
        a_new->next = loc;
    }
    //update degress
    src->out_degree++;
    src->degree = src->in_degree + src->out_degree;
    dst->in_degree++;
    dst->degree = dst->in_degree + dst->out_degree;
    return 1;
}

int del_arc_from_graph(GRAPH *g, void *from, void *to)
{
    ARC *pre, *loc;
    VERTEX *src, *dst;
    
    //VERIFY SRC AND DST VERTICES
    src = g->source;
    while(src && (g->compare(from, src->data) > 0))
        src = src->next;
    if(!src || (g->compare(from, src->data) !=0))
        return -1;//SRC VERTEX NOT FOUND
    dst = g->source;
    while(dst && (g->compare(to, dst->data) > 0))
        dst = dst->next;
    if(!dst || (g->compare(to, dst->data) != 0))
        return -2;
    
    //LOCATE ARC & delete arc on the src list
    loc = src->adj_list;
    if(!loc)
        return -3;//arc list empty
    pre = NULL;
    while(loc && (g->compare(loc->dest->data, to) > 0))
    {
        pre = loc;
        loc = loc->next;
    }
    if(!loc || g->compare(loc->dest->data, to) != 0)
        return -4;//arc not found
    if(!pre)
        src->adj_list = src->adj_list->next;//
    else
        pre->next = pre->next->next;
    free(loc);
    return 1;
}

void delete_list_directed_graph(GRAPH *g)
{
    VERTEX *pre, *cur;
    ARC *p, *c;
    
    pre = cur = g->source;
    while(cur)
    {
        if(cur->adj_list)
        {
            p = c = cur->adj_list;
            while(c)
            {
                c = c->next;
                free(p);
                p = c;
            }
        }
        cur = cur->next;
        free(pre);
        pre = cur;
    }
}



#endif /* graph_h */
