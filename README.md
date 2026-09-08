# GH3026 心率传感器测试样例（nRF52832）

基于 Nordic nRF5 SDK 的 GH3026 心率传感器最小测试代码，目标芯片为 **nRF52832**。当前只做了 **2 个最基本操作**：通过软 I2C 读取指定寄存器 ID。

> 说明：代码中复位脚宏名为 `GH3220_RESET_PIN`，I2C 函数名仍沿用 `*_pcf8563`，实际用于 GH3026 板级联调。

---

## 功能概览

| 步骤 | 操作 | 说明 |
|------|------|------|
| 1 | 芯片复位 | `GH3220_RESET_PIN` 拉低 → 延时 → 拉高 |
| 2 | I2C 初始化 | 配置 SCL / SDA 为输出并置空闲高电平 |
| 3 | 读寄存器 `0x0030` | 设备地址 `0x28`，连续读 2 字节 |
| 4 | 读寄存器 `0x0032` | 设备地址 `0x28`，连续读 2 字节 |
| 5 | 日志输出 | RTT `NRF_LOG_HEXDUMP_INFO` 打印上述 4 字节 |

---

## 硬件平台

| 项目 | 说明 |
|------|------|
| MCU | nRF52832 |
| 推荐工程 | `pca10040/blank`（GCC，无 SoftDevice） |
| SDK | nRF5 SDK **15.3.0** |
| SoftDevice（原厂配套） | S132 **6.1.1**（当前探针固件默认不烧） |
| 日志 | SEGGER RTT |

---

## 硬件连接

| 信号 | GPIO | 宏定义 | 备注 |
|------|------|--------|------|
| I2C SDA | P30 | `IIC_SDA_PCF8563` | 软 I2C 数据线 |
| I2C SCL | P29 | `IIC_SCL_PCF8563` | 软 I2C 时钟线 |
| RESET | P22 | `GH3220_RESET_PIN` | 传感器复位脚 |

I2C 从机写地址：`0x28`（读地址为 `0x29`，由 `DeviceAddress + 1` 完成）。

---

## 编译环境（推荐）

本仓库默认使用 **nRF5 SDK 15.3.0**（与原 holyuart / SoftDevice **S132 6.1.1** 配套）。

### 依赖

1. **arm-none-eabi-gcc**  
   ```bash
   brew install --cask gcc-arm-embedded
   ```

2. **nRF5 SDK 15.3.0**（默认路径）  
   ```text
   ~/.nRF5_SDK/nRF5_SDK_15.3.0_59ac345
   ```

