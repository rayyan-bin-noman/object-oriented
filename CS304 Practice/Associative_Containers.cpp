#include<iostream>     // For standard I/O (cin, cout)
#include<string>       // For using string class if needed in future
#include<set>          // For set and multiset
#include<map>          // For map and multimap

using namespace std;

int main()
{ 
    // =========================
    // Example – STL Set
    // =========================
    set<char> cs;  // Create a set of characters (unique elements only)

    cout << "Size before insertions (set): " << cs.size() << endl;

    cs.insert('a');   // Insert 'a' → OK
    cs.insert('b');   // Insert 'b' → OK
    cs.insert('b');   // Insert 'b' again → Ignored (no duplicates allowed)

    cout << "Size after insertions (set): " << cs.size() << endl;
    // Output should be 2 since 'b' is inserted only once

    // =========================
    // Example – STL Multiset
    // =========================
    multiset<char> cms;  // Create a multiset of characters (duplicates allowed)

    cout << "Size before insertions (multiset): " << cms.size() << endl;

    cms.insert('a');  // Insert 'a' → OK
    cms.insert('b');  // Insert 'b' → OK
    cms.insert('b');  // Insert 'b' again → Allowed (duplicates permitted)

    cout << "Size after insertions (multiset): " << cms.size() << endl;
    // Output should be 3

    // =========================
    // Example – STL Map
    // =========================
    typedef map<int, char> MyMap;   // Define a map from int to char
    MyMap m;                        // Create the map object

    // Insert key-value pairs (keys must be unique)
    m.insert(MyMap::value_type(1, 'a'));
    m.insert(MyMap::value_type(2, 'b'));
    m.insert(MyMap::value_type(3, 'c'));

    // Find and print the value at key 2
    MyMap::iterator it = m.find(2);  
    // 'find' returns iterator to element with key 2
    if (it != m.end()) {
        cout << "Value @ key " << it->first << " is " << it->second << endl;
    }

    // =========================
    // Example – STL Multimap
    // =========================
    typedef multimap<int, char> MyMultimap;  // Define multimap from int to char
    MyMultimap mm;                           // Create the multimap object

    // Insert key-value pairs (duplicate keys allowed)
    mm.insert(MyMultimap::value_type(1, 'a'));
    mm.insert(MyMultimap::value_type(2, 'b'));
    mm.insert(MyMultimap::value_type(3, 'b'));  // 'b' again, but value is OK

    // Find and print the value at key 2
    MyMultimap::iterator it1 = mm.find(2);  // Returns first match with key 2
    MyMultimap::iterator it2 = mm.find(3);  // Returns first match with key 3

    if (it1 != mm.end()) {
        cout << "Value @ key " << it1->first << " is " << it1->second << endl;
    }

    if (it2 != mm.end()) {
        cout << "Value @ key " << it2->first << " is " << it2->second << endl;
    }

    return 0;
}
