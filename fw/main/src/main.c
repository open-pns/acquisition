#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/i2c.h>
#include <zephyr/sys/printk.h>

#define I2C_NODE            DT_NODELABEL(i2c1)
#define BMI270_I2C_ADDR     0x68   /* default addr, SDO pulled low */
#define BMI270_REG_CHIP_ID  0x00
#define BMI270_CHIP_ID_VAL  0x24

int main(void)
{
    const struct device *i2c_dev = DEVICE_DT_GET(I2C_NODE);

    while (1) {
        printk("--- probing BMI270 ---\n");

        if (!device_is_ready(i2c_dev)) {
            printk("I2C bus not ready\n");
        } else {
            uint8_t chip_id = 0;
            int ret = i2c_reg_read_byte(i2c_dev, BMI270_I2C_ADDR,
                                         BMI270_REG_CHIP_ID, &chip_id);

            if (ret) {
                printk("I2C read failed: %d (check wiring/address)\n", ret);
            } else {
                printk("BMI270 chip ID = 0x%02X (expected 0x%02X)\n",
                       chip_id, BMI270_CHIP_ID_VAL);
            }
        }

        k_msleep(1000);
    }

    return 0;
}