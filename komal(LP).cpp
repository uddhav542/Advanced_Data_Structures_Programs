
#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    /*
    creates a hash table of size 10
    */

    char** create_hash_table(){



        char* the_hash_table[10];   // defines a hash table to store strings

        *the_hash_table=malloc(sizeof(char*)10); // allocates memory in the heap for the hash table
        int i;
        for(i=0;i<10;i++){ // this loop initializes the string pointers to NULL at the starting point of the hash table
            the_hash_table[i]=NULL;
        }
        return &the_hash_table; // returns the address of the hash table to the main memory

    }

    /*
    this is a method to insert a string into the relevant position of the hash table
    */

    void insert(char* the_string,char** the_hash_table){

        printf("%s",the_hash_table[1]);
        int n=hash(the_string);
        printf("%s",the_hash_table[1]);
        if(the_hash_table[n] == NULL)
            the_hash_table[n]=the_string;

    }


