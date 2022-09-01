#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include<time.h>
#include<wchar.h>
#include<locale.h>
#define MAX_SIZE 100
typedef struct
{
    char firstName[40];
    char lastName[40];
    char mobileNumber[20];
    float GRANDtotal;
    float amountDUE;
    float amountPAID;
    char item_order[21][30];
    int item_num;

} Info;
// array to hold contact
Info information[MAX_SIZE];
// enum for different search type
typedef enum
{
    FIRST_NAME,
    LAST_NAME,
    MOBILE_NUMBER
} search_t;

// current size of the phonebook array
int currentSize = 0;

struct items
{
    char item[20];

    float price;
    int quantity;
};

struct orders
{

    int itmNo;
    struct items itm[50];
};

float item_price[]={40,85,60,40,75,15,4,10,10,20,20,50,35,50,90,25,18,68,30,38,25};
char item_menu[10][30]={"Latte","Galao","Espreso","Doppio","Cortado","Tea","Water","Coke","Sprite","Pepsi" };

// prototype--------------------------------------
void addEntry();     //sadman
void display(int index);//rafsun
void search(char *key, search_t type);//raiyan
void strlower(char *str);//raiyan
void readFromFile();//raiyan
void saveToFile();//raiyan
void displayAll();//rafsun
void clear();//rafsun
void removeEntry(char *mobileNumber);//raiyan

void printMenu(); //rafsun
void delete_info();
void search_option();

//Color if life_______________
void red ()
{
    printf("\033[1;31m");
}

void yellow()
{
    printf("\033[1;33m");
}


void green()
{
    printf("\033[0;32m");
}
void black ()
{
    printf("\033[0;30m");
}
void cyan()
{
    printf("\033[0;36m");
}
void purple()
{
    printf("\033[0;35m");
}
void blue()
{
    printf("\033[0;34m");
}




void reset ()
{
    printf("\033[0m");
}


