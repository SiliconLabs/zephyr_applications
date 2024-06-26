#ifndef ICM42670_REG_H
#define ICM42670_REG_H

#ifdef __cplusplus
extern "C" {
#endif

/** @cond DO_NOT_INCLUDE_WITH_DOXYGEN */

#define REG_SPI_READ_BIT                                 (1 << 7U)

/* SELF_TEST_X_GYRO bit fields*/
#define ICM20689_REG_SELF_TEST_X_GYRO                    (0X00)

#define ICM20689_SELF_TEST_X_GYRO_SHIFT_XG_ST_DATA       (0X00)

#define ICM20689_SELF_TEST_X_GYRO_MASK_XG_ST_DATA        (0XFF)

/* SELF_TEST_Y_GYRO bit fields*/
#define ICM20689_REG_SELF_TEST_Y_GYRO                    (0X01)

#define ICM20689_SELF_TEST_Y_GYRO_SHIFT_YG_ST_DATA       (0X00)

#define ICM20689_SELF_TEST_Y_GYRO_MASK_YG_ST_DATA        (0XFF)

/* SELF_TEST_Z_GYRO bit fields*/
#define ICM20689_REG_SELF_TEST_Z_GYRO                    (0X02)

#define ICM20689_SELF_TEST_Z_GYRO_SHIFT_ZG_ST_DATA       (0X00)

#define ICM20689_SELF_TEST_Z_GYRO_MASK_ZG_ST_DATA        (0XFF)

/* SELF_TEST_X_ACCEL bit fields*/
#define ICM20689_REG_SELF_TEST_X_ACCEL                   (0X0D)

#define ICM20689_SELF_TEST_X_ACCEL_SHIFT_XA_ST_DATA      (0X00)

#define ICM20689_SELF_TEST_X_ACCEL_MASK_XA_ST_DATA       (0XFF)

/* SELF_TEST_Y_ACCEL bit fields*/
#define ICM20689_REG_SELF_TEST_Y_ACCEL                   (0X0E)

#define ICM20689_SELF_TEST_Y_ACCEL_SHIFT_YA_ST_DATA      (0X00)

#define ICM20689_SELF_TEST_Y_ACCEL_MASK_YA_ST_DATA       (0XFF)

/* SELF_TEST_Z_ACCEL bit fields*/
#define ICM20689_REG_SELF_TEST_Z_ACCEL                   (0X0F)

#define ICM20689_SELF_TEST_Z_ACCEL_SHIFT_ZA_ST_DATA      (0X00)

#define ICM20689_SELF_TEST_Z_ACCEL_MASK_ZA_ST_DATA       (0XFF)

/* XG_OFFS_USRH bit fields*/
#define ICM20689_REG_XG_OFFS_USRH                        (0X13)

#define ICM20689_XG_OFFS_USRH_SHIFT_X_OFFS_USR           (0X00)

#define ICM20689_XG_OFFS_USRH_MASK_X_OFFS_USR            (0XFF)

/* XG_OFFS_USRL bit fields*/
#define ICM20689_REG_XG_OFFS_USRL                        (0X14)

#define ICM20689_XG_OFFS_USRL_SHIFT_X_OFFS_USR           (0X00)

#define ICM20689_XG_OFFS_USRL_MASK_X_OFFS_USR            (0XFF)

/* YG_OFFS_USRH bit fields*/
#define ICM20689_REG_YG_OFFS_USRH                        (0X15)

#define ICM20689_YG_OFFS_USRH_SHIFT_Y_OFFS_USR           (0X00)

#define ICM20689_YG_OFFS_USRH_MASK_Y_OFFS_USR            (0XFF)

/* YG_OFFS_USRL bit fields*/
#define ICM20689_REG_YG_OFFS_USRL                        (0X16)

#define ICM20689_YG_OFFS_USRL_SHIFT_Y_OFFS_USR           (0X00)

#define ICM20689_YG_OFFS_USRL_MASK_Y_OFFS_USR            (0XFF)

/* ZG_OFFS_USRH bit fields*/
#define ICM20689_REG_ZG_OFFS_USRH                        (0X17)

#define ICM20689_ZG_OFFS_USRH_SHIFT_Z_OFFS_USR           (0X00)

#define ICM20689_ZG_OFFS_USRH_MASK_Z_OFFS_USR            (0XFF)

/* ZG_OFFS_USRL bit fields*/
#define ICM20689_REG_ZG_OFFS_USRL                        (0X18)

#define ICM20689_ZG_OFFS_USRL_SHIFT_Z_OFFS_USR           (0X00)

#define ICM20689_ZG_OFFS_USRL_MASK_Z_OFFS_USR            (0XFF)

/* SMPLRT_DIV bit fields*/
#define ICM20689_REG_SMPLRT_DIV                          (0X19)

#define ICM20689_SMPLRT_DIV_SHIFT_SMPLRT_DIV             (0X00)

#define ICM20689_SMPLRT_DIV_MASK_SMPLRT_DIV              (0XFF)

/* CONFIG bit fields*/
#define ICM20689_REG_CONFIG                              (0X1A)

#define ICM20689_CONFIG_SHIFT_DLPF_CFG                   (0X00)
#define ICM20689_CONFIG_SHIFT_EXT_SYNC_SET               (0X03)
#define ICM20689_CONFIG_SHIFT_FIFO_MODE                  (0X06)

#define ICM20689_CONFIG_MASK_DLPF_CFG                    (0X07)
#define ICM20689_CONFIG_MASK_EXT_SYNC_SET                (0X38)
#define ICM20689_CONFIG_MASK_FIFO_MODE                   (0X40)

#define ICM20689_CONFIG_BIT_FIFO_MODE                    (0X40)

#define _ICM20689_CONFIG_DLPF_CFG_250HZ                  (0X00)
#define _ICM20689_CONFIG_DLPF_CFG_176HZ                  (0X01)
#define _ICM20689_CONFIG_DLPF_CFG_92HZ                   (0X02)
#define _ICM20689_CONFIG_DLPF_CFG_41HZ                   (0X03)
#define _ICM20689_CONFIG_DLPF_CFG_20HZ                   (0X04)
#define _ICM20689_CONFIG_DLPF_CFG_10HZ                   (0X05)
#define _ICM20689_CONFIG_DLPF_CFG_5HZ                    (0X06)
#define _ICM20689_CONFIG_DLPF_CFG_3281HZ                 (0X07)
#define ICM20689_CONFIG_DLPF_CFG_250HZ                   (0X00 << \
                                                          ICM20689_CONFIG_SHIFT_DLPF_CFG)
