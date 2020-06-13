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
	int SecretariesChangeCount = 0;//密文改变的位数
	int output[64]={0}; //密文

    CharToBit(MIN,MINbits,8);//明文转为二进制

    CharToBit(MI,MIbits,8);//密钥转为二进制
    DES_Efun(MIN,MI,output);//加密 先获取未改变明文的密文


    int tempPlaintextbits[64] = {0};
	char tempPlaintext[8] = {0};
    int tempOutput[64] = {0};

    int count = 0;

	printf("*******************************************************\n");
    for(int changeSum=1;changeSum<65;changeSum++){//计算密文位数改变平均值  
     count=0;
     for(int m = 0; m < num; m++){
     	SecretariesChangeCount=0; 
     	
     int randNum =  rand()%64;
     for(int i=0;i<64;i++){tempPlaintextbits[i] = MIbits[i];}//对密钥bits重新赋值
     for(int j=0;j<changeSum;j++){//对密钥的changeSum位进行改变（改变几位）
        if(tempPlaintextbits[(randNum+j)%64]==0)
            tempPlaintextbits[(randNum+j)%64] = 1;
        else tempPlaintextbits[(randNum+j)%64] = 0;
     }
     BitToChar(tempPlaintextbits,tempPlaintext,8);
     DES_Efun(tempPlaintext, MI, tempOutput);//获取密钥改变后的密文   8位而已
     for(int k=0;k<64;k++ ){//比较密文改变的位数
        if(tempOutput[k]!=output[k]) SecretariesChangeCount++;                     
     }
     count+=SecretariesChangeCount;
 }
	 printf("改变%2d位密钥，进行%3d次统计密文平均改变位数为 %f ",changeSum,num,1.0*count/num);
     printf("\n");
	}
    printf("\n*******************************************************\n");
	return 0;

}



#endif // TASK3_H_INCLUDED
