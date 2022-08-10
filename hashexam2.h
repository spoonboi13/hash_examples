// exam 2 .h file 
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>

#ifndef HASH_H
#define HASH_H 

class hashfunction{

public:

int key;
int value;

hashfunction(int key, int value){

this->key = key;
this->value = value;
}
};

class HashMap{
private:
hashfunction **table;

public:
int table_size = 10;
void insertitem(int key, int value);
int searchitem(int key);
void display();
void removeitem(int key);
HashMap(){
table = new hashfunction * [table_size]; // took table size out and made into 10 instead - now changed back to table_size

for (int i = 0; i< table_size; i++){
table[i] = NULL;

}
}
};




#endif HASH_H