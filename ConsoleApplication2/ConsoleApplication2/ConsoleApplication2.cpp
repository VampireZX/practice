#include <iostream>

using namespace std;

//a * (a + 1) * (a + 2) * .. * (a + n)

	//Рекурсивная реализация

int recursion(const int& a, const int& n) 
{
	if (n < 0) return 1;
    return (n + a) * recursion(a, n - 1);
}

	//Нерекурсивная реализация

int nonRecursion(const int& a, const int& n)
{
	int res = 1;
	for (int i = 0; i <= n; i++)
		res *= a + i;

	return res;
}

//функция Аккермана

int A(const int& m, const int& n)
{
	if (m == 0)
		return n + 1;
	else 
		if (n == 0 && m != 0)
			return A(m - 1, 1);
		else
			return A(m - 1, A(m, n - 1));
}

int main()
{
	int a, n1, n2, m, res1, res2, res3;
	cout << "Input a: ";
	cin >> a;
	cout << "Input n: ";
	cin >> n1;

	res1 = recursion(a, n1);
	res2 = nonRecursion(a, n1);
	cout << "Recursion method: " << res1 << endl;
	cout << "Non-Recursion method: " << res2 << endl;

	system("pause");
	system("cls");

	cout << "Input n for Ackerman Func(): ";
	cin >> n2;
	cout << "Input m for Ackerman Func(): ";
	cin >> m;

	res3 = A(m, n2);
	cout << "Result is " << res3 << endl;

	return 0;
}