#define ICM20689_CONFIG_DLPF_CFG_176HZ                   (0X01 << \
                                                          ICM20689_CONFIG_SHIFT_DLPF_CFG)
#define ICM20689_CONFIG_DLPF_CFG_92HZ                    (0X02 << \
                                                          ICM20689_CONFIG_SHIFT_DLPF_CFG)
#define ICM20689_CONFIG_DLPF_CFG_41HZ                    (0X03 << \
                                                          ICM20689_CONFIG_SHIFT_DLPF_CFG)
#define ICM20689_CONFIG_DLPF_CFG_20HZ                    (0X04 << \
                                                          ICM20689_CONFIG_SHIFT_DLPF_CFG)
#define ICM20689_CONFIG_DLPF_CFG_10HZ                    (0X05 << \
                                                          ICM20689_CONFIG_SHIFT_DLPF_CFG)
#define ICM20689_CONFIG_DLPF_CFG_5HZ                     (0X06 << \
                                                          ICM20689_CONFIG_SHIFT_DLPF_CFG)
#define ICM20689_CONFIG_DLPF_CFG_3281HZ                  (0X07 << \
                                                          ICM20689_CONFIG_SHIFT_DLPF_CFG)

#define _ICM20689_CONFIG_EXT_SYNC_SET_DISABLED           (0X00)
#define _ICM20689_CONFIG_EXT_SYNC_SET_TEMP_OUT_L0        (0X01)
#define _ICM20689_CONFIG_EXT_SYNC_SET_GYRO_XOUT_L0       (0X02)
#define _ICM20689_CONFIG_EXT_SYNC_SET_GYRO_YOUT_L0       (0X03)
#define _ICM20689_CONFIG_EXT_SYNC_SET_GYRO_ZOUT_L0       (0X04)
#define _ICM20689_CONFIG_EXT_SYNC_SET_ACCEL_XOUT_L0      (0X05)
#define _ICM20689_CONFIG_EXT_SYNC_SET_ACCEL_YOUT_L0      (0X06)
#define _ICM20689_CONFIG_EXT_SYNC_SET_ACCEL_ZOUT_L0      (0X07)
#define ICM20689_CONFIG_EXT_SYNC_SET_DISABLED            (0X00 << \
                                                          ICM20689_CONFIG_SHIFT_EXT_SYNC_SET)
#define ICM20689_CONFIG_EXT_SYNC_SET_TEMP_OUT_L0         (0X01 << \
                                                          ICM20689_CONFIG_SHIFT_EXT_SYNC_SET)
#define ICM20689_CONFIG_EXT_SYNC_SET_GYRO_XOUT_L0        (0X02 << \
                                                          ICM20689_CONFIG_SHIFT_EXT_SYNC_SET)
#define ICM20689_CONFIG_EXT_SYNC_SET_GYRO_YOUT_L0        (0X03 << \
                                                          ICM20689_CONFIG_SHIFT_EXT_SYNC_SET)
#define ICM20689_CONFIG_EXT_SYNC_SET_GYRO_ZOUT_L0        (0X04 << \
                                                          ICM20689_CONFIG_SHIFT_EXT_SYNC_SET)
#define ICM20689_CONFIG_EXT_SYNC_SET_ACCEL_XOUT_L0       (0X05 << \
                                                          ICM20689_CONFIG_SHIFT_EXT_SYNC_SET)
#define ICM20689_CONFIG_EXT_SYNC_SET_ACCEL_YOUT_L0       (0X06 << \
                                                          ICM20689_CONFIG_SHIFT_EXT_SYNC_SET)
#define ICM20689_CONFIG_EXT_SYNC_SET_ACCEL_ZOUT_L0       (0X07 << \
                                                          ICM20689_CONFIG_SHIFT_EXT_SYNC_SET)

/* GYRO_CONFIG bit fields*/
#define ICM20689_REG_GYRO_CONFIG                         (0X1B)

#define ICM20689_GYRO_CONFIG_SHIFT_FCHOICE_B             (0X00)
#define ICM20689_GYRO_CONFIG_SHIFT_FS_SEL                (0X03)
#define ICM20689_GYRO_CONFIG_SHIFT_ZG_ST                 (0X05)
#define ICM20689_GYRO_CONFIG_SHIFT_YG_ST                 (0X06)
#define ICM20689_GYRO_CONFIG_SHIFT_XG_ST                 (0X07)

#define ICM20689_GYRO_CONFIG_MASK_FCHOICE_B              (0X03)
#define ICM20689_GYRO_CONFIG_MASK_FS_SEL                 (0X18)
#define ICM20689_GYRO_CONFIG_MASK_ZG_ST                  (0X20)
#define ICM20689_GYRO_CONFIG_MASK_YG_ST                  (0X40)
#define ICM20689_GYRO_CONFIG_MASK_XG_ST                  (0X80)

#define ICM20689_GYRO_CONFIG_BIT_ZG_ST                   (0X20)
#define ICM20689_GYRO_CONFIG_BIT_YG_ST                   (0X40)
#define ICM20689_GYRO_CONFIG_BIT_XG_ST                   (0X80)

#define _ICM20689_GYRO_CONFIG_FCHOICE_B_LOWPASS          (0X00)
#define _ICM20689_GYRO_CONFIG_FCHOICE_B_8173HZ           (0X01)
#define _ICM20689_GYRO_CONFIG_FCHOICE_B_3281HZ           (0X02)
#define ICM20689_GYRO_CONFIG_FCHOICE_B_LOWPASS           (0X00 << \
                                                          ICM20689_GYRO_CONFIG_SHIFT_FCHOICE_B)
#define ICM20689_GYRO_CONFIG_FCHOICE_B_8173HZ            (0X01 << \
                                                          ICM20689_GYRO_CONFIG_SHIFT_FCHOICE_B)
