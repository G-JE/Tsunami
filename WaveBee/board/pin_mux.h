/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/

/*! @brief Direction type  */
typedef enum _pin_mux_direction
{
    kPIN_MUX_DirectionInput = 0U,        /* Input direction */
    kPIN_MUX_DirectionOutput = 1U,       /* Output direction */
    kPIN_MUX_DirectionInputOrOutput = 2U /* Input or output direction */
} pin_mux_direction_t;

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

#define SOPT5_UART0TXSRC_UART_TX 0x00u /*!<@brief UART 0 transmit data source select: UART0_TX pin */

/*! @name PORTC1 (coord B11), J1[5]/U20[C5]/I2S_TXD
  @{ */
#define BOARD_INITPINS_I2S_TXD_PERIPHERAL I2S0               /*!<@brief Device name: I2S0 */
#define BOARD_INITPINS_I2S_TXD_SIGNAL TXD0                   /*!<@brief I2S0 signal: TXD0 */
#define BOARD_INITPINS_I2S_TXD_PORT PORTC                    /*!<@brief PORT device name: PORTC */
#define BOARD_INITPINS_I2S_TXD_PIN 1U                        /*!<@brief PORTC pin index: 1 */
#define BOARD_INITPINS_I2S_TXD_PIN_NAME I2S0_TXD0            /*!<@brief Pin name */
#define BOARD_INITPINS_I2S_TXD_LABEL "J1[5]/U20[C5]/I2S_TXD" /*!<@brief Label */
#define BOARD_INITPINS_I2S_TXD_NAME "I2S_TXD"                /*!<@brief Identifier name */
                                                             /* @} */

/*! @name PORTC6 (coord C8), J1[9]/LLWU_P10/FB_AD9/I2S0_MCLK
  @{ */
#define BOARD_INITPINS_I2S_MCLK_PERIPHERAL I2S0                         /*!<@brief Device name: I2S0 */
#define BOARD_INITPINS_I2S_MCLK_SIGNAL MCLK                             /*!<@brief I2S0 signal: MCLK */
#define BOARD_INITPINS_I2S_MCLK_PORT PORTC                              /*!<@brief PORT device name: PORTC */
#define BOARD_INITPINS_I2S_MCLK_PIN 6U                                  /*!<@brief PORTC pin index: 6 */
#define BOARD_INITPINS_I2S_MCLK_PIN_NAME I2S0_MCLK                      /*!<@brief Pin name */
#define BOARD_INITPINS_I2S_MCLK_LABEL "J1[9]/LLWU_P10/FB_AD9/I2S0_MCLK" /*!<@brief Label */
#define BOARD_INITPINS_I2S_MCLK_NAME "I2S_MCLK"                         /*!<@brief Identifier name */
                                                                        /* @} */

/*! @name PORTC10 (coord C7), J2[20]/U20[D8]/I2C1_SCL/DA7212_CLK
  @{ */
#define BOARD_INITPINS_I2C1_SCL_PERIPHERAL I2C1                            /*!<@brief Device name: I2C1 */
#define BOARD_INITPINS_I2C1_SCL_SIGNAL SCL                                 /*!<@brief I2C1 signal: SCL */
#define BOARD_INITPINS_I2C1_SCL_PORT PORTC                                 /*!<@brief PORT device name: PORTC */
#define BOARD_INITPINS_I2C1_SCL_PIN 10U                                    /*!<@brief PORTC pin index: 10 */
#define BOARD_INITPINS_I2C1_SCL_PIN_NAME I2C1_SCL                          /*!<@brief Pin name */
#define BOARD_INITPINS_I2C1_SCL_LABEL "J2[20]/U20[D8]/I2C1_SCL/DA7212_CLK" /*!<@brief Label */
#define BOARD_INITPINS_I2C1_SCL_NAME "I2C1_SCL"                            /*!<@brief Identifier name */
                                                                           /* @} */

/*! @name PORTC11 (coord B7), J2[18]/U20[C9]/I2C1_SDA/DA7212_SDA
  @{ */
#define BOARD_INITPINS_I2C1_SDA_PERIPHERAL I2C1                            /*!<@brief Device name: I2C1 */
#define BOARD_INITPINS_I2C1_SDA_SIGNAL SDA                                 /*!<@brief I2C1 signal: SDA */
#define BOARD_INITPINS_I2C1_SDA_PORT PORTC                                 /*!<@brief PORT device name: PORTC */
#define BOARD_INITPINS_I2C1_SDA_PIN 11U                                    /*!<@brief PORTC pin index: 11 */
#define BOARD_INITPINS_I2C1_SDA_PIN_NAME I2C1_SDA                          /*!<@brief Pin name */
#define BOARD_INITPINS_I2C1_SDA_LABEL "J2[18]/U20[C9]/I2C1_SDA/DA7212_SDA" /*!<@brief Label */
#define BOARD_INITPINS_I2C1_SDA_NAME "I2C1_SDA"                            /*!<@brief Identifier name */
                                                                           /* @} */

/*! @name PORTE12 (coord G3), J1[1]/J37[3]/I2S_TX_BCLK
  @{ */
