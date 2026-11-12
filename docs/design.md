REQUIREMENT DESIGN

Allowing the user to enter temp readings
We utilized a while loop, prompting the user to write a temperature and giving them the option to enter "-999" to exit.

Determining whether the temperature is within the acceptable range of 68F-78F, inclusive
We utilized a simple if statement to determine whether the temperature was within the range.

Display and appropriate NORMAL or WARNING status
If the if condition was true, we displayed a NORMAL status. If the condition was false, we displayed a WARNING status.

Calculate the average temperatures
We utilized a float value with some simple division to display the average of the temperatures the user added, dividing the total of each temperature by the number of temperatures added.

Save temperature readings and their statuses to a file
We utilized fprintf to display the readings that the program found with the temperatures the user entered, outputting to the file "templog.txt"

Use an LED connected to the Raspberry Pi to indicate a warning condition
Utilizing gpioWrite(PIN, 0/1), we lit an LED connected to the Raspberry Pi depending on whether the WARNING status was true.

Allow the acceptable temperature range to be changed according to a new client requirement
Before entering temperatures, the user is prompted whether they would like to change the upper and lower boundaries of their temperature range.