// Work of main******************************************************************************************
//**********************************************************************************************************
int main()
{
    readFromFile();

    char selection[50];
    int choice;

    while (1)
    {
        system("color 0f");

        cyan();
        printf("|===============================================|\n");
        printf("|              ADMINISTRATION MENU              |\n");
        printf("|===============================================|\n");

        reset();
        printf("\t|------------------------------|\n");
        printf("\t|        1.Place an order      |\n");
        printf("\t|------------------------------|\n");
        green();
        printf("\t|------------------------------|\n");
        printf("\t|  2.Display all information   |\n");
        printf("\t|------------------------------|\n");
        reset();
        printf("\t|------------------------------|\n");
        printf("\t|  3.Search Customer's Order   |\n");
        printf("\t|------------------------------|\n");
        /*printf("\t|------------------------------|\n");
        printf("\t|      4.Search by Last Name   |\n");
        printf("\t|------------------------------|\n");
        printf("\t|------------------------------|\n");
        printf("\t|   5.Search by Mobile Number  |\n");
        printf("\t|------------------------------|\n");
        */
        purple();
        printf("\t|------------------------------|\n");
        printf("\t|           4.Delete           |\n");
        printf("\t|------------------------------|\n");
        reset();
        printf("\t|------------------------------|\n");
        printf("\t|    5.Save to database        |\n");
        printf("\t|------------------------------|\n");
        red();
        printf("\t|------------------------------|\n");
        printf("\t|          6. Exit             |\n");
        printf("\t|------------------------------|\n");
        reset();

        do
        {
            //puts("\tEnter your Choice");
            //gets(selection);
            printf("\n\tEnter your Choice: ");
            scanf("%s",&selection);
            printf("_________________________________________\n");

            fflush(stdin);
            choice = atoi(selection);
        }
        while (choice < 1 || choice > 6);

        switch (choice)
        {
        case 1:
            addEntry();
            clear();
            break;
        case 2:
            displayAll();
            clear();
            break;
        case 3:
            //printf("Enter first name to search the person: ");
            //gets(selection);
            //search(selection, FIRST_NAME);
            search_option();
            clear();
            break;
        /*case 4:
            printf("Enter last name to search the person: ");
            gets(selection);
            search(selection, LAST_NAME);
            clear();
            break;
        case 5:
            printf("Enter mobile number to search the person: ");
            gets(selection);
            search(selection, MOBILE_NUMBER);
            clear();
            break;
            */
        case 4:
            delete_info();
            clear();
            break;
        case 5:
            saveToFile();
            clear();
            break;
        case 6:
            exit(0);
            clear();
            break;

        default:
            break;
        }
    }

    return 0;
}
// end of main******************************************************************************************
//**********************************************************************************************************
void addEntry()
{
    int i = 0;
    if (currentSize == MAX_SIZE)
    {
        puts("Information is full!!");
        return;
    }
    Info c;
    printf("\tEnter First name: ");
    gets(c.firstName);
    printf("\tEnter Second name: ");
    gets(c.lastName);
    printf("\tMobile Number: ");
    gets(c.mobileNumber);
    // printf("printf item 1:");
    // gets(c.item_order[i]);
    // i++;
    // printf("printf item 2:");
    // gets(c.item_order[i]);
    system("cls");
    ///----------------//--------wroking cash memo------------------------------------///----------------------
    char choice;
    struct orders order;

    float total = 0;
    char reccho;
    float amountPaid;
    int n;
    int var_k;
    int index=0;


    printMenu();

    while (1)
    {
        printf("\n\tReady to take an order?[y/n]\n");
        scanf("%c", &choice);
        fflush(stdin);

        if (choice == 'y')
        {

            printf("\tHow many items you want to order:     ");
            scanf("%d", &n);
            c.item_num=n;

            for (int i = 0; i < n; i++)
            {
                fgetc(stdin);

                printf("\tEnter %d item number:\t       ", i + 1);
                scanf("%d",&var_k);
                //gets(c.item_order[i]);
                //strcat(item_menu[k]," ");
                strcpy(c.item_order[i],item_menu[var_k-1]);
                //char temp_str[40];
                //strcat(item_menu[var_k-1],"a");
                //printf("%s\n",item_menu[var_k-1]);
                //strcat(temp_str,item_menu[var_k-1]);

                //strcpy(order.itm[i].item,item_menu[var_k-1]);
                //fflush(stdin);
                /*for(int j=0;j<12;j++){

                    if(  strcmp(c.item_order[i],item_menu[j])==0){
                        index=j;
                    }
                }
                */

                //fgets(order.itm[i].item, 20, stdin);
                fflush(stdin);
                //this is the place why space is taking-------------------------------------
                //////////////////////////////////////////////////////////////////////////////////
                 char temp_str[40];
                strcpy(temp_str,item_menu[var_k-1]);
                strcat(temp_str,"a");
                                                //printf("%s\n",item_menu[var_k-1]);
                                                //printf("%s\n",temp_str);
                //strcat(temp_str[i],item_menu[var_k-1]);
                //----------------

                strcpy(order.itm[i].item,temp_str);

                order.itm[i].item[strlen(order.itm[i].item)-1]=0;
                //c.item_order[i][strlen(c.item_order[i]) - 1] = 0;

                printf("\tPlease enter the quantity:     ");
                scanf("%d", &order.itm[i].quantity);
                fflush(stdin);

               // printf("\tEnter the unit price:\t       ");
                //scanf("%f", &order.itm[i].price);
               // fflush(stdin);
                 order.itm[i].price= item_price[var_k-1];
                total += order.itm[i].quantity * order.itm[i].price;
                //total += order.itm[i].quantity * item_price[var_k-1];
            }

            printf("Do you want a receipt for your order?\n");
            scanf("%c", &reccho);
            fflush(stdin);

            printf("Your bill is %.2f without VAT\nMake your payment:\n", total);
            scanf("%f", &amountPaid);
            ////storing paid amount in c
            c.amountPAID=amountPaid;
            fflush(stdin);

            if (reccho == 'y')
            {
                system("cls");
                setlocale(LC_ALL, "en_US.UTF-8");
                wchar_t box = 0x2592; // for the box box code alongside of guest copy
                time_t t;
                time(&t);
                printf("\t\t\t\t       Welcome to ARS Cafe\n");
                printf("\t\t\t\t      Contact no. 01*********\n");
                printf("\t\t\t\t     %s \n", ctime(&t));
                printf("\t\t\t-----------------------------------------------\n");
                printf("\n");
                printf("\t\t\t-----------------------------------------------\n");
                printf("\t\t\t%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc", box, box, box, box, box, box, box, box, box, box, box, box, box, box, box);
                printf("G u e s t C o p y"); // Put here the name of customer using %s
                printf("%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc\n", box, box, box, box, box, box, box, box, box, box, box, box, box, box, box);
                printf("\t\t\tInvoice:%d\n", rand());
                printf("\t\t\tToken for:%s\n", c.firstName); // Use count++ somewhere in code if possible while linking
                printf("\t\t\tItem name\t  Qty\t    Price\t T.Price\n");

                for (int i = 0; i < n; i++)
                {
                    printf("\t\t\t%s\t\t   %d\t    %.2f\t %.2f\n", order.itm[i].item, order.itm[i].quantity, order.itm[i].price, order.itm[i].price * order.itm[i].quantity);
                } // use %s %d %f %lf as necessary here to print the prices of food
                // printf("\t\t\tLatté           2           100        %d\n",2*100);
                printf("\t\t\t-----------------------------------------------\n");
                printf("\t\t\t-----------------------------------------------\n");
                printf("\t\t\tTOTAL:                                  $%6.2f\n", total);
                printf("\t\t\tSD(2%c):                                  $%5.2f\n", 37, (0.02 * total)); // 37 is the ascii value for % sign
                float total1 = 0.02 * total;
                printf("\t\t\tVAT(5%c):                                 $%5.2f\n", 37, (0.05 * total));
                float total2 = 0.05 * total;
                printf("\t\t\t-----------------------------------------------\n");
                float gt = total + total1 + total2;
                printf("\t\t\tTOTAL:                                  $%6.2f\n", gt);
                printf("\t\t\tDISCOUNT:                               $%6.2f\n", gt * 0.1);
                float gt1 = gt * 0.1;
                printf("\t\t\tGRANDTOTAL:                             $%6.2f\n", gt - gt1);
                float grandTotal = gt - gt1;
                //storing grand total in c
                c.GRANDtotal= grandTotal;
                red();
                printf("\t\t\tAMOUNT PAID:                            $%6.2f\n", amountPaid);
                reset();
                if (amountPaid > grandTotal)
                {
                    printf("\t\t\tCHANGE:                                 $%6.2f\n", amountPaid - grandTotal);
                }
                else
                {
                    float due= grandTotal - amountPaid;
                    //storing due amount in c
                    c.amountDUE=due;
                    yellow();
                    printf("\t\t\tAMOUNT DUE:                             $%6.2f\n", due);
                    reset();

                }
                printf("\t\t\t-----------------------------------------------\n");
                red();
                printf("\t\t\t\t\t   P A I D\n"); // we print paid or unpaid by checking if due is 0 or not using if else, if possible
                reset();
                printf("\t\t\t-----------------------------------------------\n");
                printf("\t\t  All VAT and SD are according to the rules of Government\n");
                printf("\t\t\tFor more query mail us at arzcafe@gmail.com\n");
                printf("\t\t\t-------------------------------------------\n");
                printf("\t\t\t\t   Thanks for visiting us!\n");
                cyan();
                printf("\n\t\t\tSAVE the Data to permanently save the info !\n");
                reset();
            }
            else
            {
                printf("\n                \t\t\tThank you for ordering!\n");
                cyan();
                printf("\n\t\t\t   SAVE the Data to permanently save the info !\n");
                reset();
            }
        }
        else
        {
            break;
        }
    }


    ////////-----dont touch
    ///////////--------------------------------------------------------------------------------------

    information[currentSize] = c;
    ++currentSize;
}
void display(int index)
{
    Info c = information[index];
    if (index < 0 || index >= currentSize)
    {
        puts("Error Index!");
        return;
    }
    green();
    printf("|================================|\n");
    reset();
    printf("| ORDER INFO:                    |\n");
    printf("|________________________________|\n");
    printf("| Customer Info:                 |\n");
    printf("|________________________________|\n");
    printf("| Enter 1st name:%s\n", c.firstName);
    printf("| Enter 2nd name:%s\n", c.lastName);
    printf("| Mobile number:%s\n", c.mobileNumber);
    printf("|________________________________\n");
    printf("| Ordered Items:                 |\n");
    printf("|________________________________|\n");

    // printf("Item 1: %s\n", c.item_order[0]);
    // printf("Item 2: %s\n", c.item_order[1]);
    for (int i = 0; i <c.item_num; i++)
    {
        printf("| Item %d: %s\n", i+1,c.item_order[i]);
    }

    printf("|_________________________________\n");
    red();
    printf("| PAID amount: $%.2f\n",c.amountPAID);
    yellow();
    printf("| DUE amount: $%.2f\n",c.amountDUE);
    reset();
    printf("| BILL with SD+VAT: $%.2f\n",c.GRANDtotal);

}
//-----------------------------------
void search(char *key, search_t type) // ar type pathabo na karon er readability onek kom. search_t pathabo
{
    int found = 0;
    int i;
    strlower(key);
    char content[50];
    if (type == FIRST_NAME)
    {
        // search by 1st name
        for (i = 0; i < currentSize; i++)
        {
            strcpy(content, information[i].firstName);
            strlower(content);
            if (strcmp(content, key) == 0)
            {

                display(i);
                found = 1;
            }
        }
    }
    else if (type == LAST_NAME)
    {
        // search by 2nd name
        for (i = 0; i < currentSize; i++)
        {
            strcpy(content, information[i].lastName);
            strlower(content);

            if (strcmp(content, key) == 0)
            {

                display(i);
                found = 1;
            }
        }
    }
    else if (type == MOBILE_NUMBER) // muloto enum ei kaj kore je MOBILE_NUMBER=2; assign korar moto
    {
        // search by mobile num
        for (i = 0; i < currentSize; i++)
        {
            strcpy(content, information[i].mobileNumber);

            strlower(content);
            if (strcmp(content, key) == 0)
                // if(strcmp(phonebook[i].monileNumber,key)==0) chilo eita korle hobe na karon key sob lower case jekhane input sob lower na
            {

                display(i);
                found = 1;
            }
        }
    }
    else
    {
        puts("error ! invalid search type");
        return;
    }
    if (!found)
    {
        puts("Not found in the phonebook"); // jodi key ei na mile tokhon
    }
}
//------------------display all code-------------
void displayAll()
{
    for (int i = 0; i < currentSize; i++)
    {
        display(i);
        puts(""); // for extra line
    }
}

