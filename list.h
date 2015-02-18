#include <stdio.h>
#include <stdlib.h>

typedef struct list{
	struct list * next;
	void * data;
}list;

typedef struct head{
	list * l;
	int size;
}head;

typedef void (*COMPUTE_EACH_ITEM)(void *data);

void add_node_begin(head * head, void * data);

head * create_new_list();

void for_each_node_call(void * data, head * head,COMPUTE_EACH_ITEM func);

void free_list (head * head);

#define for_each_item(item, list) \
	__typeof__(list) _l; \
	for(_l = (list); _l != NULL; _l = _l->next){ \
		item = _l->data;

#define for_each_item_call(item, list, func) \
	__typeof__(list) _l; \
	for(_l = (list); _l != NULL; _l = _l->next){ \
		item = _l->data; \
		func(item);}

