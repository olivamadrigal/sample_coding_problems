#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "linked_list.h"
#include "queue.h"
#include "graph.h"
#include "alien_dictionary.h"

/* STRING MANIPULATION, MATH, SEARCH, TREE, AND GRAPH EXERCISES */

typedef struct pair
{
    int a;
    int b;
    int count;
    int set;
    int value;
}PAIR;

typedef struct ht
{
    int n;
    int size;
    PAIR **ary;
}HT;

typedef struct node
{
    void *data;
    struct node* right;
    struct node* left;
}NODE;


typedef struct bst
{
    NODE *root;
    int count;
}BST;

typedef struct knode{
    int weight;
    int value;
    bool traversed;
    struct knode *next;
}KNODE;


#define PRINT_TEST printf("TESTING!!!\n");
#define MAX_LINE 80

void cubic_solution(HT *hash_table);
void search_permutations(char *pattern, char *str);
bool two_strings_permunations(char *s1, char *s2);
bool is_permuation_a_palindrome(char *input);
char *string_compression(char *input);
int get_next_prime(bool *flags, int size, int prime);
bool *sieve_of_eratosthenes(int max);
NODE *create_min_bst(int *ary, int start, int end);
bool compare(char freq_cp[], char freq_cw[]);
bool str_has_unique_chars(char *input);
int ch_cmp(const void *a, const void *b);
char *string_compression(char *input);
uint8_t insert_8bint(uint8_t M, uint8_t N, int s, int e);
void next_number(uint8_t n);
bool is_prime(int n);
void init_flags(bool *ary, int size);
void cross_off(bool *flags, int size, int prime);
int get_next_prime(bool *flags, int size, int prime);
bool *sieve_of_eratosthenes(int max);
NODE *create_min_bst(int *ary, int start, int end);
void traverse_tree(NODE *root);
int gcmp(void *a, void *b);
void list_all_neighbors_at_depth(BST *tree, int depth, int (*compare)(void *a, void *b), void (*process)(void *data));
void process(void *data);
bool is_valid_bst(NODE *n, void *last_printed);
void two_sum(int ary[], int size,  int target, int *pRes);
void three_sum(int ary[], int size,  int target, int *pRes);
int find_missing_number_using_summation_formula(int *ary, int size);
int find_missing_number_without_overflow(int *ary, int size);
int find_missing_number_using_xor_technique(int *ary, int size);
//knapsack
int cached_recursive_knapsack_01(int i, int j, int w[], int v[], int n, int W, int z[n][W]);
int knapsack_0_1_r(int i, int j, int w[], int v[], int r, int c, int z[r][c]);
int hashed_cache_recursive_knapsack_01(int w[], int v[], int n, int c, int z[n][c], int W, int i);
int naive_recursive_knapsack_01(int v[], int w[], int n, int W, int i);
int knapsack_01_iterative(int v[], int w[], int n, int W);
int knapsack(KNODE *list, int length, int max_weight, int combinations);
KNODE* read_knapsack_input_file(char *filename);
void find_sentences_which_contain_all_words_in_a_phrase(char **sentences, int s_len,  char **phrases, int p_len);
char *reverse_characters_in_a_word(char *word);
void reverse_words_in_sentence(char *sentence);
bool is_there_path_from_A_to_B_BFS_for_DAG(GRAPH *g, void *A, void *B);
int gcompare(void *arg1, void *arg2);
void process(void *data);



