//Сортировка подсчетом

#include <iostream>
#include <string>
#include <ctime>

using namespace std;
 
int main()
{
    srand(time(0));
    int N = 10000, max, min, L, k;
    int* A = new int[N];
    max = 0;
    min = 100;
    //cout << "Массив до сортировки:" << endl;
    
    for (int i = 0; i < N; i++)
    {
        A[i] = rand() % 11;
        if (A[i] > max)
            max = A[i];
        if (A[i] < min)
            min = A[i];
        
    }
    //for (int i = 0; i < N; i++)
    //{
    //    cout << A[i] << " ";
    //}
    //cout << endl;
    L = max - min + 1;
    int* C = new int[L];
    //старт
	clock_t start_time = clock();
    for (int i = 0; i < L; i++)
    {
        C[i] = 0;
    }
    for (int i = 0; i < N; i++)
    {
        C[A[i]-min]++;
    }
    k = 0;
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < C[i]; j++)
       {
           A[k++] = i + min;
       }
    }
    clock_t end_time = clock();
	double time_of_execution = double(end_time-start_time)/CLOCKS_PER_SEC;
	
    //cout << "Результат сортировки:" << endl;
    
    //for (int i = 0; i < N; i++)
    //{
    //    cout << A[i] << " ";
    //}
    //cout << endl;
    cout << "Время работы Сортировки подсчетом: " << time_of_execution <<  "сек" << endl;
    delete [] A;
    delete [] C;

    return 0;
}
