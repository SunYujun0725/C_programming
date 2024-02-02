//
//  main.c
//  HW W15-2-2
//
//  Created by 孫渝鈞 on 2020/12/19.
//  Copyright © 2020 孫渝鈞. All rights reserved.
//
/* probID: 15-2-BufferedGetchar */
#include <string.h>
#include <stdio.h>
char _my_buffer;
int _is_my_buffer_filled = 0;

char peek_next_char(){
    if(_is_my_buffer_filled==0){
        _my_buffer = getchar();
        _is_my_buffer_filled=1;
    }
    return _my_buffer;
    
}
char my_getchar(){
    if(_is_my_buffer_filled==1){
        _is_my_buffer_filled=0;
        return _my_buffer;
    }
    return getchar();
}


/*#include <stdio.h>

char peek_next_char(), my_getchar();

int main(){
    char cmd[(int)1e4],ch;
    
    scanf("%s",cmd);
    while( (ch=getchar()) != '\n' )
        ;
    
    char *ptr = cmd;
    while( *ptr )
    {
        if( *ptr == 'P' )
            putchar(peek_next_char());
        else if( *ptr == 'G' )
            putchar(my_getchar());
            
        ptr++;
    }
    
    return 0;
}*/
