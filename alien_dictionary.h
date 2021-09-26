#ifndef alien_dictionary_h
#define alien__dictionary_h

//Solution written by Samira C. Oliva Madrigal
//submitted 9/25/2021

#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct vertex VERTEX;

typedef struct arc_element{
    struct vertex *dst;
    struct arc_element *next;
}ARC;

typedef struct vertex
{
    char data;
    struct vertex *next;
    struct arc_element *adj_list;
    int in_degree;
    int out_degree;
    bool in_alphabet;
}VERTEX;

typedef struct
{
    int count;
    struct vertex *source;
}GRAPH;

GRAPH *create_graph(void)
{
    GRAPH *g = (GRAPH*)malloc(sizeof(GRAPH));
    g->count = 0;
    g->source = NULL;
    return g;
}

bool search_g_list(GRAPH *g, char target)
{
    VERTEX *pre, *loc;
    
    pre = NULL;
    loc = g->source;
    while(loc && (target - loc->data) > 0)
    {
        pre = loc;
        loc = loc->next;
    }
    if(!loc || (target - loc->data) != 0)
        return false;
    else
        return true;
}

bool insert_g_list(GRAPH *g, char data_in)
{
    VERTEX *v_new, *loc, *pre;
    
    //IF ITS A DUPLICATE, JUST IGNORE IT.
    if(search_g_list(g, data_in))return true;
    
    //ELSE IT'S NEW, MALLOC A NODE
    v_new = (VERTEX*)malloc(sizeof(VERTEX));
    if(v_new)
    {
        v_new->data = data_in;
        v_new->next = NULL;
        v_new->adj_list = NULL;
        v_new->in_degree = 0;
        v_new->out_degree = 0;
        v_new->in_alphabet = false;
    }
    else
        return false;
    //INSERT @ correct location
    loc = g->source;
    if(!loc) //EMPTRY GRAPH.
        g->source = v_new;
    else
    {
        pre = NULL;
        while(loc && (data_in - loc->data) > 0)
        {
            pre = loc;
            loc = loc->next;
        }
        if(!pre)//at front
        {
            v_new->next = g->source;
            g->source = v_new;
        }
        else{//middle or end
            
            v_new->next = pre->next;
            pre->next = v_new;
        }
    }
    g->count++;
    return true;
}

int add_arc_g_list(GRAPH *g, char from, char to)
{
    ARC *a_new, *pre, *loc;
    VERTEX *src, *dst;
    
    //LOCATE FROM VERTEX
    src = g->source;
    while(src && (from - src->data) > 0)
        src = src->next;
    if(!src || (from - src->data != 0))
        return -1;
    //LOCATE THE TO VERTEX
    dst = g->source;
    while(dst && (to - dst->data) > 0)
        dst = dst->next;
    if(!dst || (to - dst->data) !=0)
        return -2;
    //CREATE ARC
    a_new = (ARC*)malloc(sizeof(ARC));
    if(!a_new)
        return -3;
    //ASSIGN ARC ITS DST
    a_new->dst = dst;
    //ADD ARC TO THE ADJACENCY LIST OF SRC.
    loc = src->adj_list;
    if(loc == NULL)
    {
        src->adj_list = a_new;
        a_new->next = NULL;
    }
    else
    {
        pre = NULL;
        while(loc && (to - loc->dst->data) > 0)
        {
            pre = loc;
            loc = loc->next;
        }
        if(loc && (to - loc->dst->data) == 0) //NO DUPLICATED EDGES
            return 1;
        else
        {
            if(!pre)
                src->adj_list = a_new;//at front
            else
                pre->next = a_new;//middle or end
            a_new->next = loc;
        }
    }
    //update degrees
    src->out_degree++;
    dst->in_degree++;

    return 1;
}

