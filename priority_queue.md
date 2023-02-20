<h1 align="center">Priority queue</h1>

```c++
#include <queue>
```

<p>
It will be from a complete binary tree that the heap is born, it will have a special characteristic which is: a vertex will always have a greater value than its immediate child. This property will be fulfilled successively, so that this child must also have a greater value than its immediate child. This will cause one thing and that is that the root node of the tree will have the value that is the largest of all the values involved in the structure, this will be very useful because to know the maximum value of a given set of data will only have to consult the value of the root, while to know the smallest value of the set it will only be necessary to consult all the leaf nodes that are present.
Therefore, taking into account the construction of this structure it will be possible to understand that the most difficult thing to do is to add and remove elements, such that this will have to be done by means of value exchanges until the property is fulfilled again.<br><br>
Then, the implementation of a priority queue is based on a heap tree such that it will always be contemplating the maximum in the root, therefore it will be maintained within the structure a priority which is to always maintain the maximum in the root, and that will be the priority, to have the highest value. However, within the code it is possible to change this property and modify it to have as a priority the smallest value, it is not necessary that the ordering is always descending, it is possible to change it. This is where the two possible implementations of a heap come from, being known as MAX-HEAP and MIN-HEAP.<br><br>
Some considerations to be made are that its implementation using the heap structure is simpler than the implementation of a balanced binary search tree as in the case of a set. This is why the priority queue exists because we will see later that there are other structures that share almost all the functions of a priority queue, as is the case of the set, however, if we want a priority queue it is more convenient to use this structure directly instead of emulating it by means of another one due to the efficiency that the heap structure gives us.
On the other hand, a priority queue supports all the functions of a normal queue. <br><br>
Some of these functions are:
<ul>
<li>.empty(): O(l)</li>
<li>.size(): O(l)</li>
<li>.top(): O(l)</li>
<li>.push(): O(log n)</li>
<li>.pop(): O(log n)</li>
</ul><br>
In order to change the priority to consider the smallest element, it can be done in the following way:<br>
</p>
<br>

```c++
priority_queue<int,vector<int>,greater<int>> q;
```
<br>
For more information you can read:
<ol>
<li><a href="https://cplusplus.com/reference/queue/priority_queue/" >priority_queue</a></li>
</ol><hr><br>
<h2>Examples</h2>
<br>

<h3>Strings</h3>

```c++
#include<bits/stdc++.h>
using namespace std;

int main()
    {
        priority_queue<string> q; 
		q.push("abc"); 
		q.push("ttt"); 
		q.push("bbb");
        cout << q.top() << "\n"; // ttt
        q.pop();
        cout << q.top() << "\n"; // bbb
        q.pop();
        q.push("zkj");
        cout << q.top() << "\n"; // zkj
        q.pop();
        return 0;
    }
```

<br>
<h3>Integers</h3>

```c++
#include<bits/stdc++.h>
using namespace std;

int main()
    {
        priority_queue<int> q;
        q.push(90);
        q.push(8);
        q.push(1249);
        q.push(16);
        cout << q.top() << "\n"; // 1249
        q.pop();
        cout << q.top() << "\n"; //90
        q.pop();
        q.push(17);
        cout << q.top() << "\n"; // 17
        q.pop();
        return 0;
    }
```