#include <iostream>
// #include <stack>

using namespace std;

class stack
{
    public:
        stack(int num);
        void push(int el); //помещает элемент в стек
        int pop(); // возвращает значение верхнего элемента и удаляет его
        int top(); // возвращает значение верхнего элемента
        int num(); // возвращает кол-во элементов
        void print(); // выводит стек на экран
        bool find(int el); // не знаю, для чего это ;D
    private:
        int topSt, numSt;
        int *st;
};

stack::stack(int num)
{
    numSt = num;
    st = new int[numSt];
    topSt = -1;
}

void stack::push(int el)
{
    if (topSt == numSt - 1)
        cout << "Стек заполнен!\n";
    else
    {
        st[topSt + 1] = el;
        topSt++;
    }
}

int stack::top()
{
    if (topSt <= -1)
    {
        cout << "Стек пуст!\n";
        topSt = -1;
        return (0);
    }
    else
        return (st[topSt]);
}

int stack::pop()
{
    int k = top();
    st[topSt] = 0;
    topSt--;
    if (topSt <= - 1)
    {
        if (topSt == -1)
            cout << "\nCтек пуст!\n";
        topSt = -1;
        return (0);
    }
    else
        return (k);
}

int stack::num()
{
    return (topSt + 1);
}

bool stack::find (int el)
{
    for (int i = 0; i <= topSt; i++)
        if (st[i] == el)
            return true;
        else return false;
}

void stack::print()
{
    cout << "\nСтек:\n";
    for (int i = topSt; i >= 0; i--)
        cout << "\t" << st[i] << endl;

    cout << "Кол-во элементов в стеке: " << topSt + 1 << endl;
    cout << "Кол-во свободных мест: " << (numSt - 1) - topSt << endl;
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
    stack iStack(num);

    for (int i = 0; i < num; i++)
        iStack.push(p[i]);

    iStack.print();

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
            if (iStack.num() == num)
            {
                cout << "\nСтек заполнен! Удалить элемент? 1 - да, 0 - нет: ";
                cin >> flag;
                if (flag)
                    iStack.pop();
            }
            else
            {
                cout << "Введите значение: ";
                cin >> newEl;
                iStack.push(newEl);
            }
        }
        else
            iStack.pop();

        if (iStack.num() != 0)
            iStack.print();

        cout << "\nПродолжить? 1 - да, 0 - нет: ";
        cin >> flag;
    }

    return 0;
}
