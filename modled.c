#include <stdio.h>
#include <unistd.h>
#include <pigpio.h>

#define PIN 17

int main(int argc, char* argv[])
{
if(gpioInitialise() < 0){
fprintf(stderr, "pigpio initialization failed\n");
return 1;
}
gpioSetMode(PIN,PI_OUTPUT);
float lower = 68.0f;
float upper = 76.0f;
float temp;
float sum = 0.0f;
int count = 0;
char choice;

FILE *file = fopen("templog.txt", "w");
if(file == NULL){
perror("error opening file");
gpioTerminate();
return 1;
}
fprintf(file, "Temperature (F)\tStatus\tLED\n");//line 27
printf("Welcome to the Smart Classroom Comfort Monitor. Default upper and lower boundaries are 68 F and 76 F respectively. Press y to change boundaries or n to skip.\n");
scanf("%c", &choice);
if(choice == 'y' || choice == 'Y'){
printf("Enter your preferred lower boundary.\n");
scanf("%f", &lower);
printf("Enter your preferred upper boundary.\n");
scanf("%f", &upper);
printf("Your new range is: %.1fF - %.1fF\n", lower, upper);
}
while(1){
printf("Enter a classroom temperature in Fahrenheit. Enter -999 to exit): ");
if(scanf("%f", &temp) != 1){
while(getchar() != '\n');
continue;
}
if(temp == -999.0f){
break;
}

sum += temp;
count++;

if(temp >= lower && temp <= upper){
printf("Temperature: %1.fF | Status: NORMAL | LED OFF\n", temp);
gpioWrite(PIN,0);//led off
fprintf(file, "%.1fF\t\tNORMAL\tOFF\n", temp);
}
else
{
printf("Temperature: %.1fF | Status: WARNING | LED ON\n", temp);
gpioWrite(PIN,1);//led on
fprintf(file,"%.1fF\t\tWARNING\tON\n", temp);
}
}
//avg calc
if(count > 0)
{
float average = sum / count;
printf("\n Summary \n");
printf("Total readings recorded: %d\n", count);
printf("Average temperature: %.2fF\n", average);
fprintf(file, "\nAverage Temperature: %.2fF\n", average);
}
else{
printf("\nNo readings recorded.\n");
}

fclose(file);
gpioWrite(PIN,0);//led off
gpioTerminate();
printf("Program closed successfully. Data saved to templog.txt");
return 0;


//gpioWrite(PIN,1);//led on
//getchar(//gpioWrite(PIN,0);//led off
//getchar();
//gpioTerminate();
//return 0;
}

