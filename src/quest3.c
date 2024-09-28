#include <stdio.h>

// Функция для вычисления n-го числа Фибоначчи
int fibonacci(int n) {
  if (n < 0) {
    return -1;
  }
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
  int n;

  // Проверка на ввод числа
  if (scanf("%d", &n) != 1) {
    printf("n/a\n");
    return 1;
  }

  // Вычисляем n-ое число Фибоначчи
  int result = fibonacci(n);
  if (result == -1) {
    printf("n/a\n");
  } else {
    printf("%d\n", result);
  }

  return 0;
}
