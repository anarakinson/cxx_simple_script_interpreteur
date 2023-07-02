# Самодельный интерпретатор 

--- 

Задачи:

Написать интерпретатор кода, который выполняет следующие задачи:

1. Вычисляет значения математических выражений, состоящих из чисел и простых операторов (+ - * /).
2. Учитывает приоритет операторов
3. Учитывает скобки.
4. Распознает унарные (+ -).
5. Вычисляет ряд выражений, разделённых точкой с запятой (;).
6. Имеет встроенные константы (pi, e).
7. Позволяет создавать собственные константы с помощью оператора присваивания (=).
8. Имеет встроенные функции.
9. Позволяет задавать собственные функции.

---

Примерная структура проекта:

1. Лексический анализатор для преобразования поданной строки в набор токенов.
2. Синтаксический анализатор для преобразования токенов в набор команд.
3. Вычислитель для исполнения команд.