//delete vertex with in_degree = 0.
int delete_orphan(GRAPH *g, char target)
{
    VERTEX *pre, *loc;
    ARC *a, *b;
    
    if(g->count == 0) return -1;
    
    //locate target
    pre = NULL;
    loc = g->source;
    while(loc && (target - loc->data) > 0)
    {
        pre = loc;
        loc = loc->next;
    }
    //use short circuit if key not found
    if(!loc || (target - loc->data) != 0)
        return -1;
    if(loc->out_degree > 0)
    {   //update the degree of the neighbors
        a = loc->adj_list;
        while(a)
        {
            a->dst->in_degree--;
            a = a->next;
        }
        //then delete the ajacency linked list of ARC nodes for this vertex.
        b = a = loc->adj_list;
        while(a)
        {
            a = a->next;
            free(b);
            b = a;
        }
    }
    if(!pre)//delete @ front
        g->source = g->source->next;
    else//delete @ middle or end
        pre->next = pre->next->next;
    g->count--;
    free(loc);
    return +1;
}

//"PRUNE" NODES WITHOUT A PREDESESSOR.
bool traverse_orphan_nodes(GRAPH *g,  char *output, int *start)
{
    VERTEX *v, *del;
    char del_data;
    bool cycle = true;
    
    v = g->source;
    while(v)
    {
        if(v->in_degree == 0 && !v->in_alphabet)
        {
            output[(*start)++] = v->data;
            //printf("%d~%c \n", (*start)-1, v->data);
            v->in_alphabet = true;
            cycle = false;
        }
        v = v->next;
    }
    //so not affect order
    v = del = g->source;
    while(v)
    {
        if(v->in_alphabet)
        {
            del_data = v->data;
            v = v->next;
            delete_orphan(g, del_data);
        }
        else
            v = v->next;
    }
    return cycle;
}

void traverse_directed_list(GRAPH *g)
{
    //PRINT OUT OF ALL VERTICES AND ADJ
    VERTEX *v;
    ARC *a;
    
    v = g->source;
    while(v)
    {
        printf("(");
        printf("%c:%d:%d", v->data, v->in_degree, v->out_degree);
        printf(")");
        if(v->adj_list)
        {
            printf(":");
            a = v->adj_list;
            while(a)
            {
                printf("%c ", a->dst->data);
                a = a->next;
            }
        }
        printf("\n");
        v = v->next;
    }
}

GRAPH *build_my_graph(char **set, int size, char *extras, int extras_size)
{
    GRAPH *g;
    g = create_graph();
    for(int i = 0; i < size; i++)
    {
        insert_g_list(g, set[i][0]); //add vertices
        insert_g_list(g, set[i][1]); //add vertices
    }
    //add in the extras
    if(extras)//IF NOT NULL
    {
        for(int i = 0; i < extras_size; i++)
        {
            printf("%c", extras[i]);
            insert_g_list(g, extras[i]);
        }
    }
    for(int i = 0; i < size; i++)//add adj lists
    {
        if(set[i][0] != set[i][1])
            add_arc_g_list(g, set[i][0], set[i][1]);
    }
    return g;
}

