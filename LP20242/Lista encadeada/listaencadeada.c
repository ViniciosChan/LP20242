#include<stdio.h>
#include<stdlib.h>

struct node {
    int    conteudo;
    struct node *next;
};


struct node* createNode(int conteudo){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->conteudo=conteudo;
    newNode->next=NULL;
    return newNode;
}

struct node* insertNode(struct node*head,int conteudo){
    struct node* currentNode=head;
    while(currentNode->next!=NULL){
        currentNode=currentNode->next;

    }
    currentNode->next=createNode(conteudo);
    
}

void printlist(struct node* head){
    struct node* currentNode=head;
    while(currentNode!=NULL){
        printf("%d ->", currentNode->conteudo);
        currentNode=currentNode->next;
    }
}

int main(){
    
    struct node* head=NULL;
    head=createNode(-2);
    insertNode (head, 2);
    insertNode (head, 6);
    insertNode (head, 9);
    insertNode (head, 1);
    insertNode (head, 8);
    insertNode (head, 0);
    insertNode (head, 4);
    insertNode (head, 5);
    insertNode (head, 55);
    insertNode (head, 3);
    insertNode (head, 8);
    printlist(head);
}
