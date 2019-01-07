
//list of component
//[P_0, U5, U6, P_2, U7, U8, P_1, U9, C1, C2, C3, C4, C5, C8, C9, R1, R2, R3, R4, R5, R6, C12, R7, P_com_1, P_USB1, U1, U2, U3, U4]
//list of net
//[NetC5_1, DM, VDD5V_NET, DP, PA27, PA00, PA23, PA01, VDDIN, VDD3V3_NET, PA31, GP2D_A2, PA30, GP2D_A1, GP2D_A0, SDL_E5, SDL_A1, SDL_E6, SDL_A2, SDL_E7, SDL_A3, SDL_A4, SDL_E1, SDL_E2, SDL_E3, SDL_E4, SDL_A5, GND_NET, SDL_A6, SDL_A7]
#define  P_0  { P_0_1 , P_0_2 , P_0_3 	    } 
// Connector :  P_0
	#define  P_0_1	(GP2D_A0)		/*  [P_0.1, U8.5]*/
	#define  P_0_2	(GND_NET)		/*  [C1.1, C2.2, C3.2, C4.2, C5.2, C8.2, C9.2, C12.2, P_0.2, P_1.2, P_2.2, P_com_1.4, P_USB1.4, R1.1, R2.1, R3.1, R4.1, R5.1, R6.1, R7.1, U1.2, U2.2, U3.2, U4.2, U5.2, U6.2, U7.2, U8.10, U8.28, U9.2]*/
	#define  P_0_3	(VDD5V_NET)		/*  [C1.2, C2.1, C12.1, P_0.3, P_1.3, P_2.3, P_com_1.2, P_USB1.1, U1.3, U2.3, U3.3, U4.3, U5.3, U6.3, U7.3, U9.1]*/
#define  P_1  { P_1_1 , P_1_2 , P_1_3 	    } 
// Connector :  P_1
	#define  P_1_1	(GP2D_A1)		/*  [P_1.1, U8.6]*/
	#define  P_1_2	(GND_NET)		/*  [C1.1, C2.2, C3.2, C4.2, C5.2, C8.2, C9.2, C12.2, P_0.2, P_1.2, P_2.2, P_com_1.4, P_USB1.4, R1.1, R2.1, R3.1, R4.1, R5.1, R6.1, R7.1, U1.2, U2.2, U3.2, U4.2, U5.2, U6.2, U7.2, U8.10, U8.28, U9.2]*/
	#define  P_1_3	(VDD5V_NET)		/*  [C1.2, C2.1, C12.1, P_0.3, P_1.3, P_2.3, P_com_1.2, P_USB1.1, U1.3, U2.3, U3.3, U4.3, U5.3, U6.3, U7.3, U9.1]*/
#define  P_2  { P_2_1 , P_2_2 , P_2_3 	    } 
// Connector :  P_2
	#define  P_2_1	(GP2D_A2)		/*  [P_2.1, U8.7]*/
	#define  P_2_2	(GND_NET)		/*  [C1.1, C2.2, C3.2, C4.2, C5.2, C8.2, C9.2, C12.2, P_0.2, P_1.2, P_2.2, P_com_1.4, P_USB1.4, R1.1, R2.1, R3.1, R4.1, R5.1, R6.1, R7.1, U1.2, U2.2, U3.2, U4.2, U5.2, U6.2, U7.2, U8.10, U8.28, U9.2]*/
	#define  P_2_3	(VDD5V_NET)		/*  [C1.2, C2.1, C12.1, P_0.3, P_1.3, P_2.3, P_com_1.2, P_USB1.1, U1.3, U2.3, U3.3, U4.3, U5.3, U6.3, U7.3, U9.1]*/
#define  P_USB1  { P_USB1_1 , P_USB1_2 , P_USB1_3 , P_USB1_4 	    } 
// Connector :  P_USB1
	#define  P_USB1_1	(VDD5V_NET)		/*  [C1.2, C2.1, C12.1, P_0.3, P_1.3, P_2.3, P_com_1.2, P_USB1.1, U1.3, U2.3, U3.3, U4.3, U5.3, U6.3, U7.3, U9.1]*/
	#define  P_USB1_2	(DM)		/*  [P_USB1.2, U8.23]*/
	#define  P_USB1_3	(DP)		/*  [P_USB1.3, U8.24]*/
	#define  P_USB1_4	(GND_NET)		/*  [C1.1, C2.2, C3.2, C4.2, C5.2, C8.2, C9.2, C12.2, P_0.2, P_1.2, P_2.2, P_com_1.4, P_USB1.4, R1.1, R2.1, R3.1, R4.1, R5.1, R6.1, R7.1, U1.2, U2.2, U3.2, U4.2, U5.2, U6.2, U7.2, U8.10, U8.28, U9.2]*/
