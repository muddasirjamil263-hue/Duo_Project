#include <stdio.h>
#define base_rate 100
#define rate_per_kg 50
    char tracking_code[10];
    char sender;
    int weight;
    int status;
    double charge;

void charge_calculation(int weight);
void input_parcel(int *parcel_id, char sender[], char receiver[],
                  float *weight_kg, int *distance_km, int *booking_day)

int main(void) {

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
        case 1: input_parcel(char tracking_code[10], char sender, int *weight, int *distance_km, int *booking_day) break;
        case 2: update_parcel() break;
        case 3: track_parcel() break;
        case 4: district_view() break;
        case 5: revenue_report() break;
        default: printf("Invalid option") break;
    }

    return 0;
}

void charge_calculation(int weight)
{
    printf("Enter package weight in grams: ");
    scanf("%d", &weight);
    charge = base_rate + ((weight / 1000.0) * rate_per_kg);
    printf("Charge after fees: %.2f\n", charge);
}
void input_parcel(char tracking_code[10], char sender, int *weight, int *distance_km, int *booking_day)
{
    printf("\nParcel ID          : ");
    scanf("%d", tracking_code);
    printf("Sender name        : ");
    scanf(" %c", sender);
    printf("Weight (kg)        : ");
    scanf("%d", weight);
    printf("Distance (km)      : ");
    scanf("%d", distance_km);
    printf("Booking day        : ");
    scanf("%d", booking_day);
    charge_calculation(int weight)
}