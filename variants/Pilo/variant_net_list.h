//list of component
//[U_Can, R1, P12V, R2, R3, P_COM0_BIS, R4, R5, R6, R7, R8, J1, R9, J2, M_FTDI, P5VPI, C1, PI_SPI1, C2, C3, P_ANA1, C4, C5, C6, C7, C8, PI_I2C_USART, C9, P_ANA0, P_COM4, P_COM5, U_Lin, P_COM3, D10, U2B, C_C0b, L1, L2, L3, D1, D2, D3, D4, D5, D6, D7, D8, D9, U1, U2, U4, U5, M1, M3, C840, Y200, P_LIN, C_A1, C_C2in, P_COM0, P_COM1, C11, U4B, C10, C13, C12, C15, C14, C17, C16, C19, C18, C213, C212, C20, C22, C21, C24, C23, C26, C25, C28, C27, C29, Brst, CC1, C_C5, C_C4, P_CAN, CC3, C_C3, CC2, C_C2, C_C1, CC7, C_C0, P0, P3, M804, R10, R11, P_COM2_PI_SPI]
//list of net
//[SDA, RESET_N, NetJ1_2, VDDIN, NetD8_1, PA31, PA30, VSW, GND, VDD5V_PI, VDD5V, PB03, VS_CAN, VDDANA5V, PB02, PB05, PB04, PB01, PB00, NetR4_1, PB07, PB06, PB09, PB08, NetD7_1, VDD3V3, NetC19_2, LIN, GPIO13, GPIO12, GPIO15, GPIO14, CANL, GPIO17, GPIO16, GPIO19, GPIO18, CANH, VDD3V3_PI, PA04, PA03, VS_LIN, PA06, PA05, PA00, PB23, PA02, PB22, PA01, PA08, NetD2_1, PA07, PA09, NetD2_2, GPIO02, GPIO04, GPIO03, GPIO05, PB14, PB13, PB16, PB15, PB10, PB12, PB11, PB17, NetD10_1, GNDANA, PA20, PA25, PA28, PA27, PA22, PA21, PA24, PA23, NetD1_2, NetJ2_2, NetD5_1, GPIO23, NetD9_1, VDD1V2, PB30, PA15, PA14, PA17, PA16, PA11, PB31, PA10, PA13, PA12, GPIO20, PA19, SCL, PA18, GPIO21]
#define  M_FTDI  { M_FTDI_1 , M_FTDI_2 , M_FTDI_3 , M_FTDI_4 , M_FTDI_5 , M_FTDI_6 	    } 
// Connector :  M_FTDI
	#define  M_FTDI_1	(RESET_N)		/*  [Brst.1, Brst.2, C29.2, M_FTDI.1, R11.1, U1.52]*/
	#define  M_FTDI_2	(PA30)		/*  [D8.2, M_FTDI.2, P_COM1.8, U1.57, U_Lin.4]*/
	#define  M_FTDI_3	(PA31)		/*  [M_FTDI.3, P_COM1.7, R7.1, U1.58, U_Lin.1]*/
	#define  M_FTDI_4	(VDD5V)		/*  [C2.1, C3.1, C8.2, C_C0.1, C_C0b.2, C_C1.2, C_C5.2, CC3.2, L1.2, M1.45, M1.135, M1.136, M1.202, M_FTDI.4, P_COM0.2, P_COM0_BIS.2, P_COM1.2, P_COM2_PI_SPI.2, P_COM3.2, P_COM4.2, P_COM5.2, R1.2, R6.1, U1.56, U4.2, U4B.3]*/
	#define  M_FTDI_5	(GND)		/*  [Brst.3, Brst.4, Brst.5, C1.2, C2.2, C3.2, C5.2, C6.2, C8.1, C9.1, C10.1, C11.2, C12.2, C13.2, C14.2, C15.1, C16.1, C17.2, C18.1, C19.1, C20.2, C21.2, C22.2, C23.1, C24.1, C25.1, C26.1, C28.1, C29.1, C212.1, C213.1, C840.1, C_C0b.1, C_C1.1, C_C2.1, C_C2in.1, C_C3.1, C_C4.1, C_C5.1, CC7.1, D1.1, D9.2, D10.2, M1.14, M1.43, M1.44, M1.101, M1.102, M1.206, M3.6, M3.9, M3.14, M3.20, M3.25, M3.30, M3.34, M3.39, M804.2, M_FTDI.5, M_FTDI.6, P0.1, P5VPI.1, P5VPI.3, P5VPI.5, P12V.3, P_CAN.4, P_COM0.4, P_COM0_BIS.4, P_COM1.4, P_COM2_PI_SPI.4, P_COM3.4, P_COM4.4, P_COM5.4, P_LIN.3, PI_I2C_USART.4, PI_SPI1.4, R4.2, U1.22, U1.33, U1.47, U1.54, U2.3, U2B.1, U4.3, U4B.4, U5.3, U5.6, U_Can.2, U_Lin.5]*/
	#define  M_FTDI_6	(GND)		/*  [Brst.3, Brst.4, Brst.5, C1.2, C2.2, C3.2, C5.2, C6.2, C8.1, C9.1, C10.1, C11.2, C12.2, C13.2, C14.2, C15.1, C16.1, C17.2, C18.1, C19.1, C20.2, C21.2, C22.2, C23.1, C24.1, C25.1, C26.1, C28.1, C29.1, C212.1, C213.1, C840.1, C_C0b.1, C_C1.1, C_C2.1, C_C2in.1, C_C3.1, C_C4.1, C_C5.1, CC7.1, D1.1, D9.2, D10.2, M1.14, M1.43, M1.44, M1.101, M1.102, M1.206, M3.6, M3.9, M3.14, M3.20, M3.25, M3.30, M3.34, M3.39, M804.2, M_FTDI.5, M_FTDI.6, P0.1, P5VPI.1, P5VPI.3, P5VPI.5, P12V.3, P_CAN.4, P_COM0.4, P_COM0_BIS.4, P_COM1.4, P_COM2_PI_SPI.4, P_COM3.4, P_COM4.4, P_COM5.4, P_LIN.3, PI_I2C_USART.4, PI_SPI1.4, R4.2, U1.22, U1.33, U1.47, U1.54, U2.3, U2B.1, U4.3, U4B.4, U5.3, U5.6, U_Can.2, U_Lin.5]*/