#define BOARD_INITPINS_I2S_TX_BCLK_PERIPHERAL I2S0                  /*!<@brief Device name: I2S0 */
#define BOARD_INITPINS_I2S_TX_BCLK_SIGNAL TX_BCLK                   /*!<@brief I2S0 signal: TX_BCLK */
#define BOARD_INITPINS_I2S_TX_BCLK_PORT PORTE                       /*!<@brief PORT device name: PORTE */
#define BOARD_INITPINS_I2S_TX_BCLK_PIN 12U                          /*!<@brief PORTE pin index: 12 */
#define BOARD_INITPINS_I2S_TX_BCLK_PIN_NAME I2S0_TX_BCLK            /*!<@brief Pin name */
#define BOARD_INITPINS_I2S_TX_BCLK_LABEL "J1[1]/J37[3]/I2S_TX_BCLK" /*!<@brief Label */
#define BOARD_INITPINS_I2S_TX_BCLK_NAME "I2S_TX_BCLK"               /*!<@brief Identifier name */
                                                                    /* @} */

/*! @name PORTE11 (coord G4), J1[3]/J38[3]/I2S_TX_WCLK
  @{ */
#define BOARD_INITPINS_I2S_TX_WCLK_PERIPHERAL I2S0                  /*!<@brief Device name: I2S0 */
#define BOARD_INITPINS_I2S_TX_WCLK_SIGNAL TX_FS                     /*!<@brief I2S0 signal: TX_FS */
#define BOARD_INITPINS_I2S_TX_WCLK_PORT PORTE                       /*!<@brief PORT device name: PORTE */
#define BOARD_INITPINS_I2S_TX_WCLK_PIN 11U                          /*!<@brief PORTE pin index: 11 */
#define BOARD_INITPINS_I2S_TX_WCLK_PIN_NAME I2S0_TX_FS              /*!<@brief Pin name */
#define BOARD_INITPINS_I2S_TX_WCLK_LABEL "J1[3]/J38[3]/I2S_TX_WCLK" /*!<@brief Label */
#define BOARD_INITPINS_I2S_TX_WCLK_NAME "I2S_TX_WCLK"               /*!<@brief Identifier name */
                                                                    /* @} */

/*! @name PORTB16 (coord E10), U7[4]/UART0_RX
  @{ */
#define BOARD_INITPINS_DEBUG_UART_RX_PERIPHERAL UART0       /*!<@brief Device name: UART0 */
#define BOARD_INITPINS_DEBUG_UART_RX_SIGNAL RX              /*!<@brief UART0 signal: RX */
#define BOARD_INITPINS_DEBUG_UART_RX_PORT PORTB             /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_DEBUG_UART_RX_PIN 16U                /*!<@brief PORTB pin index: 16 */
#define BOARD_INITPINS_DEBUG_UART_RX_PIN_NAME UART0_RX      /*!<@brief Pin name */
#define BOARD_INITPINS_DEBUG_UART_RX_LABEL "U7[4]/UART0_RX" /*!<@brief Label */
#define BOARD_INITPINS_DEBUG_UART_RX_NAME "DEBUG_UART_RX"   /*!<@brief Identifier name */
                                                            /* @} */

/*! @name PORTB17 (coord E9), U10[1]/UART0_TX
  @{ */
#define BOARD_INITPINS_DEBUG_UART_TX_PERIPHERAL UART0        /*!<@brief Device name: UART0 */
#define BOARD_INITPINS_DEBUG_UART_TX_SIGNAL TX               /*!<@brief UART0 signal: TX */
#define BOARD_INITPINS_DEBUG_UART_TX_PORT PORTB              /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_DEBUG_UART_TX_PIN 17U                 /*!<@brief PORTB pin index: 17 */
#define BOARD_INITPINS_DEBUG_UART_TX_PIN_NAME UART0_TX       /*!<@brief Pin name */
#define BOARD_INITPINS_DEBUG_UART_TX_LABEL "U10[1]/UART0_TX" /*!<@brief Label */
#define BOARD_INITPINS_DEBUG_UART_TX_NAME "DEBUG_UART_TX"    /*!<@brief Identifier name */
                                                             /* @} */

/*! @name PORTE7 (coord F4), J1[15]/J34[1]/U20[C7]/I2S_RXD0
  @{ */
#define BOARD_INITPINS_I2S_RXD0_PERIPHERAL I2S0                        /*!<@brief Device name: I2S0 */
#define BOARD_INITPINS_I2S_RXD0_SIGNAL RXD0                            /*!<@brief I2S0 signal: RXD0 */
#define BOARD_INITPINS_I2S_RXD0_PORT PORTE                             /*!<@brief PORT device name: PORTE */
#define BOARD_INITPINS_I2S_RXD0_PIN 7U                                 /*!<@brief PORTE pin index: 7 */
#define BOARD_INITPINS_I2S_RXD0_PIN_NAME I2S0_RXD0                     /*!<@brief Pin name */
#define BOARD_INITPINS_I2S_RXD0_LABEL "J1[15]/J34[1]/U20[C7]/I2S_RXD0" /*!<@brief Label */
#define BOARD_INITPINS_I2S_RXD0_NAME "I2S_RXD0"                        /*!<@brief Identifier name */
                                                                       /* @} */

/*! @name PORTE0 (coord D3), SDHC0_D1
  @{ */