#define ICM20689_GYRO_CONFIG_FCHOICE_B_3281HZ            (0X02 << \
                                                          ICM20689_GYRO_CONFIG_SHIFT_FCHOICE_B)

#define _ICM20689_GYRO_CONFIG_FS_SEL_250_DPS             (0X00)
#define _ICM20689_GYRO_CONFIG_FS_SEL_500_DPS             (0X01)
#define _ICM20689_GYRO_CONFIG_FS_SEL_1000_DPS            (0X02)
#define _ICM20689_GYRO_CONFIG_FS_SEL_2000_DPS            (0X03)
#define ICM20689_GYRO_CONFIG_FS_SEL_250_DPS              (0X00 << \
                                                          ICM20689_GYRO_CONFIG_SHIFT_FS_SEL)
#define ICM20689_GYRO_CONFIG_FS_SEL_500_DPS              (0X01 << \
                                                          ICM20689_GYRO_CONFIG_SHIFT_FS_SEL)
#define ICM20689_GYRO_CONFIG_FS_SEL_1000_DPS             (0X02 << \
                                                          ICM20689_GYRO_CONFIG_SHIFT_FS_SEL)
#define ICM20689_GYRO_CONFIG_FS_SEL_2000_DPS             (0X03 << \
                                                          ICM20689_GYRO_CONFIG_SHIFT_FS_SEL)

/* ACCEL_CONFIG bit fields*/
#define ICM20689_REG_ACCEL_CONFIG                        (0X1C)

#define ICM20689_ACCEL_CONFIG_SHIFT_ACCEL_FS_SEL         (0X03)
#define ICM20689_ACCEL_CONFIG_SHIFT_ZA_ST                (0X05)
#define ICM20689_ACCEL_CONFIG_SHIFT_YA_ST                (0X06)
#define ICM20689_ACCEL_CONFIG_SHIFT_XA_ST                (0X07)

#define ICM20689_ACCEL_CONFIG_MASK_ACCEL_FS_SEL          (0X18)
#define ICM20689_ACCEL_CONFIG_MASK_ZA_ST                 (0X20)
#define ICM20689_ACCEL_CONFIG_MASK_YA_ST                 (0X40)
#define ICM20689_ACCEL_CONFIG_MASK_XA_ST                 (0X80)

#define ICM20689_ACCEL_CONFIG_BIT_ZA_ST                  (0X20)
#define ICM20689_ACCEL_CONFIG_BIT_YA_ST                  (0X40)
#define ICM20689_ACCEL_CONFIG_BIT_XA_ST                  (0X80)

#define _ICM20689_ACCEL_CONFIG_ACCEL_FS_SEL_2G           (0X00)
#define _ICM20689_ACCEL_CONFIG_ACCEL_FS_SEL_4G           (0X01)
#define _ICM20689_ACCEL_CONFIG_ACCEL_FS_SEL_8G           (0X02)
#define _ICM20689_ACCEL_CONFIG_ACCEL_FS_SEL_16G          (0X03)
#define ICM20689_ACCEL_CONFIG_ACCEL_FS_SEL_2G            (0X00 << \
                                                          ICM20689_ACCEL_CONFIG_SHIFT_ACCEL_FS_SEL)
#define ICM20689_ACCEL_CONFIG_ACCEL_FS_SEL_4G            (0X01 << \
                                                          ICM20689_ACCEL_CONFIG_SHIFT_ACCEL_FS_SEL)
#define ICM20689_ACCEL_CONFIG_ACCEL_FS_SEL_8G            (0X02 << \
                                                          ICM20689_ACCEL_CONFIG_SHIFT_ACCEL_FS_SEL)
#define ICM20689_ACCEL_CONFIG_ACCEL_FS_SEL_16G           (0X03 << \
                                                          ICM20689_ACCEL_CONFIG_SHIFT_ACCEL_FS_SEL)

/* ACCEL_CONFIG2 bit fields*/
#define ICM20689_REG_ACCEL_CONFIG2                       (0X1D)

#define ICM20689_ACCEL_CONFIG2_SHIFT_A_DLPF_CFG          (0X00)
#define ICM20689_ACCEL_CONFIG2_SHIFT_ACCEL_FCHOICE_B     (0X03)
#define ICM20689_ACCEL_CONFIG2_SHIFT_DEC2_CFG            (0X04)

#define ICM20689_ACCEL_CONFIG2_MASK_A_DLPF_CFG           (0X07)
#define ICM20689_ACCEL_CONFIG2_MASK_ACCEL_FCHOICE_B      (0X08)
#define ICM20689_ACCEL_CONFIG2_MASK_DEC2_CFG             (0X30)

#define ICM20689_ACCEL_CONFIG2_BIT_ACCEL_FCHOICE_B       (0X08)

#define _ICM20689_ACCEL_CONFIG2_A_DLPF_CFG_218_1_0HZ     (0X00)
#define _ICM20689_ACCEL_CONFIG2_A_DLPF_CFG_218_1_1HZ     (0X01)
#define _ICM20689_ACCEL_CONFIG2_A_DLPF_CFG_99HZ          (0X02)
#define _ICM20689_ACCEL_CONFIG2_A_DLPF_CFG_44HZ          (0X03)
#define _ICM20689_ACCEL_CONFIG2_A_DLPF_CFG_21_2HZ        (0X04)
#define _ICM20689_ACCEL_CONFIG2_A_DLPF_CFG_10_2HZ        (0X05)
#define _ICM20689_ACCEL_CONFIG2_A_DLPF_CFG_5_1HZ         (0X06)
#define _ICM20689_ACCEL_CONFIG2_A_DLPF_CFG_420HZ         (0X07)
#define ICM20689_ACCEL_CONFIG2_A_DLPF_CFG_218_1_0HZ      (0X00 << \
                                                          ICM20689_ACCEL_CONFIG2_SHIFT_A_DLPF_CFG)
#define ICM20689_ACCEL_CONFIG2_A_DLPF_CFG_218_1_1HZ      (0X01 << \
                                                          ICM20689_ACCEL_CONFIG2_SHIFT_A_DLPF_CFG)
#define ICM20689_ACCEL_CONFIG2_A_DLPF_CFG_99HZ           (0X02 << \
                                                          ICM20689_ACCEL_CONFIG2_SHIFT_A_DLPF_CFG)
