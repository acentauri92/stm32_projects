#include <stdint.h>
#include "stm32f4xx_hal.h"


HAL_StatusTypeDef nrf24_write_register(uint8_t reg, uint8_t* data);
HAL_StatusTypeDef nrf24_read_register(uint8_t reg, uint8_t* buffer);
HAL_StatusTypeDef nrf24_send_command(uint8_t command);