#define  P_ANA0  { P_ANA0_1 , P_ANA0_10 , P_ANA0_11 , P_ANA0_12 , P_ANA0_13 , P_ANA0_14 , P_ANA0_15 , P_ANA0_16 , P_ANA0_17 , P_ANA0_18 , P_ANA0_19 , P_ANA0_2 , P_ANA0_20 , P_ANA0_3 , P_ANA0_4 , P_ANA0_5 , P_ANA0_6 , P_ANA0_7 , P_ANA0_8 , P_ANA0_9 	    } 
// Connector :  P_ANA0
	#define  P_ANA0_1	(GNDANA)		/*  [C4.2, C7.1, C27.2, C_A1.2, CC7.2, P_ANA0.1, P_ANA0.3, P_ANA0.5, P_ANA0.7, P_ANA0.9, P_ANA0.11, P_ANA0.13, P_ANA0.15, P_ANA0.17, P_ANA0.19, P_ANA0.20, P_ANA1.1, P_ANA1.3, P_ANA1.5, P_ANA1.7, P_ANA1.9, P_ANA1.11, P_ANA1.13, P_ANA1.15, P_ANA1.17, P_ANA1.19, P_ANA1.20, U1.7]*/
	#define  P_ANA0_10	(PB09)		/*  [P_ANA0.10, P_COM0_BIS.10, U1.12]*/
	#define  P_ANA0_11	(GNDANA)		/*  [C4.2, C7.1, C27.2, C_A1.2, CC7.2, P_ANA0.1, P_ANA0.3, P_ANA0.5, P_ANA0.7, P_ANA0.9, P_ANA0.11, P_ANA0.13, P_ANA0.15, P_ANA0.17, P_ANA0.19, P_ANA0.20, P_ANA1.1, P_ANA1.3, P_ANA1.5, P_ANA1.7, P_ANA1.9, P_ANA1.11, P_ANA1.13, P_ANA1.15, P_ANA1.17, P_ANA1.19, P_ANA1.20, U1.7]*/
	#define  P_ANA0_12	(PA04)		/*  [P_ANA0.12, P_COM0_BIS.6, U1.13]*/
	#define  P_ANA0_13	(GNDANA)		/*  [C4.2, C7.1, C27.2, C_A1.2, CC7.2, P_ANA0.1, P_ANA0.3, P_ANA0.5, P_ANA0.7, P_ANA0.9, P_ANA0.11, P_ANA0.13, P_ANA0.15, P_ANA0.17, P_ANA0.19, P_ANA0.20, P_ANA1.1, P_ANA1.3, P_ANA1.5, P_ANA1.7, P_ANA1.9, P_ANA1.11, P_ANA1.13, P_ANA1.15, P_ANA1.17, P_ANA1.19, P_ANA1.20, U1.7]*/
	#define  P_ANA0_14	(PA05)		/*  [P_ANA0.14, P_COM0_BIS.5, U1.14]*/
	#define  P_ANA0_15	(GNDANA)		/*  [C4.2, C7.1, C27.2, C_A1.2, CC7.2, P_ANA0.1, P_ANA0.3, P_ANA0.5, P_ANA0.7, P_ANA0.9, P_ANA0.11, P_ANA0.13, P_ANA0.15, P_ANA0.17, P_ANA0.19, P_ANA0.20, P_ANA1.1, P_ANA1.3, P_ANA1.5, P_ANA1.7, P_ANA1.9, P_ANA1.11, P_ANA1.13, P_ANA1.15, P_ANA1.17, P_ANA1.19, P_ANA1.20, U1.7]*/
	#define  P_ANA0_16	(PA06)		/*  [P_ANA0.16, P_COM0_BIS.8, U1.15]*/
	#define  P_ANA0_17	(GNDANA)		/*  [C4.2, C7.1, C27.2, C_A1.2, CC7.2, P_ANA0.1, P_ANA0.3, P_ANA0.5, P_ANA0.7, P_ANA0.9, P_ANA0.11, P_ANA0.13, P_ANA0.15, P_ANA0.17, P_ANA0.19, P_ANA0.20, P_ANA1.1, P_ANA1.3, P_ANA1.5, P_ANA1.7, P_ANA1.9, P_ANA1.11, P_ANA1.13, P_ANA1.15, P_ANA1.17, P_ANA1.19, P_ANA1.20, U1.7]*/
	#define  P_ANA0_18	(PA07)		/*  [P_ANA0.18, P_COM0_BIS.7, U1.16]*/
	#define  P_ANA0_19	(GNDANA)		/*  [C4.2, C7.1, C27.2, C_A1.2, CC7.2, P_ANA0.1, P_ANA0.3, P_ANA0.5, P_ANA0.7, P_ANA0.9, P_ANA0.11, P_ANA0.13, P_ANA0.15, P_ANA0.17, P_ANA0.19, P_ANA0.20, P_ANA1.1, P_ANA1.3, P_ANA1.5, P_ANA1.7, P_ANA1.9, P_ANA1.11, P_ANA1.13, P_ANA1.15, P_ANA1.17, P_ANA1.19, P_ANA1.20, U1.7]*/
	#define  P_ANA0_2	(VDDANA5V)		/*  [C4.1, C7.2, C27.1, C_A1.1, L1.1, P_ANA0.2, P_ANA1.2, U1.8]*/
	#define  P_ANA0_20	(GNDANA)		/*  [C4.2, C7.1, C27.2, C_A1.2, CC7.2, P_ANA0.1, P_ANA0.3, P_ANA0.5, P_ANA0.7, P_ANA0.9, P_ANA0.11, P_ANA0.13, P_ANA0.15, P_ANA0.17, P_ANA0.19, P_ANA0.20, P_ANA1.1, P_ANA1.3, P_ANA1.5, P_ANA1.7, P_ANA1.9, P_ANA1.11, P_ANA1.13, P_ANA1.15, P_ANA1.17, P_ANA1.19, P_ANA1.20, U1.7]*/
	#define  P_ANA0_3	(GNDANA)		/*  [C4.2, C7.1, C27.2, C_A1.2, CC7.2, P_ANA0.1, P_ANA0.3, P_ANA0.5, P_ANA0.7, P_ANA0.9, P_ANA0.11, P_ANA0.13, P_ANA0.15, P_ANA0.17, P_ANA0.19, P_ANA0.20, P_ANA1.1, P_ANA1.3, P_ANA1.5, P_ANA1.7, P_ANA1.9, P_ANA1.11, P_ANA1.13, P_ANA1.15, P_ANA1.17, P_ANA1.19, P_ANA1.20, U1.7]*/
	#define  P_ANA0_4	(PB06)		/*  [P_ANA0.4, U1.9, U5.5]*/
	#define  P_ANA0_5	(GNDANA)		/*  [C4.2, C7.1, C27.2, C_A1.2, CC7.2, P_ANA0.1, P_ANA0.3, P_ANA0.5, P_ANA0.7, P_ANA0.9, P_ANA0.11, P_ANA0.13, P_ANA0.15, P_ANA0.17, P_ANA0.19, P_ANA0.20, P_ANA1.1, P_ANA1.3, P_ANA1.5, P_ANA1.7, P_ANA1.9, P_ANA1.11, P_ANA1.13, P_ANA1.15, P_ANA1.17, P_ANA1.19, P_ANA1.20, U1.7]*/
	#define  P_ANA0_6	(PB07)		/*  [P_ANA0.6, U1.10]*/
	#define  P_ANA0_7	(GNDANA)		/*  [C4.2, C7.1, C27.2, C_A1.2, CC7.2, P_ANA0.1, P_ANA0.3, P_ANA0.5, P_ANA0.7, P_ANA0.9, P_ANA0.11, P_ANA0.13, P_ANA0.15, P_ANA0.17, P_ANA0.19, P_ANA0.20, P_ANA1.1, P_ANA1.3, P_ANA1.5, P_ANA1.7, P_ANA1.9, P_ANA1.11, P_ANA1.13, P_ANA1.15, P_ANA1.17, P_ANA1.19, P_ANA1.20, U1.7]*/
	#define  P_ANA0_8	(PB08)		/*  [P_ANA0.8, P_COM0_BIS.9, U1.11]*/
	#define  P_ANA0_9	(GNDANA)		/*  [C4.2, C7.1, C27.2, C_A1.2, CC7.2, P_ANA0.1, P_ANA0.3, P_ANA0.5, P_ANA0.7, P_ANA0.9, P_ANA0.11, P_ANA0.13, P_ANA0.15, P_ANA0.17, P_ANA0.19, P_ANA0.20, P_ANA1.1, P_ANA1.3, P_ANA1.5, P_ANA1.7, P_ANA1.9, P_ANA1.11, P_ANA1.13, P_ANA1.15, P_ANA1.17, P_ANA1.19, P_ANA1.20, U1.7]*/
