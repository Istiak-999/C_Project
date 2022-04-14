//online shop management system

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void logo();
void welcome();

void log_in();
void registration();
void about();
void notice();
void forget_pass();

void product_list();
void add_cart();
void pay();
void return_product();
void cancel();
void discount();
void review();
void change_pass();
void customer_care();
void admin();
void log_out();

//part of admin function
void calculator();
void worker_information_add();
void worker_information_list();


//global variables
int password;
int customer_id;
int n;

//main function
int main()
{

    logo();
    welcome();



}


struct login
{
    int number;
    char firstname[30];
    char lastname[30];
    char username[30];
    char password[20];
};



//main logo
void logo()
{
    printf("\t\t\t   ***************************************************************\n");
    printf("\t\t\t   *-------------------------------------------------------------*\n");
    printf("\t\t\t   *|                      online shoping center                |*\n");
    printf("\t\t\t   *-------------------------------------------------------------*\n");
    printf("\t\t\t   ***************************************************************\n");
}


//welcome site
void welcome()
{

xy:
    printf("\n\n\n\t\t\t                       Welcome to our shop");
    printf("\n\t\t\t                       -------------------");
    printf("\n\n\n\t1.Log in");
    printf("\n\n\t2.Sign up");
    printf("\n\n\t3.About us");
    printf("\n\n\t4.Notice Board");
    printf("\n\nEnter no what do you want to do= ");
    scanf("%d",&n);

    system("cls");
    logo();

    switch(n)
    {
    case 1:

        log_in();                                                            //call login function
        break;
    case 2:

        registration();                                                      //call registration function
        break;
    case 3:

        about();                                                             //call about function
        break;
    case 4:

        notice();                                                           //call notice function
        break;
    default:

        printf("\n\nInvalid keyword please choice between options");
        goto xy;

    }

}

//these functions are part of welcome function
//login
void log_in()
{
    char name[30],pass[20];
    struct login acc;

    FILE *reg;
    reg=fopen("reg.txt","r");


    printf("\n\n\n\t\t\t\t\t## ## ## ## ## Log in ## ## ## ## ##\n\n\n");
    printf("user name = ");
    scanf("%s",&name);

    printf("\n\npassword = ");
    scanf("%s",&pass);

       if(reg == NULL)
    {
        system ("cls");
        logo();

        printf("\n\n\n\n\nyou are not registered.please complete your registration...");
        registration();


    }
    while(fread(&acc,sizeof(acc),1,reg))
    {


         if(strcmp(name,acc.username)==0 && strcmp (pass,acc.password)==0)
        {
            system ("cls");
            logo();
            printf("\n\n\n\n\n\n\n\t\t\t\t\t## ## ## ## ## WELCOME LOGIN SUCCESSFULL ## ## ## ## ##\n\n\n");
            getch();


            main_menu();
            break;
        }

        else

        system ("cls");
        logo();

        printf("\n\n\nyour information is unknown.please input right information or registration first\n\n");
        printf("press 1 for registration\n\npress 2 for forget password\n");
        scanf("%d",&n);

        switch(n)
        {

        case 1:

            system ("cls");
            logo();

            registration();
            break;
        case 2:

            system ("cls");
            logo();

            forget_pass();
            break;
        }


    }
    fclose(reg);


}

//registration function
void registration()
{

    FILE *reg;
    reg=fopen("reg.txt","w");

    struct login acc;

    printf("\n\nEnter first name = ");
    scanf("%s",acc.firstname);

    printf("\n\nEnter last name = ");
    scanf("%s",acc.lastname);

    printf("\n\nEnter user name = ");
    scanf("%s",acc.username);

    printf("\n\nEnter password = ");
    scanf("%s",acc.password);

    fwrite(&acc,sizeof(acc),1,reg);
    fclose(reg);

    system ("cls");
    logo();
    log_in();

}

//forget pass
void forget_pass()
{

    FILE *f;
    f=fopen("forget.txt","w");

    struct login forget;

    printf("Enter user name = ");
    scanf("%s",forget.username);

    printf("\n\n\nEnter new password = ");
    scanf("%s",forget.password);

    printf("\n\nEnter mobile no = ");
    scanf("%s",forget.firstname);

    printf("\n\npin = ");
    scanf("%s",forget.lastname);

    fwrite(&forget,sizeof(forget),1,f);
    fclose(f);


    char name1[30],pass1[20];

    f=fopen("forget.txt","r");

    system ("cls");
    logo();

    printf("\n\n\n\t\t\t\t\t## ## ## ## ## Log in ## ## ## ## ##\n\n\n");
    printf("user name = ");
    scanf("%s",&name1);

    printf("\n\npassword = ");
    scanf("%s",&pass1);

    while(fread(&forget,sizeof(forget),1,f))
    {
        if(strcmp(name1,forget.username)==0 && strcmp (pass1,forget.password)==0)
        {
            system ("cls");
            logo();

            printf("\n\n\nYour login is temporary.please contact with admin");
            getch();

            system ("cls");
            logo();

            printf("\n\n\n\n\n\n\n\t\t\t\t\t## ## ## ## ## WELCOME LOGIN SUCCESSFULL ## ## ## ## ##\n\n\n");
            getch();

            main_menu();

            break;
        }
        else

        system ("cls");
        logo();

        printf("\n\nplease registration\n\n");
        registration();

    }

    fclose(f);
}


