undefined4 main(void)

{
  int iVar1;
  undefined4 *buff;
  byte i;
  uint local_a4;
  undefined4 input [32];
  uint local_20;
  uint local_1c;
  long local_18;
  __pid_t pid;

// create a child
  i = 0;
  pid = fork();
  buff = input;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *buff = 0;
    buff = buff + (uint)i * -2 + 1;
  }
  local_18 = 0;
  local_a4 = 0;
// use ptrace to monitor the child
  if (pid == 0) {
    prctl(1,1);
    ptrace(PTRACE_TRACEME,0,0,0);
    puts("Give me some shellcode, k");
    gets((char *)input);
  }
  else {
    do {
      wait(&local_a4);
      local_20 = local_a4;
      if (((local_a4 & 0x7f) == 0) ||
         (local_1c = local_a4, '\0' < (char)(((byte)local_a4 & 0x7f) + 1) >> 1)) {
        puts("child is exiting...");
        return 0;
      }
      // ptrace check on child and if receive a signal == 11 (aka SIGSEGV) kill 
      local_18 = ptrace(PTRACE_PEEKUSER,pid,0x2c,0);
    } while (local_18 != 0xb);
    puts("no exec() for you");
    kill(pid,9);
  }
  return 0;
}
