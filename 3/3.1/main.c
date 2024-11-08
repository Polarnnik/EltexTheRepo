#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

mode_t modify_mode(mode_t mode, const char *mod_command) {
    char who = mod_command[0];
    char op = mod_command[1];
    char perm = mod_command[2];

    mode_t mask = 0;
    if (perm == 'r') mask = 0444;
    if (perm == 'w') mask = 0222;
    if (perm == 'x') mask = 0111;

    if (op == '+') {
        if (who == 'u') mode |= (mask & 0700);
        if (who == 'g') mode |= (mask & 0070);
        if (who == 'o') mode |= (mask & 0007);
    } else if (op == '-') {
        if (who == 'u') mode &= ~(mask & 0700);
        if (who == 'g') mode &= ~(mask & 0070);
        if (who == 'o') mode &= ~(mask & 0007);
    }

    return mode;
}

void print_permissions(mode_t mode) {
    char permissions[10] = "---------";

    if (mode & S_IRUSR) permissions[0] = 'r';
    if (mode & S_IWUSR) permissions[1] = 'w';
    if (mode & S_IXUSR) permissions[2] = 'x';
    if (mode & S_IRGRP) permissions[3] = 'r';
    if (mode & S_IWGRP) permissions[4] = 'w';
    if (mode & S_IXGRP) permissions[5] = 'x';
    if (mode & S_IROTH) permissions[6] = 'r';
    if (mode & S_IWOTH) permissions[7] = 'w';
    if (mode & S_IXOTH) permissions[8] = 'x';

    printf("Буквенное представление: %s\n", permissions);
    printf("Цифровое представление: %o\n", mode & 0777);
    printf("Битовое представление: %03o\n", mode & 0777);
}

mode_t parse_mode_string(const char *str) {
    mode_t mode = 0;
    for (int i = 0; i < 9; ++i) {
        if (str[i] == 'r') mode |= (1 << (8 - i));
        if (str[i] == 'w') mode |= (1 << (8 - i));
        if (str[i] == 'x') mode |= (1 << (8 - i));
    }
    return mode;
}

void get_permissions_from_file(const char *filename) {
    struct stat fileStat;
    if (stat(filename, &fileStat) < 0) {
        perror("Ошибка при получении информации о файле");
        return;
    }
    printf("Имя файла: %s\n", filename);
    print_permissions(fileStat.st_mode);
}

int main() {
    char input[256];
    char filename[256];
    int choice;

    while (1) {
        printf("Выберите действие:\n");
        printf("1. Ввести права доступа в буквенном/цифровом формате и показать битовое представление.\n");
        printf("2. Ввести имя файла и показать права доступа.\n");
        printf("3. Изменить права доступа (симуляция chmod).\n");
        printf("4. Выход.\n");
        printf("Ваш выбор: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Введите права доступа в буквенном (например, rwxr-xr-x) или цифровом формате (например, 755): ");
                scanf("%s", input);
                if (strlen(input) == 9) {
                    mode_t mode = parse_mode_string(input);
                    print_permissions(mode);
                } else {
                    mode_t mode = strtol(input, NULL, 8);
                    print_permissions(mode);
                }
                break;

            case 2:
                printf("Введите имя файла: ");
                scanf("%s", filename);
                get_permissions_from_file(filename);
                break;

            case 3:
                printf("Введите текущие права доступа в цифровом формате (например, 755): ");
                scanf("%s", input);
                mode_t mode = strtol(input, NULL, 8);

                printf("Введите команду модификации атрибутов (например, u+x, g-w): ");
                scanf("%s", input);

                mode = modify_mode(mode, input);

                printf("Измененные права доступа:\n");
                print_permissions(mode);
                break;

            case 4:
                return 0;

            default:
                printf("Неверный выбор. Попробуйте снова.\n");
        }
    }
    return 0;
}
