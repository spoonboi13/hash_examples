// exam 2 main.cpp
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include "hash.h"
#include "hashcppexam2.cpp"
using namespace std;


int main(){

HashMap hash; //object to get data from hashmap

int key, value; // main pairs
int choice; // users input
// while and switch case to go through menu 
while (1){
cout << endl; 
cout<<"1. Insert a element (number) into the table"<<endl;

cout<<"2. Delete an element at a key"<<endl;

cout<<"3. Search an element from the key"<<endl;

cout<<"4. Display Table"<<endl;

cout<<"5. Exit."<<endl;

cout<<"Enter your choice: ";
cin>>choice;

switch(choice){
// each case if selected
case 1:
cout<<"Enter an element to be inserted: ";
cin>>value;
cout<<"Enter key at which element is to be inserted: ";
cin>>key;

hash.insertitem(key, value);
break;

case 2:
cout<<"Enter key of the element to be deleted: ";

cin>>key;
hash.removeitem(key);
break;

case 3:
cout<<"Enter key of the element to be searched: ";
cin>>key;

if (hash.searchitem(key) == -1){
cout<<" -Sorry. No element found at key "<<key<<endl; // if not element was found at key.
continue;
}

else{

cout<<"Element at key "<<key<<" : "; 
cout<<hash.searchitem(key)<<endl;
}
break;

case 4:
cout<<"key"<<"\t"<<"value"<<endl;
hash.display();
break;

case 5:
exit(1); // breaks everything and exits program

default:
cout<<"\nEnter correct option\n"; // incase something was inputted correctly 
}
}

return 0;
}