#define KNAPSACK_INPUT_FILE "knapsack_input.in"
int main(int argc, const char * argv[])
{
    
    /*
    puts("FIND SOLUTIONS TO THE EQUATION: A^3 + B^3 = C^3 + D^3");
    HT *hash_table = (HT*)malloc(sizeof(HT));
    hash_table->n = 1000;
    hash_table->size = hash_table->n*hash_table->n;
    hash_table->ary = (PAIR**)calloc(hash_table->size, sizeof(PAIR*));
    for(int i = 0; i < hash_table->size; i++)
    {
        hash_table->ary[i] = (PAIR*)calloc(2,sizeof(PAIR));
        hash_table->ary[i]->set =0;
        hash_table->ary[i]->count = 0;
    }
    cubic_solution(hash_table);
    */
    
    /*
    puts("SEARCH PERMUTATIONS IN A STRING");
    char *pattern = "ABCD";
    char *str = "BACDGABCDA";
    search_permutations(pattern, str);
    */
    
    /*
    char **ary = (char**)malloc(sizeof(char*));
    int n = strlen( "moscaa") + 1;
    ary[0] = (char*)malloc(sizeof(char)*n);
    strncpy(ary[0],  "moscaa", n);
    n = strlen("mosca") + 1;
    ary[1] = (char*)malloc(sizeof(char)*n);
    strncpy(ary[1],  "mosca", n);
    n = strlen( "zagreb") + 1;
    ary[2] = (char*)malloc(sizeof(char)*n);
    strncpy(ary[2],  "zagreb", n);
    n = strlen( "apple") + 1;
    ary[3] = (char*)malloc(sizeof(char)*n);
    strncpy(ary[3],  "apple", n);
    n = strlen("clouds") + 1;
    ary[4] = (char*)malloc(sizeof(char)*n);
    strncpy(ary[4],  "clouds", n);
    for(int i = 0; i < 5; i++)
    {
        if(str_has_unique_chars(ary[i]))
            puts(ary[i]);
    }
    */
    
    
    /*
    puts("ARE TWO STRINGS PERMUTATIONS OF THE SAME STRING???\n");
    //abc
    char ary[6][4] = {"abc", "acb", "cab", "cba", "bac", "bca"};//all +
   // char ary[6][4] = {"abc", "acb", "cab", "ijk", "bbb", "aca"};//all -
    for(int i = 0; i < 3; i++)
    {
        printf("INPUTS %s:%s\n", ary[i], ary[i+3]);
        if(two_strings_permunations(ary[i], ary[i+3]))
        {
            puts("yes, both strs are a permutation of same pattern.");
            puts("post sorting:");
            printf("%s == %s\n",ary[i],ary[i+3]);
        }
    }
    */
    
    /*
    //kayak, 97879, GGTTGG, fcggcf, satie, eebabee, erik
    char **a = (char**)malloc(7*sizeof(char*));
    int n = strlen("kayak")+1;
    a[0] = (char*)malloc(sizeof(char)*n);
    strncpy(a[0], "kayak", n);
    n = strlen("97879")+1;
    a[1] = (char*)malloc(sizeof(char)*n);
    strncpy(a[1], "97879", n);
    n = strlen("GGTTGG")+1;
    a[2] = (char*)malloc(sizeof(char)*n);
    strncpy(a[2], "GGTTGG", n);
    n = strlen("fcggcf")+1;
    a[3] = (char*)malloc(sizeof(char)*n);
    strncpy(a[3], "fcggcf", n);
    n = strlen("satie")+1;
    a[4] = (char*)malloc(sizeof(char)*n);
    strncpy(a[4], "satie", n);
    n = strlen("eebabee")+1;
    a[5] = (char*)malloc(sizeof(char)*n);
    strncpy(a[5], "eebabee", n);
    n = strlen("erik")+1;
    a[6] = (char*)malloc(sizeof(char)*n);
    strncpy(a[6], "erik", n);
    for(int i = 0; i < 7; i++)
    {
        printf("TEST INPUT %s\n", a[i]);
        if(is_permuation_a_palindrome(a[i]))
            puts("yes\n");
        else
            puts("no\n");
    }
    */
    /*
    
    puts("COMPRESS A STRING:\n");
    char *ary[] = {"vaaavaa", "aallleee", "heeellllloooo", "heeeheee"};
    char *compr_str;
    for(int i = 0; i < 4; i++)
    {
        compr_str = string_compression(ary[i]); //"vaaavaa" = > v1a3v1a2
        printf("%s\n", compr_str);
    }
    */
    
    /*
    puts("BIT MANIPULATION: place lower byte of one input into upper byte of other.");
    uint8_t a = 0x0F;
    uint8_t b = 0x0A;
    uint8_t c = insert_8bint(a,b,4,7);
    printf("%d \n", c);//0xAF = 175
    */
  
    /*
    puts("FIRST SMALELS AND FIRST LARGEST WITH SAME # OF 1 bits as INPUT NUMBER.");
    next_number(102);
    */
    
    /*
    puts("SIEVE OF ARESOTHENES\n");
    bool *ary = (bool*)malloc(sizeof(bool)*18);
    puts("FIND ALL PRIME NUMBERS FROM 0 to 17:");
    ary = sieve_of_eratosthenes(17);
    for(int i = 0; i <= 17; i++)
    {
        if(ary[i])
            printf("%d ", i);
    }
    puts("\n");
    */
    
    /*
    puts("TEST PRIMALITY\n");
    int primes[45] ={2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
                   31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
                   73, 79, 83, 89, 97, 101, 103, 107, 109,113,
                   127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
                    179, 181, 191, 193, 197};
    int evens[45];
    for(int i = 0; i < 45; i++)
    {
        if(i % 2 == 0)
            evens[i] = i;
        
    }

    int count = 0;
    for(int i = 0; i < 45; i++)
    {
        if(is_prime(primes[i]))
        {
            printf("%d ",primes[i]);count++;
        }
    }
    puts("\n");
    printf("%d primes.\n", count);
    */
    
    /*
    printf("CREATE A MIN BST and IS BST VALID?\n");
    int ap[7] = {1,2,3,4,5,6,7};
    BST *t = (BST*)malloc(sizeof(BST));
    t->root = create_min_bst(ap, 0, 6); //see func comments.
    traverse_tree(t->root);
    PRINT_TEST;
        void *last = NULL;
    if(is_valid_bst(t->root,last))
        puts("VALID BST!!!!\n");
    
    puts("GIVEN A BST, PRINT ALL NEIGHBORS AT A GIVEN DEPTH\n");
    LIST *my_list = create_linked_list(gcmp, process);
    int *num = (int*)malloc(sizeof(int));
    *num = 7;//size
    insert_to_linked_list(my_list, (void*)num);
    traverse_linked_list(my_list);
    printf("\n\n\n");
    list_all_neighbors_at_depth(t, 3, gcmp, process);
    */
    
    /*
    printf("TWO SUM PROBLEM\n");
    int ary[4] = {2, 7, 11, 15};
    int idxs[2], indecis[3];
    int target = 17;
    two_sum(ary, 4, target, idxs);
    printf("TWO'S SUM ([%d]= %d + [%d]=%d) = %d\n",idxs[0], ary[idxs[0]], idxs[1], ary[idxs[1]], target);
    target = 92;
    int a[10] = {22,12,1,35,67,12,34,90,1,3};
    three_sum(a, 10, target, indecis);
    printf("THREE'S SUM ([%d]=%d + [%d]=%d + [%d]=%d) = %d\n",indecis[0], a[indecis[0]], indecis[1], a[indecis[1]], indecis[2], a[indecis[2]], target);
    */
    /*
    puts("FIND MISSING NUMBER PROBLEM\n");
    int a5[5] = {2,3,4,5};
    //int a5[5] = {1,3,4,5};
    //int a5[5] = {1,2,4,5};
    //int a5[5] = {1,2,3,5};
    //int a5[5] = {1,2,3,4};
    int m_num = find_missing_number_using_summation_formula(a5,5);
    printf("missing number is:  %d\n", m_num);
    m_num = find_missing_number_without_overflow(a5, 5);
    printf("missing number is:  %d\n", m_num);
    m_num = find_missing_number_using_xor_technique(a5, 5);
    printf("missing number is:  %d\n", m_num);
    */
    
    /*
    puts("KNAPSACK SOLUTIONS\n");
    puts("INTUITIVE SOLUTION:");
    KNODE *mylist = read_knapsack_input_file(KNAPSACK_INPUT_FILE);
    KNODE *ptr = mylist;
    while(ptr)
    {
        printf("%d:%d\n", ptr->weight, ptr->value);
        ptr = ptr->next;
    }
    int n = 3;
    int W = 5;
    int max;
    //combinatorial and order does not matter.
    int combinations = 7; // subset of 1 element, subset of 2 elements, subset of all elements.
                          //3!/(1!(3-1)! + 3!/(2!(3-2)! + 3!/(3!(3-3)! = 3 + 3 + 1.
    max = knapsack(mylist, n, W, combinations);
    printf("knapsack-01 linked list iterative max = %d\n", max);

    int v[] = {6, 10, 12};
    int w[] = {1, 2, 3};
    max = knapsack_01_iterative(v, w, n, W);
    printf("knapsack-01 iterative with arrays = %d\n", max);
    
    max =  naive_recursive_knapsack_01(v, w, n, W, 0);
    printf("knapsack-01 naive recursive max = %d\n", max);
    
    int z[3][5] = {{-1, -1, -1, -1, -1},{-1, -1, -1, -1, -1},{-1, -1, -1, -1, -1}};
    max = knapsack_0_1_r(n, W, w, v, n, W, z);
    //int z[3][5] = {{0, 0, 0, 0, 0},{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
    //max = cached_recursive_knapsack_01(n, W, w, v,n,W,z);
    printf("knapsack-01 recursive with cache max = %d\n", max);

   // for(int k=0; k <3; k++)
    //    printf("%d: %d ", v[k], w[k]);
    //int q[] = {6, 10, 12};
    //int s[] = {1, 2, 3};
    int y[3][5] = {{0, 0, 0, 0, 0},{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
    //for(int k=0; k <3; k++)
    //    printf("%d: ", v[k]);
    //printf("\n");
    //for(int k=0; k <3; k++)
    //    printf("%d: ", w[k]);
    //printf("\n");
    max = hashed_cache_recursive_knapsack_01(w, v, 3, 5, y, 5, 0);
    printf("knapsack-01 recursive with hashed caching max = %d\n", max);
    */
    
    /*
    char **sentences = (char**)malloc(3*sizeof(char*));
    char *str = "Est mercredi 7 Julliet 2021.";
    int len = strlen("Au'jourdhui est mercredi 7 Julliet 2021.")+ 1;
    sentences[0] = (char*)malloc(sizeof(char)*len);
    strncpy(sentences[0], str, len);
    str = "We are all just dreaming.";
    len = strlen("We are all just dreaming.") + 1;
    sentences[1] = (char*)malloc(sizeof(char)*len);
    strncpy(sentences[1], str, len);
    str = "We are drifting towards the shore.";
    len = strlen("We are drifting towards the shore.") + 1;
    sentences[2] = (char*)malloc(sizeof(char)*len);
    strncpy(sentences[2], str, len);
    
    char **phrases = (char**)malloc(3*sizeof(char*));
    str = "We are dreaming"; len = strlen("We are dreaming") + 1;
    phrases[0] = (char*)malloc(sizeof(char)*len);
    strncpy(phrases[0], str, len);
    str = "Est mercredi"; len = strlen("Est mercredi") + 1;
    phrases[1] = (char*)malloc(sizeof(char)*len);
    strncpy(phrases[1], str, len);
    str =  "We are drifting"; len = strlen("We are drifting") + 1;
    phrases[2] = (char*)malloc(sizeof(char)*len);
    strncpy(phrases[2], str, len);
    find_sentences_which_contain_all_words_in_a_phrase(sentences, 3, phrases, 3);
    */
    
    /*
    char *input;
    char in[] = "Amir"; //"Alice"
    char *output = reverse_characters_in_a_word(in);
    puts(output);
    
    char *s = "Only you can turn the tide, lift me up and make glide.";
    char *sentence = (char*)malloc(sizeof(char)*(strlen(s)+1));
    strncpy(sentence, s, (strlen(s)+1));
    reverse_words_in_sentence(sentence);
    */
    
    //create simple graph
    /*
    
              /  (1)  \
           (2)    |    (4)
                 (3)
                 |
                 (5)
    
    */
    GRAPH *g = create_graph(gcompare, process);
    int *node; //node
    int *ary[5];
    for(int i = 1; i <= 5; i++)
    {
        node = (int*)malloc(sizeof(int));
        *node = i;
        insert_to_graph(g, node);
        ary[i-1] = node;
    }
    //connect them
    add_arc_to_list(g, ary[0], ary[1], 1); //arc from 1 to 2
    add_arc_to_list(g, ary[0], ary[2], 1); //arc from 1 to 3
    add_arc_to_list(g, ary[0], ary[3], 1); //arc from 1 to 4
    add_arc_to_list(g, ary[2], ary[4], 1); //arc from 3 to 5
    //let A = (1) and B = (5) (yes)
    if(is_there_path_from_A_to_B_BFS_for_DAG(g, ary[0], ary[4]))
        puts("Yes, there is a path from A(1) to B(5).");
    //let A = (2) and B = (4) (no)
    if(is_there_path_from_A_to_B_BFS_for_DAG(g, ary[1], ary[3]))
        puts("Yes, there is a path from A(2) to B(4).");
    else
        puts("No, there is no path from A(2) to B(4).");
    delete_list_directed_graph(g);
    
    //Alien dict
    int wordsSize = 4;
    char *words[4] = {"a","b","ca","cc"};// {"ac","ab","b"};//{"ab", "a"}; // {"aa", "a", "ab"};//{"bc","b","cbc"}; //{"wrt","wrf","er","ett","rftt"};
    printf("%s\n", alienOrder(words, wordsSize));
    
    return 0;
}