#define ICM20689_ACCEL_CONFIG2_A_DLPF_CFG_44HZ           (0X03 << \
                                                          ICM20689_ACCEL_CONFIG2_SHIFT_A_DLPF_CFG)
#define ICM20689_ACCEL_CONFIG2_A_DLPF_CFG_21_2HZ         (0X04 << \
                                                          ICM20689_ACCEL_CONFIG2_SHIFT_A_DLPF_CFG)
#define ICM20689_ACCEL_CONFIG2_A_DLPF_CFG_10_2HZ         (0X05 << \
                                                          ICM20689_ACCEL_CONFIG2_SHIFT_A_DLPF_CFG)
#define ICM20689_ACCEL_CONFIG2_A_DLPF_CFG_5_1HZ          (0X06 << \
                                                          ICM20689_ACCEL_CONFIG2_SHIFT_A_DLPF_CFG)
#define ICM20689_ACCEL_CONFIG2_A_DLPF_CFG_420HZ          (0X07 << \
                                                          ICM20689_ACCEL_CONFIG2_SHIFT_A_DLPF_CFG)

#define _ICM20689_ACCEL_CONFIG2_DEC2_CFG_4_SMPL          (0X00)
#define _ICM20689_ACCEL_CONFIG2_DEC2_CFG_8_SMPL          (0X01)
#define _ICM20689_ACCEL_CONFIG2_DEC2_CFG_16_SMPL         (0X02)
#define _ICM20689_ACCEL_CONFIG2_DEC2_CFG_32_SMPL         (0X03)
#define ICM20689_ACCEL_CONFIG2_DEC2_CFG_4_SMPL           (0X00 << \
                                                          ICM20689_ACCEL_CONFIG2_SHIFT_DEC2_CFG)
#define ICM20689_ACCEL_CONFIG2_DEC2_CFG_8_SMPL           (0X01 << \
                                                          ICM20689_ACCEL_CONFIG2_SHIFT_DEC2_CFG)
#define ICM20689_ACCEL_CONFIG2_DEC2_CFG_16_SMPL          (0X02 << \
                                                          ICM20689_ACCEL_CONFIG2_SHIFT_DEC2_CFG)
#define ICM20689_ACCEL_CONFIG2_DEC2_CFG_32_SMPL          (0X03 << \
                                                          ICM20689_ACCEL_CONFIG2_SHIFT_DEC2_CFG)

/* LP_MODE_CFG bit fields*/
#define ICM20689_REG_LP_MODE_CFG                         (0X1E)

#define ICM20689_LP_MODE_CFG_SHIFT_G_AVGCFG              (0X04)
#define ICM20689_LP_MODE_CFG_SHIFT_GYRO_CYCLE            (0X07)

#define ICM20689_LP_MODE_CFG_MASK_G_AVGCFG               (0X70)
#define ICM20689_LP_MODE_CFG_MASK_GYRO_CYCLE             (0X80)

#define ICM20689_LP_MODE_CFG_BIT_GYRO_CYCLE              (0X80)

#define _ICM20689_LP_MODE_CFG_G_AVGCFG_1X                (0X00)
#define _ICM20689_LP_MODE_CFG_G_AVGCFG_2X                (0X01)
#define _ICM20689_LP_MODE_CFG_G_AVGCFG_4X                (0X02)
#define _ICM20689_LP_MODE_CFG_G_AVGCFG_8X                (0X03)
#define _ICM20689_LP_MODE_CFG_G_AVGCFG_16X               (0X04)
#define _ICM20689_LP_MODE_CFG_G_AVGCFG_32X               (0X05)
#define _ICM20689_LP_MODE_CFG_G_AVGCFG_64X               (0X06)
#define _ICM20689_LP_MODE_CFG_G_AVGCFG_128X              (0X07)
#define ICM20689_LP_MODE_CFG_G_AVGCFG_1X                 (0X00 << \
                                                          ICM20689_LP_MODE_CFG_SHIFT_G_AVGCFG)
#define ICM20689_LP_MODE_CFG_G_AVGCFG_2X                 (0X01 << \
                                                          ICM20689_LP_MODE_CFG_SHIFT_G_AVGCFG)
#define ICM20689_LP_MODE_CFG_G_AVGCFG_4X                 (0X02 << \
                                                          ICM20689_LP_MODE_CFG_SHIFT_G_AVGCFG)
#define ICM20689_LP_MODE_CFG_G_AVGCFG_8X                 (0X03 << \
                                                          ICM20689_LP_MODE_CFG_SHIFT_G_AVGCFG)
#define ICM20689_LP_MODE_CFG_G_AVGCFG_16X                (0X04 << \
                                                          ICM20689_LP_MODE_CFG_SHIFT_G_AVGCFG)
#define ICM20689_LP_MODE_CFG_G_AVGCFG_32X                (0X05 << \
                                                          ICM20689_LP_MODE_CFG_SHIFT_G_AVGCFG)
#define ICM20689_LP_MODE_CFG_G_AVGCFG_64X                (0X06 << \
                                                          ICM20689_LP_MODE_CFG_SHIFT_G_AVGCFG)
#define ICM20689_LP_MODE_CFG_G_AVGCFG_128X               (0X07 << \
                                                          ICM20689_LP_MODE_CFG_SHIFT_G_AVGCFG)

/* ACCEL_WOM_THR bit fields*/
#define ICM20689_REG_ACCEL_WOM_THR                       (0X1F)

#define ICM20689_ACCEL_WOM_THR_SHIFT_WOM_THR             (0X00)

#define ICM20689_ACCEL_WOM_THR_MASK_WOM_THR              (0XFF)

/* FIFO_EN bit fields*/
#define ICM20689_REG_FIFO_EN                             (0X23)

#define ICM20689_FIFO_EN_SHIFT_ACCEL_FIFO_EN             (0X03)
#define ICM20689_FIFO_EN_SHIFT_ZG_FIFO_EN                (0X04)
#define ICM20689_FIFO_EN_SHIFT_YG_FIFO_EN                (0X05)
#define ICM20689_FIFO_EN_SHIFT_XG_FIFO_EN                (0X06)
#define ICM20689_FIFO_EN_SHIFT_TEMP_FIFO_EN              (0X07)

