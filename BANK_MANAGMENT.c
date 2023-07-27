#include<stdlib.h>
#include<math.h>
#include <stdio.h>
#include<conio.h>
#include<string.h>
#include<time.h>
int z=0;
int dep=0;
int wit=0;
struct AC_holder{
    char name[50];
    char gender;
    char actype;
    int  AC_num;
    char cnic[20];
    char pin[20];
    int datew[3][50];
    int timew[3][50];
    int dated[3][50];
    int timed[3][50];
    int Deposit1[50];
    int Withdraw1[50];
    double AC_bal;
    struct AC_holder *next;
    struct AC_holder *prev;
    
};

 struct AC_holder *head=NULL;
 
struct AC_holder *createAC(struct AC_holder *head,int *z) 
{
    system("clear");
    
    struct AC_holder *newac,*ptr;
    char ucnic[20];
    char uname[30];
    char ugender;
    char uactype;
    int  uacnum;
    char upin[20];
    double ubal;
    
    printf("                              ****************CREATE USER ACCOUNT*****************                                   \n");
    printf("\n\n                              Enter user's full name        ----> ");
    while((getchar())!='\n');
    // {
        scanf("%[^\n]%*c",uname);
        // scanf(" %s ",uname);
        // printf("\n");
    // };
    printf("\n\n                              Enter CNIC( xxxxx-xxxxxxx-x ) ----> ");
    scanf("%s",ucnic);
    printf("\n\n                              Enter Gender  ( M / F )       ----> ");
    scanf("%s",&ugender);
    printf("\n\n                              Enter AC type ( S / C )       ----> ");
    scanf("%s",&uactype);
    uacnum=rand()%10000;
    printf("\n\n                              Your AC number is             ----> %d                                     \n",uacnum);
    printf("\n\n                              Enter  pin                    ----> ");
    scanf("%s",upin);
    printf("\n\n                              Enter  Blance (min . 500)     ----> ");
    scanf("%lf",&ubal);
    while(ubal<500)
    {
    printf("\n\n                              !!!  Minmum balance req. is 500 !!! ");
    printf("\n\n                              Enter  Blance (min . 500)     ----> ");
    scanf("%lf",&ubal);
    }
    int a =strlen(uname);
    int b=strlen(upin);
    int c=strlen(ucnic);
    if(head==NULL)
    {
        newac=(struct AC_holder*)malloc(sizeof(struct AC_holder));
        newac->prev=NULL;
        strncpy(newac->name,uname,a);
        strncpy(newac->cnic,ucnic,b);
        newac->gender=ugender;
        newac->actype=uactype;
        newac->AC_num=uacnum;
        strncpy(newac->pin,upin,c);
        newac->AC_bal=ubal;
        newac->next=NULL;
        head=newac;
        *z+=1;
    }
    else{
        ptr=head;
        
        newac=(struct AC_holder*)malloc(sizeof(struct AC_holder));
        strncpy(newac->name,uname,30);
        strncpy(newac->cnic,ucnic,13);
        newac->gender=ugender;
        newac->actype=uactype;
        newac->AC_num=uacnum;
        strncpy(newac->pin,upin,20);
        newac->AC_bal=ubal;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;

        }
        ptr->next=newac;
        newac->prev=ptr;
        newac->next=NULL;
        *z+=1;
    }
    printf("\n                                Account created !!! ");
    return(head);
}
   

