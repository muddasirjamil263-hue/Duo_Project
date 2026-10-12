#include <stdio.h>
#define base_rate 100
#define rate_per_kg 50
int main(void) {
    char tracking_code[10];
    char sender[];
    int weight;
    int status;
    double charge;
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
    
    printf("Enter package weight in grams:");
    scanf("%d", &weight);
    charge = base_rate + ((weight/1000)*rate_per_kg);
    printf("Charge after fees: %f", charge);


    return 0;
}