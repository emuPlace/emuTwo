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
                u32 r0 : 2; // ?
                EXCEPTION_CODE r1 : 5;
                u32 r2 : 3; // ?
                u32 r3 : 1;
                u32 r4 : 1;
                u32 r5 : 3; // ?
                u32 r6 : 1;
                ERROR_CODE r7 : 3;
                u32 r8 : 9; // ?
                u32 r9 : 2;
                u32 r10 : 1;
                u32 r11 : 1;
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
                u32 r0 : 1;
                u32 r1 : 1;
                u32 r2 : 1;
                KSU r3 : 2;
                u32 r4 : 5; // ?
                u32 r5 : 1;
                u32 r6 : 1;
                u32 r7 : 1;
                u32 r8 : 2; // ?
                u32 r9 : 1;
                u32 r10 : 1;
                u32 r11 : 1;
                CH r12 : 1;
                u32 r13 : 3; // ?
                u32 r14 : 1;
                u32 r15 : 1;
                u32 r16 : 4; // ?
                u32 r17 : 4;
            };
        };

        u32 r0;
        u32 r1;
        u32 r2; u32 r3;
        u32 r4;
        u32 r5;
        u32 r6;
        // ?
        u32 r8;
        u32 r9;
        u32 r10;
        u32 r11;
        STATUS r12;
        CAUSE r13;
        u32 r14;
        u32 r15;
        u32 r16;
        // ?
        u32 r23;
        u32 r24;
        u32 r25;
        // ?
        u32 r28;
        u32 r29;
        u32 r30;

        STATUS::KSU privilege_level() {
            return r12.r1 || r12.r2 ? STATUS::KSU::KERNEL : r12.r3;
        }
    };
}

#endif //EMUTWO_COP0_H
