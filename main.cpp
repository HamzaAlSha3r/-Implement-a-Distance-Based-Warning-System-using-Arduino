// C++ code
int cm = 0;

int pot = 0;

int maxThreshold = 20;
int minThreshold = 10;

int max = 0;
int min =0;


long readUltrasonicDistance(int triggerPin, int echoPin)
{
    pinMode(triggerPin, OUTPUT);  // Clear the trigger
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    // Sets the trigger pin to HIGH state for 10 microseconds
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
    pinMode(echoPin, INPUT);
    // Reads the echo pin, and returns the sound wave travel time in microseconds
    return pulseIn(echoPin, HIGH);
}

void setup()
{
    pinMode(A5, INPUT);
    Serial.begin(9600);
    pinMode(7, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(5, OUTPUT);
}

void loop()
{
    cm = 0.01723 * readUltrasonicDistance(11, 10);
    pot = analogRead(A5);
    max = pot/minThreshold;
    min = pot/maxThreshold;

    if (max < maxThreshold ){
        max = maxThreshold;

    }
    if (min < minThreshold){
        min = minThreshold;

    }


    Serial.println(cm);

    if (cm >  max) {
        digitalWrite(7, HIGH);
        digitalWrite(6, LOW);
        digitalWrite(5, LOW);
    }
    if (cm <=  max && cm > min) {
        digitalWrite(7, LOW);
        digitalWrite(6, HIGH);
        digitalWrite(5, LOW);
    }
    if (cm < min) {
        digitalWrite(7, LOW);
        digitalWrite(6, LOW);
        digitalWrite(5, HIGH);
    }
    delay(10); // Delay a little bit to improve simulation performance
}