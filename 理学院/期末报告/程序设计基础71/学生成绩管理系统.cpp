#include<stdio.h>
#include<string.h>
struct student
{
  char name[20];//名字
  char sex[10];//性别
  int number;//学号
  char ban[20];//班级
  int c;//成绩
}stu[90];
int n;//学生数量
void mainPage()//主页面 
{
 printf("\n");
 printf("_______________________________\n");
 printf("|                              |\n");
 printf("|_______学生成绩管理系统_______|\n");
 printf("|_______按1 输入学生信息_______|\n");
 printf("|_______按2 输出学生信息_______|\n");
 printf("|_______按3 查询学生信息_______|\n");
 printf("|_______按4 修改学生信息_______|\n");
 printf("|_______按5 删除学生信息_______|\n");
 printf("|_______按6 插入学生信息_______|\n");
 printf("|_________按0 退出系统_________|\n");
 printf("|______________________________|\n");
}
void input()//学生信息的录入
{
 int i,j=1;
 printf("\n请输入总学生数量:");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
        printf("输入第%d个学生相关信息\n",j++);
    printf("输入姓名\n");
    scanf("%s",stu[i].name);
    getchar();
    printf("输入性别\n");
    scanf("%s",stu[i].sex);
  	printf("输入学号\n");
  	scanf("%d",&stu[i].number);
  	printf("输入班级\n");
  	scanf("%s",stu[i].ban);
  	printf("输入成绩\n");
	scanf("%d",&stu[i].c);
 }
}
void output()//学生信息输出
{
 int i;
 printf("----------学生的信息是----------\n");
 if(n==0)printf("    ++++++这里没有信息++++++\n");
 else for(i=1;i<=n;i++)
 {
  printf("名字：%2s",stu[i].name);
  printf("   性别：%2s",stu[i].sex);
  printf("   学号：%2d",stu[i].number);
  printf("   班级：%2s",stu[i].ban);
  printf("   成绩：%2d\n",stu[i].c);
 }

}
void search()//查询
{
 int num,i,t;
 char a[20],k;
 if(n!=0)
 {
  printf("选择查找条件(输入1用学号查询  输入2用名字查询)\n");
     scanf("%d",&t);
  if(t==1)
  {
   printf("输入您要查找的学生的学号\n");
         scanf("%d",&num);
   for(i=1;i<=n;i++)
   {
    if(stu[i].number==num)
    {
           printf("名字：%s",stu[i].name," ");
           printf("   性别：%s",stu[i].sex);
           printf("   学号：%d",stu[i].number);
           printf("   班级：%s",stu[i].ban);
           printf("   成绩：%d\n",stu[i].c);
     break;
    }
   } if(i>n) printf("您查找的信息不存在或者学号输入错误\n");
  }
  if(t==2)
  {
   printf("输入您要查找的学生的名字\n");
   scanf("%s",a);
   for(i=1;i<=n;i++)
   {
    k=strcmp(stu[i].name,a);
    if(k==0)
    {
     printf("名字：%s",stu[i].name);
           printf("性别：%s",stu[i].sex);
           printf("   学号：%d",stu[i].number);
           printf("   班级：%s",stu[i].ban);
           printf("   成绩：%d\n",stu[i].c);
     break;

    }
   }if(i>n) printf("您查找的信息不存在或者学号输入错误\n");
  }

 }
 else printf("对不起，这里没有学生信息\n");

 

}
void change()//修改
{
 int num,i;
 printf("输入您要修改的学生的学号\n");
 scanf("%d",&num);
 if(n==0) printf("    ++++++这里没有信息++++++\n");
 else
 {
  for(i=1;i<=n;i++)
  {
   if(stu[i].number==num)
   {
    printf("您要修改的学生信息为\n");
    printf("名字：%s",stu[i].name);
          printf("   性别：%s",stu[i].sex);
          printf("   学号：%d",stu[i].number);
          printf("   班级：%s",stu[i].ban);
          printf("   成绩：%d\n",stu[i].c);
    break;

   }
   
  }

  if(i>n) printf("您查找的信息不存在或者学号输入错误\n");
  else
  {
         printf("输入姓名\n");
      scanf("%s",stu[i].name);
      getchar();
      printf("输入性别\n");
      scanf("%s",stu[i].sex);
  printf("输入学号\n");
  scanf("%d",&stu[i].number);
  printf("输入班级\n");
  scanf("%s",stu[i].ban);
  printf("输入成绩\n");
  scanf("%d",&stu[i].c);
  }
 }
}
void del()//删除
{
 int i,j,e,num;
 if(n!=0)
 {
  printf("  ****所有学生的信息****\n");
  for(i=1;i<=n;i++)
  {
   printf("--------------------------*\n");
   printf("名字：%s\n",stu[i].name);
   printf("                          *\n");
      printf("性别：%s\n",stu[i].sex);
   printf("                          *\n");
      printf("学号：%d\n",stu[i].number);
   printf("                          *\n");
      printf("班级：%s\n",stu[i].ban);
   printf("                          *\n");
      printf("成绩：%d\n",stu[i].c);
   printf("--------------------------*\n");
  }
  printf("请输入您要删除的学生的学号:");
  scanf("%d",&num);
  for(i=1;i<=n;i++)
   if(stu[i].number==num)
   {
    j=i;
    for(e=i-1;e<n;e++,j++)
    {
     strcpy(stu[j].name,stu[j+1].name);//strcpy:把字符串复制到另一空间地址 
     strcpy(stu[j].sex,stu[j+1].sex);
     stu[j].number=stu[j+1].number;
     strcpy(stu[j].ban,stu[j+1].ban);
     stu[j].c=stu[j+1].c;
     n--;
     }
    }printf("**********该学生信息已删除**********\n");

  }
  else printf("对不起，这里没有学生信息\n");

  
  
  
}
void add()//插入
{
 int i,j,t;
 if(n!=0)
 {
  printf("**********请插入学生相关信息**********\n");
  printf("输入姓名\n");
  scanf("%s",stu[n+1].name);
  getchar();
  printf("输入性别\n");
  scanf("%s",stu[n+1].sex);
  printf("输入学号\n");
  scanf("%d",&stu[n+1].number);
  printf("输入班级\n");
  scanf("%s",stu[n+1].ban);
  printf("输入成绩\n");
  scanf("%d",&stu[n+1].c);
  
  // 判断学号是否已经存在
  for(i = 1; i <= n; i++) {
    if(stu[i].number == stu[n+1].number) {
      printf("插入失败！该学生已存在");
      return;
    }
  }
  
  // 不存在则继续插入该学生信息
  printf("插入成功！该学生信息已插入\n");
  n++;
 }
 else {
  i = 1;
  printf("请输入要插入学生的相关信息\n");
  printf("输入姓名\n");
  scanf("%s",stu[i].name);
  getchar();
  printf("输入性别\n");
  scanf("%s",stu[i].sex);
  printf("输入学号\n");
  scanf("%d",&stu[i].number);
  printf("输入班级\n");
  scanf("%s",stu[i].ban);
  printf("输入成绩\n");
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
  printf("您选择的是: ");
  scanf("%d",&a);
  printf("\n");
  switch(a)
  {
  case 1:input();break;//输入
  case 2:output();break;//输出
  case 3:search();break;//查找
  case 4:change();break;//修改
  case 5:del();break;//删除
  case 6:add();break;//插入 
  case 0:b=0; break;
  //return 0;
  }
 }
 printf("       学生管理系统已退出     \n");
}
