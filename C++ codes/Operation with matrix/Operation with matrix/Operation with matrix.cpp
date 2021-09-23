#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;

//Создаёт двумерную матрицу
int** CreateMatrix(int sizeN, int sizeM);

//Выводит матрицу в файл
void PrintMatrixInFile(int** matrix, int sizeN, int sizeM);

//Выводит матрицу на консоль
void PrintMatrixOnConsole(int** matrix, int sizeN, int sizeM);

//Сортирует элементы каждого столбца матрицы по возрастанию
void SortColumnsOfMatrixInAscendingOrder(int** matrix, int sizeN, int sizeM);

//Сортирует диагонали расположенные выше главной по возрастанию
void SortDiagonalsOfMatrixAboveMainOneInAscendingOrder(int** matrix, int sizeN);

//Сортирует диагонали расположенные ниже главной по убыванию
void SortDiagonalsOfMatrixBelowMainOneInDescendingOrder(int** matrix, int sizeN);

//Сортирует элементы на главной диагонали по возрастанию
void SortElementsOfTheMainDiagonalInAscendingOrder(int** matrix, int sizeN);

//Сортирует элементы на побочной диагонали по возрастанию
void SortElementsOfTheSecondaryDiagonalInAscendingOrder(int** matrix, int sizeN);

//Сортирует все элементы матрицы по возрастанию
void SortMatrixInAscendingOrder(int** matrix, int sizeN, int sizeM);

//Сортирует элементы каждой строки матрицы по возрастанию
void SortRowsOfMatrixInAscendingOrder(int** matrix, int sizeN, int sizeM);

//Меняет местами столбцы, чтобы их максимальные элементы образовывали убывающую последовательность
void SwapColumnsInDescendingOrderOfMaximum(int** matrix, int sizeN, int sizeM);

//Меняет местами столбцы, содержащие минимальный и максимальный элементы матрицы
void SwapColumnsWithMinimumAndMaximum(int** matrix, int sizeN, int sizeM);

//Меняет местами строки так, чтобы их максимальные элементы образовывали возрастающую последовательность
void SwapRowsInAscendingOrderOfMaximum(int** matrix, int sizeN, int sizeM);

