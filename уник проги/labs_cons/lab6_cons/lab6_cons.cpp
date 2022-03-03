

#include <iostream>


int main()
{
    using namespace std;
    setlocale(LC_ALL, "rus");
    int N, M, a;
    cout << "Введите размеры матрицы: \nN = ";
    cin >> N;
    cout << "\nM = ";
    cin >> M;
    int* arr_new = new int[7]{1, 2, 3, 4, 5, 9, 7};
    
    int* vec = new int[N];
    int **arr = new int* [N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = new int[M];
    }
    cout << "Вводите элементы массива: ";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }
   arr[0][0] = 1;
    arr[0][1] = 2;
    arr[1][0] = 3;
    arr[1][1] = 4;
    
    arr[0] = arr[1];
    /*arr[0][0] = 10;
    arr[1][0] = 20;
    arr[0][1] = 10;*/


    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << arr[i][j]<<" ";
        }
        cout << endl;
    }
    for (int i = 0;  i < N; i++)
    {
        for (int j = 0; j < M-1; j++)
        {
            a = 0;
            if (arr[i][j] < arr[i][j + 1] || arr[i][j] == arr[i][j + 1])
            {
                vec[i] = 0;
                break;
            }
            else { vec[i] = 1; }
        }
        
    }
    cout << "\n\n";
    for (int i = 0; i < N; i++)
    {
        cout << vec[i]<<" ";
    }
    delete[]arr;
    
}

