#include<stdio.h>
#include <locale.h>
#include<iostream>
#include <math.h>
#include <time.h>
#include <stdint.h>
#include <string.h>
#include<stdlib.h>
#include"Header.h"


using namespace std;



int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	int n;

	do
	{
		printf("¬ведите номер задани€: ");
		scanf("%d", &n);
		cin.get();
		switch (n) {
			/*2.	—формировать массив структур, каждый элемент которого содержит следующие три пол€:
a.	фамили€, им€ отчество студента (вводим);
b.	массив оценок в дес€тибалльной системе (вводим);
c.	признак

ƒл€ каждого студента получить одно из следующих значений признака: 5 Ц отличник (только 9 и (или) 10), 4 Ц хорошист
(нет оценок, меньше 6, но не все 9 или 10, а есть 6 и (или) 7 и (или) 8), 3 Ц троечник (нет оценок, меньше 4, но есть 4 и (или) 5),
2 Ц неуспевающий (есть 1 и (или) 2 и (или) 3). –ассортировать массив структур по убыванию полученного признака.
*/
		case 1: {
			int count = 1 + rand() % 5;
			printf("Count of students: %d\n", count);
			
			Group *students = (Group*)malloc(sizeof(Group));

			if (students != NULL)
			{
				for (int i = 0;i < count;i++)
				{
					printf("Enter name: ");
					students->name = (char*)malloc(50 * sizeof(char));
					fgets(students->name, 50, stdin);
					cin.get();

					int k = (1 + rand() % 10);
					(students + i)->ses = (int*)calloc(k, sizeof(int));
					int sum = 0;
					for (int j = 0; j < k; j++)
					{
						(students + i)->ses[j] = 2 + rand() % 8;
						printf("--> %d\n", (students + i)->ses[j]);
						sum += (students + i)->ses[j];
					}

					double sr = sum / k;
					printf("Average ses:%d - %2.2lf\n", i + 1, sr);

					if (sr >= 9 && sr <= 10)
						printf(" %d - A student\n ", i + 1);
					else if (sr >= 7 && sr < 9)
						printf(" %d -B student\n ", i + 1);
					else if (sr >= 4 && sr < 7)
						printf(" %d -C student\n", i + 1);
					else
						printf(" %d -D student\n", i + 1);
				}

				/*printf("after sort: \n");
				for (int i = 0;i < count;i++)
				{
					sort_student((students + i)->sr, count);
					for (int j = 0; j < count; j++)
					{
						if ((students + i)->sr[j] >= 9 && (students + i)->sr[j] <= 10)
							printf(" %s - A student\n ", (students + i)->name);
						else if ((students + i)->sr[j] >= 7 && (students + i)->sr[j] < 9)
							printf(" %s -B student\n ", (students + i)->name);
						else if ((students + i)->sr[j] >= 4 && (students + i)->sr[j] < 7)
							printf(" %s -C student\n", (students + i)->name);
						else
							printf(" %s -D student\n", (students + i)->name);
					}
				}*/
			}
			
		}break;
			/*4.	»нформаци€ по N заводам города задаетс€ строкой следующего вида: фамили€, средний возраст,
			специальность, средний оклад. ¬вести информацию по заводам, посчитать количество слесарей и токарей.
			Ќапечатать эти значени€.*/
		case 2: {
			int c_zavod = 1 + rand() % 3;
			printf("кол-во зыводов: %d\n", c_zavod);
			zavod *zav = NULL;
			
			for (int k = 0;k < c_zavod;k++)
			{
				int l, l1;
				(zav + k)->name = (char*)malloc(sizeof(char));
				printf("¬ведите название:");
				fgets((zav + k)->name, 50, stdin);
				cin.get();

				int count = 1 + rand() % 5;
				printf("кол-во сотрудников: %d\n", count);

				worker *workers = NULL;
				workers = (worker*)malloc(count * sizeof(worker));

				if (workers != NULL)
				{
					int sum = 0,sum1=0;
					for (int i = 0;i < count; i++)
					{
						(workers + i)->name = (char*)malloc(12 * sizeof(char));
						generateName((workers + i)->name);

						(workers + i)->age = (int)malloc(12 * sizeof(int));
						(workers + i)->age = 25 + rand() % 25;
						sum1 += (workers + i)->age;

						(workers + i)->prof = (char*)malloc(sizeof(char));
						printf("¬ведите профессию:");
						fgets((workers + i)->prof, 50, stdin);
						cin.get();
						if ((workers + i)->prof == "slesar")
							l++;
						else
							l1++;
						(workers + i)->sal = (int)malloc(sizeof(int));
						(workers + i)->sal = 1000 + rand() % 30000;
						sum += (workers + i)->sal;


						printf("# %d \t %s \t %d \t%s \t %d\n", i + 1, (workers + i)->name,
							(workers + i)->age, (workers + i)->prof, (workers + i)->sal);
					}
					(zav + k)->sr_sal = sum / count;
					(zav + k)->sr_age = sum1 / count;
				}

				printf("zavod %s \t sr_sal %d \t sr_age %d \t %d - %s \t %d - %s", (zav + k)->name, (zav + k)->sr_sal, (zav + k)->sr_age, l, workers->prof, l1, workers->prof);
			}
		}break;
		}
	} while (n > 0);
}