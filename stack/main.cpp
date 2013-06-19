/*2013*/

#include <iostream>
// #include <stack>

using namespace std;

class stack
{
    public:
        stack();
        void push(int el); //помещает элемент в стек
        int pop(); // возвращает значение верхнего элемента и удаляет его
        int top(); // возвращает значение верхнего элемента
        void print(); // выводит стек на экран
        bool find(int el); // возвращает true, если элемент найден, и false в противном случае
    private:
        int *topSt, num;
};

stack::stack()
{
   num = 0;
}

void stack::push(int el)
{
    topSt = topSt + 1;
    topSt = new int (el);
    num++;
}

int stack::top()
{
    int result = *topSt;

    if (num <= 0)
    {
        cout << "\nСтек пуст!\n";
        result = -1;
    }

    return(result);
}

int stack::pop()
{
    int result = 0;

    num--;

    if (num <= 0)
    {
        if (topSt == 0)
            cout << "\nCтек пуст!\n";
        num = 0;
    }
    else
    {
        result = top();
        *topSt = 0;
        topSt = topSt - 4;
    }

    return (result);
}

bool stack::find(int el)
{
    int h = 0;
    bool result = false;
    for (int i = 0; i < num; i++)
    {
        if (*topSt == el)
            result = true;

        topSt = topSt - 4;
        h++;
    }

    topSt = topSt + 4 * h;

    return (result);
}

void stack::print()
{
    if (num == 0)
        cout << "\nСтек пуст!\n";
    else
    {
        cout << "\nСтек:\n";
        int k = 0;

        for (int i = num ; i > 0; i--)
        {
            cout << *topSt << "\t// " << topSt << endl;
            topSt = topSt - 4;
            k = k + 1;
        }
        topSt = topSt + 4 * k;

        cout << "top: " << *topSt << "\t// " << topSt << "\n";
    }

}

int main()
{
    // создаём массив из num элементов и выводим на экран
    int num;

    do
    {
        cout << "Введите кол-во элементов: ";
        cin >> num;
        if (num <= 0)
            cout << "Кол-во должно быть >= 0!\n";
    }
    while (num <= 0);

    cout << "\nМассив:  ";

    int *p = new int[num];

    for (int i = 0; i < num; i++)
    {
        p[i] = i;
        cout << p[i] << "\t";
    }

    // создаём стек на базе массива
    stack St;
    stack *iStack = &St;

    for (int i = 0; i < num; i++)
        iStack->push(p[i]);

    iStack->print();

    int newEl;
    bool flag;

    cout << "\nСовершить действие? 1 - да, 0 - нет: ";
    cin >> flag;

    while (flag)
    {
        cout << "1 - добавить элемент, 0 - удалить элемент: ";
        cin >> flag;

        if (flag)
        {
            cout << "Введите значение: ";
            cin >> newEl;
            iStack->push(newEl);
        }
        else
            iStack->pop();

        iStack->print();

        cout << "\nПродолжить? 1 - да, 0 - нет: ";
        cin >> flag;
    }

    cout << "\nИщем элемент:";

    int findEl;
    cout << "\nВведите значение: ";
    cin >> findEl;

    if (iStack->find(findEl))
        cout << "Элемент найден!\n";
    else
        cout << "Элемент отсутствует в стеке!";

    return 0;
}

