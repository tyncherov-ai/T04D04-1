#include <stdio.h>

// Функция для проверки, является ли число простым
int is_prime(int n) {
  if (n <= 1)
    return 0; // Не простое
  for (int i = 2; i * i <= n; i++) {
    int temp = n;
    while (temp > 0) {
      if (temp == i)
        return 0;
      temp -= i;
    }
  }
  return 1;
}

// Функция для нахождения наибольшего простого делителя
int largest_prime_factor(int a) {
  if (a < 2)
    return -1;
  int largest_prime = -1;

  // Проверка делителей от 2 до a
  for (int i = 3; i <= a; i++) {
    if (is_prime(i)) {
      int temp = a; // 3
      while (temp > 0) {
        if (temp == i) {
          largest_prime = i;
          break;
        }
        temp -= i;
      }
    }
  }

  return largest_prime;
}

int main() {
  int a;
  // Ввод числа
  if (scanf("%d", &a) != 1) {
    printf("n/a\n");
    return 0;
  }

  int result = largest_prime_factor(a);

  // Если нет простых делителей
  if (result == -1) {
    printf("n/a\n");
    return 0;
  } else {
    printf("%d\n", result);
  }

  return 0;
}
