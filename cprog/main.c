// 04/18/2020
// LAHAT SO FAR
//halos lahat naka-function :D
// FINAL REQ MO PRE PERO DAMING ERRORS
//  Created by Kinni Yya Lopez on 29/02/2020.
//  Copyright  2020 Kinni Yya Lopez. All rights reserved.
//	I'm here too!!! >w<

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //for toupper
//#include <curses.h> and type system ("clear") SANA PERO ANG ARTE MO LAPPY;
#include <math.h>

#define accountCreationLimit 10
#define LimitAccountName 6
#define LimitPassword 6
#define BUFFERSIZE 1000

FILE *pFile;
FILE *pFile2;
FILE *pTemp;

char EnterPassword[LimitPassword];
char EnterAccountName[LimitAccountName];

int IntChoice;
char CharChoice;

char adminAccountName[] = "admiin";
char adminPassword[] = "123456";

char tellerAccountName[] = "teller";
char tellerEnterAccountName[50];
int tellerPassword = 654321;    //magiging string din lang kayo mamaya lol
int tellerEnterPassword;

// mga DAPAT LANG gloal var:
int ModificationStatus;
//int DeletionStatus=0;
int EndProgram;

typedef struct NewAccount{
    int accountRollNo;
    int EnterAccountNo;
    char accountNo[6];
    char accountName [100];
    int accountPassword;
    float InitialDeposit;
} Create; Create AccountCreate;
//Create AccountCreate[accountCreationLimit];

/*typedef struct MaintainAccount{
    int EnterAccountNo;
    char accountNo[6];
    char accountName [100];
    float accountInitialDeposit;
} Modify; Modify AccountModification;*/ // hindi naman nagamit SKSKSKSKSK

/* FUNCTIONS */
//void AdminOrTeller(void);
void decor(void);
void adminMainMenuChoice(void);
void ammCreateRecord(void);
void ammRecordMaintenance(void);
void VerificationADMINorTELLER(char TypeOfAccount[], char OriginalAccountName[], char OriginalPassword[]);
void ammRM_ModifyRecord(void);
void ammRM_DeleteRecord(void);
//void tellerMainMenu(void);

void decor() {
    printf ("\n----------------------------------------------------------------------------------------------------------------\n");
}

int main() {
    decor();
    printf ("\nAre you an ADMIN or a TELLER?");
    printf ("\nPress [A] if you are an ADMIN");
    printf ("\nPress [T] if you are a TELLER");
    printf ("\n\n>> "); scanf (" %c", &CharChoice);
    
    if (toupper(CharChoice) == 'A') {
        char TypeOfAccount[] = "ADMIN";
        VerificationADMINorTELLER(TypeOfAccount,adminAccountName, adminPassword);
    }
    
    /*  WIP
     else if (toupper(CharChoice) == 'T'){
        tellerMainMenu();
    }*/

    return 0;
}

void VerificationADMINorTELLER(char TypeOfAccount[], char OriginalAccountName[], char OriginalPassword[]) {
    
TryAgainAccess:
    decor();
    printf ("\nPlease enter %s account name and password to verify.", TypeOfAccount);
    printf ("\nACCOUNT NAME: "); //scanf ("%6s", EnterAccountName);
    fflush(stdin);
    fgets (EnterAccountName, LimitAccountName+1, stdin);
    
    int AccessAccountName;
        AccessAccountName = strcmp (OriginalAccountName, EnterAccountName);
    
    if (AccessAccountName == 0) {
        printf ("PASSWORD: ");
        fflush(stdin);
        fgets (EnterPassword, LimitPassword+1, stdin);
        
        int AccessPassword;
        AccessPassword = strcmp (OriginalPassword, EnterPassword);
        
            if (AccessPassword == 0) {
                printf ("\nAccess granted~!\n");
                if ((strncmp(TypeOfAccount, "ADMIN", 6)) == 0) {
                    adminMainMenuChoice();
                }
                else {
                    //tellerMainMenuChoice();
                }
                
            }
            else {
                printf ("\nIncorrect Password. Please try again.\n");
                goto TryAgainAccess;
            }
    } // end of if (AccessAccountName == 0)

    else {
        printf ("PASSWORD: "); scanf ("%5s", EnterPassword);
        printf ("\nIncorrect Account Name. Please try again.\n");
        goto TryAgainAccess;
    }
} // end of VerificationADMINorTELLER

