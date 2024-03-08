 /*********************************************************************************
 ****  FileName:  demo.c
 ****  Function:  ���ɫbmpͼƬ�ļ��Ĵ���          
 ****  Usage:     demo  xxxx.bmp 
 ****  Author:    xiangdesheng  
 ****  Date:      2010-05-12        
 *********************************************************************************/
#include <CONIO.H>    
#include <STDLIB.H>    
#include <STDIO.H>    
#include <MATH.H>   
#include <MALLOC.H> 
#include <string.h>
   
typedef unsigned char BYTE;   
typedef unsigned short WORD;   
typedef unsigned long DWORD;   
   
/****  The file header of bmp file λͼ�ļ�ͷ*****/
#include <pshpack2.h> //This file turns 2 byte packing of structures on, then sizeof(BITMAPFILEHEADER)=14, otherwise sizeof(BITMAPFILEHEADER)=16
typedef struct tagBITMAPFILEHEADER {   
    WORD bfType;   
    DWORD bfSize;   
    WORD bfReserved1;   
    WORD bfReserved2;
    DWORD bfoffBits;                                                
} BITMAPFILEHEADER; 
#include <poppack.h> //This file turns packing of structures off 
   
/****  The information header of bmp file λͼ��Ϣͷ*****/
typedef struct tagBITMAPINFOHEADER {   
    DWORD biSize;   
    DWORD biWidth;   
    DWORD biHeight;   
    WORD  biPlanes;   
    WORD  biBitCount;      
    DWORD biCompress;
    DWORD biSizeImage;   
    DWORD biXPeIsPerMeter;   
    DWORD biYPeIsPerMeter;   
    DWORD biCIrUsed;   
    DWORD biClrImprotant;   
} BITMAPINFOHEADER;   
   
/****  The RGB data of bmp file ͼ��RGB����*****/
typedef struct tagRGBDATA{   
    BYTE rgbBlue;       
    BYTE rgbGreen; 
	BYTE rgbRed;   
} RGBDATA; 

