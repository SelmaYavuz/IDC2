 int ledPins[] = {2,3,4,5,6,7,8,9};
 int buzzerTones[] = {440, 494, 523, 587, 659, 784};
 int buzzerPin = 13;
 const int pResistor = A0; // photoresistor is at pin A0 
 int counter = 0;

 int value; // value photoresistor reads
 int mic;
 int micPin = 12;

void setup()

{

int index;

pinMode(pResistor, INPUT); // setting up photoresistor

pinMode(buzzerPin, OUTPUT); // setting up the buzzer

pinMode(micPin, INPUT); // setting up mic


for(index = 0; index <= 7; index++)

{  
  pinMode(ledPins[index],OUTPUT);

}

Serial.begin(9600);

}

void loop()

{

value = analogRead(pResistor);
mic = digitalRead(micPin);

if(value <= 400 && mic == 0)
{
  // oneAfterAnotherNoLoop(); // Light up all the LEDs in turn
  whichFunc();
}
else
{
  Serial.println("nada");
}

}


void whichFunc()
{

  switch(counter)
  {
    case 0:
      func1();
      counter++;
      break;
    case 1:
      func2();
      counter++;
      break;
    case 2:
      func3();
      counter++;
      break;
    case 3:
      func4();
      counter++;
      break;
    case 4:
      func5();
      counter = 0;
      break;
    default:
      break;

  }
}

/*

oneAfterAnotherNoLoop()

turns lights on one by one, ascending tones, then turns them off

*/

void func1()
{

  int delayTime = 100; // time (milliseconds) to pause between LEDs

  // make this smaller for faster switching

  // turn all the LEDs on and passive buzzer tones:

  digitalWrite(ledPins[0], HIGH); //Turns on LED #0 (pin 2)

  tone(buzzerPin, 440);

  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[1], HIGH); //Turns on LED #1 (pin 3)

  tone(buzzerPin, 494); // B4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[2], HIGH); //Turns on LED #2 (pin 4)

  tone(buzzerPin, 523); // C4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[3], HIGH); //Turns on LED #3 (pin 5)

  tone(buzzerPin, 587); // D4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[4], HIGH); //Turns on LED #4 (pin 6)

  tone(buzzerPin, 659); // E4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[5], HIGH); //Turns on LED #5 (pin 7)

  tone(buzzerPin, 698); // F4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[6], HIGH); //Turns on LED #6 (pin 8)

  tone(buzzerPin, 784); // G4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[7], HIGH); //Turns on LED #7 (pin 9)

  tone(buzzerPin, 698); // F4


  delay(delayTime); //wait delayTime milliseconds

  // turn all the LEDs off:

  digitalWrite(ledPins[7], LOW); //Turn off LED #7 (pin 9)

  tone(buzzerPin, 659); // E4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[6], LOW); //Turn off LED #6 (pin 8)

  tone(buzzerPin, 587); // D4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[5], LOW); //Turn off LED #5 (pin 7)

  tone(buzzerPin, 523); // C4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[4], LOW); //Turn off LED #4 (pin 6)

  tone(buzzerPin, 494); // B4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[3], LOW); //Turn off LED #3 (pin 5)

  tone(buzzerPin, 440); // A4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[2], LOW); //Turn off LED #2 (pin 4)

  tone(buzzerPin, 494); // B4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[1], LOW); //Turn off LED #1 (pin 3)

  tone(buzzerPin, 523); // C4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[0], LOW); //Turn off LED #0 (pin 2)

  tone(buzzerPin, 587); // D4


  delay(delayTime); //wait delayTime milliseconds

  noTone(buzzerPin);
  delay(1000);

}

