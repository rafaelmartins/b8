// SPDX-FileCopyrightText: 2024 Rafael G. Martins <rafael@rafaelmartins.eng.br>
// SPDX-License-Identifier: BSD-3-Clause

#include <stdbool.h>

#include <stm32f0xx.h>

#define BOOT_TO_DFU 0xdeadbeef


void
bootloader_entry(void)
{
    if ((RCC->CSR & RCC_CSR_SFTRSTF) == 0)
        return;

    RCC->CSR &= ~RCC_CSR_SFTRSTF;

    if (RTC->BKP0R != BOOT_TO_DFU)
        return;

    RCC->APB1ENR |= RCC_APB1ENR_PWREN;

    PWR->CR = PWR_CR_DBP;
    RTC->BKP0R = 0;
    PWR->CR = 0;

    RCC->APB1ENR &= ~RCC_APB1ENR_PWREN;

    if (FLASH->OBR & FLASH_OBR_BOOT_SEL) {
        RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
        GPIOB->MODER &= ~GPIO_MODER_MODER8;
        if ((GPIOB->IDR & GPIO_IDR_8) != 0)
            return;
        GPIOB->MODER |= GPIO_MODER_MODER8_0;
        GPIOB->BSRR = GPIO_BSRR_BS_8;
    }

    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
    SYSCFG->CFGR1 = SYSCFG_CFGR1_MEM_MODE_0;

    uint32_t bootloader_stack_pointer = *(uint32_t*)(0x1FFFC400UL);
    uint32_t bootloader_address = *(uint32_t*)(0x1FFFC404UL);

    __set_MSP(bootloader_stack_pointer);

    void (*bootloader)(void) = (void (*)(void)) bootloader_address;
    bootloader();
    while(1);
}


void
bootloader_reset(void)
{
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;

    PWR->CR = PWR_CR_DBP;
    RTC->BKP0R = BOOT_TO_DFU;
    PWR->CR = 0;

    NVIC_SystemReset();
}
