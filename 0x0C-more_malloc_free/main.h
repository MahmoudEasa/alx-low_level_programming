#ifndef MAIN_H
#define MAIN_H

/**
 * struct multiplynode - Struct Node
 * @data: the element in the node
 * @next: pointer to the next node
 * @prev: pointer to the previous node
 *
 * Description: node to multiply numbers
 */

typedef struct multiplynode
{
	char data;
	struct multiplynode *next;
	struct multiplynode *prev;
} MultiplyNode;

/**
 * struct multiply - stack
 * @size: the size of the nodes
 * @top: the first node to pop
 * @end: the last node to pop
 *
 * Description: stack pointer to nodes
 */

typedef struct myltiply
{
	int size;
	MultiplyNode *top;
	MultiplyNode *end;
} Multiply;

int _putchar(char c);
void *malloc_checked(unsigned int b);
char *string_nconcat(char *s1, char *s2, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);
int *array_range(int min, int max);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _isdigit(char *s);
void create_node(Multiply *pm);
void _push(char c, Multiply *pm);
void multiply_nums(char *arg1, char *arg2,
	Multiply *pm, int s1_len, int s2_len);
void multiply_first_num(char *arg1, char *arg2, Multiply *pm,
int s1_len, int s2_len);
void print(Multiply *pm);
void free_nodes(Multiply *pm);

#endif /* #ifndef MAIN_H */
