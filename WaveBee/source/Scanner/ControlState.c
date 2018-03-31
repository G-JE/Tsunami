/*
 * ButtonState.c
 *
 *  Created on: Mar 3, 2018
 *      Author: ericksong
 */

#include <Scanner/ControlState.h>


StateInstance State = {
		0,
		0,
		4
};

AnalogInputs inputs;

bool record = false;
bool  A_HIGH = false;
bool  B_HIGH = false;
bool encoderOpen = false;
adc16_channel_config_t adc16ChannelConfig;

void InitControls(void){
	adc16_config_t adc16Config;

	// initialize all of the ADC pins
	ADC16_GetDefaultConfig(&adc16Config);
	ADC16_Init(ADC_BASE1, &adc16Config);
	ADC16_Init(ADC_BASE0, &adc16Config);

	adc16ChannelConfig.channelNumber = POSITION_SLIDER_CHANNEL;
	adc16ChannelConfig.enableInterruptOnConversionCompleted = false;

	ADC16_SetChannelConfig(ADC_BASE1, SLIDER_GROUP, &adc16ChannelConfig);

	adc16ChannelConfig.channelNumber = LENGTH_SLIDER_CHANNEL;
	ADC16_SetChannelConfig(ADC_BASE1, SLIDER_GROUP, &adc16ChannelConfig);

	adc16ChannelConfig.channelNumber = ATTACK_SLIDER_CHANNEL;
	ADC16_SetChannelConfig(ADC_BASE1, SLIDER_GROUP, &adc16ChannelConfig);

	adc16ChannelConfig.channelNumber = DECAY_SLIDER_CHANNEL;
	ADC16_SetChannelConfig(ADC_BASE1, SLIDER_GROUP, &adc16ChannelConfig);

	adc16ChannelConfig.channelNumber = SUSTAIN_SLIDER_CHANNEL;
	ADC16_SetChannelConfig(ADC_BASE0, SLIDER_GROUP, &adc16ChannelConfig);

	adc16ChannelConfig.channelNumber = RELEASE_SLIDER_CHANNEL;
	ADC16_SetChannelConfig(ADC_BASE0, SLIDER_GROUP, &adc16ChannelConfig);

	port_pin_config_t buttonConfig = {
			/* Internal pull-up resistor is enabled */
			kPORT_PullUp,
			/* Fast slew rate is configured */
			kPORT_FastSlewRate,
			/* Passive filter is disabled */
			kPORT_PassiveFilterEnable,
			/* Open drain is disabled */
			kPORT_OpenDrainDisable,
			/* Low drive strength is configured */
			kPORT_LowDriveStrength,
			/* Pin is configured as PTA10 */
			kPORT_MuxAsGpio,
			/* Pin Control Register fields [15:0] are not locked */
			kPORT_UnlockRegister
	};
	port_pin_config_t encoderConfig = {
		/* Internal pull-up resistor is enabled */
		kPORT_PullUp,
		/* Fast slew rate is configured */
		kPORT_FastSlewRate,
		/* Passive filter is disabled */
		kPORT_PassiveFilterDisable,
		/* Open drain is disabled */
		kPORT_OpenDrainDisable,
		/* Low drive strength is configured */
		kPORT_LowDriveStrength,
		/* Pin is configured as PTA10 */
		kPORT_MuxAsGpio,
		/* Pin Control Register fields [15:0] are not locked */
		kPORT_UnlockRegister
};
	gpio_pin_config_t inputConfig = {kGPIO_DigitalInput, 0u};

	PORT_SetPinConfig(RECORD_BUTTON_PORT, RECORD_BUTTON_PIN, &buttonConfig);
	PORT_SetPinInterruptConfig(RECORD_BUTTON_PORT, RECORD_BUTTON_PIN, kPORT_InterruptEitherEdge);
	GPIO_PinInit(RECORD_BUTTON_GPIO, RECORD_BUTTON_PIN, &inputConfig);

	PORT_SetPinConfig(ENCODER_PORTA, ENCODER_PINA, &encoderConfig);
	PORT_SetPinConfig(ENCODER_PORTB, ENCODER_PINB, &encoderConfig);
	PORT_SetPinInterruptConfig(ENCODER_PORTA, ENCODER_PINA, kPORT_InterruptRisingEdge);
	PORT_SetPinInterruptConfig(ENCODER_PORTB, ENCODER_PINB, kPORT_InterruptRisingEdge);
	EnableIRQ(RECORD_IRQ);
	EnableIRQ(ENCODER_IRQ);
	EnableIRQ(ENCODER_IRQ2);
	GPIO_PinInit(ENCODER_GPIOA,ENCODER_PINA, &inputConfig);
    GPIO_PinInit(ENCODER_GPIOB,ENCODER_PINB, &inputConfig);
}

