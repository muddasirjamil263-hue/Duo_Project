

#include <stdio.h>
#include <string.h>

#define BASE_RATE 100.0
#define RATE_PER_KG 50.0
#define MAX_PARCELS 100

char tracking_codes[MAX_PARCELS][10];
char senders[MAX_PARCELS][50];
char destinations[MAX_PARCELS][30];
char statuses[MAX_PARCELS];

int weights[MAX_PARCELS];
double charges[MAX_PARCELS];

int parcel_count = 0;


void input_parcel(void);
void update_parcel(void);
void track_parcel(void);
void district_view(void);
void revenue_report(void);

int read_integer(const char prompt[]);
void read_text(const char prompt[], char text[], int size);
int find_parcel(const char code[]);
int main(void)
{
    int user_input;

    printf("================================================\n");
    printf("       WELCOME TO PARCEL TRACKING SYSTEM\n");
    printf("================================================\n");

    do
    {
        printf("\n--------------- MAIN MENU ----------------\n");
        printf("1. Book a parcel\n");
        printf("2. Update the status of a parcel\n");
        printf("3. Track a parcel by code\n");
        printf("4. View parcels by district\n");
        printf("5. View revenue report\n");
        printf("6. Exit\n");
        printf("------------------------------------------\n");

        user_input = read_integer("Please select an option: ");

        switch(user_input)
        {
            case 1:
                input_parcel();
                break;

            case 2:
                update_parcel();
                break;

            case 3:
                track_parcel();
                break;

            case 4:
                district_view();
                break;

            case 5:
                revenue_report();
                break;

            case 6:
                printf("\nThank you for using Parcel Tracking System!\n");
                break;

            default:
                printf("\nInvalid option! Please select 1-6.\n");
        }

    } while(user_input != 6);

    return 0;
}


void read_text(const char prompt[], char text[], int size)
{
    int length;

    printf("%s", prompt);

    if(fgets(text, size, stdin) == NULL)
    {
        text[0] = '\0';
        return;
    }

    length = (int)strlen(text);

    if(length > 0 && text[length - 1] == '\n')
    {
        text[length - 1] = '\0';
    }
    else
    {
        int ch;

        while((ch = getchar()) != '\n' && ch != EOF)
        {

        }
    }
}



int read_integer(const char prompt[])
{
    char input[100];
    int value;
    char extra;

    while(1)
    {
        read_text(prompt, input, sizeof(input));

        if(sscanf(input, " %d %c", &value, &extra) == 1)
        {
            return value;
        }

        printf("Invalid input! Please enter a whole number.\n");
    }
}


int find_parcel(const char code[])
{
    int i;

    for(i = 0; i < parcel_count; i++)
    {
        if(strcmp(tracking_codes[i], code) == 0)
        {
            return i;
        }
    }

    return -1;
}


void input_parcel(void)
{
    int new_weight;
    int duplicate;

    printf("\n========== BOOK A PARCEL ==========\n");

    if(parcel_count >= MAX_PARCELS)
    {
        printf("Parcel storage is full!\n");
        return;
    }

    do
    {
        read_text("Enter tracking code (maximum 9 characters): ",
                  tracking_codes[parcel_count], 10);

        if(strlen(tracking_codes[parcel_count]) == 0)
        {
            printf("Tracking code cannot be empty.\n");
            duplicate = 1;
        }
        else
        {
            duplicate = find_parcel(tracking_codes[parcel_count]) != -1;

            if(duplicate)
            {
                printf("This tracking code already exists. Try another.\n");
            }
        }

    } while(duplicate);

    read_text("Enter sender name: ",
              senders[parcel_count], 50);

    read_text("Enter destination district: ",
              destinations[parcel_count], 30);

    do
    {
        new_weight = read_integer("Enter parcel weight in grams: ");

        if(new_weight <= 0)
        {
            printf("Invalid weight! Weight must be greater than zero.\n");
        }

    } while(new_weight <= 0);

    weights[parcel_count] = new_weight;

    charges[parcel_count] =
        BASE_RATE + ((weights[parcel_count] / 1000.0) * RATE_PER_KG);

    statuses[parcel_count] = 'B';

    printf("\nParcel successfully booked!\n");
    printf("----------------------------------\n");
    printf("Tracking Code : %s\n", tracking_codes[parcel_count]);
    printf("Sender        : %s\n", senders[parcel_count]);
    printf("Destination   : %s\n", destinations[parcel_count]);
    printf("Weight        : %d grams\n", weights[parcel_count]);
    printf("Status        : Booked\n");
    printf("Parcel Charge : %.2f BDT\n", charges[parcel_count]);
    printf("----------------------------------\n");
    parcel_count++;
}

