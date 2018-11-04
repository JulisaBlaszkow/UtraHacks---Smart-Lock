

int servo = D0; //our servo's pin
Servo motor; //servo object
void setup()
{

   // Here's the pin configuration, same as last time
    motor.attach(servo);
    motor.write(180); //device is default unlocked upon start-up
   Particle.function("lockdoor",servoToggle); //function to connect with particle clound
   Serial.begin(9600);
}

void loop()
{
 
   if (motor.read() != 155) { //if the motor is not locked (155 degrees), then turn to locked position
    motor.write(155);
    } 
}

int servoToggle(String command) { //communicates with particle cloud
   
    if (command=="unlock") { //unlock at users command
        motor.write(200);
        delay(6000);
        return 1;
    }
    else {
        return -1;
    }
}