#define  P_com_1  { P_com_1_1 , P_com_1_10 , P_com_1_2 , P_com_1_3 , P_com_1_4 , P_com_1_5 , P_com_1_6 , P_com_1_7 , P_com_1_8 , P_com_1_9 	    } 
// Connector :  P_com_1
	#define  P_com_1_1	(VDDIN)		/*  [P_com_1.1]*/
	#define  P_com_1_10	(PA23)		/*  [P_com_1.10, U8.22]*/
	#define  P_com_1_2	(VDD5V_NET)		/*  [C1.2, C2.1, C12.1, P_0.3, P_1.3, P_2.3, P_com_1.2, P_USB1.1, U1.3, U2.3, U3.3, U4.3, U5.3, U6.3, U7.3, U9.1]*/
	#define  P_com_1_3	(VDD3V3_NET)		/*  [C3.1, C4.1, C9.1, P_com_1.3, U8.9, U8.30, U9.3]*/
	#define  P_com_1_4	(GND_NET)		/*  [C1.1, C2.2, C3.2, C4.2, C5.2, C8.2, C9.2, C12.2, P_0.2, P_1.2, P_2.2, P_com_1.4, P_USB1.4, R1.1, R2.1, R3.1, R4.1, R5.1, R6.1, R7.1, U1.2, U2.2, U3.2, U4.2, U5.2, U6.2, U7.2, U8.10, U8.28, U9.2]*/
	#define  P_com_1_5	(PA01)		/*  [P_com_1.5, U8.2]*/
	#define  P_com_1_6	(PA00)		/*  [P_com_1.6, U8.1]*/
	#define  P_com_1_7	(PA31)		/*  [P_com_1.7, U8.32]*/
	#define  P_com_1_8	(PA30)		/*  [P_com_1.8, U8.31]*/
	#define  P_com_1_9	(PA27)		/*  [P_com_1.9, U8.25]*/
//MCU : 
	#define  PA00	 (U8_1)		/* .. */
	#define  U8_1	 (1)		/*  PA00 */
	#define  GND_NET	 (U8_10)		/* .. */
	#define  U8_10	 (10)		/*  GND_NET */
	#define  SDL_A2	 (U8_11)		/* .. */
	#define  U8_11	 (11)		/*  SDL_A2 */
	#define  SDL_A3	 (U8_12)		/* .. */
	#define  U8_12	 (12)		/*  SDL_A3 */
	#define  SDL_A4	 (U8_13)		/* .. */
	#define  U8_13	 (13)		/*  SDL_A4 */
	#define  SDL_A5	 (U8_14)		/* .. */
	#define  U8_14	 (14)		/*  SDL_A5 */
	#define  SDL_E1	 (U8_15)		/* .. */
	#define  U8_15	 (15)		/*  SDL_E1 */
	#define  SDL_E2	 (U8_16)		/* .. */
	#define  U8_16	 (16)		/*  SDL_E2 */
	#define  SDL_E3	 (U8_17)		/* .. */
	#define  U8_17	 (17)		/*  SDL_E3 */
	#define  SDL_E4	 (U8_18)		/* .. */
	#define  U8_18	 (18)		/*  SDL_E4 */
	#define  SDL_E5	 (U8_19)		/* .. */
	#define  U8_19	 (19)		/*  SDL_E5 */
	#define  PA01	 (U8_2)		/* .. */
	#define  U8_2	 (2)		/*  PA01 */
	#define  SDL_E6	 (U8_20)		/* .. */
	#define  U8_20	 (20)		/*  SDL_E6 */
	#define  SDL_E7	 (U8_21)		/* .. */
	#define  U8_21	 (21)		/*  SDL_E7 */
	#define  PA23	 (U8_22)		/* .. */
	#define  U8_22	 (22)		/*  PA23 */
	#define  DM	 (U8_23)		/* .. */
	#define  U8_23	 (23)		/*  DM */
	#define  DP	 (U8_24)		/* .. */
	#define  U8_24	 (24)		/*  DP */
	#define  PA27	 (U8_25)		/* .. */
	#define  U8_25	 (25)		/*  PA27 */
	#define  NetC5_1	 (U8_27)		/* .. */
	#define  U8_27	 (27)		/*  NetC5_1 */
//	#define  GND_NET	 (U8_28)		/* .. */
	#define  U8_28	 (28)		/*  GND_NET */
	#define  SDL_A7	 (U8_3)		/* .. */
	#define  U8_3	 (3)		/*  SDL_A7 */
	#define  VDD3V3_NET	 (U8_30)		/* .. */
	#define  U8_30	 (30)		/*  VDD3V3_NET */
	#define  PA30	 (U8_31)		/* .. */
	#define  U8_31	 (31)		/*  PA30 */
	#define  PA31	 (U8_32)		/* .. */
	#define  U8_32	 (32)		/*  PA31 */
	#define  SDL_A6	 (U8_4)		/* .. */
	#define  U8_4	 (4)		/*  SDL_A6 */
	#define  GP2D_A0	 (U8_5)		/* .. */
	#define  U8_5	 (5)		/*  GP2D_A0 */
	#define  GP2D_A1	 (U8_6)		/* .. */
	#define  U8_6	 (6)		/*  GP2D_A1 */
	#define  GP2D_A2	 (U8_7)		/* .. */
	#define  U8_7	 (7)		/*  GP2D_A2 */
	#define  SDL_A1	 (U8_8)		/* .. */
	#define  U8_8	 (8)		/*  SDL_A1 */
//	#define  VDD3V3_NET	 (U8_9)		/* .. */
	#define  U8_9	 (9)		/*  VDD3V3_NET */
//undirect connection : [VDDIN, VDD5V_NET]
