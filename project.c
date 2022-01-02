#include"stdio.h"
#include"direct.h"
#include"string.h"


/// creat a func for hello to person
char Hello();

char Hello()
{
    FILE *H;
    char words_hello;
    H = fopen("Hello.txt","r");
    while (!feof(H))
    {
        words_hello = fgetc(H);
        printf("%c",words_hello);
    }
    printf("\n");
}

///*******************************************///creat new file
char new_file(char*);

char new_file(char *name)
{
            char address_psw[70],address_user[70];
            char psw[10],user[30];
            int i=0 ,len;
            FILE *file_psw;
            strcpy(address_psw,name);
            strcpy(address_user,name);
            strcat(address_psw,"/password.txt");
            strcat(address_user,"/user_name.txt");
            mkdir(name);
            printf("\tPlease enter your user_name(Less than thirty characters) :\n\tuser_name-------> ");
            scanf("%s",user);
            printf("\tplease enter your password (Less than ten characters) :\n\tpassword--------> ");
            scanf("%s",psw);

            file_psw = fopen(address_user,"w");
            len = strlen(user);
            for(i;i<len;i++)
                fputc(user[i],file_psw);
            fclose(file_psw);

            file_psw = fopen(address_psw,"w");
            len = strlen(psw);
            i = 0;
            for(i;i<len;i++)
                fputc(psw[i],file_psw);
            fclose(file_psw);
}

///******************************///func check password account correct .
char check_password(char *);

char check_password(char *account_name)
{
    char address[50],password[50],pass_file[50],cpy_pass[50];
    int i=0,len;
    FILE *f;
    if (access(account_name,F_OK) == 0)
    {
        printf("\tplease enter password :");
        scanf("%s",password);
        strcpy(address,account_name);
        strcat(address,"/password.txt");
        f = fopen(address,"r");
        len  = strlen(password);
        fscanf(f,"%s",pass_file);
        fclose(f);
        if (strcmp(pass_file,password) == 0)
            return 1;
        else
        {
            printf("\tnot correct password .");
            return 0;
        }
    }
    else if (access(account_name,F_OK) == -1)
        {
            printf("\tdon't have account name .");
            return 0;
        }
}

///*************************/// func creat file text .
char creat_file_txt(char *,char *);

char creat_file_txt(char *name,char *account)
{
    FILE *file;
    int i=0,j=0,len;
    char address[50],name_dir[50];
    strcpy(address,account);
    strcat(address,"/");
    strcpy(name_dir,name);
    strcat(name_dir,".txt");
    strcat(address,name_dir);
    file = fopen(address,"w");
    fclose(file);
}

