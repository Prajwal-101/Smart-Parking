#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <conio.h>
using namespace std;

int id = 1;

struct ReceiptData {
    int type_of_vehicle;
    long long phone_no;
    string vehicle_no;
    bool is_self_drive;
    int duration;
    int charges;
    int id_no;
};

class Floor {
public:
    int visited[11][11];
    int number_of_vehicles;

    Floor() {
        for (int i = 1; i <= 10; i++) {
            for (int j = 1; j <= 10; j++) {
                visited[i][j] = 0;
            }
        }
        number_of_vehicles = 0;
    }
};

class building {
public:
    string name;
    Floor f1, f2, f3;
    building(string name) {
        this->name = name;
    }
};

class location {
public:
    Floor Floor_no;
    int x;
    int y;
};

class vehicle {
public:
    int type_of_vehicle;
    long long phone_no;
    string vehicle_no;
    bool is_self_drive;
    int duration;
    location of_this_vehicle;
    int id_no;

    vehicle(int type_of_vehicle, long long phone_no, string vehicle_no, bool is_self_drive, int duration) {
        this->type_of_vehicle = type_of_vehicle;
        this->phone_no = phone_no;
        this->vehicle_no = vehicle_no;
        this->is_self_drive = is_self_drive;
        this->duration = duration;
        this->id_no = id;
    }

    void get_E_slip() {
        int charges_per_hour = 30;
        int charges = duration * charges_per_hour;

        cout << "Your vehicle_no: " << vehicle_no << endl;
        cout << "Your phone_no is: " << phone_no << endl;
        cout << "Your duration of parking is: " << duration << " Hours" << endl;
        cout << "Your charges: " << charges << endl;
        cout << "Your id is: " << id_no << endl;
        cout << "Your location of vehicle is ";
        if (type_of_vehicle == 2) {
            cout << "1st ";
        }
        else if (type_of_vehicle == 4) {
            if (is_self_drive) {
                cout << "2nd ";
            }
            else {
                cout << "3rd ";
            }
        }
        cout << "floor --> ";
        cout << "coordinates are: " << of_this_vehicle.x << " " << of_this_vehicle.y << endl;
        
        ofstream receiptFile("Receipts_data.txt", ios::app);
        receiptFile<<"Coordinates : "<< of_this_vehicle.x << " " << of_this_vehicle.y ;
    }
};


location getlocation(Floor& datum) {
    location now;
    now.Floor_no = datum;
    int flag = 0;
    for (int i = 1; i < 11 && flag == 0; i++) {
        for (int j = 1; j < 11 && flag == 0; j++) {
            if (datum.visited[i][j] != 0)
                continue;
            else {
                datum.visited[i][j] = id;
                now.x = i;
                now.y = j;
                flag = 1;
            }
        }
    }
    return now;
}

class administrator : public vehicle {
private:
    string password;

public:
    void set_password() {
        string s;
        for (int i = 0; i < vehicle_no.size(); i++) {
            s.push_back(vehicle_no[vehicle_no.size() - 1 - i]);
        }
        password = s;
    }

    administrator(int type_of_vehicle, long long phone_no, string vehicle_no, bool is_self_drive, int duration) : vehicle(type_of_vehicle, phone_no, vehicle_no, is_self_drive, duration) {
        set_password();
    }

    void display_admin() {
        cout << "ENTER PASS KEY OF THIS VEHICLE" << endl;
        string pass_key;
        cin >> pass_key;
        if (pass_key == password) {
            cout << "Your vehicle_no: " << vehicle_no << endl;
            cout << "Your phone_no is: " << phone_no << endl;
            cout << "Your duration of parking is: " << duration << " Hours" << endl;
        }
        else {
            cout << "PASSWORD IS INCORRECT" << endl;
        }
    }
};

