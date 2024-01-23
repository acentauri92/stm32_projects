#include "nRF24L01.h"
#include "main.h"

extern SPI_HandleTypeDef hspi2;

HAL_StatusTypeDef nRF24WriteRegister(uint8_t reg, uint8_t data){
    uint8_t buffer[2];

    /*Set the 5th bit to 1 indicating write mode*/
    buffer[0] = (1 << 5) | reg;
    buffer[1] = data;
  
    /*Chip select*/
    HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, GPIO_PIN_RESET);

    HAL_SPI_Transmit(&hspi2, buffer, 2, 100);

    /*Chip unselect*/
    HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, GPIO_PIN_SET);

    return HAL_OK;

}

HAL_StatusTypeDef nRF24WriteRegisterMultiple(uint8_t reg, uint8_t* data, int size){
    uint8_t buffer;

    /*Set the 5th bit to 1 indicating write mode*/
    buffer = ( 1 << 5) | reg;

    /*Chip select*/
    HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, GPIO_PIN_RESET);

    /*Send register address*/
    HAL_SPI_Transmit(&hspi2, &buffer, 1, 100);

    HAL_SPI_Transmit(&hspi2, data, size, 100);

    /*Chip unselect*/
    HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, GPIO_PIN_SET);
    
    return HAL_OK;
}


HAL_StatusTypeDef nRF24ReadRegister(uint8_t reg, uint8_t* data){
    
    /*Chip select*/
    HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi2, &reg, 1, 100);
    HAL_SPI_Receive(&hspi2, data, 1, 100);
     /*Chip unselect*/
    HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, GPIO_PIN_SET);

    return HAL_OK;
}

HAL_StatusTypeDef nRF24ReadRegisterMultiple(uint8_t reg, uint8_t* data, int size){
    
    /*Chip select*/
    HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi2, &reg, 1, 100);
    HAL_SPI_Receive(&hspi2, data, size, 100);
     /*Chip unselect*/
    HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, GPIO_PIN_SET);

    return HAL_OK;
 
}

void nRF24SendCommand(uint8_t command){
    /*Chip select*/
    HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi2, &command, 1, 100);
     /*Chip unselect*/
    HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, GPIO_PIN_SET);   
}