///********************************/// Main code :
int main()
{
    /// hello person wiht func Hello
    Hello();
    char enter[2],password_prog[50],user_prog[50],word[10][10],enter_password[50],enter_user_name[50];
    FILE *file_check;
    file_check = fopen("user_name_password.txt","r");
    fscanf(file_check,"%s %s %s %s %s %s %s",word[0],word[1],password_prog,word[2],word[3],word[4],user_prog);
    fclose(file_check);
    printf("\nPlease for use this program enter password : ");
    scanf("%s",enter_password);
    printf("Please for use this program enter user_name : ");
    scanf("%s",enter_user_name);
    if (strcmp(enter_password,password_prog)==0 && strcmp(enter_user_name,user_prog)==0 )
    {
        printf("\nCorrect......\n");
        while(1)
        {
        printf("\n\"\"\"\"\"\" if you need to guide for program enter command's 3 \"\"\"\"\"\n\nPlease enter your command : ");
        scanf("%s",&enter);
        if (strlen(enter) == 1)
        {
            if (isdigit(enter[0]) != 0) ///check correct command ===> isdigit
            {

///************************************************************************************/// exit of program .
                    if (enter[0] == '0')
                {
                    printf("\nCame out program ........\n");
                    break;
                }

///*****************************************************************************///creat new account .
                else if (enter[0] == '1')
                {
                        char accunt[30],name[30];
                        int len,i=0;
                        FILE *file;
                        printf("\nCreat new file ......\n");
                        printf("\n\tplease enter accunt's name : ");
                        scanf("%s",accunt);
                        strcpy(name,accunt);
                        if (access(accunt,F_OK) == -1)
                        {
                            new_file(name) ;
                        }
                        else
                        {
                            printf("\n\texists accunt ...... \n");
                            continue;
                        }
                }

///********************************************************************************/// show document help .
                else if (enter[0] == '3')
                {
                        FILE *help ;
                        char ch=0;
                        help = fopen("help.txt","r");
                        while(1)
                        {
                            ch = fgetc(help);
                            if (ch == '$')
                                break ;
                            else
                                printf("%c",ch);
                        }
                        fclose(help);
                }

///**********************************************************************************/// remove all account .
                else if (enter[0] == '4')
                {
                    char accunt_name[50],address_accunt[50]="accunts/",key[2],name_list[50];
                    char addrr1[50],addrr2[50],addr_pass[50],passw[50],pss[50];
                    int i=0,len;
                    printf("\tplease enter your accunt's name: ");
                    scanf("%s",&accunt_name);
                    if(access(accunt_name,F_OK) == 0)
                    {
                        if (check_password(accunt_name)==1)
                            {
                                printf("\tyou are sure remove this account(yes/no):y/n? ");
                                scanf("%s",key);
                                if (key[0] == 'y')
                                {
                                    printf("\tOK.....\n");
                                    strcpy(addrr1,accunt_name);
                                    strcat(addrr1,"/password.txt");
                                    if (access(addrr1,F_OK)==0)
                                        remove(addrr1);
                                    strcpy(addrr2,accunt_name);
                                    strcat(addrr2,"/user_name.txt");
                                    if (access(addrr2,F_OK)==0)
                                        remove(addrr2);
                                    strcpy(name_list,accunt_name);
                                    strcat(name_list,"/list_drug.txt");
                                    if (access(name_list,F_OK)== 0)
                                        remove(name_list);
                                    if (access(accunt_name,F_OK)==0)
                                        rmdir(accunt_name);
                                    if (access(accunt_name,F_OK)==-1)
                                        printf("\tremoved account : %s",accunt_name);
                                }
                                else if(key[0] == 'n')
                                    printf("\tOK....\n");
                            }
                    }
                    else
                        printf("\tdon't have accunt......");
                }

///********************************************************************************/// creat list_drug for account .
                else if (enter[0] == '5')
                {
                    char name_account[50];
                    int len_drugs,i=0;
                    printf("\twhich account ? ");
                    scanf("%s",name_account);
                    if (check_password(name_account) == 1)
                    {
                        if (access(name_account,F_OK) == 0)
                            {
                            char address[50];
                            strcpy(address,name_account);
                            strcat(address,"/list_drug.txt");
                            if (access(address,F_OK) == -1)
                                {struct list_pharmcy
                                {
                                    char name_drug[100][50];
                                    char price[100][20];
                                    char num_drug[100][50];
                                    char num_code[100][50];
                                    char expiration_date[100][50];
                                    char manufacturer[100][50];

                                }drugs;
                                printf("\tHow much do you want to add ? ");
                                scanf("%d",&len_drugs);
                                for (i;i<len_drugs;i++)
                                {
                                    printf("\tplease enter name_drug (%d): ",i+1);
                                    scanf("%s",drugs.name_drug[i]);
                                    printf("\tplease enter price (%d): ",i+1);
                                    scanf("%s",drugs.price[i]);
                                    printf("\tplease enter num_drug (%d): ",i+1);
                                    scanf("%s",drugs.num_drug[i]);
                                    printf("\tplease enter num_code (%d): ",i+1);
                                    scanf("%s",drugs.num_code[i]);
                                    printf("\tplease enter expiration_date (%d): ",i+1);
                                    scanf("%s",drugs.expiration_date[i]);
                                    printf("\tplease enter manufacturer (%d): ",i+1);
                                    scanf("%s",drugs.manufacturer[i]);

                                }
                                creat_file_txt("list_drug",name_account);
                                FILE *f;
                                f = fopen(address,"w");
                                i=0;
                                for (i;i<len_drugs;i++)
                                {
                                    fprintf(f,"%d : name : %s  price : %s  number_drug : %s  number_code : %s  expiration_date : %s  manufacturer : %s\n\n",i+1,drugs.name_drug[i],drugs.price[i],drugs.num_drug[i],drugs.num_code[i],drugs.expiration_date[i],drugs.manufacturer[i]);
                                }
                                fclose(f);}
                                else
                                    printf("\tyou don't add list_drug because this account have this list.");

                    }
                    }
                }

///***********************************************************************************/// chang and remove drugs .
                else if (enter[0] == '6')
                {
                    char name_accunt[50],password[50],command_r_a[20],address[50],list[50][50],list_add[50][50],name_remove[50];
                    FILE *f;
                    int index,i=0,j=0,index_r=0;
                    struct list_cpy
                    {
                        int num[100][10];
                        char name_drug[100][50];
                        char price[100][20];
                        char num_drug[100][50];
                        char num_code[100][50];
                        char expiration_date[100][50];
                        char manufacturer[100][50];
                    }cpy;
                    printf("\twich account ? ");
                    scanf("%s",name_accunt);
                    strcpy(address,name_accunt);
                    strcat(address,"/list_drug.txt");
                    if (access(name_accunt,F_OK) == 0)
                    {
                        if (check_password(name_accunt) == 1)
                        {
                                if (access(address,F_OK) == 0)
                                {
                                printf("\tPlease enter command (add or remove) : ");
                                scanf("%s",command_r_a);
                                f = fopen(address,"r");
                                while (!feof(f))
                                {
                                    fscanf(f,"%d %s %s %s %s",&index,list[0],list[1],list[2],list[3]);
                                    fscanf(f,"%s %s %s",list[4],list[5],list[6]);
                                    fscanf(f,"%s %s %s",list[7],list[8],list[9]);
                                    fscanf(f,"%s %s %s",list[10],list[11],list[12]);
                                    fscanf(f,"%s %s %s",list[13],list[14],list[15]);
                                    fscanf(f,"%s %s %s",list[16],list[17],list[18]);
                                    strcpy(cpy.name_drug[i] ,list[3]);
                                    strcpy(cpy.price[i] ,list[6]);
                                    strcpy(cpy.num_drug[i] ,list[9]);
                                    strcpy(cpy.num_code[i] ,list[12]);
                                    strcpy(cpy.expiration_date[i] ,list[15]);
                                    strcpy(cpy.manufacturer[i] ,list[18]);
                                    i += 1 ;
                                }
                                fclose(f);
                                if (strcmp(command_r_a,"add")==0)
                                {
                                    f= fopen(address,"a");
                                    printf("\tplease enter name_drug: ");
                                    scanf("%s",list_add[0]);
                                    printf("\tplease enter price : ");
                                    scanf("%s",list_add[1]);
                                    printf("\tplease enter num_drug: ");
                                    scanf("%s",list_add[2]);
                                    printf("\tplease enter num_code: ");
                                    scanf("%s",list_add[3]);
                                    printf("\tplease enter expiration_date: ");
                                    scanf("%s",list_add[4]);
                                    printf("\tplease enter manufacturer: ");
                                    scanf("%s",list_add[5]);
                                    fprintf(f,"%d : name : %s  price : %s  number_drug : %s  number_code : %s  expiration_date : %s  manufacturer : %s\n\n",index+1,list_add[0],list_add[1],list_add[2],list_add[3],list_add[4],list_add[5]);
                                    fclose(f);
                                    printf("\tadd to list your drug.");
                                }

                                else if (strcmp(command_r_a,"remove")==0)
                                {
                                    printf("\tPlease enter drug's name for remove of list_drug : ");
                                    scanf("%s",name_remove);
                                    f = fopen(address,"w");
                                    int inspect=0;
                                    for (j;j<index;j++)
                                    {
                                        if (strcmp(cpy.name_drug[j],name_remove)==0)
                                        {
                                            inspect +=1;
                                            continue ;
                                        }
                                        else
                                        {
                                            index_r += 1;
                                            fprintf(f,"%d : name : %s  price : %s  number_drug : %s  number_code : %s  expiration_date : %s  manufacturer : %s\n\n",index_r,cpy.name_drug[j],cpy.price[j],cpy.num_drug[j],cpy.num_code[j],cpy.expiration_date[j],cpy.manufacturer[j]);
                                        }
                                    }
                                    if (inspect == 0)
                                    {
                                        printf("\tdrug's name not in list.");
                                    }
                                    else
                                    {
                                        printf("\tremove drug.");
                                    }
                                    fclose(f);

                                }
                                else
                                    printf("Error .....");
                                }
                                else
                                    printf("This account don't have list_drug .......");
                        }
                    }
                    else
                        printf("\tdon't exist account .");
                }

 ///********************************************************************************/// search between drugs .
                else if (enter[0] == '7')
                {
                    char name_account[50],password[25],address_list[50];
                    printf("\tplease enter account's name : ");
                    scanf("%s",name_account);
                    if (access(name_account,F_OK)==0)
                    {
                        strcpy(address_list,name_account);
                        strcat(address_list,"/list_drug.txt");
                        if (check_password(name_account) == 1 && access(address_list,F_OK)==0 )
                        {
                            char list[50][50],name_command[50],address[50];
                            int i=0,j,h=0;
                            FILE *fp ;
                            struct list
                            {
                               int num;
                               char name[50];
                               char price[20];
                               char num_drug[20];
                               char num_code[20];
                               char ex_date[15];
                               char manf[30];
                            }info_drug[100];
                            strcpy(address,name_account);
                            strcat(address,"/list_drug.txt");
                            fp = fopen(address,"r");
                            while (!feof(fp))
                            {
                               fscanf(fp,"%d %s %s %s %s",&j,list[0],list[1],list[2],list[3]);
                               i += 1 ;
                               fscanf(fp,"%s %s %s",list[4],list[5],list[6]);
                               fscanf(fp,"%s %s %s",list[7],list[8],list[9]);
                               fscanf(fp,"%s %s %s",list[10],list[11],list[12]);
                               fscanf(fp,"%s %s %s",list[13],list[14],list[15]);
                               fscanf(fp,"%s %s %s",list[16],list[17],list[18]);
                               info_drug[i].num = j;
                               strcpy(info_drug[i].name ,list[3]);
                               strcpy(info_drug[i].price ,list[6]);
                               strcpy(info_drug[i].num_drug ,list[9]);
                               strcpy(info_drug[i].num_code ,list[12]);
                               strcpy(info_drug[i].ex_date ,list[15]);
                               strcpy(info_drug[i].manf ,list[18]);
                            }
                            fclose(fp);
                            printf("\tdo you search with (name or code) : ",name_command);
                            scanf("%s",name_command);
                            char search[50];
                            int inspect = 0;
                            if (strcmp(name_command,"name")==0)
                            {
                                printf("\tplease enter name_drug:");
                                scanf("%s",search);
                                for (h;h<i;h++)
                                {
                                    if (strcmp(search,info_drug[h].name)== 0)
                                        {
                                            printf("\n\t==============================================");
                                            printf("\n\tdrug's information is :\n");
                                            printf("\n\tname : %s  \n\tprice : %s  \n\tnumber_drug : %s  \n\tnumber_code : %s  \n\texpiration_date : %s  \n\tmanufacturer : %s",info_drug[h].name,info_drug[h].price,info_drug[h].num_drug,info_drug[h].num_code,info_drug[h].ex_date,info_drug[h].manf);
                                            printf("\n\t==============================================\n");
                                            inspect += 1;
                                            break ;
                                        }
                                }
                                if (inspect == 0)
                                    printf("\tnot correct drug's name ....");
                            }
                            else if (strcmp(name_command,"code")==0)
                            {
                                printf("\tplease enter code_drug:");
                                scanf("%s",search);
                                for (h;h<i;h++)
                                {
                                    if (strcmp(search,info_drug[h].num_code)== 0)
                                        {
                                            printf("\n\t==============================================");
                                            printf("\n\tdrug's information is :\n");
                                            printf("\n\tname : %s  \n\tprice : %s  \n\tnumber_drug : %s  \n\tnumber_code : %s  \n\texpiration_date : %s  \n\tmanufacturer : %s",info_drug[h].name,info_drug[h].price,info_drug[h].num_drug,info_drug[h].num_code,info_drug[h].ex_date,info_drug[h].manf);
                                            printf("\n\t==============================================\n");
                                            inspect += 1;
                                            break ;
                                        }
                                }
                                if (inspect == 0)
                                    printf("\tnot correct drug's code ....");
                            }
                            else
                                printf("\tError... ");
                        }
                        else
                            printf("\n\t(not correct password or this account don't have list_drug)");
                    }
                    else
                        printf("\tdon't have account .");
                }

///********************************************************************************///show drugs' sort list .

                else if (enter[0] == '8')
                {
                    char account_name[50],password_name[50],address[50];
                    printf("\tPlease enter your account : ");
                    scanf("%s",account_name);
                    if (access(account_name,F_OK)==0)
                    {
                        strcpy(address,account_name);
                        strcat(address,"/list_drug.txt");
                        if (check_password(account_name)==1)
                        {
                            if (access(address,F_OK)==0)
                            {
                                FILE *fp;

                                struct list_info
                                {
                                    int num_dg[100];
                                    char name_drug[100][50];
                                    char price[100][20];
                                    char num_drug[100][20];
                                    char num_code[100][20];
                                    char ex_date[100][20];
                                    char maker[100][50];
                                }list_cpy;
                                fp = fopen(address,"r");
                                char list[100][50];
                                int j,i=0;
                                while (!feof(fp))
                                {
                                    fscanf(fp,"%d %s %s %s %s",&j,list[0],list[1],list[2],list[3]);
                                    fscanf(fp,"%s %s %s",list[4],list[5],list[6]);
                                    fscanf(fp,"%s %s %s",list[7],list[8],list[9]);
                                    fscanf(fp,"%s %s %s",list[10],list[11],list[12]);
                                    fscanf(fp,"%s %s %s",list[13],list[14],list[15]);
                                    fscanf(fp,"%s %s %s",list[16],list[17],list[18]);
                                    list_cpy.num_dg[i] = j;
                                    strcpy(list_cpy.name_drug[i] ,list[3]);
                                    strcpy(list_cpy.price[i] ,list[6]);
                                    strcpy(list_cpy.num_drug[i] ,list[9]);
                                    strcpy(list_cpy.num_code[i] ,list[12]);
                                    strcpy(list_cpy.ex_date[i] ,list[15]);
                                    strcpy(list_cpy.maker[i] ,list[18]);
                                    i += 1;
                                }
                                i=0;
                                fclose(fp);
                                char cpy1[50],cpy2[50],cpy3[50];
                                int h=0;
                                for (i;i<j;i++)
                                {
                                    h=i+1;
                                    for (h;h<j;h++)
                                    {
                                        strcpy(cpy1,list_cpy.name_drug[i]);
                                        strcpy(cpy2,list_cpy.price[i]);
                                        strcpy(cpy3,list_cpy.num_drug[i]);
                                        if (strcmp(list_cpy.name_drug[i],list_cpy.name_drug[h])>0)
                                        {
                                            strcpy(list_cpy.name_drug[i],list_cpy.name_drug[h]);
                                            strcpy(list_cpy.name_drug[h],cpy1);
                                            strcpy(list_cpy.price[i],list_cpy.price[h]);
                                            strcpy(list_cpy.price[h],cpy2);
                                            strcpy(list_cpy.num_drug[i],list_cpy.num_drug[h]);
                                            strcpy(list_cpy.num_drug[h],cpy3);
                                        }
                                        else
                                            continue;
                                    }
                                }
                                i=0;
                                printf("\n\t******************************************************************\n");
                                for (i;i<j;i++)
                                {
                                    printf("\n\t%d name : %s\tprice : %s\tnumber_drug : %s\n",i+1,list_cpy.name_drug[i],list_cpy.price[i],list_cpy.num_drug[i]);
                                }
                                printf("\n\t******************************************************************\n");
                           }
                           else
                                printf("don't have list_drug this account .");
                        }
                    }
                    else
                        printf("\tdon't have this account .");

                }
///****************************************************************************\\\chang a drug's information .
                else if (enter[0] == '9')
                {
                    char account_name[50],password[50],address[50];
                    printf("\tplease enter account : ");
                    scanf("%s",&account_name);
                    if (access(account_name,F_OK) == 0)
                    {
                        strcpy(address,account_name);
                        strcat(address,"/list_drug.txt");
                        if (check_password(account_name))
                        {
                            if (access(address,F_OK)==0)
                            {
                                FILE *fp;
                                struct list_info
                                {
                                    int num_dg[100];
                                    char name_drug[100][50];
                                    char price[100][20];
                                    char num_drug[100][20];
                                    char num_code[100][20];
                                    char ex_date[100][20];
                                    char maker[100][50];
                                }list_cpy;
                                fp = fopen(address,"r");
                                char list[100][50],select[20];
                                int j,i=0;
                                while (!feof(fp))
                                {
                                    fscanf(fp,"%d %s %s %s %s",&j,list[0],list[1],list[2],list[3]);
                                    fscanf(fp,"%s %s %s",list[4],list[5],list[6]);
                                    fscanf(fp,"%s %s %s",list[7],list[8],list[9]);
                                    fscanf(fp,"%s %s %s",list[10],list[11],list[12]);
                                    fscanf(fp,"%s %s %s",list[13],list[14],list[15]);
                                    fscanf(fp,"%s %s %s",list[16],list[17],list[18]);
                                    list_cpy.num_dg[i] = j;
                                    strcpy(list_cpy.name_drug[i] ,list[3]);
                                    strcpy(list_cpy.price[i] ,list[6]);
                                    strcpy(list_cpy.num_drug[i] ,list[9]);
                                    strcpy(list_cpy.num_code[i] ,list[12]);
                                    strcpy(list_cpy.ex_date[i] ,list[15]);
                                    strcpy(list_cpy.maker[i] ,list[18]);
                                    i += 1;
                                }
                                fclose(fp);
                                i=0;
                                printf("\twhich drug's arguman ? (name,price,number_drug) :");
                                scanf("%s",select);
                                char name[20],change[20];
                                int verify=0;
                                if(strcmp(select,"name")==0 || strcmp(select,"price")==0 || strcmp(select,"number_drug")==0)
                                {
                                    printf("\twhich drug?(enter drug's name) :");
                                    scanf("%s",name);
                                    for(i;i<j;i++)
                                    {
                                        if (strcmp(list_cpy.name_drug[i],name)==0)
                                        {
                                            verify += 1;
                                            break;
                                        }
                                    }
                                    if (verify != 0)

                                    {
                                        if (strcmp(select,"name")==0)
                                        {
                                            printf("\twhat its new name ? ");
                                            scanf("%s",change);
                                            i=0;
                                            for(i;i<j;i++)
                                            {
                                                if (strcmp(list_cpy.name_drug[i],name)==0)
                                                {
                                                    strcpy(list_cpy.name_drug[i],change);
                                                    printf("\tchanged name ......");
                                                    break;
                                                }
                                            }
                                        }
                                        else if (strcmp(select,"price")==0)
                                        {
                                            printf("\twhat its new drug's price ? ");
                                            scanf("%s",change);
                                            i=0;
                                            for(i;i<j;i++)
                                            {
                                                if (strcmp(list_cpy.name_drug[i],name)==0)
                                                {
                                                    strcpy(list_cpy.price[i],change);
                                                    printf("\tchanged drug's price  .......");
                                                    break;
                                                }
                                            }
                                        }
                                        else if (strcmp(select,"number_drug")==0)
                                        {
                                            printf("\twhat its new drug's number ? ");
                                            scanf("%s",change);
                                            i=0;
                                            for(i;i<j;i++)
                                            {
                                                if (strcmp(list_cpy.name_drug[i],name)==0)
                                                {
                                                    strcpy(list_cpy.num_drug[i],change);
                                                    printf("\tchanged drug's number  .......");
                                                    break;
                                                }
                                            }
                                        }
                                        i=0;
                                        fp = fopen(address,"w");
                                        for (i;i<j;i++)
                                        {
                                            fprintf(fp,"%d : name : %s  price : %s  number_drug : %s  number_code : %s  expiration_date : %s  manufacturer : %s\n\n",i+1,list_cpy.name_drug[i],list_cpy.price[i],list_cpy.num_drug[i],list_cpy.num_code[i],list_cpy.ex_date[i],list_cpy.maker[i]);
                                        }
                                        fclose(fp);
                                    }
                                    else
                                        printf("\tdon't have this drug's name ");
                                }
                                else
                                    printf("\tthis arguman isn't for change.");

                            }
                            else
                                printf("\tthis account don't have file list_drug.txt ");
                        }
                    }
                    else
                        printf("\tdon't have this account.");
                }
///*************************************************************************************************
                else
                {
                    printf("\tdon't have this command.....\n");
                    continue;
                }
            }///check digit(enter)== True

            else if (isdigit(enter[0]) == 0)
            {
                printf("\tdon't have this command.....\n");
                continue;

            } /// check digit(enter) == False

        }/// check len(enter) == 1

        else
            printf("\tdon't have command .....");


    }///Loop while


   }///if password and user_name programm.
   else
        printf("\nnot True password or user_name \nexit of program.\n");
}