// turns lights on starting at both ends and making its way to the center
void func2()
{
  int delayTime = 100;

  // turn on pins

  // pin2
  digitalWrite(ledPins[0], HIGH); //Turns on LED #0 (pin 2)

  tone(buzzerPin, buzzerTones[0]);

  delay(delayTime); //wait delayTime milliseconds

  //pin9

  digitalWrite(ledPins[7], HIGH); //Turns on LED #0 (pin 2)

  tone(buzzerPin, buzzerTones[5]);

  delay(delayTime); //wait delayTime milliseconds

  // pin 3

  digitalWrite(ledPins[1], HIGH); //Turns on LED #0 (pin 2)

  tone(buzzerPin, buzzerTones[1]);

  delay(delayTime); //wait delayTime milliseconds

  // pin 8

  digitalWrite(ledPins[6], HIGH); //Turns on LED #0 (pin 2)

  tone(buzzerPin, buzzerTones[4]);

  delay(delayTime); //wait delayTime milliseconds

  // pin 4

  digitalWrite(ledPins[2], HIGH); //Turns on LED #0 (pin 2)

  tone(buzzerPin, buzzerTones[2]);

  delay(delayTime); //wait delayTime milliseconds


  // pin 7

  digitalWrite(ledPins[5], HIGH); //Turns on LED #0 (pin 2)

  tone(buzzerPin, buzzerTones[3]);

  delay(delayTime); //wait delayTime milliseconds


  // pin 5

  digitalWrite(ledPins[3], HIGH); //Turns on LED #0 (pin 2)

  tone(buzzerPin, buzzerTones[4]);

  delay(delayTime); //wait delayTime milliseconds

  // pin 6

  digitalWrite(ledPins[4], HIGH); //Turns on LED #0 (pin 2)

  tone(buzzerPin, buzzerTones[3]);

  delay(delayTime); //wait delayTime milliseconds


  // turn off pins

    // pin2
  digitalWrite(ledPins[0], LOW); //Turns on LED #0 (pin 2)

  tone(buzzerPin, buzzerTones[0]);

  delay(delayTime); //wait delayTime milliseconds

  //pin9

  digitalWrite(ledPins[7], LOW); //Turns on LED #0 (pin 2)

  tone(buzzerPin, buzzerTones[5]);

  delay(delayTime); //wait delayTime milliseconds

  // pin 3

  digitalWrite(ledPins[1], LOW); //Turns on LED #0 (pin 2)

  tone(buzzerPin, buzzerTones[1]);

  delay(delayTime); //wait delayTime milliseconds

  // pin 8

  digitalWrite(ledPins[6], LOW); //Turns on LED #0 (pin 2)

  tone(buzzerPin, buzzerTones[4]);

  delay(delayTime); //wait delayTime milliseconds

  // pin 4

  digitalWrite(ledPins[2], LOW); //Turns on LED #0 (pin 2)

  tone(buzzerPin, buzzerTones[2]);

  delay(delayTime); //wait delayTime milliseconds


  // pin 7

  digitalWrite(ledPins[5], LOW); //Turns on LED #0 (pin 2)

  tone(buzzerPin, buzzerTones[3]);

  delay(delayTime); //wait delayTime milliseconds


  // pin 5

  digitalWrite(ledPins[3], LOW); //Turns on LED #0 (pin 2)

  tone(buzzerPin, buzzerTones[4]);

  delay(delayTime); //wait delayTime milliseconds

  // pin 6

  digitalWrite(ledPins[4], LOW); //Turns on LED #0 (pin 2)

  tone(buzzerPin, buzzerTones[3]);

  delay(delayTime); //wait delayTime milliseconds

  noTone(buzzerPin);
  delay(1000);
}

