#include <SD.h>
#include <vector>
#include <string>

class SDCard
{

private:
    int _size;

public:
    SDCard()
    {
        SD.begin(5);
        setSize(1);
    };
    void printFile(std::string fileName)
    {
        // int strLen = fileName.length() + 1;
        // char fileNameChar [strLen];
        // fileName.toCharArray(fileName, strLen);
        const char *c = fileName.c_str();
        File textFile = SD.open(c);
        if (textFile)
        {
            Serial.print("teste.txt: \n");
            while (textFile.available())
            {
                Serial.write(textFile.read());
            }
            textFile.close();
        }
        else
        {
            Serial.println("error opening teste.txt!");
        }
    };
    void setSize(int size)
    {
        this->_size = size;
    }
};

void setup()
{
    Serial.begin(9600);
    SDCard sd;
    sd.printFile("/teste.txt");
}

void loop() {}