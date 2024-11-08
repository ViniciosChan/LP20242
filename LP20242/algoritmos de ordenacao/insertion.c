#include <stdio.h>
#include <stdlib.h>

struct node {
    int conteudo;
    struct node* next;
};

struct node* createNode(int conteudo) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }
    newNode->conteudo = conteudo;
    newNode->next = NULL;
    return newNode;
}

struct node* insertNode(struct node* head, int conteudo) {
    struct node* newNode = createNode(conteudo);
    if (head == NULL) {
        return newNode;
    }
    struct node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

void printList(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->conteudo);
        current = current->next;
    }
    printf("NULL\n");
}

struct node* insertionSort(struct node* head) {
    struct node* sorted = NULL; // Lista ordenada inicializada como vazia
    struct node* current = head;

    while (current != NULL) {
        struct node* nextNode = current->next; // Armazena o próximo nó
        if (sorted == NULL || sorted->conteudo >= current->conteudo) {
            current->next = sorted;
            sorted = current;
        } else {
            struct node* temp = sorted;
            while (temp->next != NULL && temp->next->conteudo < current->conteudo) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = nextNode;
    }
    return sorted;
}

int main() {
    struct node* head = NULL;
    head = insertNode(head, 7);
    head = insertNode(head, 8);
    head = insertNode(head, 2);
    head = insertNode(head, 9);
    head = insertNode(head, 0);
    head = insertNode(head, 5);
    head = insertNode(head, 4);
    head = insertNode(head, 6);
    head = insertNode(head, 3);
    head = insertNode(head, 1);

    printList(head);
    printf("\n");
    head = insertionSort(head);
    printList(head);

    return 0;
}