#define ICM20689_FIFO_EN_MASK_ACCEL_FIFO_EN              (0X08)
#define ICM20689_FIFO_EN_MASK_ZG_FIFO_EN                 (0X10)
#define ICM20689_FIFO_EN_MASK_YG_FIFO_EN                 (0X20)
#define ICM20689_FIFO_EN_MASK_XG_FIFO_EN                 (0X40)
#define ICM20689_FIFO_EN_MASK_TEMP_FIFO_EN               (0X80)

#define ICM20689_FIFO_EN_BIT_ACCEL_FIFO_EN               (0X08)
#define ICM20689_FIFO_EN_BIT_ZG_FIFO_EN                  (0X10)
#define ICM20689_FIFO_EN_BIT_YG_FIFO_EN                  (0X20)
#define ICM20689_FIFO_EN_BIT_XG_FIFO_EN                  (0X40)
#define ICM20689_FIFO_EN_BIT_TEMP_FIFO_EN                (0X80)

/* FSYNC_INT bit fields*/
#define ICM20689_REG_FSYNC_INT                           (0X36)

#define ICM20689_FSYNC_INT_SHIFT_FSYNC_INT               (0X07)

#define ICM20689_FSYNC_INT_MASK_FSYNC_INT                (0X80)

#define ICM20689_FSYNC_INT_BIT_FSYNC_INT                 (0X80)

/* INT_PIN_CFG bit fields*/
#define ICM20689_REG_INT_PIN_CFG                         (0X37)

#define ICM20689_INT_PIN_CFG_SHIFT_FSYNC_INT_MODE_EN     (0X02)
#define ICM20689_INT_PIN_CFG_SHIFT_FSYNC_INT_LEVEL       (0X03)
#define ICM20689_INT_PIN_CFG_SHIFT_INT_RD_CLEAR          (0X04)
#define ICM20689_INT_PIN_CFG_SHIFT_LATCH_INT_EN          (0X05)
#define ICM20689_INT_PIN_CFG_SHIFT_INT_OPEN              (0X06)
#define ICM20689_INT_PIN_CFG_SHIFT_INT_LEVEL             (0X07)

#define ICM20689_INT_PIN_CFG_MASK_FSYNC_INT_MODE_EN      (0X04)
#define ICM20689_INT_PIN_CFG_MASK_FSYNC_INT_LEVEL        (0X08)
#define ICM20689_INT_PIN_CFG_MASK_INT_RD_CLEAR           (0X10)
#define ICM20689_INT_PIN_CFG_MASK_LATCH_INT_EN           (0X20)
#define ICM20689_INT_PIN_CFG_MASK_INT_OPEN               (0X40)
#define ICM20689_INT_PIN_CFG_MASK_INT_LEVEL              (0X80)

#define ICM20689_INT_PIN_CFG_BIT_FSYNC_INT_MODE_EN       (0X04)
#define ICM20689_INT_PIN_CFG_BIT_FSYNC_INT_LEVEL         (0X08)
#define ICM20689_INT_PIN_CFG_BIT_INT_RD_CLEAR            (0X10)
#define ICM20689_INT_PIN_CFG_BIT_LATCH_INT_EN            (0X20)
#define ICM20689_INT_PIN_CFG_BIT_INT_OPEN                (0X40)
#define ICM20689_INT_PIN_CFG_BIT_INT_LEVEL               (0X80)

/* INT_ENABLE bit fields*/
#define ICM20689_REG_INT_ENABLE                          (0X38)

#define ICM20689_INT_ENABLE_SHIFT_DATA_RDY_INT_EN        (0X00)
#define ICM20689_INT_ENABLE_SHIFT_DMP_INT_EN             (0X01)
#define ICM20689_INT_ENABLE_SHIFT_GDRIVE_INT_EN          (0X02)
#define ICM20689_INT_ENABLE_SHIFT_FIFO_OFLOW_EN          (0X04)
#define ICM20689_INT_ENABLE_SHIFT_WOM_INT_EN             (0X05)

#define ICM20689_INT_ENABLE_MASK_DATA_RDY_INT_EN         (0X01)
#define ICM20689_INT_ENABLE_MASK_DMP_INT_EN              (0X02)
#define ICM20689_INT_ENABLE_MASK_GDRIVE_INT_EN           (0X04)
#define ICM20689_INT_ENABLE_MASK_FIFO_OFLOW_EN           (0X10)
#define ICM20689_INT_ENABLE_MASK_WOM_INT_EN              (0XE0)

#define ICM20689_INT_ENABLE_BIT_DATA_RDY_INT_EN          (0X01)
#define ICM20689_INT_ENABLE_BIT_DMP_INT_EN               (0X02)
#define ICM20689_INT_ENABLE_BIT_GDRIVE_INT_EN            (0X04)
#define ICM20689_INT_ENABLE_BIT_FIFO_OFLOW_EN            (0X10)

/* DMP_INT_STATUS bit fields*/
#define ICM20689_REG_DMP_INT_STATUS                      (0X39)

#define ICM20689_DMP_INT_STATUS_SHIFT_DMP_INT            (0X00)

#define ICM20689_DMP_INT_STATUS_MASK_DMP_INT             (0X3F)

/* INT_STATUS bit fields*/
#define ICM20689_REG_INT_STATUS                          (0X3A)

#define ICM20689_INT_STATUS_SHIFT_DATA_RDY_INT           (0X00)
#define ICM20689_INT_STATUS_SHIFT_DMP_INT                (0X01)
#define ICM20689_INT_STATUS_SHIFT_GDRIVE_INT             (0X02)
#define ICM20689_INT_STATUS_SHIFT_FIFO_OFLOW_INT         (0X04)
#define ICM20689_INT_STATUS_SHIFT_WOM_INT                (0X05)

#define ICM20689_INT_STATUS_MASK_DATA_RDY_INT            (0X01)
#define ICM20689_INT_STATUS_MASK_DMP_INT                 (0X02)
#define ICM20689_INT_STATUS_MASK_GDRIVE_INT              (0X04)
#define ICM20689_INT_STATUS_MASK_FIFO_OFLOW_INT          (0X10)
#define ICM20689_INT_STATUS_MASK_WOM_INT                 (0XE0)