#define BOARD_INITPINS_SDHC0_D1_PERIPHERAL SDHC   /*!<@brief Device name: SDHC */
#define BOARD_INITPINS_SDHC0_D1_SIGNAL DATA       /*!<@brief SDHC signal: DATA */
#define BOARD_INITPINS_SDHC0_D1_PORT PORTE        /*!<@brief PORT device name: PORTE */
#define BOARD_INITPINS_SDHC0_D1_PIN 0U            /*!<@brief PORTE pin index: 0 */
#define BOARD_INITPINS_SDHC0_D1_CHANNEL 1         /*!<@brief SDHC DATA channel: 1 */
#define BOARD_INITPINS_SDHC0_D1_PIN_NAME SDHC0_D1 /*!<@brief Pin name */
#define BOARD_INITPINS_SDHC0_D1_LABEL "SDHC0_D1"  /*!<@brief Label */
#define BOARD_INITPINS_SDHC0_D1_NAME "SDHC0_D1"   /*!<@brief Identifier name */
                                                  /* @} */

/*! @name PORTE1 (coord D2), SDHC0_D0
  @{ */
#define BOARD_INITPINS_SDHC0_D0_PERIPHERAL SDHC   /*!<@brief Device name: SDHC */
#define BOARD_INITPINS_SDHC0_D0_SIGNAL DATA       /*!<@brief SDHC signal: DATA */
#define BOARD_INITPINS_SDHC0_D0_PORT PORTE        /*!<@brief PORT device name: PORTE */
#define BOARD_INITPINS_SDHC0_D0_PIN 1U            /*!<@brief PORTE pin index: 1 */
#define BOARD_INITPINS_SDHC0_D0_CHANNEL 0         /*!<@brief SDHC DATA channel: 0 */
#define BOARD_INITPINS_SDHC0_D0_PIN_NAME SDHC0_D0 /*!<@brief Pin name */
#define BOARD_INITPINS_SDHC0_D0_LABEL "SDHC0_D0"  /*!<@brief Label */
#define BOARD_INITPINS_SDHC0_D0_NAME "SDHC0_D0"   /*!<@brief Identifier name */
                                                  /* @} */

/*! @name PORTE2 (coord D1), SDHC0_DCLK
  @{ */
#define BOARD_INITPINS_SDHC0_DCLK_PERIPHERAL SDHC     /*!<@brief Device name: SDHC */
#define BOARD_INITPINS_SDHC0_DCLK_SIGNAL DCLK         /*!<@brief SDHC signal: DCLK */
#define BOARD_INITPINS_SDHC0_DCLK_PORT PORTE          /*!<@brief PORT device name: PORTE */
#define BOARD_INITPINS_SDHC0_DCLK_PIN 2U              /*!<@brief PORTE pin index: 2 */
#define BOARD_INITPINS_SDHC0_DCLK_PIN_NAME SDHC0_DCLK /*!<@brief Pin name */
#define BOARD_INITPINS_SDHC0_DCLK_LABEL "SDHC0_DCLK"  /*!<@brief Label */
#define BOARD_INITPINS_SDHC0_DCLK_NAME "SDHC0_DCLK"   /*!<@brief Identifier name */
                                                      /* @} */

/*! @name PORTE3 (coord E4), SDHC0_CMD
  @{ */
#define BOARD_INITPINS_SDHC0_CMD_PERIPHERAL SDHC    /*!<@brief Device name: SDHC */
#define BOARD_INITPINS_SDHC0_CMD_SIGNAL CMD         /*!<@brief SDHC signal: CMD */
#define BOARD_INITPINS_SDHC0_CMD_PORT PORTE         /*!<@brief PORT device name: PORTE */
#define BOARD_INITPINS_SDHC0_CMD_PIN 3U             /*!<@brief PORTE pin index: 3 */
#define BOARD_INITPINS_SDHC0_CMD_PIN_NAME SDHC0_CMD /*!<@brief Pin name */
#define BOARD_INITPINS_SDHC0_CMD_LABEL "SDHC0_CMD"  /*!<@brief Label */
#define BOARD_INITPINS_SDHC0_CMD_NAME "SDHC0_CMD"   /*!<@brief Identifier name */
                                                    /* @} */

/*! @name PORTE4 (coord E3), SDHC0_D3
  @{ */
#define BOARD_INITPINS_SDHC0_D3_PERIPHERAL SDHC   /*!<@brief Device name: SDHC */
#define BOARD_INITPINS_SDHC0_D3_SIGNAL DATA       /*!<@brief SDHC signal: DATA */
#define BOARD_INITPINS_SDHC0_D3_PORT PORTE        /*!<@brief PORT device name: PORTE */
#define BOARD_INITPINS_SDHC0_D3_PIN 4U            /*!<@brief PORTE pin index: 4 */
#define BOARD_INITPINS_SDHC0_D3_CHANNEL 3         /*!<@brief SDHC DATA channel: 3 */
#define BOARD_INITPINS_SDHC0_D3_PIN_NAME SDHC0_D3 /*!<@brief Pin name */
#define BOARD_INITPINS_SDHC0_D3_LABEL "SDHC0_D3"  /*!<@brief Label */
#define BOARD_INITPINS_SDHC0_D3_NAME "SDHC0_D3"   /*!<@brief Identifier name */
                                                  /* @} */

/*! @name PORTE5 (coord E2), SDHC0_D2
  @{ */