int main()
{
    int input = -1; //Вводимая цифра с клавиатуры для передачи в switch
    int sizeN; //Колличество строк в матрице
    int sizeM; //Колличество столбцов в матрице

    srand(time(0));

    cout << "Enter the number of rows (sizeN): ";
    cin >> sizeN;
    if (sizeN < 1)
    {
        cout << "You entered the value for \"sizeN\" incorrectly!";
        return -1;
    }

    cout << "Enter the number of columns (sizeM): ";
    cin >> sizeM;
    if (sizeM < 1)
    {
        cout << "You entered the value for \"sizeM\" incorrectly!";
        return -1;
    }

    //Указатель на указатель на int
    //Матрица
    int** matrix = CreateMatrix(sizeN, sizeM);

    PrintMatrixOnConsole(matrix, sizeN, sizeM); //Выводим сгенерированную матрицу на консоль

    cout << "\nList of possible operations on the matrix:\n";
    cout << "1 - Sort all the elements of the matrix in ascending order\n";
    cout << "2 - Sort elements of each column of the matrix in ascending order\n";
    cout << "3 - Sort elements of each row of the matrix in ascending order\n";
    cout << "4 - Sort elements of the main diagonal in ascending order\n";
    cout << "5 - Sort elements of the secondary diagonal in ascending order\n";
    cout << "6 - Sort the diagonals of the matrix located above the main one in ascending order\n";
    cout << "7 - Sort the diagonals of the matrix below the main one in descending order\n";
    cout << "8 - Swap columns so that their maximum elements make a descending sequence\n";
    cout << "9 - Swap rows so that their maximum elements make an increasing sequence\n";
    cout << "10 - Swap columns containing the minimum and maximum matrix elements\n";

    cout << "\nEnter the number of the required operation with the matrix: ";
    cin >> input;

    switch (input)
    {
    case 1:
    {
        SortMatrixInAscendingOrder(matrix, sizeN, sizeM);
        PrintMatrixOnConsole(matrix, sizeN, sizeM);

        cout << "\nDo you want to write the result to the file?\n1 - Yes\n2 - No";

        int entry = -1; //Вводимая цифра с клавиатуры для передачи в switch
        cout << "\nYour input = ";
        cin >> entry;

        switch (entry)
        {
        case 1:
        {
            PrintMatrixInFile(matrix, sizeN, sizeM);
            cout << "\nWriting to the file was successful!\n";
            break;
        }
        case 2:
        {
            cout << "\nOkey. Thank you for using my program :)\n";
            break;
        }
        default:
        {
            cout << "\nYou entered the wrong number!\n";
            break;;
        }
        }

        break;
    }
    case 2:
    {
        SortColumnsOfMatrixInAscendingOrder(matrix, sizeN, sizeM);
        PrintMatrixOnConsole(matrix, sizeN, sizeM);

        cout << "\nDo you want to write the result to the file?\n1 - Yes\n2 - No";

        int entry = -1; //Вводимая цифра с клавиатуры для передачи в switch
        cout << "\nYour input = ";
        cin >> entry;

        switch (entry)
        {
        case 1:
        {
            PrintMatrixInFile(matrix, sizeN, sizeM);
            cout << "\nWriting to the file was successful!\n";
            break;
        }
        case 2:
        {
            cout << "\nOkey. Thank you for using my program :)\n";
            break;
        }
        default:
        {
            cout << "\nYou entered the wrong number!\n";
            break;;
        }
        }

        break;
    }
    case 3:
    {
        SortRowsOfMatrixInAscendingOrder(matrix, sizeN, sizeM);
        PrintMatrixOnConsole(matrix, sizeN, sizeM);

        cout << "\nDo you want to write the result to the file?\n1 - Yes\n2 - No";

        int entry = -1; //Вводимая цифра с клавиатуры для передачи в switch
        cout << "\nYour input = ";
        cin >> entry;

        switch (entry)
        {
        case 1:
        {
            PrintMatrixInFile(matrix, sizeN, sizeM);
            cout << "\nWriting to the file was successful!\n";
            break;
        }
        case 2:
        {
            cout << "\nOkey. Thank you for using my program :)\n";
            break;
        }
        default:
        {
            cout << "\nYou entered the wrong number!\n";
            break;;
        }
        }

        break;
    }
    case 4:
    {
        if (sizeN != sizeM)
        {
            cout << "\nYour matrix is not square!";
            break;
        }

        SortElementsOfTheMainDiagonalInAscendingOrder(matrix, sizeN);
        PrintMatrixOnConsole(matrix, sizeN, sizeM);

        cout << "\nDo you want to write the result to the file?\n1 - Yes\n2 - No";

        int entry = -1; //Вводимая цифра с клавиатуры для передачи в switch
        cout << "\nYour input = ";
        cin >> entry;

        switch (entry)
        {
        case 1:
        {
            PrintMatrixInFile(matrix, sizeN, sizeM);
            cout << "\nWriting to the file was successful!\n";
            break;
        }
        case 2:
        {
            cout << "\nOkey. Thank you for using my program :)\n";
            break;
        }
        default:
        {
            cout << "\nYou entered the wrong number!\n";
            break;;
        }
        }

        break;
    }
    case 5:
    {
        if (sizeN != sizeM)
        {
            cout << "\nYour matrix is not square!";
            break;
        }

        SortElementsOfTheSecondaryDiagonalInAscendingOrder(matrix, sizeN);
        PrintMatrixOnConsole(matrix, sizeN, sizeM);

        cout << "\nDo you want to write the result to the file?\n1 - Yes\n2 - No";

        int entry = -1; //Вводимая цифра с клавиатуры для передачи в switch
        cout << "\nYour input = ";
        cin >> entry;

        switch (entry)
        {
        case 1:
        {
            PrintMatrixInFile(matrix, sizeN, sizeM);
            cout << "\nWriting to the file was successful!\n";
            break;
        }
        case 2:
        {
            cout << "\nOkey. Thank you for using my program :)\n";
            break;
        }
        default:
        {
            cout << "\nYou entered the wrong number!\n";
            break;;
        }
        }

        break;
    }
    case 6:
    {
        if (sizeN != sizeM)
        {
            cout << "\nYour matrix is not square!";
            break;
        }

        SortDiagonalsOfMatrixAboveMainOneInAscendingOrder(matrix, sizeN);
        PrintMatrixOnConsole(matrix, sizeN, sizeM);

        cout << "\nDo you want to write the result to the file?\n1 - Yes\n2 - No";

        int entry = -1; //Вводимая цифра с клавиатуры для передачи в switch
        cout << "\nYour input = ";
        cin >> entry;

        switch (entry)
        {
        case 1:
        {
            PrintMatrixInFile(matrix, sizeN, sizeM);
            cout << "\nWriting to the file was successful!\n";
            break;
        }
        case 2:
        {
            cout << "\nOkey. Thank you for using my program :)\n";
            break;
        }
        default:
        {
            cout << "\nYou entered the wrong number!\n";
            break;;
        }
        }

        break;
    }
    case 7:
    {
        if (sizeN != sizeM)
        {
            cout << "\nYour matrix is not square!";
            break;
        }

        SortDiagonalsOfMatrixBelowMainOneInDescendingOrder(matrix, sizeN);
        PrintMatrixOnConsole(matrix, sizeN, sizeM);

        cout << "\nDo you want to write the result to the file?\n1 - Yes\n2 - No";

        int entry = -1; //Вводимая цифра с клавиатуры для передачи в switch
        cout << "\nYour input = ";
        cin >> entry;

        switch (entry)
        {
        case 1:
        {
            PrintMatrixInFile(matrix, sizeN, sizeM);
            cout << "\nWriting to the file was successful!\n";
            break;
        }
        case 2:
        {
            cout << "\nOkey. Thank you for using my program :)\n";
            break;
        }
        default:
        {
            cout << "\nYou entered the wrong number!\n";
            break;;
        }
        }

        break;
    }
    case 8:
    {
        SwapColumnsInDescendingOrderOfMaximum(matrix, sizeN, sizeM);
        PrintMatrixOnConsole(matrix, sizeN, sizeM);

        cout << "\nDo you want to write the result to the file?\n1 - Yes\n2 - No";

        int entry = -1; //Вводимая цифра с клавиатуры для передачи в switch
        cout << "\nYour input = ";
        cin >> entry;

        switch (entry)
        {
        case 1:
        {
            PrintMatrixInFile(matrix, sizeN, sizeM);
            cout << "\nWriting to the file was successful!\n";
            break;
        }
        case 2:
        {
            cout << "\nOkey. Thank you for using my program :)\n";
            break;
        }
        default:
        {
            cout << "\nYou entered the wrong number!\n";
            break;;
        }
        }

        break;
    }
    case 9:
    {
        SwapRowsInAscendingOrderOfMaximum(matrix, sizeN, sizeM);
        PrintMatrixOnConsole(matrix, sizeN, sizeM);

        cout << "\nDo you want to write the result to the file?\n1 - Yes\n2 - No";

        int entry = -1; //Вводимая цифра с клавиатуры для передачи в switch
        cout << "\nYour input = ";
        cin >> entry;

        switch (entry)
        {
        case 1:
        {
            PrintMatrixInFile(matrix, sizeN, sizeM);
            cout << "\nWriting to the file was successful!\n";
            break;
        }
        case 2:
        {
            cout << "\nOkey. Thank you for using my program :)\n";
            break;
        }
        default:
        {
            cout << "\nYou entered the wrong number!\n";
            break;;
        }
        }

        break;
    }
    case 10:
    {
        SwapColumnsWithMinimumAndMaximum(matrix, sizeN, sizeM);
        PrintMatrixOnConsole(matrix, sizeN, sizeM);

        cout << "\nDo you want to write the result to the file?\n1 - Yes\n2 - No";

        int entry = -1; //Вводимая цифра с клавиатуры для передачи в switch
        cout << "\nYour input = ";
        cin >> entry;

        switch (entry)
        {
        case 1:
        {
            PrintMatrixInFile(matrix, sizeN, sizeM);
            cout << "\nWriting to the file was successful!\n";
            break;
        }
        case 2:
        {
            cout << "\nOkey. Thank you for using my program :)\n";
            break;
        }
        default:
        {
            cout << "\nYou entered the wrong number!\n";
            break;;
        }
        }

        break;
    }
    default:
    {
        cout << "\nThe selected number is not in the list of suggestions!";
        break;
    }
    }

    return 0;
}

