#include<bits/stdc++.h>
using namespace std;
int main(){
	// iterator: var that points to an elelemnt of data structure
	/*
EXAMPLE:

v.begin()
v.end()

[5,2,3,5,6]
 |		  |
begin    end(outside dat structure)

-------------------------

RANGE: Sequence of consecutive elements in a data structure. 
range begin() to end() define a range that contains all elements.

reverse(v.begin(),v.end());
random_shuffle(v.begin(),v.end());

	*/
	vector<int> v = {1,2,3,4,5,6,7,8,9};

// Print first element--> acces to an element an iterator points to with *
	cout << *v.begin() << "\n"; 
//auto beacuse it is a pointer 
	auto a = lower_bound(v.begin(),v.end(),5);//Only if array sorted
	cout << *a<< endl; // 5



// Deque

	/*

DEQUE: LIKE A VECTOR BUT ADDS SOME MORE OPERATIONS:

pop_front
push_front


	*/

deque<int> d;
d.push_front(32);
d.push_front(3);
for (auto a : d) cout << a << ", ";

//THEY WORK IN O(1) average
//THE YHAVE LARGER CONSTANT FACTORS
// Preferably to use vectors because they consume less space



//STACK

	/*
	
	like a vector but that only has:

	push
	pop
	top --> retrieve last element

stack<int> s;
s.push(2); // [2]
s.push(5); // [2,5]
cout << s.top() << "\n"; // 5
s.pop(); // [2]
cout << s.top() << "\n"; // 2

//QUEUE

Then, in a queue, elements are inserted at the end of the structure and removed
from the front of the structure. Both the functions front and back are provided
for accessing the first and last element.


queue<int> q;
q.push(2); // [2]
q.push(5); // [2,5]
cout << q.front() << "\n"; // 2
q.pop(); // [5]
cout << q.back() << "\n"; // 5


	*/





}