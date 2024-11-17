#include <stdio.h>
#include <stdlib.h>


float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);


typedef float (*Operation)(float, float);

typedef struct {
    char *name;      
    Operation func;  
} Command;

int main() {
    Command commands[] = {
        {"Сложение", add},
        {"Вычитание", subtract},
        {"Умножение", multiply},
        {"Деление", divide},
        {NULL, NULL} 
    };

    int choice;
    float num1, num2, result;

    while (1) {
        printf("\nКалькулятор\n");
        for (int i = 0; commands[i].name != NULL; i++) {
            printf("%d. %s\n", i + 1, commands[i].name);
        }
        printf("%d. Выход\n", sizeof(commands) / sizeof(commands[0]));

        printf("Выберите действие (1-%d): ", sizeof(commands) / sizeof(commands[0]));
        
        scanf("%d", &choice);

        if (choice == sizeof(commands) / sizeof(commands[0])) {
            printf("Выход из программы.\n");
            break;
        }

        printf("Введите два числа: ");
        scanf("%f %f", &num1, &num2);

        if (choice < 1 || choice > sizeof(commands) / sizeof(commands[0]) - 1) {
            printf("Некорректный выбор. Пожалуйста, выберите действие от 1 до %d.\n", sizeof(commands) / sizeof(commands[0]) - 1);
            continue;
        }

        result = commands[choice - 1].func(num1, num2);
        printf("Результат: %.2f\n", result);
    }

    return 0;
}

float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    return a / b;
}
