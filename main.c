#include "get_next_line.h"



 int main()
{  
    int fd = open("ans5.txt",O_RDWR | O_CREAT , 0777);
   // int fd2 = open("anis.txt",O_RDWR | O_CREAT , 0777);
    printf("%s",get_next_line(fd));
   /*printf("%s",get_next_line(fd2));
   printf("%s",get_next_line(fd));
   printf("%s",get_next_line(fd));
   printf("%s",get_next_line(fd));*/
    

}