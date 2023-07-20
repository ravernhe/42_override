undefined8 main(void)

{
  int cmp;
  size_t i;
  long j;
  undefined8 *init_ptr;
  undefined8 g_password [14];
  undefined8 ptr [6];
  undefined8 g_user [12];
  int size_read;
  FILE *fd;

// bzero 3 pointers
  init_ptr = g_user;
  for (j = 12; j != 0; j = j + -1) {
    *init_ptr = 0;
    init_ptr = init_ptr + 1;
  }
  *(undefined4 *)init_ptr = 0;
  init_ptr = ptr;
  for (j = 5; j != 0; j = j + -1) {
    *init_ptr = 0;
    init_ptr = init_ptr + 1;
  }
  *(undefined *)init_ptr = 0;
  init_ptr = g_password;
  for (j = 12; j != 0; j = j + -1) {
    *init_ptr = 0;
    init_ptr = init_ptr + 1;
  }
// Read password file
  *(undefined4 *)init_ptr = 0;
  fd = (FILE *)0x0;
  size_read = 0;
  fd = fopen("/home/users/level03/.pass","r");
  if (fd == (FILE *)0x0) {
    fwrite("ERROR: failed to open password file\n",1,0x24,stderr);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  i = fread(ptr,1,41,fd);
// get number of bytes read and i = '\n' pos in read str
  size_read = (int)i;
  i = strcspn((char *)ptr,"\n");
  *(undefined *)((long)ptr + i) = 0;
  if (size_read != 41) {
    fwrite("ERROR: failed to read password file\n",1,0x24,stderr);
    fwrite("ERROR: failed to read password file\n",1,0x24,stderr);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  fclose(fd);
  puts("===== [ Secure Access System v1.0 ] =====");
  puts("/***************************************\\");
  puts("| You must login to access this system. |");
  puts("\\**************************************/");
  printf("--[ Username: ");
  fgets((char *)g_user,100,stdin);
// Replace '\n'with '\0'
  i = strcspn((char *)g_user,"\n");
  *(undefined *)((long)g_user + i) = 0;
  printf("--[ Password: ");
  fgets((char *)g_password,100,stdin);
  i = strcspn((char *)g_password,"\n");
  *(undefined *)((long)g_password + i) = 0;
  puts("*****************************************");
// cmp read to input password
  cmp = strncmp((char *)ptr,(char *)g_password,0x29);
  if (cmp == 0) {
    printf("Greetings, %s!\n",g_user);
    system("/bin/sh");
    return 0;
  }
  printf((char *)g_user);
  puts(" does not have access!");
                    /* WARNING: Subroutine does not return */
  exit(1);
}
