/*
 * Autor: Asafe Silva [github.com/AsafeSilva]
 * Placa: Arduino DUE
 * Data de Criação: 20/07/2017
 * Última modificação: 20/07/2017
 * 
 * -- Descrição: --
 * Leitura de entrada digital, usando os Registradores 
 * para configurar e ler a porta.
 * 
 * -- Hardware: --
 *	Push Button: pino 3, PC28
 *	Resistor de Pull-Down
 *
 */

#define USE_REGISTERS	


#define DIGITAL_PIN 	3	
#define PIO_PORT	 	PIOC
#define PIO_MASK	 	PIO_PC28
#define PIO_BIT			28

void setup() {

	Serial.begin(9600);
	while(!Serial);

#ifdef USE_REGISTERS
	// Habilita o clock de periférico
	PMC->PMC_PCER0 = 1 << ID_PIOC;

	// Desabilita Resistor de Pull-Up interno
	PIO_PORT->PIO_PUDR = PIO_MASK;

	// Configura PC28 como entrada
	PIO_PORT->PIO_ODR = PIO_MASK;
#else
	// pinMode(DIGITAL_PIN, INPUT);

	pmc_enable_periph_clk(g_APinDescription[DIGITAL_PIN].ulPeripheralId) ;
	PIO_SetInput(PIO_PORT, PIO_MASK, 0);
#endif

}

void loop() {

#ifdef USE_REGISTERS
	Serial.println(bitRead(PIO_PORT->PIO_PDSR, PIO_BIT));
#else
	Serial.println(PIO_Get(PIO_PORT, PIO_INPUT, PIO_MASK));
#endif
	
	delay(100);

}
