#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <SPI.h>

#define TFT_DC 32
#define TFT_CS 5

#define downButton 21
#define selecButton 4
#define upButton 15

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
int screen;
int defaultTemp = 20;
int maxTemp = 24;
int minTemp = 16;
int defaultSpeed = 1;
int maxSpeed = 5;
int minSpeed = 1;
String defaultMode = "Economico";

void initialScreen(int *screen)
{
    int cursorPos = 2;
    int goBack = 1;
    while (goBack == 1)
    {
        if (cursorPos == 2)
        {
            tft.setCursor(0, 0);
            tft.setTextSize(3);
            tft.println("Initial Screen:");
            tft.setTextSize(2);
            tft.println("");
            tft.write(16);
            tft.println("Temperatura: " + String(defaultTemp));
            tft.println(" Velocidade: " + String(defaultSpeed));
            tft.println(" Modo: " + defaultMode);
        }
        if (cursorPos == 3)
        {
            tft.setCursor(0, 0);
            tft.setTextSize(3);
            tft.println("Initial Screen:");
            tft.setTextSize(2);
            tft.println("");
            tft.println(" Temperatura");
            tft.write(16);
            tft.println("Velocidade");
            tft.println(" Modo");
        }
        if (cursorPos == 4)
        {
            tft.setCursor(0, 0);
            tft.setTextSize(3);
            tft.println("Initial Screen:");
            tft.setTextSize(2);
            tft.println("");
            tft.println(" Temperatura");
            tft.println(" Velocidade");
            tft.write(16);
            tft.println("Modo");
        }

        if (digitalRead(downButton) == 0 && cursorPos != 4)
        {
            cursorPos++;
            tft.fillRect(0, 25, 12, 80, ILI9341_BLACK);
            delay(150);
        }
        if (digitalRead(upButton) == 0 && cursorPos != 2)
        {
            cursorPos--;
            tft.fillRect(0, 25, 12, 80, ILI9341_BLACK);
            delay(150);
        }
        if (digitalRead(selecButton) == 0)
        {
            goBack = 0;
            *screen = cursorPos;
            tft.fillScreen(ILI9341_BLACK);
            delay(150);
        }
    }
}

void tempScreen(int *screen)
{
    int goBack = 0;
    while (goBack == 0)
    {
        tft.setCursor(0, 0);
        tft.setTextSize(3);
        tft.println(" Temperatura");
        tft.println("");
        tft.println("");
        tft.setTextSize(4);
        tft.write(24);
        tft.write(25);
        tft.setTextSize(6);
        tft.println(" " + String(defaultTemp) + " C" + '\370');
        tft.println("");
        tft.setTextSize(2);
        tft.write(16);
        tft.println("Go back");

        if (digitalRead(downButton) == 0)
        {
            if (defaultTemp > minTemp)
            {
                defaultTemp--;
                tft.fillRect(78, 40, 80, 80, ILI9341_BLACK);
                delay(150);
            }
            else
            {
                defaultTemp = defaultTemp;
            }
        }
        if (digitalRead(upButton) == 0)
        {
            if (defaultTemp < maxTemp)
            {
                defaultTemp++;
                tft.fillRect(78, 40, 80, 80, ILI9341_BLACK);
                delay(150);
            }
            else
            {
                defaultTemp = defaultTemp;
            }
        }

        if (digitalRead(selecButton) == 0)
        {
            goBack = 1;
            *screen = 1;
            tft.fillScreen(ILI9341_BLACK);
            delay(150);
        }
    }
}

void speedScreen(int *screen)
{
    int goBack = 0;
    while (goBack == 0)
    {
        tft.setCursor(0, 0);
        tft.setTextSize(3);
        tft.println(" Velocidade");
        tft.println("");
        tft.println("");
        tft.setTextSize(4);
        tft.write(24);
        tft.write(25);
        tft.setTextSize(6);
        tft.println(" " + String(defaultSpeed));
        tft.println("");
        tft.setTextSize(2);
        tft.write(16);
        tft.println("Go back");

        if (digitalRead(downButton) == 0)
        {
            if (defaultSpeed > minSpeed)
            {
                defaultSpeed--;
                tft.fillRect(78, 40, 80, 80, ILI9341_BLACK);
                delay(150);
            }
            else
            {
                defaultSpeed = defaultSpeed;
            }
        }
        if (digitalRead(upButton) == 0)
        {
            if (defaultSpeed < maxSpeed)
            {
                defaultSpeed++;
                tft.fillRect(78, 40, 80, 80, ILI9341_BLACK);
                delay(150);
            }
            else
            {
                defaultSpeed = defaultSpeed;
            }
        }

        if (digitalRead(selecButton) == 0)
        {
            goBack = 1;
            *screen = 1;
            tft.fillScreen(ILI9341_BLACK);
            delay(150);
        }
    }
}

void modeScreen(int *screen)
{
    int cursorPos = 2;
    int goBack = 1;
    while (goBack == 1)
    {
        if (cursorPos == 2)
        {
            tft.setCursor(0, 0);
            tft.setTextSize(3);
            tft.println("Modo:");
            tft.setTextSize(2);
            tft.println("");
            tft.write(16);
            tft.println("Economico");
            tft.println(" Rapido");
            tft.println(" Turbo");
        }
        if (cursorPos == 3)
        {
            tft.setCursor(0, 0);
            tft.setTextSize(3);
            tft.println("Modo:");
            tft.setTextSize(2);
            tft.println("");
            tft.println(" Economico");
            tft.write(16);
            tft.println("Rapido");
            tft.println(" Turbo");
        }
        if (cursorPos == 4)
        {
            tft.setCursor(0, 0);
            tft.setTextSize(3);
            tft.println("Modo:");
            tft.setTextSize(2);
            tft.println("");
            tft.println(" Economico");
            tft.println(" Rapido");
            tft.write(16);
            tft.println("Turbo");
        }

        if (digitalRead(downButton) == 0 && cursorPos != 4)
        {
            cursorPos++;
            tft.fillRect(0, 25, 12, 80, ILI9341_BLACK);
            delay(150);
        }
        if (digitalRead(upButton) == 0 && cursorPos != 2)
        {
            cursorPos--;
            tft.fillRect(0, 25, 12, 80, ILI9341_BLACK);
            delay(150);
        }
        if (digitalRead(selecButton) == 0)
        {
            Serial.println(cursorPos);
            if (cursorPos == 2)
            {
                defaultMode = "Economico";
            }
            else if (cursorPos == 3)
            {
                defaultMode = "Rapido";
            }
            else if (cursorPos == 4)
            {
                defaultMode = "Turbo";
            }
            goBack = 0;
            *screen = 1;
            tft.fillScreen(ILI9341_BLACK);
            delay(150);
        }
    }
}

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(115200);
    Serial.println("Hello, ESP32!");
    tft.begin();
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);
    tft.setRotation(1);
    tft.fillScreen(ILI9341_BLACK);
    screen = 1;

    pinMode(upButton, INPUT_PULLUP);
    pinMode(downButton, INPUT_PULLUP);
    pinMode(selecButton, INPUT_PULLUP);
}

void loop()
{
    // put your main code here, to run repeatedly:
    switch (screen)
    {
    case 1:
    {
        initialScreen(&screen);
        break;
    }
    case 2:
    {
        tempScreen(&screen);
        break;
    }
    case 3:
    {
        speedScreen(&screen);
        break;
    }
    case 4:
    {
        modeScreen(&screen);
        break;
    }
    }
}
