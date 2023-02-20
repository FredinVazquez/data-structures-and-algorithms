<h1 align="center">Hash table: unordered_map && unordered_set</h1>

```c++
#include <unordered_map> 
#include <unordered_set> 
```

<p>
<br><br>
In C++ what we have for the implementations of hash tables are again the set and map structures, these same ones do the function of hash tables, being more explicit the map structure due to the fact that it will be using a key to access a certain value. However, for the set, you can also have the same applications only having the limitation of the key, but having other advantages due to its functions.<br><br>
However, the operations that a hash table has natively are usually of a logarithmic complexity for the set and map structures, although this complexity is good, it is much better to have constant complexities and it is here where the structures are born:<br>
<ol>
<li>unordered_set </li>
<li>unordered_map </li>
</ol>
Which have the operations of insertion, search, and deletion in constant time for the average case. Although it is necessary to consider the worst case being of linear complexity.<br><br>
Now, both structures are too similar to each other and this is not a coincidence because they really share many similarities between them. However, the main difference between these unordered versions with the original versions is precise that you will not be guaranteed a specific order for their elements, and this allows precisely to have insertions and searches in constant time. But between the unordered versions of set and map the way to choose which one to use is entirely up to the implementation you want to give, and for this, it is very important to read the different functions that have incorporated both structures in order to choose the most appropriate for your solution.<br><br>
For more information you can read:
<ol>
<li><a href="https://cplusplus.com/reference/unordered_set/unordered_set/" >unordered_set functions</a></li>
<li><a href="https://cplusplus.com/reference/unordered_map/unordered_map/" >unordered_map functions</a></li>
</ol>

</p>