#define BOARD_INITPINS_SDHC0_D2_PERIPHERAL SDHC   /*!<@brief Device name: SDHC */
#define BOARD_INITPINS_SDHC0_D2_SIGNAL DATA       /*!<@brief SDHC signal: DATA */
#define BOARD_INITPINS_SDHC0_D2_PORT PORTE        /*!<@brief PORT device name: PORTE */
#define BOARD_INITPINS_SDHC0_D2_PIN 5U            /*!<@brief PORTE pin index: 5 */
#define BOARD_INITPINS_SDHC0_D2_CHANNEL 2         /*!<@brief SDHC DATA channel: 2 */
#define BOARD_INITPINS_SDHC0_D2_PIN_NAME SDHC0_D2 /*!<@brief Pin name */
#define BOARD_INITPINS_SDHC0_D2_LABEL "SDHC0_D2"  /*!<@brief Label */
#define BOARD_INITPINS_SDHC0_D2_NAME "SDHC0_D2"   /*!<@brief Identifier name */
                                                  /* @} */

/*! @name PORTD10 (coord B3), SD_CARD_DETECT
  @{ */
#define BOARD_INITPINS_SDCARD_CARD_DETECTION_PERIPHERAL GPIOD             /*!<@brief Device name: GPIOD */
#define BOARD_INITPINS_SDCARD_CARD_DETECTION_SIGNAL GPIO                  /*!<@brief GPIOD signal: GPIO */
#define BOARD_INITPINS_SDCARD_CARD_DETECTION_GPIO GPIOD                   /*!<@brief GPIO device name: GPIOD */
#define BOARD_INITPINS_SDCARD_CARD_DETECTION_GPIO_PIN 10U                 /*!<@brief PORTD pin index: 10 */
#define BOARD_INITPINS_SDCARD_CARD_DETECTION_PORT PORTD                   /*!<@brief PORT device name: PORTD */
#define BOARD_INITPINS_SDCARD_CARD_DETECTION_PIN 10U                      /*!<@brief PORTD pin index: 10 */
#define BOARD_INITPINS_SDCARD_CARD_DETECTION_CHANNEL 10                   /*!<@brief GPIOD GPIO channel: 10 */
#define BOARD_INITPINS_SDCARD_CARD_DETECTION_PIN_NAME PTD10               /*!<@brief Pin name */
#define BOARD_INITPINS_SDCARD_CARD_DETECTION_LABEL "SD_CARD_DETECT"       /*!<@brief Label */
#define BOARD_INITPINS_SDCARD_CARD_DETECTION_NAME "SDCARD_CARD_DETECTION" /*!<@brief Identifier name */
                                                                          /* @} */

/*! @name PORTB2 (coord G12), J4[12]/ADC0_SE12/I2C0_SCL
  @{ */
#define BOARD_INITPINS_ADC0_SE12_PERIPHERAL ADC0                   /*!<@brief Device name: ADC0 */
#define BOARD_INITPINS_ADC0_SE12_SIGNAL SE                         /*!<@brief ADC0 signal: SE */
#define BOARD_INITPINS_ADC0_SE12_PORT PORTB                        /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_ADC0_SE12_PIN 2U                            /*!<@brief PORTB pin index: 2 */
#define BOARD_INITPINS_ADC0_SE12_CHANNEL 12                        /*!<@brief ADC0 SE channel: 12 */
#define BOARD_INITPINS_ADC0_SE12_PIN_NAME ADC0_SE12                /*!<@brief Pin name */
#define BOARD_INITPINS_ADC0_SE12_LABEL "J4[12]/ADC0_SE12/I2C0_SCL" /*!<@brief Label */
#define BOARD_INITPINS_ADC0_SE12_NAME "ADC0_SE12"                  /*!<@brief Identifier name */
                                                                   /* @} */

/*! @name PORTB3 (coord G11), J4[10]/ADC0_SE13/I2C0_SDA
  @{ */
#define BOARD_INITPINS_ADC0_SE13_PERIPHERAL ADC0                   /*!<@brief Device name: ADC0 */
#define BOARD_INITPINS_ADC0_SE13_SIGNAL SE                         /*!<@brief ADC0 signal: SE */
#define BOARD_INITPINS_ADC0_SE13_PORT PORTB                        /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_ADC0_SE13_PIN 3U                            /*!<@brief PORTB pin index: 3 */
#define BOARD_INITPINS_ADC0_SE13_CHANNEL 13                        /*!<@brief ADC0 SE channel: 13 */
#define BOARD_INITPINS_ADC0_SE13_PIN_NAME ADC0_SE13                /*!<@brief Pin name */
#define BOARD_INITPINS_ADC0_SE13_LABEL "J4[10]/ADC0_SE13/I2C0_SDA" /*!<@brief Label */
#define BOARD_INITPINS_ADC0_SE13_NAME "ADC0_SE13"                  /*!<@brief Identifier name */
                                                                   /* @} */

/*! @name PORTB4 (coord G10), J4[8]/ADC1_SE10
  @{ */
#define BOARD_INITPINS_ADC1_SE10_PERIPHERAL ADC1         /*!<@brief Device name: ADC1 */
#define BOARD_INITPINS_ADC1_SE10_SIGNAL SE               /*!<@brief ADC1 signal: SE */
#define BOARD_INITPINS_ADC1_SE10_PORT PORTB              /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_ADC1_SE10_PIN 4U                  /*!<@brief PORTB pin index: 4 */
#define BOARD_INITPINS_ADC1_SE10_CHANNEL 10              /*!<@brief ADC1 SE channel: 10 */
#define BOARD_INITPINS_ADC1_SE10_PIN_NAME ADC1_SE10      /*!<@brief Pin name */
#define BOARD_INITPINS_ADC1_SE10_LABEL "J4[8]/ADC1_SE10" /*!<@brief Label */
#define BOARD_INITPINS_ADC1_SE10_NAME "ADC1_SE10"        /*!<@brief Identifier name */
                                                         /* @} */

