#ifndef TASK4_H_INCLUDED
#define TASK4_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
void CharToInt6(char a[6],int b[6]);                    //6位字符型转整型 
void CharToInt4(char a[4],int b[4]);                    //4位字符型转整型 

int mainFuntion4(char E[6],char ee[6],char hello[4]){
    int EInt[6];
    int eeInt[6];
    int helloInt[4];

	CharToInt6(E,EInt);
    CharToInt6(ee,eeInt);
    CharToInt4(hello,helloInt);

	void happy(int EInt[6],int eeInt[6],int helloInt[4]);          //实现P138例4-2的函数                  
    
//    void s_box(int array[6],int brray[4],int crray[4][16]);    //根据des把结果写成8个6比特串的并联，每一个s盒把6比特映射到4比特
                                                             //则array是输入比特串是6位 brray是输出比特串是4位，crray是s盒4X16

    printf("————————————————————————————————————————————————————\n");
    
    happy(EInt,eeInt,helloInt);                        
     
    return 0;

} 

void happy(int EInt[6],int eeInt[6],int helloInt[4])
{   //定义了s盒
    int s[4][16]={{14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7}
                ,{0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8}
                ,{4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0}
                ,{15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}
                };
    int b[6]; //可能的输入
    int d[6];
    int e[4],f[4],Out[4];
    int flag;
    int l,k;
    int i,j;
    int g,h;
    int p,q;
    int u,v;      //l,k,i,j,g,h,p,q均为循环所需要的变量 
    int count;    //定义一个计数器
    int in[13][6];
    int test[13][6];
//    void s_box(int array[6],int brray[4],int crray[4][16]);
//    void CharToInt6(char a[6],int b[6]);//6位字符型转整型 
//    void CharToInt4(char a[4],int b[4]);//4位字符型转整型 


    int a[6];
	for(i=0; i<6; i++){
		a[i]=EInt[i]^eeInt[i];     //输入差分 
	} 
        
        count=0;                   //将当前输出异或分布初始化为0次
        for(j=0;j<=63;j++)              //遍历输入六元组
        {

            {   int t;                     //b[]为可能的输入 
                t=j;
                b[5]=t%2;  t=t/2;
                b[4]=t%2;  t=t/2;
                b[3]=t%2;  t=t/2;
                b[2]=t%2;  t=t/2;
                b[1]=t%2;  t=t/2;
                b[0]=t%2;
            }
            
            for(l=0;l<6;l++)
               d[l]=b[l]^a[l];         //将数组进行按位异或操作，求出当前输入异或下x对应的x*，并保存在数组d[]中  In为输入差分 
            s_box(b,e,s);               //b是输入x ，e是s盒在输入为b时的输出
            s_box(d,f,s);               //d是b在输入异或为in[l]对应下的输入x*，f是s盒在输入为b时的输出
            for(k=0;k<4;k++)
                Out[k]=e[k]^f[k];       //求出输出差分，存在Out数组中
            flag=1;                     //并将标志位置1；
            for(k=0;k<4;k++)
            {
                if(Out[k]!=helloInt[k]) //输出差分与用户输入的输入差分不匹配 
                {
                 flag=0;
                 break;
                }
            }
           if(flag==1)  {//符合当前输出差分的时候，当前输出差分的计数器加一
            count=count+1;
                if(count>0){
                	for(int z=0;z<6;z++){   
					//int r=count-1;             
                  in[count-1][z]=b[z];
              }               	
			}
            	
		   }

        }
        in[count][0]=2;  //无论count是否为零，最后都在下一行开头赋一个大于1的值。用于后面的筛选 
        
        printf("可能的输入为：\n");
        if(count==0)printf("由于没有输入的可能值，所以没有密钥集合。");
        else{
        	for(g=0;g<13;g++){
        	if(in[g][0]>1)
				break;
        	else{
        		for(h=0;h<6;h++)
				{
        		  printf(" %d ",in[g][h]);       		  
        		  if((h+1)%6==0)
					printf("\n");
				}	
			}
	      }
		} 
		
		for(p=0;p<13;p++){
			for(q=0;q<6;q++)
			{
				test[p][q]=in[p][q]^EInt[q];
			}
		}
		
		
		printf("密钥可能为：\n");
		if(count==0)printf("由于没有输入的可能值，所以没有密钥集合。");
		else {
			for(u=0;u<13;u++){
			if(in[u][0]>1)
				break;
        	else{
        		for(v=0;v<6;v++)
				{
        		  printf(" %d ",test[u][v]);
        		  if((v+1)%6==0)
					printf("\n");
				}	
			}
	      }
		}
    }



//    void s_box(int array[6],int brray[4],int crray[4][16])
//    {
//        int p,q,t;
//        p=2*array[0]+array[5];                               //用b1b6比特决定s盒的行取值为p
//        q=2*2*2*array[1]+2*2*array[2]+2*array[3]+array[4];   //用b2b3b4b5决定s盒的列取值为q
//        t=crray[p][q];                                       //t就是s盒在输入为array[6]时的输出
//        brray[3]=t%2;
//        t=t/2;
//        brray[2]=t%2;
//        t=t/2;
//        brray[1]=t%2;
//        t=t/2;
//        brray[0]=t%2;                                        //把t转换成二进制数存储在brray中
//    }
    
    void CharToInt6(char a[6],int b[6]){
    	for(int q=0;q<6;q++){
             if(a[q]=='0')
             b[q] = 0;
             else b[q] = 1;   //防止用户输入了些奇奇怪怪的数字
			 }  
	}
	void CharToInt4(char a[4],int b[4]){
    	for(int q=0;q<4;q++){
             if(a[q]=='0')
             b[q] = 0;
             else b[q] = 1;   //防止用户输入了些奇奇怪怪的数字
			 }  
	}


#endif // TASK4_H_INCLUDED
