#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void) {
  int num1, num2, mul;// define random variables 
  
  int input_fds = open("./input.txt", O_RDONLY);
  int output_fds = open("./output.txt", O_WRONLY | O_CREAT, S_IRUSR |S_IWUSR);
  
  int error_fds = open("./error.txt", O_RDONLY);
  
  dup2(input_fds, STDIN_FILENO);
  dup2(output_fds, STDOUT_FILENO);
  dup2(error_fds, STDERR_FILENO);//dup2 function
  
  scanf("%d %d", &num1, &num2);
  mul = num1 * num2;
  printf("%d * %d = %d\n", num1, num2, mul);
  return EXIT_SUCCESS;
}
