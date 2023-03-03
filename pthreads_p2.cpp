/*
 @file: pthreads_skeleton.cpp
 
 @author: Virginia @uncc.edu
 @description: A program that demonstrates processes.
 
 @course: ITSC 3146
 @assignment: in-class activity [n]
 */

#include <pthread.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>

int array[10];

using namespace std;

void *countNegatives(void*){
   int count = 0;
   for(int i=0; i<10; i++){
       if(array[i] < 0){
           count++;
       }
   }
   cout << "Total negative numbers: " << count << endl;
}

void *average(void*){
   int sum = 0;
   for(int i=0; i<10; i++){
       sum += array[i];
   }
   cout << "Average: " << (float)sum/10 << endl;
}

void *reverse(void*){
   cout << "The numbers in reverse\n";
   for(int i=9; i>=0; i--){
       cout << array[i] <<" ";
   }
   cout << endl;
}

void *routineName(void *arg)
{
   cout << "Thread is running..." << endl;
   return 0;
}


int main()
{
   // id is used to store a unique thread identifier,
   // returned by the call to create a new POSIX thread
   pthread_t t1, t2, t3;
   
   // rc is used to store the code returned by the
   // call to create a new POSIX thread. The value is
   // zero (0) if the call succeeds.
   int rc;
   
   
   //process user input

   for(int i=0; i<10; i++){
      cout << "Enter an integer" <<endl;
      cin >> array[i]; 
   }
   
   // Create thread(s)
   rc = pthread_create(&t1, NULL, countNegatives, NULL);
    if(rc){
        cout << "Error: unable to create thread " << rc << endl;
   }
      //delay
      for (int count = 0; count < 10000; count++);
   
   rc = pthread_create(&t2, NULL, average, NULL);
      if(rc){
         cout << "Error: unable to create thread " << rc << endl;
      }
      //delay
      for (int count = 0; count < 10000; count++);
   
   rc = pthread_create(&t3, NULL, reverse, NULL);
      if(rc){
        cout << "Error: unable to create thread " << rc << endl;
      }
      //delay
      for (int count = 0; count < 10000; count++);
   
   void* status;
   
   rc = pthread_join(t1,&status);
   if(rc){
       cout << "Error:unable to join " << rc << endl;
   }

   rc = pthread_join(t2,&status);
   if(rc){
       cout << "Error:unable to join " << rc << endl;
   }

   rc = pthread_join(t3,&status);
   if(rc){
       cout << "Error:unable to join " << rc << endl;
   }

   //immediately end execution of all threads
   pthread_exit(0);
}