//HASHING SOLUTION TO FIND INPUTS FOR A, B, C, D SUCH THAT A^3 + B^3 = C^3 + D^3
void cubic_solution(HT *hash_table)
{
    int result, loc, idx;
    for(int c = 1; c < hash_table->n; c++)
    {
        for(int d = 1; d < hash_table->n; d++)
        {
            result = (int)(pow(c, 3) + pow(d, 3));
            loc = (result)%hash_table->size;
            idx = hash_table->ary[loc]->count;
            if(idx == 1 && hash_table->ary[loc]->value == result)
            {
                printf("a=%d b=%d c=%d d=%d result=%d\n",
                       hash_table->ary[loc][0].a, hash_table->ary[loc][0].b,
                       c, d, result);
                hash_table->ary[loc]->set = 1;//in the set of solutions

            }
            hash_table->ary[loc][idx].a = c;
            hash_table->ary[loc][idx].b = d;
            hash_table->ary[loc]->value = result;
            hash_table->ary[loc]->count++;

        }
    }
    //PRINTS SOLUTIONS
    for(int i = 0; i < hash_table->size; i++)
    {
        if(hash_table->ary[i]->set == 1)// && hash_table->ary[i]->count == 1)
        {
            printf("a=%d b=%d c=%d d=%d result=%d\n",
                   hash_table->ary[i][0].a, hash_table->ary[i][0].b,
                   hash_table->ary[i][1].a, hash_table->ary[i][1].b, hash_table->ary[i]->value);
            
        }
    }
}

/*
 Example: Given a smaller strings and a bigger string b, design an algorithm to
 find all permuta­tions of the shorter string within the longer one and print
the location of each permutation.
 */
//assumming:  fixed alphabet size
#define MAX 256
void search_permutations(char *pattern, char *str)
{
    char count_p[MAX] = {0};//count all chars in pattern
    char count_cw[MAX] = {0};//count of cw of text
    int m, n ;
    
    m = (int)strlen(pattern);
    n = (int)strlen(str);
    for(int i = 0;  i < m; i++)//O(m)
    {
        count_p[pattern[i]]++;
        count_cw[str[i]]++;
    }
    
    //ABCDDE
    for(int i = m; i < n; i++)//O(n)
    {
        
        if(strncmp(count_p, count_cw, 256) == 0) //(O(256)
        {
            printf("found at index %d\n", i-m);
            
        }
        //2*O(1)
        count_cw[str[i]]++;//add current char to current window
        count_cw[str[i-m]]--;//remove the first char from previous window
    
    }
    //TEST FOR LAST
    if(strncmp(count_p, count_cw, 256))//O(256)
    {
        printf("found at index %d\n", n-m);
    }
}

