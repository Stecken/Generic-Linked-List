#include <stdio.h>
#include <stdlib.h>

/*************************
Stecken, 2021
Generic Linked List in C
*************************/

/****************LINKED LIST*****************/
// example: each node have a generic data, and pointer to next node(or not), so is a linked list


typedef struct Node { // generic node
	void *data; // pointer to generic data
	struct Node *next; // pointer to next struct node
} node;

node* initList(void* data) {
	node * pnode = NULL;
	pnode = (node *) malloc(sizeof(node));
	
	pnode->data = data;
	pnode->next = NULL;
	return pnode;
}

node* push(node* pnode, void* data) {
	while(pnode->next != NULL) {
		pnode = pnode->next;
	} // pointer to last node;

	pnode->next = (node *) malloc(sizeof(node)); // next node
	
	pnode->next->data = data;
	pnode->next->next = NULL;
	
	return pnode;
}

void* pop(node** pnode){// retira todos os itens
	int count = 1;
	void* data;
	if ((*pnode)->next == NULL) {
		printf("\nclear first pnode->data = %d\n", (*pnode)->data);
		data = (*pnode)->data;
		free(*pnode);
		*pnode = NULL;
		return data;
	}
	while(pnode != NULL) {
		if ((*pnode)->next->next == NULL) {
			printf("\nclear last pnode->data = %d\n",(*pnode)->next->data);
			data = (*pnode)->next->data;
			free((*pnode)->next);
			(*pnode)->next = NULL;
			break;
		}
		count = count + 1;
		(*pnode) = (*pnode)->next;
	}
	
	printf("Limpando node: %d\n", count);
	return data;
}

int printAllNode(node* pnode){
	int count = 0;
	printf("\n\n\nPRINTANDO NODE\n");
	if (pnode != NULL ) {
		while(pnode != NULL) {
			printf("\nnode: %d\ndata: %d\n", count, pnode->data);
			pnode = pnode->next;
			count = count + 1;
		}
	}
	else {
		puts("\nempty list\n");
	}
	
	return 1;
}

void clearAllNode(node** pnode){
	while((*pnode) != NULL) {
		pop(pnode);
	}
	printf("Node Totalmente Limpo");
}

int main(int argv, char* argc[]) {
	node* list = initList((int*) 23);
	
	push(list, (int*) 29);
	push(list, (int*) 25);
	push(list, (int*) 27);
	push(list, (int*) 489);
	printAllNode(list);
	
	push(list, (int*) 35);
	printAllNode(list);
	printf("\nList Final: %d\n", *list);
	clearAllNode(&list);
	printAllNode(list);
	system("pause");
	return 0; // sucess
}
