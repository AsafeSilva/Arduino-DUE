/*
 * Autor: Asafe Silva [github.com/AsafeSilva]
 * Placa: Arduino DUE
 * Data de Criação: 20/07/2017
 * Última modificação: 20/07/2017
 * 
 * -- Descrição: --
 * Leitura de entrada digital, através de Interrupção Externa
 * 
 * -- Hardware: --
 *	Push Button: pino 53, PB14
 *	Resistor de Pull-Down
 *
 */

// #define USE_REGISTERS	


// #define DIGITAL_PIN 	53	
// #define PIO_PORT	 	PIOB
// #define PIO_MASK	 	PIO_PB14
// #define PIO_BIT			14


// // #define CHANGE_MODE
// // #define LOW_MODE
// // #define HIGH_MODE
// // #define FALLING_MODE
// #define RISING_MODE

// void setup() {

// 	Serial.begin(9600);
// 	while(!Serial);


// #ifdef USE_REGISTERS

// 	// Habilita o clock de periférico
// 	PMC->PMC_PCER0 = 1 << ID_PIOC;

// 	// Desabilita Resistor de Pull-Up interno
// 	PIO_PORT->PIO_PUDR = PIO_MASK;

// 	// Configura PB14 como entrada
// 	PIO_PORT->PIO_ODR = PIO_MASK;

// 	// Configura modo da Interrupção
// #ifdef CHANGE_MODE
// 	// Desabilita modo de interrupção adicional
// 	PIO_PORT->PIO_AIMDR = PIO_MASK;				// Detecta qualquer mudança de nível
// #else
// 	// Habilita modo de interrupção adicional
// 	PIO_PORT->PIO_AIMER = PIO_MASK;

// 	#ifdef LOW_MODE

// 		PIO_PORT->PIO_LSR = PIO_MASK;			// Detecção de Nível		
// 		PIO_PORT->PIO_FELLSR = PIO_MASK;		// Low Level

// 	#elif defined HIGH_MODE

// 		PIO_PORT->PIO_LSR = PIO_MASK;			// Detecção de Nível
// 		PIO_PORT->PIO_REHLSR = PIO_MASK;		// High Level

// 	#elif defined FALLING_MODE

// 		PIO_PORT->PIO_ESR = PIO_MASK;			// Detecção de Borda
// 		PIO_PORT->PIO_FELLSR = PIO_MASK;		// Falling Edge

// 	#elif defined RISING_MODE

// 		PIO_PORT->PIO_ESR = PIO_MASK;			// Detecção de Borda
// 		PIO_PORT->PIO_REHLSR = PIO_MASK;		// Rising Edge

// 	#endif
// #endif

// 	NVIC_DisableIRQ(PIOB_IRQn);
// 	NVIC_ClearPendingIRQ(PIOB_IRQn);
// 	NVIC_SetPriority(PIOB_IRQn, 0);
// 	NVIC_EnableIRQ(PIOB_IRQn);

// 	// Habilita interrupção no PB14
// 	PIO_PORT->PIO_IER = PIO_MASK;

// #else
// 	// pinMode(DIGITAL_PIN, INPUT);
// 	// attachInterrupt(DIGITAL_PIN, Handler, RISING);

// 	// pmc_enable_periph_clk(g_APinDescription[DIGITAL_PIN].ulPeripheralId) ;
// 	// PIO_SetInput(PIO_PORT, PIO_MASK, 0);
// #endif

// }

// void loop() {
// 	delay(1000);
// }

// #ifdef USE_REGISTERS
// // void PIOB_Handler(){
// // 	if(bitRead(PIOB->PIO_ISR, PIO_BIT)){

// // 	}
// // }
// #else
// void Handler(void){

// }
// #endif
