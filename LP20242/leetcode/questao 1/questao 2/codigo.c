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
    struct node* sorted = NULL;
    struct node* current = head;

    while (current != NULL) {
        struct node* nextNode = current->next;
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

struct node* arrayIntersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    struct node* head = NULL;
    for (int i = 0; i < nums1Size; i++) {
        for (int j = 0; j < nums2Size; j++) {
            if (nums1[i] == nums2[j]) {
                head = insertNode(head, nums1[i]);
                break;
            }
        }
    }

    head = insertionSort(head);
    struct node* current = head;
    int size = 0;
    while (current != NULL) {
        size++;
        current = current->next;
    }

    int* result = (int*)malloc(size * sizeof(int));
    current = head;
    for (int i = 0; i < size; i++) {
        result[i] = current->conteudo;
        current = current->next;
    }
    
    *returnSize = size;
    return result;
}

int main() {
    int nums1[] = {1, 2, 2, 1};
    int nums2[] = {2, 2};
    int returnSize;
    int* result = arrayIntersection(nums1, 4, nums2, 2, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    int nums3[] = {4, 9, 5};
    int nums4[] = {9, 4, 9, 8, 4};
    result = arrayIntersection(nums3, 3, nums4, 5, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}
