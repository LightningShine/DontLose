
#include <iostream>      // For console input/output (std::cout, std::cerr)
#include <filesystem>    // For file system operations (fs::path, fs::recursive_directory_iterator)
#include <string>        // For using the std::string class
#include <algorithm>     // For std::transform to convert strings to lowercase
#include <vector>        // For std::vector to store the paths of found files
#include <windows.h>     // For Windows-specific console color functions (SetConsoleTextAttribute)


namespace fs = std::filesystem;

// These are standard Windows console color codes.
constexpr int CONSOLE_COLOR_GREEN = 10;
constexpr int CONSOLE_COLOR_RED = 12;
constexpr int CONSOLE_COLOR_WHITE = 7;


void set_console_color(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}


void findFiles(const std::string& target) {
    fs::path currentPath = fs::current_path();
    std::vector<fs::path> found_files;

    // Recursively iterate through the current directory and its subdirectories.
    // fs::directory_options::skip_permission_denied prevents the program from
    // crashing when it encounters a directory it doesn't have access to.
    for (const auto& entry : fs::recursive_directory_iterator(currentPath, fs::directory_options::skip_permission_denied)) {
        // We only care about regular files, not directories or other types.
        if (entry.is_regular_file()) {
            std::string filename = entry.path().filename().string();

            // For a case-insensitive search, convert both the filename and the target to lowercase.
            // This avoids creating temporary strings repeatedly inside the loop, adhering to DRY.
            std::string filename_lowercase = filename;
            std::transform(filename_lowercase.begin(), filename_lowercase.end(), filename_lowercase.begin(), ::tolower);

            std::string target_lowercase = target;
            std::transform(target_lowercase.begin(), target_lowercase.end(), target_lowercase.begin(), ::tolower);

            // std::string::find is used to check if the target is a substring of the filename.
            if (filename_lowercase.find(target_lowercase) != std::string::npos) {
                found_files.push_back(entry.path());
            }
        }
    }

    // After searching, report the results.
    if (!found_files.empty()) {
        set_console_color(CONSOLE_COLOR_GREEN);
        std::cout << "Successfully found " << found_files.size() << " file(s):" << std::endl;
        set_console_color(CONSOLE_COLOR_WHITE);
        for (const auto& path : found_files) {
            std::cout << path.string() << std::endl;
        }
    } else {
        set_console_color(CONSOLE_COLOR_RED);
        std::cout << "File not found." << std::endl;
        set_console_color(CONSOLE_COLOR_WHITE);
    }
}


int main(int argc, char* argv[]) {
    // The program requires one argument: the filename to search for.
    // argc is always at least 1 (the program name itself).
    if (argc < 2) {
        set_console_color(CONSOLE_COLOR_RED);
        std::cerr << "Error: You need to provide a filename." << std::endl;
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        set_console_color(CONSOLE_COLOR_WHITE);
        return 1; // Return a non-zero value to indicate an error.
    }

    // Filesystem operations can throw exceptions (e.g., if a disk is unreadable).
    // A try-catch block ensures the program can handle these errors gracefully
    // instead of crashing.
    try {
        findFiles(argv[1]);
    } catch (const fs::filesystem_error& e) {
        set_console_color(CONSOLE_COLOR_RED);
        std::cerr << "Filesystem error: " << e.what() << std::endl;
        set_console_color(CONSOLE_COLOR_WHITE);
    } catch (const std::exception& e) {
        set_console_color(CONSOLE_COLOR_RED);
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
        set_console_color(CONSOLE_COLOR_WHITE);
    }

    return 0; // Success
}