3. **烧录工具**：`nrfjprog`（[nRF Command Line Tools](https://www.nordicsemi.com/Products/Development-tools/nRF-Command-Line-Tools)）或 `nrfutil device`  
4. **调试器**：J-Link / 板载 SWD（设备识别为 nRF52832）

### 编译

```bash
cd /path/to/ble_app_uart-21043-holyuart-1.0
make
```

产物：

```text
pca10040/blank/armgcc/_build/nrf52832_xxaa.hex
```

---

## 烧录

### SoftDevice 文件位置

| 项目 | 值 |
|------|-----|
| 型号 / 版本 | **S132 6.1.1** |
| 默认路径 | `~/.nRF5_SDK/nRF5_SDK_15.3.0_59ac345/components/softdevice/s132/hex/s132_nrf52_6.1.1_softdevice.hex` |

可用环境变量覆盖 SDK 根目录：`SDK_ROOT=...`

### 前置条件

- 板子通过 SWD 连上电脑  
- 终端可执行 `nrfjprog`  
- 烧应用前需先 `make` 生成 hex（仅烧 SoftDevice 时可不编译应用）

检查连接：

```bash
nrfjprog -f nrf52 --ids
```

---

### 方式 A：只烧 SoftDevice（S132 6.1.1）

```bash
make flash_softdevice
# 或
./flash_softdevice.sh
```

等价命令：

```bash
nrfjprog -f nrf52 --eraseall
nrfjprog -f nrf52 --program ~/.nRF5_SDK/nRF5_SDK_15.3.0_59ac345/components/softdevice/s132/hex/s132_nrf52_6.1.1_softdevice.hex --verify
nrfjprog -f nrf52 --reset
```

---

### 方式 B：SoftDevice + 应用（原 holyuart 烧录顺序）

适用于按 SoftDevice 布局链接的应用（App 起始约 **`0x26000`**），与原厂脚本一致：

```bash
nrfjprog -f nrf52 --eraseall
nrfjprog -f nrf52 --program s132_nrf52_6.1.1_softdevice.hex --verify
nrfjprog -f nrf52 --program nrf52832_xxaa_app.hex --verify
nrfjprog -f nrf52 --reset
```

仓库内一键脚本（可传入 app hex 路径）：

```bash
./flash_sd.sh /path/to/nrf52832_xxaa_app.hex
# 或使用默认 blank 产物路径（仅当该 hex 确为 SoftDevice 布局时再用）：
make flash_sd
```

| 步骤 | 作用 |
|------|------|
| 1. `--eraseall` | 整片擦除 |
| 2. 烧 SoftDevice | 写入 S132 6.1.1 |
| 3. 烧 App | 写入应用固件 |
| 4. `--reset` | 复位运行 |

---

### 方式 C：只烧应用（当前 GH3026 探针固件，推荐联调传感器时用）

当前仓库默认编译出的探针固件链接在 Flash **`0x00000000`**，**与 SoftDevice 互斥**，不要先烧 SoftDevice。

```bash
make          # 先编译
make flash
# 或
./flash.sh
```

等价命令：

```bash
nrfjprog -f nrf52 --eraseall
nrfjprog -f nrf52 --program pca10040/blank/armgcc/_build/nrf52832_xxaa.hex --verify
nrfjprog -f nrf52 --reset
```

产物路径：`pca10040/blank/armgcc/_build/nrf52832_xxaa.hex`

仅擦除：

```bash
make erase
```

---

### 怎么选

| 场景 | 用哪种 |
|------|--------|
| 只想写入 SoftDevice | **方式 A** |
| 跑原 holyuart / SoftDevice 布局的 App | **方式 B** |
| 跑本仓库当前 GH3026 寄存器探针 | **方式 C**（不要烧 SoftDevice） |

---

### 烧录后看日志（探针固件）

1. 保持 SWD 连接  
2. 打开 **J-Link RTT Viewer**（Device: `NRF52832_XXAA`，Interface: SWD）  
3. 复位后应看到寄存器 dump

### 常见问题

| 现象 | 处理 |
|------|------|
| `nrfjprog` 找不到设备 | 检查 USB/SWD；试 `nrfjprog --recover -f nrf52` |
| SoftDevice + 探针固件一起烧后异常 / RTT 连不上 | 探针在 `0x00000`，会被 SoftDevice 盖住。请改用 **方式 C**：`./flash.sh`（先 `eraseall` 再只烧 app） |
| RTT Viewer 无法连接 | 见下方「RTT Viewer 设置」 |
| 读寄存器全 `FF` | 多为 I2C/供电/复位问题，与烧录分开排查 |

### RTT Viewer 设置

1. **先关掉**占用 J-Link 的其它程序（再开的 RTT Viewer、Ozone、`nrfjprog` 会话等）  
2. 确认已用 `./flash.sh` 烧录成功（不要用 `./flash_sd.sh` 烧当前探针）  
3. 打开 **J-Link RTT Viewer**，连接参数：

| 项 | 值 |
|----|-----|
| Device | `NRF52832_XXAA` |
| Interface | `SWD` |
| Speed | `4000 kHz`（或 Auto） |
| RTT Control Block | 可选填 `0x20000828`（本固件 `_SEGGER_RTT` 地址；也可选 Search） |

4. Connect 成功后，对板子 **Reset**（RTT Viewer 里点 Reset，或 `nrfjprog -f nrf52 --reset`）  
5. 终端里应出现 `GH3026 basic register read test start` 和 hex dump  

命令行也可用：

```bash
JLinkRTTClient
# 或
/Applications/SEGGER/JLink/JLinkRTTViewer.app/Contents/MacOS/JLinkRTTViewer
```

---

## 目录结构

```
.
├── Makefile                        # make / make flash / make flash_softdevice / make flash_sd
├── flash.sh                        # 只烧应用（当前探针，无 SoftDevice）
├── flash_softdevice.sh             # 只烧 SoftDevice S132 6.1.1
├── flash_sd.sh                     # SoftDevice + App（原 holyuart 顺序）
├── main.c                          # GH3026 复位与读寄存器测试
├── i2c.c / i2c.h                   # 软件模拟 I2C
└── pca10040/
    ├── blank/                      # ★ 当前推荐：GCC 无 SoftDevice 工程
    │   ├── armgcc/Makefile
    │   └── config/sdk_config.h
    ├── s132/                       # 历史 Keil / SoftDevice 工程（可忽略）
    └── s112/
```

---

## I2C 接口说明

实现方式为 **GPIO 位带软 I2C**（非 TWI 硬件外设），位间隔约 `2 µs`（`I2Cdelay()`）。

### 连续读（本样例使用）

```c
uint8_t I2CReadSerial_pcf8563(
    uint8_t DeviceAddress,  // 写地址，如 0x28
    uint16_t Address,       // 16 位寄存器地址
    uint8_t *ps,            // 读出缓冲
    uint8_t length          // 字节数
);
```

时序概要：

1. START → 发送写地址  
2. 发送寄存器地址高字节、低字节  
3. 重复 START → 发送读地址（写地址 + 1）  
4. 连续接收 `length` 字节（末字节 NACK）→ STOP  

### 连续写（已实现，样例未调用）

```c
uint8_t I2CWriteSerial_pcf8563(
    uint8_t DeviceAddress,
    uint16_t Address,
    uint8_t *ps,
    uint8_t length
);
```

---

## 测试流程（`main.c`）

上电后自动执行复位 → I2C 初始化 → 读 `0x0030` / `0x0032` → RTT 打印 4 字节。

| 缓冲 | 内容 |
|------|------|
| `m_reg_buf[0..1]` | 寄存器 `0x0030` |
| `m_reg_buf[2..3]` | 寄存器 `0x0032` |

---

## 当前范围

**已有：** 软 I2C、复位时序、指定寄存器读取、GCC 一键编译  

**未包含：** 完整初始化表、PPG/心率数据流、算法库、宏命名整理（`pcf8563` / `GH3220` → `GH3026`）

---

## 许可证

底层工程源自 Nordic Semiconductor ASA 示例代码，详见各源文件头部版权声明。