int** CreateMatrix(int sizeN, int sizeM)
{
    //Переменная типа "указатель на указатель на int"
   //Выделяется память под массив указателей на строки матрицы
    int** matrix = new int* [sizeN];

    //Цикл выделяет память под каждую строку массива
    for (int i = 0; i < sizeN; i++)
    {
        matrix[i] = new int[sizeM]; //Каждому элементу массива указателей на строке присваевается адресс начала участка памяти
    }

    for (int i = 0; i < sizeN; i++)
    {
        for (int j = 0; j < sizeM; j++)
        {
            matrix[i][j] = -50 + rand() % 100; //В каждый элемент матрицы записываем случайное число в диапазоне от -50 до 50;
        }
    }

    return matrix;
}

void PrintMatrixInFile(int** matrix, int sizeN, int sizeM)
{
    //В качестве параметра можно передать другое название файла, как и расширение файла.
    //Также, можно указать полный путь, а не просто название конечного желаемого файла
    ofstream out("output.txt");//Объект класса ofstream для записи

    out << "The matrix:\n"; //Делаем небольшой заголовок
    for (int i = 0; i < sizeN; i++)
    {
        for (int j = 0; j < sizeM; j++)
        {
            out << matrix[i][j] << '\t'; //Выводим каждый элемент в виде матрицы
        }
        out << endl;
    }

    out.close(); //Закрываем файл
}