//------------- ---------------------------------
// CAUTION (this function will modified the given string)!!
// ejonno temp string pass korle kicchu hobe na
void strlower(char *str)
{
    int len = strlen(str);
    int i;
    for (i = 0; i < len; i++)
    {
        str[i] = tolower(str[i]);
    }
}
//----------------clear-------------
void clear()
{
    system("PAUSE"); // it will show, press any key to continue
    system("CLS");
}
//------------------------------

void printMenu()
{
    yellow();
    printf("  \t|----------------------------------------------------------------------------------------|\n");
    printf("  \t|                                          MENU                                          |\n");
    printf("  \t|________________________________________________________________________________________|\n");
    cyan();



    printf("  \t|----------------------------------------------------------------------------------------|\n");
    printf("  \t| Coffee and Drinks                                                                      |\n");
    printf("  \t|----------------------------------------------------------------------------------------|\n");
    reset();
    printf("  \t|    Coffee:                 Price             Drinks:                   Price           |\n");
    printf("  \t|    1.Latte                  $40              7.Water                    $4             |\n");
    printf("  \t|    2.Galao                  $85              8.Coke (250 mL)            $10            |\n");
    printf("  \t|    3.Espreso                $60              9.Sprite (250 mL)          $10            |\n");
    printf("  \t|    4.Doppio                 $40              10.Pepsi (250 mL)          $20            |\n");
    printf("  \t|    5.Cortado                $75              11.Juice                   $20            |\n");
    printf("  \t|    6.Tea                    $15                                                        |\n");
    cyan();
    printf("  \t|----------------------------------------------------------------------------------------|\n");
    printf("  \t| Snacks and Dessert                                                                     |\n");
    printf("  \t|----------------------------------------------------------------------------------------|\n");
    reset();
    printf("  \t|    Snacks:                 Price                 Dessert:              Price           |\n");
    printf("  \t|    12.Burger                $50                  18.Cake                $68            |\n");
    printf("  \t|    13.Chicken               $35                  19.Brownie             $30            |\n");
    printf("  \t|    14.Hotdog                $50                  20.Pastry              $38            |\n");
    printf("  \t|    15.Pizza (medium)        $90                  21.Muffin              $25            |\n");
    printf("  \t|    16.Patties               $25                                                        |\n");
    printf("  \t|    17.Singara (4 pc)        $18                                                        |\n");
    printf("  \t|----------------------------------------------------------------------------------------|\n");
    reset();
    printf("\n");
    yellow();
    printf("  \t                    **All prices are subject to 2%% SD and 5%% VAT**                      \n");
    reset();

}
//------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------
//----------removing a entry------------
void removeEntry(char *mobileNumber)
{
    if(currentSize==0){
        printf("Database is empty! Nothing to show\n");
    }

    int j;
    int count = 0;
    for (int i = 0; i < currentSize; i++)
    {
        if (strcmp(information[i].mobileNumber, mobileNumber) == 0)
        {
            for (j = i; j < currentSize - 1; j++)
            {
                information[j] = information[j + 1];
            }
            // it's reset the  value
            strcpy(information[j].firstName, "");
            strcpy(information[j].lastName, "");
            strcpy(information[j].mobileNumber, "");
            currentSize -= 1;
            ++count;
        }
    }
    if (count == 0)
    {
        puts("No information deleted\n");
    }
    else
    {
        printf("%d customer information deleted\n", count);
    }
}
//-------------read form file--------------
void readFromFile()
{
    FILE *fp;
    if ((fp = fopen("C:\\Users\\Raiyan\\Desktop\\mygupi.txt", "r")) == NULL)
    {
        puts("CAN NOT LOAD THE DATABASE!!");
        return;
    }

    // it's read the currentsize of the phone book
    if (fread(&currentSize, sizeof(currentSize), 1, fp) != 1)
    {
        puts("ERROR IN READING THE DATA!");
        return;
    }

    // it's read the phone book content
    if (fread(information, sizeof(information), 1, fp) != 1)
    {
        puts("ERROR IN READING THE DATA!");
        return;
    }
}
//-------------------------save to file er function------------------file a likhe save kore
void saveToFile()
{
    FILE *fp;
    if ((fp = fopen("C:\\Users\\Raiyan\\Desktop\\mygupi.txt", "w")) == NULL)
    {
        puts("Error: can't create a database file!");
        return;
    }

    // Save the current size of the phonebook
    if (fwrite(&currentSize, sizeof(currentSize), 1, fp) != 1)
    {
        puts("ERROR IN SAVING THE DATA!");
        return;
    }

    // it's save the phonebook contents info
    if (fwrite(information, sizeof(information), 1, fp) != 1)
    {
        puts("ERROR IN SAVING THE DATA!");
        return;
    }
    green();
    puts("Information saved to database successfully!");
    reset();
}
void delete_info()
{
    int pass;
    int pass_key=1234;
    char mobile_num[30];
    red();
    printf("\tThis is a password protected sector\n");
    reset();
    printf("\tPleae Enter the password:");
    scanf("%d",&pass);
    fflush(stdin);
    if(pass_key==pass)
    {

        printf("\t|------------------------------|\n");
        printf("\t|     1.Delete an order        |\n");
        printf("\t|------------------------------|\n");

        printf("\t|------------------------------|\n");
        printf("\t|  2.Remove all Information    |\n");
        printf("\t|------------------------------|\n");

        printf("\tEnter your choice:");
        scanf("%d",&pass_key);
        fflush(stdin);
        //FILE *fp;
        //fp = fopen("information.db", "w");
        switch(pass_key)
        {
        case 1:
            printf("\tEnter the person Mobile Number:");
            gets(mobile_num);
            fflush(stdin);
            removeEntry(mobile_num);
            break;
        case 2:
            FILE *fp;
            fp = fopen("C:\\Users\\Raiyan\\Desktop\\mygupi.txt", "w");
            purple();
            printf("\n\tAll information is deleted\n");
            reset();
            break;
        }
    }

}

void search_option()
{
    int choice;
    char selection [40];
    printf("\t|------------------------------|\n");
    printf("\t|     1.Search by First Name   |\n");
    printf("\t|------------------------------|\n");
    printf("\t|------------------------------|\n");
    printf("\t|      2.Search by Last Name   |\n");
    printf("\t|------------------------------|\n");
    printf("\t|------------------------------|\n");
    printf("\t|   3.Search by Mobile Number  |\n");
    printf("\t|------------------------------|\n");
    printf("\tEnter your Choice:");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        printf("Enter first name to search the person: ");
        scanf("%s",&selection);
        fflush(stdin);
        search(selection, FIRST_NAME);
        clear();
        break;
    case 2:
        printf("Enter last name to search the person: ");
      scanf("%s",&selection);
        fflush(stdin);
        search(selection, LAST_NAME);
        clear();
        break;
    case 3:
        printf("Enter mobile number to search the person: ");
       scanf("%s",&selection);
        fflush(stdin);
        search(selection, MOBILE_NUMBER);
        clear();
        break;


    }
}
