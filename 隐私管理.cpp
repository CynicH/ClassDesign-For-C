
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
typedef struct information{
    int num; //编号
    char location[80]; //账号位置
    char describe[10]; //账号描述
    char name[20]; //账号名
    char password[20]; //密码
    struct information *next;

} info;
int size=sizeof(info);
//添加信息 
info* addInfo(info* head){
	info *p;
	for(p=head; p->next!=NULL; p=p->next){}
	struct information* p1 = (struct information*)malloc(sizeof(struct information));

		printf("请输入编号：\n");
        scanf("%d", &p1->num);
        printf("请输入账号位置：\n");
        scanf("%s", p1->location);
        printf("请输入账号描述：\n");
        scanf("%s", p1->describe);
        printf("请输入账号名：\n");
        scanf("%s", p1->name);
        printf("请输入密码：\n");
        scanf("%s", p1->password);
		p1->next = NULL;
	p->next=p1;
} 

//根据账户名删除结点 
info* Delete(info *head){
	 info *p1,*p2,*p;
	char in[20] ="#";
if(!head){
        printf("还没有录入信息!\n\n");
        return NULL;
    }	
	printf("请输入账号名：");
	 scanf("%s",&in);
	 int flag=0;int count=0;
	for(p=head; p!=NULL; p=p->next){
		if(flag==0)count++; 
	if(strcmp(p->name,in)==0){
        flag = 1;
        printf("------------------------------------------\n");
        printf("|编号|账号位置|账号描述|账号名  |密码    |\n");
		printf("|%-4d|%-8s|%-8s|%-8s|%-8s|\n", p->num, p->location, p->describe, p->name, p->password); 
		printf("-----------------------------------------\n\n");
	if(p->next!=NULL){
		p->num=p->next->num;
	strcpy(p->location,p->next->location);
    strcpy(p->describe,p->next->describe);
    strcpy(p->name,p->next->name);
    strcpy(p->password,p->next->password);
	p->next=p->next->next;	
	}
	else{
		if(p==head){
			return NULL;
		}
		else{
//前置结点位置 
for(p1=head;p1->next!=p;p1=p1->next){
}
p1->next=NULL;
		}


	
	}	

}
}

 
if(flag==0)
                printf("账号不存在！\n\n");
            else{
                printf("删除成功！\n\n");
            }
return head;
}
//根据账户名修改结点信息 
info* Change(info *head){
	if(head==NULL){
        printf("还没有录入信息\n");
        return head;
    }
    info *p;
	char in[20] ="#";
	 printf("请输入要修改的账号名");
	 scanf("%s",&in);
	 int flag=0;
	  for(p=head; p!=NULL; p=p->next){
	if(strcmp(p->name,in)==0){
        flag = 1;
        printf("------------------------------------------\n");
        printf("|编号|账号位置|账号描述|账号名  |密码    |\n");
		printf("|%-4d|%-8s|%-8s|%-8s|%-8s|\n", p->num, p->location, p->describe, p->name, p->password); 
		printf("-----------------------------------------\n\n");
	while(1){
		printf("请选择你要修改的内容：\n");
		printf("1：编号\n");
		printf("2：账号位置：\n");
		printf("3：账号描述：\n");
		printf("4：账号名：\n");
		printf("5：密码：\n");
		int choose;
		scanf("%d",&choose); 
		switch(choose){
			case 1:
			printf("1：编号\n");
			printf("请输入修改后的内容：");	
			scanf("%d", &p->num);
			
				break;
			case 2:
			printf("2：账号位置：\n");	
			printf("请输入修改后的内容：");
			memset(p->location, 0, sizeof(p->location));
            scanf("%s", p->location);
				break;
			case 3:
			printf("3：账号描述：\n");	
			printf("请输入修改后的内容：");
		    memset(p->describe, 0, sizeof(p->describe));
            scanf("%s", p->describe);
				break;
			case 4:
			printf("4：账号名：\n");	
			printf("请输入修改后的内容：");
			memset(p->name, 0, sizeof(p->name));
            scanf("%s", p->name);
				break;
			case 5:
			printf("5：密码：\n");	
			printf("请输入修改后的内容：");
			memset(p->password, 0, sizeof(p->password));
            scanf("%s", p->password);	
				break;
			default:
				printf("无效操作！"); 
				break;		
		}
		printf("修改成功！");
	char con[5];
do{
	    printf("是否继续修改？(Y/N):");
		scanf("%c",&con);
		
	}while(con[0]!='y'&&con[0]!='n');
	if(con[0]=='y'){
			continue;
		}else{
		break;	
		} 
		
	} 	
}}if(flag==0){
	printf("未找到相关信息！\n"); 
}
return head;
}
//根据账户名查找信息 
void search(info *head){
	int flag=0;
	if(head==NULL){
        printf("还没有录入信息！\n\n");
        return;
    }
info *p;
char a[20]="#";
printf("请输入要查找的账号名\n");
scanf("%s",&a);
for(p=head; p!=NULL; p=p->next){
	if(strcmp(p->name,a)==0){
        flag = 1;
        printf("------------------------------------------\n");
        printf("|编号|账号位置|账号描述|账号名  |密码    |\n");
		printf("|%-4d|%-8s|%-8s|%-8s|%-8s|\n", p->num, p->location, p->describe, p->name, p->password); 
		printf("-----------------------------------------\n\n");
}

}if(flag==0){
	printf("未找到相关信息！\n"); 
}}
//显示全部信息 
void printAll(info* head){
	if(head==NULL){
		printf("您还未填入任何信息！");
		return; 
	}
	 else{
        info *p;
        printf("------------------------------------\n");
        printf("|编号|账号位置|账号描述|账号名  |密码    |\n");
        for(p=head; p!=NULL; p=p->next)
            printf("|%-4d|%-8s|%-8s|%-8s|%-8s|\n", p->num, p->location, p->describe, p->name, p->password);
        printf("------------------------------\n\n");
    }
}
//从文件中导入 
void filein(info *head)
{
    FILE *fp;
    info *p;
    int i;
    char file[20];
    printf("请输入文件名:");
    scanf("%s", file);
    if((fp=fopen(file, "w"))==NULL){
        printf("File open error!\n");
        exit(0);
    }
    for(p=head; p!=NULL; p=p->next){
        for(i=0; p->password[i]!='\0'; i++){
        	//加密算法 
            p->password[i] += 64;
        }
        fprintf(fp, "%d     %s     %s     %s     %s\n", p->num, p->location, p->describe, p->name, p->password);
    }
    printf("导入成功!\n\n");
    for(p=head; p!=NULL; p=p->next){
        for(i=0; p->password[i]!='\0'; i++){
            p->password[i] -= 64;
        }
    }
    if(fclose(fp)){
        printf("Can not close the file!\n");
        exit(0);
    }
}
//导出成文件 
info* fileout(info *head)
{
    FILE *fp;
    info *p, *tail;
    int i;
    char file[20];
    printf("请输入文件名：");
    scanf("%s", file);
    if((fp=fopen(file, "r"))==NULL){
        printf("File open error!\n");
        exit(0);
    }
    head = tail = NULL;
    p = (info*)malloc(size);
    fscanf(fp, "%d%s%s%s%s", &p->num, p->location, p->describe, p->name, p->password);
    while(!feof(fp)){
        p->next =NULL;
        if(!head)
            head = p;
        else
            tail->next = p;
        tail = p;
        p = (info*)malloc(size);
        fscanf(fp, "%d%s%s%s%s", &p->num, p->location, p->describe, p->name, p->password);
    }
    for(p=head; p!=NULL; p=p->next){
        for(i=0; p->password[i]!='\0'; i++){
            p->password[i] -= 64;
        }
    }
    printf("导出成功！\n\n");
    if(fclose(fp)){
        printf("Can not close the file!\n");
        exit(0);
    }
 
    return head;
}
//输入数据 
info* add(){
	info*head=NULL,*tail=NULL,*p;
	int flag=1;
	do{
		p = (info*)malloc(size);
		printf("请输入编号：\n");
        scanf("%d", &p->num);
        printf("请输入账号位置：\n");
        scanf("%s", p->location);
        printf("请输入账号描述：\n");
        scanf("%s", p->describe);
        printf("请输入账号名：\n");
        scanf("%s", p->name);
        printf("请输入密码：\n");
        scanf("%s", p->password);
		p->next = NULL;
            if(!head)
                head = p;
            else
                tail->next = p;
            tail = p;
            printf("\n");
		//continue
char con[5];
do{
	    printf("是否继续添加？(Y/N):");
		scanf("%c",&con);
		
	}while(con[0]!='y'&&con[0]!='n');
	if(con[0]=='y'){
			continue;
		}else{
		break;	
		} 
		
	}while(flag);
return head;	
}
//主菜单选择界面 
int select(){
	int n=0;
	printf("\n***请选择你要进行的操作***\n");
	printf("\n---1:浏览全部信息---\n");
	printf("\n---2：录入信息---\n");
	printf("\n---3：按账号名查询信息---\n");
	printf("\n---4：修改信息---\n");
	printf("\n---5：从文件导入信息---\n");
	printf("\n---6：导入信息到文件---\n");
	printf("\n---7：删除信息---\n");
	printf("\n---8：添加信息---\n");
	printf("\n---9：退出---\n");
	scanf("%d",&n);
	return n; 
} 
//隐私管理系统
void Management(){
	info *head=NULL;
	while(1){
		int choose=select();	
		switch(choose){
			case 1:	
			printf("\n---1:浏览全部信息---\n");
			printAll(head);
			break;
			case 2:	
			printf("\n---2：录入信息---\n");
		    head=add();
			break;
			case 3:	
			printf("\n---3：按账号名查询信息---\n");
			search(head);
			break;
			case 4:	
			printf("\n---4：修改信息---\n");
            head = Change(head);
			break;
			case 5:	
			printf("\n---5：从文件导入信息---\n");
			head = fileout(head);

			break;
			case 6:	
			printf("\n---6：导入信息到文件---\n");
			filein(head); 
			break; 
			case 7:	
			printf("\n---7：删除信息---\n");
			head=Delete(head);
			break;
			case 8:	
			printf("\n---8：添加信息---\n");
            addInfo(head);
			break;
			case 9:	
			printf("\n---程序关闭---\n");
			exit(0);
			break;
			default:
                printf("非法操作\n"); 
                break;
			
			
		}
	}
	
	
} 
int main(){
	char code[6]="12345",scan[6];
	printf("------Privacy Management System------\n");
	printf("*************************************\n");
	printf("请输入密码\n");
 for(int i=3;i>0;i--){
 	printf("Password:\n");
 	scanf("%s",&scan);
 	if(strcmp(code, scan)){
 		if(i==1){
 			printf("非法用户，系统退出\n");
			 return 0; 
		 }
		 else{
		 	printf("密码错误，还有%d次机会\n",i-1);
		 }
	 }
 	else{
 		//打开管理系统 
 		printf("欢迎来到隐私管理系统");	
 		Management(); 
 		break;

	 }
 }
	
} 