int main(int argc, char *argv[])
{
	RGBDATA *bmpData=NULL;	//ͼ������ָ��
	FILE *fp;				//BMP�ļ�ָ��
	long i,j,k;
	long width=300;			//ͼ����
	long height=300;		//ͼ��߶�
	long dataSize=width*height;
	BITMAPFILEHEADER bmfHeader;   
	BITMAPINFOHEADER bmiHeader; 

	if(argc<3)
	{
		printf("\n    ��ָ����Ҫ���ɵ�BMP�ļ�����\n");
		printf("\n    ����1����cmd�������룺 demo xxx.txt xxxx.bmp����س�ִ�У�\n");
		printf("\n    ����2����VC�Ĺ�����������Ӳ�����xxx.txt xxxx.bmp����������У�\n");
		printf("\n    ���ܣ� �����趨��������ɫ������ֵ��������ʾ��ͬ�Ĳ�ɫ���ƣ�\n\n");
		exit(0);
	}		
FILE *fq;  
char a[500][500],b[500][500];
int len=0;
//��txt�ļ����������� 
   if((fq=fopen(argv[1],"r"))==NULL)
   {
		printf("�ļ���ʧ�ܣ�\n");
		return 0;
   }
   while(!feof(fq))
		{if(1!=fscanf(fq,"%s",a[len]))
			break;
			len++;
		}
		int i3=0;
		for(i3=0;i3<len;i3++){
			printf("%s\n",a[i3]);
		}
//��01�洢
int lenth=strlen(a[0]);
int i1,j1=0;
for(i1=0;i1<len;i1++){
	int end=0;
	for(j1=0;j1<lenth;j1++){
		if(a[i1][j1]=='_'){
			b[i1][end]='0';end++;
		}
if(a[i1][j1]=='X'){
			b[i1][end]='1';end++;
		}
b[i1][end]=='\0';

	}
printf("%s\n",b[i1]);
}		
fclose(fq);	
	printf("\n    ********************************************************************************\n");
	printf("\n         ��л��ʹ��BMPͼƬ�ļ�����DEMO����                 \n");
	printf("\n             ���ߣ��ο���                 \n");
	printf("\n             ���ڣ�2024��3��3��                 \n");
	printf("\n             Ŀ�ģ�����ӡ�����ɳ���ʱ�����ο���       \n");
	printf("\n             ���ܣ������ض���ӡ��\n\n");
	printf("\n    ********************************************************************************\n\n");



    //��һ�������������и������ļ����½�һBMP�ļ�����ʱ����һ�����ļ�
	if((fp=fopen(argv[2], "wb+"))==NULL)
	{
		printf("Cannot open BMP file!");
		exit(0);
	}


	//�ڶ��������ļ�ͷ���ݲ�д��BMP�ļ�
	bmfHeader.bfType=0x4d42;
	bmfHeader.bfSize=14+40+width*height*3;
	bmfHeader.bfReserved1=0;
	bmfHeader.bfReserved2=0;
	bmfHeader.bfoffBits=0x36;
    fwrite(&bmfHeader, sizeof(BITMAPFILEHEADER), 1, fp);

	//������������Ϣͷ���ݲ�д��BMP�ļ�
	bmiHeader.biSize=40;
	bmiHeader.biWidth=width;
	bmiHeader.biHeight=height;
	bmiHeader.biPlanes=1;
	bmiHeader.biBitCount=24;
	bmiHeader.biCompress=0;
	bmiHeader.biSizeImage=width*height*3;
	bmiHeader.biXPeIsPerMeter=0;
	bmiHeader.biYPeIsPerMeter=0;
	bmiHeader.biCIrUsed=0;
	bmiHeader.biClrImprotant=0;
    fwrite(&bmiHeader, sizeof(BITMAPINFOHEADER), 1, fp);

	//���Ĳ�����ͼ��RGB���ݲ�д��BMP�ļ�
	//�����㹻�ڴ棬��bmpDataָ������ڴ棬���ڴ��ͼ������ص��RGB����ֵ
	if((bmpData=(RGBDATA*)malloc(width*height*3))==NULL)
	{
		printf("bmpData memory malloc error!");
	}	
	//����bmpData��ָ�ڴ�����ͼ��RGB���ݣ�Ȼ����������д��BMP�ļ�
	for(i=0;i<height;i++)
	{
		for(j=0;j<width;j++)
		{
			k=(height-i-1)*width + j;//����bmpͼƬ�е�i�е�j��ͼ��������bmpData[]�����е�λ��
			if(
			//���ñ߿� 
			i>=(height-len)/2&&
			i<=(height/2+len/2)-1&&
			j>=(width-lenth)/2&&
			j<=(width/2+lenth/2)-1&&
			b[i-(height-len)/2][j-(width-lenth)/2]=='0' )
			{
				bmpData[k].rgbBlue=255;
				bmpData[k].rgbGreen=255;
				bmpData[k].rgbRed=255;
			}
			else
				{
					bmpData[k].rgbBlue=0;
					bmpData[k].rgbGreen=0;
					bmpData[k].rgbRed=255;
				}

		}
	}
	fwrite(bmpData,sizeof(RGBDATA),dataSize,fp);//��bmpData��ָ�ڴ��е�RGB����һ����д��BMP�ļ�

	printf("\n    ��ϲ����BMP�ļ��Ѿ��ɹ����ɣ�\n");
	printf("\n    ���ڵ�ǰĿ¼�²鿴���ɵ�BMP�ļ�%s\n\n",argv[1]);

	free(bmpData);	//�ͷ�bmpData��ָ���ڴ�ռ�
	bmpData=NULL;	//��bmpDataΪ��ָ��
	fclose(fp);		//�ر�fp��ָ�ļ�

}
