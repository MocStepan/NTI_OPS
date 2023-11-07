#include "mbed.h"
#include <chrono>
#include <cstdint>
#include "stm32746g_discovery_lcd.h"

// Blinking rate in milliseconds
#define BLINKING_RATE 200ms
Thread thr1;
Thread thr2;
Thread thr3;


void led1_thread()
{
    DigitalOut led1(LED1);
    while (true) {
        led1 = !led1;
        ThisThread::sleep_for(BLINKING_RATE);
    }
}

void showStringAtDisplay(char* input, Text_AlignModeTypdef mode) 
{
        BSP_LCD_DisplayStringAt(0, 1, (uint8_t *)input, mode);
        HAL_Delay(2000);
        BSP_LCD_Clear(LCD_COLOR_BLACK);
        HAL_Delay(2000);
}

void disp1_thread() 
{
    while(true){
        showStringAtDisplay("ahoj", LEFT_MODE);
    }
}

void button_thread()
{
    DigitalIn button(PI_11);
    while(true){
        if(button == 1){
            for(int x = 0; x<= 2; x++) {
                showStringAtDisplay("Asi to funguje, ale nevím", RIGHT_MODE);
            }
        }
    }
}

// Initialise the display
void initDispl() {
    BSP_LCD_Init();
    BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FB_START_ADDRESS);
    BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
    BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
    BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
    BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
}

int main()
{
    initDispl();
    thr1.start(led1_thread);
    thr2.start(disp1_thread);
    thr3.start(button_thread);
    thr1.join();
}    
