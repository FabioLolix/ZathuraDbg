#include "windows.hpp"

tsl::ordered_map<std::string, std::string> registerValueMap = {{"RIP", "0x00"}, {"RSP", "0x00"}, {"RBP", "0x00"},{"RAX", "0x00"}, {"RBX", "0x00"}, {"RCX", "0x00"}, {"RDX", "0x00"},
                                                               {"RSI", "0x00"}, {"RDI", "0x00"}, {"R8", "0x00"}, {"R9", "0x00"}, {"R10", "0x00"}, {"R11", "0x00"}, {"R12", "0x00"},
                                                               {"R13", "0x00"}, {"R14", "0x00"}, {"R15", "0x00"}, {"CS", "0x00"}, {"DS", "0x00"}, {"ES", "0x00"}, {"FS", "0x00"}, {"GS", "0x00"}, {"SS", "0x00"}};
std::string toLowerCase(const std::string& input) {
    std::string result = input; // Create a copy of the input string
    std::transform(result.begin(), result.end(), result.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
    return result;
}

std::string toUpperCase(const std::string& input) {
    std::string result = input; // Create a copy of the input string
    std::transform(result.begin(), result.end(), result.begin(), [](unsigned char c) {
        return std::toupper(c);
    });
    return result;
}

void updateRegs(){
    std::stringstream hex;
    for (auto &reg: registerValueMap) {
        hex << "0x";
        hex << std::hex << getRegister(toLowerCase(reg.first));
        registerValueMap[reg.first] = hex.str();
        hex.str("");
        hex.clear();
    }
}

void registerWindow() {
    updateRegs();
    auto io = ImGui::GetIO();
    ImGui::PushFont(io.Fonts->Fonts[JetBrainsMono20]);

    if (ImGui::BeginTable("RegistersTable", 4, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_Resizable)) {
        ImGui::TableSetupColumn("Register", ImGuiTableColumnFlags_WidthStretch);
        ImGui::TableSetupColumn("Value", ImGuiTableColumnFlags_WidthStretch);
        ImGui::TableSetupColumn("Register", ImGuiTableColumnFlags_WidthStretch);
        ImGui::TableSetupColumn("Value", ImGuiTableColumnFlags_WidthStretch);
        ImGui::TableHeadersRow();

        int index = 0;
        for (auto it = registerValueMap.begin(); it != registerValueMap.end(); ++index) {
            ImGui::TableNextRow();

            ImGui::TableSetColumnIndex(0);
            float textHeight = ImGui::GetTextLineHeight();
            float frameHeight = ImGui::GetFrameHeight();
            float spacing = (frameHeight - textHeight) / 2.0f;
            ImGui::SetCursorPosY(ImGui::GetCursorPosY() + spacing);
            ImGui::Text("%s", it->first.c_str());

            ImGui::TableSetColumnIndex(1);
            static char value1[64] = {};
            strncpy(value1, it->second.c_str(), sizeof(value1) - 1);
            value1[sizeof(value1) - 1] = '\0';

            ImGui::PushID(index * 2);
            ImGui::SetNextItemWidth(-FLT_MIN); // Use the remaining space in the column
            if (ImGui::InputText(("##value1" + std::to_string(index)).c_str(), value1, IM_ARRAYSIZE(value1), ImGuiInputTextFlags_CharsHexadecimal | ImGuiInputTextFlags_CharsUppercase | ImGuiInputTextFlags_CharsNoBlank)) {
                if (strncmp(value1, "0x", 2) != 0) {
                    registerValueMap[it->first] = "0x";
                    registerValueMap[it->first].append(value1);
                } else {
                    registerValueMap[it->first] = value1;
                }
            }
            ImGui::PopID();

            ++it;
            if (it == registerValueMap.end()) break;

            ImGui::TableSetColumnIndex(2);
            ImGui::Text("%s", it->first.c_str());

            ImGui::TableSetColumnIndex(3);
            static char value2[64] = {};
            strncpy(value2, it->second.c_str(), sizeof(value2) - 1);
            value2[sizeof(value2) - 1] = '\0';

            ImGui::PushID(index * 2 + 1);
            ImGui::SetNextItemWidth(-FLT_MIN); // Use the remaining space in the column
            if (ImGui::InputText(("##value2" + std::to_string(index)).c_str(), value2, IM_ARRAYSIZE(value2), ImGuiInputTextFlags_CharsHexadecimal | ImGuiInputTextFlags_CharsUppercase | ImGuiInputTextFlags_CharsNoBlank)) {
                if (strncmp(value2, "0x", 2) != 0) {
                    registerValueMap[it->first] = "0x";
                    registerValueMap[it->first].append(value2);
                } else {
                    registerValueMap[it->first] = value2;
                }
            }
            ImGui::PopID();
            ++it;
            if (it == registerValueMap.end()) break;
        }

        ImGui::EndTable();
    }
    std::vector<std::string> test = {};
    const float footer_height_to_reserve = ImGui::GetStyle().ItemSpacing.y + ImGui::GetFrameHeightWithSpacing();
    ImGui::BeginChild("ScrollingRegion", ImVec2(0, -footer_height_to_reserve), ImGuiChildFlags_None, ImGuiWindowFlags_HorizontalScrollbar);
    ImGui::EndChild();

    std::list<std::string> commands;
    char input[500]{};
    ImGui::PushID(&input);

    if (ImGui::InputText("Command", input, IM_ARRAYSIZE(input), ImGuiInputTextFlags_EnterReturnsTrue)){
        commands.emplace_back(input);
    }

    if (!commands.empty()){
        for (auto& command: commands){
            if (getRegister(command) != UC_X86_REG_INVALID){
                command = toUpperCase(command);
                registerValueMap[command] = "";
            }
        }
    }


    ImGui::PopID();
    ImGui::PopFont();
}