struct AC_holder *Delete(struct AC_holder *head,int *z)
{
    system("clear");
    int aa,i,am;
    struct AC_holder *pp ;
    pp=head;
    printf("\n                                Enter A/C Number : ");
    scanf("%d",&aa);
    for(i=0;i<*z;i++)
    {
        am=pp->AC_num;
        if(aa==am)
        {
            //printf("ac found!!");
            break;
        }
        else
        {
            pp=pp->next;
            continue;
        }
    }
    if(i==*z)
    {
        printf("\n\n                                Account Not found !!                                     ");
    }
    else
    {
        if(*z==1)
        {
            head=NULL;
        }
        else if(i==0)
        {
            head=head->next;
            head->prev=NULL;
        }
        else if(i==(*z-1))
        {
            pp->prev->next=NULL;
        }
        else
        {
            pp->prev->next=pp->next;
            pp->next->prev=pp->prev;
        }
        *z=*z-1;
         printf("\n\n                                Account succesfully Deleted !!                                     ");
    }
    free(pp);
    return(head);
}
struct AC_holder *SearchAC(struct AC_holder *head,int *z)
{
    system("clear");
    
    struct AC_holder *ptr;
    ptr=head;
    int a;
    printf("\n                                Enter A/C Number  :  ");
    scanf("%d",&a);
    int i=0;
    while(i<*z)
    {
        if(ptr->AC_num==a)
        {
            printf("\n\n                                Account found !!                                     ");
            printf("\n########################################################################################################################################\n");
            printf("A/C-NUMBER       Name                 CNIC             GENDER           A/c- Type            PIN            BALANCE   \n");
            printf("########################################################################################################################################\n");
            printf("%d              %s        %s               %c              %c                %s                 %0.1lf \n",ptr->AC_num,ptr->name, ptr->cnic,ptr->gender,ptr->actype,ptr->pin,ptr->AC_bal);
            break;
        }
          ptr=ptr->next;
          i++;
    }
    if(i==*z)
    {
        printf("\n\n                                Account Not found !!                                     ");
    }
    return(head);
}
struct AC_holder *showAllAC(struct AC_holder *head,int *z) 
{
    system("clear");
    
    struct AC_holder *ptr;
    
    ptr=head;
    int i=0;
    printf("\n########################################################################################################################################\n");
    printf("A/C-NUMBER       Name                 CNIC             GENDER           A/c- Type            PIN            BALANCE   \n");
    printf("########################################################################################################################################\n");

    while(i<*z)
    {
    printf("%d              %s        %s               %c              %c                %s                 %0.1lf \n",ptr->AC_num,ptr->name, ptr->cnic,ptr->gender,ptr->actype,ptr->pin,ptr->AC_bal);
    ptr=ptr->next;
    i++;
    }
    
    return(head) ;
}
struct AC_holder *editAC(struct AC_holder *head,int *z) 
{
    system("clear");
    char ucnic[13];
    char uname[30];
    char ugender;
    char uactype;
    char upin[20];
    printf("\n                                **Change Information of Account**  ");
    struct AC_holder *ptr;
    ptr=head;
    int a;
    printf("\n                                Enter user Account Number  :  ");
    scanf("%d",&a);
    