/*! @name PORTB5 (coord G9), J4[6]/ADC1_SE11
  @{ */
#define BOARD_INITPINS_ADC1_SE11_PERIPHERAL ADC1         /*!<@brief Device name: ADC1 */
#define BOARD_INITPINS_ADC1_SE11_SIGNAL SE               /*!<@brief ADC1 signal: SE */
#define BOARD_INITPINS_ADC1_SE11_PORT PORTB              /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_ADC1_SE11_PIN 5U                  /*!<@brief PORTB pin index: 5 */
#define BOARD_INITPINS_ADC1_SE11_CHANNEL 11              /*!<@brief ADC1 SE channel: 11 */
#define BOARD_INITPINS_ADC1_SE11_PIN_NAME ADC1_SE11      /*!<@brief Pin name */
#define BOARD_INITPINS_ADC1_SE11_LABEL "J4[6]/ADC1_SE11" /*!<@brief Label */
#define BOARD_INITPINS_ADC1_SE11_NAME "ADC1_SE11"        /*!<@brief Identifier name */
                                                         /* @} */

/*! @name PORTB6 (coord F12), J4[4]/ADC1_SE12
  @{ */
#define BOARD_INITPINS_ADC1_SE12_PERIPHERAL ADC1         /*!<@brief Device name: ADC1 */
#define BOARD_INITPINS_ADC1_SE12_SIGNAL SE               /*!<@brief ADC1 signal: SE */
#define BOARD_INITPINS_ADC1_SE12_PORT PORTB              /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_ADC1_SE12_PIN 6U                  /*!<@brief PORTB pin index: 6 */
#define BOARD_INITPINS_ADC1_SE12_CHANNEL 12              /*!<@brief ADC1 SE channel: 12 */
#define BOARD_INITPINS_ADC1_SE12_PIN_NAME ADC1_SE12      /*!<@brief Pin name */
#define BOARD_INITPINS_ADC1_SE12_LABEL "J4[4]/ADC1_SE12" /*!<@brief Label */
#define BOARD_INITPINS_ADC1_SE12_NAME "ADC1_SE12"        /*!<@brief Identifier name */
                                                         /* @} */

/*! @name PORTB7 (coord F11), J4[2]/ADC1_SE13
  @{ */
#define BOARD_INITPINS_ADC1_SE13_PERIPHERAL ADC1         /*!<@brief Device name: ADC1 */
#define BOARD_INITPINS_ADC1_SE13_SIGNAL SE               /*!<@brief ADC1 signal: SE */
#define BOARD_INITPINS_ADC1_SE13_PORT PORTB              /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_ADC1_SE13_PIN 7U                  /*!<@brief PORTB pin index: 7 */
#define BOARD_INITPINS_ADC1_SE13_CHANNEL 13              /*!<@brief ADC1 SE channel: 13 */
#define BOARD_INITPINS_ADC1_SE13_PIN_NAME ADC1_SE13      /*!<@brief Pin name */
#define BOARD_INITPINS_ADC1_SE13_LABEL "J4[2]/ADC1_SE13" /*!<@brief Label */
#define BOARD_INITPINS_ADC1_SE13_NAME "ADC1_SE13"        /*!<@brief Identifier name */
                                                         /* @} */

/*! @name PORTB10 (coord E12), J2[7]/PTB10_RC/ADC1_SE14
  @{ */
#define BOARD_INITPINS_PTB10_RC_PERIPHERAL ADC1                  /*!<@brief Device name: ADC1 */
#define BOARD_INITPINS_PTB10_RC_SIGNAL SE                        /*!<@brief ADC1 signal: SE */
#define BOARD_INITPINS_PTB10_RC_PORT PORTB                       /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_PTB10_RC_PIN 10U                          /*!<@brief PORTB pin index: 10 */
#define BOARD_INITPINS_PTB10_RC_CHANNEL 14                       /*!<@brief ADC1 SE channel: 14 */
#define BOARD_INITPINS_PTB10_RC_PIN_NAME ADC1_SE14               /*!<@brief Pin name */
#define BOARD_INITPINS_PTB10_RC_LABEL "J2[7]/PTB10_RC/ADC1_SE14" /*!<@brief Label */
#define BOARD_INITPINS_PTB10_RC_NAME "PTB10_RC"                  /*!<@brief Identifier name */
                                                                 /* @} */

/*! @name PORTB11 (coord E11), J2[9]/PTB11_RC/ADC1_SE15
  @{ */
#define BOARD_INITPINS_PTB11_RC_PERIPHERAL ADC1                  /*!<@brief Device name: ADC1 */
#define BOARD_INITPINS_PTB11_RC_SIGNAL SE                        /*!<@brief ADC1 signal: SE */
#define BOARD_INITPINS_PTB11_RC_PORT PORTB                       /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_PTB11_RC_PIN 11U                          /*!<@brief PORTB pin index: 11 */
#define BOARD_INITPINS_PTB11_RC_CHANNEL 15                       /*!<@brief ADC1 SE channel: 15 */
#define BOARD_INITPINS_PTB11_RC_PIN_NAME ADC1_SE15               /*!<@brief Pin name */
#define BOARD_INITPINS_PTB11_RC_LABEL "J2[9]/PTB11_RC/ADC1_SE15" /*!<@brief Label */
#define BOARD_INITPINS_PTB11_RC_NAME "PTB11_RC"                  /*!<@brief Identifier name */
                                                                 /* @} */

