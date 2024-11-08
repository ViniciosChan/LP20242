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

struct node* merge(struct node* left, struct node* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    struct node* result = NULL;
    if (left->conteudo <= right->conteudo) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}

void splitList(struct node* head, struct node** left, struct node** right) {
    struct node* slow = head;
    struct node* fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    *left = head;
    *right = slow->next;
    slow->next = NULL;
}

struct node* mergeSort(struct node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct node *left = NULL, *right = NULL;
    splitList(head, &left, &right);
    left = mergeSort(left);
    right = mergeSort(right);
    return merge(left, right);
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
    head = mergeSort(head);
    printList(head);

    return 0;
}
