#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

// Convert integer to 8-bit binary string
string toBinary(int n) {
    string bin = "";
    while (n > 0) {
        bin = char('0' + (n % 2)) + bin;
        n /= 2;
    }
    while (bin.length() < 8) {
        bin = "0" + bin;
    }
    return bin;
}

int main() {
    string ip, sm;
    int ipInt[4], smInt[4], netInt[4], broadcastInt[4];

    // Input IP and subnet mask
    cout << "Enter the IP address: ";
    getline(cin, ip);
    cout << "Enter the Subnet Mask: ";
    getline(cin, sm);

    // Split IP and Mask
    stringstream ss1(ip), ss2(sm);
    string part;
    int i = 0;
    while (getline(ss1, part, '.')) ipInt[i++] = stoi(part);
    i = 0;
    while (getline(ss2, part, '.')) smInt[i++] = stoi(part);

    // Calculate Network & Broadcast
    for (int i = 0; i < 4; i++) {
        netInt[i] = ipInt[i] & smInt[i];
        broadcastInt[i] = ipInt[i] | (~smInt[i] & 0xFF); 
    }

    // Subnet Address
    cout << "\nSubnet Address: " 
         << netInt[0] << "." << netInt[1] << "." << netInt[2] << "." << netInt[3] << "\n";

    // Broadcast Address
    cout << "Broadcast Address: " 
         << broadcastInt[0] << "." << broadcastInt[1] << "." << broadcastInt[2] << "." << broadcastInt[3] << "\n";

    // First and Last Hosts
    cout << "First Host: " 
         << netInt[0] << "." << netInt[1] << "." << netInt[2] << "." << (netInt[3] + 1) << "\n";

    cout << "Last Host: " 
         << broadcastInt[0] << "." << broadcastInt[1] << "." << broadcastInt[2] << "." << (broadcastInt[3] - 1) << "\n";

    // Count mask bits
    int totalOnes = 0;
    for (int i = 0; i < 4; i++) {
        string binary = toBinary(smInt[i]);
        for (char bit : binary) {
            if (bit == '1') totalOnes++;
        }
    }

    int totalZeros = 32 - totalOnes;

    // Block size & usable hosts
    int blockSize = (int)pow(2, totalZeros);
    cout << "Block Size: " << blockSize << "\n";
    cout << "Usable Hosts: " << (blockSize - 2) << "\n";

    int subnetBits = totalOnes - 16;
    int numberOfSubnets = (int)pow(2, abs(subnetBits));
    cout << "Number of Subnets: " << numberOfSubnets << "\n";

    return 0;
}
/*
Sample Output:

Enter the IP address: 192.168.10.17
Enter the Subnet Mask: 255.255.255.240

Subnet Address: 192.168.10.16
Broadcast Address: 192.168.10.31
First Host: 192.168.10.17
Last Host: 192.168.10.30
Block Size: 16
Usable Hosts: 14
Number of Subnets: 256
*/
