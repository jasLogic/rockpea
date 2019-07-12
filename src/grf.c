/*
 * grf.c
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

#include <stdint.h>

#include "grf.h"
#include "peripheral.h"

static const size_t GRF_OFFSET = 0xFF770000;
static const size_t GRF_SIZE = 0xF7A4;

static const size_t PMUGRF_OFFSET = 0xFF320000;
static const size_t PMUGRF_SIZE = 0x310;

static volatile uint32_t *grf_base_ptr = NULL;
volatile struct grf_register_map *GRF = NULL;

static volatile uint32_t *pmugrf_base_ptr = NULL;
volatile struct pmugrf_register_map *PMUGRF = NULL;

int pmugrf_map(void)
{
    if (peripheral_map(&pmugrf_base_ptr, PMUGRF_OFFSET, PMUGRF_SIZE) < 0)
        return -1;
    PMUGRF = (volatile struct pmugrf_register_map *)pmugrf_base_ptr;
    return 0;
}
void pmugrf_unmap(void)
{
    peripheral_unmap(pmugrf_base_ptr, PMUGRF_SIZE);
}
