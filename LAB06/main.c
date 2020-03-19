#include <stdio.h>
#include <stdlib.h>
#include "treeapi.h"

struct node{
 struct file *file;
 struct node *next;
};

struct queue
{
    struct node *front, *rear;
};

struct node *newNode(struct file* file);
struct queue *createQueue();
void enQueue(struct queue *q,struct file* file);
struct file *deQueue(struct queue *q);
struct node *printQueue_rec(struct node *temp);
void printQueue(struct queue *q);

struct node *newNode(struct file* file)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->file = file;
    temp->next = NULL;
    return temp;
}
struct queue *createQueue()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}
void enQueue(struct queue *q,struct file* file)
{
    struct node *temp = newNode(file);

    if (q->rear == NULL)
    {
        q->front = temp;
        q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}
struct file *deQueue(struct queue *q)
{
    if (q->front == NULL)
        return NULL;
    struct file *temp = q->front->file;

    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;
    printf("%s ",temp->fileName);
    return temp;
}

void add_directory(struct queue *q,struct file* f){
    if(f == NULL){
        return;
    }
    while(f != NULL)
    {
        enQueue(q,f);
        f = f->next;
    }
}
void printTree(struct file *tree, struct node *head){
    struct queue *q = createQueue();
    add_directory(q,tree);
    while(q->front != NULL)
    {
       struct file* f = deQueue(q);
       add_directory(q,f->subdir);
    }
}

int main(void)
{
 struct file *tree = createTree();
 struct node *head = NULL;
 printTree(tree, head);
 freeTree(tree);
 return 0;
}

