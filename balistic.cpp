#include "stdafx.h"
#include "balistic.h"


Balistic::Balistic()
{
	menu();
}
void Balistic::one()
{
	
	cout << "Сколько будет выстрелов?\nОтвет: ";
	//shooting = 14;
	//shooting = 5;
	cin >> shooting;
	cout << "\n\nВведите растояние в метрах к каждой точки :\n";

	distance = new int[shooting];
	for (int i = 0, num = 1; i < shooting; i++, num++)
	{
		cout << num << "- ";
		cin >> distance[i];
		//distance[i] = arraY[i];
		//distance[i] = arraY2[i];
	}
}
void Balistic::two()
{
	system("cls");
	cout << "\tОтстрел и его порядковый номер\n\nКакой отстрел попал под сомнение?\nНапишите его индефикатор\n\n";

	for (int i = 0; i < shooting; i++)
		cout << i << "- Порядковый номер   " << distance[i] << "- Пролетел метров\n";

	while (true)
	{
		cout << "Ответ: ";
		cin >> DELET;
		if (0 <= DELET)
			if (DELET <= shooting - 1)
				break;
	}

	cache = distance[DELET];
	shooting_2 = shooting;
	distance_2 = new int[shooting_2];

	for (int i = 0; i < shooting_2; i++)
		distance_2[i] = distance[i];
}
void Balistic::tree()
{
	system("cls");

	shooting_2--;
	for (int i = DELET, j = DELET + 1; i < shooting_2; i++, j++)
	{
		if (DELET == shooting_2)
			break;

		distance_2[i] = distance[j];
		/*if (j == shooting_2)
		break;*/
	}
	cout << endl;

	for (int i = 0; i < shooting_2; i++)
		cout << i << "- Порядковый номер   " << distance_2[i] << "- Пролетел метров\n";

	cout << "\nПод сомнения попал снаряд пролетевший: " << cache << "m\n\n";
}
void Balistic::metod_Smirnova()
{
	system("cls");

	for (int i = 0; i < shooting_2; i++)
	{
		sum += distance_2[i];
	}
	sum = sum / shooting_2;

	cout <<"сумма: "<< sum << endl;
	//Bg = E * sqrt(pow((shooting_range - sum), 2) / shooting_2);

	for (int i = 0; i < shooting_2; i++)
		sum_2 += pow((distance_2[i] - sum), 2);
		
	shooting_2--;
	Bg = E * sqrt(sum_2 / shooting_2);

	if (sum < cache)
		Tn = (cache - sum) / Bg;
	else if(sum > cache)
		Tn = (sum - cache) / Bg;

	cout << "Bg :" << Bg << "\nTn :" << Tn << "\n\n\n";


	for (int i = 0; i < 24; i++)
	{
		if (sd[0][i] == shooting)
		{
			line = i;
			break;
		}
	}

	for (int i = 1; i < 5; i++)
	{
		if (Tn > sd[i][line])
		{
			B1 = sd[i][line];
			P2 = sd[i][0];

			B2 = sd[i + 1][line];
			P1 = sd[i + 1][0];
			break;
		}
	}

	B = Tn;

	float yl;
	cout << "B: " << B << " B1: " << B1 << " B2: " << B2 << endl;
	cout << "P: ?" << " P1: " << P1 << " P2: " << P2 << "\n\n";
	
	yl = P2 - P1;
	cout << "\tyl = P2 - P1\nyl = " << yl << "\n\n\tP = (P1*(B - B1)) / (B2 - B1) + yl\n";

	P = (P1*(B - B1)) / (B2 - B1) + yl;

	cout << "P = " << P << endl;

	P = P * 100;
	alpha = P*2;
	cout << "\n\talpha = P * 2\nalpha : " << alpha << endl;

	malfunction = (1 - M) * 100;

	if (malfunction > alpha)
		cout <<"\n\tБрак\n";
	if (malfunction < alpha)
		cout << "\n\tНе брак\n";

}
void Balistic::menu()
{
	string b = "t";
	while (true)
	{
		one();
		two();
		tree();
		metod_Smirnova();
		
		//while (true)
		
			cout << "\n\n\tПровести вычисления заново? (yes/no)\nОтвет: ";
			cin >> b;
		

		if (b == "no" || b == "No" || b == "NO")
			break;
		else if (b == "yes" || b == "Yes" || b == "YES")
			cout << endl;
		else
			cout << "Вы сделали что-то не так!\n";
		system("cls");

		sum = 0;
		sum_2 = 0;
	}
}

Balistic::~Balistic()
{
	delete [] distance;
	distance = nullptr;

	delete[] distance_2;
	distance_2 = nullptr;
}
