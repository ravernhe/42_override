void secret_backdoor(void)
{
  char buff [128];
  
  fgets(buff,128,_stdin);
  system(buff);
  return;
}

void set_username(long param_1)
{
  long i;
  undefined8 *ptr;
  undefined8 buff [17];
  int j;
  
  ptr = buff;
  for (i = 16; i != 0; i = i + -1) {
    *ptr = 0;
    ptr = ptr + 1;
  }
  puts(">: Enter your username");
  printf(">>: ");
  fgets((char *)buff,128,_stdin);
  for (j = 0; (j < 41 && (*(char *)((long)buff + (long)j) != '\0')); j = j + 1) {
    *(undefined *)(param_1 + 0x8c + (long)j) = *(undefined *)((long)buff + (long)j);
  }
  printf(">: Welcome, %s",param_1 + 0x8c);
  return;
}

void set_msg(char *param_1)
{
  long i;
  undefined8 *ptr;
  undefined8 buff [128];
  
  ptr = buff;
  for (i = 128; i != 0; i = i + -1) {
    *ptr = 0;
    ptr = ptr + 1;
  }
  puts(">: Msg @Unix-Dude");
  printf(">>: ");
  fgets((char *)buff,0x400,_stdin);
  strncpy(param_1,(char *)buff,(long)*(int *)(param_1 + 0xb4));
  return;
}

void handle_msg(void)
{
  undefined local_c8 [140];
  undefined8 local_3c;
  undefined8 local_34;
  undefined8 local_2c;
  undefined8 local_24;
  undefined8 local_1c;
  undefined4 local_14;
  
  local_3c = 0;
  local_34 = 0;
  local_2c = 0;
  local_24 = 0;
  local_1c = 0;
  local_14 = 0x8c;
  set_username(local_c8);
  set_msg(local_c8);
  puts(">: Msg sent!");
  return;
}


int main(void)
{
  puts(
      "--------------------------------------------\n|   ~Welcome to l33t-m$n ~    v1337        |\n- -------------------------------------------"
      );
  handle_msg();
  return 0;
}
