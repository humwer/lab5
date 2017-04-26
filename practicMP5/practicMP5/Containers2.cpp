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
	cout << "������� ���������� ���������, ������� ������ � ������� "; cin >> k;
	vector <let> v2(k);
	for (i = 0; i <= k - 1; i++)   //���������� �������
	{
		let element; element.n = 2 * i + 1; element.s = (char)(-i);
		q1.push(element);
	}
	size_t size_q1 = q1.size();
	while (!q1.empty())  //������ � ��������
	{
		v.push_back(q1.front());
		q1.pop();
	}
	sort(v.begin(), v.end(), [](const let& a, const let& b)
	{
		return a.n > b.n; });
	cout << "�������, ��������������� �� �������� = ( ";
	for_each(v.begin(), v.end(), [](const let& n) {
		cout << n.n << "." << n.s << " ";
	});
	cout << ")" << endl;
	while (!v.empty())
	{
		q1.push(v.front());
		v.erase(v.begin());
	}
	for (i = size_q1; i > 0; i--) {    // ������ � ��������
		let element = q1.front(); q1.pop();
		if ((int)element.s < -5) v1.push_back(element); else
			q1.push(element);
	}
	sort(v1.begin(), v1.end(), [](const let& a, const let& b)
	{
		return a.n > b.n; });
	cout << "������ v1, ��������������� �� �������� = ( ";
	for_each(v1.begin(), v1.end(), [](const let& n) {
		cout << n.n << "." << n.s << " ";
	});
	cout << ")" << endl;
	while (!q1.empty())  //����� ������ � ��������: ���������� �� �����������
	{
		v.push_back(q1.front());
		q1.pop();
	}
	sort(v.begin(), v.end(), [](const let& a, const let& b)
	{
		return a.n < b.n; });
	cout << "�������, ��������������� �� ����������� = ( ";
	for_each(v.begin(), v.end(), [](const let& n) {
		cout << n.n << "." << n.s << " ";
	});
	cout << ")" << endl;
	while (!v.empty())
	{
		q1.push(v.front());
		v.erase(v.begin());
	}
	sort(v1.begin(), v1.end(), [](const let& a, const let& b) //���������� �������
	{
		return a.n < b.n; });
	cout << "������ v1, ��������������� �� ����������� = ( ";
	for_each(v1.begin(), v1.end(), [](const let& n) {
		cout << n.n << "." << n.s << " ";
	});
	cout << ")" << endl;
	while (!q1.empty())  //����� ������ � ��������
	{
		v.push_back(q1.front());
		q1.pop();
	}
	merge(v.begin(), v.end(), v1.begin(), v1.end(), v2.begin(), [](const let& a, const let& b)
	{
		return a.n < b.n; });
	cout << "����� ������, ���������� ����� ������� = ( ";
	for_each(v2.begin(), v2.end(), [](const let& n) {
		cout << n.n << "." << n.s << " ";
	});
	cout << ")" << endl;
	vector<let>::iterator::difference_type result;
	result = count_if(v2.begin(), v2.end(), [](const let& n) {
		return ((int)n.s < -5);
	});
	cout << "���������� ��������, ��� ������� ������ -5, ����� " << result << endl;
	bool cash = any_of(v2.begin(), v2.end(), [](const let& n) {
		return ((int)n.s < -8);
	});
	if (cash) cout << "� ������� ��������� ������ � ����� ������, ��� -8" << endl;
	else cout << "� ������� ��� ������� � ����� ������ -8" << endl;
	system("pause");
}