
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
typedef struct information{
    int num; //���
    char location[80]; //�˺�λ��
    char describe[10]; //�˺�����
    char name[20]; //�˺���
    char password[20]; //����
    struct information *next;

} info;
int size=sizeof(info);
//�����Ϣ 
info* addInfo(info* head){
	info *p;
	for(p=head; p->next!=NULL; p=p->next){}
	struct information* p1 = (struct information*)malloc(sizeof(struct information));

		printf("�������ţ�\n");
        scanf("%d", &p1->num);
        printf("�������˺�λ�ã�\n");
        scanf("%s", p1->location);
        printf("�������˺�������\n");
        scanf("%s", p1->describe);
        printf("�������˺�����\n");
        scanf("%s", p1->name);
        printf("���������룺\n");
        scanf("%s", p1->password);
		p1->next = NULL;
	p->next=p1;
} 

//�����˻���ɾ����� 
info* Delete(info *head){
	 info *p1,*p2,*p;
	char in[20] ="#";
if(!head){
        printf("��û��¼����Ϣ!\n\n");
        return NULL;
    }	
	printf("�������˺�����");
	 scanf("%s",&in);
	 int flag=0;int count=0;
	for(p=head; p!=NULL; p=p->next){
		if(flag==0)count++; 
	if(strcmp(p->name,in)==0){
        flag = 1;
        printf("------------------------------------------\n");
        printf("|���|�˺�λ��|�˺�����|�˺���  |����    |\n");
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
//ǰ�ý��λ�� 
for(p1=head;p1->next!=p;p1=p1->next){
}
p1->next=NULL;
		}


	
	}	

}
}

 
if(flag==0)
                printf("�˺Ų����ڣ�\n\n");
            else{
                printf("ɾ���ɹ���\n\n");
            }
