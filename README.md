Лабраторная работа 1

Задание:
        Написать программу на языке C/C++ для перемножения двух матриц. 
        Исходные данные: файл(ы) содержащие значения исходных матриц.
        Выходные данные: файл со значениями результирующей матрицы, время выполнения, объем задачи.
        Обязательна автоматизированная верификация результатов вычислений с помощью сторонних библиотек или стороннего ПО (например на Matlab/Python).

Source.spp:
        Данный файл содержит код C++, который создаёт и заполняет два файла, - matrix_1.txt и matrix_2.txt, - псеводслучайными значениями в упроделенной упорядочённости - генерирует квадратные матрицы (для простоты умножения) 
        заданных размеров от 100 до 1 000, перемножает их, записывая затем результат в файл result_matrix.txt. В файл stats.txt записываются значения размера матриц, объема работ и времени выполнения для всех случаев.

Work.ipynb:
        Файл содержит функции для проверки точность умножения в другом файле, выводит таблицу времнём выполнения перемножения матриц всех размеров по 10 попыток на каждую. Также строиться табица зависимости времени перемножения 
        от размера.
        ![image](https://github.com/PripyatskyPrometheus/paralel_proga_1/assets/113877569/0ff95c6e-7007-4c05-ac26-5a0bd50e40d8)

Вывод:
        Время выполнения переумножения увеличивается, при возрастании размеров матрицы.