/*
 Is Unique: Implement an algorithm to determine if a string has all unique characters.
 What if you cannot use additional data structures?
 */
bool str_has_unique_chars(char *input)//O(n): time, O(256): space
{
    int input_len = (int)strlen(input);
    char fac[256] = {0};
    
    for(int i = 0; i < input_len; i++)
    {
        if(++fac[input[i]] > 1)
            return false;
    }
    return true;
}

int ch_cmp(const void *a, const void *b)
{
    char *c, *d;
    int res;
    
    c = (char*)a;
    d = (char*)b;
    res = *c - *d;
    
    if(res < 0)
        return -1;
    else if(res > 0)
        return +1;
    else
        return 0;
}

/*
 ARRE TWO STRINGS PERMUATIONS OF THE SAME PATTERN???
 time: nlog(n), space: o(n)
 
 1) if used frequncy arrays: space 2*(256) -- asumming ascci; generate O(n) TIME
 2) stncmp -- O(n) time
 
 TIME: O(n)
 SPACE: O(512)
 */
bool two_strings_permunations(char s1[], char s2[])
{
    //sort the strings -- time: O(nlogn), space: 2*log(n)
    qsort (s1, strlen(s1), sizeof(char), ch_cmp);
    qsort (s2, strlen(s2), sizeof(char), ch_cmp);

    if(strncmp(s1, s2, strlen(s1)) == 0)//TIME: O(n)
        return true;
    else
        return false;
}

//DETERMINE IF STRING IS A PALINDROMe
bool is_permuation_a_palindrome(char *input)
{
    char fary[256] = {0};
    int input_len, mid, rest;
    bool palindrome = false;
    
    //build frequency array for all characters
    input_len = (int)strlen(input);
    for(int i = 0; i < input_len; i++)
        fary[input[i]]++;

    mid = 0;
    rest = 0;
    for(int i = 0; i < input_len; i++)
    {
        if(fary[input[i]] == 1 || fary[input[i]] == 3) //frequency of 1 or 3 => odd len palindrome
            mid++;
        if(fary[input[i]]%2 == 0) //freq 2 => even len or flanq chars which is a multiple of 2. ex: ggttgg
            rest++;
    }
    //very indeed a palindrome, then this must be the case
    if(input_len%2 == 0)
    {
        if(input_len == rest)
            palindrome = true;
    }
    // this case:  a x i x a        or   this case:   a x a x a
    if((mid == 1 && input_len-1 == rest)  || (mid == 3 && input_len-3 == rest))
          palindrome = true;
    
    printf("%d:%d\n", mid, rest);
    return palindrome;
}

//O(N)
// Given an alphabetic string, compress it by compressing repeated characters such that
// a repated character is included only once  followed by a count of it's instances: clokkkks = clok4s.
// Requirement:  if the compressed string == size of input string, then return the original input string.
char* string_compression(char *input)
{
    char buffer[10];
    int size, i, count;
    
    size = (int)strlen(input);
    i = count = 1;
    char *compr_str = (char*)malloc(sizeof(char));
    for(; i < size; i++)
    {
        if(input[i-1] == input[i])
            count++;
        else
        {
            sprintf(buffer,"%c%d",input[i-1],count);
            strcat(compr_str, buffer);
            count = 1;//reset count
        }

    }
    if(count != 1)//get the last one: vaaav(aa); else taken care of if type is vaaa(v)
    {
        sprintf(buffer,"%c%d",input[i-1],count);
        strcat(compr_str, buffer);
    }
    if(strlen(compr_str) == size)
        return input;
    else
        return compr_str;
}


//insert_8bint(0x0F,0x0A,4,7);
//M = 0x0F
//N = 0x0A
//7,4
//result is:  0xAF = M.
//EXTRACT LOWER BYTE OF N starting at bit s
//PLACE IN UPPER BYTE OF M which ends at bit e
uint8_t insert_8bint(uint8_t M, uint8_t N, int s, int e)
{
    int i, d;
    uint8_t lsbs, mask;
    
    d = e - s + 1;
    //create a mask for lower byte of N
    mask = 0x0;
    for(i = 0; i < d; i++)
        mask = mask | (0x01 << i);
    
    //extract those bits and shift to align with upper byte rage of M.
    lsbs = (mask & N) << d;
    M = M | lsbs;//set those bits in the destination (upper byte of M).
    return M;
}


/*
 Next Number: Given a positive integer, print the next smallest and the next
 largest number that have the same number of 1 bits in their binary representation.
  //O(N)-time
  //O(1)-space
  Example: given 102 and the count of 1 bits,
  find the first number < 102 with the same number of 1 bits
  find the first number > 102 with the same number of 1 bits
 */
void next_number(uint8_t n)
{
    uint8_t mask, next_smallst, next_largest;
    int i, ls1, ls0, sls0;
    //ASSUMMING LITTLE ENDIAN
    //FIND FIRST LEAST SIGNIFICANT 0-BIT, 1-BIT; SECOND LEAST SIGNIFICANT 0-BIT
    ls1 = ls0 = sls0 = -1;
    for(i = 0; i < 8; i++)
    {
        mask = 0x0;
        mask |= (0x1 << i);//test bit i
        if(mask == (mask & n))//if bit i is 1
        {
            if(ls1 < 0)
                ls1 = i;
        }
        else
        {
            if(ls0 < 0)
                ls0 = i;
            else
            {
                if(sls0 < 0)
                    sls0 = i;
            }
        }
    }
    
    printf("\n%d: %d: %d\n", ls0, ls1, sls0);
    //set 1st lsb 0 bit, then clear 1st lsb 1 bit
    next_smallst = (n | (0x01 << ls0));
    next_smallst = (next_smallst & ~(0x01 << ls1));
    //set 2nd lsb 0 bit, then clear 1st lsb 1 bit
    next_largest = (n | (0x1 << sls0));
    next_largest = (next_largest & ~(0x1 << ls1));
    printf("\n%u: %u: %u\n", next_smallst, n, next_largest);
}


/*
 Debugger: Explain what the following code does: ((n & (n-1)) == 0).
*/
//check for primality
bool is_prime(int n)
{
    if(n < 2)
        return false;
    
    int sq = (int)sqrt(n);
    for(int i = 2; i <= sq; i++)
    {
        if(n % i == 0)
            return false;
    }
    return true;
    
}

void init_flags(bool *ary, int size)
{
    ary[0] = ary[1] = false;
    for(int i = 2; i < size; i++)
        ary[i] = true;
}

