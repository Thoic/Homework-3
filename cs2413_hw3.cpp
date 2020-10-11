#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b);

void print(vector<int> arr, int n);

void bubbleSort(vector<int> &arr, int n);

void selectionSort(vector<int> &arr, int n);

void mergeSort(vector<int> &arr);

void merge(vector<int> &out, vector<int> &left, vector<int> &right, int n, int m);

int main() {
    
    int task;
    cin >> task;
    
    vector<int> list;

    int nextVal;
    while(cin >> nextVal) {
        list.push_back(nextVal);
    }

    switch (task)
    {
    case 0:
        bubbleSort(list, list.size());
        print(list, list.size());
        break;
    case 1:
        mergeSort(list);
        print(list, list.size());
        break;
    default:
        cout << "invalid task selected" << endl;
        break;
    }

    return 0;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void print(vector<int> arr, int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}


void bubbleSort(vector<int> &arr, int n) {
    //run n - 1 rounds
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            //swap the current value with the next if the current is less than next
            if(arr[j] < arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        //if no changes were made to the vector during this round, return
        if (swapped == false)
            return;
    }
}

void selectionSort(vector<int> &arr, int n) {

    //loop through unsorted array
    for (int i = 0; i < n - 1; i++) {
        
        //find index of largest element
        int idxLargest = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[idxLargest])
                idxLargest = j;
        }

        //swap value of largest with bottom element
        swap(arr[idxLargest], arr[i]);
    }
}

void mergeSort(vector<int> &arr) {
    //find midpoint
    int m = (arr.size() / 2);

    //create vectors of left and right side
    vector<int> left(arr.begin(), arr.begin() + m);
    vector<int> right(arr.begin() + m, arr.end());

    //sort left and right
    selectionSort(left, left.size());
    selectionSort(right, right.size());

    merge(arr, left, right, left.size(), right.size());
}

void merge(vector<int> &out, vector<int> &left, vector<int> &right, int n, int m) {
    int i = 0, j = 0, k = 0;

    //add value from the largest value between right and left
    while (i < n && j < m) {
        if (left[i] > right[j]) {
            out[k] = left[i];
            i++;
        } else {
            out[k] = right[j];
            j++;
        }
        k++;
    }

    //add the rest of the values from either array
    while (i < n) {
        out[k] = left[i];
        i++;
        k++;
    }

    while (j < m) {
        out[k] = right[j];
        j++;
        k++;
    }
}