/*! @name PORTD12 (coord B1), row1
  @{ */
#define BOARD_INITPINS_FB_A20_PERIPHERAL GPIOD /*!<@brief Device name: GPIOD */
#define BOARD_INITPINS_FB_A20_SIGNAL GPIO      /*!<@brief GPIOD signal: GPIO */
#define BOARD_INITPINS_FB_A20_GPIO GPIOD       /*!<@brief GPIO device name: GPIOD */
#define BOARD_INITPINS_FB_A20_GPIO_PIN 12U     /*!<@brief PORTD pin index: 12 */
#define BOARD_INITPINS_FB_A20_PORT PORTD       /*!<@brief PORT device name: PORTD */
#define BOARD_INITPINS_FB_A20_PIN 12U          /*!<@brief PORTD pin index: 12 */
#define BOARD_INITPINS_FB_A20_CHANNEL 12       /*!<@brief GPIOD GPIO channel: 12 */
#define BOARD_INITPINS_FB_A20_PIN_NAME PTD12   /*!<@brief Pin name */
#define BOARD_INITPINS_FB_A20_LABEL "row1"     /*!<@brief Label */
#define BOARD_INITPINS_FB_A20_NAME "FB_A20"    /*!<@brief Identifier name */
                                               /* @} */

/*! @name PORTD13 (coord C3), row2
  @{ */
#define BOARD_INITPINS_FB_A21_PERIPHERAL GPIOD /*!<@brief Device name: GPIOD */
#define BOARD_INITPINS_FB_A21_SIGNAL GPIO      /*!<@brief GPIOD signal: GPIO */
#define BOARD_INITPINS_FB_A21_GPIO GPIOD       /*!<@brief GPIO device name: GPIOD */
#define BOARD_INITPINS_FB_A21_GPIO_PIN 13U     /*!<@brief PORTD pin index: 13 */
#define BOARD_INITPINS_FB_A21_PORT PORTD       /*!<@brief PORT device name: PORTD */
#define BOARD_INITPINS_FB_A21_PIN 13U          /*!<@brief PORTD pin index: 13 */
#define BOARD_INITPINS_FB_A21_CHANNEL 13       /*!<@brief GPIOD GPIO channel: 13 */
#define BOARD_INITPINS_FB_A21_PIN_NAME PTD13   /*!<@brief Pin name */
#define BOARD_INITPINS_FB_A21_LABEL "row2"     /*!<@brief Label */
#define BOARD_INITPINS_FB_A21_NAME "FB_A21"    /*!<@brief Identifier name */
                                               /* @} */

/*! @name PORTE25 (coord K5), row3
  @{ */
#define BOARD_INITPINS_ADC0_SE18_PERIPHERAL GPIOE /*!<@brief Device name: GPIOE */
#define BOARD_INITPINS_ADC0_SE18_SIGNAL GPIO      /*!<@brief GPIOE signal: GPIO */
#define BOARD_INITPINS_ADC0_SE18_GPIO GPIOE       /*!<@brief GPIO device name: GPIOE */
#define BOARD_INITPINS_ADC0_SE18_GPIO_PIN 25U     /*!<@brief PORTE pin index: 25 */
#define BOARD_INITPINS_ADC0_SE18_PORT PORTE       /*!<@brief PORT device name: PORTE */
#define BOARD_INITPINS_ADC0_SE18_PIN 25U          /*!<@brief PORTE pin index: 25 */
#define BOARD_INITPINS_ADC0_SE18_CHANNEL 25       /*!<@brief GPIOE GPIO channel: 25 */
#define BOARD_INITPINS_ADC0_SE18_PIN_NAME PTE25   /*!<@brief Pin name */
#define BOARD_INITPINS_ADC0_SE18_LABEL "row3"     /*!<@brief Label */
#define BOARD_INITPINS_ADC0_SE18_NAME "ADC0_SE18" /*!<@brief Identifier name */
                                                  /* @} */

/*! @name PORTE24 (coord M4), row4
  @{ */
#define BOARD_INITPINS_ADC0_SE17_PERIPHERAL GPIOE /*!<@brief Device name: GPIOE */
#define BOARD_INITPINS_ADC0_SE17_SIGNAL GPIO      /*!<@brief GPIOE signal: GPIO */
#define BOARD_INITPINS_ADC0_SE17_GPIO GPIOE       /*!<@brief GPIO device name: GPIOE */
#define BOARD_INITPINS_ADC0_SE17_GPIO_PIN 24U     /*!<@brief PORTE pin index: 24 */
#define BOARD_INITPINS_ADC0_SE17_PORT PORTE       /*!<@brief PORT device name: PORTE */
#define BOARD_INITPINS_ADC0_SE17_PIN 24U          /*!<@brief PORTE pin index: 24 */
#define BOARD_INITPINS_ADC0_SE17_CHANNEL 24       /*!<@brief GPIOE GPIO channel: 24 */
#define BOARD_INITPINS_ADC0_SE17_PIN_NAME PTE24   /*!<@brief Pin name */
#define BOARD_INITPINS_ADC0_SE17_LABEL "row4"     /*!<@brief Label */
#define BOARD_INITPINS_ADC0_SE17_NAME "ADC0_SE17" /*!<@brief Identifier name */
                                                  /* @} */

