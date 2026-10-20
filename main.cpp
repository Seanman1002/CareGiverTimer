#include <iostream>
#include <unistd.h> // Needed for the sleep() function to freeze time loops


// Standard function to handle flashing the desktop alert
void sendDesktopAlert(std::string title, std::string message) {
    // Construct the terminal execution command string
    std::string command = "notify-send '" + title + "' '" + message + "'";

    // system() executes the string command natively on your Linux layout
    system(command.c_str());
}

int main()
{
    int minuteFourHour = 240;
    int minuteTwoHour = 120;
    bool isRunning = true;

    std::cout << "========================================\n";
    std::cout << "CareGiver Timer\n";
    std::cout << "========================================\n";
    std::cout << "Beginning Timer Loop for Meals | Beginning Timer Loop for Exercise\n";

    sendDesktopAlert("Nutrition Timer Started", "4 hours till meal time");
    sendDesktopAlert("Walking Timer Started", "2 Hours till the next exercise");

   while (isRunning) {
        std::cout << "Time Remaining till next meal: " << minuteFourHour << " minutes...\n";
        std::cout << "Time Remaining to Exercise: " << minuteTwoHour << " minutes...\n";
        if (minuteFourHour == 0) {
                minuteFourHour = 240;
            sendDesktopAlert("Time to Eat", "4 Hours starts again");
        }
        sleep(60);
        minuteFourHour = minuteFourHour - 1;
        minuteTwoHour = minuteTwoHour - 1;
    }
    isRunning = false;
    if (!isRunning){
        std::cout << "Time is up, Restarting timer";

        sendDesktopAlert("Timer Begins", "4 Hours Remain");

        std::cout << "\a";
    }
    while (isRunning){
        std::cout << "Time Remaining till Exercise: " << minuteTwoHour << " minutes...\n";
        if (minuteTwoHour == 0){
            minuteTwoHour = 120;
            sendDesktopAlert("Time to go from Christopher Reeves to Christopher Walken!!!", "Get Yo Butt Up!!!");
        }
        sleep(60);
        minuteTwoHour = minuteTwoHour - 1;
    }
    isRunning = false;
    if (!isRunning){
        std::cout << "Time to Walk, Restarting timer till next Round";

        sendDesktopAlert("Timer begins", "2 Hours Remain");

        std::cout << "\a";
    }
}