void cross_off(bool *flags, int size, int prime)
{
    for(int i = prime*prime; i < size; i += prime)
        flags[i] = false;
}

int get_next_prime(bool *flags, int size, int prime)
{
    int next = prime + 1;
    while(next < size && !flags[next])
        next++;
    return next;
    
}


//is max divisible by a prime #
//generat a list of prime numbers from 2 up to a given max
bool *sieve_of_eratosthenes(int max)
{
    int size = max + 1;
    bool *flags = (bool*)malloc(sizeof(bool)*size);
    int prime, sq_max;
    
    init_flags(flags, size);
    prime = 2;
    sq_max = (int)sqrt(max);
    while(prime <= sq_max)
    {
        //cross off remaining multiples of prime
        cross_off(flags, size, prime);
        
        ///find next value which is true
        prime = get_next_prime(flags, size, prime);
        
    }
    return flags;
}

/*
 Minimal Tree: Given a sorted (increasing order) array with unique integer elements, write an algo­
 rithm to create a binary search tree with minimal height.
 */
NODE *create_min_bst(int *ary, int start, int end)
{
    if(end < start)
        return NULL;
    
    int mid = (start + end)/2;
    NODE *n = (NODE*)malloc(sizeof(NODE));
    n->data = &ary[mid];
    n->left = create_min_bst(ary, start, mid - 1);
    n->right = create_min_bst(ary, mid+1, end);
    return n;
}

void traverse_tree(NODE *root)
{
    if(root)
    {
        traverse_tree(root->left);
        process(root->data);
        traverse_tree(root->right);
    }
}

/*
 List of Depths: Given a binary tree, design an algorithm which creates a linked list of all the nodes
 at each depth (e.g., if you have a tree with depth D, you'll have D linked lists).
 */
void list_all_neighbors_at_depth(BST *tree, int depth, int (*compare)(void *a, void *b), void (*process)(void *data))
{
    
    LIST **ary;
    QUEUE *q;
    NODE *cur;
    int levels[depth], count, level;
    
    //create array of node count per level
    for(int i = 0; i < depth; i++)
        levels[i] = (int)pow(2, i);
    
    //create array of linked lists
    ary = (LIST**)malloc(sizeof(LIST*)*depth);
    for(int i = 0; i < depth; i++)
        ary[i] = create_linked_list(compare, process);
    
    //create queue
    q = create_queue(compare, process);
    enqueue(q, tree->root);
    
    count = level = 0;
    while(!is_queue_empty(q))
    {
        //dequeue
        cur = (NODE*)dequeue(q);
        // process(cur->data);
        //INSERT NODE TO APPROPRIATE LEVEL LINKED LIST
        if(count < levels[level])
        {
            insert_to_linked_list(ary[level], cur->data);
            count++;
        }
        else
        {
            level++;
            insert_to_linked_list(ary[level], cur->data);
            count = 1;
        }
        //enqueue any right or left child
        if(cur->left)
            enqueue(q, cur->left);
        if(cur->right)
            enqueue(q, cur->right);

    }
    
    for(int i = 0; i < depth; i++)
    {
        printf("Linked list at depth %d\n", i);
        for(LL_NODE *mov = ary[i]->front; mov; mov = mov->next)
        {
            process(mov->data);
        }
        printf("\n");
        
    }

}

int gcmp(void *a, void *b)
{
    int a1, b1;
    
    a1 = *((int*)a);
    b1 = *((int*)b);
    
    if(a1 < b1)
        return -1;
    else if(a1 > b1)
        return +1;
    else
        return 0;

}

void process(void *data)
{
    int *app_data = (int*)data;
    
    printf("~%d ", *app_data);

}

bool is_valid_bst(NODE *n, void *last_printed)
{
    if(!n)
        return true;
    
    if(!is_valid_bst(n->left, last_printed))
        return false;
    
    if(last_printed && (gcmp(n->data, last_printed)) <=0)
        return false;
    
    last_printed = n->data;
    
    if(!is_valid_bst(n->right, last_printed))
        return false;
    
    return true;
    
}

//direct addressing for small examples, other type of addressing with large n.
// WE NEED O(n) space
// TIME:  O(n)
void two_sum(int ary[], int size,  int target, int *pRes)
{
    int *hash_table;
    int comp;
    bool found;
    
    hash_table = (int*)calloc(size, sizeof(int));
    //values are the address, indecis ae the value
    for(int i = 0; i < size; i++)
        hash_table[ary[i]] = i;
    
    //compliment lookup is constant.
    found = false;
    for(int i = 0; i < size && !found; i++)
    {
        //compute compliment of value at ary[i]
        comp = target - ary[i];
        //if the compliment exists in our hash table, we are done.
        //ensure compliment of index in hash table is not it self.
        if((hash_table[comp] != 0) && hash_table[comp] != i)
        {
            pRes[0] = i;
            pRes[1] = hash_table[comp];
            found = true;
        }
    }
    free(hash_table);
}

void three_sum(int ary[], int size,  int target, int *pRes)
{
    int *hash_table;
    int cur_sum;
    int i, j;
    
    hash_table = (int*)calloc(size, sizeof(int));
    //values are the address, indecis ae the value
    for(i = 0; i < size; i++)
        hash_table[ary[i]] = i;
    for(i = 0; i < size-1; i = i + 1)
    {
        //find a pair in subarray A_i+1 thorugh A_n-1
        //with sum = sum - A[i]
        cur_sum = target - ary[i];
        for(j = i + 1; j < size; j++)
        {
            if(hash_table[cur_sum - ary[j]])
            {
                //printf("Triplets %d:%d:%d\n", ary[i], ary[j], cur_sum - ary[j]);
                pRes[0] = hash_table[ary[i]];
                pRes[1] = hash_table[ary[j]];
                pRes[2] = hash_table[cur_sum - ary[j]];
                return;
            }
        }
   
   }
    free(hash_table);
}

/*
You are given a list of n-1 integers and these integers are in the range of 1 to n.
There are no duplicates in the list. One of the integers is missing in the list.
Write an efficient code to find the missing integer.
O(n) time, O(1) space.
*/
int find_missing_number_using_summation_formula(int *ary, int size)
{
    //use Gauss formula for sum of n numbers from 1 to n
    //compute sum for given array and subtract from the sum of first n natural numbers
    //result is our missing number
    //n(n+1) / 2,
    int sum_first_n, ary_sum, missing_num;
    
    sum_first_n = (int)(size*(size+1))/2;
    ary_sum = ary[0];
    for(int i = 1; i < size; i++)
        ary_sum += ary[i];
    
    missing_num = sum_first_n - ary_sum;
    
    return missing_num;
    
}

