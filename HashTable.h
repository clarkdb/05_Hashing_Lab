//DO NOT CHANGE THIS FILE
//Author: Bo Brinkman
//Date: 2013/07/24
#include "USet.h"

/*
 * Note: Just above your template declaration when you use this class, you
 * must define method called "hash" that takes a Key as input, and returns
 * an unsigned long (which is the hash value)
 *
 * For example, you might do:
 * unsigned long hash(char c){ return 10*((unsigned long)c)%13; }
 * HashTable<char,int> mySillyTable;
 *
 * If you don't define an appropriate hash function, the class won't compile.
 */

template <class Key, class T>
class HashTable : public USet <Key, T> {
 private:
  class HashRecord {
  public:
    Key k;
    T x;
    //If the slot in the hash table is totally empty, set this to true.
    bool isNull;

    //If the slot used to have something in it, but doesn't now, set
    // isDel to true, and isNull to false. isNull is only for slots
    // that have never been used
    bool isDel;

    HashRecord() { isNull = true; isDel = false; };
  };

 public:
  //See USet.h for documentation of these methods
  virtual unsigned long size();
  virtual void add(Key k, T x);
  virtual void remove(Key k);
  virtual T find(Key k);
  virtual bool keyExists(Key k);

  //Initialize all private member variables.
  HashTable();
  //Delete any dynamically allocated memory.
  virtual ~HashTable();

private:
  //A pointer to the array that holds the hash table data
  HashRecord* backingArray;

  //Whenever numItems + numRemoved >= backingArraySize/2, call
  // grow(). grow() should make a new backing array that is twice the
  // size of the old one, similar to what we did in the ArrayQueue
  // lab.
  //Note: You cannot just loop through the old array and copy it to the
  // new one! Since the backing array size has changed, each item will likely
  // map to a different slot in the array. You may just want to use add()
  // after initializing the new array.
  void grow();

  //This helper method should take a key, and return the index for that
  // item within the hash table. If the item already exists, return the
  // index of the existing item. If the item doesn't exist, return the index
  // where it OUGHT to be. This function can then be used as a helper method in
  // your other methods.
  unsigned long calcIndex(Key k);

  unsigned long numItems; //Number of items in the hash table

  //Note: Ordinarily, these OUGHT to be private. In this case I have
  // made them public for ease of testing.
 public:
  unsigned long numRemoved; //Number of slots that have been removed but not re-used. Those that have isDel == true
  unsigned long backingArraySize;
  unsigned 	int prime;
};







//CONTENTS OF THE IPP FILE







//You will need this so you can make a string to throw in
// remove
#include <string>


/**
template <class Key, class T>
HashTable<Key, T>::HashTable(){
	prime = 0;
	T* backingArray = New T[hashPrimes[prime]];
	backingArraySize = numItems;
	numRemoved = 0;
	for (unsigned int x = 0; x < hashPrimes[prime]; x++){
		backingArray[x].isNull = true;
	}
}



template <class Key, class T>
HashTable<Key, T>::~HashTable() {
	delete backingArray[];
}

template <class Key, class T>
unsigned long HashTable<Key, T>::calcIndex(Key k){
	int index = hash(k)%backingArraySize;
	if (backingArray[index].isNull == true){
		return numItems;
	}
	else if (backingArray[index].isNull == false && backingArray[index].isDel == false){
		if(index->Key == k){
		return index;
		}
	}
	return numItems; //This indicates failure, since it is an impossible value
}

**/

/**

template <class Key, class T>
void HashTable<Key, T>::add(Key k, T x){
	numItems++;
	if(numItems + numRemoved >= backingArraySize){
		grow();
	} else if(backingArray[k%backingArraySize].isNull == false && backingArray[k%backingArraySize].isDel == false){
		
	} else {
	backingArray[k % backingArraySize].isNull = false;
	backingArray[k % backingArraySize].T = x;
	backingArray[k % backingArraySize].Key = k;
	}
}

template <class Key, class T>
void HashTable<Key, T>::remove(Key k){
	numRemoved++;
	backingArray[find(k)].isDel = true;
}

template <class Key, class T>
T HashTable<Key, T>::find(Key k){
	if(backingArray[k%backingArraySize].k != k){

	for (unsigned int x = 0; x < backingArraySize - k%backingArraySize; x++){
		if (k == backingArray[x].Key){
			return x;
		}
		else if (backingArray[x].isNull == true){
			throw std::string("The key does not match any data!");
		}
		}
	} else {
	throw std::string("The key does not match any data!");
	T dummy;
	return dummy;
	}
}

template <class Key, class T>
bool HashTable<Key, T>::keyExists(Key k){
		if (CalcIndex(k) == k){
		return true;
		}
		

	return false;
		
}

template <class Key, class T>
unsigned long HashTable<Key, T>::size(){
	return numItems;
}

template <class Key, class T>
void HashTable<Key, T>::grow(){
	prime++;
	NUM_HASH_PRIMES = hashPrimes[prime]/2;
	T* backingArray = New T[hashPrimes[prime]];
	backingArraySize = numItems;
	for (unsigned int x = 0; x < hashPrimes[prime - 1] / 2; x++){
		add(backingArray[x].Key, backingArray[x].T);
	}

}

**/