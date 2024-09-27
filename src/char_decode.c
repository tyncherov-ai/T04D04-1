#include <stdio.h>

void encode(const char *input) {
    while (*input) {
        // Пропускаем пробелы
        if (*input == ' ') {
            input++;
            continue;
        }
        // Проверяем, является ли символ допустимым печатным символом
        if (*input < 32 || *input > 126) {
            return; // Убираем вывод "n/a" при невалидных символах
        }
        // Печатаем шестнадцатеричное представление символа
        printf("%02X ", (unsigned char)(*input));
        input++;
    }
}

void decode(const char *input) {
    unsigned int num;
    int first = 1; // Флаг для управления пробелами
    while (sscanf(input, "%2X", &num) == 1) {
        // Проверяем, попадает ли число в диапазон печатных символов
        if (num < 32 || num > 126) {
            return; // Убираем вывод "n/a" при невалидных символах
        }
        // Печатаем пробел перед символом, если это не первый символ
        if (!first) {
            putchar(' ');
        }
        putchar((char)num);
        first = 0; // Сброс флага после первого символа
        input += 2; // Пропускаем два символа
        if (*input == ' ') {
            input++; // Пропускаем пробел
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Ошибка: необходимо указать режим (0 - кодирование, 1 - декодирование).\n");
        return 1;
    }

    // Проверка режима работы
    int mode;
    if (argv[1][0] == '0' && argv[1][1] == '\0') {
        mode = 0;
    } else if (argv[1][0] == '1' && argv[1][1] == '\0') {
        mode = 1;
    } else {
        fprintf(stderr, "Ошибка: режим должен быть 0 (кодирование) или 1 (декодирование).\n");
        return 1;
    }

    char buffer[1024];

    // Ввод строки
    printf("Введите буквы через пробел: ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        // Проверка на наличие пробелов
        int has_space = 0;
        for (int i = 0; buffer[i] != '\0'; i++) {
            if (buffer[i] == ' ') {
                has_space = 1;
                break;
            }
        }

        if (!has_space && mode == 0) {
            printf("Ошибка: необходимо вводить буквы через пробел для кодирования.\n");
            return 1;
        }

        if (mode == 0) {
            encode(buffer);
                printf("\n"); // Перенос строки после кодирования
        } else {
            decode(buffer);
                printf("\n"); // Перенос строки после кодирования
        }
    }

    return 0;
}