#define  P_ANA1  { P_ANA1_1 , P_ANA1_10 , P_ANA1_11 , P_ANA1_12 , P_ANA1_13 , P_ANA1_14 , P_ANA1_15 , P_ANA1_16 , P_ANA1_17 , P_ANA1_18 , P_ANA1_19 , P_ANA1_2 , P_ANA1_20 , P_ANA1_3 , P_ANA1_4 , P_ANA1_5 , P_ANA1_6 , P_ANA1_7 , P_ANA1_8 , P_ANA1_9 	    } 
// Connector :  P_ANA1
	#define  P_ANA1_1	(GNDANA)		/*  [C4.2, C7.1, C27.2, C_A1.2, CC7.2, P_ANA0.1, P_ANA0.3, P_ANA0.5, P_ANA0.7, P_ANA0.9, P_ANA0.11, P_ANA0.13, P_ANA0.15, P_ANA0.17, P_ANA0.19, P_ANA0.20, P_ANA1.1, P_ANA1.3, P_ANA1.5, P_ANA1.7, P_ANA1.9, P_ANA1.11, P_ANA1.13, P_ANA1.15, P_ANA1.17, P_ANA1.19, P_ANA1.20, U1.7]*/
	#define  P_ANA1_10	(PB03)		/*  [P_ANA1.10, U1.64]*/
	#define  P_ANA1_11	(GNDANA)		/*  [C4.2, C7.1, C27.2, C_A1.2, CC7.2, P_ANA0.1, P_ANA0.3, P_ANA0.5, P_ANA0.7, P_ANA0.9, P_ANA0.11, P_ANA0.13, P_ANA0.15, P_ANA0.17, P_ANA0.19, P_ANA0.20, P_ANA1.1, P_ANA1.3, P_ANA1.5, P_ANA1.7, P_ANA1.9, P_ANA1.11, P_ANA1.13, P_ANA1.15, P_ANA1.17, P_ANA1.19, P_ANA1.20, U1.7]*/
	#define  P_ANA1_12	(PA02)		/*  [P_ANA1.12, U1.3]*/
	#define  P_ANA1_13	(GNDANA)		/*  [C4.2, C7.1, C27.2, C_A1.2, CC7.2, P_ANA0.1, P_ANA0.3, P_ANA0.5, P_ANA0.7, P_ANA0.9, P_ANA0.11, P_ANA0.13, P_ANA0.15, P_ANA0.17, P_ANA0.19, P_ANA0.20, P_ANA1.1, P_ANA1.3, P_ANA1.5, P_ANA1.7, P_ANA1.9, P_ANA1.11, P_ANA1.13, P_ANA1.15, P_ANA1.17, P_ANA1.19, P_ANA1.20, U1.7]*/
	#define  P_ANA1_14	(PA03)		/*  [P_ANA1.14, U1.4]*/
	#define  P_ANA1_15	(GNDANA)		/*  [C4.2, C7.1, C27.2, C_A1.2, CC7.2, P_ANA0.1, P_ANA0.3, P_ANA0.5, P_ANA0.7, P_ANA0.9, P_ANA0.11, P_ANA0.13, P_ANA0.15, P_ANA0.17, P_ANA0.19, P_ANA0.20, P_ANA1.1, P_ANA1.3, P_ANA1.5, P_ANA1.7, P_ANA1.9, P_ANA1.11, P_ANA1.13, P_ANA1.15, P_ANA1.17, P_ANA1.19, P_ANA1.20, U1.7]*/
	#define  P_ANA1_16	(PB04)		/*  [P_ANA1.16, U1.5]*/
	#define  P_ANA1_17	(GNDANA)		/*  [C4.2, C7.1, C27.2, C_A1.2, CC7.2, P_ANA0.1, P_ANA0.3, P_ANA0.5, P_ANA0.7, P_ANA0.9, P_ANA0.11, P_ANA0.13, P_ANA0.15, P_ANA0.17, P_ANA0.19, P_ANA0.20, P_ANA1.1, P_ANA1.3, P_ANA1.5, P_ANA1.7, P_ANA1.9, P_ANA1.11, P_ANA1.13, P_ANA1.15, P_ANA1.17, P_ANA1.19, P_ANA1.20, U1.7]*/
	#define  P_ANA1_18	(PB05)		/*  [P_ANA1.18, U1.6]*/
	#define  P_ANA1_19	(GNDANA)		/*  [C4.2, C7.1, C27.2, C_A1.2, CC7.2, P_ANA0.1, P_ANA0.3, P_ANA0.5, P_ANA0.7, P_ANA0.9, P_ANA0.11, P_ANA0.13, P_ANA0.15, P_ANA0.17, P_ANA0.19, P_ANA0.20, P_ANA1.1, P_ANA1.3, P_ANA1.5, P_ANA1.7, P_ANA1.9, P_ANA1.11, P_ANA1.13, P_ANA1.15, P_ANA1.17, P_ANA1.19, P_ANA1.20, U1.7]*/
	#define  P_ANA1_2	(VDDANA5V)		/*  [C4.1, C7.2, C27.1, C_A1.1, L1.1, P_ANA0.2, P_ANA1.2, U1.8]*/
	#define  P_ANA1_20	(GNDANA)		/*  [C4.2, C7.1, C27.2, C_A1.2, CC7.2, P_ANA0.1, P_ANA0.3, P_ANA0.5, P_ANA0.7, P_ANA0.9, P_ANA0.11, P_ANA0.13, P_ANA0.15, P_ANA0.17, P_ANA0.19, P_ANA0.20, P_ANA1.1, P_ANA1.3, P_ANA1.5, P_ANA1.7, P_ANA1.9, P_ANA1.11, P_ANA1.13, P_ANA1.15, P_ANA1.17, P_ANA1.19, P_ANA1.20, U1.7]*/
	#define  P_ANA1_3	(GNDANA)		/*  [C4.2, C7.1, C27.2, C_A1.2, CC7.2, P_ANA0.1, P_ANA0.3, P_ANA0.5, P_ANA0.7, P_ANA0.9, P_ANA0.11, P_ANA0.13, P_ANA0.15, P_ANA0.17, P_ANA0.19, P_ANA0.20, P_ANA1.1, P_ANA1.3, P_ANA1.5, P_ANA1.7, P_ANA1.9, P_ANA1.11, P_ANA1.13, P_ANA1.15, P_ANA1.17, P_ANA1.19, P_ANA1.20, U1.7]*/
	#define  P_ANA1_4	(PB00)		/*  [P_ANA1.4, P_COM1.10, R6.2, U1.61, U_Lin.8]*/
	#define  P_ANA1_5	(GNDANA)		/*  [C4.2, C7.1, C27.2, C_A1.2, CC7.2, P_ANA0.1, P_ANA0.3, P_ANA0.5, P_ANA0.7, P_ANA0.9, P_ANA0.11, P_ANA0.13, P_ANA0.15, P_ANA0.17, P_ANA0.19, P_ANA0.20, P_ANA1.1, P_ANA1.3, P_ANA1.5, P_ANA1.7, P_ANA1.9, P_ANA1.11, P_ANA1.13, P_ANA1.15, P_ANA1.17, P_ANA1.19, P_ANA1.20, U1.7]*/
	#define  P_ANA1_6	(PB01)		/*  [P_ANA1.6, P_COM1.9, R8.2, U1.62, U_Lin.2]*/
	#define  P_ANA1_7	(GNDANA)		/*  [C4.2, C7.1, C27.2, C_A1.2, CC7.2, P_ANA0.1, P_ANA0.3, P_ANA0.5, P_ANA0.7, P_ANA0.9, P_ANA0.11, P_ANA0.13, P_ANA0.15, P_ANA0.17, P_ANA0.19, P_ANA0.20, P_ANA1.1, P_ANA1.3, P_ANA1.5, P_ANA1.7, P_ANA1.9, P_ANA1.11, P_ANA1.13, P_ANA1.15, P_ANA1.17, P_ANA1.19, P_ANA1.20, U1.7]*/
	#define  P_ANA1_8	(PB02)		/*  [P_ANA1.8, U1.63]*/
	#define  P_ANA1_9	(GNDANA)		/*  [C4.2, C7.1, C27.2, C_A1.2, CC7.2, P_ANA0.1, P_ANA0.3, P_ANA0.5, P_ANA0.7, P_ANA0.9, P_ANA0.11, P_ANA0.13, P_ANA0.15, P_ANA0.17, P_ANA0.19, P_ANA0.20, P_ANA1.1, P_ANA1.3, P_ANA1.5, P_ANA1.7, P_ANA1.9, P_ANA1.11, P_ANA1.13, P_ANA1.15, P_ANA1.17, P_ANA1.19, P_ANA1.20, U1.7]*/
