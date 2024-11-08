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

void mergeArrays(int* nums1, int m, int* nums2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}

int main() {


    int nums1[] = {1, 2, 3, 0, 0, 0};
    int m = 3;
    int nums2[] = {2, 5, 6};
    int n = 3;

    mergeArrays(nums1, m, nums2, n);
    for (int i = 0; i < m + n; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    return 0;
}
