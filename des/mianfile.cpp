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
	printf("                        ##                          �ĸ�����                          ##\n");
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
	printf("                               @       **     1=����1   ��ַ���               **   @\n");
	printf("                               @       **     2=����2   �ı�����               **   @\n");
	printf("                               @       **     3=����3   �ı���Կ               **   @\n");
    printf("                               @       **     4=����4   �����Կ���ϣ���4-2��  **   @\n");
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
             printf("������6λ��֣�");
             char intput[6];
//             scanf("%s",intput);
			 gets(intput);
             int intputchafen[6];
             for(q=0;q<6;q++){
             if(intput[q]=='0')
             intputchafen[q] = 0;
             else intputchafen[q] = 1;   //��ֹ�û�������Щ����ֵֹ�����
			 }                            
             printf("\n");
             mainFuntion(intputchafen);
             system("PAUSE");
			break;

			case 2:
             printf("������8λ�ַ���Ϊ���ģ�");
             scanf("%s",Ptext);
             printf("\n������8λ�ַ���Ϊ��Կ��");
             scanf("%s",Skey);
             printf("\n��������Ҫͳ�ƵĴ�����");//������ͳ�ƴ���        ���ĸı��λ��
             scanf("%d",&num);//�ĳ�num  changeSum
             mainFuntion2(Ptext,Skey,num);//�ĳ�num   changeSum
             system("PAUSE");
			break;

			case 3:
             printf("������8λ�ַ���Ϊ���ģ�");
             scanf("%s",Ptext);
             printf("\n������8λ�ַ���Ϊ��Կ��");
             scanf("%s",Skey);
             printf("\n��������Ҫͳ�ƵĴ�����");   //��������Կ�ı��λ��
             scanf("%d",&num);
             mainFuntion3(Ptext,Skey,num);
             system("PAUSE");
            break;

			case 4:
			 char E[6];
             char ee[6];       //E* 
             char hello[4];    //������ 
			 printf("s�е�����E:��6λ��");                                  
             gets(E);
//             scanf("%s",E);
			 printf("s�е�����e:��6λ��");   
//			 scanf("%s",ee);                              
			 gets(ee);
			 printf("s�е�������hello:��4λ��");                                
			 gets(hello);
//             scanf("%s",hello);
			 mainFuntion4(E,ee,hello);
             system("PAUSE");
            break;
		}
    system("cls");
    printf("\n\n\n\n\n\n\n                                                 ��ѡ���������:\n");
	printf("                               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("                               @                                                    @\n");
	printf("                               @       **           1=����1 ��ַ���         **     @\n");
	printf("                               @       **           2=����2 �ı�����         **     @\n");
	printf("                               @       **           3=����3 �ı���Կ         **     @\n");
    printf("                               @       **     4=����4 �����Կ���ϣ���4-2��  **     @\n");
	printf("                               @       **           5=�˳�                   **     @\n");
    printf("                               @                                                    @\n");
	printf("                               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("                                           ����������ѡ��");
	scanf("%d", &chooseNum);
	getchar();
	}

 return 0;
}