    int i=0;
    while(i<*z)
    {
        if(ptr->AC_num==a)
        {
            break;
        }
        else
        {
          ptr=ptr->next;
          i++;
        }
    }
    if(i==*z)
    {
        printf("\n\n                                Account Not found !!                                     ");
    }
    else
    {
        char xpin[20];
        int i=1,m=0;
        while(i!=0&&m<10)
        {
        printf("\n\n                                Enter user-Account PIN : ");
        scanf("%s",xpin);
      //  printf("%s",ptr->pin);
        if(strcmp(ptr->pin,xpin)==0)
        {
            printf("\n\n                              Enter New Name / previous Name ----> ");
            while((getchar())!='\n');
             // {
               scanf("%[^\n]%*c",uname);
             // scanf(" %s ",uname);
              // printf("\n");
              // };
            printf("\n\n                              Enter New CNIC / previous CNIC ----> ");
            scanf("%s",ucnic);
            printf("\n\n                              Enter Gender  ( M / F )        ----> ");
            scanf("%s",&ugender);
            printf("\n\n                              Enter AC type ( S / C )        ----> ");
            scanf("%s",&uactype);
            printf("\n\n                              Enter New pin / previous pin   ---> ");
            scanf("%s",upin);
            strncpy(ptr->name,uname,30);
            // newac->cnic=malloc(strlen(ucnic)+1);
            strncpy(ptr->cnic,ucnic,13);
            ptr->gender=ugender;
            ptr->actype=uactype;
            // newac->pin=malloc(strlen(upin)+1);
            strncpy(ptr->pin,upin,20);
            printf("\n                                **Information of Account succesfully Change**  ");
            i=0;
        }
        
        else
        {
            printf("\n                                Enter Valid PIN !! ");
        }
        
       
        }
         if(i!=0)
        {
            printf("\n                                Please contact your bank Maneger !! ");
        }
    }
    return(head);
}
struct AC_holder *Withdraw(struct AC_holder *head,int *z)
{
    system("clear");
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int aa,i,am;
    int money;
    struct AC_holder *pp ;
    pp=head;
    printf("\n                                Enter A/C Number : ");
    scanf("%d",&aa);
    for(i=0;i<*z;i++)
    {
        am=pp->AC_num;
        if(aa==am)
        {
            break;
        }
        else
        {
            pp=pp->next;
            continue;
        }
    }
    if(i==*z)
    {
        printf("\n\n                                Account Not found !!                                     ");
    }
    else
    {
        char xpin[20];
        int i=1,m=0;
        while(i!=0&&m<10)
        {
        printf("\n                                Enter user-Account PIN : ");
        scanf("%s",xpin);
        //  printf("%s",ptr->pin);
        if(strcmp(pp->pin,xpin)==0)
        {
            printf("\n                                Enter The Amount of WithDrawal :  ");
            scanf("%d",&money);
            if(money>pp->AC_bal)
            {
                printf("\n                                Account did not have sufficient balance !  ");
            }
            else
            {
                printf("\n\n                                Account status before WithDrawal");
                printf("\n\n");
                printf("\n########################################################################################################################################\n");
            printf("A/C-NUMBER       Name                 CNIC             GENDER           A/c- Type            PIN            BALANCE   \n");
            printf("########################################################################################################################################\n");
            printf("%d              %s        %s               %c              %c                %s                 %0.1lf \n",pp->AC_num,pp->name, pp->cnic,pp->gender,pp->actype,pp->pin,pp->AC_bal);
                pp->AC_bal=(pp->AC_bal)-money;
                printf("\n\n                                Account status After WithDrawal");
                printf("\n\n");
                printf("\n########################################################################################################################################\n");
            printf("A/C-NUMBER       Name                 CNIC             GENDER           A/c- Type            PIN            BALANCE   \n");
            printf("########################################################################################################################################\n");
            printf("%d              %s        %s               %c              %c                %s                 %0.1lf \n",pp->AC_num,pp->name, pp->cnic,pp->gender,pp->actype,pp->pin,pp->AC_bal);
            }
            pp->datew[0][wit]=tm.tm_mday;
            pp->datew[1][wit]=tm.tm_mon + 1;
            pp->datew[2][wit]=tm.tm_year + 1900;
            pp->timew[0][wit]=tm.tm_hour;  
            pp->timew[1][wit]=tm.tm_min;
            pp->timew[2][wit]=tm.tm_sec;
            pp->Withdraw1[wit]=money;
            wit++;
            i=0;
        }
        
        else
        {
            printf("\n                                Enter Valid PIN !! ");
        }
        
       
        }
         if(i!=0)
        {
            printf("\n                                Please contact your bank Maneger !! ");
        }
    }
    return(head);
}
struct AC_holder *Deposit(struct AC_holder *head,int *z)
{
    system("clear");
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int aa,i,am;
    int money;
    struct AC_holder *pp ;
    pp=head;
    printf("\n                                Enter A/C Number : ");
    scanf("%d",&aa);
    for(i=0;i<*z;i++)
    {
        am=pp->AC_num;
        if(aa==am)
        {
            break;
        }
        else
        {
            pp=pp->next;
            continue;
        }
    }
    if(i==*z)
    {
        printf("\n\n                                Account Not found !!                                     ");
    }
    else
    {
        printf("\n\n                                Enter Deposit Amount : ");
        scanf("%d",&money);
        pp->AC_bal=(pp->AC_bal)+money;
         printf("\n\n                                Account status After Deposit");
         printf("\n\n");
         printf("\n########################################################################################################################################\n");
            printf("A/C-NUMBER       Name                 CNIC             GENDER           A/c- Type            PIN            BALANCE   \n");
            printf("########################################################################################################################################\n");
            printf("%d              %s        %s               %c              %c                %s                 %0.1lf \n",pp->AC_num,pp->name, pp->cnic,pp->gender,pp->actype,pp->pin,pp->AC_bal);
         pp->dated[0][dep]=tm.tm_mday;
         pp->dated[1][dep]=tm.tm_mon + 1;
         pp->dated[2][dep]=tm.tm_year + 1900;
         pp->timed[0][dep]=tm.tm_hour;  
         pp->timed[1][dep]=tm.tm_min;
         pp->timed[2][dep]=tm.tm_sec;
         pp->Deposit1[dep]=money;
         dep++;
    }
    return(head);
}
struct AC_holder *Logs_of_User(struct AC_holder *head,int *z)
{
    system("clear");
    int aa,i,am;
    int money;
    struct AC_holder *pp ;
    pp=head;
    printf("\n                                Enter A/C Number : ");
    scanf("%d",&aa);
    for(i=0;i<*z;i++)
    {
        am=pp->AC_num;
        if(aa==am)
        {
            break;
        }
        else
        {
            pp=pp->next;
            continue;
        }
    }
    if(i==*z)
    {
        printf("\n\n                                Account Not found !!                                     ");
    }
    else
    {
         printf("\n\n");
         printf("\n########################################################################################################################################\n");
            printf("A/C-NUMBER       Name                 CNIC             GENDER           A/c- Type            PIN            BALANCE   \n");
            printf("########################################################################################################################################\n");
           printf("%d              %s        %s               %c              %c                %s                 %0.1lf \n",pp->AC_num,pp->name, pp->cnic,pp->gender,pp->actype,pp->pin,pp->AC_bal);
         for(int i=0;i<dep;i++)
         {
            printf("\n                                %d Amount deposited in A/C at Date -> %d / %d / %d  Time-> %d : %d : %d ",pp->Deposit1[i],pp->dated[0][i],pp->dated[1][i],pp->dated[2][i],pp->timed[0][i],pp->timed[1][i],pp->timed[2][i]);
         }
          printf("\n\n                                ** WithDrawal status **                                     ");
          for(int i=0;i<wit;i++)
         {
            printf("\n                                %d Amount Withdraw out of A/C at Date -> %d / %d / %d  Time-> %d : %d : %d ",pp->Withdraw1[i],pp->datew[0][i],pp->datew[1][i],pp->datew[2][i],pp->timew[0][i],pp->timew[1][i],pp->timew[2][i]);
         }
    }
    return(head);
}
void ADMIN_LOGIN()
{
    
    system("clear");
    int n;
   
   do{
    //system("clear");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                ****************************************************                                   \n");
    printf("                                ********************ADMIN||PANEL********************                                \n");
    printf("                                ****************************************************                                   \n");
    printf("                                *      Press 1----> To Create Account              *                      \n");
    printf("                                *      Press 2----> To Delete Account              *                      \n");
    printf("                                *      Press 3----> To Search Account              *                      \n");
    printf("                                *      Press 4----> To Show List of all Account    *                      \n");
    printf("                                *      Press 5----> TO Edit Information            *                      \n");
    printf("                                *      Press 0----> To Return to Main Manu         *                      \n");
    printf("                                ****************************************************                                   \n");
    printf("                                ****************************************************                                   \n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                Enter your choice ----> ");
    scanf("%d",&n);
    switch (n)
    {
    case 1:
        head=createAC(head,&z);
        break ;
    case 2:
        head=Delete(head,&z);
        break ;
    case 3:
        head=SearchAC(head,&z);
        break;
    case 4:
        head=showAllAC(head , &z);
        break;
    case 5:
        head=editAC(head, &z);
        break;
    }
   }while(n!=0);
    return ;

}

