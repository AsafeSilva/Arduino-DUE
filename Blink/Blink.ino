/*
 * Autor: Asafe Silva [github.com/AsafeSilva]
 * Placa: Arduino DUE
 * Data de Criação: 20/07/2017
 * Última modificação: 20/07/2017
 * 
 * -- Descrição: --
 * Oscilador simples com delay, usando os Registradores 
 * para configurar e (re)setar as portas.
 * 
 * -- Hardware: --
 *	LED onBoard: pino 13, PB27
 */
	

#define USE_REGISTERS

#define DIGITAL_PIN  	13	
#define PIO_PORT	 	PIOB
#define PIO_MASK	 	PIO_PB27			

void setup() {

#ifdef USE_REGISTERS
	// Inicia PB27 em HIGH
	PIO_PORT->PIO_SODR = PIO_MASK;

	// Configura PB27 como saída
	PIO_PORT->PIO_OER = PIO_MASK;
#else
	pinMode(DIGITAL_PIN, OUTPUT);
#endif	
}

void loop() {
#ifdef USE_REGISTERS
	// PB27 em HIGH
	PIO_PORT->PIO_SODR = PIO_MASK;
	delay(1000);

	// PB27 em LOW
	PIO_PORT->PIO_CODR = PIO_MASK;
	delay(1000);
#else
	// PB27 em HIGH
	PIO_Set(PIO_PORT, PIO_MASK);
	delay(1000);

	// PB27 em LOW
	PIO_Clear(PIO_PORT, PIO_MASK);
	delay(1000);
#endif		

}
