#include <stdio.h>
#include <stdlib.h>

struct node {
    int conteudo;
    struct node *next;
};

// Função para criar um novo nó
struct node* createNode(int conteudo) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->conteudo = conteudo;
    newNode->next = NULL;
    return newNode;
}

// Função para inserir um nó no final da lista
struct node* insertNode(struct node* head, int conteudo) {
    struct node* currentNode = head;
    
    // Se a lista estiver vazia, cria o primeiro nó
    if (head == NULL) {
        return createNode(conteudo);
    }

    // Caso contrário, encontra o último nó e o adiciona
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    currentNode->next = createNode(conteudo);
    return head;  // Retorna o ponteiro head original
}

// Função para imprimir a lista
void printList(struct node* head) {
    struct node* currentNode = head;
    while (currentNode != NULL) {
        printf("%d -> ", currentNode->conteudo);
        currentNode = currentNode->next;
    }
    printf("NULL\n");
}

// Função de ordenação Bubble Sort
void bubbleSort(struct node** head) {
    int swapped;
    struct node* ptr;
    struct node* lastPtr = NULL;

    // Verifica se a lista não está vazia
    if (*head == NULL) return;

    do {
        swapped = 0;
        ptr = *head;

        // Percorre a lista
        while (ptr->next != lastPtr) {
            if (ptr->conteudo > ptr->next->conteudo) {
                // Troca os valores dos nós
                int temp = ptr->conteudo;
                ptr->conteudo = ptr->next->conteudo;
                ptr->next->conteudo = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
        lastPtr = ptr;
    } while (swapped);  // Continua até não haver mais trocas
}

int main() {
    struct node* head = NULL;
    
    // Insere os elementos na lista
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

    printf("Lista antes da ordenação: \n");
    printList(head);

    // Ordena a lista
    bubbleSort(&head);

    printf("Lista após a ordenação: \n");
    printList(head);

    return 0;
}
