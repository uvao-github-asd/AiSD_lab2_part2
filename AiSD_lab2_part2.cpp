#include <stdlib.h>
#include <iostream>
#include <Windows.h>

struct Queue 
{     int* data;
      int last;
      int first;
};  
class arr {
public:     int* y;    
      void cloning(Queue* x);     
      void copy(Queue* x);     
      void Print(Queue* x);     
      void insert(int n);     
      void enqueue(Queue* x, int a);     
      bool dequeue(Queue* x);     
      int N;     
      int t;     
      void init(Queue* x);    
      bool isempty(Queue* x);
};
bool arr::isempty(Queue* x) {
    if (x->last == x->first)    
        return false;     
    else  
        return true;
}
bool arr::dequeue(Queue* x) {

    if (isempty(x) == false) 
        return false;     
    t = x->data[x->first];     
    for (int h = x->first; h < x->last; h++) {
        x->data[h] = x->data[h + 1];
    }     
    x->last--;     
    return true;
}
void arr::cloning(Queue* x)
{

    Queue* c = new Queue;     
    N = 4;     
    init(c);     
    c->data = new int[N];
    while (c->last != x->last) {
        c->data = x->data;         
        c->last++;
    }
    printf("Клонирование структуры\n");     
    printf("Первая структура ");     
    Print(x);
    printf("Вторая структура ");
    Print(c);
}
void arr::Print(Queue* x)
{
    int i = 0;     
    printf("Вывод: ");     
    while (i < x->last) {
        printf("%d ", x->data[i]);         
        i++;
    }     
    printf("\n");
}
void arr::init(Queue* x)
{
    x->data = { 0 };     
    x->first = 0;     
    x->last = 0;
};
void arr::copy(Queue* x)
{
    N = N * 2;     
    y = new int[N];     
    for (int i = 0; i < x->last; i++)         
        y[i] = x->data[i];
    delete[] x->data;     
    x->data = new int[N];

    for (int i = 0; i < x->last; i++)         
        x->data[i] = y[i];     
    delete[] y;
    printf("Новый размер буфера %d\n", N);
};
void arr::enqueue(Queue* x, int a)
{
    if (x->last > N - 1)
    {
        printf("\nОчередь заполнена, пересоздаем очередь\n ");

        copy(x);

    }
    x->data[x->last++] = a;

};

; int main() 
{
    setlocale(LC_ALL, ("RUS"));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    arr arr;     
    Queue* x = new Queue;    
    arr.N = 4;    
    arr.init(x);     
    x->data = new int[arr.N];
    int a, choice, c = 0;


    printf("Размер буфера: %d\n ", arr.N);     
    printf("Вставьте элементы в очередь:\n");     
    do {
        scanf_s("%d", &a);        
        arr.enqueue(x, a);
    } while ((getchar()) != '\n');

    arr.Print(x);     

    do {
        printf("\n1.Вставить элемент в очередь"
            "\n2.Извлечь и вернуть первый элемент из очередь"
            "\n3.Клонировать очередь"
            "\n4.Вывести очередь"
            "\n5.Завершить"
            "\n\n Пожалуйста, выберите нужный вариант: ");

        scanf_s("%d", &choice);


        switch (choice)
        {
        case 1:

            printf("Введите ключ -:\t");             
            scanf_s("%d", &a);             
            arr.enqueue(x, a);

            break;
        case 2:

            bool b;             
            b = arr.dequeue(x);             
            if (b == true) {
                printf("True\n");                 
                arr.Print(x);                 
                arr.enqueue(x, arr.t);

            }
            else {
                printf("False\n");
            }             break;
        case 3:

            arr.cloning(x);
        break;         
        case 4:

            arr.Print(x);
        break;         
        case 5:             
            c = 1;             
            delete x;             
            break;
        default:
            printf("Недействительный ввод\n");
        }


    } 
    while (c != 1);


}
