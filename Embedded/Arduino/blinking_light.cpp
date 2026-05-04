//to use on arduino copy file as a .ino file and use in Arduino IDE

void setup() {
    //digital pin 13 is arduino built in LED
    pinMode(13, OUTPUT);
    /*pinMode function 
    x = pin you want to use;
    y = the mode of the pin;
    pinMode(x,y);
    */

}

void loop() {
    //after the pins you will use are setup properly in setup()
    //you can use them in your loop

    //digitalWrite - function for using OUTPUT digital pins
    /*digital write function (and similar functions)
    x = pin you want to use;
    y = information you want sent/recieved;
    digitalWrite(x,y);
    */
    digitalWrite(13, HIGH);
    //delay acts as sleep function, takes input in milliseconds
    delay(1000);
    digitalWrite(13, LOW);
    delay(1000);
}

