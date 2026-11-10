#include <stdio.h>
#define base_rate 100
#define rate_per_kg 50
char tracking_code[10];
char sender;
int weight;
char status;
char destination;
double charge;

void input_parcel(char tracking_code[10], char status, char sender, int weight, int distance_km, double charge);
void update_parcel(char tracking_code[10], char status);

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
        case 1: input_parcel(tracking_code[10], status, sender, weight, destination, charge); break;
        case 2: update_parcel(tracking_code[10], status); break;
        case 3: track_parcel(tracking_code[10], status, sender, weight, destination); break;
        case 4: district_view(); break;
        case 5: revenue_report(); break;
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
        if (temp_input == track_parcel)
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





void input_parcel(char tracking_code[10], char status, char sender, int weight, char destination, double charge)
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
}

void track_parcel(char tracking_code[10], char status, char sender, int weight, char destination)
{
    char temp_input[10];
    do
    {
        printf("Enter parcel ID: ");
        scanf(" %10c", &temp_input[10]);
        if (temp_input == track_parcel)
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