void STAFF_LOGIN()
{
     system("clear");
    int n;
    int y;
   
   do{
    //system("clear");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                ****************************************************                                   \n");
    printf("                                ********************STAFF||PANEL********************                                \n");
    printf("                                ****************************************************                                   \n");
    printf("                                *      Press 1----> To Cheak Account Info          *                      \n");
    printf("                                *      Press 2----> To Deposit Cash                *                      \n");
    printf("                                *      Press 3----> To With_Draw cash              *                      \n");
    printf("                                *      Press 4----> To Cheak Logs of User          *                      \n");
    printf("                                *      Press 0----> To Return to Main Manu         *                      \n");
    printf("                                ****************************************************                                   \n");
    printf("                                ****************************************************                                   \n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                Enter your choice ----> ");
    scanf("%d",&n);
    switch (n)
    {
    case 1:
        head=SearchAC(head,&z);
        break ;
    case 2:
        head=Deposit(head,&z);
        break ;
    case 3:
        head=Withdraw(head,&z);
        break;
    case 4:
        head=Logs_of_User(head , &z);
        break;
    }
   }while(n!=0);
   
    return ;
}

void ATM_SERVICE()
{
    system("clear");
    int n;
    int y;
   
   do{
    //system("clear");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                ****************************************************                                   \n");
    printf("                                ********************ATM||PANEL**********************                                \n");
    printf("                                ****************************************************                                   \n");
    printf("                                *      Press 1----> To Withdraw Cash               *                      \n");
    printf("                                *      Press 2----> To Deposit Cash                *                      \n");
    printf("                                *      Press 0----> To Return to Main Manu         *                      \n");
    printf("                                ****************************************************                                   \n");
    printf("                                ****************************************************                                   \n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                Enter your choice ----> ");
    scanf("%d",&n);
    switch (n)
    {
    
    case 1:
        head=Withdraw(head,&z);
        break;
    case 2:
        head=Deposit(head,&z);
    break ;
    }
   }while(n!=0);
   
    return ;
}