/* avoid integer overflow if n is large */
int find_missing_number_without_overflow(int *ary, int size)
{
    //use Gauss formula for sum of n numbers from 1 to n
    //compute sum for given array and subtract from the sum of first n natural numbers
    //result is our missing number
    //n(n+1) / 2,
    int sum = 1;
    for(int i = 2; i <= size; i++)
        sum = sum + i - ary[i-2];
    return sum;
}

int find_missing_number_using_xor_technique(int *ary, int size)
{
    int a, b;
    
    a = ary[0];
    b = 1;
    
    for(int i=1; i < size; i++)
        a = a^ary[i];
    for(int i=2; i <= size; i++)
        b = b^i;
    
    return a^b;
}

KNODE* read_knapsack_input_file(char *filename)
{
    KNODE *list, *mov, *item;
    FILE *SpIn;
    int weight, value;
    
    list = (KNODE*)malloc(sizeof(KNODE));
    list->next = NULL;
    mov = list;
    SpIn = fopen(filename, "r");
    while(fscanf(SpIn, "%d %d", &weight, &value) != EOF)
    {
        //printf("%d %d\n", weight, value);
        item = (KNODE*)malloc(sizeof(KNODE));
        item->value = value;
        item->weight = weight;
        item->traversed = false;
        mov->next = item;
        item->next = NULL;
        mov = mov->next;
    }
    fclose(SpIn);
    
    return list->next;
}

/*
 Optimization Version of Knapsack
 
 For a set of n items, each with a specific weight (w_i) and value (v_i)
 find the maximum sum of values while the sum of weights is within a given constraint.
 
 V_max = Σ (v_i) for i=1 to at most n. such that. Σ (w_i) <= W (constraint).
 
 List is passed in order by weights.
 
 0-1 version using linked list.
 
 We consider only sums <= W of each possible subset:
 S = {a, b, c} where each element has a given weight and value.
 SUM from r=1 to n: n!/(n-r)!r!

 start with a and consider a
 consider a, ab
 consider abc
 start from a again
 consider ac
 start b
 consider b, bc
 start from c
 consider c
 
 Complexity is linear with at worst exponential
 */
int knapsack(KNODE *list, int length, int max_weight, int combinations)
{
    int sum, value, max_value, i;

    KNODE *cur, *next, *reset, *verify;
    int ary[combinations];
    bool done, done2, cont;
    
    //max sums we would compute; not all possible combinations will fall within <=W.
    for(int k = 0; k < combinations; k++)
        ary[k] = 0;
    
    // we consider all combinations but only store sum of subsets within the treshold W.
    // start from first element
    for(cur = list, i=0; cur; cur = cur->next)
    {
            cur->traversed = true;
            done = false;
            //consider all combinations of elements from the start without repetions.
            while(!done)
            {
                value = cur->value; //re-assing values from start
                sum = cur->weight;
                next = cur->next;   //start from here again
                done2 = false;
                while((sum <= max_weight) && !done2)
                {
                    if(next)
                    {   //consider next element only if sum would be within W
                        if(!next->traversed && ((sum + next->weight) <= max_weight))
                        {
                        sum += next->weight;
                        next->traversed = true;
                        value += next->value;
                        }
                        next = next->next;
                    }
                    //if we reached the end of the list of elements
                    if(!next)
                        done2 = true;

                }//SUM
                ary[i] = value; //store that sum in array
                i = i+1;
                cont = false;
                for(verify = cur->next; verify; verify = verify->next)
                {
                    if(!verify->traversed)//any node not yet considered from the relative start
                        cont = true;
                }
                if(!cont)
                    done = true;//start traversal from next element in the list (cur = cur->next)
            }//while
            for(reset = cur->next; reset; reset = reset->next) //reset flags of remaining elements
            {                                                  //to reconsider from the start
                reset->traversed = false;
            }

    }//for
    
    //determine the max value
    max_value = 0;
    for(int j =0; j < i; j = j + 1)
    {
        printf("%d:", ary[j]);//print the array of actual values considered which we computed.
        if(max_value < ary[j])
            max_value = ary[j];
    }
    printf("\n");
    
    return max_value;
}

/*
ITERATIVE KNAPSACK
 
Iterate through subsets storing in a matrix
computing relative maximum value.

 Complexity for this implementation is linear O(nW) to worst of exponential O(2^n)

 */
#define MAX(x, y) ((x) > (y) ? (x):(y))
int knapsack_01_iterative(int v[], int w[], int n, int W)
{
    int m[n+1][W+1];
    int i, j;
    
    //initialize first row only
    for(j = 0; j <= W; j++)
            m[0][j] = 0;
    
    //m[i][j] will contain a sum of values v_i for the first i items s.t. sum of the wi <= j.
    for(i = 1; i <= n; i++)// each time we consider adding a new item in the knapsack
        for(j = 0; j <= W; j++)// we iterate over the previous values for each relative max weight comparing it with w_i
            if (w[i-1] > j) //if w_i exceeds j (the current weight limit), exclude it and assign the table entry the previous sum.
                m[i][j] = m[i-1][j]; //assign previous relative max value sum.
            else//take the max value sum from excluding or including the ith item
                m[i][j] = MAX(m[i-1][j], m[i-1][j-w[i-1]] + v[i-1]);

   /* for(i = 0; i <= n; i++ )
    {
        for(j = 0; j <= W; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }*/
    return m[n][W];//return ultinate max
}

/*
 NAIVE RECURSIVE KNAPSACK
 
 recursively consider possible subsets, for example with 3 items:
 
             subsets with v[0], without it.
            /                               \
  max(subsebts with [v1], without it)      max(subset with v[1], without)
                          \                         \               \ max(with v[2], without)
                    max(subset with v[2], without)   max(with v[2], without)
 
 */
int naive_recursive_knapsack_01(int v[], int w[], int n, int W, int i)
{
    
    if(i == n) //unwind when we reach the end of the list subset
        return 0;
    
    if(W - w[i] < 0)//if item exceeds weight constraint, move on to next item
        return naive_recursive_knapsack_01(v, w, n, W, i+1);
    
    //else take max from including the item or excluding
    int v1 = naive_recursive_knapsack_01(v, w, n, W - w[i], i+1) + v[i];
    int v2 = naive_recursive_knapsack_01(v, w, n, W, i+1);
    return v1 > v2? v1: v2;
}

/*
 RECURSIVE KNAPSACK WITH HASHING
 For sparse key space. here we hash into the rows.
 Similar to recursive cached version but with hashing.
 */