#define  P_CAN  { P_CAN_1 , P_CAN_2 , P_CAN_3 , P_CAN_4 	    } 
// Connector :  P_CAN
	#define  P_CAN_1	(VS_CAN)		/*  [D4.1, P_CAN.1]*/
	#define  P_CAN_2	(CANH)		/*  [P_CAN.2, R2.2, U_Can.7]*/
	#define  P_CAN_3	(CANL)		/*  [P_CAN.3, R3.1, U_Can.6]*/
	#define  P_CAN_4	(GND)		/*  [Brst.3, Brst.4, Brst.5, C1.2, C2.2, C3.2, C5.2, C6.2, C8.1, C9.1, C10.1, C11.2, C12.2, C13.2, C14.2, C15.1, C16.1, C17.2, C18.1, C19.1, C20.2, C21.2, C22.2, C23.1, C24.1, C25.1, C26.1, C28.1, C29.1, C212.1, C213.1, C840.1, C_C0b.1, C_C1.1, C_C2.1, C_C2in.1, C_C3.1, C_C4.1, C_C5.1, CC7.1, D1.1, D9.2, D10.2, M1.14, M1.43, M1.44, M1.101, M1.102, M1.206, M3.6, M3.9, M3.14, M3.20, M3.25, M3.30, M3.34, M3.39, M804.2, M_FTDI.5, M_FTDI.6, P0.1, P5VPI.1, P5VPI.3, P5VPI.5, P12V.3, P_CAN.4, P_COM0.4, P_COM0_BIS.4, P_COM1.4, P_COM2_PI_SPI.4, P_COM3.4, P_COM4.4, P_COM5.4, P_LIN.3, PI_I2C_USART.4, PI_SPI1.4, R4.2, U1.22, U1.33, U1.47, U1.54, U2.3, U2B.1, U4.3, U4B.4, U5.3, U5.6, U_Can.2, U_Lin.5]*/
#define  P_COM0  { P_COM0_1 , P_COM0_10 , P_COM0_2 , P_COM0_3 , P_COM0_4 , P_COM0_5 , P_COM0_6 , P_COM0_7 , P_COM0_8 , P_COM0_9 	    } 
// Connector :  P_COM0
	#define  P_COM0_1	(VDDIN)		/*  [C1.1, C11.1, C14.1, C15.2, C20.1, C21.1, C_C2in.2, D3.2, D4.2, D5.2, D7.2, M1.42, P3.2, P_COM0.1, P_COM0_BIS.1, P_COM1.1, P_COM2_PI_SPI.1, P_COM3.1, P_COM4.1, P_COM5.1, PI_I2C_USART.1, PI_SPI1.1, U2.2, U2B.3, U4.1, U4B.1, U5.1, U_Lin.7]*/
	#define  P_COM0_10	(PA21)		/*  [M804.3, P_COM0.10, U1.42]*/
	#define  P_COM0_2	(VDD5V)		/*  [C2.1, C3.1, C8.2, C_C0.1, C_C0b.2, C_C1.2, C_C5.2, CC3.2, L1.2, M1.45, M1.135, M1.136, M1.202, M_FTDI.4, P_COM0.2, P_COM0_BIS.2, P_COM1.2, P_COM2_PI_SPI.2, P_COM3.2, P_COM4.2, P_COM5.2, R1.2, R6.1, U1.56, U4.2, U4B.3]*/
	#define  P_COM0_3	(VDD3V3)		/*  [C6.1, C10.2, C12.1, C13.1, C18.2, C840.2, C_C0.2, C_C2.2, C_C3.2, C_C4.2, CC3.1, M1.46, M804.1, P_COM0.3, P_COM0_BIS.3, P_COM1.3, P_COM2_PI_SPI.3, P_COM3.3, P_COM4.3, P_COM5.3, U1.21, U1.34, U1.48, U2.1, U2B.2, U_Can.3]*/
	#define  P_COM0_4	(GND)		/*  [Brst.3, Brst.4, Brst.5, C1.2, C2.2, C3.2, C5.2, C6.2, C8.1, C9.1, C10.1, C11.2, C12.2, C13.2, C14.2, C15.1, C16.1, C17.2, C18.1, C19.1, C20.2, C21.2, C22.2, C23.1, C24.1, C25.1, C26.1, C28.1, C29.1, C212.1, C213.1, C840.1, C_C0b.1, C_C1.1, C_C2.1, C_C2in.1, C_C3.1, C_C4.1, C_C5.1, CC7.1, D1.1, D9.2, D10.2, M1.14, M1.43, M1.44, M1.101, M1.102, M1.206, M3.6, M3.9, M3.14, M3.20, M3.25, M3.30, M3.34, M3.39, M804.2, M_FTDI.5, M_FTDI.6, P0.1, P5VPI.1, P5VPI.3, P5VPI.5, P12V.3, P_CAN.4, P_COM0.4, P_COM0_BIS.4, P_COM1.4, P_COM2_PI_SPI.4, P_COM3.4, P_COM4.4, P_COM5.4, P_LIN.3, PI_I2C_USART.4, PI_SPI1.4, R4.2, U1.22, U1.33, U1.47, U1.54, U2.3, U2B.1, U4.3, U4B.4, U5.3, U5.6, U_Can.2, U_Lin.5]*/
	#define  P_COM0_5	(PA09)		/*  [M804.5, P_COM0.5, U1.18]*/
	#define  P_COM0_6	(PA08)		/*  [M804.7, P_COM0.6, U1.17]*/
	#define  P_COM0_7	(PA11)		/*  [M804.6, P_COM0.7, U1.20]*/
	#define  P_COM0_8	(PA10)		/*  [M804.4, P_COM0.8, U1.19]*/
	#define  P_COM0_9	(PA18)		/*  [M804.8, P_COM0.9, U1.37]*/
