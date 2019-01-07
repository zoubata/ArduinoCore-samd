#include "variant.h"


volatile           SCB_Type * MySCB=SCB;
volatile           SysTick_Type * MySysTick=SysTick;
volatile           NVIC_Type * MyNVIC=NVIC;

#if defined(ADC)
	volatile   Adc               *               MyADC               =0;    
 #endif
   

#if defined(RAMECC)
	volatile   Ramecc               *               MyRAMECC               =0;    
 #endif
   

#if defined(DIVAS)
	volatile   Divas               *               MyDIVAS               =0;    
 #endif
   

#if defined(ATW)
	volatile   Atw               *               MyATW               =0;    
 #endif
   

#if defined(LINCTRL)
	volatile   Linctrl               *               MyLINCTRL               =0;    
 #endif
   

#if defined(DSUSTANDBY)
	volatile   Dsustandby               *               MyDSUSTANDBY               =0;    
 #endif
   

#if defined(TRNG)
	volatile   Trng               *               MyTRNG               =0;    
 #endif
   

#if defined(SDHC1)
	volatile   Sdhc               *               MySDHC1               =0;    
 #endif
   
#if defined(GCLK)
	volatile   Gclk               *               MyGCLK               =0;    
 #endif
   

        
#if defined(SDHC0)
	volatile   Sdhc               *               MySDHC0               =0;    
 #endif
   

#if defined(EIC)
	volatile   Eic               *               MyEIC               =0;    
 #endif
   

#if defined(CAN1)
	volatile   Can               *               MyCAN1               =0;    
 #endif
   

#if defined(CAN0)
	volatile   Can               *               MyCAN0               =0;    
 #endif
   

#if defined(TC0)
	volatile   Tc               *               MyTC0               =0;    
 #endif
   

#if defined(AC)
	volatile   Ac               *               MyAC               =0;    
 #endif
   

#if defined(TC2)
	volatile   Tc               *               MyTC2               =0;    
 #endif
   

#if defined(TC1)
	volatile   Tc               *               MyTC1               =0;    
 #endif
   

#if defined(TC4)
	volatile   Tc               *               MyTC4               =0;    
 #endif
   

#if defined(PORT)
	volatile   Port               *               MyPORT               =0;    
 #endif
   

#if defined(TC3)
	volatile   Tc               *               MyTC3               =0;    
 #endif
   

#if defined(PAC2)
	volatile   Pac               *               MyPAC2               =0;    
 #endif
   

#if defined(HMATRIXLP)
	volatile   Hmatrixb               *               MyHMATRIXLP               =0;    
 #endif
   

#if defined(TC6)
	volatile   Tc               *               MyTC6               =0;    
 #endif
   

#if defined(WDT)
	volatile   Wdt               *               MyWDT               =0;    
 #endif
   

#if defined(DSU)
	volatile   Dsu               *               MyDSU               =0;    
 #endif
   

#if defined(TCC4)
	volatile   Tcc               *               MyTCC4               =0;    
 #endif
   

#if defined(TC5)
	volatile   Tc               *               MyTC5               =0;    
 #endif
   

#if defined(EVSYS)
	volatile   Evsys               *               MyEVSYS               =0;    
 #endif
   

#if defined(TC7)
	volatile   Tc               *               MyTC7               =0;    
 #endif
   

#if defined(SERCOM0)
	volatile   Sercom               *               MySERCOM0               =0;    
 #endif
   

#if defined(GMAC)
	volatile   Gmac               *               MyGMAC               =0;    
 #endif
   

#if defined(SYSCTRL)
	volatile   Sysctrl               *               MySYSCTRL               =0;    
 #endif
   

#if defined(TSENS)
	volatile   Tsens               *               MyTSENS               =0;    
 #endif
   

#if defined(ADC0)
	volatile   Adc               *               MyADC0               =0;    
 #endif
   

#if defined(ADC1)
	volatile   Adc               *               MyADC1               =0;    
 #endif
   

#if defined(AES)
	volatile   Aes               *               MyAES               =0;    
 #endif
   

#if defined(SERCOM7)
	volatile   Sercom               *               MySERCOM7               =0;    
 #endif
   

#if defined(MCLK)
	volatile   Mclk               *               MyMCLK               =0;    
 #endif
   

#if defined(PCC)
	volatile   Pcc               *               MyPCC               =0;    
 #endif
   