#define hash_f(a, b) a % b
int hashed_cache_recursive_knapsack_01(int w[], int v[], int n, int c, int z[n][c], int W, int i)
{
    if(i == n) //reached max items
        return 0;
    
    if(z[hash_f(i, n)][W-1] != 0) // if slot has been assigned a value ( a hit)
        return z[hash_f(i, n)][W-1]; //return it.
    
    if((W - w[i]) < 0)//if current item weight exceeds current constraint, move on to next item.
        return hashed_cache_recursive_knapsack_01(w, v, n, c, z, W, i+1);
 
    //compare inclyde and exclude and
    int v1 = hashed_cache_recursive_knapsack_01(w, v, n, c, z, W - w[i], i+1) + v[i];//include
    int v2 = hashed_cache_recursive_knapsack_01(w, v, n, c, z, W, i+1);//exclude
    z[hash_f(i, n)][W-1] = (v1 > v2) ? v1 : v2;//take max
    return z[hash_f(i, n)][W-1];
    
}

/*
 RECURSIVE VERSION WITH CACHE
Optimized recursive version with "cache" table which
computes only needed entries recursively to solve m[n][W].
*/
int knapsack_0_1_r(int i, int j, int w[], int v[], int r, int c, int z[r][c])
{

    if(i == 0 || j <= 0) //reached end of subset
    {
        return 0;
    }
    if (z[i-1][j] == -1) //if entry not yet computed, recursively compute it by solving for only for previous entries needed.
    {
        z[i-1][j] = knapsack_0_1_r(i-1, j, w, v, r, c, z);
    }
    if (w[i-1] > j)// if w_i > relative max, assign value from previous row.
    {
        z[i][j] = z[i-1][j];
    }
    else
    {
        if(z[i-1][j-w[i-1]] == -1) //if current item not computed,
        {
            z[i-1][j-w[i-1]] = knapsack_0_1_r(i-1, j-w[i-1], w, v, r, c, z);//compute it.
        }
        //z[i][j] = z[i-1][j] > (z[i-1][j-w[i-1]] + v[i-1])? z[i-1][j] : z[i-1][j-w[i-1]] + v[i-1];
        //return z[i][j]; //return max from including/excluding current ith item.
        return  z[i-1][j] > (z[i-1][j-w[i-1]] + v[i-1])? z[i-1][j] : z[i-1][j-w[i-1]] + v[i-1];
    }
    return 0;//for control purpose.
}

/*
 RECURSIVE KNAPSACK STORING VALUES IN A "CACHE"; EXACTLY SAME AS ABOVE.
 */
int cached_recursive_knapsack_01(int i, int j, int w[], int v[], int n, int W, int z[n][W])
{
    if(i == 0 || j == 0)//reached end of current subset or relative max weight.
        return 0;
    
    if(z[i-1][j] == 0) //if table entry has not been computed, do so.
        z[i-1][j] = cached_recursive_knapsack_01(i-1, j, w, v, n, W, z);
    
    if(w[i-1] > j) // if adding item to bag exceeds the constraint, assing it the (previous row, current column) value.
        z[i][j] = z[i-1][j];
    else
    {
        if(z[i-1][j-w[i-1]] == 0) // if entry for current item not computed,
            z[i-1][j-w[i-1]] = cached_recursive_knapsack_01(i-1, j - w[i-1], w, v, n, W, z);//do so.
        return z[i-1][j] > z[i-1][j-w[i-1]] + v[i-1] ? z[i-1][j] : z[i-1][j-w[i-1]] + v[i-1];//max include/exclude ith item.
        
        //return z[i-1][j] ? z[i-1][j] > z[i-1][j-w[i-1]] + v[i-1]: z[i-1][j-w[i-1]] + v[i-1];//max include/exclude ith item.
    }
    return 0;
}

char *sanitize_string(char *input)
{
    char *pchar;
    char *word;
    int idx;
    
    word = malloc(sizeof(char)*(strlen(input)+1));
    for(idx = 0, pchar = input; *pchar; pchar++)
    {
        if(isalnum(*pchar))
        {
            word[idx] = *pchar;
            idx++;
        }
    }
    word[idx] = '\0';
    //realloc(word, (idx+1)*sizeof(char));
    return word;
}

void find_sentences_which_contain_all_words_in_a_phrase(char **sentences, int s_len,  char **phrases, int p_len)
{
    char **hash_table[s_len]; //array of arrays of strings
    char *ptr, *word;
    int idx, count, i, j;
    
    for(j = 0; j < p_len; j++)
        printf("Phrase %d = %s\n", j, phrases[j]);
    for(j = 0; j < s_len; j++)
        printf("Sentence %d = %s\n", j, sentences[j]);
    
    //tokenize each phrase
    for(i = 0; i < p_len; i++)
    {
        //direct addressing for simplicity
        hash_table[i] = (char**)malloc(sizeof(char*));
        idx = 0;
        for(ptr = strtok(phrases[i], " "); ptr != NULL; ptr = strtok(NULL, " "))
        {
             word = sanitize_string(ptr);
             hash_table[i][idx] = (char*)malloc(sizeof(char)*(strlen(word)+1));
             strncpy(hash_table[i][idx], word, strlen(word)+1);
             idx++;
        }
        //view
        //for(int j = 0; j < idx; j++)
            //puts(hash_table[i][j]);

        //for current phrase parse sentences to find any sentences which contain all words
        for(j = 0; j < s_len; j++)//for each sentence
        {
            count = 0;
            for(int w = 0; w < idx; w++)//verify if all words in current phrases are found.
            {
                if(strstr(sentences[j], hash_table[i][w]))
                    count++;
            }
            if(count == idx)
                printf("sentece %d contains phrase %d\n", j, i);
        }
    }//end_tokenize phrases
    
}

/*
INPUT: NULL TERMINATED STRING WHICH REPRESETNS A WORD.
*/
char *reverse_characters_in_a_word(char *word)
{
    char *front, *rear, a, b;
    int char_count;
    
    char_count = (int)strlen(word)/2;
    
    front = word;
    rear = word + (strlen(word) - 1);
    while(char_count > 0)
    {
        a = *front;
        b = *rear;
        *rear = a;
        *front = b;
        front++;
        rear--;
        char_count--;
    }

    return word;
}

void reverse_words_in_sentence(char *sentence)
{
    char **tokens, *ptok;
    int i;
    
    tokens = (char**)malloc(sizeof(char*));
    for(ptok = strtok(sentence, " "), i=0; ptok; ptok = strtok(NULL, " "), i++)
    {
        tokens[i] = (char*)malloc(sizeof(char));
        tokens[i] = sanitize_string(ptok);
    }
    //print reversed sentence
    for(int j = i-1; j >=0; j--)
        printf("%s ", tokens[j]);
    puts("\n");
    //free space
    for(int j = 0; j < i; j++)
        free(tokens[j]);
    free(tokens);
}


