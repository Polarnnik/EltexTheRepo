#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_STRING_LENGTH 50

typedef struct {
    char lastName[MAX_STRING_LENGTH];
    char firstName[MAX_STRING_LENGTH];
    char workPlace[MAX_STRING_LENGTH];
    char position[MAX_STRING_LENGTH];
    char phone[MAX_STRING_LENGTH];
    char email[MAX_STRING_LENGTH];
    char socialMedia[MAX_STRING_LENGTH];
    char messenger[MAX_STRING_LENGTH];
} Contact;

Contact contacts[MAX_CONTACTS];
int contactCount = 0;

void readInput(char *buffer, int length) {
    fgets(buffer, length, stdin);
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }
}

void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Телефонная книга заполнена.\n");
        return;
    }

    Contact newContact;

    printf("Введите фамилию: ");
    readInput(newContact.lastName, MAX_STRING_LENGTH);
    printf("Введите имя: ");
    readInput(newContact.firstName, MAX_STRING_LENGTH);

    printf("Введите место работы (необязательно): ");
    readInput(newContact.workPlace, MAX_STRING_LENGTH);
    printf("Введите должность (необязательно): ");
    readInput(newContact.position, MAX_STRING_LENGTH);
    printf("Введите номер телефона (необязательно): ");
    readInput(newContact.phone, MAX_STRING_LENGTH);
    printf("Введите email (необязательно): ");
    readInput(newContact.email, MAX_STRING_LENGTH);
    printf("Введите ссылку на соц. сети (необязательно): ");
    readInput(newContact.socialMedia, MAX_STRING_LENGTH);
    printf("Введите мессенджер (необязательно): ");
    readInput(newContact.messenger, MAX_STRING_LENGTH);

    contacts[contactCount++] = newContact;
    printf("Контакт добавлен!\n");
}

void displayContacts() {
    if (contactCount == 0) {
        printf("Телефонная книга пуста.\n");
        return;
    }
    printf("\n-------------------------\n");

    for (int i = 0; i < contactCount; i++) {
        printf("Контакт %d:\n", i + 1);
        printf("Фамилия: %s\n", contacts[i].lastName);
        printf("Имя: %s\n", contacts[i].firstName);
        printf("Место работы: %s\n", contacts[i].workPlace[0] ? contacts[i].workPlace : "Не указано");
        printf("Должность: %s\n", contacts[i].position[0] ? contacts[i].position : "Не указана");
        printf("Телефон: %s\n", contacts[i].phone[0] ? contacts[i].phone : "Не указан");
        printf("Email: %s\n", contacts[i].email[0] ? contacts[i].email : "Не указан");
        printf("Соц. сети: %s\n", contacts[i].socialMedia[0] ? contacts[i].socialMedia : "Не указано");
        printf("Мессенджер: %s\n", contacts[i].messenger[0] ? contacts[i].messenger : "Не указан");
        printf("-------------------------\n");
    }
}

void deleteContact() {
    int index;
    printf("Введите номер контакта для удаления: ");
    scanf("%d", &index);
    getchar();
    if (index < 1 || index > contactCount) {
        printf("Некорректный номер контакта.\n");
        return;
    }

    for (int i = index - 1; i < contactCount - 1; i++) {
        contacts[i] = contacts[i + 1];
    }
    contactCount--;
    printf("Контакт удален!\n");
}

void editContact() {
    int index;
    printf("Введите номер контакта для редактирования: ");
    scanf("%d", &index);
    getchar();
    if (index < 1 || index > contactCount) {
        printf("Некорректный номер контакта.\n");
        return;
    }

    Contact *contact = &contacts[index - 1];
    printf("Редактирование контакта %d:\n", index);

    printf("Введите новую фамилию (%s): ", contact->lastName);
    readInput(contact->lastName, MAX_STRING_LENGTH);
    printf("Введите новое имя (%s): ", contact->firstName);
    readInput(contact->firstName, MAX_STRING_LENGTH);
    printf("Введите новое место работы (%s): ", contact->workPlace);
    readInput(contact->workPlace, MAX_STRING_LENGTH);
    printf("Введите новую должность (%s): ", contact->position);
    readInput(contact->position, MAX_STRING_LENGTH);
    printf("Введите новый телефон (%s): ", contact->phone);
    readInput(contact->phone, MAX_STRING_LENGTH);
    printf("Введите новый email (%s): ", contact->email);
    readInput(contact->email, MAX_STRING_LENGTH);
    printf("Введите новую ссылку на соц. сети (%s): ", contact->socialMedia);
    readInput(contact->socialMedia, MAX_STRING_LENGTH);
    printf("Введите новый мессенджер (%s): ", contact->messenger);
    readInput(contact->messenger, MAX_STRING_LENGTH);

    printf("Контакт обновлен!\n");
}

int main() {
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
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                deleteContact();
                break;
            case 4:
                editContact();
                break;
            case 5:
                printf("Выход из программы.\n");
                return 0;
            default:
                printf("Некорректный выбор, попробуйте снова.\n");
        }
    }
}