#if defined(SERCOM5)
	volatile   Sercom               *               MySERCOM5               =0;    
 #endif
   

#if defined(NVMCTRL)
	volatile   Nvmctrl               *               MyNVMCTRL               =0;    
 #endif
   

#if defined(SERCOM6)
	volatile   Sercom               *               MySERCOM6               =0;    
 #endif
   

#if defined(OZCTRL)
	volatile   Ozctrl               *               MyOZCTRL               =0;    
 #endif
   

#if defined(SERCOM3)
	volatile   Sercom               *               MySERCOM3               =0;    
 #endif
   

#if defined(OSCCTRL)
	volatile   Oscctrl               *               MyOSCCTRL               =0;    
 #endif
   
#if defined(OSC32KCTRL)
	volatile   Osc32kctrl               *               MyOSC32KCTRL               =0;    
 #endif

        
#if defined(SERCOM4)
	volatile   Sercom               *               MySERCOM4               =0;    
 #endif
   

#if defined(SERCOM1)
	volatile   Sercom               *               MySERCOM1               =0;    
 #endif
   

#if defined(PDEC)
	volatile   Pdec               *               MyPDEC               =0;    
 #endif
   

#if defined(SERCOM2)
	volatile   Sercom               *               MySERCOM2               =0;    
 #endif
   

#if defined(QSPI)
	volatile   Qspi               *               MyQSPI               =0;    
 #endif
   


#if defined(SDADC)
	volatile   Sdadc               *               MySDADC               =0;    
 #endif
   

#if defined(HMATRIXHS)
	volatile   Hmatrixb               *               MyHMATRIXHS               =0;    
 #endif
   

#if defined(RTC)
	volatile   Rtc               *               MyRTC               =0;    
 #endif
   

#if defined(PICOP)
	volatile   Picop               *               MyPICOP               =0;    
 #endif
   

#if defined(PUKCC)
	volatile   Pukcc               *               MyPUKCC               =0;    
 #endif
   

#if defined(DMAC)
	volatile   Dmac               *               MyDMAC               =0;    
 #endif
   

#if defined(AC1)
	volatile   Ac               *               MyAC1               =0;    
 #endif
   

#if defined(CMCC)
	volatile   Cmcc               *               MyCMCC               =0;    
 #endif
   

#if defined(FREQM)
	volatile   Freqm               *               MyFREQM               =0;    
 #endif
   

#if defined(RSTC)
	volatile   Rstc               *               MyRSTC               =0;    
 #endif
   

#if defined(TCC3)
	volatile   Tcc               *               MyTCC3               =0;    
 #endif
   

#if defined(TCC2)
	volatile   Tcc               *               MyTCC2               =0;    
 #endif
   

#if defined(TCC1)
	volatile   Tcc               *               MyTCC1               =0;    
 #endif
   

#if defined(PAC1)
	volatile   Pac               *               MyPAC1               =0;    
 #endif
   

#if defined(TCC0)
	volatile   Tcc               *               MyTCC0               =0;    
 #endif
   

#if defined(PAC0)
	volatile   Pac               *               MyPAC0               =0;    
 #endif
   

#if defined(SLCD)
	volatile   Slcd               *               MySLCD               =0;    
 #endif
   

#if defined(OPAMP)
	volatile   Opamp               *               MyOPAMP               =0;    
 #endif
   

#if defined(USB)
	volatile   Usb               *               MyUSB               =0;    
 #endif
   

#if defined(DAC)
	volatile   Dac               *               MyDAC               =0;    
 #endif
   

#if defined(REV_HMATRIX2)
	volatile   Hmatrix2               *               MyHMATRIX               =0;    
 
#else
#if defined(HMATRIX)
	volatile   Hmatrixb               *               MyHMATRIX               =0;    
 #endif
   #endif

#if defined(CCL)
	volatile   Ccl               *               MyCCL               =0;    
 #endif
   

#if defined(SUPC)
	volatile   Supc               *               MySUPC               =0;    
 #endif
   

#if defined(ICM)
	volatile   Icm               *               MyICM               =0;    
 #endif
   

#if defined(PAC)
	volatile   Pac               *               MyPAC               =0;    
 #endif
   

#if defined(RFCTRL)
	volatile   Rfctrl               *               MyRFCTRL               =0;    
 #endif
   