// abcd
// abc
char **build_releations_set(char **words, int set_size, char **extras, int *k)
{
    char *wi, *wi1, **set;
    int new_size, len1, len2;
    bool found;
    bool cmp_done;
    

    //array of strings of LEN 2 or lists of 2 char.
    set = (char**)malloc(set_size*sizeof(char*));
    wi = words[0];
    for(int i = 1; i <= set_size; i++)
    {
        //compare adjacent words
        cmp_done = false;
        wi1 = words[i];
        len1 = (int)strlen(wi);
        len2 = (int)strlen(wi1);
        while(!cmp_done)
        {
            if(*wi && *wi1)// if != '\0'
            {
                if(*wi == *wi1)
                {
                    len1--;len2--;
                    if(len1 > 0) wi++;
                    if(len2 > 0) wi1++;
                    
                    if(len1 == 0 || len2 == 0)
                        cmp_done = true;
                }
                else//first non-equal
                    cmp_done = true;
            }
            else
                cmp_done = true;
        }
        set[i-1] = (char*)malloc(2*sizeof(char));
        set[i-1][0] = *wi;
        set[i-1][1] = *wi1;
        wi = words[i];
        printf("%d: %c -> %c\n", i-1, set[i-1][0], set[i-1][1]);
    }
    
    //what happends if as we build the relations, we skipped characters :o
    //we must account for those
    //since the problem says that each word be up to 100 chars...
    //and there can be up to 100 words...
    //max chars we can have is 100*100 = 10000... clearly an array of this
    //size for starting is not resasonable.
    
    //keep track of any extras
    //because they have no in/out degree we can just keep them in sep arry
    //and pass on to build graph.
    *k = 0;
    new_size = set_size;
    for(int i = 0; i <= set_size; i++)
    {
        for(wi = words[i]; *wi; wi++)//for each CHAR in a WORD
        {
            found = false;
            for(int j = 0; j < set_size; j++)//scan the entire SET.
            {
                if((*wi == set[j][0]) || (*wi == set[j][1]))
                    found = true;
            }
            if(!found)
            {
                for(int e = 0; e < *k; e++)
                    if(*wi == (*extras)[e])
                        found = true;//no duplicates
                if(!found)//if not already in our extras, add it.
                {
                    (*extras)[*k] = *wi;
                    (*k)++;
                    printf("EXTRA (%d): %c\n", (*k)-1, (*extras)[(*k)-1]);
                }
            }
            if(*k == new_size)
            {
                new_size += set_size;//INC by this amount each time.
                *extras = realloc(*extras, new_size);
           }
        }
    }
    if(*k > 0)
    {
        if(*k < new_size)//shrink it
            (*extras) = realloc((*extras), *k);
        for(int i = 0; i < *k; i++)
            printf("found: %c \n", (*extras)[i]);
    }
    if(*k == 0)
    {
        free(*extras);
        (*extras) = NULL;
    }
   return set;
}

bool all_the_same(char *input)
{
    int strLen, count;
    strLen = (int)strlen(input);
    count = 0;
    for(int i = 1 ; i < strLen; i++)
    {
        if(input[i-1] != input[i])
            return false;
    }
    return true;
}

/* we could use a trie or string manipulation */
#define INVALID_LEXICON "INVALID LEXICON!!\n"
bool scan_for_invalid_prefix(char **words, int wordsSize)
{
    int strLen, strLen2;
    char *prefix, *addr;
    bool condition1, condition2;
    
    //since prefixes vary in length....
    prefix = words[0];
    strLen = (int)strlen(prefix);
    for(int i = 1; i <  wordsSize; i++)
    {
        strLen2 = (int)strlen(words[i]);
        condition1 = (strLen > 1 && strLen2 == 1 && *prefix == words[i][0]);
        addr =  strstr(prefix, words[i]);//address to start of substring
        condition2 = (strLen > 1 && strLen2 > 1 && addr && addr == prefix);
        if(condition1 || condition2)
        {
            printf("WORD %d FOLLOWED BY PREFIX WORD %d!", i-1, i);
            return true;
        }
        strLen = (int)strlen(words[i]);
        prefix = words[i];
    }
    return false;
}

//same as detecting a cycle in a graph with DFS but we want to detect this
//before we even build the relations set and the graph..
bool scan_for_invalid_order(char **words, int wordsSize)
{
    char *wi;
    
    for(int i = 0; i <  wordsSize; i++)
    {
        wi = words[i];
        for(int j = i + 2; j < wordsSize; j++)//basically, if at any point, hit duplicate, => invalid order.
        {
            
            if((strlen(wi) >= 1) && (strlen(words[j]) >= 1) && (strcmp(wi, words[j]) == 0)) //z x (z) has to be at least one apart.
            {
                //printf("word %d after word %d are the same!",j, i);
                if(strlen(words[j]) >= 1 && strcmp( words[j], words[j-1]) != 0)
                    return true;
            }
        }
    }
    return false;
}

