/* Program to input, display, and update the time using Structure */

#include<stdio.h>


// Structure of time
struct time {
	int hour;
	int minute;
	int second;
}t;

// Function prototypes
void input ();
void display ();
void update ();

int main() {
	int choice;
	
	// Menu Driving While Loop
	while(1) {
	printf("\n\nEnter 1 to Input new Time\nEnter 2 to Display Time\nEnter 3 to Update Time\nEnter 4 to Exit Code\n\n");
	scanf("%d",&choice);
	
		switch(choice) {
			case 1: input ();
				break;
		
			case 2: display ();
				break;
			
			case 3: update ();	
				break;
			
			case 4: return 0;
		
			default: printf("Error!");
				break;
		}	
	}
	return 0;
}


// Function to Input new Time
void input () {
	printf("Enter hour, minute and second :\n");
	scanf("%d %d %d",&t.hour,&t.minute,&t.second);
}

// Function to Display Current Time
void display () {
	printf("Current Time is :\n%d : %d : %d",t.hour,t.minute,t.second);
}


// Function to Update Existing Time
void update () {
    int h, m, s;
    printf("Enter time to Add to Existing Time:\n ");
    scanf("%d %d %d", &h, &m, &s);

    t.second += s;
    t.minute += m + t.second / 60;
    t.hour += h + t.minute / 60;

    t.second %= 60;
    t.minute %= 60;
    t.hour %= 24;	
}

