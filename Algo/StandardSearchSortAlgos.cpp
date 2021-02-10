#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void print(vector<int> &arr) {
    for(int i=0; i<arr.size(); i++) cout << arr[i] << ' ';
    cout << '\n';
}

int linear(vector<int> &arr, int s, int e, int k) {
    for(int i=s; i<=e; i++) {
        if(arr[i]==k) return i;
    }
    return -1;
}

int binary(vector<int> &arr, int s, int e, int k) {
    int mid;
    while(s<=e) {
        mid = (s+e)/2;
        if(arr[mid]>k) e = mid-1;
        else if(arr[mid]<k) s = mid+1;
        else return mid;
    }
    return -1;
}

void selectionSort(vector<int> &arr, int s, int e) {
    int pos;
    for(int i=s; i<e; i++) {
        pos = i;
        for(int j=i+1; j<=e; j++) {
            if(arr[pos]>arr[j]) pos = j;
        }
        if(pos!=i) swap(arr[pos], arr[i]);
    }
}

void bubbleSort(vector<int> &arr, int s, int e) {
    for(int i=s; i<e; i++) {
        for(int j=s; j<e-i; j++) {
            if(arr[j]>arr[j+1]) swap(arr[j], arr[j+1]);
        }
    }
}

void insertionSort(vector<int> &arr, int s, int e) {
    bool set;
    int k;
    for(int i=s+1; i<=e; i++) {
        k=arr[i];
        set = false;
        for(int j=i-1; j>=s; j--) {
            if(k<arr[j]) arr[j+1]=arr[j];
            else { arr[j+1]=k; set=true; break; }
        }
        if(!set) arr[s]=k;
    }
}
void shellSort(vector<int> &arr, int n) {
    int temp;
    int gap=n/2;
    while(gap) {
        for(int i=gap; i<n; i++) {
                temp=arr[i];
                int j;
                for(j=i; j-gap>=0 && temp<arr[j-gap]; j-=gap) {
                    arr[j]=arr[j-gap];
                }
                arr[j]=temp;
        }
        gap/=2;
    }
}
void merge(vector<int> &arr, int s, int k, int e) {
    vector<int> l, r;
    for(int i=s; i<=k; i++) l.push_back(arr[i]);
    for(int i=k+1; i<=e; i++) r.push_back(arr[i]);
    int lp=0; int rp=0;
    l.push_back(INT_MAX);
    r.push_back(INT_MAX);
    for(int i=s; i<=e; i++) arr[i] = l[lp]<r[rp] ? l[lp++] : r[rp++];
}

void mergeSort(vector<int> &arr, int s, int e) {
    if(s<e) {
        int k=(s+e)/2;
        mergeSort(arr, s, k);
        mergeSort(arr, k+1, e);
        merge(arr, s, k, e);
    }
}

int partition(vector<int> &arr, int s, int e) {
    int pos=s+1;
    int pivot=arr[s];
    for(int j=s+1; j<=e; j++) {
        if (arr[j]<pivot) swap(arr[pos++],arr[j]);
    }
    swap(arr[s], arr[pos-1]);
    return pos-1;
}

void quickSort(vector<int> &arr, int s, int e) {
    if(s<e) {
        int p=partition(arr, s, e);
        quickSort(arr, s, p-1);
        quickSort(arr, p+1, e);
    }
}

int main() {
    int n;
    cin >> n;
    vector <int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    quickSort(arr, 0, n-1);
    print(arr);
    int k;
    cin >> k;
    cout << binary(arr, 0, n-1, k);
}