/*! @name PORTC0 (coord B12), col1
  @{ */
#define BOARD_INITPINS_ADC0_SE14_PERIPHERAL GPIOC /*!<@brief Device name: GPIOC */
#define BOARD_INITPINS_ADC0_SE14_SIGNAL GPIO      /*!<@brief GPIOC signal: GPIO */
#define BOARD_INITPINS_ADC0_SE14_GPIO GPIOC       /*!<@brief GPIO device name: GPIOC */
#define BOARD_INITPINS_ADC0_SE14_GPIO_PIN 0U      /*!<@brief PORTC pin index: 0 */
#define BOARD_INITPINS_ADC0_SE14_PORT PORTC       /*!<@brief PORT device name: PORTC */
#define BOARD_INITPINS_ADC0_SE14_PIN 0U           /*!<@brief PORTC pin index: 0 */
#define BOARD_INITPINS_ADC0_SE14_CHANNEL 0        /*!<@brief GPIOC GPIO channel: 0 */
#define BOARD_INITPINS_ADC0_SE14_PIN_NAME PTC0    /*!<@brief Pin name */
#define BOARD_INITPINS_ADC0_SE14_LABEL "col1"     /*!<@brief Label */
#define BOARD_INITPINS_ADC0_SE14_NAME "ADC0_SE14" /*!<@brief Identifier name */
                                                  /* @} */

/*! @name PORTD1 (coord D4), col2
  @{ */
#define BOARD_INITPINS_SPI0_SCK_PERIPHERAL GPIOD /*!<@brief Device name: GPIOD */
#define BOARD_INITPINS_SPI0_SCK_SIGNAL GPIO      /*!<@brief GPIOD signal: GPIO */
#define BOARD_INITPINS_SPI0_SCK_GPIO GPIOD       /*!<@brief GPIO device name: GPIOD */
#define BOARD_INITPINS_SPI0_SCK_GPIO_PIN 1U      /*!<@brief PORTD pin index: 1 */
#define BOARD_INITPINS_SPI0_SCK_PORT PORTD       /*!<@brief PORT device name: PORTD */
#define BOARD_INITPINS_SPI0_SCK_PIN 1U           /*!<@brief PORTD pin index: 1 */
#define BOARD_INITPINS_SPI0_SCK_CHANNEL 1        /*!<@brief GPIOD GPIO channel: 1 */
#define BOARD_INITPINS_SPI0_SCK_PIN_NAME PTD1    /*!<@brief Pin name */
#define BOARD_INITPINS_SPI0_SCK_LABEL "col2"     /*!<@brief Label */
#define BOARD_INITPINS_SPI0_SCK_NAME "SPI0_SCK"  /*!<@brief Identifier name */
                                                 /* @} */

/*! @name PORTD2 (coord C4), col4
  @{ */
#define BOARD_INITPINS_SPI0_SOUT_PERIPHERAL GPIOD /*!<@brief Device name: GPIOD */
#define BOARD_INITPINS_SPI0_SOUT_SIGNAL GPIO      /*!<@brief GPIOD signal: GPIO */
#define BOARD_INITPINS_SPI0_SOUT_GPIO GPIOD       /*!<@brief GPIO device name: GPIOD */
#define BOARD_INITPINS_SPI0_SOUT_GPIO_PIN 2U      /*!<@brief PORTD pin index: 2 */
#define BOARD_INITPINS_SPI0_SOUT_PORT PORTD       /*!<@brief PORT device name: PORTD */
#define BOARD_INITPINS_SPI0_SOUT_PIN 2U           /*!<@brief PORTD pin index: 2 */
#define BOARD_INITPINS_SPI0_SOUT_CHANNEL 2        /*!<@brief GPIOD GPIO channel: 2 */
#define BOARD_INITPINS_SPI0_SOUT_PIN_NAME PTD2    /*!<@brief Pin name */
#define BOARD_INITPINS_SPI0_SOUT_LABEL "col4"     /*!<@brief Label */
#define BOARD_INITPINS_SPI0_SOUT_NAME "SPI0_SOUT" /*!<@brief Identifier name */
                                                  /* @} */

/*! @name PORTD3 (coord B4), col3
  @{ */
#define BOARD_INITPINS_SPI0_SIN_PERIPHERAL GPIOD /*!<@brief Device name: GPIOD */
#define BOARD_INITPINS_SPI0_SIN_SIGNAL GPIO      /*!<@brief GPIOD signal: GPIO */
#define BOARD_INITPINS_SPI0_SIN_GPIO GPIOD       /*!<@brief GPIO device name: GPIOD */
#define BOARD_INITPINS_SPI0_SIN_GPIO_PIN 3U      /*!<@brief PORTD pin index: 3 */
#define BOARD_INITPINS_SPI0_SIN_PORT PORTD       /*!<@brief PORT device name: PORTD */
#define BOARD_INITPINS_SPI0_SIN_PIN 3U           /*!<@brief PORTD pin index: 3 */
#define BOARD_INITPINS_SPI0_SIN_CHANNEL 3        /*!<@brief GPIOD GPIO channel: 3 */
#define BOARD_INITPINS_SPI0_SIN_PIN_NAME PTD3    /*!<@brief Pin name */
#define BOARD_INITPINS_SPI0_SIN_LABEL "col3"     /*!<@brief Label */
#define BOARD_INITPINS_SPI0_SIN_NAME "SPI0_SIN"  /*!<@brief Identifier name */
                                                 /* @} */

