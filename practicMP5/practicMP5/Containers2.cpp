#include <queue>
#include <vector>
#include <algorithm>    
#include <iostream>
#include <Windows.h>
using namespace std;
struct let {
	int n;
	char s;
};

int main()
{
	setlocale(LC_ALL, "Russian");
	queue <let> q1;
	vector <let> v1, v;
	int i, k;
	cout << "¬ведите количество элементов, которые войдут в очередь "; cin >> k;
	vector <let> v2(k);
	for (i = 0; i <= k - 1; i++)   //заполнение очереди
	{
		let element; element.n = 2 * i + 1; element.s = (char)(-i);
		q1.push(element);
	}
	size_t size_q1 = q1.size();
	while (!q1.empty())  //работа с очередью
	{
		v.push_back(q1.front());
		q1.pop();
	}
	sort(v.begin(), v.end(), [](const let& a, const let& b)
	{
		return a.n > b.n; });
	cout << "ќчередь, отсортированна€ по убыванию = ( ";
	for_each(v.begin(), v.end(), [](const let& n) {
		cout << n.n << "." << n.s << " ";
	});
	cout << ")" << endl;
	while (!v.empty())
	{
		q1.push(v.front());
		v.erase(v.begin());
	}
	for (i = size_q1; i > 0; i--) {    // работа с вектором
		let element = q1.front(); q1.pop();
		if ((int)element.s < -5) v1.push_back(element); else
			q1.push(element);
	}
	sort(v1.begin(), v1.end(), [](const let& a, const let& b)
	{
		return a.n > b.n; });
	cout << "¬ектор v1, отсортированный по убыванию = ( ";
	for_each(v1.begin(), v1.end(), [](const let& n) {
		cout << n.n << "." << n.s << " ";
	});
	cout << ")" << endl;
	while (!q1.empty())  //снова работа с очередью: сортировка по возрастанию
	{
		v.push_back(q1.front());
		q1.pop();
	}
	sort(v.begin(), v.end(), [](const let& a, const let& b)
	{
		return a.n < b.n; });
	cout << "ќчередь, отсортированна€ по возрастанию = ( ";
	for_each(v.begin(), v.end(), [](const let& n) {
		cout << n.n << "." << n.s << " ";
	});
	cout << ")" << endl;
	while (!v.empty())
	{
		q1.push(v.front());
		v.erase(v.begin());
	}
	sort(v1.begin(), v1.end(), [](const let& a, const let& b) //сортировка вектора
	{
		return a.n < b.n; });
	cout << "¬ектор v1, отсортированный по возрастанию = ( ";
	for_each(v1.begin(), v1.end(), [](const let& n) {
		cout << n.n << "." << n.s << " ";
	});
	cout << ")" << endl;
	while (!q1.empty())  //снова работа с очередью
	{
		v.push_back(q1.front());
		q1.pop();
	}
	merge(v.begin(), v.end(), v1.begin(), v1.end(), v2.begin(), [](const let& a, const let& b)
	{
		return a.n < b.n; });
	cout << "Ќовый вектор, полученный после сли€ни€ = ( ";
	for_each(v2.begin(), v2.end(), [](const let& n) {
		cout << n.n << "." << n.s << " ";
	});
	cout << ")" << endl;
	vector<let>::iterator::difference_type result;
	result = count_if(v2.begin(), v2.end(), [](const let& n) {
		return ((int)n.s < -5);
	});
	cout << " оличество символов, код которых меньше -5, равно " << result << endl;
	bool cash = any_of(v2.begin(), v2.end(), [](const let& n) {
		return ((int)n.s < -8);
	});
	if (cash) cout << "¬ векторе находитс€ символ с кодом меньше, чем -8" << endl;
	else cout << "¬ векторе нет символа с кодом меньше -8" << endl;
	system("pause");
}