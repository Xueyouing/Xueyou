#include<stdio.h>
#include<string.h>
struct student
{
  char name[20];//����
  char sex[10];//�Ա�
  int number;//ѧ��
  char ban[20];//�༶
  int c;//�ɼ�
}stu[90];
int n;//ѧ������
void mainPage()//��ҳ�� 
{
 printf("\n");
 printf("_______________________________\n");
 printf("|                              |\n");
 printf("|_______ѧ���ɼ�����ϵͳ_______|\n");
 printf("|_______��1 ����ѧ����Ϣ_______|\n");
 printf("|_______��2 ���ѧ����Ϣ_______|\n");
 printf("|_______��3 ��ѯѧ����Ϣ_______|\n");
 printf("|_______��4 �޸�ѧ����Ϣ_______|\n");
 printf("|_______��5 ɾ��ѧ����Ϣ_______|\n");
 printf("|_______��6 ����ѧ����Ϣ_______|\n");
 printf("|_________��0 �˳�ϵͳ_________|\n");
 printf("|______________________________|\n");
}
void input()//ѧ����Ϣ��¼��
{
 int i,j=1;
 printf("\n��������ѧ������:");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
        printf("�����%d��ѧ�������Ϣ\n",j++);
    printf("��������\n");
    scanf("%s",stu[i].name);
    getchar();
    printf("�����Ա�\n");
    scanf("%s",stu[i].sex);
  	printf("����ѧ��\n");
  	scanf("%d",&stu[i].number);
  	printf("����༶\n");
  	scanf("%s",stu[i].ban);
  	printf("����ɼ�\n");
	scanf("%d",&stu[i].c);
 }
}
void output()//ѧ����Ϣ���
{
 int i;
 printf("----------ѧ������Ϣ��----------\n");
 if(n==0)printf("    ++++++����û����Ϣ++++++\n");
 else for(i=1;i<=n;i++)
 {
  printf("���֣�%2s",stu[i].name);
  printf("   �Ա�%2s",stu[i].sex);
  printf("   ѧ�ţ�%2d",stu[i].number);
  printf("   �༶��%2s",stu[i].ban);
  printf("   �ɼ���%2d\n",stu[i].c);
 }

}
void search()//��ѯ
{
 int num,i,t;
 char a[20],k;
 if(n!=0)
 {
  printf("ѡ���������(����1��ѧ�Ų�ѯ  ����2�����ֲ�ѯ)\n");
     scanf("%d",&t);
  if(t==1)
  {
   printf("������Ҫ���ҵ�ѧ����ѧ��\n");
         scanf("%d",&num);
   for(i=1;i<=n;i++)
   {
    if(stu[i].number==num)
    {
           printf("���֣�%s",stu[i].name," ");
           printf("   �Ա�%s",stu[i].sex);
           printf("   ѧ�ţ�%d",stu[i].number);
           printf("   �༶��%s",stu[i].ban);
           printf("   �ɼ���%d\n",stu[i].c);
     break;
    }
   } if(i>n) printf("�����ҵ���Ϣ�����ڻ���ѧ���������\n");
  }
  if(t==2)
  {
   printf("������Ҫ���ҵ�ѧ��������\n");
   scanf("%s",a);
   for(i=1;i<=n;i++)
   {
    k=strcmp(stu[i].name,a);
    if(k==0)
    {
     printf("���֣�%s",stu[i].name);
           printf("�Ա�%s",stu[i].sex);
           printf("   ѧ�ţ�%d",stu[i].number);
           printf("   �༶��%s",stu[i].ban);
           printf("   �ɼ���%d\n",stu[i].c);
     break;

    }
   }if(i>n) printf("�����ҵ���Ϣ�����ڻ���ѧ���������\n");
  }

 }
 else printf("�Բ�������û��ѧ����Ϣ\n");

 

}
void change()//�޸�
{
 int num,i;
 printf("������Ҫ�޸ĵ�ѧ����ѧ��\n");
 scanf("%d",&num);
 if(n==0) printf("    ++++++����û����Ϣ++++++\n");
 else
 {
  for(i=1;i<=n;i++)
  {
   if(stu[i].number==num)
   {
    printf("��Ҫ�޸ĵ�ѧ����ϢΪ\n");
    printf("���֣�%s",stu[i].name);
          printf("   �Ա�%s",stu[i].sex);
          printf("   ѧ�ţ�%d",stu[i].number);
          printf("   �༶��%s",stu[i].ban);
          printf("   �ɼ���%d\n",stu[i].c);
    break;

   }
   
  }

  if(i>n) printf("�����ҵ���Ϣ�����ڻ���ѧ���������\n");
  else
  {
         printf("��������\n");
      scanf("%s",stu[i].name);
      getchar();
      printf("�����Ա�\n");
      scanf("%s",stu[i].sex);
  printf("����ѧ��\n");
  scanf("%d",&stu[i].number);
  printf("����༶\n");
  scanf("%s",stu[i].ban);
  printf("����ɼ�\n");
  scanf("%d",&stu[i].c);
  }
 }
}
void del()//ɾ��
{
 int i,j,e,num;
 if(n!=0)
 {
  printf("  ****����ѧ������Ϣ****\n");
  for(i=1;i<=n;i++)
  {
   printf("--------------------------*\n");
   printf("���֣�%s\n",stu[i].name);
   printf("                          *\n");
      printf("�Ա�%s\n",stu[i].sex);
   printf("                          *\n");
      printf("ѧ�ţ�%d\n",stu[i].number);
   printf("                          *\n");
      printf("�༶��%s\n",stu[i].ban);
   printf("                          *\n");
      printf("�ɼ���%d\n",stu[i].c);
   printf("--------------------------*\n");
  }
  printf("��������Ҫɾ����ѧ����ѧ��:");
  scanf("%d",&num);
  for(i=1;i<=n;i++)
   if(stu[i].number==num)
   {
    j=i;
    for(e=i-1;e<n;e++,j++)
    {
     strcpy(stu[j].name,stu[j+1].name);//strcpy:���ַ������Ƶ���һ�ռ��ַ 
     strcpy(stu[j].sex,stu[j+1].sex);
     stu[j].number=stu[j+1].number;
     strcpy(stu[j].ban,stu[j+1].ban);
     stu[j].c=stu[j+1].c;
     n--;
     }
    }printf("**********��ѧ����Ϣ��ɾ��**********\n");

  }
  else printf("�Բ�������û��ѧ����Ϣ\n");

  
  
  
}
void add()//����
{
 int i,j,t;
 if(n!=0)
 {
  printf("**********�����ѧ�������Ϣ**********\n");
  printf("��������\n");
  scanf("%s",stu[n+1].name);
  getchar();
  printf("�����Ա�\n");
  scanf("%s",stu[n+1].sex);
  printf("����ѧ��\n");
  scanf("%d",&stu[n+1].number);
  printf("����༶\n");
  scanf("%s",stu[n+1].ban);
  printf("����ɼ�\n");
  scanf("%d",&stu[n+1].c);
  
  // �ж�ѧ���Ƿ��Ѿ�����
  for(i = 1; i <= n; i++) {
    if(stu[i].number == stu[n+1].number) {
      printf("����ʧ�ܣ���ѧ���Ѵ���");
      return;
    }
  }
  
  // ����������������ѧ����Ϣ
  printf("����ɹ�����ѧ����Ϣ�Ѳ���\n");
  n++;
 }
 else {
  i = 1;
  printf("������Ҫ����ѧ���������Ϣ\n");
  printf("��������\n");
  scanf("%s",stu[i].name);
  getchar();
  printf("�����Ա�\n");
  scanf("%s",stu[i].sex);
  printf("����ѧ��\n");
  scanf("%d",&stu[i].number);
  printf("����༶\n");
  scanf("%s",stu[i].ban);
  printf("����ɼ�\n");
  scanf("%d",&stu[i].c);
  n++;
 }
}
int main()
{
 int a,b=1;
 while(b)
 {
  mainPage();
  printf("��ѡ�����: ");
  scanf("%d",&a);
  printf("\n");
  switch(a)
  {
  case 1:input();break;//����
  case 2:output();break;//���
  case 3:search();break;//����
  case 4:change();break;//�޸�
  case 5:del();break;//ɾ��
  case 6:add();break;//���� 
  case 0:b=0; break;
  //return 0;
  }
 }
 printf("       ѧ������ϵͳ���˳�     \n");
}