/*! @name PORTD0 (coord A5), col5
  @{ */
#define BOARD_INITPINS_SPI0_PCS0_PERIPHERAL GPIOD /*!<@brief Device name: GPIOD */
#define BOARD_INITPINS_SPI0_PCS0_SIGNAL GPIO      /*!<@brief GPIOD signal: GPIO */
#define BOARD_INITPINS_SPI0_PCS0_GPIO GPIOD       /*!<@brief GPIO device name: GPIOD */
#define BOARD_INITPINS_SPI0_PCS0_GPIO_PIN 0U      /*!<@brief PORTD pin index: 0 */
#define BOARD_INITPINS_SPI0_PCS0_PORT PORTD       /*!<@brief PORT device name: PORTD */
#define BOARD_INITPINS_SPI0_PCS0_PIN 0U           /*!<@brief PORTD pin index: 0 */
#define BOARD_INITPINS_SPI0_PCS0_CHANNEL 0        /*!<@brief GPIOD GPIO channel: 0 */
#define BOARD_INITPINS_SPI0_PCS0_PIN_NAME PTD0    /*!<@brief Pin name */
#define BOARD_INITPINS_SPI0_PCS0_LABEL "col5"     /*!<@brief Label */
#define BOARD_INITPINS_SPI0_PCS0_NAME "SPI0_PCS0" /*!<@brief Identifier name */
                                                  /* @} */

/*! @name PORTA25 (coord J12), col8
  @{ */
#define BOARD_INITPINS_CMP3_IN5_PERIPHERAL GPIOA /*!<@brief Device name: GPIOA */
#define BOARD_INITPINS_CMP3_IN5_SIGNAL GPIO      /*!<@brief GPIOA signal: GPIO */
#define BOARD_INITPINS_CMP3_IN5_GPIO GPIOA       /*!<@brief GPIO device name: GPIOA */
#define BOARD_INITPINS_CMP3_IN5_GPIO_PIN 25U     /*!<@brief PORTA pin index: 25 */
#define BOARD_INITPINS_CMP3_IN5_PORT PORTA       /*!<@brief PORT device name: PORTA */
#define BOARD_INITPINS_CMP3_IN5_PIN 25U          /*!<@brief PORTA pin index: 25 */
#define BOARD_INITPINS_CMP3_IN5_CHANNEL 25       /*!<@brief GPIOA GPIO channel: 25 */
#define BOARD_INITPINS_CMP3_IN5_PIN_NAME PTA25   /*!<@brief Pin name */
#define BOARD_INITPINS_CMP3_IN5_LABEL "col8"     /*!<@brief Label */
#define BOARD_INITPINS_CMP3_IN5_NAME "CMP3_IN5"  /*!<@brief Identifier name */
                                                 /* @} */

/*! @name PORTC2 (coord A12), col6
  @{ */
#define BOARD_INITPINS_FTM0_CH1_PERIPHERAL GPIOC /*!<@brief Device name: GPIOC */
#define BOARD_INITPINS_FTM0_CH1_SIGNAL GPIO      /*!<@brief GPIOC signal: GPIO */
#define BOARD_INITPINS_FTM0_CH1_GPIO GPIOC       /*!<@brief GPIO device name: GPIOC */
#define BOARD_INITPINS_FTM0_CH1_GPIO_PIN 2U      /*!<@brief PORTC pin index: 2 */
#define BOARD_INITPINS_FTM0_CH1_PORT PORTC       /*!<@brief PORT device name: PORTC */
#define BOARD_INITPINS_FTM0_CH1_PIN 2U           /*!<@brief PORTC pin index: 2 */
#define BOARD_INITPINS_FTM0_CH1_CHANNEL 2        /*!<@brief GPIOC GPIO channel: 2 */
#define BOARD_INITPINS_FTM0_CH1_PIN_NAME PTC2    /*!<@brief Pin name */
#define BOARD_INITPINS_FTM0_CH1_LABEL "col6"     /*!<@brief Label */
#define BOARD_INITPINS_FTM0_CH1_NAME "FTM0_CH1"  /*!<@brief Identifier name */
                                                 /* @} */

/*! @name PORTC5 (coord D8), col7
  @{ */
#define BOARD_INITPINS_FB_AD10_PERIPHERAL GPIOC /*!<@brief Device name: GPIOC */
#define BOARD_INITPINS_FB_AD10_SIGNAL GPIO      /*!<@brief GPIOC signal: GPIO */
#define BOARD_INITPINS_FB_AD10_GPIO GPIOC       /*!<@brief GPIO device name: GPIOC */
#define BOARD_INITPINS_FB_AD10_GPIO_PIN 5U      /*!<@brief PORTC pin index: 5 */
#define BOARD_INITPINS_FB_AD10_PORT PORTC       /*!<@brief PORT device name: PORTC */
#define BOARD_INITPINS_FB_AD10_PIN 5U           /*!<@brief PORTC pin index: 5 */
#define BOARD_INITPINS_FB_AD10_CHANNEL 5        /*!<@brief GPIOC GPIO channel: 5 */
#define BOARD_INITPINS_FB_AD10_PIN_NAME PTC5    /*!<@brief Pin name */
#define BOARD_INITPINS_FB_AD10_LABEL "col7"     /*!<@brief Label */
#define BOARD_INITPINS_FB_AD10_NAME "FB_AD10"   /*!<@brief Identifier name */
                                                /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void);

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
