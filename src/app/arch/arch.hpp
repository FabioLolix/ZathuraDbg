#ifndef ZATHURA_ARCH_HPP
#define ZATHURA_ARCH_HPP
#include <unicorn/unicorn.h>
#include <string>
#include "x86.hpp"
#include "arm.hpp"
#include <keystone/keystone.h>

struct codeInformationT{
    uc_arch archUC;
    ks_arch archKS;
    uc_mode mode;
    ks_mode modeKS;
};

extern codeInformationT codeInformation;
extern bool initArch();
extern std::string (*getArchIPStr)(uc_mode);
extern std::string (*getArchSPStr)(uc_mode);
extern int regNameToConstant(const std::string &name);
extern std::unordered_map<std::string, std::pair<size_t, int>> regInfoMap;
#endif //ZATHURA_ARCH_HPP