#define  P_COM0_BIS  { P_COM0_BIS_1 , P_COM0_BIS_10 , P_COM0_BIS_2 , P_COM0_BIS_3 , P_COM0_BIS_4 , P_COM0_BIS_5 , P_COM0_BIS_6 , P_COM0_BIS_7 , P_COM0_BIS_8 , P_COM0_BIS_9 	    } 
// Connector :  P_COM0_BIS
	#define  P_COM0_BIS_1	(VDDIN)		/*  [C1.1, C11.1, C14.1, C15.2, C20.1, C21.1, C_C2in.2, D3.2, D4.2, D5.2, D7.2, M1.42, P3.2, P_COM0.1, P_COM0_BIS.1, P_COM1.1, P_COM2_PI_SPI.1, P_COM3.1, P_COM4.1, P_COM5.1, PI_I2C_USART.1, PI_SPI1.1, U2.2, U2B.3, U4.1, U4B.1, U5.1, U_Lin.7]*/
	#define  P_COM0_BIS_10	(PB09)		/*  [P_ANA0.10, P_COM0_BIS.10, U1.12]*/
	#define  P_COM0_BIS_2	(VDD5V)		/*  [C2.1, C3.1, C8.2, C_C0.1, C_C0b.2, C_C1.2, C_C5.2, CC3.2, L1.2, M1.45, M1.135, M1.136, M1.202, M_FTDI.4, P_COM0.2, P_COM0_BIS.2, P_COM1.2, P_COM2_PI_SPI.2, P_COM3.2, P_COM4.2, P_COM5.2, R1.2, R6.1, U1.56, U4.2, U4B.3]*/
	#define  P_COM0_BIS_3	(VDD3V3)		/*  [C6.1, C10.2, C12.1, C13.1, C18.2, C840.2, C_C0.2, C_C2.2, C_C3.2, C_C4.2, CC3.1, M1.46, M804.1, P_COM0.3, P_COM0_BIS.3, P_COM1.3, P_COM2_PI_SPI.3, P_COM3.3, P_COM4.3, P_COM5.3, U1.21, U1.34, U1.48, U2.1, U2B.2, U_Can.3]*/
	#define  P_COM0_BIS_4	(GND)		/*  [Brst.3, Brst.4, Brst.5, C1.2, C2.2, C3.2, C5.2, C6.2, C8.1, C9.1, C10.1, C11.2, C12.2, C13.2, C14.2, C15.1, C16.1, C17.2, C18.1, C19.1, C20.2, C21.2, C22.2, C23.1, C24.1, C25.1, C26.1, C28.1, C29.1, C212.1, C213.1, C840.1, C_C0b.1, C_C1.1, C_C2.1, C_C2in.1, C_C3.1, C_C4.1, C_C5.1, CC7.1, D1.1, D9.2, D10.2, M1.14, M1.43, M1.44, M1.101, M1.102, M1.206, M3.6, M3.9, M3.14, M3.20, M3.25, M3.30, M3.34, M3.39, M804.2, M_FTDI.5, M_FTDI.6, P0.1, P5VPI.1, P5VPI.3, P5VPI.5, P12V.3, P_CAN.4, P_COM0.4, P_COM0_BIS.4, P_COM1.4, P_COM2_PI_SPI.4, P_COM3.4, P_COM4.4, P_COM5.4, P_LIN.3, PI_I2C_USART.4, PI_SPI1.4, R4.2, U1.22, U1.33, U1.47, U1.54, U2.3, U2B.1, U4.3, U4B.4, U5.3, U5.6, U_Can.2, U_Lin.5]*/
	#define  P_COM0_BIS_5	(PA05)		/*  [P_ANA0.14, P_COM0_BIS.5, U1.14]*/
	#define  P_COM0_BIS_6	(PA04)		/*  [P_ANA0.12, P_COM0_BIS.6, U1.13]*/
	#define  P_COM0_BIS_7	(PA07)		/*  [P_ANA0.18, P_COM0_BIS.7, U1.16]*/
	#define  P_COM0_BIS_8	(PA06)		/*  [P_ANA0.16, P_COM0_BIS.8, U1.15]*/
	#define  P_COM0_BIS_9	(PB08)		/*  [P_ANA0.8, P_COM0_BIS.9, U1.11]*/
#define  P_COM1  { P_COM1_1 , P_COM1_10 , P_COM1_2 , P_COM1_3 , P_COM1_4 , P_COM1_5 , P_COM1_6 , P_COM1_7 , P_COM1_8 , P_COM1_9 	    } 
// Connector :  P_COM1
	#define  P_COM1_1	(VDDIN)		/*  [C1.1, C11.1, C14.1, C15.2, C20.1, C21.1, C_C2in.2, D3.2, D4.2, D5.2, D7.2, M1.42, P3.2, P_COM0.1, P_COM0_BIS.1, P_COM1.1, P_COM2_PI_SPI.1, P_COM3.1, P_COM4.1, P_COM5.1, PI_I2C_USART.1, PI_SPI1.1, U2.2, U2B.3, U4.1, U4B.1, U5.1, U_Lin.7]*/
	#define  P_COM1_10	(PB00)		/*  [P_ANA1.4, P_COM1.10, R6.2, U1.61, U_Lin.8]*/
	#define  P_COM1_2	(VDD5V)		/*  [C2.1, C3.1, C8.2, C_C0.1, C_C0b.2, C_C1.2, C_C5.2, CC3.2, L1.2, M1.45, M1.135, M1.136, M1.202, M_FTDI.4, P_COM0.2, P_COM0_BIS.2, P_COM1.2, P_COM2_PI_SPI.2, P_COM3.2, P_COM4.2, P_COM5.2, R1.2, R6.1, U1.56, U4.2, U4B.3]*/
	#define  P_COM1_3	(VDD3V3)		/*  [C6.1, C10.2, C12.1, C13.1, C18.2, C840.2, C_C0.2, C_C2.2, C_C3.2, C_C4.2, CC3.1, M1.46, M804.1, P_COM0.3, P_COM0_BIS.3, P_COM1.3, P_COM2_PI_SPI.3, P_COM3.3, P_COM4.3, P_COM5.3, U1.21, U1.34, U1.48, U2.1, U2B.2, U_Can.3]*/
	#define  P_COM1_4	(GND)		/*  [Brst.3, Brst.4, Brst.5, C1.2, C2.2, C3.2, C5.2, C6.2, C8.1, C9.1, C10.1, C11.2, C12.2, C13.2, C14.2, C15.1, C16.1, C17.2, C18.1, C19.1, C20.2, C21.2, C22.2, C23.1, C24.1, C25.1, C26.1, C28.1, C29.1, C212.1, C213.1, C840.1, C_C0b.1, C_C1.1, C_C2.1, C_C2in.1, C_C3.1, C_C4.1, C_C5.1, CC7.1, D1.1, D9.2, D10.2, M1.14, M1.43, M1.44, M1.101, M1.102, M1.206, M3.6, M3.9, M3.14, M3.20, M3.25, M3.30, M3.34, M3.39, M804.2, M_FTDI.5, M_FTDI.6, P0.1, P5VPI.1, P5VPI.3, P5VPI.5, P12V.3, P_CAN.4, P_COM0.4, P_COM0_BIS.4, P_COM1.4, P_COM2_PI_SPI.4, P_COM3.4, P_COM4.4, P_COM5.4, P_LIN.3, PI_I2C_USART.4, PI_SPI1.4, R4.2, U1.22, U1.33, U1.47, U1.54, U2.3, U2B.1, U4.3, U4B.4, U5.3, U5.6, U_Can.2, U_Lin.5]*/
	#define  P_COM1_5	(PA01)		/*  [C213.2, P_COM1.5, U1.2, Y200.4]*/
	#define  P_COM1_6	(PA00)		/*  [C212.2, P_COM1.6, U1.1, Y200.1]*/
	#define  P_COM1_7	(PA31)		/*  [M_FTDI.3, P_COM1.7, R7.1, U1.58, U_Lin.1]*/
	#define  P_COM1_8	(PA30)		/*  [D8.2, M_FTDI.2, P_COM1.8, U1.57, U_Lin.4]*/
	#define  P_COM1_9	(PB01)		/*  [P_ANA1.6, P_COM1.9, R8.2, U1.62, U_Lin.2]*/
