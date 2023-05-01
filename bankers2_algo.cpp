#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the need matrix
void calculateNeed(vector<vector<int>>& need, const vector<vector<int>>& max, const vector<vector<int>>& allocation, int num_processes, int num_resources) {
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_resources; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

// Function to check if a process can finish
bool isSafe(vector<int>& available, vector<vector<int>>& need, vector<vector<int>>& allocation, int num_processes, int num_resources, vector<bool>& finished, vector<int>& safe_sequence) {
    bool safe = false;
    int count = 0;

    // Loop until all processes are finished or there are no more safe processes
    while (count < num_processes) {
        bool found = false;
        for (int i = 0; i < num_processes; i++) {
            if (!finished[i]) {
                bool can_finish = true;
                for (int j = 0; j < num_resources; j++) {
                    if (need[i][j] > available[j]) {
                        can_finish = false;
                        break;
                    }
                }
                if (can_finish) {
                    for (int j = 0; j < num_resources; j++) {
                        available[j] += allocation[i][j];
                    }
                    safe_sequence.push_back(i);
                    finished[i] = true;
                    found = true;
                    count++;
                    break;
                }
            }
        }
        if (!found) {
            break;
        }
    }

    if (count == num_processes) {
        safe = true;
    }

    return safe;
}

int main() {
    int num_processes, num_resources;

    cout << "Enter the number of processes: ";
    cin >> num_processes;

    cout << "Enter the number of resources: ";
    cin >> num_resources;

    vector<int> available(num_resources);
    cout << "Enter the available resources: ";
    for (int i = 0; i < num_resources; i++) {
        cin >> available[i];
    }

    vector<vector<int>> allocation(num_processes, vector<int>(num_resources));
    cout << "Enter the allocation matrix:" << endl;
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_resources; j++) {
            cin >> allocation[i][j];
        }
    }

    vector<vector<int>> max(num_processes, vector<int>(num_resources));
    cout << "Enter the maximum matrix:" << endl;
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_resources; j++) {
            cin >> max[i][j];
        }
    }

    vector<vector<int>> need(num_processes, vector<int>(num_resources));
    calculateNeed(need, max, allocation, num_processes, num_resources);

    vector<bool> finished(num_processes, false);
    vector<int> safe_sequence;
    if (isSafe(available, need, allocation, num_processes, num_resources, finished, safe_sequence)) {
        cout << "Safe sequence: ";
        for (int i = 0; i < safe_sequence.size(); i++) {
            cout << "P" << safe_sequence[i] << " ";
        }
        cout << endl;
        cout << "Need matrix:" << endl;
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_resources; j++) {
            cout << need[i][j] << " ";
        }
        cout << endl;
    }
}
else {
    cout << "System is unsafe." << endl;
}

return 0;
}
