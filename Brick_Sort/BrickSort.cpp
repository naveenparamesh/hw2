#include <iostream>

using namespace std;

//algorithm that runs through array making comparisons
// and starts at different indexes each run through the for loop
// so it seems like bricks coming together
void BrickSort (int numbers[], int n)
{
    for (int i = 0 ; i < n ; i++)
    {
         if (i & 1) // 'i' is odd
         {
             for (int j = 2 ; j < n ; j += 2)
             {     
                  if (numbers[j] < numbers[j-1])
                      swap (numbers[j-1], numbers[j]);//swap the two
             }
          }
          else
          {  
              for (int j = 1 ; j < n ; j += 2)
              {
                   if (numbers[j] < numbers[j-1])
                       swap (numbers[j-1], numbers[j]);//swap the two
              } 
          }
    }
}


int main(){
   int my_array[] = {10, 7, 34, 18, 24, -1093, 26396, -94, 580, 12};
   cout << "UNSORTED:" << endl;
   for(int i = 0; i < 10; i++){
      cout << my_array[i] << " ";
   }
   BrickSort(my_array, 10);
   cout << "\nSORTED:" << endl;
   for(int i = 0; i < 10; i++){
      cout << my_array[i] << " ";
   }
   cout << endl;
   return 0;
}