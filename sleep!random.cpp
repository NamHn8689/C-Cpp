#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <windows.h>//chua Sleep(mili s);
int main()
{
   int i, n;
   time_t t;
   
   n = 5;
   
   /* Khoi tao bo sinh so ngau nhien */
   srand (time(NULL));
   /* in so ngau nhien trong day tu 0 toi 49 */

   for( i = 0 ; i < 1000 ; i++ ) 
   {
   		
      printf("%d ", rand() % 10);
      Sleep(1000);
   }
   return 0;
}
