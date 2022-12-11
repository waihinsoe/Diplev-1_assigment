#include "stdio.h"
#include "stdlib.h"
struct node {
    int data;
    struct node *next;
};

int searchingData(struct node *myNode, int data){
    if(myNode == NULL){
        printf("MyNode is Null!!");
        return -1;
    }
    while (myNode != NULL){
        if(myNode->data == data){
            return 1;
        }else{
            myNode = myNode->next;
        }
    }
    return -1;
}

void insertAfter(struct node *prev_node, int dataForNewNode){
    if(prev_node == NULL){
        printf("There is no data!!");
        return;
    }
    struct node *new_node = malloc(sizeof (struct node));
    new_node->data = dataForNewNode;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}


void printData(struct node *myNode){
    while(myNode != NULL){
        printf("%d\n", myNode->data);
        myNode = myNode->next;
    }
}

int main() {
    struct node *head=NULL;
    struct node *one=NULL;
    struct node *two=NULL;
    struct node *three=NULL;

    one  = malloc(sizeof (struct node));
    two  = malloc(sizeof (struct node));
    three  = malloc(sizeof (struct node));

    one->data = 10;
    two->data =20;
    three->data = 30;

    one->next = two;
    two->next = three;
    three->next = NULL;

    printData(one);
    insertAfter(one,15);
    printf("After inserting data ::\n");
    printData(one);
    int result = searchingData(one, 10);
    if(result == 1){
        printf("Found Data !!\n");
    }else{
        printf("Not found Data!!\n");
    }

    return 0;
}