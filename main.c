#include "get_next_line.h"



 int main()
{  
    char *str1;
    char *str2;
    int fd = open("ans.txt",O_RDWR | O_CREAT , 0777);
    //int fd2= open("anis.txt",O_RDWR | O_CREAT , 0777);
    //int fd = open("ans5.txt",O_RDWR | O_CREAT , 0777);
    //printf("%d\n\n\n\n",fd);
   // int fd2 = open("anis.txt",O_RDWR | O_CREAT , 0777);
    str1 =  get_next_line(fd);
   // str2 = get_next_line(fd);
    printf("%s",str1);
    //printf("%s",str2);
    free(str1);
    free(str2);
   /*printf("%s",get_next_line(fd));
   printf("%s",get_next_line(fd));
   printf("%s",get_next_line(fd));*/
    

}