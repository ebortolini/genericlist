#include"list.h"
#include <stdio.h>



list * newNode(){
	return malloc(sizeof(list));
}

head * create_new_list(){
	head * h = malloc(sizeof(head));
	list * l = newNode();
	l->data = l->next = NULL;
	h->l = l;
	h->size = 0;
	return h;
}

void add_node_begin(head * head, void * data){
	list* l = head->l;
	if(l->data == NULL){
		l->data = data;
		head->size++;
		return;
	}

	list * node = newNode();
	node->data = data;
	node->next = l;
	head->l = node;
	head->size++;
}

void for_each_node_call(void * data, head * head,COMPUTE_EACH_ITEM func){
	for_each_item_call(data,head->l,func);
}

void free_list (head * head){
	if(head == NULL || head->l == NULL)
		return;

	list * node = head->l;
	list * temp;
	while(node != NULL){
		temp = node->next;
		if(node->data != NULL)
			free(node->data);
		free(node);

		node = temp;
	}

	free(head);
}
