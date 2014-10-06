05_Hashing_Lab
==============

Implement a hash table in C++

Requirements
------------

1. `keyExists`, `find`, `remove`, and `size` should all be O(1)
2. `add` should be reasonably fast. Use linear probing to find an open slot in the hash table. This will be O(1), on average, except when `grow` is called.
3. `grow` should be O(n)
4. Do not leak memory


Reading
=======
"Open Data Structures," Chapter 5, except for 5.2.3. http://opendatastructures.org/ods-cpp/5_Hash_Tables.html

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. KeyExists does not work and I do not believe find works, but size and remove should both work.
2. add was very difficult to understand and I could not get the code to work.
3. Grow should work fine.
4. The destructor works and removes data along with the pointer to the data.

#### 2. I decided to use two function (`keyExists` and `find`) to enable lookup of keys. Another option would have been to have `find` return a `T*`, which would be `NULL` if an item with matching key is not found. Which design do you think would be better? Explain your reasoning. You may notice that the designers of C++ made the same decision I did when they designed http://www.cplusplus.com/reference/unordered_map/unordered_map/

I think it is better to return the key rather than a T* because the user should not be using addresses rather than keywords to access their data, it would be more confusing and more difficult to deal with when accessing data. The table should be easy to use and implement and should not allow users to know what the T* is in case they misuse the information or are confused by it.

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

It was very confusing to use this type of structure because it consists of an array of HashRecords if I am not mistaken and using an array of classes was quite difficult when implementing the find and keyExists methods especially. How are we supposed to use the HashRecord, are we using it as the data within an array and does the '->' operator have use in getting the key or data within an element of the array?