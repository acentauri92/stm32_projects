#include "nRF24L01.h"
#include "main.h"

#define SPI_WRITE       1U
#define SPI_READ        0U
#define SPI_RW_MODE_BIT 5U

#define SET_SPI_RW_MODE(x) ( (x) <<  (SPI_RW_MODE_BIT) )


extern SPI_HandleTypeDef hspi2;

// HAL_StatusTypeDef nrf24_write_register(uint8_t reg, uint8_t* data){
//     uint8_t buffer[2], status;

//     /*Set the 5th bit to 1 indicating write mode*/
//     uint8_t write_commad = ( 1 << 5) | reg;
  
//     /*Chip select*/
//     HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, GPIO_PIN_SET);
//     HAL_SPI_Transmit(&hspi2, &write_commad, 1, 100);
//     HAL_SPI_Transmit(&hspi2, buffer, 2, 100);

//     /*Chip unselect*/
//     HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, GPIO_PIN_RESET);

// }


// HAL_StatusTypeDef nrf24_read_register(uint8_t reg, uint8_t* data){
//     uint8_t buffer;

//     /*Set the 5th bit to 0 indicating read mode*/
//     buffer = ~( 1 << 5) & reg;

//     /*Chip select*/
//     HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, GPIO_PIN_SET);
//     HAL_SPI_Transmit(&hspi2, buffer, 1, 100);
//     HAL_SPI_Receive(&hspi2, data, 1, 100);
//      /*Chip unselect*/
//     HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, GPIO_PIN_SET);
 
// }