//noticeboard
void notice()
{
    system ("cls");
    logo();

    printf("\n\n\n\t\t\t\t\t## ## ## ## ## NOTICE BOARD ## ## ## ## ##\n\n\n");
    printf("1. winter offer.Come first gain much.This winter we will provide\n");
    printf("   15 percent discount in all winter clothes.The stock is limited.\n");
    printf("   So take your one as soon as possible.\n\n");

    printf("2. Our COD system is close now.We will inform if we update it.\n\n");
    printf("3. For promote your business please contact us.\n\n");
    getch();

    system ("cls");
    logo();

    welcome();
}


//about
void about()
{
    system ("cls");
    logo();

    printf("\n\n\n\t\t\t\t\t## ## ## ## ## ABOUT US ## ## ## ## ##\n\n\n");

    printf("\n\n\n\t\t\there is our new site.We are still in developing mode.If you find any bug inform us.\n\t\t\tNow you can shopping more easily from here.Happy shopping. ");
    getch();

    system ("cls");
    logo();

    welcome();

}
//end of welcome function part



//main menu next all function will include here

void main_menu()
{

    system ("cls");
    logo();

xy:
    printf("\n\n\n\t1.search products");
    printf("\n\n\t2.return product");
    printf("\n\n\t3.cancel order");
    printf("\n\n\t4.discounts");
    printf("\n\n\t5.review");
    printf("\n\n\t6.change passwword");
    printf("\n\n\t7.customer care");
    printf("\n\n\t8.admin");
    printf("\n\n\t9.Logout");
    printf("\n\nEnter no what do you want to do= ");
    scanf("%d",&n);

    system("cls");
    logo();

    switch(n)
    {
    case 1:

        product_list();                                                              //call product list function
        break;
    case 2:

        return_product();                                                           //call return product function
        break;
    case 3:

        cancel();                                                                  //call cancel function
        break;
    case 4:

        discount();                                                                //call discount function
        break;
    case 5:

        review();                                                                  //call review function
        break;
    case 6:

        change_pass();                                                             //call change pass function
        break;
    case 7:

        customer_care();                                                           //call customer care function
        break;
    case 8:

        admin();                                                              //call calculator function
        break;

    case 9:

        log_out();                                                                 //call logout function
        break;
    default:

        printf("\n\nInvalid keyword please choice between options");
        goto xy;

    }
}



//review
void review()
{
    FILE *file;
    char r[50];
    int read;
    file=fopen("text.txt","a");
    printf("Enter your review:\n");

    scanf("%s",&r);

    printf("\nThanks for your review.\n\n");

    printf("*************Here are all the reviews*************\n\n");
    printf("I like it.\n");
    getch();
    main_menu();

    fclose(file);


}

//product list

void product_list()
{

    printf("\n\n\n\nHere our most reviewed products list(only for you): \n");
    printf("\n\nProduct number 1 = Dress\n\nProduct number 2 = Shirt\n ");
    scanf("%d",&n);

    system("cls");
    logo();

    if(n==1)
    {

        printf("\n\n\n\nDress is good quality.\ncolour:green\nprice 7000 tk only");

        add_cart();

    }
   else if(n==2)
    {

        printf("\n\n\n\nshirt is good quality.\ncolour:blue\nprice 2000 tk only");

        add_cart();

    }
    else
        main_menu();
}
//this function will enter in product list function
void add_cart()
{

    printf("\n\n\n\nIf You want to buy press 1 ,otherwise press cancel.\n ");
    scanf("%d",&n);

    if(n==1)
    {
        system("cls");
        logo();
        pay();

    }
    else
        {
         main_menu();
        }

}

//payment system
void pay()
{
    printf("\n\n\n\n1.Bkash 017********\n2.Rocket018********\n3.Nagad017********\n");
    scanf("%d",&n);

    system("cls");
    logo();

    printf("\n\n\n\nPlease wait for confirmation.After that You will get your product soon. Thank you");

    getch();
    main_menu();

}
//customer care
void customer_care()
{

xy:
    printf("\n\nwant help?? \n\n\t1.sms \n\n\t2.call\n");
    scanf("%d",&n);
    system("cls");
    logo();

    if(n==1)
    {

        printf("\n\n\n017******** give sms in this number.\nwe will contract with you.\nThank you\n\n");
        getch();
        main_menu();

    }
    else if(n==2)
    {

        printf("\n\n\nplease call in this number 018********.\nThank you\n\n");
        getch();
        main_menu();

    }
    else
    {
        printf("\n\n\nenter right number");
        goto xy;
    }

}

//password change
void change_pass()
{

    FILE *reg;
    reg=fopen("reg.txt","w");

    struct login acc;

    printf("\n\nEnter user name = ");
    scanf("%s",acc.username);

    printf("\n\nEnter password = ");
    scanf("%s",acc.password);

    fwrite(&acc,sizeof(acc),1,reg);
    fclose(reg);

    system ("cls");
    logo();
    log_in();

}


