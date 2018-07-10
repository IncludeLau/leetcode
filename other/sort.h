//
// Created by 刘新军 on 2018/6/21.
//

#ifndef LEETCODE_SORT_H
#define LEETCODE_SORT_H

#include <vector>

using namespace std;

void insertSort(vector<int> &v) {
    int temp;
    for(int i = 1; i< v.size(); i++) {
        int j = i - 1;
        temp = v[i];
        while (j >= 0 && v[j] > temp) {
            v[j+1] = v[j];
            j--;
        }
        if (j != i - 1) {
            v[j+1] = temp;
        }
    }
}

void selectSort(vector<int> &v) {
    int i,j,k;
    for(i =0 ; i < v.size(); ++i) {
        k = i;
        for (j=i+1; j < v.size(); ++j) {
            if(v[j] < v[k]) {
                k = j;
            }
        }
        if(i != k) {
            swap(v[i], v[k]);
        }
    }
}

void bubbleSort(vector<int> &v) {
    for(int i = 0; i < v.size() - 1; ++i) {
        bool noswap = true;
        for(int j = 0; j < v.size() - i - 1; ++j) {
            if(v[j] > v[j+1]) {
                swap(v[j], v[j+1]);
                noswap = false;
            }
        }
        if (noswap) break;
    }
}

void _quickSort(vector<int>&, int, int);

void quickSort(vector<int>& v) {
    _quickSort(v, 0, static_cast<int>(v.size()) - 1);
}

void _quickSort(vector<int>& v, int low, int high) {
    if(high <= low) return;
    int left = low;
    int right = high;
    int pivot = v[left];
    while(left != right) {
        while (left < right && v[right] >= pivot) --right;
        v[left] = v[right];
        while (left < right && v[left] <= pivot) ++left;
        v[right] = v[left];
    }
    v[left] = pivot;
    _quickSort(v, low, left -1);
    _quickSort(v, left+1, high);
}



void merge(vector<int>& v, int l, int m, int r) {
    int i = l;
    int j = m;

    while (i < j && j <= r) {
        if (i < j && v[i] < v[j]) ++i;
        int index = j;
        while (j<=r && v[j] < v[i]) j++;
        reverse(v.begin()+ i, v.begin()+index);
        reverse(v.begin()+index, v.begin()+j);
        reverse(v.begin()+i, v.begin()+j);
        i += j-index;
    }

}

void _mergeSort(vector<int>& v, int l, int r) {
    if(l < r) {
        int mid = ( l+ r) >> 1;
        _mergeSort(v, l, mid);
        _mergeSort(v, mid+1, r);
        merge(v, l, mid, r);
    }
}



void mergeSort(vector<int>& v) {
    _mergeSort(v, 0, static_cast<int>(v.size()));
}

void maxHeapify(vector<int>& v, int i, int size) {
    int l = i * 2 + 1;
    int r = l + 1;
    int k;
    if(l < size && v[l] > v[i]) {
        k = l;
    }else {
        k = i;
    }
    if (r < size && v[r] > v[k]) {
        k = r;
    }
    if (i != k) {
        swap(v[i], v[k]);
        maxHeapify(v, k, size);
    }
}

void buildMaxHeap(vector<int>& v, int size) {
    for(int i = (static_cast<int>(v.size()) - 1) / 2; i >= 0; --i) {
        maxHeapify(v, i, size);
    }
}


void heapSort(vector<int>& v, int size) {
    buildMaxHeap(v, size-1);

    for(int i = size - 1; i > 0; --i) {
        swap(v[0], v[i]);
        maxHeapify(v, 0, i);
    }
}

#endif //LEETCODE_SORT_H
