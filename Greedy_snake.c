#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h> 
char x[10][20]; //定义一个二维数组 
int H[20];
int Z[20];      //分别定义两个一位数组，数组元素用来记录蛇身的横纵坐标 
int i,j;
int h,v;//分别代表 食物的横纵坐标  
char ch = 'd';  
int len = 3;
char f; //方向  

void createFood()//生成食物
{   
	h = rand() % 10;
	v = rand() % 20;
	if (x[h][v] == 'O')//蛇身体 
	{
		createFood();
	}
	else
		x[h][v] = '$';
}
void print()
{
	for (i = 0; i <len; i++)//将数组中记录的蛇身坐标全部填充为 O
	{
		x[H[i]][Z[i]] = 'O';
	}
	for (i = 0; i< 10; i++)//用遍历的形式绘制
	{
         for(j=0;j<20;j++)
		    printf("%c",x[i][j]) ;
		 printf("\n");
	}
	Sleep(500);//休眠0.5秒 相当于蛇0.5秒动一下
	system("cls");//清屏函数。。以便将蛇身重新绘制
}
void getkey()//判断是否按下键盘
{
	if (kbhit())//如果按下键盘，就会执行以下语句
	{
		ch = getch();//获取键盘值
		if (ch == f)//如果这次按键和现在走的方向一致则为无效按键，重新来获取按下的键盘值
		{
			getkey();
		}
		else if ((ch == 'd'&& f != 'a') || ch == 'w' && f != 's' || ch == 'a' && f != 'd' || ch == 's' && f != 'w') //即来判断其他无效按键（即朝左走时不能让其朝右走等等）
			f = ch;//按键有效时将ch赋值为f
		else
			getkey();//按键无效时重新捕获键盘
	}
}
void left()
{
	x[H[0]][Z[0]] = '-';
	for (i = 0; i <len - 1; i++)//蛇身全部前进一格
	{
		Z[i] = Z[i + 1];
		H[i] = H[i + 1];
	}
	Z[len-1]--;
}
void right()
{
	x[H[0]][Z[0]] = '-';
	for (i = 0; i <len - 1; i++)//蛇身全部前进一格
	{
		Z[i] = Z[i + 1];
		H[i] = H[i + 1];
	}
	Z[len-1]++;
}
void up()
{
	x[H[0]][Z[0]] = '-';
	for (i = 0; i <len-1; i++)//蛇身全部前进一格
	{
		Z[i] = Z[i + 1];
		H[i] = H[i + 1];
	}
	H[len-1]--;
}
void down()
{
	x[H[0]][Z[0]] = '-';
	for (i = 0; i <len - 1; i++)//蛇身全部前进一格
	{
		Z[i] = Z[i + 1];
		H[i] = H[i + 1];
	}
	H[len-1]++;
}
int main()
{
	f = ch;//将初始的移动方向赋值给f
	for (i = 0; i < 10; i++) //将字符数组全部以'-'填充，进行初始化
	{
		for (j = 0; j < 20; j++)
		{
			x[i][j] = '-';
		}
	}
	for (i = 0; i <20; i++)//将储存坐标的数组全部归零
	{
		Z[i] = 0;
		H[i] = 0;
	}
	for (i = 0; i <len; i++)//记录前3个蛇身坐标
		Z[i] = i;
		
	createFood();
	
	while (len<=15)//设置蛇的最大长度来赢得游戏
	{
		getkey();
		if (x[h][v]!='$')//食物没有了才生成食物
		{
          createFood();
		}
		switch (f)  //判断方向 
		{
		case 'w':
			  if(H[len-1]==0)
			 {
			  printf("碰到上墙了\n");
		      return 0;
             }
			else if (H[len-1]-1==h&&Z[len-1]==v)//判断蛇要走的下个点是否是食物的点
			 {
				 H[len]=h;
				 Z[len]=v;
				 len++;
				 break;
			 }
			up();
			break;
		case 'a':
			if(Z[len-1]-1<0)
			{
			printf("碰到左墙了\n");
		    return 0;
			}
            else if (H[len-1]==h&&Z[len-1]-1==v)
			 {
				 H[len]=h;
				 Z[len]=v;
				 len++;
				 break;
			 }
			left();
			break;
		case 's':
			if(H[len-1]+1>=10)
			{
			printf("碰到下墙了\n");
		    return 0;
			}
			if (H[len-1]+1==h&&Z[len-1]==v)
			 {
				 H[len]=h;
				 Z[len]=v;
				 len++;
				 break;
			 }
			down();
			break;
		case 'd':
			if(Z[len-1]+1>=20)
			{
			printf("碰到右墙了\n");
		    return 0;
			}
			if (H[len-1]==h&&Z[len-1]+1==v)
			 {
				 H[len]=h;
				 Z[len]=v;
				 len++;
				 break;
			 }
			right();
			break;
		}
		print();
	}
	
    printf("You win!\n");
    
	system("pause");
	return 0;
}

