#include "contacts.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>



void readInput(char* buffer, int length) {
    fgets(buffer, length, stdin);
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }
}

Contact* createContact() {
    Contact* newContact = (Contact*)malloc(sizeof(Contact));
    if (newContact == NULL) {
        printf("Ошибка выделения памяти.\n");
        return NULL;
    }

    printf("Введите фамилию: ");
    readInput(newContact->lastName, MAX_STRING_LENGTH);
    printf("Введите имя: ");
    readInput(newContact->firstName, MAX_STRING_LENGTH);
    printf("Введите место работы (необязательно): ");
    readInput(newContact->workPlace, MAX_STRING_LENGTH);
    printf("Введите должность (необязательно): ");
    readInput(newContact->position, MAX_STRING_LENGTH);
    printf("Введите номер телефона (необязательно): ");
    readInput(newContact->phone, MAX_STRING_LENGTH);
    printf("Введите email (необязательно): ");
    readInput(newContact->email, MAX_STRING_LENGTH);
    printf("Введите ссылку на соц. сети (необязательно): ");
    readInput(newContact->socialMedia, MAX_STRING_LENGTH);
    printf("Введите мессенджер (необязательно): ");
    readInput(newContact->messenger, MAX_STRING_LENGTH);

    return newContact;
}

void displayContact(Contact* contact) {
    printf("Фамилия: %s\n", contact->lastName);
    printf("Имя: %s\n", contact->firstName);
    printf("Место работы: %s\n", contact->workPlace[0] ? contact->workPlace : "Не указано");
    printf("Должность: %s\n", contact->position[0] ? contact->position : "Не указана");
    printf("Телефон: %s\n", contact->phone[0] ? contact->phone : "Не указан");
    printf("Email: %s\n", contact->email[0] ? contact->email : "Не указан");
    printf("Соц. сети: %s\n", contact->socialMedia[0] ? contact->socialMedia : "Не указано");
    printf("Мессенджер: %s\n", contact->messenger[0] ? contact->messenger : "Не указан");
    printf("-------------------------\n");
}

void editContact(Contact* contact) {
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