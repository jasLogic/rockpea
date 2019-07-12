/*
 * grf.h
 * Copyright (C) 2019  jasLogic
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef _GRF_H
#define _GRF_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif//__cplusplus

#define TOKENPASTE(x, y)    x##y
#define TOKENPASTE2(x, y)   TOKENPASTE(x, y)
#define RESERVED(n) uint32_t TOKENPASTE2(reserved, __COUNTER__)[n]

struct grf_register_map {
    uint32_t USB3_PERF_CON0; // 0x2000
    uint32_t USB3_PERF_CON1;
    uint32_t USB3_PERF_CON2;
    uint32_t USB3_PERF_RD_MAX_LATENCY_NUM;
    uint32_t USB3_PERF_RD_LATENCY_SAMP_NUM; // 0x2010
    uint32_t USB3_PERF_RD_LATENCY_ACC_NUM;
    uint32_t USB3_PERF_RD_AXI_TOTAL_BYTE;
    uint32_t USB3_PERF_WR_AXI_TOTAL_BYTE;
    uint32_t USB3_PERF_WORKING_CNT; // 0x2020
    uint32_t: 32;
    uint32_t: 32;
    uint32_t: 32;

    RESERVED(0x100); // 0x2030 ... 0x242c

    uint32_t USB3OTG0_CON0; // 0x2430
    uint32_t USB3OTG0_CON1;
    uint32_t: 32;
    uint32_t: 32;
    uint32_t USB3OTG1_CON0; // 0x2440
    uint32_t USB3OTG1_CON1;
    uint32_t: 32;
    uint32_t: 32;
    uint32_t USB3OTG0_STATUS_LAT0; // 0x2450
    uint32_t USB3OTG0_STATUS_LAT1;
    uint32_t USB3OTG0_STATUS_CB;
    uint32_t: 32;
    uint32_t USB3OTG1_STATUS_LAT0; // 0x2460
    uint32_t USB3OTG1_STATUS_LAT1;
    uint32_t USB3OTG1_STATUS_CB;
    uint32_t: 32;

    RESERVED(0x6e4); // 0x2470 ... 0x3ffc

    uint32_t PCIE_PERF_CON0; // 0x4000
    uint32_t PCIE_PERF_CON1;
    uint32_t PCIE_PERF_CON2;
    uint32_t PCIE_PERF_RD_MAX_LATENCY_NUM;
    uint32_t PCIE_PERF_RD_LATENCY_SAMP_NUM; // 0x4010
    uint32_t PCIE_PERF_RD_LATENCY_ACC_NUM;
    uint32_t PCIE_PERF_RD_AXI_TOTAL_BYTE;
    uint32_t PCIE_PERF_WR_AXI_TOTAL_BYTE;
    uint32_t PCIE_PERF_WORKING_CNT; // 0x4020
    uint32_t: 32;
    uint32_t: 32;
    uint32_t: 32;

    RESERVED(0x34); // 0x4030 ... 0x40fc

    uint32_t USB20_HOST0_CON0; // 0x4100
    uint32_t USB20_HOST0_CON1;
    uint32_t: 32;
    uint32_t: 32;
    uint32_t USB20_HOST1_CON0; // 0x4110
    uint32_t USB20_HOST1_CON1;
    uint32_t: 32;
    uint32_t: 32;
    uint32_t HSIC_CON0; // 0x4120
    uint32_t HSIC_CON1;
    uint32_t: 32;
    uint32_t: 32;
    uint32_t: 32; // 0x4130
    uint32_t: 32;
    uint32_t: 32;
    uint32_t: 32;
    uint32_t USBHOST0_STATUS; // 0x4140
    uint32_t USBHOST1_STATUS;
    uint32_t HSIC_STATUS;
    uint32_t: 32;

    RESERVED(0xc8); // 0x4150 ... 0x446c

    uint32_t HSICPHY_CON0; // 0x4470
    uint32_t: 32;
    uint32_t: 32;
    uint32_t: 32;
    uint32_t usbphy0_ctrl0; // 0x4480
    uint32_t usbphy0_ctrl1;
    uint32_t usbphy0_ctrl2;
    uint32_t usbphy0_ctrl3;
    uint32_t usbphy0_ctrl4; // 0x4490
    uint32_t usbphy0_ctrl5;
    uint32_t usbphy0_ctrl6;
    uint32_t usbphy0_ctrl7;
    uint32_t usbphy0_ctrl8; // 0x44a0
    uint32_t usbphy0_ctrl9;
    uint32_t usbphy0_ctrl10;
    uint32_t usbphy0_ctrl11;
    uint32_t usbphy0_ctrl12; // 0x44b0
    uint32_t usbphy0_ctrl13;
    uint32_t usbphy0_ctrl14;
    uint32_t usbphy0_ctrl15;
    uint32_t usbphy0_ctrl16; // 0x44c0
    uint32_t usbphy0_ctrl17;
    uint32_t usbphy0_ctrl18;
    uint32_t usbphy0_ctrl19;
    uint32_t usbphy0_ctrl20; // 0x44d0
    uint32_t usbphy0_ctrl21;
    uint32_t usbphy0_ctrl22;
    uint32_t usbphy0_ctrl23;
    uint32_t usbphy0_ctrl24; // 0x44e0
    uint32_t usbphy0_ctrl25;
    uint32_t: 32;
    uint32_t: 32;
    uint32_t: 32; // 0x44f0
    uint32_t: 32;
    uint32_t: 32;
    uint32_t: 32;
    uint32_t usbphy1_ctrl0; // 0x4500
    uint32_t usbphy1_ctrl1;
    uint32_t usbphy1_ctrl2;
    uint32_t usbphy1_ctrl3;
    uint32_t usbphy1_ctrl4; // 0x4510
    uint32_t usbphy1_ctrl5;
    uint32_t usbphy1_ctrl6;
    uint32_t usbphy1_ctrl7;
    uint32_t usbphy1_ctrl8; // 0x4520
    uint32_t usbphy1_ctrl9;
    uint32_t usbphy1_ctrl10;
    uint32_t usbphy1_ctrl11;
    uint32_t usbphy1_ctrl12; // 0x4530
    uint32_t usbphy1_ctrl13;
    uint32_t usbphy1_ctrl14;
    uint32_t usbphy1_ctrl15;
    uint32_t usbphy1_ctrl16; // 0x4540
    uint32_t usbphy1_ctrl17;
    uint32_t usbphy1_ctrl18;
    uint32_t usbphy1_ctrl19;
    uint32_t usbphy1_ctrl20; // 0x4550
    uint32_t usbphy1_ctrl21;
    uint32_t usbphy1_ctrl22;
    uint32_t usbphy1_ctrl23;
    uint32_t usbphy1_ctrl24; // 0x4560
    uint32_t usbphy1_ctrl25;
    uint32_t: 32;
    uint32_t: 32;

    RESERVED(0x6a4); // 0x4570 ... 0x5ffc

    uint32_t HDCP22_PERF_CON0; // 0x6000
    uint32_t HDCP22_PERF_CON1;
    uint32_t HDCP22_PERF_CON2;
    uint32_t HDCP22_PERF_RD_MAX_LATENCY_NUM;
    uint32_t HDCP22_PERF_RD_LATENCY_SAMP_NUM; // 0x6010
    uint32_t HDCP22_PERF_RD_LATENCY_ACC_NUM;
    uint32_t HDCP22_PERF_RD_AXI_TOTAL_BYTE;
    uint32_t HDCP22_PERF_WR_AXI_TOTAL_BYTE;
    uint32_t HDCP22_PERF_WORKING_CNT; // 0x6020
    uint32_t: 32;
    uint32_t: 32;
    uint32_t: 32;

    RESERVED(0x7c); // 0x6030 ... 0x621c

    uint32_t: 32; // 0x6220
    uint32_t SOC_CON9;
    uint32_t: 32;
    uint32_t: 32;

    RESERVED(0x8); // 0x6230 ... 0x624c

    uint32_t SOC_CON20; // 0x6250
    uint32_t SOC_CON21;
    uint32_t SOC_CON22;
    uint32_t SOC_CON23;
    uint32_t SOC_CON24; // 0x6260
    uint32_t SOC_CON25;
    uint32_t SOC_CON26;
    uint32_t: 32;

    RESERVED(0x764); // 0x6270 ... 0x7ffc

    uint32_t GPU_PERF_CON0; // 0x8000
    uint32_t GPU_PERF_CON1;
    uint32_t GPU_PERF_CON2;
    uint32_t GPU_PERF_RD_MAX_LATENCY_NUM;
    uint32_t GPU_PERF_RD_LATENCY_SAMP_NUM; // 0x8010
    uint32_t GPU_PERF_RD_LATENCY_ACC_NUM;
    uint32_t GPU_PERF_RD_AXI_TOTAL_BYTE;
    uint32_t GPU_PERF_WR_AXI_TOTAL_BYTE;
    uint32_t GPU_PERF_WORKING_CNT; // 0x8020
    uint32_t: 32;
    uint32_t: 32;
    uint32_t: 32;

    RESERVED(0x7f4); // 0x8030 ... 0x9ffc

    uint32_t CPU_CON0; // 0xa000
    uint32_t CPU_CON1;
    uint32_t CPU_CON2;
    uint32_t CPU_CON3;

    RESERVED(0x1c); // 0xa010 ... 0xa07c

    uint32_t CPU_STATUS0; // 0xa080
    uint32_t CPU_STATUS1;
    uint32_t CPU_STATUS2;
    uint32_t CPU_STATUS3;
    uint32_t CPU_STATUS4; // 0xa090
    uint32_t CPU_STATUS5;
    uint32_t: 32;
    uint32_t: 32;

    RESERVED(0x18); // 0xa0a0 ... 0xa0fc

    uint32_t A53_PERF_CON0; // 0xa100
    uint32_t A53_PERF_CON1;
    uint32_t A53_PERF_CON2;
    uint32_t A53_PERF_CON3;
    uint32_t A53_PERF_RD_MON_ST; // 0xa110
    uint32_t A53_PERF_RD_MON_END;
    uint32_t A53_PERF_WR_MON_ST;
    uint32_t A53_PERF_WR_MON_END;
    uint32_t A53_PERF_RD_MAX_LATENCY_NUM; // 0xa120
    uint32_t A53_PERF_RD_LATENCY_SAMP_NUM;
    uint32_t A53_PERF_RD_LATENCY_ACC_NUM;
    uint32_t A53_PERF_RD_AXI_TOTAL_BYTE;
    uint32_t A53_PERF_WR_AXI_TOTAL_BYTE; // 0xa130
    uint32_t A53_PERF_WORKING_CNT;
    uint32_t A53_PERF_INT_STATUS;
    uint32_t: 32;

    RESERVED(0x30); // 0xa140 ... 0xa1fc

    uint32_t A72_PERF_CON0; // 0xa200
    uint32_t A72_PERF_CON1;
    uint32_t A72_PERF_CON2;
    uint32_t A72_PERF_CON3;
    uint32_t A72_PERF_RD_MON_ST; // 0xa210
    uint32_t A72_PERF_RD_MON_END;
    uint32_t A72_PERF_WR_MON_ST;
    uint32_t A72_PERF_WR_MON_END;
    uint32_t A72_PERF_RD_MAX_LATENCY_NUM; // 0xa220
    uint32_t A72_PERF_RD_LATENCY_SAMP_NUM;
    uint32_t A72_PERF_RD_LATENCY_ACC_NUM;
    uint32_t A72_PERF_RD_AXI_TOTAL_BYTE;
    uint32_t A72_PERF_WR_AXI_TOTAL_BYTE; // 0xa230
    uint32_t A72_PERF_WORKING_CNT;
    uint32_t A72_PERF_INT_STATUS;
    uint32_t: 32;

    RESERVED(0x770); // 0xa240 ... 0xbffc

    uint32_t GMAC_PERF_CON0; // 0xc000
    uint32_t GMAC_PERF_CON1;
    uint32_t GMAC_PERF_CON2;
    uint32_t GMAC_PERF_RD_MAX_LATENCY_NUM;
    uint32_t GMAC_PERF_RD_LATENCY_SAMP_NUM; // 0xc010
    uint32_t GMAC_PERF_RD_LATENCY_ACC_NUM;
    uint32_t GMAC_PERF_RD_AXI_TOTAL_BYTE;
    uint32_t GMAC_PERF_WR_AXI_TOTAL_BYTE;
    uint32_t GMAC_PERF_WORKING_CNT; // 0xc020
    uint32_t: 32;
    uint32_t: 32;
    uint32_t: 32;

    RESERVED(0x78); // 0xc030 ... 0xc20c

    uint32_t: 32; // 0xc210
    uint32_t SOC_CON5;
    uint32_t SOC_CON6;
    uint32_t: 32;

    RESERVED(0x778); // 0xc220 ... 0xdffc

    uint32_t GPIO2A_IOMUX; // 0xe000
};

struct pmugrf_register_map {
    uint32_t GPIO0A_IOMUX; // 0x0
    uint32_t GPIO0B_IOMUX;
    uint32_t: 32;
    uint32_t: 32;
    uint32_t GPIO1A_IOMUX; // 0x10
    uint32_t GPIO1B_IOMUX;
    uint32_t GPIO1C_IOMUX;
    uint32_t GPIO1D_IOMUX;

    RESERVED(8); // 0x20 ... 0x30

    uint32_t GPIO0A_P; // 0x40
    uint32_t GPIO0B_P;
    uint32_t: 32;
    uint32_t: 32;
    uint32_t GPIO1A_P; // 0x50
    uint32_t GPIO1B_P;
    uint32_t GPIO1C_P;
    uint32_t GPIO1D_P;

    RESERVED(8); // 0x60 ... 0x70

    uint32_t GPIO0A_E; // 0x80
    uint32_t: 32;
    uint32_t GPIO0B_E;
    uint32_t: 32;
    uint32_t: 32; // 0x90
    uint32_t: 32;
    uint32_t: 32;
    uint32_t: 32;
    uint32_t GPIO1A_E; // 0xa0
    uint32_t: 32;
    uint32_t GPIO1B_E;
    uint32_t: 32;
    uint32_t GPIO1C_E; // 0xb0
    uint32_t: 32;
    uint32_t GPIO1D_E;
    uint32_t: 32;

    RESERVED(16); // 0xc0 ... 0xf0

    uint32_t GPIO0L_SR; // 0x100
    uint32_t: 32;
    uint32_t GPIO1L_SR;
    uint32_t GPIO1H_SR;
    uint32_t: 32; // 0x110
    uint32_t: 32;
    uint32_t: 32;
    uint32_t: 32;
    uint32_t GPIO0A_SMT; // 0x120
    uint32_t GPIO0B_SMT;
    uint32_t: 32;
    uint32_t: 32;
    uint32_t GPIO1A_SMT; // 0x130
    uint32_t GPIO1B_SMT;
    uint32_t GPIO1C_SMT;
    uint32_t GPIO1D_SMT;

    RESERVED(8); // 0x140 ... 0x150

    uint32_t GPIO0L_HE; // 0x160
    uint32_t: 32;
    uint32_t: 32;
    uint32_t: 32;
    uint32_t: 32; // 0x170
    uint32_t: 32;
    uint32_t: 32;
    uint32_t: 32;
    uint32_t SOC_CON0; // 0x180
    uint32_t: 32;
    uint32_t: 32;
    uint32_t: 32;
    uint32_t: 32; // 0x190
    uint32_t: 32;
    uint32_t: 32;
    uint32_t: 32;
    uint32_t: 32; // 0x1a0
    uint32_t: 32;
    uint32_t SOC_CON10;
    uint32_t SOC_CON11;

    RESERVED(36); // 0x1b0 ... 0x230

    uint32_t PMUPVTM_CON0; // 0x240
    uint32_t PMUPVTM_CON1;
    uint32_t PMUPVTM_STATUS0;
    uint32_t PMUPVTM_STATUS1;
    uint32_t OSC_E; // 0x250
    uint32_t: 32;
    uint32_t: 32;
    uint32_t: 32;

    RESERVED(40); // 0x260 ... 0x2f0

    uint32_t OS_REG0; // 0x300
    uint32_t OS_REG1;
    uint32_t OS_REG2;
    uint32_t OS_REG3;
};

#undef TOKENPASTE
#undef TOKENPASTE2
#undef RESERVED

extern volatile struct grf_register_map *GRF;
extern volatile struct pmugrf_register_map *PMUGRF;

int grf_map(void);
void grf_unmap(void);

int pmugrf_map(void);
void pmugrf_unmap(void);

#ifdef __cplusplus
}
#endif//__cplusplus

#endif//_GRF_H
