/*
 @file: pthreads_skeleton.cpp
 
 @author: Virginia, @uncc.edu
 
 @description: A program that demonstrates processes.
 
 @course: ITSC 3146
 @assignment: in-class activity [n]
 */

#include <pthread.h>
#include <iostream>
#define THREAD_COUNT 4
using namespace std;

//global array
const char* my_messages[4] = {"English: Hello!", 
	"French: Bonjour!", "Spanish: Hola!", 
	"German: Guten Tag!" }; 
	
//pthread function sent a single integer parameter, index
//prints the message stored in the location index of the array my_messages. 
void *printMessage(void *arg)
{
   // explicit type cast void to index value
   int *index = (int *)arg;
   cout << my_messages[*index] << endl;
   return 0;
}

void *routineName(void *arg)
   // the thread's functionality
   cout << "Thread is running..." << endl;
   return 0;
}


int main()
{
   // id is used to store a unique thread identifier,
   // returned by the call to create a new POSIX thread
   pthread_t id[4];
   
   // rc is used to store the code returned by the
   // call to create a new POSIX thread. The value is
   // zero (0) if the call succeeds.
   int rc;

   // Create thread(s)
   
   int i;

   int loc[] = { 0, 1, 2 , 3};

   for ( i = 0 ; i < THREAD_COUNT ; i++ )
   {
      rc = pthread_create(&id[i], NULL, printMessage, (void*)(loc + i));

      if (rc){
         cout << "ERROR; return code from pthread_create() is " << rc << endl;
         return -1;
      }
   } 
   for ( i = 0; i < THREAD_COUNT ; i++)
      pthread_join( id[i], NULL );
   //exit here immediately ends execution of all threads
   pthread_exit(0);
}
