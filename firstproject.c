#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include<time.h>
#include<locale.h>
#define SIZE 100
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
// array to hold information of customer and order
Info information[SIZE];
// enum for different search type
typedef enum
{
    FIRST_NAME,
    LAST_NAME,
    MOBILE_NUMBER
} search_t;

// current size of the information array
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

//array to hold the price of items
float item_price[]={40,85,60,40,75,15,4,10,10,20,20,50,35,50,90,25,18,68,30,38,25};
//array to hold the items
char item_menu[21][30]={"Latte","Galao","Espreso","Doppio","Cortado","Tea","Water","Coke","Sprite","Pepsi","Juice","Burger","Chicken","Hotdog","Pizza","Patties","Singara","Cake","Brownie","Pastry", "Muffin" };

// prototype of functions--------------------------------------
void addEntry();//-------------------------------//Shadman
void display(int index);//-----------------------//Rafsun
void search(char *key, search_t type);//---------//Raiyan
void strlower(char *str);//----------------------//Raiyan
void readFromFile();//---------------------------//Raiyan
void saveToFile();//-----------------------------//Raiyan
void displayAll();//-----------------------------//Rafsun
void clear();//----------------------------------//Rafsun
void removeEntry(char *mobileNumber);//----------//Raiyan
void printMenu();//------------------------------//Shadman
void delete_info();//----------------------------//Raiyan
void search_option();//--------------------------//Raiyan

//Color------------------------------------------//Shadman
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


