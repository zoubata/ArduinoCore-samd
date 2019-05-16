

#define WDT_TIMEOUT_0_8clk      0x0
#define WDT_TIMEOUT_MIN         WDT_TIMEOUT_0_8clk
#define WDT_TIMEOUT_1_16clk     0x1
#define WDT_TIMEOUT_2_32clk     0x2
#define WDT_TIMEOUT_3_64clk     0x3
#define WDT_TIMEOUT_4_128clk    0x4
#define WDT_TIMEOUT_5_256clk    0x5
#define WDT_TIMEOUT_6_512clk    0x6
#define WDT_TIMEOUT_7_1024clk   0x7
#define WDT_TIMEOUT_8_2048clk   0x8
#define WDT_TIMEOUT_9_4096clk   0x9
#define WDT_TIMEOUT_10_8192clk  0xA
#define WDT_TIMEOUT_11_16384clk 0xB
#define WDT_TIMEOUT_MAX         WDT_TIMEOUT_11_16384clk
#define WDT_TIMEOUT_4S         WDT_TIMEOUT_9_4096clk
#define WDT_TIMEOUT_2S         WDT_TIMEOUT_8_2048clk
#define WDT_TIMEOUT_1S         WDT_TIMEOUT_7_1024clk
#define WDT_TIMEOUT_0S5         WDT_TIMEOUT_6_512clk
#define WDT_TIMEOUT_0S1         WDT_TIMEOUT_4_128clk
#define WDT_TIMEOUT_100MS         WDT_TIMEOUT_4_128clk
#define WDT_TIMEOUT_50MS         WDT_TIMEOUT_3_64clk
#define WDT_TIMEOUT_10MS         WDT_TIMEOUT_1_16clk
#define WDT_TIMEOUT_5MS         WDT_TIMEOUT_0_8clk

void wdt_clr();


// code With  clock cycles count then no optimisation here,
void WDT_off(void);


void WDT_set(uint32_t timeout);
void WDT_on(  );

