# litex_sdk
## LiteX C/C++ SDK: access LiteX SoC peripherals

This is a library to access LiteX SoC peripheral with an API and/or memory mapped CSR with a clean syntax
Example
```
  dma->LOOP = 0;
```
or usign the API:
```
litedma_writer_t *dma = litedma_writer_instance(0);
litedma_writer_set_loop(dma, 0);
```

## Fast RAM

There's a way to excute code from SRAM (block ram) and/or put data there for fast access, by just using the following macro at the function or variable definition:
```
int FAST_CODE fast_square(int x) { return x*x; } //code will be copied to SRAM at startup, with correct addresses
```
those macro just define a specific section for the code or data, handled by the combination of linker scripts and startup code
```
#define FAST_DATA __attribute__ ((section (".fast_data")))
#define FAST_CODE __attribute__ ((section (".fast_text")))
```
