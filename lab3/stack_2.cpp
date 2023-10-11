#include <stdlib.h>
#include <iostream>

// Функция stackMemory1, которая создает целочисленную переменную a в своей локальной области видимости и возвращает указатель на эту переменную. Однако после завершения функции a выходит из области видимости, и указатель, возвращенный из функции, теперь указывает на недействительную память.

int* stackMemory1()
{
    int a = 1;
    return &a;
}

//Аналогично функция stackMemory2 - создает переменную b, возвращая указатель на нее. После завершения функции переменная b становится недействительной.

int* stackMemory2()
{
    int b = 2;
    return &b;
}

//В функции main вызываются функции stackMemory1 и stackMemory2. Результаты их вызовов сохраняются в указателях b и c. Значения, на которые указывают b и c, копируются в переменные a1 и a2. Однако, после завершения соответствующих функций переменные a и b больше не действительны, и поэтому доступ к ним через указатели b и c является недействительным.

int main()
{
    int* b = stackMemory1();
    int a1 = *b; 
    int* c = stackMemory2();
    int a2 = *c; 
    int a3 = *b; 

//Вывод значений a1, a2 и a3 на экран. a1 и a2 содержат значения, которые находятся в недействительных областях памяти, поэтому вывод может быть непредсказуемым.

    std::cout << a1 << std::endl; 
    std::cout << a2 << std::endl; 
    std::cout << a3 << std::endl; 

//вычисление разницы в байтах между указателями b и c

    std::cout << ((std::byte*) b - (std::byte*) c) << std::endl;

    return 0;
}