#define  P_COM2_PI_SPI  { P_COM2_PI_SPI_1 , P_COM2_PI_SPI_10 , P_COM2_PI_SPI_2 , P_COM2_PI_SPI_3 , P_COM2_PI_SPI_4 , P_COM2_PI_SPI_5 , P_COM2_PI_SPI_6 , P_COM2_PI_SPI_7 , P_COM2_PI_SPI_8 , P_COM2_PI_SPI_9 	    } 
// Connector :  P_COM2_PI_SPI
	#define  P_COM2_PI_SPI_1	(VDDIN)		/*  [C1.1, C11.1, C14.1, C15.2, C20.1, C21.1, C_C2in.2, D3.2, D4.2, D5.2, D7.2, M1.42, P3.2, P_COM0.1, P_COM0_BIS.1, P_COM1.1, P_COM2_PI_SPI.1, P_COM3.1, P_COM4.1, P_COM5.1, PI_I2C_USART.1, PI_SPI1.1, U2.2, U2B.3, U4.1, U4B.1, U5.1, U_Lin.7]*/
	#define  P_COM2_PI_SPI_10	(PA17)		/*  [M3.13, P_COM2_PI_SPI.10, U1.36]*/
	#define  P_COM2_PI_SPI_2	(VDD5V)		/*  [C2.1, C3.1, C8.2, C_C0.1, C_C0b.2, C_C1.2, C_C5.2, CC3.2, L1.2, M1.45, M1.135, M1.136, M1.202, M_FTDI.4, P_COM0.2, P_COM0_BIS.2, P_COM1.2, P_COM2_PI_SPI.2, P_COM3.2, P_COM4.2, P_COM5.2, R1.2, R6.1, U1.56, U4.2, U4B.3]*/
	#define  P_COM2_PI_SPI_3	(VDD3V3)		/*  [C6.1, C10.2, C12.1, C13.1, C18.2, C840.2, C_C0.2, C_C2.2, C_C3.2, C_C4.2, CC3.1, M1.46, M804.1, P_COM0.3, P_COM0_BIS.3, P_COM1.3, P_COM2_PI_SPI.3, P_COM3.3, P_COM4.3, P_COM5.3, U1.21, U1.34, U1.48, U2.1, U2B.2, U_Can.3]*/
	#define  P_COM2_PI_SPI_4	(GND)		/*  [Brst.3, Brst.4, Brst.5, C1.2, C2.2, C3.2, C5.2, C6.2, C8.1, C9.1, C10.1, C11.2, C12.2, C13.2, C14.2, C15.1, C16.1, C17.2, C18.1, C19.1, C20.2, C21.2, C22.2, C23.1, C24.1, C25.1, C26.1, C28.1, C29.1, C212.1, C213.1, C840.1, C_C0b.1, C_C1.1, C_C2.1, C_C2in.1, C_C3.1, C_C4.1, C_C5.1, CC7.1, D1.1, D9.2, D10.2, M1.14, M1.43, M1.44, M1.101, M1.102, M1.206, M3.6, M3.9, M3.14, M3.20, M3.25, M3.30, M3.34, M3.39, M804.2, M_FTDI.5, M_FTDI.6, P0.1, P5VPI.1, P5VPI.3, P5VPI.5, P12V.3, P_CAN.4, P_COM0.4, P_COM0_BIS.4, P_COM1.4, P_COM2_PI_SPI.4, P_COM3.4, P_COM4.4, P_COM5.4, P_LIN.3, PI_I2C_USART.4, PI_SPI1.4, R4.2, U1.22, U1.33, U1.47, U1.54, U2.3, U2B.1, U4.3, U4B.4, U5.3, U5.6, U_Can.2, U_Lin.5]*/
	#define  P_COM2_PI_SPI_5	(PA13)		/*  [M3.23, P_COM2_PI_SPI.5, U1.30]*/
	#define  P_COM2_PI_SPI_6	(PA12)		/*  [M3.21, P_COM2_PI_SPI.6, U1.29]*/
	#define  P_COM2_PI_SPI_7	(PA15)		/*  [M3.19, P_COM2_PI_SPI.7, U1.32]*/
	#define  P_COM2_PI_SPI_8	(PA14)		/*  [J1.1, J2.1, P_COM2_PI_SPI.8, U1.31]*/
	#define  P_COM2_PI_SPI_9	(PA16)		/*  [M3.15, P_COM2_PI_SPI.9, U1.35]*/
#define  P_COM3  { P_COM3_1 , P_COM3_10 , P_COM3_2 , P_COM3_3 , P_COM3_4 , P_COM3_5 , P_COM3_6 , P_COM3_7 , P_COM3_8 , P_COM3_9 	    } 
// Connector :  P_COM3
	#define  P_COM3_1	(VDDIN)		/*  [C1.1, C11.1, C14.1, C15.2, C20.1, C21.1, C_C2in.2, D3.2, D4.2, D5.2, D7.2, M1.42, P3.2, P_COM0.1, P_COM0_BIS.1, P_COM1.1, P_COM2_PI_SPI.1, P_COM3.1, P_COM4.1, P_COM5.1, PI_I2C_USART.1, PI_SPI1.1, U2.2, U2B.3, U4.1, U4B.1, U5.1, U_Lin.7]*/
	#define  P_COM3_10	(PA20)		/*  [P_COM3.10, U1.41]*/
	#define  P_COM3_2	(VDD5V)		/*  [C2.1, C3.1, C8.2, C_C0.1, C_C0b.2, C_C1.2, C_C5.2, CC3.2, L1.2, M1.45, M1.135, M1.136, M1.202, M_FTDI.4, P_COM0.2, P_COM0_BIS.2, P_COM1.2, P_COM2_PI_SPI.2, P_COM3.2, P_COM4.2, P_COM5.2, R1.2, R6.1, U1.56, U4.2, U4B.3]*/
	#define  P_COM3_3	(VDD3V3)		/*  [C6.1, C10.2, C12.1, C13.1, C18.2, C840.2, C_C0.2, C_C2.2, C_C3.2, C_C4.2, CC3.1, M1.46, M804.1, P_COM0.3, P_COM0_BIS.3, P_COM1.3, P_COM2_PI_SPI.3, P_COM3.3, P_COM4.3, P_COM5.3, U1.21, U1.34, U1.48, U2.1, U2B.2, U_Can.3]*/
	#define  P_COM3_4	(GND)		/*  [Brst.3, Brst.4, Brst.5, C1.2, C2.2, C3.2, C5.2, C6.2, C8.1, C9.1, C10.1, C11.2, C12.2, C13.2, C14.2, C15.1, C16.1, C17.2, C18.1, C19.1, C20.2, C21.2, C22.2, C23.1, C24.1, C25.1, C26.1, C28.1, C29.1, C212.1, C213.1, C840.1, C_C0b.1, C_C1.1, C_C2.1, C_C2in.1, C_C3.1, C_C4.1, C_C5.1, CC7.1, D1.1, D9.2, D10.2, M1.14, M1.43, M1.44, M1.101, M1.102, M1.206, M3.6, M3.9, M3.14, M3.20, M3.25, M3.30, M3.34, M3.39, M804.2, M_FTDI.5, M_FTDI.6, P0.1, P5VPI.1, P5VPI.3, P5VPI.5, P12V.3, P_CAN.4, P_COM0.4, P_COM0_BIS.4, P_COM1.4, P_COM2_PI_SPI.4, P_COM3.4, P_COM4.4, P_COM5.4, P_LIN.3, PI_I2C_USART.4, PI_SPI1.4, R4.2, U1.22, U1.33, U1.47, U1.54, U2.3, U2B.1, U4.3, U4B.4, U5.3, U5.6, U_Can.2, U_Lin.5]*/
	#define  P_COM3_5	(PA23)		/*  [P_COM3.5, U1.44]*/
	#define  P_COM3_6	(PA22)		/*  [P_COM3.6, U1.43]*/
	#define  P_COM3_7	(PA25)		/*  [P_COM3.7, U1.46]*/
	#define  P_COM3_8	(PA24)		/*  [P_COM3.8, U1.45]*/
	#define  P_COM3_9	(PA19)		/*  [P_COM3.9, U1.38]*/
