// Queue.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template <class T>
class vovan
{
private:
	int n, m;
	T temp;
	queue<T> q1, q2;
public:
	void vovka()
	{
		printf("Какое количество символов внести в очередь? \n");
		cin >> n;
		printf("Заполнение очереди: \n");
		for (int i = 0; i < n; i++) // Заполнение очереди q1
		{
			cin >> temp;
			q1.push(temp);
		}
		cout << endl;
		q2 = q1; // Дублируем очередь
		printf("Содержание очереди: \n");
		for (int i = 0; i < n; i++) // Показываем что содержится в очереди.
		{
			cout << q1.front() << " | ";
			q1.pop();
		}
		cout << endl;
		printf("Заполнение очереди: \n");
		for (int i = 0; i < n; i++) // Заполнение очереди q1
		{
			cin >> temp;
			q1.push(temp);
		}
		printf("Количество удаляемых элементов из первой очереди? \n");
		cin >> m;
		for (int i = 0; i < m; i++) // Удаление из первой очереди
		{
			q2.pop();
		}
		for (int i = 0; i < m; i++) // Переброска элементов из очереди q1 в очередь q2
		{
			q2.push(q1.front());
			q1.pop();
		}
		printf("Содержание первой очереди: \n");
		for (int i = 0; i < n; i++) // Показываем что содержится в очередях.
		{
			cout << " | " << q2.front();
			q2.pop();
		}
		cout << endl;
		printf("Содержание второй очереди: \n");
		for (int i = 0; i < n - m; i++)
		{
			cout << " | " << q1.front() << endl;
			q1.pop();
		}
		cout << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	vovan<char> v;
	v.vovka();
	system("pause");
	return 0;
}

