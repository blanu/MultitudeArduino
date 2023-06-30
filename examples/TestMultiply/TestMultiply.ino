#include <Arduino.h>
#include "MutableMultitudeInt.hpp"

void setup()
{
  Serial.begin(9600);

  MutableMultitudeInt *selector=new MutableMultitudeInt(2);
  selector->becomeSetInt(0, 0);
  selector->becomeSetInt(1, 5);

  MutableMultitudeInt *input=new MutableMultitudeInt(2);
  input->becomeSetInt(0, 8);
  input->becomeSetInt(1, 7);

  MutableMultitudeInt *results=input->replicate(selector);
  int result = 0;
  for(int index = 0; index < 5; index++ )
  {
    if(!results->getInt(index, &result))
    {
      return;
    }

    Serial.println(index);
    Serial.println(result);
  }
}

void loop()
{
}
