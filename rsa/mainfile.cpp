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
	printf("                        ##                        rsa�ľ�������                       ##\n");
	printf("                        ##                                                            ##\n");
	printf("                        ##                                                            ##\n");
    printf("                        ##                                                            ##\n");
	printf("                        ################################################################\n\n");
	printf(" �밴�κμ��Լ��� ,, ");
	getchar();
	system("cls");

    printf("\n\n\n\n\n\n\n                                            ��ѡ���������:\n");
	printf("                               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("                               @                                                    @\n");
	printf("                               @       **     1=����1   ����ƽ��������         **   @\n");
	printf("                               @       **     2=����2   �����������           **   @\n");
	printf("                               @       **     3=����3   �Ƿ�Ϊ������Miller��   **   @\n");
    printf("                               @       **     4=����4   RSA�㷨ȫ����          **   @\n");
	printf("                               @       **     5=        �˳�                   **   @\n");
    printf("                               @                                                    @\n");
	printf("                               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("                                           ����������ѡ��");
	scanf("%d", &chooseNum);
	getchar();

	   while (chooseNum != 5)
	{
		switch (chooseNum)
		{
			case 1:
            printf("������һ�������Ե�����:");
	        scanf("%d",&n); 
            mainFuntion1(n);
            system("PAUSE");
			break;

			case 2:
            printf("������һ�������Ե�����:");
            scanf("%d",&n); 
            mainFuntion2(n);
            system("PAUSE");
			break;

			case 3:
            printf("������һ�������Ե�����:");
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
     printf("\n\n\n\n\n\n\n                                            ��ѡ���������:\n");
	printf("                               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("                               @                                                    @\n");
	printf("                               @       **     1=����1   ����ƽ��������         **   @\n");
	printf("                               @       **     2=����2   �����������           **   @\n");
	printf("                               @       **     3=����3   �Ƿ�Ϊ������Miller��   **   @\n");
    printf("                               @       **     4=����4   RSA�㷨ȫ����          **   @\n");
	printf("                               @       **     5=        �˳�                   **   @\n");
    printf("                               @                                                    @\n");
	printf("                               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("                                           ����������ѡ��");
	scanf("%d", &chooseNum);
	getchar();
	}

 return 0;
}
