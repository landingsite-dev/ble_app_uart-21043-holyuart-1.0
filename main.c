/** @file
 *
 * @brief GH3026 heart-rate sensor minimal I2C register-read test (nRF52832).
 */

#include <stdint.h>
#include <stdbool.h>

#include "app_error.h"
#include "nrf_delay.h"
#include "nrf_gpio.h"
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"

#include "i2c.h"

#define DEAD_BEEF 0xDEADBEEF

/** GH3026 I2C 7-bit address shifted for 8-bit write address used by soft-I2C.
 */
#define GH3026_I2C_ADDR 0x28
#define GH3026_REG_0030 0x0030
#define GH3026_REG_0032 0x0032

static uint8_t m_reg_buf[12];

/**@brief Callback for SoftDevice / app asserts. */
void assert_nrf_callback(uint16_t line_num, const uint8_t *p_file_name) {
  app_error_handler(DEAD_BEEF, line_num, p_file_name);
}

static void log_init(void) {
  ret_code_t err_code = NRF_LOG_INIT(NULL);
  APP_ERROR_CHECK(err_code);
  NRF_LOG_DEFAULT_BACKENDS_INIT();
}

/**@brief Reset GH3026 then read registers 0x0030 and 0x0032. */
static void gh3026_basic_read_test(void) {
  nrf_gpio_cfg_output(GH3220_RESET_PIN);
  IIC_Init_pcf8563();

  nrf_gpio_pin_clear(GH3220_RESET_PIN);
  nrf_delay_ms(50);
  nrf_gpio_pin_set(GH3220_RESET_PIN);
  nrf_delay_ms(50);

  for (uint8_t i = 0; i < sizeof(m_reg_buf); i++) {
    m_reg_buf[i] = 0;
  }

  I2CReadSerial_pcf8563(GH3026_I2C_ADDR, GH3026_REG_0030, m_reg_buf, 2);
  nrf_delay_ms(50);
  nrf_delay_ms(50);

  I2CReadSerial_pcf8563(GH3026_I2C_ADDR, GH3026_REG_0032, &m_reg_buf[2], 2);
  nrf_delay_ms(50);
  nrf_delay_ms(50);

  NRF_LOG_INFO("GH3026 reg 0x0030 / 0x0032:");
  NRF_LOG_HEXDUMP_INFO(m_reg_buf, 4);
}

int main(void) {
  log_init();
  NRF_LOG_INFO("GH3026 basic register read test start");

  gh3026_basic_read_test();

  for (;;) {
    if (NRF_LOG_PROCESS() == false) {
      /* idle */
    }
  }
}
