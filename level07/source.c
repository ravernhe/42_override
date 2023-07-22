undefined4 read_number(int param_1)
{
  int index;
  
  printf(" Index: ");
  index = get_unum();
  printf(" Number at data[%u] is %u\n",index,*(undefined4 *)(index * 4 + param_1));
  return 0;
}

int store_number(int param_1)
{
  uint num;
  uint index;
  int ret;
  
  printf(" Number: ");
  num = get_unum();
  printf(" Index: ");
  index = get_unum();
  if ((index % 3 == 0) || (num >> 24 == 0xb7)) {
    puts(" *** ERROR! ***");
    puts("   This index is reserved for wil!");
    puts(" *** ERROR! ***");
    ret = 1;
  }
  else {
    *(uint *)(index * 4 + param_1) = num;
    ret = 0;
  }
  return ret;
}

int main(int argc,char **argv,char **envp)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  char *pcVar5;
  byte *pbVar6;
  int in_GS_OFFSET;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  byte bVar10;
  char **_env;
  char **_argv;
  undefined4 local_1bc [100];
  undefined4 ret;
  undefined4 input;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  
  bVar10 = 0;
  _argv = argv;
  _env = envp;
  local_14 = *(int *)(in_GS_OFFSET + 0x14);
  ret = 0;
  input = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  puVar4 = local_1bc;
  for (iVar2 = 100; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  for (; *_argv != (char *)0x0; _argv = _argv + 1) {
    uVar3 = 0xffffffff;
    pcVar5 = *_argv;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + (uint)bVar10 * -2 + 1;
    } while (cVar1 != '\0');
    memset(*_argv,0,~uVar3 - 1);
  }
  for (; *_env != (char *)0x0; _env = _env + 1) {
    uVar3 = 0xffffffff;
    pcVar5 = *_env;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + (uint)bVar10 * -2 + 1;
    } while (cVar1 != '\0');
    memset(*_env,0,~uVar3 - 1);
  }
  puts(
      "----------------------------------------------------\n  Welcome to wil\'s crappy number stora ge service!   \n----------------------------------------------------\n Commands:                                           \n    store - store a number into the data storage    \n    read   - read a number from the data storage     \n    quit  - exit the program                         \n----------------------------------------------------\n   wil has reserved some storage :>                  \n----------------------------------------------------\n"
      );
  do {
    printf("Input command: ");
    ret = 1;
    fgets((char *)&input,0x14,stdin);
    uVar3 = 0xffffffff;
    puVar4 = &input;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *(char *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + (uint)bVar10 * -2 + 1);
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    bVar7 = uVar3 == 1;
    bVar9 = uVar3 == 2;
    *(undefined *)((int)&ret + uVar3 + 2) = 0;
    iVar2 = 5;
    puVar4 = &input;
    pbVar6 = (byte *)"store";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar7 = *(byte *)puVar4 < *pbVar6;
      bVar9 = *(byte *)puVar4 == *pbVar6;
      puVar4 = (undefined4 *)((int)puVar4 + (uint)bVar10 * -2 + 1);
      pbVar6 = pbVar6 + (uint)bVar10 * -2 + 1;
    } while (bVar9);
    bVar8 = false;
    bVar7 = (!bVar7 && !bVar9) == bVar7;
    if (bVar7) {
      ret = store_number((int)local_1bc);
    }
    else {
      iVar2 = 4;
      puVar4 = &input;
      pbVar6 = &DAT_08048d61;
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar8 = *(byte *)puVar4 < *pbVar6;
        bVar7 = *(byte *)puVar4 == *pbVar6;
        puVar4 = (undefined4 *)((int)puVar4 + (uint)bVar10 * -2 + 1);
        pbVar6 = pbVar6 + (uint)bVar10 * -2 + 1;
      } while (bVar7);
      bVar9 = false;
      bVar7 = (!bVar8 && !bVar7) == bVar8;
      if (bVar7) {
        ret = read_number(local_1bc);
      }
      else {
        iVar2 = 4;
        puVar4 = &input;
        pbVar6 = &DAT_08048d66;
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar9 = *(byte *)puVar4 < *pbVar6;
          bVar7 = *(byte *)puVar4 == *pbVar6;
          puVar4 = (undefined4 *)((int)puVar4 + (uint)bVar10 * -2 + 1);
          pbVar6 = pbVar6 + (uint)bVar10 * -2 + 1;
        } while (bVar7);
        if ((!bVar9 && !bVar7) == bVar9) {
          if (local_14 == *(int *)(in_GS_OFFSET + 0x14)) {
            return 0;
          }
                    /* WARNING: Subroutine does not return */
          __stack_chk_fail();
        }
      }
    }
    if (ret == 0) {
      printf(" Completed %s command successfully\n",&input);
    }
    else {
      printf(" Failed to do %s command\n",&input);
    }
    input = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
  } while( true );
}
