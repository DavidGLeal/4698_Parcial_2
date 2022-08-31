#include "Proceso.h"

Proceso::Proceso(/* args */)
{
}

Proceso::~Proceso()
{
}

int Proceso::Dato_Max(int arr[], int index, int l)
{
    int max;
    if (index >= l - 2)
    {
        if (arr[index] > arr[index + 1])
            return arr[index];
        else
            return arr[index + 1];
    }
    max = Dato_Max(arr, index + 1, l);
    if (arr[index] > max)
        return arr[index];
    else
        return max;
}

// Function to find the minimum no.
// in a given array
int Proceso::Dato_Min(int arr[], int index, int l)
{
    int min;
    if (index >= l - 2)
    {
        if (arr[index] < arr[index + 1])
            return arr[index];
        else
            return arr[index + 1];
    }

    min = Dato_Min(arr, index + 1, l);
    if (arr[index] < min)
        return arr[index];
    else
        return min;
}