#ifndef TASK4_H_INCLUDED
#define TASK4_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
void CharToInt6(char a[6],int b[6]);                    //6λ�ַ���ת���� 
void CharToInt4(char a[4],int b[4]);                    //4λ�ַ���ת���� 

int mainFuntion4(char E[6],char ee[6],char hello[4]){
    int EInt[6];
    int eeInt[6];
    int helloInt[4];

	CharToInt6(E,EInt);
    CharToInt6(ee,eeInt);
    CharToInt4(hello,helloInt);

	void happy(int EInt[6],int eeInt[6],int helloInt[4]);          //ʵ��P138��4-2�ĺ���                  
    
//    void s_box(int array[6],int brray[4],int crray[4][16]);    //����des�ѽ��д��8��6���ش��Ĳ�����ÿһ��s�а�6����ӳ�䵽4����
                                                             //��array��������ش���6λ brray��������ش���4λ��crray��s��4X16

    printf("��������������������������������������������������������������������������������������������������������\n");
    
    happy(EInt,eeInt,helloInt);                        
     
    return 0;

} 

void happy(int EInt[6],int eeInt[6],int helloInt[4])
{   //������s��
    int s[4][16]={{14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7}
                ,{0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8}
                ,{4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0}
                ,{15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}
                };
    int b[6]; //���ܵ�����
    int d[6];
    int e[4],f[4],Out[4];
    int flag;
    int l,k;
    int i,j;
    int g,h;
    int p,q;
    int u,v;      //l,k,i,j,g,h,p,q��Ϊѭ������Ҫ�ı��� 
    int count;    //����һ��������
    int in[13][6];
    int test[13][6];
//    void s_box(int array[6],int brray[4],int crray[4][16]);
//    void CharToInt6(char a[6],int b[6]);//6λ�ַ���ת���� 
//    void CharToInt4(char a[4],int b[4]);//4λ�ַ���ת���� 


    int a[6];
	for(i=0; i<6; i++){
		a[i]=EInt[i]^eeInt[i];     //������ 
	} 
        
        count=0;                   //����ǰ������ֲ���ʼ��Ϊ0��
        for(j=0;j<=63;j++)              //����������Ԫ��
        {

            {   int t;                     //b[]Ϊ���ܵ����� 
                t=j;
                b[5]=t%2;  t=t/2;
                b[4]=t%2;  t=t/2;
                b[3]=t%2;  t=t/2;
                b[2]=t%2;  t=t/2;
                b[1]=t%2;  t=t/2;
                b[0]=t%2;
            }
            
            for(l=0;l<6;l++)
               d[l]=b[l]^a[l];         //��������а�λ�������������ǰ���������x��Ӧ��x*��������������d[]��  InΪ������ 
            s_box(b,e,s);               //b������x ��e��s��������Ϊbʱ�����
            s_box(d,f,s);               //d��b���������Ϊin[l]��Ӧ�µ�����x*��f��s��������Ϊbʱ�����
            for(k=0;k<4;k++)
                Out[k]=e[k]^f[k];       //��������֣�����Out������
            flag=1;                     //������־λ��1��
            for(k=0;k<4;k++)
            {
                if(Out[k]!=helloInt[k]) //���������û�����������ֲ�ƥ�� 
                {
                 flag=0;
                 break;
                }
            }
           if(flag==1)  {//���ϵ�ǰ�����ֵ�ʱ�򣬵�ǰ�����ֵļ�������һ
            count=count+1;
                if(count>0){
                	for(int z=0;z<6;z++){   
					//int r=count-1;             
                  in[count-1][z]=b[z];
              }               	
			}
            	
		   }

        }
        in[count][0]=2;  //����count�Ƿ�Ϊ�㣬�������һ�п�ͷ��һ������1��ֵ�����ں����ɸѡ 
        
        printf("���ܵ�����Ϊ��\n");
        if(count==0)printf("����û������Ŀ���ֵ������û����Կ���ϡ�");
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
		
		
		printf("��Կ����Ϊ��\n");
		if(count==0)printf("����û������Ŀ���ֵ������û����Կ���ϡ�");
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
//        p=2*array[0]+array[5];                               //��b1b6���ؾ���s�е���ȡֵΪp
//        q=2*2*2*array[1]+2*2*array[2]+2*array[3]+array[4];   //��b2b3b4b5����s�е���ȡֵΪq
//        t=crray[p][q];                                       //t����s��������Ϊarray[6]ʱ�����
//        brray[3]=t%2;
//        t=t/2;
//        brray[2]=t%2;
//        t=t/2;
//        brray[1]=t%2;
//        t=t/2;
//        brray[0]=t%2;                                        //��tת���ɶ��������洢��brray��
//    }
    
    void CharToInt6(char a[6],int b[6]){
    	for(int q=0;q<6;q++){
             if(a[q]=='0')
             b[q] = 0;
             else b[q] = 1;   //��ֹ�û�������Щ����ֵֹ�����
			 }  
	}
	void CharToInt4(char a[4],int b[4]){
    	for(int q=0;q<4;q++){
             if(a[q]=='0')
             b[q] = 0;
             else b[q] = 1;   //��ֹ�û�������Щ����ֵֹ�����
			 }  
	}


#endif // TASK4_H_INCLUDED
