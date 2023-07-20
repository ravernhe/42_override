void main(void)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  byte bVar4;
  byte buff [100];
  uint i;
  
  bVar4 = 0;
  i = 0;
  fgets((char *)buff,100,stdin);
  i = 0;
  do {
    uVar2 = 0xffffffff;
    pbVar3 = buff;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      bVar1 = *pbVar3;
      pbVar3 = pbVar3 + (uint)bVar4 * -2 + 1;
    } while (bVar1 != 0);
    if (~uVar2 - 1 <= i) {
      printf((char *)buff);
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
  // XOR ^ 32 = xor && xor ^ 32 = XOR
    if (('@' < (char)buff[i]) && ((char)buff[i] < '[')) {
      buff[i] = buff[i] ^ 32;
    }
    i = i + 1;
  } while( true );
}
