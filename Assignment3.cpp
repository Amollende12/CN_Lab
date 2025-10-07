#include<iostream>
using namespace std;

void goBackN(int totalFrames) {
    int lostFrame;
    cout << "\nEnter the frame number that is lost: ";
    cin >> lostFrame;

    for (int i = 1; i <= totalFrames; i++) {
        cout << "Sending frame " << i << endl;
    }

    for (int i = 1; i <= totalFrames; i++) {
        if (i == lostFrame) {
            cout << "Acknowledgment not received for frame " << i << endl;
            break;
        } else {
            cout << "Acknowledgment received for frame " << i << endl;
        }
    }

    cout << "\nResending from frame " << lostFrame << endl;
    for (int i = lostFrame; i <= totalFrames; i++) {
        cout << "Sending frame " << i << endl;
        cout << "Acknowledgment received for frame " << i << endl;
    }
}

void selectiveRepeat(int totalFrames) {
    int lostFrame;
    cout << "\nEnter the frame number that is lost: ";
    cin >> lostFrame;

    for (int i = 1; i <= totalFrames; i++) {
        cout << "Sending frame " << i << endl;
        if (i == lostFrame) {
            cout << "Acknowledgment: -1 (lost)" << endl;
        } else {
            cout << "Acknowledgment received for frame " << i << endl;
        }
    }

    cout << "\nResending frame " << lostFrame << endl;
    cout << "Acknowledgment received for frame " << lostFrame << endl;
}

int main() {
    int totalFrames, choice;
    cout << "Enter the total number of frames: ";
    cin >> totalFrames;

    do {
        cout << "\nMenu: \n1. Go-Back-N \n2. Selective Repeat \n3. Exit \nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                goBackN(totalFrames);
                break;

            case 2:
                selectiveRepeat(totalFrames);
                break;

            case 3:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice, try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
/*
Sample Output:

Enter the total number of frames: 5

Menu: 
1. Go-Back-N 
2. Selective Repeat 
3. Exit 
Choice: 1

Enter the frame number that is lost: 3
Sending frame 1
Sending frame 2
Sending frame 3
Sending frame 4
Sending frame 5
Acknowledgment received for frame 1
Acknowledgment received for frame 2
Acknowledgment not received for frame 3

Resending from frame 3
Sending frame 3
Acknowledgment received for frame 3
Sending frame 4
Acknowledgment received for frame 4
Sending frame 5
Acknowledgment received for frame 5

Menu: 
1. Go-Back-N 
2. Selective Repeat 
3. Exit 
Choice: 2

Enter the frame number that is lost: 4
Sending frame 1
Acknowledgment received for frame 1
Sending frame 2
Acknowledgment received for frame 2
Sending frame 3
Acknowledgment received for frame 3
Sending frame 4
Acknowledgment: -1 (lost)
Sending frame 5
Acknowledgment received for frame 5

Resending frame 4
Acknowledgment received for frame 4

Menu: 
1. Go-Back-N 
2. Selective Repeat 
3. Exit 
Choice: 3
Exiting program...
*/