void adminMainMenuChoice() {
aMM:
    decor();
    printf ("\nADMIN MAIN MENU\n");
    printf ("[1] Create Record\n");
    printf ("[2] Record Maintenance\n");
    printf ("[3] Reports\n");
    printf ("[0] Go Back\n");
    printf ("\n>> "); scanf ("%d", &IntChoice);
            
    switch (IntChoice) {
        case 1:
            ammCreateRecord();
            break;
        case 2:
            ammRecordMaintenance();
            break;
        case 0:
            main();
            break;
            } // end of switch (IntChoice)
        } // end of void adminMainMenuChoice ()

void ammCreateRecord() {
    if (ModificationStatus == 1) {             // it's a special tool that will help us later *wink wink*
        goto ModificationAccountNo;                 // for void ammRM_ModifyRecord();
    }
    
    else {
        pFile = fopen ("accounts.txt", "r");
           
        if (pFile == NULL) {
            AccountCreate.accountRollNo = 1;                                                        /*kapag wala pang nagawa na account (or txt file)
                                                                                                           edi automatic na 1 yung roll number*/
            pFile = fopen ("accounts.txt", "w");
            fprintf (pFile, "ROLL NO.\tACCOUNT NO.\t\tACCOUNT NAME\t\t\tINITIAL BALANCE");
            fclose (pFile);
        }
           
        else {
            char string [100];

            while (fgets(string, 100, pFile) != NULL) {             //i-ccopy niya yung unang account info na up to 100 characters (kaya may na-declared na char string)*/
                continue;
            }
            /*if (DeletionStatus ==1) {
                AccountCreate.accountRollNo = atoi(string) + 2;
                ++DeletionStatus;
            }
            else {*/
            AccountCreate.accountRollNo = atoi(string) + 1;         /*atoi(string) turns (string variable) string into an integer. Hence, atoi which stands                                                                                        for alphanumeric to integer.*/
            

        }
           
        fclose (pFile);
           
createRecord:
        pFile = fopen("accounts.txt", "a");
           
        decor();
        printf ("\nRECORD CREATION");
ModificationAccountNo:
        printf ("\nPlease enter a 5-digit ACCOUNT NO.: "); scanf (" %5d", &AccountCreate.EnterAccountNo);
    
        int CounterDigits=0;
        int temp;
            temp = AccountCreate.EnterAccountNo;
    
        while (temp != 0) {
            temp /= 10;     // n = n/10
            CounterDigits++;
        }
    
        printf ("CounterDigits = %d", CounterDigits);
    
        if (CounterDigits == 5) {
            printf ("\nAccountCreate.EnterAccountNo = %d\n", AccountCreate.EnterAccountNo);
            
            if (ModificationStatus == 1){
                sprintf (AccountCreate.accountNo, "%d", AccountCreate.EnterAccountNo);
                return;
            }
            
            else {
                sprintf (AccountCreate.accountNo, "%d", AccountCreate.EnterAccountNo);
            }
        }
        
        else if ((CounterDigits>0) && (CounterDigits<= 4)) {
            printf ("\nAccountCreate.EnterAccountNo = %05d\n", AccountCreate.EnterAccountNo);
            
            if (ModificationStatus == 1) {
                sprintf (AccountCreate.accountNo, "%05d", AccountCreate.EnterAccountNo);
                return;
            }
            
            else {
                sprintf (AccountCreate.accountNo, "%05d", AccountCreate.EnterAccountNo);
            }
        }
    
    
        // else if (strlen(AccountCreate.accountNo) != 5)
        else {
            decor();
            printf ("\nInvalid Input. Please view list of accounts and enter a unique Account No. The program will now end...\n");
            
            decor();
            if (ModificationStatus == 1){
                EndProgram = 1;
                return;
            }
            
            return;
        }
              
        printf ("\nPlease enter ACCOUNT NAME: "); scanf ("%s", AccountCreate.accountName);
        printf ("Please enter the INITIAL DEPOSIT of the new account: "); scanf ("%f", &AccountCreate.InitialDeposit);
               
        decor();
        printf ("\nPlease review the following details...");
        printf ("\nACCOUNT NO.: %s", AccountCreate.accountNo);
        printf ("\nACCOUNT NAME: %s", AccountCreate.accountName);
        printf ("\nINITIAL BALANCE: Php %.2f", AccountCreate.InitialDeposit);
        printf ("\n\nConfirm account creation? [Y]es or [N]o \n\n>> "); scanf (" %c", &CharChoice);
               
        if (toupper(CharChoice) == 'Y') {
tryAgainAccountConfirmPassword:
            printf ("\nPlease enter PIN for the new account: "); scanf ("%d", &AccountCreate.accountPassword);
                   
            int accountEnterPassword;
            printf ("Please confirm PIN: "); scanf ("%d", &accountEnterPassword);
                
                if (accountEnterPassword==AccountCreate.accountPassword) {
                    printf ("\nNew account created successfully~ \n");

                    fprintf (pFile, "\n%d\t", AccountCreate.accountRollNo);
                    fprintf (pFile, "\t%s\t\t", AccountCreate.accountNo);
                    fprintf (pFile,"\t%s\t\t\t", AccountCreate.accountName);
                    fprintf (pFile, "\t%.2f", AccountCreate.InitialDeposit);
                    fclose (pFile);
                    
                    adminMainMenuChoice();
                }
                       
                else {
                    printf ("\nPIN does not match. Please try again.\n");
                    decor();
                    goto tryAgainAccountConfirmPassword;
                }
      
        } // end of if (toupper(CharChoice) == 'Y')
               
        else if (toupper(CharChoice) == 'N') {
            decor();
            printf ("\nAccount was not created successfully. \n[1] Go back to RECORD CREATION \n[2] Go back to ADMIN MAIN MENU \n\n>> ");
            scanf (" %d", &IntChoice);
                   
            if (IntChoice == 1) {
                printf ("\nRedirecting to RECORD CREATION...\n");
                goto createRecord;
            }
                   
            else if (IntChoice == 2) {
                printf ("\nRedirecting to ADMIN MAIN MENU...\n");
                adminMainMenuChoice();
            }
        } // end of if (toupper(CharChoice) == 'N')
    } // else of void ammCreateRecord()
} //end of void ammCreateRecord()

