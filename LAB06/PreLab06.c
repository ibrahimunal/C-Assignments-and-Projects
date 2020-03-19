#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
   char data;
   struct node *next;
};

struct Queue{
    struct node *rear,*front;
};



int isEmpty(struct Queue *q);
void enqueue(struct Queue *q, char ch);
char dequeue(struct Queue *q);
void initialize(struct Queue *q);
void display(struct node *n);
/int main()
{
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
        initialize(q);


    char command;
    printf("Start:\nAny Char Except;\n        [D]equeue\n        [P]rint All\n        [Q]uit\nTo Enqueue\n");
    do{

    scanf(" %c",&command);

    switch(command){

    case 'D' :
        if(isEmpty(q)>0){
            printf(">$\n");
        }
        else{

            printf(">%c\n",dequeue(q));
        }

    break;

    case 'P' :
        if(isEmpty(q)>0){
            printf("Empty.\n");
        }
        else{
                  printf("---\n");
        display(q->front);

        printf("\n---\n");

        }

    break;


    case 'Q' :

    break;

    default :
            enqueue(q,command);

    }

    }
    while(command != 'Q');

    return 0;
}



void enqueue(struct Queue *q, char ch){

    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=ch;
    newNode->next=NULL;
    if(q->rear==NULL){
        q->rear=q->front=newNode;
    }
    else{
        q->rear->next=newNode;
        q->rear=newNode;
    }

}
void display(struct node *n){
    if(n==NULL){
    return;
 }
    else {

        display(n->next);
        printf("%c ",n->data);
        }
    }



void initialize(struct Queue *q){
    q->front=NULL;
    q->rear=NULL;

}
char dequeue(struct Queue *q){
    struct node *temp;
    char ch=q->front->data;
    temp=q->front;
    q->front=q->front->next;
    return temp->data;

}

int isEmpty(struct Queue *q){
    if(q->front==NULL){

        return 1;

    }
    else return 0;


}







