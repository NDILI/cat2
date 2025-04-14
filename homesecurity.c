#include <stdio.h>
#include <stdbool.h>

// --- System Configuration ---
#define CORRECT_PIN "1234" // Define the correct PIN as a string
#define MAX_PIN_ATTEMPTS 3 // Maximum allowed incorrect PIN attempts

// --- Function Declarations ---
bool checkPin(const char *enteredPin);
void grantAccess();
void denyAccess();
void soundAlarm();
void resetSystem();

// --- Global Variables ---
int incorrectAttempts = 0; // Keep track of incorrect PIN attempts

int main() {
    printf("--- Home Security Access System ---\n");

    char enteredPin[10]; // Array to store the PIN entered by the user (simulated)

    // --- Iteration Control Structure (Main Loop for Access Attempts) ---
    while (incorrectAttempts < MAX_PIN_ATTEMPTS) {
        printf("\nPlease enter your PIN: ");
        // In a real system, you would read from a keypad.
        // For simulation, we'll use scanf and simulate user input.
        scanf("%9s", enteredPin); // Read up to 9 characters to prevent buffer overflow

        // --- Sequence Control Structure ---
        // 1. Check the entered PIN
        bool isPinCorrect = checkPin(enteredPin);

        // --- Selection Control Structure ---
        // 2. Grant or deny access based on the PIN
        if (isPinCorrect) {
            grantAccess();
            break; // Exit the loop if the PIN is correct
        } else {
            denyAccess();
            incorrectAttempts++;
            printf("Incorrect PIN. Attempts remaining: %d\n", MAX_PIN_ATTEMPTS - incorrectAttempts);
        }
    }

    // --- Selection Control Structure (After the loop) ---
    // 3. If too many incorrect attempts, sound the alarm
    if (incorrectAttempts >= MAX_PIN_ATTEMPTS) {
        soundAlarm();
    }

    resetSystem(); // Reset the system state

    printf("\n--- System reset ---\n"); //"System finished" in Russian
    return 0;
}

// --- Function Definitions ---

// Function to check the PIN (using string comparison)
bool checkPin(const char *enteredPin) {
    if (strcmp(enteredPin, CORRECT_PIN) == 0) {
        return true;
    } else {
        return false;
    }
}

// Function to grant access
void grantAccess() {
    printf("Access GRANTED. Welcome home!\n");
    // In a real system, this would unlock the door.
}

// Function to deny access
void denyAccess() {
    printf("Access DENIED. Incorrect PIN.\n");
}

// Function to sound the alarm
void soundAlarm() {
    printf("--- ALARM SOUNDING! ---\n");
    printf("Intruder alert! Access denied after multiple attempts.\n");
    // In a real system, this would activate a siren or send an alert.
}

void resetSystem(){
    incorrectAttempts = 0;
    printf("System has been reset\n");
}