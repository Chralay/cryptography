#ifndef TASK3_H_INCLUDED
#define TASK3_H_INCLUDED

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>

int mainFuntion3(char MIN[8],char MI[8],int num)
{
    srand((unsigned)time(NULL));

	int MINbits[64]={0};
	int MIbits[64]={0};
	int SecretariesChangeCount = 0;//���ĸı��λ��
	int output[64]={0}; //����

    CharToBit(MIN,MINbits,8);//����תΪ������

    CharToBit(MI,MIbits,8);//��ԿתΪ������
    DES_Efun(MIN,MI,output);//���� �Ȼ�ȡδ�ı����ĵ�����


    int tempPlaintextbits[64] = {0};
	char tempPlaintext[8] = {0};
    int tempOutput[64] = {0};

    int count = 0;

	printf("*******************************************************\n");
    for(int changeSum=1;changeSum<65;changeSum++){//��������λ���ı�ƽ��ֵ  
     count=0;
     for(int m = 0; m < num; m++){
     	SecretariesChangeCount=0; 
     	
     int randNum =  rand()%64;
     for(int i=0;i<64;i++){tempPlaintextbits[i] = MIbits[i];}//����Կbits���¸�ֵ
     for(int j=0;j<changeSum;j++){//����Կ��changeSumλ���иı䣨�ı伸λ��
        if(tempPlaintextbits[(randNum+j)%64]==0)
            tempPlaintextbits[(randNum+j)%64] = 1;
        else tempPlaintextbits[(randNum+j)%64] = 0;
     }
     BitToChar(tempPlaintextbits,tempPlaintext,8);
     DES_Efun(tempPlaintext, MI, tempOutput);//��ȡ��Կ�ı�������   8λ����
     for(int k=0;k<64;k++ ){//�Ƚ����ĸı��λ��
        if(tempOutput[k]!=output[k]) SecretariesChangeCount++;                     
     }
     count+=SecretariesChangeCount;
 }
	 printf("�ı�%2dλ��Կ������%3d��ͳ������ƽ���ı�λ��Ϊ %f ",changeSum,num,1.0*count/num);
     printf("\n");
	}
    printf("\n*******************************************************\n");
	return 0;

}



#endif // TASK3_H_INCLUDED
