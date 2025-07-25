#include <deque>
#include<iostream>
#include<string>
using namespace std;

int main() 
{ 
 deque< int > dq; 
 dq.push_front( 3 ); 
 dq.push_back( 5 ); 
 dq.pop_front(); 
 dq.pop_back();

 return 0; 
} 