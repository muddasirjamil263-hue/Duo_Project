#include <stdio.h>
#define base_rate 100
#define rate_per_kg 50
char tracking_code[10];
char sender;
int weight;
int parcel_count = 0;
char status;
char destination;
double charge;

void input_parcel(int parcel_count, char tracking_code[10], char status, char sender, int weight, int distance_km, double charge);
void update_parcel(char tracking_code[10], char status);
void track_parcel(char tracking_code[10], char status, char sender, int weight, char destination);
void district_view(int parcel_count, char tracking_code[10], char status, char sender, int weight, char destination, double charge);
void revenue_report(int parcel_count, double charge);

int main(void) 
{

    int user_input;
    printf("Welcome to the parcel tracking system.\n");
    printf("===============================================================================\n");
    printf("Please select one of the options below.(Type the No. only)\n");
    printf("1.\t Book a parcel\n");
    printf("2.\t Update the status of a parcel\n");
    printf("3.\t Track a parcel by code\n");
    printf("4.\t View parcels by district\n");
    printf("5.\t View revenue report");
    scanf("%d", &user_input);
    switch(user_input){
        case 1: input_parcel(parcel_count,tracking_code[10], status, sender, weight, destination, charge); break;
        case 2: update_parcel(tracking_code[10], status); break;
        case 3: track_parcel(tracking_code[10], status, sender, weight, destination); break;
        case 4: district_view(parcel_count, tracking_code[10], status, sender, weight, destination, charge); break;
        case 5: revenue_report(parcel_count, charge); break;
        default: printf("Invalid option"); break;
    }

    return 0;
}



void update_parcel(char tracking_code[10], char status)
{
    char temp_input[10];
    do
    {
        printf("Enter parcel ID: ");
        scanf(" %10c", &temp_input[10]);
        if (temp_input == tracking_code)
        printf("Valid code.");
        else
        printf("Invalid code. Try again.");
    } 
    while (temp_input != tracking_code);
    printf("Current status: %c\n", status);
    printf("Enter the new status: ");
    scanf(" %c", &status);
    printf("New status is now: %c\n", status);
}





void input_parcel(int parcel_count, char tracking_code[10], char status, char sender, int weight, int distance_km, double charge)
{
    printf("Parcel ID          : ");
    scanf(" %10c", &tracking_code[10]);
    printf("Sender name        : ");
    scanf(" %c", &sender);
    printf("Destination district      : ");
    scanf(" %c", &destination);


    printf("Enter package weight in grams: ");
    scanf("%d", &weight);
    charge = base_rate + ((weight / 1000.0) * rate_per_kg);
    printf("Charge after fees: %.2f\n", charge);
    parcel_count += 1;
}

void track_parcel(char tracking_code[10], char status, char sender, int weight, char destination)
{
    char temp_input[10];
    do
    {
        printf("Enter parcel ID: ");
        scanf(" %10c", &temp_input[10]);
        if (temp_input[10] == tracking_code[10])
        printf("Valid code.");
        else
        printf("Invalid code. Try again.");
    } 
    while (temp_input != tracking_code);
    
    printf("Parcel ID: %c\n", tracking_code[10]);
    printf("Sender: %c\n", sender);
    printf("Weight: %d\n", weight);
    printf("Destination District: %c\n", destination);
    printf("Status: %c\n", status);
}


void district_view(int parcel_count, char tracking_code[10], char status, char sender, int weight, char destination, double charge)
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

    printf("Enter district name: ");
    scanf(" %c", &search_district);

    for(i = 0; i < parcel_count; i++)
    {
        if(destination == search_district)
        {
            printf("\nParcel Found!\n");
            printf("----------------------------------\n");
            printf("Tracking Code : %s\n", tracking_code[10]);
            printf("Sender        : %s\n", sender);
            printf("Destination   : %s\n", destination);
            printf("Weight        : %d grams\n", weight);
            printf("Status        : %c\n", status);
            printf("Charge        : %.2f BDT\n", charge);
            printf("----------------------------------\n");

            found = 1;
        }
    }

    if(found == 0)
    {
        printf("No parcels found for district: %s\n", search_district);
    }

}
void revenue_report(int parcel_count, double charge)
{
    double total_revenue = 0.0;
    int i;

    printf("\n========== REVENUE REPORT ==========\n");

    for(i = 0; i < parcel_count; i++)
    {
        total_revenue += charge;
    }

    printf("Total Parcels Booked : %d\n", parcel_count);
    printf("-----------------------------------\n");
    printf("Total Revenue        : %.2f BDT\n", total_revenue);
    printf("===================================\n");
}