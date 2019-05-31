//
//  main.cpp
//  作業19
//
//  Created by 劉世翔 on 2019/5/31.
//  Copyright © 2019年 劉世翔. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    printf("請輸入一連串(最多10個)矩形的左上及右下座標：（輸入完畢後請輸入{*}）\n");
    char s[5];
    int w=0;
    double map[11][4];
    int cr[11];
    while(1)
    {
        scanf("%s",s);
        if(s[0]=='*') break;
        if(s[0]=='r')
        {
            scanf("%lf %lf %lf %lf",&map[w][0],&map[w][1],&map[w][2],&map[w][3]);
            cr[w]=1;
        }
        else
        {
            scanf("%lf %lf %lf",&map[w][0],&map[w][1],&map[w][2]);
            cr[w]=0;
        }
        w++;
    }
    int d,e,f,m=0;
    double x,y;
    while(1)
    {
        printf("請輸入座標(x,y)：");
        scanf("%lf %lf",&x,&y);
        if(x==9999.9&&y==9999.9) break;
        int flag=0;
        m++;
        for(d=0;d<w;d++)
        {
            if(cr[d]==1&&x>map[d][0]&&x<map[d][2]&&y<map[d][1]&&y>map[d][3])
            {printf("判斷結果：Point %d is contained in figure %d\n",m,d+1);flag=1;}
            if(cr[d]==0&&sqrt((x-map[d][0])*(x-map[d][0])+(y-map[d][1])*(y-map[d][1]))<map[d][2])
            {printf("判斷結果：Point %d is contained in figure %d\n",m,d+1);flag=1;}
        }
        if(flag==0)
            printf("判斷結果：Point %d is not contained in any figure\n",m);
    }
    return 0;
}
