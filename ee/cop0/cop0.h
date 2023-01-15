//
// Created by Antique on 15/01/2023.
//

#ifndef EMUTWO_COP0_H
#define EMUTWO_COP0_H

#include "util/util.h"

namespace EE {
    union COP0 {
        union CAUSE {
            u32 value;

            enum ERROR_CODE : u32 {
                RESET = 0x00,
                NMI = 0x01,
                PERFORMANCE_COUNTER = 0x02,
                DEBUG = 0x03
            };

            enum EXCEPTION_CODE : u32 {
                INTERRUPT = 0x00,
                TLB_MODIFIED = 0x01,
                TLB_REFILL_FETCH = 0x02,
                TLB_REFILL_STORE = 0x03,
                ADDRESS_ERROR_FETCH = 0x04,
                ADDRESS_ERROR_STORE = 0x05,
                BUS_ERROR_INSTRUCTION = 0x06,
                BUS_ERROR_DATA = 0x07,
                SYSCALL = 0x08,
                BREAKPOINT = 0x09,
                RESERVED_INSTRUCTION = 0x0A,
                COPROCESSOR_USABILITY = 0x0B,
                OVERFLOW = 0x0C,
                TRAP = 0x0D
            };

            struct {
                EXCEPTION_CODE exception_code : 5;
                u32 intc_ip : 1;
                u32 dmac_ip : 1;
                u32 cop0_ip : 1;
                ERROR_CODE error_code : 3;
                u32 cop_cue : 2;
                u32 bd2 : 1;
                u32 bd : 1;
            };
        };

        union STATUS {
            u32 value;

            enum CH : u32 {
                MISS = 0x00,
                HIT = 0x01
            };

            enum KSU : u32 {
                KERNEL = 0x00,
                SUPERVISOR = 0x01,
                USER = 0x02
            };

            struct {
                u32 ie : 1;
                u32 exl : 1;
                u32 erl : 1;
                KSU ksu : 2;
                u32 int0 : 1; u32 int1 : 1;
                u32 bem : 1;
                u32 int5 : 1;
                u32 eie : 1;
                u32 edi : 1;
                CH ch : 1;
                u32 bev : 1;
                u32 dev : 1;
                u32 cop_use : 4;
            };
        };

        u32 index;
        u32 random;
        u32 entryLo0; u32 entryLo1;
        u32 context;
        u32 page_mask;
        u32 wired;
        u32 badVAddr;
        u32 count;
        u32 entryHi;
        u32 compare;
        STATUS status;
        CAUSE cause;
        u32 epc;
        u32 prid;
        u32 config;
        u32 badPAddr;
        u32 debug;
        u32 perf;
        u32 tagLo; u32 tagHi;
        u32 errorEpc;

        STATUS::KSU privilege_level() {
            return status.erl || status.exl ? STATUS::KSU::KERNEL : status.ksu;
        }
    };
}

#endif //EMUTWO_COP0_H
