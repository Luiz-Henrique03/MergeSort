#include <iostream>
#include <vector>
#include <utility>

using namespace std;
void mergeSort(int* a,int length);
void merge(int* originalArray, const std::vector<int>& left, const std::vector<int>& right);


int main()
{
    int ara[] = {8,81,45,63,23,10,21,31,46};
    mergeSort(ara,size(ara));

    for (int i = 0; i < size(ara); i++) {
        cout << ara[i] << endl;
    }
}

void mergeSort(int* a,int length)
{
    if (length <= 1) return;
    int middle = length / 2;
    int rightSize = length - middle;

    vector<int> leftArray(middle);
    vector<int> rightArray(rightSize);
    int j = 0;
    int i = 0;

    for (; i < length; i++) {
        if (i < middle) {
            leftArray[i] = a[i];
        }
        else {
            rightArray[j] = a[i];
            j++;
        }
    }
    mergeSort(leftArray.data(), size(leftArray));
    mergeSort(rightArray.data(), size(rightArray));
    merge(a, leftArray, rightArray);

}

void merge(int* originalArray, const std::vector<int>& left, const std::vector<int>& right)
{
    int i = 0;
    int j = 0;
    int k = 0; 


    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            originalArray[k] = left[i];
            i++;
        }
        else {
            originalArray[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left.size()) {
        originalArray[k] = left[i];
        i++;
        k++;
    }

    while (j < right.size()) {
        originalArray[k] = right[j];
        j++;
        k++;
    }
}