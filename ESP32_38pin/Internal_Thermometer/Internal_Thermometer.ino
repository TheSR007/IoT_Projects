#ifdef __cplusplus
extern "C" {
#endif
uint8_t temprature_sens_read();
#ifdef __cplusplus
}
#endif

uint8_t temprature_sens_read();

void setup()
{
Serial.begin(9600);

}


void loop()
{

    Serial.print("Internal Core Temperature: ");
    Serial.print(((temprature_sens_read() - 32 ) / 1.8));
    Serial.print(" °C / ");
    Serial.print(temprature_sens_read());
    Serial.println(" °F ");
    delay(3000);

}