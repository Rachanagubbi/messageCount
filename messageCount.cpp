#include <iostream>
#include <unordered_map>

class DeviceMonitor {
private:
    std::unordered_map<std::string, int> messageCount;

public:
    // Member function to record a message for a given device
    void recordMessage(const std::string& deviceName) {
        messageCount[deviceName]++;
    }

    // Member function to get the message count for a specific device
    int getMessageCount(const std::string& deviceName) const {
        return messageCount.count(deviceName) ? messageCount.at(deviceName) : 0;
    }
     
    // Member function to get the message counts for all devices
    const std::unordered_map<std::string, int>& getAllMessageCounts() const {
        return messageCount;
    }
};

int main() {
    DeviceMonitor monitor;

    // Get input from the user
    std::cout << "Enter device names (type 'exit' to stop):\n";

    std::string deviceName;
    while (true) {
        std::cout << "Device name: ";
        std::cin >> deviceName;

        // Check if the user wants to exit
        if (deviceName == "exit") {
            break;
        }

        // Record the message
        monitor.recordMessage(deviceName);
    }

    // Get and print the message count for each device
    std::cout << "\nMessage counts:\n";
    std::cout << "-----------------\n";

    for (const auto& entry : monitor.getAllMessageCounts()) {
        std::cout << "Device " << entry.first << ": " << entry.second << " messages\n";
    }

    return 0;
}