int main()
{
    int ch=1;
    int y=1212;
    int z;
    int yes=1;
    do
    {
    system("clear");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                ****************************************************                                   \n");
    printf("                                ********************LOGIN||PANEL********************                                \n");
    printf("                                ****************************************************                                   \n");
    printf("                                *      Press 1---->    For ADMIN Login             *                      \n");
    printf("                                *      Press 2---->    For STAFF Login             *                      \n");
    printf("                                *      Press 3---->    For ATM  Sevice             *                      \n");
    printf("                                *      Press 0---->    To  Exite                   *                      \n");
    printf("                                ****************************************************                                   \n");
    printf("                                ****************************************************                                   \n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                Enter your choice ----> ");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
    ADMIN_LOGIN();
        break;
    case 2:
    while(yes!=0)
    {
    system("clear");
    printf("\n                                Enter Staff pin:  ----> ");
    scanf("%d",&z);
    if(y==z)
    {
    STAFF_LOGIN();
    break ;
    }
    else
    {
    printf("\n\n                                Wrong pin ! Please Enter again !! ");
    printf("\n\n                                Press ---> 1 To Retry");
    printf("\n\n                                Press ---> 0 To Exit");
    printf("\n\n                                Enter ---> ");
    scanf("%d",&yes);
    }
    }
    
        break;
    case 3:
    ATM_SERVICE();
        break;
        
    } 
    }while(ch!=0);
    getch();
    return 0;
    }









