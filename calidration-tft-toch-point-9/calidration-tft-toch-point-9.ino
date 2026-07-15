#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <XPT2046_Touchscreen.h>

#define TFT_CS    10
#define TFT_DC     9
#define TFT_RST    8

#define TFT_MOSI  11
#define TFT_MISO  13
#define TFT_SCLK  12

#define TOUCH_CS  17
#define TOUCH_IRQ  7

Adafruit_ILI9341 tft(TFT_CS, TFT_DC, TFT_RST);
XPT2046_Touchscreen ts(TOUCH_CS, TOUCH_IRQ);

// مختصات 9 نقطه
int points[9][2];

int currentPoint = 0;

int rawX[9];
int rawY[9];

void generatePoints()
{
    int margin = 20;

    int xs[3] =
    {
        margin,
        tft.width() / 2,
        tft.width() - margin
    };

    int ys[3] =
    {
        margin,
        tft.height() / 2,
        tft.height() - margin
    };

    int index = 0;

    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            points[index][0] = xs[c];
            points[index][1] = ys[r];
            index++;
        }
    }
}

void drawPoint(int x, int y)
{
    tft.fillScreen(ILI9341_BLACK);

    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);

    tft.setCursor(10,10);
    tft.print("Touch point ");
    tft.print(currentPoint + 1);
    tft.print("/9");

    tft.fillCircle(x,y,8,ILI9341_RED);
    tft.drawCircle(x,y,12,ILI9341_WHITE);
}

void setup()
{
    Serial.begin(115200);

    SPI.begin(TFT_SCLK,TFT_MISO,TFT_MOSI);

    tft.begin();

    tft.setRotation(1);

    ts.begin();
    ts.setRotation(1);

    Serial.println();
    Serial.println("Display size");

    Serial.print("Width : ");
    Serial.println(tft.width());

    Serial.print("Height: ");
    Serial.println(tft.height());

    generatePoints();

    drawPoint(points[0][0],points[0][1]);
}

void loop()
{
    if(ts.touched())
    {
        TS_Point p = ts.getPoint();

        rawX[currentPoint]=p.x;
        rawY[currentPoint]=p.y;

        Serial.print("Point ");
        Serial.print(currentPoint+1);

        Serial.print("  Screen(");
        Serial.print(points[currentPoint][0]);
        Serial.print(",");
        Serial.print(points[currentPoint][1]);
        Serial.print(")");

        Serial.print("   Raw(");
        Serial.print(p.x);
        Serial.print(",");
        Serial.print(p.y);
        Serial.println(")");

        while(ts.touched());

        delay(200);

        currentPoint++;

        if(currentPoint>=9)
        {
            Serial.println();
            Serial.println("===== CALIBRATION DATA =====");

            for(int i=0;i<9;i++)
            {
                Serial.print(i+1);

                Serial.print(" Screen(");
                Serial.print(points[i][0]);
                Serial.print(",");
                Serial.print(points[i][1]);
                Serial.print(")");

                Serial.print(" Raw(");
                Serial.print(rawX[i]);
                Serial.print(",");
                Serial.print(rawY[i]);
                Serial.println(")");
            }

            while(1);
        }

        drawPoint(points[currentPoint][0],points[currentPoint][1]);
    }
}