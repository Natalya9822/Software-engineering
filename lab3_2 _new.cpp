//Сортировка слиянием

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int n = 10000;

//функция для сливания массивов
void Merge(int *A, int first, int last) {
  int middle, start, end, j;
  int *mas = new int[n];
  middle = (first + last) / 2;  
  start = first;               
  end = middle + 1;           
  for (j = first; j <= last; j++)  
    if ((start <= middle) && ((end > last) || (A[start] < A[end]))) {
      mas[j] = A[start];
      start++;
    } else {
      mas[j] = A[end];
      end++;
    }
  //возвращение результата в список
  for (j = first; j <= last; j++)
    A[j] = mas[j];
  delete[] mas;
};
//рекурсивная процедура сортировки
void MergeSort(int *A, int first, int last) {
  if (first < last) {
    MergeSort(A, first, (first + last) / 2);  
    MergeSort(A, (first + last) / 2 + 1, last);  
    Merge(A, first, last);  //слияние двух частей
  }
}
//главная функция
int main() {

  int i;
  int *A = new int[n];
  //cout << "Массив до сортировки:" << endl;
    
   // for (i = 1; i <n; i++) {
   //     A[i] = rand() % 11;
  //      cout << A[i] << " ";
  //  }
  //cout << endl;
  
  //старт
	clock_t start_time = clock();
  MergeSort(A, 1, n);  //вызов сортирующей процедуры
  clock_t end_time = clock();
	double time_of_execution = double(end_time-start_time)/CLOCKS_PER_SEC;
	cout << "Время работы Сортировки слиянием: " << time_of_execution <<  "сек" << endl;
  //cout << "Массив после сортировки: ";  //вывод упорядоченного массива
  //for (i = 1; i <n; i++)
  //  cout << A[i] << " ";
  delete[] A;
 return(0);
}
