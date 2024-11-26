#include <iostream>
#include <termios.h>
#include <unistd.h>

void disableCanonicalMode(struct termios &oldSettings) {
    struct termios newSettings;
    tcgetattr(STDIN_FILENO, &oldSettings);  // Get current terminal settings
    newSettings = oldSettings;
    newSettings.c_lflag &= ~ICANON;         // Disable canonical mode
    newSettings.c_lflag &= ~ECHO;           // Disable echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newSettings); // Apply new settings
}

void restoreCanonicalMode(struct termios &oldSettings) {
    tcsetattr(STDIN_FILENO, TCSANOW, &oldSettings); // Restore original settings
}

int main() {
    struct termios oldSettings;
    disableCanonicalMode(oldSettings);

    char ch;
    std::cout << "Enter characters, press space to continue:" << std::endl;

    // Loop to read characters immediately as they are typed
    while (true) {
        std::cin.get(ch);
        if (ch == ' ') {
            break; // Exit loop when space is detected
        }
        std::cout << ch; // Echo the character back (optional)
    }

    restoreCanonicalMode(oldSettings);

    std::cout << "\nSpace detected. Program continues..." << std::endl;

    // Additional program logic here

    return 0;
}
