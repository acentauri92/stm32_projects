#include <stdint.h>
#include "stm32f4xx_hal.h"


HAL_StatusTypeDef nRF24WriteRegister(uint8_t reg, uint8_t data);
HAL_StatusTypeDef nRF24WriteRegisterMultiple(uint8_t reg, uint8_t* data, int size);
HAL_StatusTypeDef nRF24ReadRegister(uint8_t reg, uint8_t* buffer);
void nRF24SendCommand(uint8_t command);