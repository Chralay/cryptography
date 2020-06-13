#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<string.h>
#include<math.h>
#include"task1.h"
#include"task2.h"
#include"task3.h"
#include"task4.h"

int main(){   
    long long n;
	long long p,q; 
    int chooseNum; 
    printf(" \n\n\n\n\n\n\n                                                    \n");
	printf("                        ################################################################\n");
	printf("                        ##                                                            ##\n");
	printf("                        ##                                                            ##\n");
	printf("                        ##                        rsa的具体任务                       ##\n");
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
	printf("                               @       **     1=任务1   素数平方根测试         **   @\n");
	printf("                               @       **     2=任务2   素数费马测试           **   @\n");
	printf("                               @       **     3=任务3   是否为素数（Miller）   **   @\n");
    printf("                               @       **     4=任务4   RSA算法全过程          **   @\n");
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
            printf("请输入一个待测试的数字:");
	        scanf("%d",&n); 
            mainFuntion1(n);
            system("PAUSE");
			break;

			case 2:
            printf("请输入一个待测试的数字:");
            scanf("%d",&n); 
            mainFuntion2(n);
            system("PAUSE");
			break;

			case 3:
            printf("请输入一个待测试的数字:");
	        scanf("%d",&n);
            mainFuntion3(n);
            system("PAUSE");
            break;

			case 4:
			printf("please enter p and q:\n");
            printf("p:");
            scanf("%lld",&p);
            printf("q:");
            scanf("%lld",&q);
			mainFuntion4(p,q);
            system("PAUSE");
            break;
		}
    system("cls");
     printf("\n\n\n\n\n\n\n                                            请选择任务序号:\n");
	printf("                               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("                               @                                                    @\n");
	printf("                               @       **     1=任务1   素数平方根测试         **   @\n");
	printf("                               @       **     2=任务2   素数费马测试           **   @\n");
	printf("                               @       **     3=任务3   是否为素数（Miller）   **   @\n");
    printf("                               @       **     4=任务4   RSA算法全过程          **   @\n");
	printf("                               @       **     5=        退出                   **   @\n");
    printf("                               @                                                    @\n");
	printf("                               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("                                           请输入您的选择：");
	scanf("%d", &chooseNum);
	getchar();
	}

 return 0;
}