//main starts from here******************************************************************************************
//**********************************************************************************************************
int main()//------------------------------//Raiyan
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

            printf("\n\tEnter your Choice: ");
            scanf("%s",&selection);
            printf("______________________________________________\n");

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

            search_option();
            clear();
            break;

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

        }
    }

    return 0;
}
// end of main******************************************************************************************
//**********************************************************************************************************
void addEntry()
{
    int i = 0;
    if (currentSize == SIZE)
    {
        printf("Information DATABASE is full!!");
        return;
    }
    //c is the variable with type Info
    Info c;
    printf("\tEnter First name: ");
    gets(c.firstName);
    printf("\tEnter Second name: ");
    gets(c.lastName);
    printf("\tMobile Number: ");
    gets(c.mobileNumber);

    system("cls");
    ///---------------------------cash memo----------------------------------------------------------
    char choice;
    struct orders order;

    float total = 0;
    char reccho;
    float amountPaid;
    int n;
    int var_k;
    int index=0;

    //for printing the menu
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

                //soting ite_menu into Info
                strcpy(c.item_order[i],item_menu[var_k-1]);

                fflush(stdin);
                //****making a temporary array to store the item_menu because it is a call by reference
                char temp_str[40];
                strcpy(temp_str,item_menu[var_k-1]);//copying item_menu[var_k-1] into temp_str
                strcat(temp_str,"a");           //for tasting purpose
                                                //printf("%s\n",item_menu[var_k-1]);
                                                //printf("%s\n",temp_str);

                //value inside temp_str is storing in order.itm
                strcpy(order.itm[i].item,temp_str);
                //for alignment purpose
                order.itm[i].item[strlen(order.itm[i].item)-1]=0;


                printf("\tPlease enter the quantity:     ");
                scanf("%d", &order.itm[i].quantity);
                fflush(stdin);

                //storing price of (vark)th item into order.itm
                order.itm[i].price= item_price[var_k-1];
                //total will store the total price
                total += order.itm[i].quantity * order.itm[i].price;

            }

            printf("Do you want a receipt for your order?\n");
            scanf("%c", &reccho);
            fflush(stdin);

            printf("Your bill is $%.2f without VAT+SD\nMake your payment:\n", total);
            scanf("%f", &amountPaid);
            //storing paid amount in Info (c.amountPAID)
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

                printf("\t\t\tG u e s t C o p y\n");
                srand(time(NULL));
                printf("\t\t\tInvoice: %d\n", rand()%400);
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
                //storing grand total in Info as c.GRANDtotal
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
                    //storing due amount in Info c.amountDUE
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
                printf("\t\t\tFor more query mail us at arscafe@gmail.com\n");
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


    ////cash memo end here
    ///////////--------------------------------------------------------------------------------------
    //c is being stored in information array and the index is currentSize
    //initially currentSize =0, so c will store in information[0]
    //currentSize also gives a brief idea about the current array size also
    information[currentSize] = c;
    //increasing the currentSize (because we want to increase the index of information array to store another c)
    ++currentSize;
}
void display(int index)
{
    //the index is referring to the index of information array
    Info c = information[index];
    if (index < 0 || index >= currentSize)
    {
        puts("Error Index!");
        return;
    }
    green();
    printf("|________________________________ \n");
    printf("| ORDER INFO:                    |\n");
    printf("|________________________________|\n");
    reset();
    printf("| Customer Info:                  \n");
    printf("| Enter 1st name: %s\n", c.firstName);
    printf("| Enter 2nd name: %s\n", c.lastName);
    printf("| Mobile number: %s\n", c.mobileNumber);
    printf("|________________________________\n");
    printf("| Ordered Items:                  \n");

    //it will print the items stored in c.item_order array
    for (int i = 0; i <c.item_num; i++)
    {
        printf("| Item %d: %s\n", i+1,c.item_order[i]);
    }

    printf("|_________________________________\n");
    red();
    printf("| PAID amount : $%.2f\n",c.amountPAID);
    yellow();
    printf("| DUE amount : $%.2f\n",c.amountDUE);
    reset();
    printf("| BILL : $%.2f\n",c.GRANDtotal);
    printf("|_________________________________\n");

}
//---------------------------------------------------------------------------------------
void search(char *key, search_t type) // actually we need to check 3 different, enum will make that process easy and readable it also reduce a user input
{
    //key is actually the name or mobile number provided by user
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
            // if(strcmp(phonebook[i].monileNumber,key)==0) it's not possible, because their a chance that user input are not all in small letter
            strcpy(content, information[i].lastName);
            //here strlower will change the actual stored named to user entered name beacuse its a call by ref
            //that's why we have to store it into a temp array
            strlower(content);

            if (strcmp(content, key) == 0)
            {

                display(i);
                found = 1;
            }
        }
    }
    else if (type == MOBILE_NUMBER)
    {
        // search by mobile num
        for (i = 0; i < currentSize; i++)
        {
            strcpy(content, information[i].mobileNumber);

            strlower(content);
            if (strcmp(content, key) == 0)

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
        puts("Not found in the information DATABASE");
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

//---------------------------------------------------
// CAUTION (this function will modified the given string)!!

void strlower(char *str)
{
    int len = strlen(str);
    int i;
    for (i = 0; i < len; i++)
    {
        str[i] = tolower(str[i]);
    }
}
//----------------clear function -------------
void clear()
{
    system("PAUSE"); // it will show, "press any key to continue. . ." on the monitor
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
    printf("  \t|    Snacks:                 Price              Dessert:                 Price           |\n");
    printf("  \t|    12.Burger                $50               18.Cake                   $68            |\n");
    printf("  \t|    13.Chicken               $35               19.Brownie                $30            |\n");
    printf("  \t|    14.Hotdog                $50               20.Pastry                 $38            |\n");
    printf("  \t|    15.Pizza (medium)        $90               21.Muffin                 $25            |\n");
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
//----------removing a entry--------------------------------------------
void removeEntry(char *mobileNumber)
{
    if(currentSize==0){
        printf("Database is empty! Nothing to show\n");
    }

    int j;
    int count = 0;
    for (int i = 0; i < currentSize; i++)
    {
        //Info c is not a array, that's why we are using the information array
        //if the user input and stored input are same (here it is mobile number) then it will continue the process
        if (strcmp(information[i].mobileNumber, mobileNumber) == 0)
        {
            //input found in i th index of the array so i is the position
            //if we delete something from this position then we have to move i+1 element to i, and i+2 position to i+1 and so on.
            for (j = i; j < currentSize - 1; j++)
            {
                //it will store the i+1 th position information into i
                information[j] = information[j + 1];
            }
            // it's reset the  value
            strcpy(information[j].firstName, "");
            strcpy(information[j].lastName, "");
            strcpy(information[j].mobileNumber, "");
            //before deleting the array size was n so deleting 1 info will make is n-1
            currentSize -= 1;
            ++count;
        }
    }
    if (count == 0)
    {
        puts("\tNo information deleted\n");
    }
    else
    {
        printf("\t%d customer information deleted\n", count);
        cyan();
        printf("\tSAVE the Data to permanently save the info !\n");
        reset();
    }
}
//-------------read form file--------------
void readFromFile()
{
    FILE *fp;
    //we have to read and write into binary files if we are using the fwrite ot fread function
    //it will open the file and if not found in then it will create a new file and then opens it
    if ((fp = fopen("information.db", "rb")) == NULL)
    {
        puts("CAN NOT LOAD THE DATABASE!!");
        return;
    }

    // it's read the currentsize of the information array
    if (fread(&currentSize, sizeof(currentSize), 1, fp) != 1)
    {
        puts("ERROR IN READING THE DATA!");
        return;
    }
    //fwrite write the file into binary from so we have to use fread to read that file
    // it's read the information content (actually it's read the array from the file)
    //information is the array, size of the total information array is also a input for this function
    //we are using the whole array so total numbers of elements are in the array so we should take 1 for that
    //fp is the file pointer who points to that file where information array is stored
    if (fread(information, sizeof(information), 1, fp) != 1)
    {
        puts("ERROR IN READING THE DATA!");
        return;
    }
}
//-------------------------save to file er function------------------
void saveToFile()
{
    FILE *fp;
    //we are opening a binary file so we have to use fread() and fwrite() function to read and write;
    if ((fp = fopen("information.db", "wb")) == NULL)
    {
        puts("Error: can't create a database file!");
        return;
    }

    // Save the current size of the information
    if (fwrite(&currentSize, sizeof(currentSize), 1, fp) != 1)
    {
        puts("ERROR IN SAVING THE DATA!");
        return;
    }

    // it's save the info stores into the information array
    // it's read the information content (actually it's read the array from the file)
    //information is the array, size of the total information array is also a input for this function
    //we are using the whole array so total numbers of elements are in the array so we should take 1 for that
    //fp is the file pointer where information array is being stored
    if (fwrite(information, sizeof(information), 1, fp) != 1)
    {
        puts("ERROR IN SAVING THE DATA!");
        return;
    }
    green();
    puts("Information saved to database successfully!");
    reset();
}
//-----------------------------------------------------------------------------------
void delete_info()
{
    int pass;
    char pass_key[10]="1234";
    char mobile_num[30];
    char password[20];
    char c;
    int index_arrsize=0;
    red();
    printf("\tThis is a password protected sector\n");
    reset();
    printf("\tPleae Enter the password:");

       while((c = getch()) != 13){
       if(index_arrsize < 0)
           index_arrsize = 0;
       // 8 is ASCII value backspace charachter
       if(c == 8){
        //if user inputs 8 then it will be a backspace (like 12387 will store as 123_7) so it's make the password wrong
        //so we have to put NULL on that position and decrease the arraysize
           putch('0');  // 0 is ASCII value of NULL

           index_arrsize--;
       continue;
       }
       //it will store the char c in the password array of index=0 (initially)
       password[index_arrsize] = c;
       //it will make index=1 and increasing the index by 1 untill user enter
       index_arrsize++;
       printf("*"); //for each rotation it will print on the screen

   }

   password[index_arrsize] = '\0';                 //for testing purpose, it will show the password
                                                   //printf("\t\n%s\n",password);

    fflush(stdin);
    if(strcmp(pass_key,password)==0)
    {
        printf("\n");
        printf("\t|------------------------------|\n");
        printf("\t|     1.Delete an order        |\n");
        printf("\t|------------------------------|\n");

        printf("\t|------------------------------|\n");
        printf("\t|  2.Remove all Information    |\n");
        printf("\t|------------------------------|\n");

        printf("\tEnter your choice: ");
        scanf("%d",&pass);
        fflush(stdin);
        switch(pass)
        {
        case 1:
            printf("\tEnter the person Mobile Number:");
            gets(mobile_num);
            fflush(stdin);
            removeEntry(mobile_num);
            break;
        case 2:
            FILE *fp;
            fp = fopen("information.db", "w");
            purple();
            printf("\n\tAll information is deleted\n");
            reset();
            exit(1);
            break;
        }
    }
    else{
        red();
        printf("\n\tWrong P A S S W O R D ! !\n");
        reset();
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