StateInstance GetControlState(void){
	return State;
}

void UpdateControlState(uint8_t value){
	State.state = value;
}

// expand this for reading ADC values from all sliders
void UpdateADCValues(void){

	int temp = 0;
	uint16_t conversion = 0;
	uint16_t delay = 1000;

	adc16ChannelConfig.channelNumber = POSITION_SLIDER_CHANNEL;
	ADC16_SetChannelConfig(ADC_BASE1, SLIDER_GROUP, &adc16ChannelConfig);
	while(delay--);
	conversion =  ADC16_GetChannelConversionValue(ADC_BASE1, SLIDER_GROUP);
	temp = ((double) conversion / 4096.0) * 100;

	if(temp != inputs.startPosition){
		inputs.startPosition = temp;
		State.state = UPDATE_INDEXES;
	}

	delay = 1000;
	adc16ChannelConfig.channelNumber = LENGTH_SLIDER_CHANNEL;
	ADC16_SetChannelConfig(ADC_BASE1, SLIDER_GROUP, &adc16ChannelConfig);
	while(delay--);
	conversion =  ADC16_GetChannelConversionValue(ADC_BASE1, SLIDER_GROUP);
	temp = ((double) conversion / 4096.0) * 100;

	if(temp != inputs.length){
		inputs.length = temp;
		State.state = UPDATE_INDEXES;
	}
	// use these when the envelope is rolled in
//	adc16ChannelConfig.channelNumber = ATTACK_SLIDER_CHANNEL;
//	ADC16_SetChannelConfig(ADC_BASE1, SLIDER_GROUP, &adc16ChannelConfig);
//
//	adc16ChannelConfig.channelNumber = DECAY_SLIDER_CHANNEL;
//	ADC16_SetChannelConfig(ADC_BASE1, SLIDER_GROUP, &adc16ChannelConfig);
//
//	adc16ChannelConfig.channelNumber = SUSTAIN_SLIDER_CHANNEL;
//	ADC16_SetChannelConfig(ADC_BASE0, SLIDER_GROUP, &adc16ChannelConfig);
//
//	adc16ChannelConfig.channelNumber = RELEASE_SLIDER_CHANNEL;
//	ADC16_SetChannelConfig(ADC_BASE0, SLIDER_GROUP, &adc16ChannelConfig);

	// do something with this value to update parameters

}
float GetPosition(void){
	return inputs.startPosition;
}

float GetLength(void){
	return inputs.length;
}

void RECORD_HANDLER(void){

	uint32_t flags = GPIO_PortGetInterruptFlags(RECORD_BUTTON_GPIO);
	GPIO_PortClearInterruptFlags(RECORD_BUTTON_GPIO, RECORD_MASK);
		//Trigger the recording to start and end based on rising or falling edge
		if(flags & (1u << RECORD_BUTTON_PIN)){
			if(!record){
				record = true;
				State.state = RECORDING;
			}
			else{
				record = false;
				State.state = NOP;
				EndRecording();
			}
		}
	// this is needed for M4 ARM arch
	__DSB();
}

void ENCODER_HANDLER(void){

	uint32_t flags = GPIO_PortGetInterruptFlags(ENCODER_GPIOA);
	GPIO_PortClearInterruptFlags(ENCODER_GPIOA,  (1u << ENCODER_PINA));
	if(flags & (1u << ENCODER_PINA))
		B_HIGH = GPIO_PinRead(ENCODER_GPIOB, ENCODER_PINB);

	if(!B_HIGH){
		State.state = ENCODER_CW;
		B_HIGH = true;
	}

}

void ENCODER_HANDLER2(void){

	uint32_t flags = GPIO_PortGetInterruptFlags(ENCODER_GPIOB);
	GPIO_PortClearInterruptFlags(ENCODER_GPIOB, (1u << ENCODER_PINB));

	if(flags & (1u << ENCODER_PINB))
		A_HIGH = GPIO_PinRead(ENCODER_GPIOA, ENCODER_PINA);

	//this part uses variable 1U based off of example code probably should be changed to suit this application
	if(!A_HIGH){
		State.state = ENCODER_CCW;
		A_HIGH = true;
	}

}
