#include "../test_header.h"
#include <assert.h>

typedef struct testData{
	int x;
}testData;

void print(void * d){
	printf("Data: %d\n", ((testData*)d)->x);
}



void add_file_elements(){
	testData * data1 = malloc(sizeof(testData));
	head * h = create_new_list();

	data1->x = 5;
	add_node_begin(h, data1);


	testData * data2 = malloc(sizeof(testData));
	data2->x = 10;
	add_node_begin(h, data2);

	testData * data3 = malloc(sizeof(testData));
	data3->x = 15;
	add_node_begin(h, data3);

	testData * data4 = malloc(sizeof(testData));
	data4->x = 10;
	add_node_begin(h, data4);

	testData * data5 = malloc(sizeof(testData));
	data5->x = 100;
	add_node_begin(h, data5);

	assert(h->size == 5);

	free_list(h);

}

void run_list_add_tests(){
	add_file_elements();
}