return head;
}
//�����˻����޸Ľ����Ϣ 
info* Change(info *head){
	if(head==NULL){
        printf("��û��¼����Ϣ\n");
        return head;
    }
    info *p;
	char in[20] ="#";
	 printf("������Ҫ�޸ĵ��˺���");
	 scanf("%s",&in);
	 int flag=0;
	  for(p=head; p!=NULL; p=p->next){
	if(strcmp(p->name,in)==0){
        flag = 1;
        printf("------------------------------------------\n");
        printf("|���|�˺�λ��|�˺�����|�˺���  |����    |\n");
		printf("|%-4d|%-8s|%-8s|%-8s|%-8s|\n", p->num, p->location, p->describe, p->name, p->password); 
		printf("-----------------------------------------\n\n");
	while(1){
		printf("��ѡ����Ҫ�޸ĵ����ݣ�\n");
		printf("1�����\n");
		printf("2���˺�λ�ã�\n");
		printf("3���˺�������\n");
		printf("4���˺�����\n");
		printf("5�����룺\n");
		int choose;
		scanf("%d",&choose); 
		switch(choose){
			case 1:
			printf("1�����\n");
			printf("�������޸ĺ�����ݣ�");	
			scanf("%d", &p->num);
			
				break;
			case 2:
			printf("2���˺�λ�ã�\n");	
			printf("�������޸ĺ�����ݣ�");
			memset(p->location, 0, sizeof(p->location));
            scanf("%s", p->location);
				break;
			case 3:
			printf("3���˺�������\n");	
			printf("�������޸ĺ�����ݣ�");
		    memset(p->describe, 0, sizeof(p->describe));
            scanf("%s", p->describe);
				break;
			case 4:
			printf("4���˺�����\n");	
			printf("�������޸ĺ�����ݣ�");
			memset(p->name, 0, sizeof(p->name));
            scanf("%s", p->name);
				break;
			case 5:
			printf("5�����룺\n");	
			printf("�������޸ĺ�����ݣ�");
			memset(p->password, 0, sizeof(p->password));
            scanf("%s", p->password);	
				break;
			default:
				printf("��Ч������"); 
				break;		
		}
		printf("�޸ĳɹ���");
	char con[5];
do{
	    printf("�Ƿ�����޸ģ�(Y/N):");
		scanf("%c",&con);
		
	}while(con[0]!='y'&&con[0]!='n');
	if(con[0]=='y'){
			continue;
		}else{
		break;	
		} 
		
	} 	
}}if(flag==0){
	printf("δ�ҵ������Ϣ��\n"); 
}
return head;
}
//�����˻���������Ϣ 
void search(info *head){
	int flag=0;
	if(head==NULL){
        printf("��û��¼����Ϣ��\n\n");
        return;
    }
info *p;
char a[20]="#";
printf("������Ҫ���ҵ��˺���\n");
scanf("%s",&a);
for(p=head; p!=NULL; p=p->next){
	if(strcmp(p->name,a)==0){
        flag = 1;
        printf("------------------------------------------\n");
        printf("|���|�˺�λ��|�˺�����|�˺���  |����    |\n");
		printf("|%-4d|%-8s|%-8s|%-8s|%-8s|\n", p->num, p->location, p->describe, p->name, p->password); 
		printf("-----------------------------------------\n\n");
}

}if(flag==0){
	printf("δ�ҵ������Ϣ��\n"); 
}}
//��ʾȫ����Ϣ 
void printAll(info* head){
	if(head==NULL){
		printf("����δ�����κ���Ϣ��");
		return; 
	}
	 else{
        info *p;
        printf("------------------------------------\n");
        printf("|���|�˺�λ��|�˺�����|�˺���  |����    |\n");
        for(p=head; p!=NULL; p=p->next)
            printf("|%-4d|%-8s|%-8s|%-8s|%-8s|\n", p->num, p->location, p->describe, p->name, p->password);
        printf("------------------------------\n\n");
    }
}
//���ļ��е��� 
void filein(info *head)
{
    FILE *fp;
    info *p;
    int i;
    char file[20];
    printf("�������ļ���:");
    scanf("%s", file);
    if((fp=fopen(file, "w"))==NULL){
        printf("File open error!\n");
        exit(0);
    }
    for(p=head; p!=NULL; p=p->next){
        for(i=0; p->password[i]!='\0'; i++){
        	//�����㷨 
            p->password[i] += 64;
        }
        fprintf(fp, "%d     %s     %s     %s     %s\n", p->num, p->location, p->describe, p->name, p->password);
    }
    printf("����ɹ�!\n\n");
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
//�������ļ� 
info* fileout(info *head)
{
    FILE *fp;
    info *p, *tail;
    int i;
    char file[20];
    printf("�������ļ�����");
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
    printf("�����ɹ���\n\n");
    if(fclose(fp)){
        printf("Can not close the file!\n");
        exit(0);
    }
 
    return head;
}
//�������� 
info* add(){
	info*head=NULL,*tail=NULL,*p;
	int flag=1;
	do{
		p = (info*)malloc(size);
		printf("�������ţ�\n");
        scanf("%d", &p->num);
        printf("�������˺�λ�ã�\n");
        scanf("%s", p->location);
        printf("�������˺�������\n");
        scanf("%s", p->describe);
        printf("�������˺�����\n");
        scanf("%s", p->name);
        printf("���������룺\n");
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
	    printf("�Ƿ������ӣ�(Y/N):");
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
//���˵�ѡ����� 
int select(){
	int n=0;
	printf("\n***��ѡ����Ҫ���еĲ���***\n");
	printf("\n---1:���ȫ����Ϣ---\n");
	printf("\n---2��¼����Ϣ---\n");
	printf("\n---3�����˺�����ѯ��Ϣ---\n");
	printf("\n---4���޸���Ϣ---\n");
	printf("\n---5�����ļ�������Ϣ---\n");
	printf("\n---6��������Ϣ���ļ�---\n");
	printf("\n---7��ɾ����Ϣ---\n");
	printf("\n---8�������Ϣ---\n");
	printf("\n---9���˳�---\n");
	scanf("%d",&n);
	return n; 
} 
//��˽����ϵͳ
void Management(){
	info *head=NULL;
	while(1){
		int choose=select();	
		switch(choose){
			case 1:	
			printf("\n---1:���ȫ����Ϣ---\n");
			printAll(head);
			break;
			case 2:	
			printf("\n---2��¼����Ϣ---\n");
		    head=add();
			break;
			case 3:	
			printf("\n---3�����˺�����ѯ��Ϣ---\n");
			search(head);
			break;
			case 4:	
			printf("\n---4���޸���Ϣ---\n");
            head = Change(head);
			break;
			case 5:	
			printf("\n---5�����ļ�������Ϣ---\n");
			head = fileout(head);

			break;
			case 6:	
			printf("\n---6��������Ϣ���ļ�---\n");
			filein(head); 
			break; 
			case 7:	
			printf("\n---7��ɾ����Ϣ---\n");
			head=Delete(head);
			break;
			case 8:	
			printf("\n---8�������Ϣ---\n");
            addInfo(head);
			break;
			case 9:	
			printf("\n---����ر�---\n");
			exit(0);
			break;
			default:
                printf("�Ƿ�����\n"); 
                break;
			
			
		}
	}
	
	
} 
int main(){
	char code[6]="12345",scan[6];
	printf("------Privacy Management System------\n");
	printf("*************************************\n");
	printf("����������\n");
 for(int i=3;i>0;i--){
 	printf("Password:\n");
 	scanf("%s",&scan);
 	if(strcmp(code, scan)){
 		if(i==1){
 			printf("�Ƿ��û���ϵͳ�˳�\n");
			 return 0; 
		 }
		 else{
		 	printf("������󣬻���%d�λ���\n",i-1);
		 }
	 }
 	else{
 		//�򿪹���ϵͳ 
 		printf("��ӭ������˽����ϵͳ");	
 		Management(); 
 		break;

	 }
 }
	
} 
