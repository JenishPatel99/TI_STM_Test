Testing connection between TI TMS570LC43x (MASTER) and STM32LC0538-disco (SLAVE) via spi.
- SPI_DEMO/ : represents the TI side (.hcg file included)
- spi_interface/ : represents the STM32 side (.ioc file included)

Current issue:
- Facing issues with properly latching onto data coming from the MOSI line
