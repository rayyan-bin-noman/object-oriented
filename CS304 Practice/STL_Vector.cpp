#include<iostream>
#include<string>
using namespace std;
// | Concept       | What it means                                                                  |
// | ------------- | ------------------------------------------------------------------------------ |
// | `vector<int>` | A dynamic array of integers from the STL (Standard Template Library).          |
// | `push_back()` | Adds an element to the end of the vector.                                      |
// | `capacity()`  | How much memory the vector has reserved (can be more than size).               |
// | `size()`      | The number of actual elements stored in the vector.                            |
// | `do...while`  | A loop that asks the user again if they want to continue (based on 'y' input). |

#include <vector> 
int main()
{ 
 vector<int> iv;                // Create an empty vector of integers
 int x, y;                      // Create to store two integers
 char ch;                       // Create to ask if the user wants to continue
 do { 
  cout<<"Enter the first integer:"; 
  cin >> x; 
  cout<<"Enter the second integer:"; 
  cin >> y; 
  iv.push_back( x );            // Add x to the vector
  iv.push_back( y );            // Add y to the vector 
  cout << "Current capacity of iv = " << iv.capacity() << endl; 
  cout << "Current size of iv = " << iv.size() << endl;
  cout<<"Do you want to continue?"; 
  cin >> ch;                     // Ask user if they want to continue (press 'y' to keep going)
 } while ( ch == 'y' );
    
    return 0;
} 
// In Super Simple Words:
// You’re filling a basket (vector) with number pairs.
// The basket grows on its own as you add more numbers.
// You’re watching:
// How many numbers are inside (size)
// How big the basket really is (capacity)