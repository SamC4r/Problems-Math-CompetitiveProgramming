#include<bits/stdc++.h>
using namespace std;
int main(){
	/*

main operations: insertion, saerch, removal

SET STRUCTURES:

1. ALL elements distinct
2. Ordered (often)


set: 

1. ORDERED

Based on a balanced binary search tree and works in O(logn) time.
Due to that, sometimes set solutoins could be slower than sorting
ideas due to the amount of space/data/effort needed in 
balanced binary saerch tree.



unordered_set:

2. Unordered

Based on a hash table and it works in O(1) 

	*/

	set<int> s; //declare set!
	s.insert(3); // insert a set --> every insertion takes in average O(log n)
	s.insert(2);
	s.insert(5);
	cout << s.count(3) << "\n"; // 1
	cout << s.count(4) << "\n"; // 0
	s.erase(3);
	s.insert(4);
	cout << s.count(3) << "\n"; // 0 --> s.count(x)
	cout << s.count(4) << "\n"; // 1

	//COUNT --> great function. Returns 1 if the element is in set.


	//iterate through a set:

	for(auto x : s)
		cout << x << "\n";

	//find(x) function

	auto it = s.find(3); //returns an iterator/pointer to that element
	//IF that element is not present it returns s.end();



	//ACCES AN ELEMENT;
//PROBLEM: FIND LARGEST ELELEMENT: --> LAST POSITION

	auto largest = s.end();
	largest--;//because end point out of the array
	cout << *largest << " ";
	cout << *s.lower_bound(6) << endl;

	auto myElement = next(s.begin(),3); //next returns a pointer that is moved 3 times from begin.
	cout << *myElement << endl;





	/*

	MULTISET: 

SET WITH MULTIPLE COPIES Of the same value. 
other variation: 

unordered_multiset

KEEPS THE ORDER!!!!

is O(log n)

	*/

	multiset<int> s2;
	s2.insert(5);
	s2.insert(5);
	s2.insert(5);
	cout << s2.count(5) << "\n"; // 3 returns number of times 5 appears!!

	//erase() ? --> removes all copies of a value!!!!!!

	//How to remove one?

	s2.erase(s.find(5)); // returns an iterator to one number 5 and removes that position.



	//PRIORITY QUEUE

	/*
	multiset 

	insertion --> O(log n) 
	retrieval --> O(1)    of max element
	(USUALLY)

	
	IT has smaller constant factors. Uses a heap instead of B.S
	More efficient
	
	Functions: 

    empty()
    size()
    front()
    top()
    push_back()
    pop_back()

	GOOD WHEN TRYING TO FIND MAX ELEMENT OF ARRAY.


	*/

	priority_queue<int> q;
	q.push(3);
	q.push(5);
	q.push(3);
	q.push(7);
	q.push(2);
	cout << q.top() << "\n"; // 7   top(x) gives last element
	q.pop();
	cout << q.top() << "\n"; // 5
	q.pop(); //erases last element
	q.push(6);
	cout << q.top() << "\n"; // 6
	q.pop();
	while (! q.empty() ) {
   	 cout << q.top() << "\n";
  	  q.pop();
	}

	//UNORDERED SETS
	//unordered sets have count!!!! --> works with hash sheesh.

    unordered_set<int> unset;
    unset.insert(4);
    unset.insert(4);
    unset.insert(5);
    unset.insert(3);
    unset.insert(1);
    unset.insert(9);
    cout << endl;
    for(auto a : unset) cout << a << " ";
    cout << unset.count(4) << " yes number 4 is there!";
	//coutn based on 

}