/*
 Route Between Nodes: Given a DAG
 design an algorithm to find out whether there is a route between two nodes.
 Solution: BFS or DFS. make start vertex A and traverse until you find B or not.
 so we easily convert the traversal of DFT or BFT into the search algorithm..
 */
bool is_there_path_from_A_to_B_BFS_for_DAG(GRAPH *g, void *A, void *B)
{
    VERTEX *v;
    ARC *a;
    QUEUE *q;
    bool found;
    
    if(g->count == 0)
        return false;
    
    //CREATE OUT QUEUE
    q = create_queue(g->compare, g->process);
    
    //set processed flag to all nodes and search for A.
    //if we find A, add to queue, and set processed to 1.
    v = g->source;
    found = false;
    while(v)
    {
        if(g->compare(v->data, A) == 0)
        {
             enqueue(q, v);
             v->processed = 1;
             found = true;
        }
        v->processed = 0;
        v = v->next;
    }
    if(!found)
        return false;
    
    //traverse the rest of the graph to see if we find the end point B.
    while(!is_queue_empty(q))
    {
        v = dequeue(q);
        //g->process(v->data);
        v->processed = 2;
        //process it's adjacency list
        if(v->adj_list)
        {
            a = v->adj_list;
            while(a)
            {
                if(a->dest->processed < 1)
                {
                    if(g->compare(a->dest->data, B) == 0)
                    {
                        puts("Yes, there exist a path from a to b.");
                        g->process(a->dest->data);
                        return true;
                    }
                    enqueue(q, a->dest);
                    a->dest->processed = 2;
                }
                a = a->next;
            }
        }
        v = v->next;
    }
    delete_queue(q);
    return false;
}

int gcompare(void *arg1, void *arg2)
{
    int *a, *b;
    a = (int*)arg1;
    b = (int*)arg2;
    if(*a > *b)
        return +1;
    else if (*a < *b)
        return -1;
    else
        return 0;
}

/*
We can solve without hashing: making a copy of nums, sorting nums once,
then 2 sequential searches on the copy to map to locate the corresponding indecis.

We can do better: Does not require unsorted search but only sort and a datastrcutre.

Optimality depends on: sort function used. This solutions requires 1 call to sort
and a data structure and or map to preserve original indecis:value:sorted_idx.
*/
typedef struct sums
{
    int oidx;
    int sval;//sorted val & idx
}SUMS;

void selection_sort_map(SUMS *ary, int last)
{
    int cur, mov, smallest, hold, oidx;
    
    for(cur = 0; cur < last; cur++)
    {
        smallest = cur;
        for(mov = cur + 1; mov <= last; mov++)
            if(ary[mov].sval < ary[smallest].sval)
                smallest = mov;
        hold =  ary[cur].sval;
        oidx =  ary[cur].oidx;
        ary[cur].sval = ary[smallest].sval;
        ary[cur].oidx = ary[smallest].oidx;
        ary[smallest].sval = hold;
        ary[smallest].oidx = oidx;
    }
}

int* twoSumLC_optimalV2(int* nums, int numsSize, int target, int* returnSize)
{
    
    int *answer, sum, left, right;
    bool found;
    SUMS sorted[numsSize];
    
    //MAKE A COPY OF THE ARRAY & save the original index corresponding to each value.
    for(int i = 0; i < numsSize; i++)
    {
        sorted[i].oidx = i;
        sorted[i].sval = nums[i];
    }
    
    //SORT THE ARRAY AND PRESERVE original VALU:IDX mapping.
    selection_sort_map(sorted,numsSize-1);
    
    //TEST BOUNDS
    if(!(numsSize >= 2 && numsSize <= (int)pow(10,4)))
        return NULL;
    if(!(target >= -(int)pow(10,9) && target <= (int)pow(10,9)))
        return NULL;
    
    //set first and last index of array
    left = 0;
    right =  numsSize - 1;
    answer = (int*)malloc(2*sizeof(int));
    found = false;
    while(left < right&& !found)  //travese the copy from both endpoints, inwards.
    {
        sum = sorted[left].sval + sorted[right].sval;
        if(sum == target)
            found = true;
        else if(sum < target)//move up from smaller #s
            left++;
        else //move down from larger #s
            right--;
    }
    
    if(found)
    {   //if found, return the original indecis corresponding to our solution.
        answer[0] = sorted[left].oidx;
        answer[1] = sorted[right].oidx;
    }
  
    *returnSize = 2;//TWO INDECIS
    return answer;
}

#define TEST_FILE "twosum_test_file.in"

void test_twossum(void)
{
    FILE *fp;
    char buffer[80], *ary, *e, *exp;
    int nums[5], expected[2], target, size, tv_size, i, returnSize, *actual;
    bool passed;
    
    fp = fopen(TEST_FILE, "r");
    while(fgets(buffer, 80, fp ))
    {
        if(buffer[0] != '#')
        {
            target = (int)strtol(strtok(buffer, ":"),(char**)NULL, 10);
            size =(int)strtol(strtok(NULL, ":"),(char**)NULL, 10);
            ary =strtok(NULL, ":");
            exp =strtok(NULL, ":");
            tv_size = size; i = 0;
            for(e = strtok(ary, ","); i < tv_size; e = strtok(NULL, ","))
            {
                nums[i] = (int)strtol(e,(char**)NULL, 10);i++;
            }
            e = strtok(exp, ",");
            expected[0] =(int)strtol(e,(char**)NULL, 10);
            e = strtok(NULL, ",");
            expected[1] =(int)strtol(e,(char**)NULL, 10);

            /*
            printf("target=%d, size=%d\n", target, size);
            printf("ary: ");
            for(int i = 0; i < size; i++)
            printf("%d ", nums[i]);
            printf("\n");
            printf("expected: %d:%d\n", expected[0], expected[1]);puts("\n");
            */
            actual = twoSumLC_optimalV2(nums, size, target, &returnSize);
            //actual = twoSumLC_optimal(nums, size, target, &returnSize);
            passed = (actual[0] == expected[0] && actual[1] == expected[1]) ||
                     (actual[1] == expected[0] && actual[0] == expected[1]);
            if(!passed)
            {
                printf("TEST CASE %d FAILED!!", i);
                printf("target=%d, size=%d\n", target, size);
                printf("ary: ");
                for(int i = 0; i < size; i++)
                    printf("%d ", nums[i]);
                printf("\n");
                printf("expected: %d:%d\n", expected[0], expected[1]);puts("\n");
                printf("actual: %d:%d\n", actual[0], actual[1]);puts("\n");
                break;
            }

        }


    }
    fclose(fp);
}

