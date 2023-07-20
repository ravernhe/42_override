void clear_stdin(void)

{
  int i;
  
  do {
    i = getchar();
    if ((char)i == '\n') {
      return;
    }
  } while ((char)i != -1);
  return;
}

undefined4 get_unum(void)

{
  undefined4 res [3];
  
  res[0] = 0;
  fflush(stdout);
  __isoc99_scanf(&DAT_080489c0,res);
  clear_stdin();
  return res[0];
}

int decrypt(EVP_PKEY_CTX *diff,uchar *out,size_t *outlen,uchar *in,size_t inlen)

{
  char cVar1;
  uint i;
  int iVar2;
  undefined4 *puVar3;
  byte *gg_str;
  int in_GS_OFFSET;
  bool bVar4;
  bool bVar5;
  uint plus;
  undefined4 s1;
  undefined4 s2;
  undefined4 s3;
  undefined4 s4;
  undefined local_11;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  s1 = 0x757c7d51;
  s2 = 0x67667360;
  s3 = 0x7b66737e;
  s4 = 0x33617c7d;
  local_11 = 0;
  i = 0xffffffff;
  puVar3 = &s1;
  do {
    if (i == 0) break;
    i = i - 1;
    cVar1 = *(char *)puVar3;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
  } while (cVar1 != '\0');
  plus = 0;
  while( true ) {
    bVar4 = plus < ~i - 1;
    bVar5 = plus == ~i - 1;
    if (!bVar4) break;
    *(byte *)((int)&s1 + plus) = (byte)diff ^ *(byte *)((int)&s1 + plus);
    plus = plus + 1;
  }
  iVar2 = 0x11;
  puVar3 = &s1;
  gg_str = (byte *)"Congratulations!";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar4 = *(byte *)puVar3 < *gg_str;
    bVar5 = *(byte *)puVar3 == *gg_str;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
    gg_str = gg_str + 1;
  } while (bVar5);
  if ((!bVar4 && !bVar5) == bVar4) {
    iVar2 = system("/bin/sh");
  }
  else {
    iVar2 = puts("\nInvalid Password");
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

void test(int param_1,int param_2)

{
  EVP_PKEY_CTX *diff;
  uchar *in;
  size_t inlen;
  uchar *out;
  size_t *outlen;
  
  diff = (EVP_PKEY_CTX *)(param_2 - param_1);
  switch(diff) {
  default:
    diff = (EVP_PKEY_CTX *)rand();
    decrypt(diff,out,outlen,in,inlen);
    break;
  case (EVP_PKEY_CTX *)0x1:
    decrypt(diff,out,outlen,in,inlen);
    break;
  case (EVP_PKEY_CTX *)0x2:
    decrypt(diff,out,outlen,in,inlen);
    break;
  case (EVP_PKEY_CTX *)0x3:
    decrypt(diff,out,outlen,in,inlen);
    break;
  case (EVP_PKEY_CTX *)0x4:
    decrypt(diff,out,outlen,in,inlen);
    break;
  case (EVP_PKEY_CTX *)0x5:
    decrypt(diff,out,outlen,in,inlen);
    break;
  case (EVP_PKEY_CTX *)0x6:
    decrypt(diff,out,outlen,in,inlen);
    break;
  case (EVP_PKEY_CTX *)0x7:
    decrypt(diff,out,outlen,in,inlen);
    break;
  case (EVP_PKEY_CTX *)0x8:
    decrypt(diff,out,outlen,in,inlen);
    break;
  case (EVP_PKEY_CTX *)0x9:
    decrypt(diff,out,outlen,in,inlen);
    break;
  case (EVP_PKEY_CTX *)0x10:
    decrypt(diff,out,outlen,in,inlen);
    break;
  case (EVP_PKEY_CTX *)0x11:
    decrypt(diff,out,outlen,in,inlen);
    break;
  case (EVP_PKEY_CTX *)0x12:
    decrypt(diff,out,outlen,in,inlen);
    break;
  case (EVP_PKEY_CTX *)0x13:
    decrypt(diff,out,outlen,in,inlen);
    break;
  case (EVP_PKEY_CTX *)0x14:
    decrypt(diff,out,outlen,in,inlen);
    break;
  case (EVP_PKEY_CTX *)0x15:
    decrypt(diff,out,outlen,in,inlen);
  }
  return;
}

undefined4 main(void)

{
  uint seed;
  int user_input;
  
  seed = time((time_t *)0x0);
  srand(seed);
  puts("***********************************");
  puts("*\t\tlevel03\t\t**");
  puts("***********************************");
  printf("Password:");
  __isoc99_scanf();
  test(user_input,0x1337d00d);
  return 0;
}
