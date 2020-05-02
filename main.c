#define REG volatile unsigned long int *

volatile unsigned long int * RCC = 0x400FE060;
volatile unsigned long int * GPIOHBCTL = 0x400FE06C;
volatile unsigned long int * RCGCGPIO = 0x400FE608;
volatile unsigned long int * GPIODIRF = 0x4005D400;

#define F_BASE  0x4005D000

#define FB(offest) F_BASE+offest

#define PIN 1

REG GPIOAFSEL_F = 0x4005D420;
REG GPIODR8R_F = F_BASE + 0x508;
REG GPIODEN_F = FB(0x51C);

REG GPIODATA_F1 = 0x4005D008;//

int main(void)
{
    *RCC |= (1<<11);
    *RCC &= ~(1<<22);
    *RCC |= (1<<4);
    *RCC &= ~(1<<5);
    *RCC |= (1<<13);

    *GPIOHBCTL |= (1<<5);

    *RCGCGPIO |= (1<<5);

    *GPIODIRF |= (1<<1);

    *GPIOAFSEL_F &= ~(1<<1);

    *GPIODR8R_F |= (1<<1);

    *GPIODEN_F |= (1<<PIN);

    *GPIODATA_F1 = (1<<PIN);
	return 0;
}