void PrintMatrixOnConsole(int** matrix, int sizeN, int sizeM)
{
    cout << "\nThe matrix:\n"; //Делаем небольшой заголовок
    for (int i = 0; i < sizeN; i++)
    {
        for (int j = 0; j < sizeM; j++)
        {
            cout << matrix[i][j] << '\t'; //Выводим каждый элемент в виде матрицы
        }
        cout << endl;
    }
}

void SortColumnsOfMatrixInAscendingOrder(int** matrix, int sizeN, int sizeM)
{
    for (int i = 0; i < sizeM; i++) //Внешний цикл по столбцам
    {
        //Второй цикл, который останавливается на текущем элементе и сравнивает его с последующими элементами
        for (int j = 0; j < sizeN; j++)
        {
            //Третий цикл пробегает по всем оставшимся элементам столбца и сравнивает с тем, на котором остановился предыдущий цикл
            for (int k = 0; k < sizeN; k++)
            {
                if (matrix[j][i] < matrix[k][i])
                {
                    swap(matrix[k][i], matrix[j][i]);
                }
            }
        }
    }
}

void SortDiagonalsOfMatrixAboveMainOneInAscendingOrder(int** matrix, int sizeN)
{
    int temp; //Временная переменная для хранения индекса

    for (int i = 1; i < sizeN - 1; i++)
    {
        for (int j = 0; j < sizeN && j + i < sizeN; j++)
        {
            temp = j;
            for (int k = j + 1; k < sizeN && k + i < sizeN; k++)
            {
                if (matrix[temp][i + temp] > matrix[k][k + i])
                {
                    temp = k;
                }
            }

            swap(matrix[j][i + j], matrix[temp][i + temp]);
        }
    }
}

