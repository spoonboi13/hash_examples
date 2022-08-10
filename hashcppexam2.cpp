// exam 2  
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include "hash.h"
using namespace std;

const int TABLE_SIZE = 10;// table size is going to be 10 

//declartation for hash function
class hashfunction{

public:
    int key;
    int value;
//main function to go off of
hashfunction(int key, int value){

this->key = key;
this->value = value;
}
};


//hashmap declaration
class HashMap{

private:
    hashfunction **table; //pointer to pointer of table 

public:
// constructor for the hashmap
HashMap(){

table = new hashfunction * [TABLE_SIZE];

for (int i = 0; i< TABLE_SIZE; i++){
table[i] = NULL;
}
}

//hash function
int HashFunc(int key){

return key % TABLE_SIZE;
}


//inserting element at the key
void insertitem(int key, int value){

int hash = HashFunc(key);

while (table[hash] != NULL && table[hash]->key != key){
hash = HashFunc(hash + 1);
}

    if (table[hash] != NULL)

delete table[hash];

table[hash] = new hashfunction(key, value);
}


 //search element at key

int searchitem(int key){

int hash = HashFunc(key);

while (table[hash] != NULL && table[hash]->key != key){
hash = HashFunc(hash + 1);
}

    if (table[hash] == NULL)
return -1;

else
return table[hash]->value;
}

// displays output of table
void display(){

int i=0;

while (i<TABLE_SIZE){

    if(table[i]!=NULL)

cout<<table[i]->key<<"\t"<<table[i]->value<<endl;

i++;
}
}

//remove the element at key
void removeitem(int key){

int hash = HashFunc(key);

while (table[hash] != NULL){

    if (table[hash]->key == key)

break;

hash = HashFunc(hash + 1);
}

if (table[hash] == NULL){

cout<<" -Sorry. No Element found at key "<<key<<endl; // outside of the key. 

return;
}

else{

table[hash]=NULL;
}

cout<<" Your Element was Deleted. Check display to see! "<<endl;
}

~HashMap(){

for (int i = 0; i < TABLE_SIZE; i++){
    if (table[i] != NULL)
    delete table[i];
    delete[] table;
}
}
};
 
