#include "../include/methods.h"

// Function to disable echoing
void disableEcho() {
    struct termios oldTerminalSettings, newTerminalSettings;
    tcgetattr(STDIN_FILENO, &oldTerminalSettings);
    newTerminalSettings = oldTerminalSettings;
    newTerminalSettings.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newTerminalSettings);
}

// Function to restore echoing
void restoreEcho() {
    struct termios oldTerminalSettings;
    tcgetattr(STDIN_FILENO, &oldTerminalSettings);
    oldTerminalSettings.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &oldTerminalSettings);
}