//discount
void discount()
{
    int amount;

    printf("\n\n\n\nThere are many discounts offers for you,depends on how much amount you want to spend.\n\nPlease enter the amount and see your offer.\n");
    printf("\n\nYour spending amount = ");
    scanf("%d",&amount);
    if(amount<1500)
    {
        printf("\nyou have to spend more money");
    }
    else if(2500>amount&&amount>=1500)
    {
        printf("\nyou will get free delivery");
    }
    else if(5000>amount&&amount>=2500)
    {
        printf("\nYou will get 10 percent discount");
    }
    else if (10000>amount&&amount>=5000)
    {
        printf("\nYou will get 20 percent discount");
    }
    else
    {
        printf("\nYou will get 30 percent discount");
    }

    getch();
    main_menu();

}

//logout system

void log_out()
{

    printf("\n\n\n\n\t\t\tLog out successful...");
    getch();

    system ("cls");
    logo();
    welcome();

}


//return system

void return_product()
{

    printf("\n\n\nwhy you want to return our product? If it damaged press 1\n");
    scanf("%d",&n);

    if(n==1)
    {
        printf("\nWe are really sorry for this product. You can return this product.please contact with us\n");
    }
    else
    {
        printf("\nsorry ,we can not return your product.This product is out of our return policy\n");
    }

    getch();
    main_menu();
}


//cancel
void cancel()
{

    int Date1,last_date,Date2;

    printf( "\n\n\n\nIf you want to cancel your order press 1\n");
    scanf("%d",&n);
    if(n==1)
    {
        printf("\n\nplease enter the Date you order = ");
        scanf("%d",&Date1);

        printf("\n\nplease enter todays date = ");
        scanf("%d",&Date2);

        last_date=Date1+2;
        if(Date2<=last_date)
        {
            printf("\n\nYour oder successfully canceled.");
        }
        else
            printf("\n\nsorry you can't cancel your order because it's more than 2 days");
    }
    else
    {
        printf("\n\nThanks for not cancel your products");
    }

    getch();
    main_menu();
}


//admin system
void admin()
{
    printf("\n\n\n\t1.profit calculator");
    printf("\n\n\t2.Add worker information");
    printf("\n\n\t3.see worker information\n");

    scanf("%d",&n);

    if(n==1)
        {
          calculator();
        }
    else if (n==2)
    {
        worker_information_add();
    }
    else if(n==3)
    {
        worker_information_list();
    }
    else
       {
         main_menu();
       }

}



//profit loss calculator
void calculator()
{
    int price[50],cost[50],rslt[50],i,sum=0;

    printf("\n\n\n\n\t\t\t*******Here you can see todays loss or profit*******\n\n\n\n");
    printf("please enter number of selling products =");
    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        printf("\n\nNumber %d product price = ",i+1);
        scanf("%d",&price[i]);
    }
    for(i=0; i<n; i++)
    {
        printf("\n\nNumber %d product cost = ",i+1);
        scanf("%d",&cost[i]);
    }
    for(i=0; i<n; i++)
    {
        rslt[i]=price[i]-cost[i];
    }
    for(i=0; i<n; i++)
    {
        sum=sum+rslt[i];
    }

    if(sum>0)
    {
        printf("\n\n\n\t\tToday your profit =%d",sum);
    }
    else if (sum<0)
    {
        printf("\n\n\n\ttoday your lose=%d",sum);
    }
    else
    {
        printf("\n\n\n\tToday you have no profit and no lose.");
    }

    getch();
    main_menu();
}



//admin part
void worker_information_add()
{
    int t;
    int *x=&t;
    FILE *worker;
    char name[20];
    int age;
    int id;
    int number;
    int i;
    worker=fopen("worker.txt","a");

    system("cls");
    logo();

    printf("\n\n\n\n\nEnter how many worker's information do you want to enter...\n");
    scanf("%d",&*x);
    for(i=0; i<*x; i++)
    {
        printf("Enter worker first name:\n");
        scanf("%s",&name);
        printf("Enter worker age:\n");
        scanf("%d",&age);
        printf("Enter worker id\n");
        scanf("%d",&id);
        fprintf(worker,"%s\t\t%d\t\t%d\t\t\t\n",name,age,id);
    }
    fclose(worker);

    getch();
    main_menu();

}



//admin part
void worker_information_list()
{

    system("cls");
    logo();

    FILE *worker;
    char name[20];
    int age;
    int id;
    int number;
    int i;
    worker=fopen("worker.txt","r");

    printf("\n\n\nEnter how many worker's info do you want to see...");
    scanf("%d",&n);
    printf("\n\n\nHere are all the information:\n\n\n");
    for(i=0; i<n; i++)
    {
        fscanf(worker,"%s\t\t%d\t\t%d\t\t\n",&name,&age,&id);
        printf("%s\t\t%d\t\t%d\t\t\n",name,age,id);

    }
    fclose(worker);

    getch();
    main_menu();

}
