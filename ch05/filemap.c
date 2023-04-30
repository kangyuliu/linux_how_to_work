#include <err.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 1000
#define ALLOC_SIZE (100 * 1024 * 1024)
static char command[BUFFER_SIZE];
static char file_contents[BUFFER_SIZE];
static char overwrite_data[] = "HELLO";
// main函数
int main(void) {
  pid_t pid;
  pid = getpid();                                            // 获取进程id
  snprintf(command, BUFFER_SIZE, "cat /proc/%d/maps", pid);  // 格式化comm
  printf("command: %s\n", command);
  puts("*** memory map before mapping file ***");
  fflush(stdout);
  system(command);  // exec shell script
  // 打开testfile fd
  int fd;
  fd = open("testfile", O_RDWR);
  if (fd == -1) err(EXIT_FAILURE, "open() failed");
  // 将testfile mmap到内存中
  char* file_contents;
  file_contents =
      mmap(NULL, ALLOC_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  if (file_contents == (void*)-1) {
    warn("mmap() failed");
    goto close_file;
  }
  puts("");
  printf("*** succeeded to map file: address = %p; size =0x%x ***\n",
         file_contents, ALLOC_SIZE);
  puts("");
  puts("*** memory map after mapping file ***");
  fflush(stdout);
  system(command);  // 执行comm shell脚本
  puts("");
  printf("*** file contents before overwrite mapped region:%s", file_contents);
  // 覆写映射的区域
  memcpy(file_contents, overwrite_data, strlen(overwrite_data));
  puts("");
  printf("*** overwritten mapped region with: %s\n", file_contents);
  if (munmap(file_contents, ALLOC_SIZE) == -1) warn("munmap() failed");
  // while (1) {
  /* code */
  //}

close_file:
  if (close(fd) == -1) warn("close() failed");
  exit(EXIT_SUCCESS);
}