#define  P_COM4  { P_COM4_1 , P_COM4_10 , P_COM4_2 , P_COM4_3 , P_COM4_4 , P_COM4_5 , P_COM4_6 , P_COM4_7 , P_COM4_8 , P_COM4_9 	    } 
// Connector :  P_COM4
	#define  P_COM4_1	(VDDIN)		/*  [C1.1, C11.1, C14.1, C15.2, C20.1, C21.1, C_C2in.2, D3.2, D4.2, D5.2, D7.2, M1.42, P3.2, P_COM0.1, P_COM0_BIS.1, P_COM1.1, P_COM2_PI_SPI.1, P_COM3.1, P_COM4.1, P_COM5.1, PI_I2C_USART.1, PI_SPI1.1, U2.2, U2B.3, U4.1, U4B.1, U5.1, U_Lin.7]*/
	#define  P_COM4_10	(PB16)		/*  [P_COM4.10, U1.39]*/
	#define  P_COM4_2	(VDD5V)		/*  [C2.1, C3.1, C8.2, C_C0.1, C_C0b.2, C_C1.2, C_C5.2, CC3.2, L1.2, M1.45, M1.135, M1.136, M1.202, M_FTDI.4, P_COM0.2, P_COM0_BIS.2, P_COM1.2, P_COM2_PI_SPI.2, P_COM3.2, P_COM4.2, P_COM5.2, R1.2, R6.1, U1.56, U4.2, U4B.3]*/
	#define  P_COM4_3	(VDD3V3)		/*  [C6.1, C10.2, C12.1, C13.1, C18.2, C840.2, C_C0.2, C_C2.2, C_C3.2, C_C4.2, CC3.1, M1.46, M804.1, P_COM0.3, P_COM0_BIS.3, P_COM1.3, P_COM2_PI_SPI.3, P_COM3.3, P_COM4.3, P_COM5.3, U1.21, U1.34, U1.48, U2.1, U2B.2, U_Can.3]*/
	#define  P_COM4_4	(GND)		/*  [Brst.3, Brst.4, Brst.5, C1.2, C2.2, C3.2, C5.2, C6.2, C8.1, C9.1, C10.1, C11.2, C12.2, C13.2, C14.2, C15.1, C16.1, C17.2, C18.1, C19.1, C20.2, C21.2, C22.2, C23.1, C24.1, C25.1, C26.1, C28.1, C29.1, C212.1, C213.1, C840.1, C_C0b.1, C_C1.1, C_C2.1, C_C2in.1, C_C3.1, C_C4.1, C_C5.1, CC7.1, D1.1, D9.2, D10.2, M1.14, M1.43, M1.44, M1.101, M1.102, M1.206, M3.6, M3.9, M3.14, M3.20, M3.25, M3.30, M3.34, M3.39, M804.2, M_FTDI.5, M_FTDI.6, P0.1, P5VPI.1, P5VPI.3, P5VPI.5, P12V.3, P_CAN.4, P_COM0.4, P_COM0_BIS.4, P_COM1.4, P_COM2_PI_SPI.4, P_COM3.4, P_COM4.4, P_COM5.4, P_LIN.3, PI_I2C_USART.4, PI_SPI1.4, R4.2, U1.22, U1.33, U1.47, U1.54, U2.3, U2B.1, U4.3, U4B.4, U5.3, U5.6, U_Can.2, U_Lin.5]*/
	#define  P_COM4_5	(PB13)		/*  [P_COM4.5, U1.26]*/
	#define  P_COM4_6	(PB12)		/*  [P_COM4.6, U1.25]*/
	#define  P_COM4_7	(PB15)		/*  [P_COM4.7, U1.28]*/
	#define  P_COM4_8	(PB14)		/*  [P_COM4.8, U1.27]*/
	#define  P_COM4_9	(PB17)		/*  [P_COM4.9, U1.40]*/
#define  P_COM5  { P_COM5_1 , P_COM5_10 , P_COM5_2 , P_COM5_3 , P_COM5_4 , P_COM5_5 , P_COM5_6 , P_COM5_7 , P_COM5_8 , P_COM5_9 	    } 
// Connector :  P_COM5
	#define  P_COM5_1	(VDDIN)		/*  [C1.1, C11.1, C14.1, C15.2, C20.1, C21.1, C_C2in.2, D3.2, D4.2, D5.2, D7.2, M1.42, P3.2, P_COM0.1, P_COM0_BIS.1, P_COM1.1, P_COM2_PI_SPI.1, P_COM3.1, P_COM4.1, P_COM5.1, PI_I2C_USART.1, PI_SPI1.1, U2.2, U2B.3, U4.1, U4B.1, U5.1, U_Lin.7]*/
	#define  P_COM5_10	(PA27)		/*  [P_COM5.10, U1.51]*/
	#define  P_COM5_2	(VDD5V)		/*  [C2.1, C3.1, C8.2, C_C0.1, C_C0b.2, C_C1.2, C_C5.2, CC3.2, L1.2, M1.45, M1.135, M1.136, M1.202, M_FTDI.4, P_COM0.2, P_COM0_BIS.2, P_COM1.2, P_COM2_PI_SPI.2, P_COM3.2, P_COM4.2, P_COM5.2, R1.2, R6.1, U1.56, U4.2, U4B.3]*/
	#define  P_COM5_3	(VDD3V3)		/*  [C6.1, C10.2, C12.1, C13.1, C18.2, C840.2, C_C0.2, C_C2.2, C_C3.2, C_C4.2, CC3.1, M1.46, M804.1, P_COM0.3, P_COM0_BIS.3, P_COM1.3, P_COM2_PI_SPI.3, P_COM3.3, P_COM4.3, P_COM5.3, U1.21, U1.34, U1.48, U2.1, U2B.2, U_Can.3]*/
	#define  P_COM5_4	(GND)		/*  [Brst.3, Brst.4, Brst.5, C1.2, C2.2, C3.2, C5.2, C6.2, C8.1, C9.1, C10.1, C11.2, C12.2, C13.2, C14.2, C15.1, C16.1, C17.2, C18.1, C19.1, C20.2, C21.2, C22.2, C23.1, C24.1, C25.1, C26.1, C28.1, C29.1, C212.1, C213.1, C840.1, C_C0b.1, C_C1.1, C_C2.1, C_C2in.1, C_C3.1, C_C4.1, C_C5.1, CC7.1, D1.1, D9.2, D10.2, M1.14, M1.43, M1.44, M1.101, M1.102, M1.206, M3.6, M3.9, M3.14, M3.20, M3.25, M3.30, M3.34, M3.39, M804.2, M_FTDI.5, M_FTDI.6, P0.1, P5VPI.1, P5VPI.3, P5VPI.5, P12V.3, P_CAN.4, P_COM0.4, P_COM0_BIS.4, P_COM1.4, P_COM2_PI_SPI.4, P_COM3.4, P_COM4.4, P_COM5.4, P_LIN.3, PI_I2C_USART.4, PI_SPI1.4, R4.2, U1.22, U1.33, U1.47, U1.54, U2.3, U2B.1, U4.3, U4B.4, U5.3, U5.6, U_Can.2, U_Lin.5]*/
	#define  P_COM5_5	(PB31)		/*  [P_COM5.5, U1.60]*/
	#define  P_COM5_6	(PB30)		/*  [P_COM5.6, U1.59]*/
	#define  P_COM5_7	(PB23)		/*  [P_COM5.7, U1.50]*/
	#define  P_COM5_8	(PB22)		/*  [P_COM5.8, U1.49]*/
	#define  P_COM5_9	(PA28)		/*  [CC2.2, P_COM5.9, U1.53]*/
#define  P_LIN  { P_LIN_1 , P_LIN_2 , P_LIN_3 	    } 
// Connector :  P_LIN
	#define  P_LIN_1	(VS_LIN)		/*  [D3.1, D6.2, P_LIN.1]*/
	#define  P_LIN_2	(LIN)		/*  [C22.1, P_LIN.2, R5.2, U_Lin.6]*/
	#define  P_LIN_3	(GND)		/*  [Brst.3, Brst.4, Brst.5, C1.2, C2.2, C3.2, C5.2, C6.2, C8.1, C9.1, C10.1, C11.2, C12.2, C13.2, C14.2, C15.1, C16.1, C17.2, C18.1, C19.1, C20.2, C21.2, C22.2, C23.1, C24.1, C25.1, C26.1, C28.1, C29.1, C212.1, C213.1, C840.1, C_C0b.1, C_C1.1, C_C2.1, C_C2in.1, C_C3.1, C_C4.1, C_C5.1, CC7.1, D1.1, D9.2, D10.2, M1.14, M1.43, M1.44, M1.101, M1.102, M1.206, M3.6, M3.9, M3.14, M3.20, M3.25, M3.30, M3.34, M3.39, M804.2, M_FTDI.5, M_FTDI.6, P0.1, P5VPI.1, P5VPI.3, P5VPI.5, P12V.3, P_CAN.4, P_COM0.4, P_COM0_BIS.4, P_COM1.4, P_COM2_PI_SPI.4, P_COM3.4, P_COM4.4, P_COM5.4, P_LIN.3, PI_I2C_USART.4, PI_SPI1.4, R4.2, U1.22, U1.33, U1.47, U1.54, U2.3, U2B.1, U4.3, U4B.4, U5.3, U5.6, U_Can.2, U_Lin.5]*/
