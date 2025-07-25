#include<iostream>
#include<string>
using namespace std;
#include <list> 
int main() 
{ 
 std::list< float > _list; 
 _list.push_back( 7.8 ); 
 _list.push_back( 8.9 ); 
 std::list< float >::iterator it = _list.begin(); 
_list.insert( ++it, 5.3 );
 
 return 0; 
} 