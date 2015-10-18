#include <iostream>

using namespace std;

int Partition(int numbers[], int i, int k) {
   int l = 0;
   int h = 0;
   int midpoint = 0;
   int pivot = 0;
   int temp = 0;
   bool done = false;
   
   /* Pick middle element as pivot */
   midpoint = i + (k - i) / 2;
   pivot = numbers[midpoint];
   
   l = i;
   h = k;
   
   while (!done) {
      
      //Increment l until theres a number greater than or equal to pivot 
      while (numbers[l] < pivot) {
         ++l;
      }
      
      // Decrement h until theres a number less than or equal to pivot 
      while (pivot < numbers[h]) {
         --h;
      }
      
      //finshed partitioning
      if (l >= h) {
         done = true;
      }
      else {
         /* Swap numbers[l] and numbers[h],
          update l and h */
         swap(numbers[l], numbers[h]);
         
         ++l;
         --h;
      }
   }
   
   return h;
}

void Quicksort(int numbers[], int i, int k) {
   int j = 0;
   
   /* Base case: If there are 1 or zero elements to sort,
    partition is already sorted */
   if (i >= k) {
      return;
   }
   
   /* Partition the data within the array. Value j returned
    from partitioning is location of last element in low partition. */
   j = Partition(numbers, i, k);
   
   /* Recursively sort low partition (i to j) and
    high partition (j + 1 to k) */
   Quicksort(numbers, i, j);
   Quicksort(numbers, j + 1, k);
   
   return;
}
int main(){
    
    int my_array[] = {10, 7, 34, 18, 24, -1093, 26396, -94, 580, 12};
   cout << "UNSORTED:" << endl;
   for(int i = 0; i < 10; i++){
      cout << my_array[i] << " ";
   }
   Quicksort(my_array, 0, 9);
   cout << "\nSORTED:" << endl;
   for(int i = 0; i < 10; i++){
      cout << my_array[i] << " ";
   }
   cout << endl;
    return 0;
}