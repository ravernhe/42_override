undefined4 auth(char *src,uint param_2)

{
  size_t len;
  undefined4 ret;
  long temperimg_var;
  int i;
  uint xor_value;
  
  len = strcspn(src,"\n");
  src[len] = '\0';
  len = strnlen(src,0x20);
  if ((int)len < 6) {
    ret = 1;
  }
  else {
    temperimg_var = ptrace(PTRACE_TRACEME);
    if (temperimg_var == -1) {
      puts("\x1b[32m.---------------------------.");
      puts("\x1b[31m| !! TAMPERING DETECTED !!  |");
      puts("\x1b[32m\'---------------------------\'");
      ret = 1;
    }
    else {
      xor_value = ((int)src[3] ^ 0x1337U) + 0x5eeded;
      for (i = 0; i < (int)len; i = i + 1) {
        if (src[i] < ' ') {
          return 1;
        }
        xor_value = xor_value + ((int)src[i] ^ xor_value) % 0x539;
      }
      if (param_2 == xor_value) {
        ret = 0;
      }
      else {
        ret = 1;
      }
    }
  }
  return ret;
}

bool main(int ac,char **av)

{
  int ret;
  int in_GS_OFFSET;
  uint i;
  char buff [32];
  int local_14;
  
  local_14 = *(int *)(in_GS_OFFSET + 20);
  puts("***********************************");
  puts("*\t\tlevel06\t\t  *");
  puts("***********************************");
  printf("-> Enter Login: ");
  fgets(buff,32,stdin);
  puts("***********************************");
  puts("***** NEW ACCOUNT DETECTED ********");
  puts("***********************************");
  printf("-> Enter Serial: ");
  __isoc99_scanf();
  ret = auth(buff,i);
  if (ret == 0) {
    puts("Authenticated!");
    system("/bin/sh");
  }
  if (local_14 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return ret != 0;
}