#define ICM20689_INT_STATUS_BIT_DATA_RDY_INT             (0X01)
#define ICM20689_INT_STATUS_BIT_DMP_INT                  (0X02)
#define ICM20689_INT_STATUS_BIT_GDRIVE_INT               (0X04)
#define ICM20689_INT_STATUS_BIT_FIFO_OFLOW_INT           (0X10)

/* ACCEL_XOUT_H bit fields*/
#define ICM20689_REG_ACCEL_XOUT_H                        (0X3B)

#define ICM20689_ACCEL_XOUT_H_SHIFT_ACCEL_XOUT_H         (0X00)

#define ICM20689_ACCEL_XOUT_H_MASK_ACCEL_XOUT_H          (0XFF)

/* ACCEL_XOUT_L bit fields*/
#define ICM20689_REG_ACCEL_XOUT_L                        (0X3C)

#define ICM20689_ACCEL_XOUT_L_SHIFT_ACCEL_XOUT_L         (0X00)

#define ICM20689_ACCEL_XOUT_L_MASK_ACCEL_XOUT_L          (0XFF)

/* ACCEL_YOUT_H bit fields*/
#define ICM20689_REG_ACCEL_YOUT_H                        (0X3D)

#define ICM20689_ACCEL_YOUT_H_SHIFT_ACCEL_YOUT_H         (0X00)

#define ICM20689_ACCEL_YOUT_H_MASK_ACCEL_YOUT_H          (0XFF)

/* ACCEL_YOUT_L bit fields*/
#define ICM20689_REG_ACCEL_YOUT_L                        (0X3E)

#define ICM20689_ACCEL_YOUT_L_SHIFT_ACCEL_YOUT_L         (0X00)

#define ICM20689_ACCEL_YOUT_L_MASK_ACCEL_YOUT_L          (0XFF)

/* ACCEL_ZOUT_H bit fields*/
#define ICM20689_REG_ACCEL_ZOUT_H                        (0X3F)

#define ICM20689_ACCEL_ZOUT_H_SHIFT_ACCEL_ZOUT_H         (0X00)

#define ICM20689_ACCEL_ZOUT_H_MASK_ACCEL_ZOUT_H          (0XFF)

/* ACCEL_ZOUT_L bit fields*/
#define ICM20689_REG_ACCEL_ZOUT_L                        (0X40)

#define ICM20689_ACCEL_ZOUT_L_SHIFT_ACCEL_ZOUT_L         (0X00)

#define ICM20689_ACCEL_ZOUT_L_MASK_ACCEL_ZOUT_L          (0XFF)

/* TEMP_OUT_H bit fields*/
#define ICM20689_REG_TEMP_OUT_H                          (0X41)

#define ICM20689_TEMP_OUT_H_SHIFT_TEMP_OUT               (0X00)

#define ICM20689_TEMP_OUT_H_MASK_TEMP_OUT                (0XFF)

/* TEMP_OUT_L bit fields*/
#define ICM20689_REG_TEMP_OUT_L                          (0X42)

#define ICM20689_TEMP_OUT_L_SHIFT_TEMP_OUT               (0X00)

#define ICM20689_TEMP_OUT_L_MASK_TEMP_OUT                (0XFF)

/* GYRO_XOUT_H bit fields*/
#define ICM20689_REG_GYRO_XOUT_H                         (0X43)

#define ICM20689_GYRO_XOUT_H_SHIFT_GYRO_XOUT             (0X00)

#define ICM20689_GYRO_XOUT_H_MASK_GYRO_XOUT              (0XFF)

/* GYRO_XOUT_L bit fields*/
#define ICM20689_REG_GYRO_XOUT_L                         (0X44)

#define ICM20689_GYRO_XOUT_L_SHIFT_GYRO_XOUT             (0X00)

#define ICM20689_GYRO_XOUT_L_MASK_GYRO_XOUT              (0XFF)

/* GYRO_YOUT_H bit fields*/
#define ICM20689_REG_GYRO_YOUT_H                         (0X45)

#define ICM20689_GYRO_YOUT_H_SHIFT_GYRO_YOUT             (0X00)

#define ICM20689_GYRO_YOUT_H_MASK_GYRO_YOUT              (0XFF)

/* GYRO_YOUT_L bit fields*/
#define ICM20689_REG_GYRO_YOUT_L                         (0X46)

#define ICM20689_GYRO_YOUT_L_SHIFT_GYRO_YOUT             (0X00)

#define ICM20689_GYRO_YOUT_L_MASK_GYRO_YOUT              (0XFF)

/* GYRO_ZOUT_H bit fields*/
#define ICM20689_REG_GYRO_ZOUT_H                         (0X47)

#define ICM20689_GYRO_ZOUT_H_SHIFT_GYRO_ZOUT             (0X00)

#define ICM20689_GYRO_ZOUT_H_MASK_GYRO_ZOUT              (0XFF)

/* GYRO_ZOUT_L bit fields*/
#define ICM20689_REG_GYRO_ZOUT_L                         (0X48)

#define ICM20689_GYRO_ZOUT_L_SHIFT_GYRO_ZOUT             (0X00)

#define ICM20689_GYRO_ZOUT_L_MASK_GYRO_ZOUT              (0XFF)

/* SIGNAL_PATH_RESET bit fields*/
#define ICM20689_REG_SIGNAL_PATH_RESET                   (0X68)

#define ICM20689_SIGNAL_PATH_RESET_SHIFT_TEMP_RST        (0X00)
#define ICM20689_SIGNAL_PATH_RESET_SHIFT_ACCEL_RST       (0X01)

#define ICM20689_SIGNAL_PATH_RESET_MASK_TEMP_RST         (0X01)
#define ICM20689_SIGNAL_PATH_RESET_MASK_ACCEL_RST        (0X02)

#define ICM20689_SIGNAL_PATH_RESET_BIT_TEMP_RST          (0X01)
#define ICM20689_SIGNAL_PATH_RESET_BIT_ACCEL_RST         (0X02)

/* ACCEL_INTEL_CTRL bit fields*/
#define ICM20689_REG_ACCEL_INTEL_CTRL                    (0X69)

