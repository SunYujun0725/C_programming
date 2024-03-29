//
//  main.c
//  3.
//
//  Created by 孫渝鈞 on 2020/11/25.
//  Copyright © 2020 孫渝鈞. All rights reserved.
//
/*  probID: MT2A-3-strrev  */
char* strrev(char* s)
{
    /* h指向s的頭部 */
   char* h = s;
   char* t = s;
   char ch;
    /* t指向s的尾部 */
while(*t++){};
    t--;    /* 與t++抵消 */
    t--;    /* 回跳過結束符'\0' */
    /* 當h和t未重合時，交換它們所指向的字元 */
  while(h < t)
  {
     ch = *h;
     *h++ = *t;    /* h向尾部移動 */
     *t-- = ch;    /* t向頭部移動 */
   }
    return(s);
}

/*#include<stdio.h>
char *strrev(char*);
int main(){

    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char tmp[1000];
        scanf("%s",tmp);
        printf("%s\n",strrev(tmp));
    }
    return 0;
}*/

