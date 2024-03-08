 /*********************************************************************************
 ****  FileName:  demo.c
 ****  Function:  真彩色bmp图片文件的创建          
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
   
/****  The file header of bmp file 位图文件头*****/
#include <pshpack2.h> //This file turns 2 byte packing of structures on, then sizeof(BITMAPFILEHEADER)=14, otherwise sizeof(BITMAPFILEHEADER)=16
typedef struct tagBITMAPFILEHEADER {   
    WORD bfType;   
    DWORD bfSize;   
    WORD bfReserved1;   
    WORD bfReserved2;
    DWORD bfoffBits;                                                
} BITMAPFILEHEADER; 
#include <poppack.h> //This file turns packing of structures off 
   
/****  The information header of bmp file 位图信息头*****/
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
   
/****  The RGB data of bmp file 图像RGB数据*****/
typedef struct tagRGBDATA{   
    BYTE rgbBlue;       
    BYTE rgbGreen; 
	BYTE rgbRed;   
} RGBDATA; 

int main(int argc, char *argv[])
{
	RGBDATA *bmpData=NULL;	//图像数据指针
	FILE *fp;				//BMP文件指针
	long i,j,k;
	long width=300;			//图像宽度
	long height=300;		//图像高度
	long dataSize=width*height;
	BITMAPFILEHEADER bmfHeader;   
	BITMAPINFOHEADER bmiHeader; 

	if(argc<3)
	{
		printf("\n    请指定您要生成的BMP文件名！\n");
		printf("\n    方法1：在cmd窗口输入： demo xxx.txt xxxx.bmp　后回车执行！\n");
		printf("\n    方法2：在VC的工程设置中添加参数：xxx.txt xxxx.bmp　后编译运行！\n");
		printf("\n    功能： 根据设定红绿蓝三色分量的值，控制显示不同的彩色条纹！\n\n");
		exit(0);
	}		
FILE *fq;  
char a[500][500],b[500][500];
int len=0;
//将txt文件导入数组中 
   if((fq=fopen(argv[1],"r"))==NULL)
   {
		printf("文件打开失败！\n");
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
//用01存储
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
	printf("\n         感谢您使用BMP图片文件制作DEMO程序                 \n");
	printf("\n             作者：何俊逸                 \n");
	printf("\n             日期：2024年3月3日                 \n");
	printf("\n             目的：编制印章生成程序时，供参考！       \n");
	printf("\n             功能：生成特定的印章\n\n");
	printf("\n    ********************************************************************************\n\n");



    //第一步：用命令行中给出的文件名新建一BMP文件，此时还是一个空文件
	if((fp=fopen(argv[2], "wb+"))==NULL)
	{
		printf("Cannot open BMP file!");
		exit(0);
	}


	//第二步：置文件头数据并写入BMP文件
	bmfHeader.bfType=0x4d42;
	bmfHeader.bfSize=14+40+width*height*3;
	bmfHeader.bfReserved1=0;
	bmfHeader.bfReserved2=0;
	bmfHeader.bfoffBits=0x36;
    fwrite(&bmfHeader, sizeof(BITMAPFILEHEADER), 1, fp);

	//第三步：置信息头数据并写入BMP文件
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

	//第四步：置图像RGB数据并写入BMP文件
	//分配足够内存，让bmpData指向这块内存，用于存放图像各象素点的RGB分量值
	if((bmpData=(RGBDATA*)malloc(width*height*3))==NULL)
	{
		printf("bmpData memory malloc error!");
	}	
	//先在bmpData所指内存中置图像RGB数据，然后将所有数据写入BMP文件
	for(i=0;i<height;i++)
	{
		for(j=0;j<width;j++)
		{
			k=(height-i-1)*width + j;//计算bmp图片中第i行第j列图像数据在bmpData[]数组中的位置
			if(
			//设置边框 
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
	fwrite(bmpData,sizeof(RGBDATA),dataSize,fp);//将bmpData所指内存中的RGB数据一次性写入BMP文件

	printf("\n    恭喜您！BMP文件已经成功生成！\n");
	printf("\n    请在当前目录下查看生成的BMP文件%s\n\n",argv[1]);

	free(bmpData);	//释放bmpData所指的内存空间
	bmpData=NULL;	//置bmpData为空指针
	fclose(fp);		//关闭fp所指文件

}
