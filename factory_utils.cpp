 #include "factory_utils.h"
using namespace std;

#include <sstream>
#include <map>

void load_conveyors(vector<Conveyor*>& assembly_line) {
    string input;
    Tray* current_tray = nullptr;

    while (getline(cin, input)) {
        switch (input[0]) {
            case 'C': {
                Conveyor* current_conveyor = new Conveyor;
                assembly_line.push_back(current_conveyor);
                current_tray = nullptr; // Reset current_tray because we're on a new conveyor
                break;
            }

            case 'T': {
                if (!assembly_line.empty()) {
                    Tray* new_tray = new Tray;
                    assembly_line.back()->attach_back(new_tray);
                    current_tray = new_tray; 
                }
                break; 
            } 

            default: {
                if (current_tray != nullptr) {
                    float weight = std::stof(input);
                    current_tray->place_back(Egg(weight));
                }
                break;
            }
        }
    }
}

string vertical_report(const vector<Conveyor*>& conveyors) {
    vector<vector<string>> allConveyorsLines;
    size_t maxLines = 0;
    size_t maxLineLength = 0;

    for (const auto& conveyor : conveyors) {
        ostringstream oss;
        oss << *conveyor;
        string conveyorStr = oss.str();

        vector<string> lines;
        istringstream iss(conveyorStr);
        string line;
        while (getline(iss, line)) {
            maxLineLength = max(maxLineLength, line.length());
            lines.push_back(line);
        }

        maxLines = max(maxLines, lines.size());
        allConveyorsLines.push_back(lines);
    }

    // Pad each line of each conveyor to have the same length and ensure all conveyors have the same number of lines
    for (auto& lines : allConveyorsLines) {
        for (auto& line : lines) {
            line += string(maxLineLength - line.length(), ' '); // Pad each line to have the same length
        }
        while (lines.size() < maxLines) {
            lines.push_back(string(maxLineLength, ' ')); // Pad conveyors with fewer lines
        }
    }

    string result;
for (size_t i = 0; i < maxLines; ++i) {
    for (size_t j = 0; j < allConveyorsLines.size(); ++j) {
        result += allConveyorsLines[j][i];
        result += "  "; // Always add two spaces between conveyors, including after the last one
    }
    if (i < maxLines ) {
        result += "\n"; // New line for each layer
    }
}

    return result;
}

string basic_report(const std::vector<Conveyor*>& assembly_line){
    ostringstream report;

    for (const auto& conveyor : assembly_line) {
        if (conveyor) { // Check if conveyor is not a nullptr
            report << *conveyor;
            report << "\n\n"; // Add separation between conveyors
        }
    }

    string finalReport = report.str();
    if (!finalReport.empty()) {
        // Remove the last two newlines to match the requested format exactly
        finalReport.pop_back();
        finalReport.pop_back();
    }

    return finalReport;
}

string horizontal_report(const vector<Conveyor*>& assembly_line) {
    size_t maxLines = 0;
    map<char, char> replacements = {{'|', '-'}, {'-', '|'}, {'/', '\\'}, {'\\', '/'}};
    vector<string> rotatedSections;

    for (const auto& conveyor : assembly_line) {
        stringstream ss;
        ss << *conveyor;
        size_t lineCount = 0;
        string line;
        while (getline(ss, line)) {
            lineCount++;
        }
        maxLines = max(maxLines, lineCount);
    }

    for (auto it = assembly_line.rbegin(); it != assembly_line.rend(); ++it) {
        stringstream ss;
        ss << **it;
        vector<string> lines;
        string temp;
        while (getline(ss, temp)) {
            lines.push_back(temp);
        }

        string rotatedConveyor;
        for (size_t col = 5; col-- > 0; ) {
            for (size_t row = 0; row < maxLines; ++row) {
                if (row < lines.size()) {
                    char ch = col < lines[row].size() ? lines[row][col] : ' ';
                    if (replacements.find(ch) != replacements.end()) {
                        ch = replacements[ch];
                    }
                    rotatedConveyor += ch;
                } else {
                    rotatedConveyor += ' ';
                }
            }
            rotatedConveyor += "\n";
        }
        rotatedSections.push_back(rotatedConveyor);
    }

    string report;
    for (const auto& section : rotatedSections) {
        report += section + string(maxLines, ' ') + "\n";
    }

    return report;
}

