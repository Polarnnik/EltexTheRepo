#include <stdio.h>

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

int main() {
    int choice;
    float num1, num2, result;

    while (1) {
        printf("\nКалькулятор\n");
        printf("1. Сложение\n");
        printf("2. Вычитание\n");
        printf("3. Умножение\n");
        printf("4. Деление\n");
        printf("5. Выход\n");
        printf("Выберите действие (1-5): ");
        
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Выход из программы.\n");
            break;
        }

        printf("Введите два числа: ");
        scanf("%f %f", &num1, &num2);

        switch (choice) {
            case 1:
                result = add(num1, num2);
                printf("Результат: %.2f\n", result);
                break;
            case 2:
                result = subtract(num1, num2);
                printf("Результат: %.2f\n", result);
                break;
            case 3:
                result = multiply(num1, num2);
                printf("Результат: %.2f\n", result);
                break;
            case 4:
                if (num2 != 0) {
                    result = divide(num1, num2);
                    printf("Результат: %.2f\n", result);
                } else {
                    printf("Ошибка: деление на ноль невозможно.\n");
                }
                break;
            default:
                printf("Некорректный выбор. Пожалуйста, выберите действие от 1 до 5.\n");
                break;
        }
    }

    return 0;
}