void update_parcel(void)
{
    char temp_code[10];
    char new_status;
    int index;

    printf("\n========== UPDATE PARCEL STATUS ==========\n");

    if(parcel_count == 0)
    {
        printf("No parcels have been booked yet.\n");
        return;
    }

    read_text("Enter parcel tracking code: ", temp_code, 10);

    index = find_parcel(temp_code);

    if(index == -1)
    {
        printf("Invalid tracking code! Parcel not found.\n");
        return;
    }

    printf("\nCurrent status: %c\n", statuses[index]);

    printf("Status codes:\n");
    printf("B = Booked\n");
    printf("I = In Transit\n");
    printf("D = Delivered\n");

    do
    {
        read_text("Enter new status (B/I/D): ", temp_code, 10);

        new_status = temp_code[0];

        if(strlen(temp_code) != 1 ||
           (new_status != 'B' && new_status != 'I' && new_status != 'D'))
        {
            printf("Invalid status! Enter B, I or D.\n");
        }

    } while(strlen(temp_code) != 1 ||
            (new_status != 'B' && new_status != 'I' && new_status != 'D'));

    statuses[index] = new_status;

    printf("Parcel status successfully updated to %c.\n", statuses[index]);
}


void track_parcel(void)
{
    char temp_code[10];
    int index;

    printf("\n========== TRACK A PARCEL ==========\n");

    if(parcel_count == 0)
    {
        printf("No parcels have been booked yet.\n");
        return;
    }

    read_text("Enter parcel tracking code: ", temp_code, 10);

    index = find_parcel(temp_code);

    if(index == -1)
    {
        printf("Invalid tracking code! Parcel not found.\n");
        return;
    }

    printf("\n========== PARCEL DETAILS ==========\n");
    printf("Tracking Code       : %s\n", tracking_codes[index]);
    printf("Sender              : %s\n", senders[index]);
    printf("Destination District: %s\n", destinations[index]);
    printf("Weight              : %d grams\n", weights[index]);
    printf("Status              : %c\n", statuses[index]);
    printf("Charge              : %.2f BDT\n", charges[index]);
    printf("====================================\n");
}

void district_view(void)
{
    char search_district[30];
    int found = 0;
    int i;

    printf("\n========== VIEW PARCELS BY DISTRICT ==========\n");

    if(parcel_count == 0)
    {
        printf("No parcels have been booked yet.\n");
        return;
    }

    read_text("Enter district name: ", search_district, 30);

    for(i = 0; i < parcel_count; i++)
    {
        if(strcmp(destinations[i], search_district) == 0)
        {
            printf("\nParcel Found!\n");
            printf("----------------------------------\n");
            printf("Tracking Code : %s\n", tracking_codes[i]);
            printf("Sender        : %s\n", senders[i]);
            printf("Destination   : %s\n", destinations[i]);
            printf("Weight        : %d grams\n", weights[i]);
            printf("Status        : %c\n", statuses[i]);
            printf("Charge        : %.2f BDT\n", charges[i]);
            printf("----------------------------------\n");

            found = 1;
        }
    }

    if(found == 0)
    {
        printf("No parcels found for district: %s\n", search_district);
    }
}

void revenue_report(void)
{
    double total_revenue = 0.0;
    int i;

    printf("\n========== REVENUE REPORT ==========\n");

    for(i = 0; i < parcel_count; i++)
    {
        total_revenue += charges[i];
    }

    printf("Total Parcels Booked : %d\n", parcel_count);
    printf("-----------------------------------\n");
    printf("Total Revenue        : %.2f BDT\n", total_revenue);
    printf("===================================\n");
}
