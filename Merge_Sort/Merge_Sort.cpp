#include <iostream>

using namespace std;

void Merge(int numbers[], int i, int j, int k){
    int mergedSize = (k - i) + 1;
    int mergedNumbers[mergedSize];
    int mergePos = 0;
    int leftPos = 0;
    int rightPos = 0;
    
    leftPos = i;
    rightPos = j + 1;
    while(leftPos <= j && rightPos <= k){
        if(numbers[leftPos] < numbers[rightPos]){
            mergedNumbers[mergePos] = numbers[leftPos];
            leftPos += 1;
        }
        else {
            mergedNumbers[mergePos] = numbers[rightPos];
            rightPos += 1;
        }
        
        mergePos += 1;
    }
    
    while(leftPos <= j){
        mergedNumbers[mergePos] = numbers[leftPos];
        leftPos += 1;
        mergePos += 1;
    }
    
    while(rightPos <= k){
        mergedNumbers[mergePos] = numbers[rightPos];
        rightPos += 1;
        mergePos += 1;
    }
    
    for(mergePos = 0; mergePos < mergedSize; mergePos++){
        numbers[i + mergePos] = mergedNumbers[mergePos];
    }
    
    
}

void Merge_Sort(int numbers[], int i, int k){
    int j = 0;
    
    if(i < k){
        j = (i + k) / 2;// calculating midpoint
        
        //partition segment into halves again
        Merge_Sort(numbers, i, j);
        Merge_Sort(numbers, j + 1, k);
        
        Merge(numbers, i, j, k);
    }
    
}


int main(){
   int my_array[] = {10, 7, 34, 18, 24, -1093, 26396, -94, 580, 12};
   cout << "UNSORTED:" << endl;
   for(int i = 0; i < 10; i++){
      cout << my_array[i] << " ";
   }
   Merge_Sort(my_array, 0, 9);
   cout << "\nSORTED:" << endl;
   for(int i = 0; i < 10; i++){
      cout << my_array[i] << " ";
   }
   cout << endl;
    
    return 0;
}