void ammRecordMaintenance() {
    decor();
    printf ("\nRECORD MAINTENANCE\n");
    printf ("[1] Modify Record\n");
    printf ("[2] Delete Record\n");
    printf ("\n>> "); scanf ("%d", &IntChoice);
    
    switch (IntChoice) {
    case 1:
        ammRM_ModifyRecord();
        break;
    case 2:
        ammRM_DeleteRecord();
        break;
    } // end of switch (IntChoice)
} // end of void ammRecordMaintenance()

void ammRM_ModifyRecord(){
    decor();
    printf ("\nEnter ROLL NUMBER to search for account to be MODIFIED: "); scanf ("%d", &IntChoice);
    printf ("\nThe following account will be modified...");
                
    pFile = fopen ("accounts.txt", "r+");
    
    char temp[100];
    int LineChecker = 1;
    char DisplayAccountToBeModified[100];
    char AccountToBeModified[100];
    
    int StoreLineForModification=0;

    while (!feof(pFile)){       // condition: while file has not yet reached its end.
        if (LineChecker>=2) {    // inside loop, on condition LineCount >= 2: on condition roll no. = search input: BREAK LOOP
            fscanf(pFile, "%d\t\t%s\t\t\t%s\t\t\t\t%f\n", &AccountCreate.accountRollNo, AccountCreate.accountNo, AccountCreate.accountName, &AccountCreate.InitialDeposit);
            
            if (IntChoice == AccountCreate.accountRollNo) {
                printf ("\n\nROLL NO.\tACCOUNT NO.\t\tACCOUNT NAME\t\t\tINITIAL BALANCE");
                printf ("\n%d\t\t    %s  \t\t\t%s\t\t\t\t    Php %.2f", AccountCreate.accountRollNo, AccountCreate.accountNo, AccountCreate.accountName, AccountCreate.InitialDeposit);
                snprintf (DisplayAccountToBeModified, 100, "\nROLL NO.\tACCOUNT NO.\t\tACCOUNT NAME\t\t\tINITIAL BALANCE\n%d\t\t    %s  \t\t\t%s\t\t\t\t    Php %.2f", AccountCreate.accountRollNo, AccountCreate.accountNo, AccountCreate.accountName, AccountCreate.InitialDeposit);
                snprintf (AccountToBeModified, 100, "%d %s %s %f", AccountCreate.accountRollNo, AccountCreate.accountNo, AccountCreate.accountName, AccountCreate.InitialDeposit);
                StoreLineForModification = LineChecker;
                break;
            }
        }
        else {
            fscanf (pFile, " %[^\n]s\n", temp);     //first line consists of file headers (ROLL NO.\tACC NO.\tACC NAME...)
        }
        
        LineChecker++;  // 1st account does not match up with IntChoice? move file line to 2nd account.
    } // end of while (!feof(pFile))
    
    if ((feof(pFile)) && (IntChoice != AccountCreate.accountRollNo)) {
        printf ("\n\nACCOUNT DOES NOT EXIST.\n");
        decor();
        goto NonExistingAccount;
    }
    
    fclose (pFile);
    
    printf ("\n\nWish to continue? [Y]es or [N]o: "); scanf (" %c", &CharChoice);
                
    if (toupper(CharChoice) == 'Y') {
        goto ContinueModification;
    }
                
    else if (toupper(CharChoice) == 'N') {
NonExistingAccount:
        printf ("\nAccount was not modified successfully. \n[1] Go back to RECORD MAINTENANCE \n[2] Go back to ADMIN MAIN MENU \n\n>> ");
        scanf (" %d", &IntChoice);
                    
        if (IntChoice == 1) {
            printf ("\nRedirecting to RECORD MAINTENANCE...\n");
            ammRecordMaintenance();
        }
                    
        else if (IntChoice == 2) {
            printf ("\nRedirecting to ADMIN MAIN MENU...\n");
            adminMainMenuChoice();
        }
    } // end of else if (toupper(CharChoice) == 'N')
                
ContinueModification:
    decor();
    printf ("%s\n\n", DisplayAccountToBeModified);
    printf ("What should be modified?\n");
    printf ("[1]    ACCOUNT NO.\n");
    printf ("[2]    ACCOUNT NAME\n");
    printf ("[3]    INITIAL BALANCE\n");
    printf ("\n>> "); scanf ("%d", &IntChoice);
    
    decor();
    switch (IntChoice) {
        case 1:
            ModificationStatus = 1;
            ammCreateRecord();
            
            if (EndProgram == 1) {
                return;
            }
            else {
                break;
            }
            
        case 2:
            printf ("\nPlease enter NEW ACCOUNT NAME: "); scanf ("%s", AccountCreate.accountName);
            break;
        case 3:
            printf ("\nPlease enter the INITIAL BALANCE of the account: "); scanf ("%f", &AccountCreate.InitialDeposit);
            break;
        default:
            printf ("INVALID INPUT.\n");
            return;
        } // end of switch (IntChoice)
    
    decor();
    printf ("\nPlease review the following details...\n");

    typedef struct TempAccountInfo{
        int accountRollNo;
        char accountNo[6];
        char accountName [100];
        float accountInitialDeposit;
    } Temp; Temp TemporaryAccountInfo;
    
    sscanf (AccountToBeModified,"%d %s %s %f", &TemporaryAccountInfo.accountRollNo, TemporaryAccountInfo.accountNo, TemporaryAccountInfo.accountName, &TemporaryAccountInfo.accountInitialDeposit);
    
    char AccountModified[100];
    /* fprintf (pFile, "\n%d\t", AccountCreate.accountRollNo);
       fprintf (pFile, "\t%s\t\t", AccountCreate.accountNo);
       fprintf (pFile,"\t%s\t\t\t", AccountCreate.accountName);
       fprintf (pFile, "\tPhp %.2f",
     */
    switch (IntChoice) {
        case 1: // ACCOUNT NO.
            printf ("\nROLL NO.\tACCOUNT NO.\t\tACCOUNT NAME\t\t\tINITIAL BALANCE\n%d\t\t    %s  \t\t\t%s\t\t\t\t    Php %.2f", TemporaryAccountInfo.accountRollNo, AccountCreate.accountNo, TemporaryAccountInfo.accountName, TemporaryAccountInfo.accountInitialDeposit);
            snprintf (AccountModified, 100, "%d\t\t%s\t\t\t%s\t\t\t\t%.2f", TemporaryAccountInfo.accountRollNo, AccountCreate.accountNo, TemporaryAccountInfo.accountName, TemporaryAccountInfo.accountInitialDeposit);
            break;
        case 2: // ACCOUNT NAME
            printf ("\nROLL NO.\tACCOUNT NO.\t\tACCOUNT NAME\t\t\tINITIAL BALANCE\n%d\t\t    %s  \t\t\t%s\t\t\t\t    Php %.2f", TemporaryAccountInfo.accountRollNo, TemporaryAccountInfo.accountNo, AccountCreate.accountName, TemporaryAccountInfo.accountInitialDeposit);
            snprintf (AccountModified, 100, "%d\t\t%s\t\t\t%s\t\t\t\t%.2f", TemporaryAccountInfo.accountRollNo, TemporaryAccountInfo.accountNo, AccountCreate.accountName, TemporaryAccountInfo.accountInitialDeposit);
            break;
        case 3: // INITIAL BALANCE
            printf ("\nROLL NO.\tACCOUNT NO.\t\tACCOUNT NAME\t\t\tINITIAL BALANCE\n%d\t\t    %s  \t\t\t%s\t\t\t\t    Php %.2f", TemporaryAccountInfo.accountRollNo, TemporaryAccountInfo.accountNo, TemporaryAccountInfo.accountName, AccountCreate.InitialDeposit);
            snprintf (AccountModified, 100, "%d\t\t%s\t\t\t%s\t\t\t\t%.2f", TemporaryAccountInfo.accountRollNo, TemporaryAccountInfo.accountNo, TemporaryAccountInfo.accountName, AccountCreate.InitialDeposit);
            break;
    }

    printf ("\n\nConfirm account modification? [Y]es or [N]o \n\n>> "); scanf (" %c", &CharChoice);
    
    if (toupper(CharChoice) == 'Y') {
        pFile = fopen ("accounts.txt", "r");
        pTemp = fopen("replace.txt", "w");
        
        LineChecker = 0;
        char buffer[BUFFERSIZE];
        
        while ((fgets(buffer, BUFFERSIZE, pFile)) != NULL) {
            LineChecker++;

            /* If current line is line to replace */
            if (LineChecker == StoreLineForModification) {
                fputs(AccountModified, pTemp);
            }
            else{
                fputs(buffer, pTemp);
            }
        }
        
        fclose(pFile);
        fclose(pTemp);
        
        remove("accounts.txt");
        rename("replace.txt", "accounts.txt");
        
        decor();
        printf ("\nAccount modified successfully~ \nRedirecting to ADMIN MAIN MENU...\n");
        adminMainMenuChoice();
    } // end of if (toupper(CharChoice) == 'Y')
        
    else if (toupper(CharChoice) == 'N') {
        decor();
        printf ("\nAccount was not modified successfully. \n[1] Go back to RECORD MAINTENANCE \n[2] Go back to ADMIN MAIN MENU \n\n>> ");
        scanf (" %d", &IntChoice);
                    
        if (IntChoice == 1) {
            printf ("\nRedirecting to RECORD MAINTENANCE...\n");
            ammRecordMaintenance();
        }
                    
        else if (IntChoice == 2) {
            printf ("\nRedirecting to ADMIN MAIN MENU...\n");
            adminMainMenuChoice();
        }
    } //end of else if (toupper(CharChoice) == 'N')
} //end of void ammRM_ModifyRecord()