#if defined(MTB)
	volatile   Mtb               *               MyMTB               =0;    
 #endif
   



#if defined(PM)
	volatile   Pm               *               MyPM               =0;    
 #endif
   

#if defined(TAL)
	volatile   Tal               *               MyTAL               =0;    
 #endif
   

void init_debug() 
{	
#if defined(ADC)
	MyADC=ADC;
#endif

#if defined(RAMECC)
	MyRAMECC=RAMECC;
#endif

#if defined(DIVAS)
	MyDIVAS=DIVAS;
#endif

#if defined(ATW)
	MyATW=ATW;
#endif

#if defined(LINCTRL)
	MyLINCTRL=LINCTRL;
#endif

#if defined(DSUSTANDBY)
	MyDSUSTANDBY=DSUSTANDBY;
#endif

#if defined(TRNG)
	MyTRNG=TRNG;
#endif

#if defined(SDHC1)
	MySDHC1=SDHC1;
#endif

#if defined(SDHC0)
	MySDHC0=SDHC0;
#endif

#if defined(EIC)
	MyEIC=EIC;
#endif

#if defined(CAN1)
	MyCAN1=CAN1;
#endif

#if defined(CAN0)
	MyCAN0=CAN0;
#endif

#if defined(TC0)
	MyTC0=TC0;
#endif

#if defined(AC)
	MyAC=AC;
#endif

#if defined(TC2)
	MyTC2=TC2;
#endif

#if defined(TC1)
	MyTC1=TC1;
#endif

#if defined(TC4)
	MyTC4=TC4;
#endif

#if defined(PORT)
	MyPORT=PORT;
#endif

#if defined(TC3)
	MyTC3=TC3;
#endif

#if defined(PAC2)
	MyPAC2=PAC2;
#endif

#if defined(HMATRIXLP)
	MyHMATRIXLP=HMATRIXLP;
#endif

#if defined(TC6)
	MyTC6=TC6;
#endif

#if defined(WDT)
	MyWDT=WDT;
#endif

#if defined(DSU)
	MyDSU=DSU;
#endif

#if defined(TCC4)
	MyTCC4=TCC4;
#endif

#if defined(TC5)
	MyTC5=TC5;
#endif

#if defined(EVSYS)
	MyEVSYS=EVSYS;
#endif

#if defined(TC7)
	MyTC7=TC7;
#endif

#if defined(SERCOM0)
	MySERCOM0=SERCOM0;
#endif

#if defined(GMAC)
	MyGMAC=GMAC;
#endif

#if defined(SYSCTRL)
	MySYSCTRL=SYSCTRL;
#endif

#if defined(TSENS)
	MyTSENS=TSENS;
#endif

#if defined(ADC0)
	MyADC0=ADC0;
#endif

#if defined(ADC1)
	MyADC1=ADC1;
#endif

#if defined(AES)
	MyAES=AES;
#endif

#if defined(SERCOM7)
	MySERCOM7=SERCOM7;
#endif

#if defined(MCLK)
	MyMCLK=MCLK;
#endif

#if defined(PCC)
	MyPCC=PCC;
#endif

#if defined(SERCOM5)
	MySERCOM5=SERCOM5;
#endif

#if defined(NVMCTRL)
	MyNVMCTRL=NVMCTRL;
#endif

#if defined(SERCOM6)
	MySERCOM6=SERCOM6;
#endif

#if defined(OZCTRL)
	MyOZCTRL=OZCTRL;
#endif

#if defined(SERCOM3)
	MySERCOM3=SERCOM3;
#endif

#if defined(OSCCTRL)
	MyOSCCTRL=OSCCTRL;
#endif

#if defined(OSC32KCTRL)
	MyOSC32KCTRL=OSC32KCTRL;
#endif
        
#if defined(SERCOM4)
	MySERCOM4=SERCOM4;
#endif

#if defined(SERCOM1)
	MySERCOM1=SERCOM1;
#endif

#if defined(PDEC)
	MyPDEC=PDEC;
#endif

#if defined(SERCOM2)
	MySERCOM2=SERCOM2;
#endif

#if defined(QSPI)
	MyQSPI=QSPI;
#endif



#if defined(SDADC)
	MySDADC=SDADC;
#endif

#if defined(HMATRIXHS)
	MyHMATRIXHS=HMATRIXHS;
#endif

#if defined(RTC)
	MyRTC=RTC;
#endif

#if defined(PICOP)
	MyPICOP=PICOP;
#endif

#if defined(PUKCC)
	MyPUKCC=PUKCC;
#endif

#if defined(DMAC)
	MyDMAC=DMAC;
#endif

#if defined(AC1)
	MyAC1=AC1;
#endif

#if defined(CMCC)
	MyCMCC=CMCC;
#endif

#if defined(FREQM)
	MyFREQM=FREQM;
#endif

#if defined(RSTC)
	MyRSTC=RSTC;
#endif

#if defined(TCC3)
	MyTCC3=TCC3;
#endif

#if defined(TCC2)
	MyTCC2=TCC2;
#endif

#if defined(TCC1)
	MyTCC1=TCC1;
#endif

#if defined(PAC1)
	MyPAC1=PAC1;
#endif

#if defined(TCC0)
	MyTCC0=TCC0;
#endif

#if defined(PAC0)
	MyPAC0=PAC0;
#endif

#if defined(SLCD)
	MySLCD=SLCD;
#endif

#if defined(OPAMP)
	MyOPAMP=OPAMP;
#endif

#if defined(USB)
	MyUSB=USB;
#endif

#if defined(DAC)
	MyDAC=DAC;
#endif

#if defined(HMATRIX)
	MyHMATRIX=HMATRIX;
#endif

#if defined(CCL)
	MyCCL=CCL;
#endif

#if defined(SUPC)
	MySUPC=SUPC;
#endif

#if defined(ICM)
	MyICM=ICM;
#endif

#if defined(PAC)
	MyPAC=PAC;
#endif

#if defined(RFCTRL)
	MyRFCTRL=RFCTRL;
#endif

#if defined(MTB)
	MyMTB=MTB;
#endif

#if defined(GCLK)
	MyGCLK=GCLK;
#endif

#if defined(PM)
	MyPM=PM;
#endif

#if defined(TAL)
	MyTAL=TAL;
#endif

volatile int tmp= (int)   0                ;

#if defined(ADC)
	tmp= (int)         MyADC;
#endif

#if defined(RAMECC)
	tmp= (int)         MyRAMECC;
#endif

#if defined(DIVAS)
	tmp= (int)         MyDIVAS;
#endif

#if defined(ATW)
	tmp= (int)         MyATW;
#endif

#if defined(LINCTRL)
	tmp= (int)         MyLINCTRL;
#endif

#if defined(DSUSTANDBY)
	tmp= (int)         MyDSUSTANDBY;
#endif

#if defined(TRNG)
	tmp= (int)         MyTRNG;
#endif

#if defined(SDHC1)
	tmp= (int)         MySDHC1;
#endif

#if defined(SDHC0)
	tmp= (int)         MySDHC0;
#endif
#if defined(GCLK)
	tmp= (int)         MyGCLK;
#endif

#if defined(EIC)
	tmp= (int)         MyEIC;
#endif

#if defined(CAN1)
	tmp= (int)         MyCAN1;
#endif

#if defined(CAN0)
	tmp= (int)         MyCAN0;
#endif

#if defined(TC0)
	tmp= (int)         MyTC0;
#endif

#if defined(AC)
	tmp= (int)         MyAC;
#endif

#if defined(TC2)
	tmp= (int)         MyTC2;
#endif

#if defined(TC1)
	tmp= (int)         MyTC1;
#endif

#if defined(TC4)
	tmp= (int)         MyTC4;
#endif

#if defined(PORT)
	tmp= (int)         MyPORT;
#endif

#if defined(TC3)
	tmp= (int)         MyTC3;
#endif

#if defined(PAC2)
	tmp= (int)         MyPAC2;
#endif

#if defined(HMATRIXLP)
	tmp= (int)         MyHMATRIXLP;
#endif

#if defined(TC6)
	tmp= (int)         MyTC6;
#endif

#if defined(WDT)
	tmp= (int)         MyWDT;
#endif

#if defined(DSU)
	tmp= (int)         MyDSU;
#endif

#if defined(TCC4)
	tmp= (int)         MyTCC4;
#endif

#if defined(TC5)
	tmp= (int)         MyTC5;
#endif

#if defined(EVSYS)
	tmp= (int)         MyEVSYS;
#endif

#if defined(TC7)
	tmp= (int)         MyTC7;
#endif

#if defined(SERCOM0)
	tmp= (int)         MySERCOM0;
#endif

#if defined(GMAC)
	tmp= (int)         MyGMAC;
#endif

#if defined(SYSCTRL)
	tmp= (int)         MySYSCTRL;
#endif

#if defined(TSENS)
	tmp= (int)         MyTSENS;
#endif

#if defined(ADC0)
	tmp= (int)         MyADC0;
#endif

#if defined(ADC1)
	tmp= (int)         MyADC1;
#endif

#if defined(AES)
	tmp= (int)         MyAES;
#endif

#if defined(SERCOM7)
	tmp= (int)         MySERCOM7;
#endif

#if defined(MCLK)
	tmp= (int)         MyMCLK;
#endif

#if defined(PCC)
	tmp= (int)         MyPCC;
#endif

#if defined(SERCOM5)
	tmp= (int)         MySERCOM5;
#endif

#if defined(NVMCTRL)
	tmp= (int)         MyNVMCTRL;
#endif

#if defined(SERCOM6)
	tmp= (int)         MySERCOM6;
#endif

#if defined(OZCTRL)
	tmp= (int)         MyOZCTRL;
#endif

#if defined(SERCOM3)
	tmp= (int)         MySERCOM3;
#endif

#if defined(OSCCTRL)
	tmp= (int)         MyOSCCTRL;
#endif

#if defined(OSC32KCTRL)
	tmp= (int)         MyOSC32KCTRL;
#endif

#if defined(SERCOM4)
	tmp= (int)         MySERCOM4;
#endif

#if defined(SERCOM1)
	tmp= (int)         MySERCOM1;
#endif

#if defined(PDEC)
	tmp= (int)         MyPDEC;
#endif

#if defined(SERCOM2)
	tmp= (int)         MySERCOM2;
#endif

#if defined(QSPI)
	tmp= (int)         MyQSPI;
#endif


#if defined(SDADC)
	tmp= (int)         MySDADC;
#endif

#if defined(HMATRIXHS)
	tmp= (int)         MyHMATRIXHS;
#endif

#if defined(RTC)
	tmp= (int)         MyRTC;
#endif

#if defined(PICOP)
	tmp= (int)         MyPICOP;
#endif

#if defined(PUKCC)
	tmp= (int)         MyPUKCC;
#endif

#if defined(DMAC)
	tmp= (int)         MyDMAC;
#endif

#if defined(AC1)
	tmp= (int)         MyAC1;
#endif

#if defined(CMCC)
	tmp= (int)         MyCMCC;
#endif

#if defined(FREQM)
	tmp= (int)         MyFREQM;
#endif

#if defined(RSTC)
	tmp= (int)         MyRSTC;
#endif

#if defined(TCC3)
	tmp= (int)         MyTCC3;
#endif

#if defined(TCC2)
	tmp= (int)         MyTCC2;
#endif

#if defined(TCC1)
	tmp= (int)         MyTCC1;
#endif

#if defined(PAC1)
	tmp= (int)         MyPAC1;
#endif

#if defined(TCC0)
	tmp= (int)         MyTCC0;
#endif

#if defined(PAC0)
	tmp= (int)         MyPAC0;
#endif

#if defined(SLCD)
	tmp= (int)         MySLCD;
#endif

#if defined(OPAMP)
	tmp= (int)         MyOPAMP;
#endif

#if defined(USB)
	tmp= (int)         MyUSB;
#endif

#if defined(DAC)
	tmp= (int)         MyDAC;
#endif

#if defined(HMATRIX)
	tmp= (int)         MyHMATRIX;
#endif

#if defined(CCL)
	tmp= (int)         MyCCL;
#endif

#if defined(SUPC)
	tmp= (int)         MySUPC;
#endif

#if defined(ICM)
	tmp= (int)         MyICM;
#endif

#if defined(PAC)
	tmp= (int)         MyPAC;
#endif

#if defined(RFCTRL)
	tmp= (int)         MyRFCTRL;
#endif

#if defined(MTB)
	tmp= (int)         MyMTB;
#endif

#if defined(GCLK)
	tmp= (int)         MyGCLK;
#endif

#if defined(PM)
	tmp= (int)         MyPM;
#endif

#if defined(TAL)
	tmp= (int)         MyTAL;
#endif

MySCB = SCB;
	MySysTick = SysTick;
	MyNVIC = NVIC;
}

