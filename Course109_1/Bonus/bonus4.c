//
//  main.c
//  Bonus 4
//
//  Created by 孫渝鈞 on 2020/11/12.
//  Copyright © 2020 孫渝鈞. All rights reserved.
//

#include <stdio.h>
#include <math.h>
int main()
{
    int x1,x2,x3,y1,y2,y3,z1,z2,z3;
    scanf("%d %d %d",&x1,&y1,&z1);
    scanf("%d %d %d",&x2,&y2,&z2);
    scanf("%d %d %d",&x3,&y3,&z3);
    int ans;
    ans=(x1*y2*z3)+(x3*y1*z2)+(x2*y3*z1)-(z1*y2*x3)-(x1*y3*z2)-(y1*x2*z3);
    if(ans>=0){
        printf("%d\n",ans);}
    else{
        printf("%d\n",-ans);
    }
    
    
    
    
    return 0;
}
