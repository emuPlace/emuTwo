//
// Created by Antique on 15/01/2023.
//

#ifndef EMUTWO_EE_H
#define EMUTWO_EE_H

#include "cop0/cop0.h"
#include "util/util.h"

namespace GPR {
    union Registers {
        struct {
            u128 zero;
            u128 at;
            u128 v0; u128 v1;
            u128 a0; u128 a1; u128 a2; u128 a3;
            u128 t0; u128 t1; u128 t2; u128 t3; u128 t4; u128 t5; u128 t6; u128 t7;
            u128 s0; u128 s1; u128 s2; u128 s3; u128 s4; u128 s5; u128 s6; u128 s7;
            u128 t8; u128 t9;
            u128 k0; u128 k1;
            u128 gp;
            u128 sp;
            u128 fp;
            u128 ra;
        };
    };
}

namespace EE {
    class EMOTION_ENGINE {
    public:
        EMOTION_ENGINE();
        ~EMOTION_ENGINE();

    public:
        GPR::Registers registers = {};

        COP0 cop0 = {};

        u32 pc = 0x00;
        u64 hi = 0x00; u64 lo = 0x00;
        u64 hi1 = 0x00; u64 lo1 = 0x00;
        u32 sa = 0x00;

    public:
        /*
        void op_add(); void op_addi(); void op_addiu(); void op_addu();
        void op_and(); void op_andi();
        void op_beq(); void op_beql();
        void op_bgez(); void op_bgezal(); void op_bgezall(); void op_bgezl();
        void op_bgtz(); void op_bgtzl();
        void op_blez(); void op_blezl();
        void op_bltz(); void op_bltzal(); void op_bltzall(); void op_bltzl();
        void op_bne(); void op_bnel();
        void op_break();
        void op_dadd(); void op_daddi(); void op_daddiu(); void op_daddu();
        void op_div(); void op_divu();
         */

        void tick();
    };
}

#endif //EMUTWO_EE_H