void SortDiagonalsOfMatrixBelowMainOneInDescendingOrder(int** matrix, int sizeN)
{
    int temp; //Временная переменная для хранения индекса

    for (int i = 1; i < sizeN - 1; i++)
    {
        for (int j = 0; j < sizeN && j + i < sizeN; j++)
        {
            temp = j;
            for (int k = j + 1; k < sizeN && k + i < sizeN; k++)
            {
                if (matrix[temp + i][temp] < matrix[k + i][k])
                {
                    temp = k;
                }
            }

            swap(matrix[j + i][j], matrix[temp + i][temp]);
        }
    }
}

void SortElementsOfTheMainDiagonalInAscendingOrder(int** matrix, int sizeN)
{
    for (int i = 0; i < sizeN; i++)
    {
        for (int j = i + 1; j < sizeN; j++)
        {
            if (matrix[i][i] > matrix[j][j])
            {
                swap(matrix[i][i], matrix[j][j]);
            }
        }
    }
}

void SortElementsOfTheSecondaryDiagonalInAscendingOrder(int** matrix, int sizeN)
{
    for (int i = 0; i < sizeN - 1; i++)
    {
        for (int j = i + 1; j < sizeN; j++)
        {
            if (matrix[j][sizeN - 1 - j] < matrix[i][sizeN - 1 - i])
            {
                swap(matrix[j][sizeN - 1 - j], matrix[i][sizeN - 1 - i]);
            }
        }
    }
}

void SortMatrixInAscendingOrder(int** matrix, int sizeN, int sizeM)
{
    for (int k = 0; k < sizeN; k++)
    {
        for (int l = 0; l < sizeM; l++)
        {
            for (int i = 0; i < sizeN; i++)
            {
                for (int j = 0; j < sizeM; j++)
                {
                    //Проверка на выход за границу массива и, соответсвенно, сравнение самих элементов
                    if ((j != sizeM - 1) && (matrix[i][j] > matrix[i][j + 1]))
                    {
                        swap(matrix[i][j], matrix[i][j + 1]);
                    }
                    else
                    {
                        //Если всё же прошлые условии не были пройдены, то снова проверяем, но уже по другим идексам
                        if ((i != sizeN - 1) && (matrix[i][j] > matrix[i + 1][0]))
                        {
                            swap(matrix[i][j], matrix[i + 1][0]);
                        }
                    }
                }
            }
        }
    }
}

void SortRowsOfMatrixInAscendingOrder(int** matrix, int sizeN, int sizeM)
{
    for (int i = 0; i < sizeN; i++)
    {
        for (int j = 0; j < sizeM; j++)
        {
            for (int k = 0; k < sizeM; k++)
            {
                if (matrix[i][j] < matrix[i][k])
                {
                    swap(matrix[i][j], matrix[i][k]);
                }
            }
        }
    }
}

void SwapColumnsInDescendingOrderOfMaximum(int** matrix, int sizeN, int sizeM)
{
    int* arrayOfMaximums = new int[sizeM]; //Массив из максимальных элементов каждого столбца
    int temp = -1; //Временная переменная для хранения номера строки/столбца

    for (int j = 0; j < sizeM; ++j)
    {
        arrayOfMaximums[j] = matrix[0][j]; //Записываем в созданный массив первый элемент столбца 

        for (int i = 1; i < sizeN; ++i)
        {
            //Если очередной элемент столбца больше уже записанного максимального 
            //(на первой итерации сравнивается с первым элементом столбца)
            if (matrix[i][j] > arrayOfMaximums[j])
            {
                arrayOfMaximums[j] = matrix[i][j]; //То перезаписываем такой найденный
            }
        }
    }

    for (int i = 0; i < sizeM; i++)
    {
        cout << "\nMaximum element in " << i + 1 << " column = " << arrayOfMaximums[i]; //Вывыдем максимальные элементы каждого столбца
    }
    cout << endl;

    for (int i = 0; i < sizeM; ++i)
    {
        temp = i; //Запоминаем номер текущего столбца
        for (int j = i + 1; j < sizeM; ++j)
        {
            //Если максимальный элемент следующего столбца (i + 1), больше предыдущего
            if (arrayOfMaximums[j] > arrayOfMaximums[temp])
            {
                temp = j; //Запоминаем номер этого "следующего" столбца
            }
        }

        //Если хоть раз максимальный элемент "следующего" столбца оказался больше предыдущего 
        //(хоть раз программа зашла внутрь предыдущего if'а и переменная temp изменилась)
        if (i != temp)
        {
            swap(arrayOfMaximums[i], arrayOfMaximums[temp]); //То меняем эти элементы в массиве максимумов
            for (int j = 0; j < sizeN; ++j)
            {
                swap(matrix[j][i], matrix[j][temp]); //И все элементы данных столбцов
            }
        }
    }
}

