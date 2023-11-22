#include <iostream>
#include <vector>

using namespace std;

class Heap {
private:
    vector<int> heapArray;
    int heapSize;

    void maxHeapify(int i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < heapSize && heapArray[left] > heapArray[largest]) {
            largest = left;
        }

        if (right < heapSize && heapArray[right] > heapArray[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(heapArray[i], heapArray[largest]);
            maxHeapify(largest);
        }
    }

public:
    Heap(vector<int>& array) : heapArray(array), heapSize(array.size()) {}

    void buildMaxHeap() {
        for (int i = heapSize / 2 - 1; i >= 0; --i) {
            maxHeapify(i);
        }
    }

    void heapSort() {
        buildMaxHeap();
        for (int i = heapSize - 1; i > 0; --i) {
            swap(heapArray[0], heapArray[i]);
            heapSize--;
            maxHeapify(0);
        }
    }

    void displayHeap() {
        cout << "Heap elements: ";
        for (int i = 0; i < heapArray.size(); ++i) {
            cout << heapArray[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    vector<int> arr;
    int size;
    int i = 0;
    cout<<"Enter size: ";
    cin>>size;
    while(i<size){
        int temp;
        cin>>temp;
        arr.push_back(temp);
        i++;
    }
    Heap maxHeap(arr);

    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    maxHeap.heapSort();

    cout << "Sorted array: ";
    maxHeap.displayHeap();

    return 0;
}