#define ICM20689_ACCEL_INTEL_CTRL_SHIFT_ACCEL_INTEL_MODE (0X06)
#define ICM20689_ACCEL_INTEL_CTRL_SHIFT_ACCEL_INTEL_EN   (0X07)

#define ICM20689_ACCEL_INTEL_CTRL_MASK_ACCEL_INTEL_MODE  (0X40)
#define ICM20689_ACCEL_INTEL_CTRL_MASK_ACCEL_INTEL_EN    (0X80)

#define ICM20689_ACCEL_INTEL_CTRL_BIT_ACCEL_INTEL_MODE   (0X40)
#define ICM20689_ACCEL_INTEL_CTRL_BIT_ACCEL_INTEL_EN     (0X80)

/* USER_CTRL bit fields*/
#define ICM20689_REG_USER_CTRL                           (0X6A)

#define ICM20689_USER_CTRL_SHIFT_SIG_COND_RST            (0X00)
#define ICM20689_USER_CTRL_SHIFT_FIFO_RST                (0X02)
#define ICM20689_USER_CTRL_SHIFT_DMP_RST                 (0X03)
#define ICM20689_USER_CTRL_SHIFT_I2C_IF_DIS              (0X04)
#define ICM20689_USER_CTRL_SHIFT_FIFO_EN                 (0X06)
#define ICM20689_USER_CTRL_SHIFT_DMP_EN                  (0X07)

#define ICM20689_USER_CTRL_MASK_SIG_COND_RST             (0X01)
#define ICM20689_USER_CTRL_MASK_FIFO_RST                 (0X04)
#define ICM20689_USER_CTRL_MASK_DMP_RST                  (0X08)
#define ICM20689_USER_CTRL_MASK_I2C_IF_DIS               (0X10)
#define ICM20689_USER_CTRL_MASK_FIFO_EN                  (0X40)
#define ICM20689_USER_CTRL_MASK_DMP_EN                   (0X80)

#define ICM20689_USER_CTRL_BIT_SIG_COND_RST              (0X01)
#define ICM20689_USER_CTRL_BIT_FIFO_RST                  (0X04)
#define ICM20689_USER_CTRL_BIT_DMP_RST                   (0X08)
#define ICM20689_USER_CTRL_BIT_I2C_IF_DIS                (0X10)
#define ICM20689_USER_CTRL_BIT_FIFO_EN                   (0X40)
#define ICM20689_USER_CTRL_BIT_DMP_EN                    (0X80)

/* PWR_MGMT_1 bit fields*/
#define ICM20689_REG_PWR_MGMT_1                          (0X6B)

#define ICM20689_PWR_MGMT_1_SHIFT_CLKSEL                 (0X00)
#define ICM20689_PWR_MGMT_1_SHIFT_TEMP_DIS               (0X03)
#define ICM20689_PWR_MGMT_1_SHIFT_GYRO_STANDBY           (0X04)
#define ICM20689_PWR_MGMT_1_SHIFT_ACCEL_CYCLE            (0X05)
#define ICM20689_PWR_MGMT_1_SHIFT_SLEEP                  (0X06)
#define ICM20689_PWR_MGMT_1_SHIFT_DEVICE_RESET           (0X07)

#define ICM20689_PWR_MGMT_1_MASK_CLKSEL                  (0X07)
#define ICM20689_PWR_MGMT_1_MASK_TEMP_DIS                (0X08)
#define ICM20689_PWR_MGMT_1_MASK_GYRO_STANDBY            (0X10)
#define ICM20689_PWR_MGMT_1_MASK_ACCEL_CYCLE             (0X20)
#define ICM20689_PWR_MGMT_1_MASK_SLEEP                   (0X40)
#define ICM20689_PWR_MGMT_1_MASK_DEVICE_RESET            (0X80)

#define ICM20689_PWR_MGMT_1_BIT_TEMP_DIS                 (0X08)
#define ICM20689_PWR_MGMT_1_BIT_GYRO_STANDBY             (0X10)
#define ICM20689_PWR_MGMT_1_BIT_ACCEL_CYCLE              (0X20)
#define ICM20689_PWR_MGMT_1_BIT_SLEEP                    (0X40)
#define ICM20689_PWR_MGMT_1_BIT_DEVICE_RESET             (0X80)

#define _ICM20689_PWR_MGMT_1_CLKSEL_INTERNAL_OSC_0       (0X00)
#define _ICM20689_PWR_MGMT_1_CLKSEL_AUTOSEL_0            (0X01)
#define _ICM20689_PWR_MGMT_1_CLKSEL_AUTOSEL_1            (0X02)
#define _ICM20689_PWR_MGMT_1_CLKSEL_AUTOSEL_2            (0X03)
#define _ICM20689_PWR_MGMT_1_CLKSEL_AUTOSEL_3            (0X04)
#define _ICM20689_PWR_MGMT_1_CLKSEL_AUTOSEL_4            (0X05)
#define _ICM20689_PWR_MGMT_1_CLKSEL_INTERNAL_OSC_1       (0X06)
#define _ICM20689_PWR_MGMT_1_CLKSEL_STOPPED              (0X07)
#define ICM20689_PWR_MGMT_1_CLKSEL_INTERNAL_OSC_0        (0X00 << \
                                                          ICM20689_PWR_MGMT_1_SHIFT_CLKSEL)
#define ICM20689_PWR_MGMT_1_CLKSEL_AUTOSEL_0             (0X01 << \
                                                          ICM20689_PWR_MGMT_1_SHIFT_CLKSEL)
#define ICM20689_PWR_MGMT_1_CLKSEL_AUTOSEL_1             (0X02 << \
                                                          ICM20689_PWR_MGMT_1_SHIFT_CLKSEL)
#define ICM20689_PWR_MGMT_1_CLKSEL_AUTOSEL_2             (0X03 << \
                                                          ICM20689_PWR_MGMT_1_SHIFT_CLKSEL)
#define ICM20689_PWR_MGMT_1_CLKSEL_AUTOSEL_3             (0X04 << \
                                                          ICM20689_PWR_MGMT_1_SHIFT_CLKSEL)
#define ICM20689_PWR_MGMT_1_CLKSEL_AUTOSEL_4             (0X05 << \
                                                          ICM20689_PWR_MGMT_1_SHIFT_CLKSEL)