// turns lights on and off one by one, alternate between high and low tones
void func3()
{

    int delayTime = 100;

    // turn on and off pins

    // pin2 on
    digitalWrite(ledPins[0], HIGH); //Turns on LED #0 (pin 2)

    tone(buzzerPin, buzzerTones[0]);

    delay(delayTime); //wait delayTime milliseconds

    // off
    digitalWrite(ledPins[0], LOW); //Turns on LED #0 (pin 2)

    tone(buzzerPin, buzzerTones[5]);

    delay(delayTime); //wait delayTime milliseconds

    // pin 3 on
   
    digitalWrite(ledPins[1], HIGH); //Turns on LED #0 (pin 2)

    tone(buzzerPin, buzzerTones[0]);

    delay(delayTime); //wait delayTime milliseconds

    // off

    digitalWrite(ledPins[1], LOW); //Turns on LED #0 (pin 2)

    tone(buzzerPin, buzzerTones[5]);

    delay(delayTime); //wait delayTime milliseconds

    // pin 4 on

    digitalWrite(ledPins[2], HIGH); //Turns on LED #0 (pin 2)

    tone(buzzerPin, buzzerTones[0]);

    delay(delayTime); //wait delayTime milliseconds

    // off
    digitalWrite(ledPins[2], LOW); //Turns on LED #0 (pin 2)

    tone(buzzerPin, buzzerTones[5]);

    delay(delayTime); //wait delayTime milliseconds

    // pin 5 on

    digitalWrite(ledPins[3], HIGH); //Turns on LED #0 (pin 2)

    tone(buzzerPin, buzzerTones[0]);

    delay(delayTime); //wait delayTime milliseconds

    // off
    digitalWrite(ledPins[3], LOW); //Turns on LED #0 (pin 2)

    tone(buzzerPin, buzzerTones[5]);

    delay(delayTime); //wait delayTime milliseconds

    // pin 6 on

    digitalWrite(ledPins[4], HIGH); //Turns on LED #0 (pin 2)

    tone(buzzerPin, buzzerTones[0]);

    delay(delayTime); //wait delayTime milliseconds

    // off
    digitalWrite(ledPins[4], LOW); //Turns on LED #0 (pin 2)

    tone(buzzerPin, buzzerTones[5]);

    delay(delayTime); //wait delayTime milliseconds

    // pin 7 on

    digitalWrite(ledPins[5], HIGH); //Turns on LED #0 (pin 2)

    tone(buzzerPin, buzzerTones[0]);

    delay(delayTime); //wait delayTime milliseconds

    // off
    digitalWrite(ledPins[5], LOW); //Turns on LED #0 (pin 2)

    tone(buzzerPin, buzzerTones[5]);

    delay(delayTime); //wait delayTime milliseconds

    // pin 8 on

    digitalWrite(ledPins[6], HIGH); //Turns on LED #0 (pin 2)

    tone(buzzerPin, buzzerTones[0]);

    delay(delayTime); //wait delayTime milliseconds

    // off
    digitalWrite(ledPins[6], LOW); //Turns on LED #0 (pin 2)

    tone(buzzerPin, buzzerTones[5]);

    delay(delayTime); //wait delayTime milliseconds

    // pin 9 on
    digitalWrite(ledPins[7], HIGH); //Turns on LED #0 (pin 2)

    tone(buzzerPin, buzzerTones[0]);

    delay(delayTime); //wait delayTime milliseconds

    // off

    digitalWrite(ledPins[7], LOW); //Turns on LED #0 (pin 2)

    tone(buzzerPin, buzzerTones[5]);

    delay(delayTime); //wait delayTime milliseconds

    noTone(buzzerPin);
    delay(1000);
}

// turn on all blue lights, turn them off, turn on all red, turn them off
void func4()
{
  int delayTime = 100; // time (milliseconds) to pause between LEDs

  // make this smaller for faster switching

  // turn all the LEDs on and passive buzzer tones:

  digitalWrite(ledPins[0], HIGH); //Turns on LED #0 (pin 2)

  tone(buzzerPin, 440);

  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[1], HIGH); //Turns on LED #1 (pin 3)

  tone(buzzerPin, 494); // B4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[2], HIGH); //Turns on LED #2 (pin 4)

  tone(buzzerPin, 523); // C4


  delay(delayTime); //wait delayTime milliseconds


  digitalWrite(ledPins[3], HIGH); //Turns on LED #3 (pin 5)

  tone(buzzerPin, 587); // D4


  delay(delayTime); //wait delayTime milliseconds


  // turn off

  digitalWrite(ledPins[3], LOW); //Turn off LED #3 (pin 5)

  tone(buzzerPin, 440); // A4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[2], LOW); //Turn off LED #2 (pin 4)

  tone(buzzerPin, 494); // B4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[1], LOW); //Turn off LED #1 (pin 3)

  tone(buzzerPin, 523); // C4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[0], LOW); //Turn off LED #0 (pin 2)

  tone(buzzerPin, 587); // D4


  delay(delayTime); //wait delayTime milliseconds

  // red lights on

  digitalWrite(ledPins[4], HIGH); //Turns on LED #4 (pin 6)

  tone(buzzerPin, 659); // E4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[5], HIGH); //Turns on LED #5 (pin 7)

  tone(buzzerPin, 698); // F4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[6], HIGH); //Turns on LED #6 (pin 8)

  tone(buzzerPin, 784); // G4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[7], HIGH); //Turns on LED #7 (pin 9)

  tone(buzzerPin, 698); // F4


  delay(delayTime); //wait delayTime milliseconds

  // red lights off

  digitalWrite(ledPins[7], LOW); //Turn off LED #7 (pin 9)

  tone(buzzerPin, 659); // E4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[6], LOW); //Turn off LED #6 (pin 8)

  tone(buzzerPin, 587); // D4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[5], LOW); //Turn off LED #5 (pin 7)

  tone(buzzerPin, 523); // C4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[4], LOW); //Turn off LED #4 (pin 6)

  tone(buzzerPin, 494); // B4


  delay(delayTime); //wait delayTime milliseconds


  noTone(buzzerPin);
  delay(1000);


}