//MCU : 
	#define  PA00	 (U1_1)		/* .. */
	#define  U1_1	 (1)		/*  PA00 */
	#define  PB07	 (U1_10)		/* .. */
	#define  U1_10	 (10)		/*  PB07 */
	#define  PB08	 (U1_11)		/* .. */
	#define  U1_11	 (11)		/*  PB08 */
	#define  PB09	 (U1_12)		/* .. */
	#define  U1_12	 (12)		/*  PB09 */
	#define  PA04	 (U1_13)		/* .. */
	#define  U1_13	 (13)		/*  PA04 */
	#define  PA05	 (U1_14)		/* .. */
	#define  U1_14	 (14)		/*  PA05 */
	#define  PA06	 (U1_15)		/* .. */
	#define  U1_15	 (15)		/*  PA06 */
	#define  PA07	 (U1_16)		/* .. */
	#define  U1_16	 (16)		/*  PA07 */
	#define  PA08	 (U1_17)		/* .. */
	#define  U1_17	 (17)		/*  PA08 */
	#define  PA09	 (U1_18)		/* .. */
	#define  U1_18	 (18)		/*  PA09 */
	#define  PA10	 (U1_19)		/* .. */
	#define  U1_19	 (19)		/*  PA10 */
	#define  PA01	 (U1_2)		/* .. */
	#define  U1_2	 (2)		/*  PA01 */
	#define  PA11	 (U1_20)		/* .. */
	#define  U1_20	 (20)		/*  PA11 */
	#define  VDD3V3	 (U1_21)		/* .. */
	#define  U1_21	 (21)		/*  VDD3V3 */
	#define  GND	 (U1_22)		/* .. */
	#define  U1_22	 (22)		/*  GND */
	#define  PB10	 (U1_23)		/* .. */
	#define  U1_23	 (23)		/*  PB10 */
	#define  PB11	 (U1_24)		/* .. */
	#define  U1_24	 (24)		/*  PB11 */
	#define  PB12	 (U1_25)		/* .. */
	#define  U1_25	 (25)		/*  PB12 */
	#define  PB13	 (U1_26)		/* .. */
	#define  U1_26	 (26)		/*  PB13 */
	#define  PB14	 (U1_27)		/* .. */
	#define  U1_27	 (27)		/*  PB14 */
	#define  PB15	 (U1_28)		/* .. */
	#define  U1_28	 (28)		/*  PB15 */
	#define  PA12	 (U1_29)		/* .. */
	#define  U1_29	 (29)		/*  PA12 */
	#define  PA02	 (U1_3)		/* .. */
	#define  U1_3	 (3)		/*  PA02 */
	#define  PA13	 (U1_30)		/* .. */
	#define  U1_30	 (30)		/*  PA13 */
	#define  PA14	 (U1_31)		/* .. */
	#define  U1_31	 (31)		/*  PA14 */
	#define  PA15	 (U1_32)		/* .. */
	#define  U1_32	 (32)		/*  PA15 */
	#define  GND	 (U1_33)		/* .. */
	#define  U1_33	 (33)		/*  GND */
	#define  VDD3V3	 (U1_34)		/* .. */
	#define  U1_34	 (34)		/*  VDD3V3 */
	#define  PA16	 (U1_35)		/* .. */
	#define  U1_35	 (35)		/*  PA16 */
	#define  PA17	 (U1_36)		/* .. */
	#define  U1_36	 (36)		/*  PA17 */
	#define  PA18	 (U1_37)		/* .. */
	#define  U1_37	 (37)		/*  PA18 */
	#define  PA19	 (U1_38)		/* .. */
	#define  U1_38	 (38)		/*  PA19 */
	#define  PB16	 (U1_39)		/* .. */
	#define  U1_39	 (39)		/*  PB16 */
	#define  PA03	 (U1_4)		/* .. */
	#define  U1_4	 (4)		/*  PA03 */
	#define  PB17	 (U1_40)		/* .. */
	#define  U1_40	 (40)		/*  PB17 */
	#define  PA20	 (U1_41)		/* .. */
	#define  U1_41	 (41)		/*  PA20 */
	#define  PA21	 (U1_42)		/* .. */
	#define  U1_42	 (42)		/*  PA21 */
	#define  PA22	 (U1_43)		/* .. */
	#define  U1_43	 (43)		/*  PA22 */
	#define  PA23	 (U1_44)		/* .. */
	#define  U1_44	 (44)		/*  PA23 */
	#define  PA24	 (U1_45)		/* .. */
	#define  U1_45	 (45)		/*  PA24 */
	#define  PA25	 (U1_46)		/* .. */
	#define  U1_46	 (46)		/*  PA25 */
	#define  GND	 (U1_47)		/* .. */
	#define  U1_47	 (47)		/*  GND */
	#define  VDD3V3	 (U1_48)		/* .. */
	#define  U1_48	 (48)		/*  VDD3V3 */
	#define  PB22	 (U1_49)		/* .. */
	#define  U1_49	 (49)		/*  PB22 */
	#define  PB04	 (U1_5)		/* .. */
	#define  U1_5	 (5)		/*  PB04 */
	#define  PB23	 (U1_50)		/* .. */
	#define  U1_50	 (50)		/*  PB23 */
	#define  PA27	 (U1_51)		/* .. */
	#define  U1_51	 (51)		/*  PA27 */
	#define  RESET_N	 (U1_52)		/* .. */
	#define  U1_52	 (52)		/*  RESET_N */
	#define  PA28	 (U1_53)		/* .. */
	#define  U1_53	 (53)		/*  PA28 */
	#define  GND	 (U1_54)		/* .. */
	#define  U1_54	 (54)		/*  GND */
	#define  VSW	 (U1_55)		/* .. */
	#define  U1_55	 (55)		/*  VSW */
	#define  VDD5V	 (U1_56)		/* .. */
	#define  U1_56	 (56)		/*  VDD5V */
	#define  PA30	 (U1_57)		/* .. */
	#define  U1_57	 (57)		/*  PA30 */
	#define  PA31	 (U1_58)		/* .. */
	#define  U1_58	 (58)		/*  PA31 */
	#define  PB30	 (U1_59)		/* .. */
	#define  U1_59	 (59)		/*  PB30 */
	#define  PB05	 (U1_6)		/* .. */
	#define  U1_6	 (6)		/*  PB05 */
	#define  PB31	 (U1_60)		/* .. */
	#define  U1_60	 (60)		/*  PB31 */
	#define  PB00	 (U1_61)		/* .. */
	#define  U1_61	 (61)		/*  PB00 */
	#define  PB01	 (U1_62)		/* .. */
	#define  U1_62	 (62)		/*  PB01 */
	#define  PB02	 (U1_63)		/* .. */
	#define  U1_63	 (63)		/*  PB02 */
	#define  PB03	 (U1_64)		/* .. */
	#define  U1_64	 (64)		/*  PB03 */
	#define  GNDANA	 (U1_7)		/* .. */
	#define  U1_7	 (7)		/*  GNDANA */
	#define  VDDANA5V	 (U1_8)		/* .. */
	#define  U1_8	 (8)		/*  VDDANA5V */
	#define  PB06	 (U1_9)		/* .. */
	#define  U1_9	 (9)		/*  PB06 */
//undirect connection : [CANL, CANH, VS_LIN, VDDIN, VS_CAN, LIN]