#define ICM20689_PWR_MGMT_1_CLKSEL_INTERNAL_OSC_1        (0X06 << \
                                                          ICM20689_PWR_MGMT_1_SHIFT_CLKSEL)
#define ICM20689_PWR_MGMT_1_CLKSEL_STOPPED               (0X07 << \
                                                          ICM20689_PWR_MGMT_1_SHIFT_CLKSEL)

/* PWR_MGMT_2 bit fields*/
#define ICM20689_REG_PWR_MGMT_2                          (0X6C)

#define ICM20689_PWR_MGMT_2_SHIFT_STBY_ZG                (0X00)
#define ICM20689_PWR_MGMT_2_SHIFT_STBY_YG                (0X01)
#define ICM20689_PWR_MGMT_2_SHIFT_STBY_XG                (0X02)
#define ICM20689_PWR_MGMT_2_SHIFT_STBY_ZA                (0X03)
#define ICM20689_PWR_MGMT_2_SHIFT_STBY_YA                (0X04)
#define ICM20689_PWR_MGMT_2_SHIFT_STBY_XA                (0X05)
#define ICM20689_PWR_MGMT_2_SHIFT_DMP_LP_DIS             (0X06)
#define ICM20689_PWR_MGMT_2_SHIFT_FIFO_LP_EN             (0X07)

#define ICM20689_PWR_MGMT_2_MASK_STBY_ZG                 (0X01)
#define ICM20689_PWR_MGMT_2_MASK_STBY_YG                 (0X02)
#define ICM20689_PWR_MGMT_2_MASK_STBY_XG                 (0X04)
#define ICM20689_PWR_MGMT_2_MASK_STBY_ZA                 (0X08)
#define ICM20689_PWR_MGMT_2_MASK_STBY_YA                 (0X10)
#define ICM20689_PWR_MGMT_2_MASK_STBY_XA                 (0X20)
#define ICM20689_PWR_MGMT_2_MASK_DMP_LP_DIS              (0X40)
#define ICM20689_PWR_MGMT_2_MASK_FIFO_LP_EN              (0X80)

#define ICM20689_PWR_MGMT_2_BIT_STBY_ZG                  (0X01)
#define ICM20689_PWR_MGMT_2_BIT_STBY_YG                  (0X02)
#define ICM20689_PWR_MGMT_2_BIT_STBY_XG                  (0X04)
#define ICM20689_PWR_MGMT_2_BIT_STBY_ZA                  (0X08)
#define ICM20689_PWR_MGMT_2_BIT_STBY_YA                  (0X10)
#define ICM20689_PWR_MGMT_2_BIT_STBY_XA                  (0X20)
#define ICM20689_PWR_MGMT_2_BIT_DMP_LP_DIS               (0X40)
#define ICM20689_PWR_MGMT_2_BIT_FIFO_LP_EN               (0X80)

/* FIFO_COUNTH bit fields*/
#define ICM20689_REG_FIFO_COUNTH                         (0X72)

#define ICM20689_FIFO_COUNTH_SHIFT_FIFO_COUNT            (0X00)

#define ICM20689_FIFO_COUNTH_MASK_FIFO_COUNT             (0X1F)

/* FIFO_COUNTL bit fields*/
#define ICM20689_REG_FIFO_COUNTL                         (0X73)

#define ICM20689_FIFO_COUNTL_SHIFT_FIFO_COUNT            (0X00)

#define ICM20689_FIFO_COUNTL_MASK_FIFO_COUNT             (0XFF)

/* FIFO_R_W bit fields*/
#define ICM20689_REG_FIFO_R_W                            (0X74)

#define ICM20689_FIFO_R_W_SHIFT_FIFO_DATA                (0X00)

#define ICM20689_FIFO_R_W_MASK_FIFO_DATA                 (0XFF)

/* WHO_AM_I bit fields*/
#define ICM20689_REG_WHO_AM_I                            (0X75)

#define ICM20689_WHO_AM_I_SHIFT_WHOAMI                   (0X00)

#define ICM20689_WHO_AM_I_MASK_WHOAMI                    (0XFF)

/* XA_OFFSET_H bit fields*/
#define ICM20689_REG_XA_OFFSET_H                         (0X77)

#define ICM20689_XA_OFFSET_H_SHIFT_WHOAMI                (0X00)

#define ICM20689_XA_OFFSET_H_MASK_WHOAMI                 (0XFF)

/* XA_OFFSET_L bit fields*/
#define ICM20689_REG_XA_OFFSET_L                         (0X78)

#define ICM20689_XA_OFFSET_L_SHIFT_WHOAMI                (0X00)

#define ICM20689_XA_OFFSET_L_MASK_WHOAMI                 (0XFF)

/* YA_OFFSET_H bit fields*/
#define ICM20689_REG_YA_OFFSET_H                         (0X7A)

#define ICM20689_YA_OFFSET_H_SHIFT_WHOAMI                (0X00)

#define ICM20689_YA_OFFSET_H_MASK_WHOAMI                 (0XFF)

/* YA_OFFSET_L bit fields*/
#define ICM20689_REG_YA_OFFSET_L                         (0X7B)

#define ICM20689_YA_OFFSET_L_SHIFT_WHOAMI                (0X00)

#define ICM20689_YA_OFFSET_L_MASK_WHOAMI                 (0XFF)

/* ZA_OFFSET_H bit fields*/
#define ICM20689_REG_ZA_OFFSET_H                         (0X7D)

#define ICM20689_ZA_OFFSET_H_SHIFT_WHOAMI                (0X00)

#define ICM20689_ZA_OFFSET_H_MASK_WHOAMI                 (0XFF)

/* ZA_OFFSET_L bit fields*/
#define ICM20689_REG_ZA_OFFSET_L                         (0X7E)

#define ICM20689_ZA_OFFSET_L_SHIFT_WHOAMI                (0X00)

#define ICM20689_ZA_OFFSET_L_MASK_WHOAMI                 (0XFF)

#define MIN_ACCEL_SENS_SHIFT                             11

#ifdef __cplusplus
}
#endif

/** @endcond */
#endif // ICM42670_REG_H