void display(Floor W) {
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            cout << W.visited[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    string name;
    ofstream customerFile("customer_data.txt", ios::app);
    if (!customerFile.is_open()) {
        cout << "Error opening customer_data.txt" << endl;
        return 1;
    }
    cout << "ENTER NAME OF YOUR BUILDING" << endl;
    cin >> name;
    customerFile << "\nBuilding: " << name;

    building A(name);
    vector<administrator> a;

    int count_selfdriven_vehicle = 0, count_4wheeler_vehicle = 0, count_2wheeler_vehicle = 0;
    int f = 0;

    do {
        int total_no_of_vehicle = id;

        cout << "Press 1 to park your vehicle OR 2 to EXIT OR 3 TO GO TO ADMIN RIGHTS" << endl;
        int t;
        cin >> t;

        if (t == 3) {
            cout << "YOU ARE IN ADMIN SECTION" << endl;
            cout << "ENTER PASSWORD" << endl;
            char pass_to_admin[5];
            char ch;
            for (int i = 0; i < 4; i++) {
                ch = getch();
                pass_to_admin[i] = ch;
                cout << "*";
            }
            cout << endl;
            pass_to_admin[4] = '\0';
            if (strcmp(pass_to_admin, "n007") == 0) {
                cout << "PRESS 1 TO GET FLOOR DETAILS OR 2 TO GET VEHICLE DETAILS" << endl;
                int q;
                cin >> q;
                if (q == 1) {
                    display(A.f1);
                    display(A.f2);
                    display(A.f3);
                }
                else if (q == 2) {
                    cout << "ENTER VEHICLE NO. OF THE VEHICLE" << endl;
                    string vehicle_number_check;
                    cin >> vehicle_number_check;
                    for (int i = 0; i <= total_no_of_vehicle; i++) {
                        if (a[i].vehicle_no == vehicle_number_check) {
                            a[i].display_admin();
                        }
                    }
                }
            }
            else {
                cout << "INCORRECT PASSWORD" << endl;
            }
            continue;
        }
        else if (t == 2) {
            cout << "Enter your vehicle ID_NO" << endl;
            int id_check;
            cin >> id_check;
            customerFile << "\nVehicle ID: " << id_check;

            for (int i = 1; i <= total_no_of_vehicle; i++) {
                if (a[i].id_no == id_check) {
                    if (a[i].type_of_vehicle == 2) {
                        A.f1.visited[a[i].of_this_vehicle.x][a[i].of_this_vehicle.y] = 0;
                    }
                    else if (a[i].type_of_vehicle == 4 && a[i].is_self_drive) {
                        A.f2.visited[a[i].of_this_vehicle.x][a[i].of_this_vehicle.y] = 0;
                    }
                    else {
                        A.f3.visited[a[i].of_this_vehicle.x][a[i].of_this_vehicle.y] = 0;
                    }
                    a.erase(a.begin() + i);
                    break;
                }
            }
            continue;
        }

        total_no_of_vehicle++;

        int type_of_vehicle;
        long long phone_no;
        string vehicle_no;
        bool is_self_drive;
        int duration;

        cout << "Enter type of Vehicle:" << endl
             << "Press 2 for 2 wheeler or Press 4 for 4 wheeler" << endl;
        cin >> type_of_vehicle;
        if (type_of_vehicle == 4) {
            cout << "Is your car self-driven?" << endl
                 << "Press 1 if Yes or 0 if No" << endl;
            int choice;
            cin >> choice;
            is_self_drive = (choice == 1);
        }
        else {
            is_self_drive = false;
        }

        if (type_of_vehicle == 2 && A.f1.number_of_vehicles == 100) {
            cout << "NO MORE PARKING SPACE" << endl;
            continue;
        }

        if (type_of_vehicle == 4 && is_self_drive && A.f2.number_of_vehicles == 100) {
            cout << "NO MORE PARKING SPACE" << endl;
            continue;
        }

        if (type_of_vehicle == 4 && A.f3.number_of_vehicles == 100) {
            cout << "NO MORE PARKING SPACE" << endl;
            continue;
        }

        cout << "Enter phone_no" << endl;
        cin >> phone_no;
        cout << "Enter vehicle_no" << endl;
        cin >> vehicle_no;
        cout << "Enter duration of parking in hours" << endl;
        cin >> duration;

        administrator ad(type_of_vehicle, phone_no, vehicle_no, is_self_drive, duration);
        ad.id_no = id;
        a.push_back(ad);

        vehicle v(type_of_vehicle, phone_no, vehicle_no, is_self_drive, duration);
        v.of_this_vehicle = getlocation((type_of_vehicle == 2) ? A.f1 : (is_self_drive ? A.f2 : A.f3));
        v.get_E_slip();
        id++;

        ReceiptData receiptData;
        receiptData.type_of_vehicle = type_of_vehicle;
        receiptData.phone_no = phone_no;
        receiptData.vehicle_no = vehicle_no;
        receiptData.is_self_drive = is_self_drive;
        receiptData.duration = duration;
        receiptData.charges = duration * 30;
        receiptData.id_no = ad.id_no;

        ofstream receiptFile("Receipts_data.txt", ios::app);
        if (receiptFile.is_open()) {
            receiptFile << "\nType of Vehicle: " << receiptData.type_of_vehicle << "\nVehicle no: " << receiptData.vehicle_no << "\nMobile no: " << receiptData.phone_no << "\nDuration (Hrs): " << receiptData.duration << "\nIs Self-Driven: " << receiptData.is_self_drive << "\nCharges: " << receiptData.charges << "\nID: " << receiptData.id_no<<endl;
             receiptFile.close();
        }
        else {
            cout << "Error opening Receipts_data.txt" << endl;
        }

        customerFile << "\nType of Vehicle: " << type_of_vehicle << "\nVehicle no: " << vehicle_no << "\nMobile no: " << phone_no << "\nDuration (Hrs): " << duration << "\nIs Self-Driven: " << is_self_drive << endl;
    } while (f == 0);

    customerFile.close();

    return 0;
}
