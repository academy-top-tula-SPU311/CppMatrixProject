#include <iostream>

// create array
template <typename T>
T* ArrayCreate(int size);

// init array
template <typename T>
void ArrayInit(T* array, int size, T begin, T end);

// print array
template <typename T>
void ArrayPrint(T* array, int size);

// free array
template <typename T>
void ArrayDelete(T* array);

void PointerToPointerExample();


int main()
{
    int rows{ 5 };
    int columns{ 7 };

    /*
    int** matrix{new int* [rows]};
    for (int i{}; i < rows; i++)
        matrix[i] = new int[columns] {};

    for (int i{}; i < rows; i++)
        for (int j{}; j < columns; j++)
            matrix[i][j] = (i + 1) * 10 + (j + 1);

    for (int i{}; i < rows; i++)
    {
        for (int j{}; j < columns; j++)
            std::cout << matrix[i][j] << "\t";
        std::cout << "\n";
    }

    for (int i{}; i < rows; i++)
        delete[] matrix[i];
    delete[] matrix;
    */



    srand(time(nullptr));
    int* sizes = new int[rows];

    int** jagged = new int*[rows];
    for (int i{}; i < rows; i++)
    {
        //sizes[i] = 5 + rand() % 6;
        int size = 5 + rand() % 6;
        jagged[i] = new int[size + 1] {};
        jagged[i][0] = size;
    }
        
    for (int i{}; i < rows; i++)
    {
        for (int j{ 1 }; j < jagged[i][0] + 1; j++)
            std::cout << jagged[i][j] << "\t";
        std::cout << "\n";
    }


}

template <typename T>
T* ArrayCreate(int size)
{
    return new T[size];
}

template<typename T>
void ArrayInit(T* array, int size, T begin, T end)
{
    srand(time(nullptr));

    for (int i{}; i < size; i++)
        array[i] = begin + rand() % (end - begin + 1);
}

template<typename T>
void ArrayPrint(T* array, int size)
{
    for (int i{}; i < size; i++)
        std::cout << array[i] << " ";
    std::cout << "\n";
}

template<typename T>
void ArrayDelete(T* array)
{
    delete[] array;
}

void PointerToPointerExample()
{
    /*int* ptr = new int[5] {};
    ArrayPrint(ptr, 5);*/

    int n{ 123 };
    int* ptr{ &n };
    int** pptr{ &ptr };

    std::cout << &n << " "
        << n << "\n";

    std::cout << &ptr << " "
        << ptr << " "
        << *ptr << "\n";

    std::cout << &pptr << " "
        << pptr << " "
        << *pptr << " "
        << **pptr << "\n";
}
