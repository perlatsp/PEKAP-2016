/*
  Arduino Bluetooth Connection with AppInventor Android application
  Created by Perlat Kociaj 
*/
 
String entoli;    //δήλωση μεταβλητής τύπου string για την εντολή

//δομή αρχικοποιήσης
void setup() 
{
  Serial.begin(9600);   //εναρξη σύνδεσης με την συριακή θύρα
  pinMode(13, OUTPUT);  //καθορισμός του pin 13 για έξοδο
}
// επαναληπτική μέθοδος 
void loop()     
{
  while (Serial.available())  //έλεγχος εάν υπάρχουν διαθέσιμα δεδομένα
  {
    delay(3);               //καθυστέρηση 3 milisec
    char readSerial = Serial.read();  //δηλωση μεταβλητής για να διαβαζει απο την σειριακή θύρα και
    entoli += readSerial;             //εγχώρηση της τιμής στην μεταβλητή της εντολής
  }
  
  if (entoli.length() >0)
  {
    Serial.println("Δεχηκα την εντολή : " + entoli);  
    if (entoli == "on")     
    {
      digitalWrite(2, HIGH);   //Αναψε το LED
      Serial.println("LED Αναμένο!");
    } //έλεγχος οταν ο χρήστης πατάει το κουμπι "ΟΝ" 
    
    if (entoli == "off")//ελεγχος οταν ο χρήστης ππατήσει το κουμπί "OFF"
    {
      digitalWrite(2, LOW);    //Σβήσημο του LED
      Serial.println("LED Σβησμένο!" );
    }
    entoli="";  //αδειασμα της εντολής και αναμένει για την επόμενη εντολή
  } //έλεγχος εαν δέχτηκε εντολή
}

