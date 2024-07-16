#include "arm.hpp"

std::unordered_map <std::string, std::pair<size_t, int>> armRegInfoMap = {
        {"INVALID", {0, UC_ARM_REG_INVALID}},
        {"APSR", {32, UC_ARM_REG_APSR}},
        {"NZCV", {32, UC_ARM_REG_APSR_NZCV}},
        {"CPSR", {32, UC_ARM_REG_CPSR}},
        {"FPEXC", {32, UC_ARM_REG_FPEXC}},
        {"FPINST", {32, UC_ARM_REG_FPINST}},
        {"FPSCR", {32, UC_ARM_REG_FPSCR}},
        {"FPSCR_NZCV", {32, UC_ARM_REG_FPSCR_NZCV}},
        {"FPSID", {32, UC_ARM_REG_FPSID}},
        {"ITSTATE", {8, UC_ARM_REG_ITSTATE}},
        {"LR", {32, UC_ARM_REG_LR}},
        {"PC", {32, UC_ARM_REG_PC}},
        {"SP", {32, UC_ARM_REG_SP}},
        {"SPSR", {32, UC_ARM_REG_SPSR}},
        {"D0", {64, UC_ARM_REG_D0}},
        {"D1", {64, UC_ARM_REG_D1}},
        {"D2", {64, UC_ARM_REG_D2}},
        {"D3", {64, UC_ARM_REG_D3}},
        {"D4", {64, UC_ARM_REG_D4}},
        {"D5", {64, UC_ARM_REG_D5}},
        {"D6", {64, UC_ARM_REG_D6}},
        {"D7", {64, UC_ARM_REG_D7}},
        {"D8", {64, UC_ARM_REG_D8}},
        {"D9", {64, UC_ARM_REG_D9}},
        {"D10", {64, UC_ARM_REG_D10}},
        {"D11", {64, UC_ARM_REG_D11}},
        {"D12", {64, UC_ARM_REG_D12}},
        {"D13", {64, UC_ARM_REG_D13}},
        {"D14", {64, UC_ARM_REG_D14}},
        {"D15", {64, UC_ARM_REG_D15}},
        {"D16", {64, UC_ARM_REG_D16}},
        {"D17", {64, UC_ARM_REG_D17}},
        {"D18", {64, UC_ARM_REG_D18}},
        {"D19", {64, UC_ARM_REG_D19}},
        {"D20", {64, UC_ARM_REG_D20}},
        {"D21", {64, UC_ARM_REG_D21}},
        {"D22", {64, UC_ARM_REG_D22}},
        {"D23", {64, UC_ARM_REG_D23}},
        {"D24", {64, UC_ARM_REG_D24}},
        {"D25", {64, UC_ARM_REG_D25}},
        {"D26", {64, UC_ARM_REG_D26}},
        {"D27", {64, UC_ARM_REG_D27}},
        {"D28", {64, UC_ARM_REG_D28}},
        {"D29", {64, UC_ARM_REG_D29}},
        {"D30", {64, UC_ARM_REG_D30}},
        {"D31", {64, UC_ARM_REG_D31}},
        {"FPINST2", {32, UC_ARM_REG_FPINST2}},
        {"MVFR0", {32, UC_ARM_REG_MVFR0}},
        {"MVFR1", {32, UC_ARM_REG_MVFR1}},
        {"MVFR2", {32, UC_ARM_REG_MVFR2}},
        {"Q0", {128, UC_ARM_REG_Q0}},
        {"Q1", {128, UC_ARM_REG_Q1}},
        {"Q2", {128, UC_ARM_REG_Q2}},
        {"Q3", {128, UC_ARM_REG_Q3}},
        {"Q4", {128, UC_ARM_REG_Q4}},
        {"Q5", {128, UC_ARM_REG_Q5}},
        {"Q6", {128, UC_ARM_REG_Q6}},
        {"Q7", {128, UC_ARM_REG_Q7}},
        {"Q8", {128, UC_ARM_REG_Q8}},
        {"Q9", {128, UC_ARM_REG_Q9}},
        {"Q10", {128, UC_ARM_REG_Q10}},
        {"Q11", {128, UC_ARM_REG_Q11}},
        {"Q12", {128, UC_ARM_REG_Q12}},
        {"Q13", {128, UC_ARM_REG_Q13}},
        {"Q14", {128, UC_ARM_REG_Q14}},
        {"Q15", {128, UC_ARM_REG_Q15}},
        {"R0", {32, UC_ARM_REG_R0}},
        {"R1", {32, UC_ARM_REG_R1}},
        {"R2", {32, UC_ARM_REG_R2}},
        {"R3", {32, UC_ARM_REG_R3}},
        {"R4", {32, UC_ARM_REG_R4}},
        {"R5", {32, UC_ARM_REG_R5}},
        {"R6", {32, UC_ARM_REG_R6}},
        {"R7", {32, UC_ARM_REG_R7}},
        {"R8", {32, UC_ARM_REG_R8}},
        {"R9", {32, UC_ARM_REG_R9}},
        {"R10", {32, UC_ARM_REG_R10}},
        {"R11", {32, UC_ARM_REG_R11}},
        {"R12", {32, UC_ARM_REG_R12}},
        {"S0", {32, UC_ARM_REG_S0}},
        {"S1", {32, UC_ARM_REG_S1}},
        {"S2", {32, UC_ARM_REG_S2}},
        {"S3", {32, UC_ARM_REG_S3}},
        {"S4", {32, UC_ARM_REG_S4}},
        {"S5", {32, UC_ARM_REG_S5}},
        {"S6", {32, UC_ARM_REG_S6}},
        {"S7", {32, UC_ARM_REG_S7}},
        {"S8", {32, UC_ARM_REG_S8}},
        {"S9", {32, UC_ARM_REG_S9}},
        {"S10", {32, UC_ARM_REG_S10}},
        {"S11", {32, UC_ARM_REG_S11}},
        {"S12", {32, UC_ARM_REG_S12}},
        {"S13", {32, UC_ARM_REG_S13}},
        {"S14", {32, UC_ARM_REG_S14}},
        {"S15", {32, UC_ARM_REG_S15}},
        {"S16", {32, UC_ARM_REG_S16}},
        {"S17", {32, UC_ARM_REG_S17}},
        {"S18", {32, UC_ARM_REG_S18}},
        {"S19", {32, UC_ARM_REG_S19}},
        {"S20", {32, UC_ARM_REG_S20}},
        {"S21", {32, UC_ARM_REG_S21}},
        {"S22", {32, UC_ARM_REG_S22}},
        {"S23", {32, UC_ARM_REG_S23}},
        {"S24", {32, UC_ARM_REG_S24}},
        {"S25", {32, UC_ARM_REG_S25}},
        {"S26", {32, UC_ARM_REG_S26}},
        {"S27", {32, UC_ARM_REG_S27}},
        {"S28", {32, UC_ARM_REG_S28}},
        {"S29", {32, UC_ARM_REG_S29}},
        {"S30", {32, UC_ARM_REG_S30}},
        {"S31", {32, UC_ARM_REG_S31}},
        {"C1_C0_2", {32, UC_ARM_REG_C1_C0_2}},
        {"C13_C0_2", {32, UC_ARM_REG_C13_C0_2}},
        {"C13_C0_3", {32, UC_ARM_REG_C13_C0_3}},
        {"IPSR", {32, UC_ARM_REG_IPSR}},
        {"MSP", {32, UC_ARM_REG_MSP}},
        {"PSP", {32, UC_ARM_REG_PSP}},
        {"CONTROL", {32, UC_ARM_REG_CONTROL}},
        {"IAPSR", {32, UC_ARM_REG_IAPSR}},
        {"EAPSR", {32, UC_ARM_REG_EAPSR}},
        {"XPSR", {32, UC_ARM_REG_XPSR}},
        {"EPSR", {32, UC_ARM_REG_EPSR}},
        {"IEPSR", {32, UC_ARM_REG_IEPSR}},
        {"PRIMASK", {32, UC_ARM_REG_PRIMASK}},
        {"BASEPRI", {32, UC_ARM_REG_BASEPRI}},
        {"BASEPRI_MAX", {32, UC_ARM_REG_BASEPRI_MAX}},
        {"FAULTMASK", {32, UC_ARM_REG_FAULTMASK}},
        {"APSR_NZCVQ", {32, UC_ARM_REG_APSR_NZCVQ}},
        {"APSR_G", {32, UC_ARM_REG_APSR_G}},
        {"APSR_NZCVQG", {32, UC_ARM_REG_APSR_NZCVQG}},
        {"IAPSR_NZCVQ", {32, UC_ARM_REG_IAPSR_NZCVQ}},
        {"IAPSR_G", {32, UC_ARM_REG_IAPSR_G}},
        {"IAPSR_NZCVQG", {32, UC_ARM_REG_IAPSR_NZCVQG}},
        {"EAPSR_NZCVQ", {32, UC_ARM_REG_EAPSR_NZCVQ}},
        {"EAPSR_G", {32, UC_ARM_REG_EAPSR_G}},
        {"EAPSR_NZCVQG", {32, UC_ARM_REG_EAPSR_NZCVQG}},
        {"XPSR_NZCVQ", {32, UC_ARM_REG_XPSR_NZCVQ}},
        {"XPSR_G", {32, UC_ARM_REG_XPSR_G}},
        {"XPSR_NZCVQG", {32, UC_ARM_REG_XPSR_NZCVQG}},
        {"CP_REG", {32, UC_ARM_REG_CP_REG}},
};

std::string armIPStr(uc_mode mode) {
    if (mode == UC_MODE_ARM1176 || mode == UC_MODE_ARM946 || mode == UC_MODE_ARM926){
        return "R15";
    }
    else {
        return "";
    }
}

std::string arm64IPStr(uc_mode mode) {
    switch (mode) {
        case UC_MODE_ARM:
            return "PC";
        case UC_MODE_THUMB:
            return "R15";
        default:
            return "";
    }
}
