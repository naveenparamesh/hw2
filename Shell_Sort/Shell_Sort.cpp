#include <iostream>

using namespace std;

void ShellSort(int numbers[], int numbersSize) {
   int i = 0;
   int j = 0;
   int jump = numbersSize / 2;// Temporary variable for swap
   
   while(jump >= 1){
      for (i = 0; (i + jump) < numbersSize; ++i) {
         j = i;
         while (j >= 0 && numbers[j + jump] < numbers[j]) {
         // Swap numbers[j] and numbers[j - 1]
         swap(numbers[j + jump], numbers[j]);
         j -= jump;
         }
      }
      jump /= 2;
   }
   
}

int main(){
   int my_array[] = {10, 7, 34, 18, 24, -1093, 26396, -94, 580, 12};
   cout << "UNSORTED:" << endl;
   for(int i = 0; i < 10; i++){
      cout << my_array[i] << " ";
   }
   ShellSort(my_array, 10);
   cout << "\nSORTED:" << endl;
   for(int i = 0; i < 10; i++){
      cout << my_array[i] << " ";
   }
   cout << endl;
   
   
   return 0;
}
