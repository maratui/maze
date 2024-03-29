# Maze (Linux, Mac)

## Реализация проекта Maze

Реализовал программу Maze, позволяющую генерировать и отрисовывать идеальные лабиринты:
- Программа разработана на языке C++
- Код программы находится в папке src
- При написании кода придерживался Google Style
- Сборка программы настроена с помощью Makefile со стандартным набором целей для GNU-программ: all, install, uninstall, clean, dvi, dist, tests.
- В программе реализован графический пользовательский интерфейс на базе Qt
- В программе предусмотрена кнопка для загрузки лабиринта из файла
- Максимальный размер лабиринта - 50х50
- Загруженный лабиринт отрисовывается на экране в поле размером 500 x 500 пикселей
- Толщина "стены" - 2 пикселя
- Размер самих ячеек лабиринта вычисляется таким образом, чтобы лабиринт занимал всё отведенное под него поле

## Генерация идеального лабиринта

Добавлена возможность автоматической генерации идеального лабиринта. \
Идеальным считается лабиринт, в котором из каждой точки можно попасть в любую другую точку ровно одним способом.
- Лабиринт генерируется согласно **алгоритму Эллера**
- Сгенерированный лабиринт не имеет изолированных областей и петель
- Обеспечено полное покрытие unit-тестами модуля генерации идеального лабиринта
- Пользователем вводится только размерность лабиринта: количество строк и столбцов
- Сгенерированный лабиринт сохраняется в файл
- Созданный лабиринт отображается на экране

## Решение лабиринта

Добавлена возможность показать решение лабиринта, который сейчас изображен на экране:
- Пользователем задаются начальная и конечная точки
- Маршрут, являющийся решением, отображается линией толщиной 2 пикселя, проходящей через середины всех ячеек лабиринта, через которые пролегает решение
- Цвет линии решения отличается от цветов стен и поля
- Обеспечено полное покрытие unit-тестами модуля решения лабиринта

