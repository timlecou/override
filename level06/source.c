#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int auth(char *buffer, unsigned int serial)
{
  size_t buffer_len;
  long ptret;
  int i;
  unsigned int local_14;
  
  buffer_len = strcspn(buffer, "\n");
  buffer[buffer_len] = '\0';
  buffer_len = strnlen(buffer, 32);
  if ((int)buffer_len < 6) {
    return (1);
  }
  else
  {
    ptret = ptrace(PTRACE_TRACEME);
    if (ptret == -1) {
      puts("\x1b[32m.---------------------------.");
      puts("\x1b[31m| !! TAMPERING DETECTED !!  |");
      puts("\x1b[32m\'---------------------------\'");
      return (1);
    }
    else
    {
      local_14 = ((int)buffer[3] ^ 4919) + 6221293;
      for (i = 0; i < buffer_len; i++)
      {
        if (buffer[i] < ' ')
          return (1);
        local_14 += ((int)buffer[i] ^ local_14) % 1337;
      }
      if (serial == local_14) {
        return (0);
      }
      else {
        return (1);
      }
    }
  }
  return (0);
}

bool main(void)

{
  char buffer [32];
  int  serial;
  
  puts("***********************************");
  puts("*\t\tlevel06\t\t  *");
  puts("***********************************");
  printf("-> Enter Login: ");
  fgets(buffer, 32, stdin);
  puts("***********************************");
  puts("***** NEW ACCOUNT DETECTED ********");
  puts("***********************************");
  printf("-> Enter Serial: ");
  scanf("%d", serial);
  if (auth(buffer, serial) == 0) {
    puts("Authenticated!");
    system("/bin/sh");
  }
  return 0;
}
