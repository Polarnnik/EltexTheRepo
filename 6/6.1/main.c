#include <stdio.h>
#include "linkedList.h"
#include "contacts.h"

int main() {
    LinkedList* contactList = createLinkedList();
    int choice;

    while (1) {
        printf("\nТелефонная книга:\n");
        printf("1. Добавить контакт\n");
        printf("2. Показать все контакты\n");
        printf("3. Удалить контакт\n");
        printf("4. Редактировать контакт\n");
        printf("5. Выйти\n");
        printf("Выберите действие: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: {
                Contact* newContact = createContact();
                if (newContact != NULL) {
                    pushNode(contactList, newContact);
                    printf("Контакт добавлен!\n");
                }
                break;
            }
            case 2:
                if (contactList->size == 0) {
                    printf("Телефонная книга пуста.\n");
                } else {
                    Node* current = contactList->head;
                    int index = 1;
                    while (current != NULL) {
                        printf("Контакт %d:\n", index++);
                        displayContact(current->contact);
                        current = current->next;
                    }
                }
            break;
            case 3: {
                int index;
                printf("Введите номер контакта для удаления: ");
                scanf("%d", &index);
                getchar();
                deleteNode(contactList, index - 1);
                break;
            }
            case 4: {
                int index;
                printf("Введите номер контакта для редактирования: ");
                scanf("%d", &index);
                getchar();
                Node* nodeToEdit = getNodeAt(contactList, index - 1);
                if (nodeToEdit != NULL) {
                    editContact(nodeToEdit->contact);
                } else {
                    printf("Контакт не найден.\n");
                }
                break;
            }
            case 5:
                deleteList(contactList);
            printf("Выход.\n");
            return 0;
            default:
                printf("Неверный выбор, попробуйте снова.\n");
        }
    }
}