void SwapColumnsWithMinimumAndMaximum(int** matrix, int sizeN, int sizeM)
{
    int maxElement = INT32_MIN; //Максимальный элемент матрицы
    int minElement = INT32_MAX; //Минимальный элемент матрицы
    int numberOfColumnOfMaxElementMatrix = -1; //Номер колонки, в которой содержится максимальный элемент матрицы
    int numberOfColumnOfMinElementMatrix = -1; //Номер колонки, в которой содержится минимальный элемент матрицы

    //Поиск максимального и минимального значение и номеров соответствующих столбцов
    for (int i = 0; i < sizeN; i++)
    {
        for (int j = 0; j < sizeM; j++)
        {
            if (matrix[i][j] > maxElement) //Если очередной элемент больше максимального
            {
                maxElement = matrix[i][j]; //То перезаписываем
                numberOfColumnOfMaxElementMatrix = j; //И запоминаем номер этого столбца
            }

            if (matrix[i][j] < minElement) //Если очередной элемент меньше минимального
            {
                minElement = matrix[i][j]; //То перезаписываем
                numberOfColumnOfMinElementMatrix = j; //И запоминаем номер этого столбца
            }
        }
    }

    for (int i = 0; i < sizeN; i++)
    {
        swap(matrix[i][numberOfColumnOfMaxElementMatrix], matrix[i][numberOfColumnOfMinElementMatrix]);
    }

    //Выводим максимальный элемент и номер столбца
    cout << "\nThe maximum value " << maxElement << " is contained in the column " << numberOfColumnOfMaxElementMatrix + 1 << endl;

    //Выводим минимальный элемент и номер столбца
    cout << "The minimum value " << minElement << " is contained in the column " << numberOfColumnOfMinElementMatrix + 1 << endl;
}

void SwapRowsInAscendingOrderOfMaximum(int** matrix, int sizeN, int sizeM)
{
    int* arrayOfMaximums = new int[sizeN]; //Массив из максимальных элементов каждой строки

    for (int i = 0; i < sizeN; i++)
    {
        arrayOfMaximums[i] = matrix[i][0]; //Записываем в созданный массив первый элемент строки 

        for (int j = 0; j < sizeM; j++)
        {
            //Если очередной элемент строки больше уже записанного максимального 
            //(на первой итерации сравнивается с первым элементом строки)
            if (matrix[i][j] > arrayOfMaximums[i])
            {
                arrayOfMaximums[i] = matrix[i][j]; //То перезаписываем такой найденный
            }
        }
    }

    for (int i = 0; i < sizeN; i++)
    {
        cout << "\nMaximum element in " << i + 1 << " row = " << arrayOfMaximums[i]; //Вывыдем максимальные элементы каждой строки
    }
    cout << endl;

    //Производим перестановку элементов каждой строки, в соответствии с найденными максимальными элементами
    for (int i = 1; i < sizeN; i++)
    {
        for (int j = 0; j < sizeN - i; j++)
        {
            if (arrayOfMaximums[j] > arrayOfMaximums[j + 1]) //Если очередной элемент из максимальных больше чем последующий 
            {
                swap(arrayOfMaximums[j], arrayOfMaximums[j + 1]); //Меняем местами данные элементы
                swap(matrix[j], matrix[j + 1]); //И также меняем элементы матрицы с этими индексами
            }
        }
    }
}