// put it all together!!
void func5()
{

    int delayTime = 100;

    // turn on and off pins

    // pin2 on
    digitalWrite(ledPins[0], HIGH); //Turns on LED #0 (pin 2)

    tone(buzzerPin, buzzerTones[0]);

    delay(delayTime); //wait delayTime milliseconds

    // off
    digitalWrite(ledPins[0], LOW); //Turns on LED #0 (pin 2)

    tone(buzzerPin, buzzerTones[5]);

    delay(delayTime); //wait delayTime milliseconds

    // pin 3 on
   
    digitalWrite(ledPins[1], HIGH); //Turns on LED #0 (pin 2)

    tone(buzzerPin, buzzerTones[0]);

    delay(delayTime); //wait delayTime milliseconds

    // off

    digitalWrite(ledPins[1], LOW); //Turns on LED #0 (pin 2)

    tone(buzzerPin, buzzerTones[5]);

    delay(delayTime); //wait delayTime milliseconds

    // pin 4 on

    digitalWrite(ledPins[2], HIGH); //Turns on LED #0 (pin 2)

    tone(buzzerPin, buzzerTones[0]);

    delay(delayTime); //wait delayTime milliseconds

    // off
    digitalWrite(ledPins[2], LOW); //Turns on LED #0 (pin 2)

    tone(buzzerPin, buzzerTones[5]);

    delay(delayTime); //wait delayTime milliseconds

    // pin 5 on

    digitalWrite(ledPins[3], HIGH); //Turns on LED #0 (pin 2)

    tone(buzzerPin, buzzerTones[0]);

    delay(delayTime); //wait delayTime milliseconds

    // off
    digitalWrite(ledPins[3], LOW); //Turns on LED #0 (pin 2)

    tone(buzzerPin, buzzerTones[5]);

    delay(delayTime); //wait delayTime milliseconds

    // pin 6 on

    digitalWrite(ledPins[4], HIGH); //Turns on LED #0 (pin 2)

    tone(buzzerPin, buzzerTones[0]);

    delay(delayTime); //wait delayTime milliseconds

    // off
    digitalWrite(ledPins[4], LOW); //Turns on LED #0 (pin 2)

    tone(buzzerPin, buzzerTones[5]);

    delay(delayTime); //wait delayTime milliseconds

    // pin 7 on

    digitalWrite(ledPins[5], HIGH); //Turns on LED #0 (pin 2)

    tone(buzzerPin, buzzerTones[0]);

    delay(delayTime); //wait delayTime milliseconds

    // off
    digitalWrite(ledPins[5], LOW); //Turns on LED #0 (pin 2)

    tone(buzzerPin, buzzerTones[5]);

    delay(delayTime); //wait delayTime milliseconds

    // pin 8 on

    digitalWrite(ledPins[6], HIGH); //Turns on LED #0 (pin 2)

    tone(buzzerPin, buzzerTones[0]);

    delay(delayTime); //wait delayTime milliseconds

    // off
    digitalWrite(ledPins[6], LOW); //Turns on LED #0 (pin 2)

    tone(buzzerPin, buzzerTones[5]);

    delay(delayTime); //wait delayTime milliseconds

    // pin 9 on
    digitalWrite(ledPins[7], HIGH); //Turns on LED #0 (pin 2)

    tone(buzzerPin, buzzerTones[0]);

    delay(delayTime); //wait delayTime milliseconds

    // off

    digitalWrite(ledPins[7], LOW); //Turns on LED #0 (pin 2)

    tone(buzzerPin, buzzerTones[5]);

    delay(delayTime); //wait delayTime milliseconds

    // second part

      // pin2
  digitalWrite(ledPins[0], HIGH); //Turns on LED #0 (pin 2)

  tone(buzzerPin, buzzerTones[0]);

  delay(delayTime); //wait delayTime milliseconds

  //pin9

  digitalWrite(ledPins[7], HIGH); //Turns on LED #0 (pin 2)

  tone(buzzerPin, buzzerTones[5]);

  delay(delayTime); //wait delayTime milliseconds

  // pin 3

  digitalWrite(ledPins[1], HIGH); //Turns on LED #0 (pin 2)

  tone(buzzerPin, buzzerTones[1]);

  delay(delayTime); //wait delayTime milliseconds

  // pin 8

  digitalWrite(ledPins[6], HIGH); //Turns on LED #0 (pin 2)

  tone(buzzerPin, buzzerTones[4]);

  delay(delayTime); //wait delayTime milliseconds

  // pin 4

  digitalWrite(ledPins[2], HIGH); //Turns on LED #0 (pin 2)

  tone(buzzerPin, buzzerTones[2]);

  delay(delayTime); //wait delayTime milliseconds


  // pin 7

  digitalWrite(ledPins[5], HIGH); //Turns on LED #0 (pin 2)

  tone(buzzerPin, buzzerTones[3]);

  delay(delayTime); //wait delayTime milliseconds


  // pin 5

  digitalWrite(ledPins[3], HIGH); //Turns on LED #0 (pin 2)

  tone(buzzerPin, buzzerTones[4]);

  delay(delayTime); //wait delayTime milliseconds

  // pin 6

  digitalWrite(ledPins[4], HIGH); //Turns on LED #0 (pin 2)

  tone(buzzerPin, buzzerTones[3]);

  delay(delayTime); //wait delayTime milliseconds


  // turn off pins

    // pin2
  digitalWrite(ledPins[0], LOW); //Turns on LED #0 (pin 2)

  tone(buzzerPin, buzzerTones[0]);

  delay(delayTime); //wait delayTime milliseconds

  //pin9

  digitalWrite(ledPins[7], LOW); //Turns on LED #0 (pin 2)

  tone(buzzerPin, buzzerTones[5]);

  delay(delayTime); //wait delayTime milliseconds

  // pin 3

  digitalWrite(ledPins[1], LOW); //Turns on LED #0 (pin 2)

  tone(buzzerPin, buzzerTones[1]);

  delay(delayTime); //wait delayTime milliseconds

  // pin 8

  digitalWrite(ledPins[6], LOW); //Turns on LED #0 (pin 2)

  tone(buzzerPin, buzzerTones[4]);

  delay(delayTime); //wait delayTime milliseconds

  // pin 4

  digitalWrite(ledPins[2], LOW); //Turns on LED #0 (pin 2)

  tone(buzzerPin, buzzerTones[2]);

  delay(delayTime); //wait delayTime milliseconds


  // pin 7

  digitalWrite(ledPins[5], LOW); //Turns on LED #0 (pin 2)

  tone(buzzerPin, buzzerTones[3]);

  delay(delayTime); //wait delayTime milliseconds


  // pin 5

  digitalWrite(ledPins[3], LOW); //Turns on LED #0 (pin 2)

  tone(buzzerPin, buzzerTones[4]);

  delay(delayTime); //wait delayTime milliseconds

  // pin 6

  digitalWrite(ledPins[4], LOW); //Turns on LED #0 (pin 2)

  tone(buzzerPin, buzzerTones[3]);

  delay(delayTime); //wait delayTime milliseconds

  // func 4

  // make this smaller for faster switching

  // turn all the LEDs on and passive buzzer tones:

  digitalWrite(ledPins[0], HIGH); //Turns on LED #0 (pin 2)

  tone(buzzerPin, 440);

  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[1], HIGH); //Turns on LED #1 (pin 3)

  tone(buzzerPin, 494); // B4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[2], HIGH); //Turns on LED #2 (pin 4)

  tone(buzzerPin, 523); // C4


  delay(delayTime); //wait delayTime milliseconds


  digitalWrite(ledPins[3], HIGH); //Turns on LED #3 (pin 5)

  tone(buzzerPin, 587); // D4


  delay(delayTime); //wait delayTime milliseconds


  // turn off

  digitalWrite(ledPins[3], LOW); //Turn off LED #3 (pin 5)

  tone(buzzerPin, 440); // A4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[2], LOW); //Turn off LED #2 (pin 4)

  tone(buzzerPin, 494); // B4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[1], LOW); //Turn off LED #1 (pin 3)

  tone(buzzerPin, 523); // C4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[0], LOW); //Turn off LED #0 (pin 2)

  tone(buzzerPin, 587); // D4


  delay(delayTime); //wait delayTime milliseconds

  // red lights on

  digitalWrite(ledPins[4], HIGH); //Turns on LED #4 (pin 6)

  tone(buzzerPin, 659); // E4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[5], HIGH); //Turns on LED #5 (pin 7)

  tone(buzzerPin, 698); // F4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[6], HIGH); //Turns on LED #6 (pin 8)

  tone(buzzerPin, 784); // G4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[7], HIGH); //Turns on LED #7 (pin 9)

  tone(buzzerPin, 698); // F4


  delay(delayTime); //wait delayTime milliseconds

  // red lights off

  digitalWrite(ledPins[7], LOW); //Turn off LED #7 (pin 9)

  tone(buzzerPin, 659); // E4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[6], LOW); //Turn off LED #6 (pin 8)

  tone(buzzerPin, 587); // D4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[5], LOW); //Turn off LED #5 (pin 7)

  tone(buzzerPin, 523); // C4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[4], LOW); //Turn off LED #4 (pin 6)

  tone(buzzerPin, 494); // B4


  delay(delayTime); //wait delayTime milliseconds


  // func1

  // turn all the LEDs on and passive buzzer tones:

  digitalWrite(ledPins[0], HIGH); //Turns on LED #0 (pin 2)

  tone(buzzerPin, 440);

  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[1], HIGH); //Turns on LED #1 (pin 3)

  tone(buzzerPin, 494); // B4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[2], HIGH); //Turns on LED #2 (pin 4)

  tone(buzzerPin, 523); // C4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[3], HIGH); //Turns on LED #3 (pin 5)

  tone(buzzerPin, 587); // D4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[4], HIGH); //Turns on LED #4 (pin 6)

  tone(buzzerPin, 659); // E4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[5], HIGH); //Turns on LED #5 (pin 7)

  tone(buzzerPin, 698); // F4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[6], HIGH); //Turns on LED #6 (pin 8)

  tone(buzzerPin, 784); // G4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[7], HIGH); //Turns on LED #7 (pin 9)

  tone(buzzerPin, 698); // F4


  delay(delayTime); //wait delayTime milliseconds

  // turn all the LEDs off:

  digitalWrite(ledPins[7], LOW); //Turn off LED #7 (pin 9)

  tone(buzzerPin, 659); // E4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[6], LOW); //Turn off LED #6 (pin 8)

  tone(buzzerPin, 587); // D4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[5], LOW); //Turn off LED #5 (pin 7)

  tone(buzzerPin, 523); // C4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[4], LOW); //Turn off LED #4 (pin 6)

  tone(buzzerPin, 494); // B4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[3], LOW); //Turn off LED #3 (pin 5)

  tone(buzzerPin, 440); // A4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[2], LOW); //Turn off LED #2 (pin 4)

  tone(buzzerPin, 494); // B4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[1], LOW); //Turn off LED #1 (pin 3)

  tone(buzzerPin, 523); // C4


  delay(delayTime); //wait delayTime milliseconds

  digitalWrite(ledPins[0], LOW); //Turn off LED #0 (pin 2)

  tone(buzzerPin, 587); // D4


  delay(delayTime); //wait delayTime milliseconds

  noTone(buzzerPin);
  delay(1000);

}