void ammRM_DeleteRecord(){
    decor();
    printf ("\nEnter ROLL NUMBER to search for account to be DELETED: "); scanf ("%d", &IntChoice);
    printf ("\nThe following account will be deleted...");
    
    pFile = fopen ("accounts.txt", "r");
    
    char temp[100];
    int LineChecker = 1;
    //char DisplayAccountToBeDeleted[100];
    //char AccountToBeDeleted[100];
    int StoreLineForDeletion=0;
    
    while (!feof(pFile)) {       // condition: while file has not yet reached its end.
        if (LineChecker>=2) {    // inside loop, on condition LineCount >= 2: on condition roll no. = search input: BREAK LOOP
        fscanf(pFile, "%d\t\t%s\t\t\t%s\t\t\t\t%f\n", &AccountCreate.accountRollNo, AccountCreate.accountNo, AccountCreate.accountName, &AccountCreate.InitialDeposit);
            
            if (IntChoice == AccountCreate.accountRollNo) {
                printf ("\n\nROLL NO.\tACCOUNT NO.\t\tACCOUNT NAME\t\t\tINITIAL BALANCE");
                printf ("\n%d\t\t    %s  \t\t\t%s\t\t\t\t    Php %.2f", AccountCreate.accountRollNo, AccountCreate.accountNo, AccountCreate.accountName, AccountCreate.InitialDeposit);
                StoreLineForDeletion = LineChecker;
                break;
            }
        }
        else {
            fscanf (pFile, " %[^\n]s\n", temp);     //first line consists of file headers (ROLL NO.\tACC NO.\tACC NAME...)
        }
        
        LineChecker++;  // 1st account does not match up with IntChoice? move file line to 2nd account.
    } // end of while (!feof(pFile))
 
    fclose (pFile);
        
    printf ("\n\nWish to continue? [Y]es or [N]o: "); scanf (" %c", &CharChoice);
                    
    if (toupper(CharChoice) == 'Y') {
        goto ContinueDeletion;
    }
                    
    else if (toupper(CharChoice) == 'N') {
NonExistingAccount:
        decor();
        printf ("\nAccount was not deleted successfully. \n[1] Go back to RECORD MAINTENANCE \n[2] Go back to ADMIN MAIN MENU \n\n>> ");
        scanf (" %d", &IntChoice);
                        
        if (IntChoice == 1) {
            printf ("\nRedirecting to RECORD MAINTENANCE...\n");
            ammRecordMaintenance();
        }
                        
        else if (IntChoice == 2) {
            printf ("\nRedirecting to ADMIN MAIN MENU...\n");
            adminMainMenuChoice();
        }
    } // end of else if (toupper(CharChoice) == 'N')
                    
ContinueDeletion:
    decor();
    if (toupper(CharChoice) == 'Y') {

        pFile = fopen ("accounts.txt", "r");
        pTemp = fopen("replace.txt", "w");
            
        LineChecker = 0;
        char buffer[BUFFERSIZE];
        
        while ((fgets(buffer, BUFFERSIZE, pFile)) != NULL) {
            LineChecker++;
                
            if (LineChecker != StoreLineForDeletion){
                fputs(buffer, pTemp);
            }
            
        }

        //++DeletionStatus;

        fclose(pFile);
        fclose(pTemp);
            
        remove("accounts.txt");
        rename("replace.txt", "accounts.txt");
            
        printf ("\nAccount deleted successfully~ \nRedirecting to ADMIN MAIN MENU...\n");
        adminMainMenuChoice();
            
    } // end of if (toupper(CharChoice) == 'Y')
            
    else if (toupper(CharChoice) == 'N') {
        printf ("\nAccount was not deleted successfully. \n[1] Go back to RECORD MAINTENANCE \n[2] Go back to ADMIN MAIN MENU \n\n>> ");
        scanf (" %d", &IntChoice);
                        
        if (IntChoice == 1) {
            printf ("\nRedirecting to RECORD MAINTENANCE...\n");
            ammRecordMaintenance();
        }
                        
        else if (IntChoice == 2) {
            printf ("\nRedirecting to ADMIN MAIN MENU...\n");
            adminMainMenuChoice();
        }
    } //end of else if (toupper(CharChoice) == 'N')
} // end of void ammRM_DeleteRecord(void)



