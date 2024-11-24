void setup() {
  Serial.begin(9600);

  delay(100);
  double myDouble = 5.678;
  int myInt = doubleToInt(myDouble);

  Serial.print("Double to Int: ");
  Serial.println(myInt); // Output: 5

  int anotherInt = 42;
  double anotherDouble = intToDouble(anotherInt);
  Serial.print("Int to Double: ");
  Serial.println(anotherDouble, 3); // Output: 42.000
}

void loop() {
  // Do nothing
}

int doubleToInt(double value) {
  return (int)value; // Convert double to int by truncation
}

double intToDouble(int value) {
  return (double)value; // Convert int to double
}