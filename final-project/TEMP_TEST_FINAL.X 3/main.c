#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/examples/i2c2_master_example.h"
#define address 0b1001100
#define tempreg 0x00


void main(void)
{
    SYSTEM_Initialize();
    I2C2_Initialize();
    EUSART2_Initialize();
    
    uint8_t readtemp;
    uint8_t temp;
    
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
  
    while (1)
        
    {
        if(EUSART2_is_tx_ready())
        {
            readtemp = I2C2_Read1ByteRegister(address, tempreg);
            temp = (readtemp*1.8)+32;
            printf ("temp = %uF \n", readtemp,temp);
            __delay_ms(1000);
        }
        
    }
}


