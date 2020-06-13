#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<string.h>
#include<math.h>
#include"task11.h"
#include"task22.h"
#include"task33.h"
#include"task44.h"

int main(){

    int chooseNum ;
    char Ptext[8];
    char Skey[8];
    int num;
	int q;

    printf(" \n\n\n\n\n\n\n                                                    \n");
	printf("                        ################################################################\n");
	printf("                        ##                                                            ##\n");
	printf("                        ##                                                            ##\n");
	printf("                        ##                          四个任务                          ##\n");
	printf("                        ##                                                            ##\n");
	printf("                        ##                                                            ##\n");
    printf("                        ##                                                            ##\n");
	printf("                        ################################################################\n\n");
	printf(" 请按任何键以继续 ,, ");
	getchar();
	system("cls");

    printf("\n\n\n\n\n\n\n                                            请选择任务序号:\n");
	printf("                               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("                               @                                                    @\n");
	printf("                               @       **     1=任务1   差分分析               **   @\n");
	printf("                               @       **     2=任务2   改变明文               **   @\n");
	printf("                               @       **     3=任务3   改变秘钥               **   @\n");
    printf("                               @       **     4=任务4   输出密钥集合（例4-2）  **   @\n");
	printf("                               @       **     5=        退出                   **   @\n");
    printf("                               @                                                    @\n");
	printf("                               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("                                           请输入您的选择：");
	scanf("%d", &chooseNum);
	getchar();

	   while (chooseNum != 5)
	{
		switch (chooseNum)
		{
			case 1:
             printf("请输入6位差分：");
             char intput[6];
//             scanf("%s",intput);
			 gets(intput);
             int intputchafen[6];
             for(q=0;q<6;q++){
             if(intput[q]=='0')
             intputchafen[q] = 0;
             else intputchafen[q] = 1;   //防止用户输入了些奇奇怪怪的数字
			 }                            
             printf("\n");
             mainFuntion(intputchafen);
             system("PAUSE");
			break;

			case 2:
             printf("请输入8位字符作为明文：");
             scanf("%s",Ptext);
             printf("\n请输入8位字符作为秘钥：");
             scanf("%s",Skey);
             printf("\n请输入需要统计的次数：");//请输入统计次数        明文改变的位数
             scanf("%d",&num);//改成num  changeSum
             mainFuntion2(Ptext,Skey,num);//改成num   changeSum
             system("PAUSE");
			break;

			case 3:
             printf("请输入8位字符作为明文：");
             scanf("%s",Ptext);
             printf("\n请输入8位字符作为秘钥：");
             scanf("%s",Skey);
             printf("\n请输入需要统计的次数：");   //请输入秘钥改变的位数
             scanf("%d",&num);
             mainFuntion3(Ptext,Skey,num);
             system("PAUSE");
            break;

			case 4:
			 char E[6];
             char ee[6];       //E* 
             char hello[4];    //输出差分 
			 printf("s盒的输入E:（6位）");                                  
             gets(E);
//             scanf("%s",E);
			 printf("s盒的输入e:（6位）");   
//			 scanf("%s",ee);                              
			 gets(ee);
			 printf("s盒的输出差分hello:（4位）");                                
			 gets(hello);
//             scanf("%s",hello);
			 mainFuntion4(E,ee,hello);
             system("PAUSE");
            break;
		}
    system("cls");
    printf("\n\n\n\n\n\n\n                                                 请选择任务序号:\n");
	printf("                               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("                               @                                                    @\n");
	printf("                               @       **           1=任务1 差分分析         **     @\n");
	printf("                               @       **           2=任务2 改变明文         **     @\n");
	printf("                               @       **           3=任务3 改变秘钥         **     @\n");
    printf("                               @       **     4=任务4 输出密钥集合（例4-2）  **     @\n");
	printf("                               @       **           5=退出                   **     @\n");
    printf("                               @                                                    @\n");
	printf("                               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("                                           请输入您的选择：");
	scanf("%d", &chooseNum);
	getchar();
	}

 return 0;
}
