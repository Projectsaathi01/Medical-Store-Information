#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include <stdlib.h>
#include<string.h>                  //contains strcmp(),strcpy(),strlen(),etc
#include<ctype.h>                   //contains toupper(), tolower(),etc
#include<dos.h>                     //contains _dos_getdate
#include<time.h>
void supplier();
void add_supplier();
void view_supplier();
void modify_supplier();
void search_supplier();
void delete_supplier();

void customer();
void add_customer();
void view_customer();
void modify_customer();
void search_customer();
void delete_customer();

void medicine();
void add_medicine();
void view_medicine();
void modify_medicine();
void search_medicine();
void delete_medicine();

void design();

/*int checkid(int i)
{
	rewind(fp);
	while(fread(&s, sizeof(s), 1, fp)==1)
	if(s.id == r)
	return 0;
	return 1;
}*/


COORD coord = {0, 0};// for cordinating the text
void gotoxy (int x, int y)//wher cordinate you have to display
{
coord.X = x; coord.Y = y; // X and Y coordinates
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

FILE *fp;
struct supp
{
    int id;
    char name[20], address[50];
    long long phone;

};
struct supp s;


    struct medicine
    {

        int rack, qty;
        char name[20],e_date[50],m_date[50];
        float price;
    };
    struct medicine m;

void main()
{
	design();
	//getch();
    do{
        system("cls");
        gotoxy(50,6);printf("[1] SUPPLIER SECTION\n");
        gotoxy(50,7);printf("[2] CUSTOMER SECTION\n");
        gotoxy(50,8);printf("[3] MEDICINE SECTION\n");
        gotoxy(50,9);printf("[4] CLOSE APPLICATION\n");
        gotoxy(50,10);printf("Enter Choice:\t");
        switch(getch())
        {
        case '1':
            supplier();
            break;
        case '2':
            customer();
            break;
        case '3':
            medicine();
            break;
        case '4':
            exit(0);
        default:
            main();
            break;
        }
        getch();
    }while(1);

}


void supplier()
{
    do{
        system("cls");
		gotoxy(50,2);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SUPPLIER INFORMATION SECTION \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		gotoxy(50,4);printf("\xB2\xB2\xB2 [1] ADD    SUPPLIER");
		gotoxy(50,6);printf("\xB2\xB2\xB2 [2] VIEW   SUPPLIER");
		gotoxy(50,8);printf("\xB2\xB2\xB2 [3] MODIFY SUPPLIER");
		gotoxy(50,10);printf("\xB2\xB2\xB2 [4] SEARCH SUPPLIER");
		gotoxy(50,12);printf("\xB2\xB2\xB2 [5] DELETE SUPPLIER");
		gotoxy(50,14);printf("\xB2\xB2\xB2 [6] BACK TO MAIN PROGRAM");
		gotoxy(50,16);printf("\xB2\xB2\xB2 [7] CLOSE APPLICATION");
		gotoxy(50,18);printf("Enter Choice:\t");
		switch(getch())
		{
			case '1':
				system("cls");
				add_supplier();
				break;
			case '2':
				system("cls");
				view_supplier();
				break;
			case '3':
				modify_supplier();
				break;
			case '4':
				search_supplier();
				break;
			case '5':
				delete_supplier();
				break;
			case '6':
				main();
				break;
			case '7':
				exit(0);
			default:
				supplier();
				break;
		}
	}while(1);
}

add_supplier()
{
    //int x = 1;
/*
fp=fopen("supplier.dat","ab+");
int t_id;
system("cls");
printf("\t\t\t\t<<<********** Fill the Supplier Information **********>>>");
fflush(stdin);
printf("\nEnter ID:");
scanf("%d",&t_id);
while(fread(&s, sizeof(s), 1, fp))
{
    if(s.id == t_id)
    {
        printf("ID is Already Exists");
    }
    else
    {
        fflush(stdin);
        printf("\nEnter Name:");
        gets(s.name);
        printf("\nEnter Address:");
        gets(s.address);
        printf("\nEnter Phone No:");
        scanf("%lli",&s.phone);
        fseek(fp,0,SEEK_END);
        fwrite(&s,sizeof(s),1,fp);
        fclose(fp);
        printf(" Again Enter supplier info(y/n)" );
        if(getch()!='y')
        {

            add_supplier();
        }
        if(getch()=='n')
        {
            main();
        }




    }
}
 getch();
}
*/
// my original code

	m:
		fp=fopen("supplier.dat","ab+");
		system("cls");
		gotoxy(50,2);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SUPPLIER INFORMATION SECTION \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		fflush(stdin);
		gotoxy(50,4);printf("\xB2\xB2\t Enter ID :\t\t");
		scanf("%d",&s.id);
		fflush(stdin);
		gotoxy(50,6);printf("\xB2\xB2\t Enter Name :\t\t");
		gets(s.name);
		gotoxy(50,8);printf("\xB2\xB2\t Enter Address :\t\t");
		gets(s.address);
		gotoxy(50,10);printf("\xB2\xB2\t Enter Phone No :\t\t");
		scanf("%lli",&s.phone);
		fseek(fp,0,SEEK_END);
		fwrite(&s,sizeof(s),1,fp);
		fclose(fp);
		gotoxy(50,12);printf("\t Again Enter Supplier info(y/n)" );
		if(getch()=='y')
		goto m;
	else
	{
		main();
	}
}


view_supplier()
{
    system("cls");
    int j=5;
    gotoxy(50,1);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SUPPLIER INFORMATION SECTION \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(50,3);printf("ID          NAME                    ADDRESS               CONTACTS");
    fp=fopen("supplier.dat","rb+");
    while(fread(&s,sizeof(s),1,fp))
        {
            gotoxy(50,j);
            printf("%d",s.id);
            gotoxy(62,j);
            printf("%s",s.name);
            gotoxy(86,j);
            printf("%s",s.address);
            gotoxy(108,j);
            printf("%lli",s.phone);
            j++;
        }
        fclose(fp);
        getch();
    }

/*
ft=fopen("deuba.txt","rb+");
while(fread(&t,sizeof(t),1,ft))
{
gotoxy(45,j);
printf("%d",t.ids);
gotoxy(55,j);
printf("%s",t.nams);
j++;
}
fclose(ft);
printf("\n\n\n\n\n\n\t\t\tPress any key to back");//only show user easy to what can i do for back
getch();//hold the value
main();//main function call
}
*/

void modify_supplier()
{

    system("cls");
    int supplier;
    FILE *fn,*fp;
    char x;
	gotoxy(50,2);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 UPDATE SUPPLIER  SECTION \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(50,3);printf("Enter Supplier ID to Modify the Supplier\n");
    scanf("%d",&supplier);
    fn = fopen("supplier.dat","rb+");
    fp = fopen("temp.dat","wb+");
    while(fread(&s,sizeof(s),1,fn))
    {
        if(s.id == supplier){

                fflush(stdin);
                printf("Enter Name:\t");
                gets(s.name);
                fflush(stdin);
                printf("Enter Address:\t");
                gets(s.address);
                printf("Enter Phone:\t");
                scanf("%lli",&s.phone);
                fwrite(&s, sizeof(s), 1, fp);
                //fwrite(&s,sizeof(s),1,fp);
        }
        else{
            fwrite(&s, sizeof(s), 1, fp);
        }
/*        {   system("cls");
            printf("\n Are you sure to modify the record, Press Y for Yes  ");
            x = getch();
            if((x == 'Y'||x=='y')==0){
                fwrite(&s,sizeof(s),1,fp);
                getch();

            }
    }

    }*/
    fclose(fp);
    fclose(fn);
    remove("supplier.dat");
    rename("temp.dat","supplier.dat");
}

}

  /*  system("cls");
    struct supp a;
    struct supp t;
    long long p;
    int j=10;
    int supplier;
    FILE *fn,*fp;
    char x;

    printf("Enter Supplier ID to Modify the Supplier\n");
    scanf("%d",&supplier);
    fn = fopen("supplier.dat","rb+");
    fp = fopen("temp.dat","wb+");
    while(fread(&s,sizeof(s),1,fn))
    {
        if(s.id != supplier){
                fwrite(&s,sizeof(s),1,fp);
        }
        else{
                printf("\n");
                printf("ID : %d    ",s.id);
                printf("Name : %s    ",s.name);
                printf("Address : %s    ",s.address);
                printf("Phone No :%lli    ",s.phone);
            printf("\nEnter New Name or Press Enter For Same Previous Name\n");
            gets(a.name);
            if(strcmp(a.name,t.name)==0)
                s.name = a.name;

            printf("\nEnter New Address or Press Enter For Same Previous Address\n");
            gets(a);
            if(strcmp(a.address,t.address)==0)
                s.address = a.address;

            printf("\nEnter New Phone Number or Press Enter For Same Previous Number\n");
            scanf("%lli",&a.phone);
            if(a.phone!=t.phone)
                s.phone = a.phone;


            printf("\n Are you sure to Modify the record, Press Y for Yes  ");
            x = getch();
            if((x == 'Y'||x=='y')==0){
                fwrite(&s,sizeof(s),1,fp);
            }
        }

    }
    fclose(fp);
    fclose(fn);
    remove("supplier.dat");
    rename("temp.dat","supplier.dat");


    gotoxy(120,1);printf("\n\t\t\t\t\t Supplier Information");
    gotoxy(20,3);
    printf("ID          Name                    Address                 Contact");
    fp=fopen("supplier.dat","rb+");
    while(fread(&s,sizeof(s),1,fp))
    {
    gotoxy(20,j);
    printf("%d",s.id);
    gotoxy(32,j);
    printf("%s",s.name);
    gotoxy(56,j);
    printf("%s",s.address);
    gotoxy(80,j);
    printf("%lli",s.phone);
    j++;
    }
    fclose(fp);
    getch();
}*/


void delete_supplier()
{
    system("cls");
    int supplier;
    FILE *fn,*fp;
    char x;

    printf("Enter Supplier ID to Delete the Supplier\n");
    scanf("%d",&supplier);
    fn = fopen("supplier.dat","rb+");
    fp = fopen("temp.dat","wb+");
    while(fread(&s,sizeof(s),1,fn))
    {
        if(s.id != supplier){
                fwrite(&s,sizeof(s),1,fp);
        }
        else{   system("cls");
                printf("\n");
                printf("ID : %d    ",s.id);
                printf("Name : %s    ",s.name);
                printf("Address : %s    ",s.address);
                printf("Phone No :%lli    ",s.phone);
            printf("\n Are you sure to delete the record, Press Y for Yes  ");
            x = getch();
            if((x == 'Y'||x=='y')==0){
                fwrite(&s,sizeof(s),1,fp);
            }
        }

    }
    fclose(fp);
    fclose(fn);
    remove("supplier.dat");
    rename("temp.dat","supplier.dat");
    getch();

   /* system("cls");
    gotoxy(20,1);printf("\n\t\t\t\t\t Supplier Information");
    gotoxy(20,3);
    printf("ID          Name                    Address                 Contact");
    fp=fopen("supplier.dat","rb+");
    while(fread(&s,sizeof(s),1,fp))
    {
    gotoxy(20,4);
    printf("%d",s.id);
    gotoxy(32,5);
    printf("%s",s.name);
    gotoxy(56,6);
    printf("%s",s.address);
    gotoxy(80,7);
    printf("%lli",s.phone);
    }
    fclose(fp);
    getch();
*/
view_supplier();
getch();
}

void search_supplier()
{
    system("cls");
	int id ;
	fp = fopen("supplier.dat","rb+");
	printf("Enter Supplier ID :");
	scanf("%d",&id);
	printf("Searching...");

//	system("cls");
	while(fread(&s, sizeof(s),1, fp)==1)
	{
		if(s.id==id)
		{
			printf("\nThe Suupplier is Avaliable");
			printf("\nID : %d",s.id);
			printf("\nName : %s",s.name);
		}
		else
		{
			printf("The Supplier is not Avalaible");
		}
		search_supplier();
	}
	getch();
	fclose(fp);
}


void customer()
{
    int x=1;
    do{
			system("cls");
			gotoxy(50,2);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  CUSTOMER INFORMATION SECTION	\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
			gotoxy(50,4);printf("\xB2\xB2\xB2 [1] ADD    CUSTOMER");
			gotoxy(50,6);printf("\xB2\xB2\xB2 [2] VIEW   CUSTOMER");
			gotoxy(50,8);printf("\xB2\xB2\xB2 [3] MODIFY CUSTOMER");
			gotoxy(50,10);printf("\xB2\xB2\xB2 [4] SEARCH CUSTOMER");
			gotoxy(50,12);printf("\xB2\xB2\xB2 [5] DELETE CUSTOMER");
			gotoxy(50,14);printf("\xB2\xB2\xB2 [6] CLOSE APPLICATION");
			gotoxy(50,16);printf("\xB2\xB2\xB2 [7] BACK TO MAIN MENU");
			gotoxy(50,18);printf("Enter Choice:\t");
			switch(getch())
				{
					case '1':
						system("cls");
						add_customer();
						break;
					case '2':
						system("cls");
						view_customer();
					case '3':
						system("cls");
						modify_customer();
						break;
					case '4':
						system("cls");
						search_customer();
						break;
					case '5':
						system("cls");
						delete_customer();
						break;
					case '6':
						system("cls");
						exit(0);
					case '7':
						main();
    //default:
      //  break;
				}
				if(x==0)break;
			}while(x);
}


struct custo
{
    int id;
    char name[20], address[50];
    long long phone;

};
struct custo c;
void add_customer()
{
    m:
fp=fopen("customer.dat","ab+");
system("cls");
gotoxy(50,2);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 CUSTOMER ADD SECTION	\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
fflush(stdin);
gotoxy(50,4);printf("\xB2\xB2\t Enter ID :\t");
scanf("%d",&c.id);
fflush(stdin);
gotoxy(50,4);printf("\xB2\xB2\t Enter Name :\t");
gets(c.name);
gotoxy(50,6);printf("\xB2\xB2\t Enter Address :\t");
gets(c.address);
gotoxy(50,8);printf("\xB2\xB2\t Enter Phone No :\t");
scanf("%lli",&c.phone);
fseek(fp,0,SEEK_END);
fwrite(&c,sizeof(c),1,fp);
fclose(fp);
printf(" Again Enter student info(y/n)" );
if(getch()=='y')
goto m;
else
supplier();

}

void view_customer()
{

	system("cls");
	int j=6;
	gotoxy(50,1);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2	CUSTOMER INFORMATION SECTION	\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(50,4);printf("ID          NAME                    ADDRESS               CONTACTS");
	fp=fopen("customer.dat","rb+");
	while(fread(&c,sizeof(c),1,fp))
		{
			gotoxy(50,j);
			printf("%d",c.id);
			gotoxy(62,j);
			printf("%s",c.name);
			gotoxy(86,j);
			printf("%s",c.address);
			gotoxy(108,j);
			printf("%lli",c.phone);
			j++;
		}
		fclose(fp);
	getch();
}

void modify_customer()
{

}

void search_customer()
{

}

void delete_customer()
{

    system("cls");
    int j=10;
    int customer;
    FILE *fn,*fp;
    char x;
	gotoxy(50,2);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 CUSTOMER DELETE SECTION \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(50,3);printf("\xB2\xB2\xB2 Enter ID :\t");
    scanf("%d",&customer);
    fn = fopen("customer.dat","rb+");
    fp = fopen("tempo.dat","wb+");
    while(fread(&c,sizeof(c),1,fn))
    {
        if(c.id != customer){
                fwrite(&c,sizeof(c),1,fp);
        }
        else{
                //printf("\n");
               // system("cls");
				gotoxy(50,5);printf("\xB2\xB2\xB2 ID   	   : %d    ",c.id);
                gotoxy(50,6);printf("\xB2\xB2\xB2 NAME     : %s    ",c.name);
                gotoxy(50,7);printf("\xB2\xB2\xB2 Address  : %s    ",c.address);
                gotoxy(50,8);printf("\xB2\xB2\xB2 Phone No :%lli    ",c.phone);
				gotoxy(50,9);printf("\t\t Are you sure to delete the record, Press Y for Yes  ");
            x = getch();
            if((x == 'Y'||x=='y')==0){
                fwrite(&c,sizeof(c),1,fp);
            }
        }

    }
    fclose(fp);
    fclose(fn);
    remove("customer.dat");
    rename("tempo.dat","customer.dat");
    view_customer();
    getch();

}
   /* system("cls");
    gotoxy(20,1);printf("\n\t\t\t\t\t Customer Information");
    gotoxy(20,3);
    printf("ID          Name                    Address                 Contact");
    fp=fopen("tempo.dat","rb+");
    while(fread(&c,sizeof(c),1,fp))
    {
    gotoxy(20,j);
    printf("%d",c.id);
    gotoxy(32,j);
    printf("%s",c.name);
    gotoxy(56,j);
    printf("%s",c.address);
    gotoxy(80,j);
    printf("%lli",c.phone);
    j++;
    }
    fclose(fp);
    getch();
*/




void medicine()
{
    do{
        system("cls");
        gotoxy(50,3);printf("[1] ADD    MEDICINE \n");
        gotoxy(50,4);printf("[2] VIEW   MEDICINE \n");
        gotoxy(50,5);printf("[3] UPDATE MEDICINE \n");
        gotoxy(50,6);printf("[4] SEARCH MEDICINE \n");
        gotoxy(50,7);printf("[5] DELETE MEDICINE \n");
        gotoxy(50,8);printf("[6] BACK TO MAIN\n");
        gotoxy(50,9);printf("[7] CLOSE APPLICATION\n");
        gotoxy(50,10);printf("Enter Choice:\t");
        switch(getch())
            {
                case '1':
                    add_medicine();
                    break;
                case '2':
                    view_medicine();
                    break;
                case '3':
                    modify_medicine();
                    break;
                case '4':
                    search_medicine();
                    break;
                case '5':
                    delete_medicine();
                    break;
                case '6':
                    main();
                case '7':
                    exit(0);
                    break;
                default:
                    medicine();
                    break;
            }
        }while(1);

}

void add_medicine()
{
    m:
    fp=fopen("medicine.dat","ab+");
    system("cls");
    printf("****** Fill the Medicine Information ********");
    printf("\nEnter Rack No:");
    scanf("%d",&m.rack);
    fflush(stdin);
    system("cls");
    printf("\nEnter Medicine Name :");
    gets(m.name);
    printf("Enter Medicine Qty :");
    scanf("%d",&m.qty);
    system("cls");
    fflush(stdin);
    printf("\nEnter Manufacturing Date:");
    gets(m.m_date);
    system("cls");
    fflush(stdin);
    printf("\nEnter Expiring Date:");
    gets(m.e_date);
    fflush(stdin);
    printf("\nEnter Medicine Price:");
    scanf("%f",&m.price);
    fseek(fp, 0, SEEK_END);
    fwrite(&m, sizeof(m), 1, fp);
    fclose(fp);
    printf("Again Enter Medicine Info(y/n)");
    if(getch()=='y')
    goto m;
    else
    {
        medicine();
    }
}


void view_medicine()
{
    int j = 5;
    struct medicine m;
    system("cls");
    FILE *fp;
    gotoxy(10,1);printf("************************************* MEDICINE INFORMATION *************************************\n");
    gotoxy(10,3);
    printf("Rack No.        Qty(Pices)      Medicine_Name       Price(Per.)     MGF_Date        EXP_Date");
    fp=fopen("medicine.dat","rb+");
    while(fread(&m,sizeof(m),1,fp))
        {
       //     gotoxy(20,j);
        //    printf("%d",m.id)
            gotoxy(10,j);
            printf("%d",m.rack);
            gotoxy(26,j);
            printf("%d",m.qty);
            gotoxy(42,j);
            printf("%s",m.name);
            gotoxy(62,j);
            printf("%.2f",m.price);
            gotoxy(78,j);
            printf("%s",m.m_date);
            gotoxy(94,j);
            printf("%s",m.e_date);
            j++;
        }
        fclose(fp);
/*		ft = fopen("supplier.dat","ab+");
		while(fread(&s, sizeof(s),1,ft))
		{
			gotoxy(120,j);printf("%s",s.name);
			fclose(ft);
		}
  */      getch();
}
void modify_medicine()
{

}

void search_medicine()
{

}

void delete_medicine()
{
    system("cls");
    int j=5;
    int medicine;
    FILE *fn,*fp;
    char x;

    printf("Enter Medicine Rack to Delete the Medicine:\n");
    scanf("%d",&medicine);
    fn = fopen("medicine.dat","rb+");
    fp = fopen("tempo.dat","wb+");
    while(fread(&m,sizeof(m),1,fn))
    {
        if(m.rack != medicine){
                fwrite(&m,sizeof(m),1,fp);
        }
        else{
                printf("\n");
                printf("Rack : %d    ",m.rack);
                printf("Name : %s    ",m.name);
            printf("\n Are you sure to delete the record, Press Y for Yes  ");
            x = getch();
            if((x == 'Y'||x=='y')==0){
                fwrite(&m,sizeof(m),1,fp);
            }
        }

    }
    fclose(fp);
    fclose(fn);
    remove("medicine.dat");
    rename("tempo.dat","medicine.dat");
    view_medicine();
    getch();

}


void design()
{
        int i;
        system("cls");
        gotoxy(50,2);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MEDICAL STORE INFORMATION SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
     do{
        gotoxy(50,4);printf("\xB2\xB2\xB2 [1] SUPPLIER SECTION");
        gotoxy(50,6);printf("\xB2\xB2\xB2 [2] CUSTOMER SECTION");
        gotoxy(50,8);printf("\xB2\xB2\xB2 [3] MEDICINE SECTION\n");
        gotoxy(50,10);printf("\xB2\xB2\xB2 [4] CLOSE APPLICATION\n");
        gotoxy(50,12);printf("Enter Choice:\t");
        switch(getch())
        {
        case '1':
            supplier();
            break;
        case '2':
            customer();
            break;
        case '3':
            medicine();
            break;
        case '4':
            exit(0);
        default:
            main();
            break;
        }
        getch();
    }while(1);

}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