void selection_sort(char *ary, int last)
{
    int cur, mov, smallest, hold;
    
    for(cur = 0; cur < last; cur++)
    {
        smallest = cur;
        for(mov = cur + 1; mov <= last; mov++)
            if(ary[mov] < ary[smallest])
                smallest = mov;
        hold =  ary[cur];
        ary[cur] = ary[smallest];
        ary[smallest] = hold;
    }
}

char *extract_unique_chars(char *word)
{
    char *alpha, *p, *r, *q;
    int strLen, count;
    
    strLen = (int)strlen(word);
    alpha = malloc(sizeof(char)*(strLen));
    
    char wp[strLen];
    strncpy(wp, word, strLen);
    selection_sort(wp,strLen-1);
    
    p = wp;
    r = alpha;
    count = 0;
    for(int i = 1; i < strLen; i++)
    {
        q = wp + i;
        if(*p != *q)
        {
            *r = *p; r++; count++;
            p = q; q++;
            if(i == strLen-1)
            {
                *r = *p;
                count++;
            }
        }
    }
    
    alpha = realloc(alpha, count+1);
    *(alpha + count) = '\0';
    
    return alpha;
}

bool if_bundles(char **set, int set_size)
{
    for(int i = 1; i < set_size; i++)
    {
        if(set[i-1][0] != set[i-1][1] && strncmp(set[i-1], set[i], 2) == 0)
            return true;
    }
    return false;
}

// 1 2 3 4 5 1
char * alien_lexicon(char ** words, int wordsSize)
{
    GRAPH *g;
    int set_size, extras_size, idx, outSize;
    char *extras, **set, *out;
    bool cycle;
    
    //STEP 1) VERIFY WE HAVE A VALID LEXICON
    //before we do anything, ensure alien alphabet is valid
    //and no prefix of a word is contained
    if(scan_for_invalid_prefix(words, wordsSize) || scan_for_invalid_order(words, wordsSize))
        return "";//empty string
    
    if(wordsSize == 1) return extract_unique_chars(words[0]);
    
    //STEP 2) BUILD A SET OF RELATIONS AND ACCOUNT FOR SINGLE CHARS (those with degree == 0 )
    set_size = wordsSize-1;
    extras = calloc(set_size, sizeof(char));//initialize to this size.
    extras_size = 0;
    set = build_releations_set(words, set_size, &extras, &extras_size);
    
    if(if_bundles(set, set_size))
    {
        if(extras)
            free(extras);
        free(set);
        return "";
    }
    
    //STEP 3) REPRESENT RELATIONS IN A GRAPH.
    g = build_my_graph(set, set_size, extras, extras_size);
    traverse_directed_list(g);
    
    //STEP 4) "PRUNE THE TREE" and ADD to output
    char output[g->count];
    outSize = g->count;
    idx = 0;
    cycle = false;
    while(g->count > 0 && !cycle)
    {
        cycle = traverse_orphan_nodes(g, output, &idx);
        //traverse_directed_list(g);
    }
    if(cycle) return "";//INVALID lexicon
    
    //BTW, expected output is a STRING not an true array of chars.
    out =  (char*)malloc(sizeof(char)*(outSize+1));
    strncpy(out, output, outSize);
    *(out + outSize) = '\0';
    if(extras)
        free(extras);
    free(set);
    free(g);
    return out;
}

/*
PREFIX TC:
ca, c invalid
ca, cc valid

when both string > 1:
ca, cc (valid) a-->c relation.
(ab)c, (ab) invalid because prefix from start
abc, bc valid
["aa", "a"]
["wrt","wrf","er","ett","rftt"]
["z","x"]
["z","x","z"]
["z", "z", "z"]
["bc","b","cbc"]
["aa","a","ab"]
["a", "aa"]
["ac","ab","b"]
["ac","ababa","b"]
["aa", "a"]
["ab", "b"]
["ab", "a"]
["abc","ab"]
["ca", "cd"]
["ca", "ccccccccc"]
["ca", "c"]
["a","b","ca","cc"]
["a","b","ca","cc"]
*/
#endif /* alien_lexicon_working_h */
