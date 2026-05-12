#include <iostream>
#include "headerr.h"
using namespace std;
int main() {
    Patient patients[10];

    string slots1[] = { "10:00 AM", "2:00 PM" };
    string slots2[] = { "11:00 AM", "3:00 PM" };
    string slots3[] = { "3:25 PM", "5:00 PM" };
    string slots4[] = { "8:00 AM", "1:30 PM" };
    string slots5[] = { "8:00 PM", "4:00 PM" };

    Doctor doctors[5] = {
        Doctor("Cardiology", slots1, 2, "Dr.shalaby", 45, "Male", "01234567890"),
        Doctor("Neurology", slots2, 2, "Dr.Aly", 50, "Male", "010987654321"),
        Doctor("Dermatology", slots3, 2, "Dr.Adham", 35, "Male", "010123456789"),
        Doctor("Orthopedics", slots4, 2, "Dr.Mazen", 40, "Male", "011234567890"),
        Doctor("Pediatrics", slots5, 2, "Dr.Hussain", 38, "Male", "012345678912")
    };
    Medicine medicines[4] = {
        Medicine("Painkiller", 50, 19.99, "Pharma Inc."),
        Medicine("Antibiotic", 30, 29.99, "HealthCorp"),
        Medicine("Flagyl", 20, 9.99, "MedLife"),
        Medicine("Panadol", 20, 9.99, "MedLife")
    };

    Payment payments[2] = {
        Payment("150.00", "Credit Card"),
        Payment("150.00", "Cash")
    };

    Patient patient;
    int choice;
    string ch;
    displayMenu();
    cout << "Enter your choice: ";
    cin >> choice;

    do {

        switch (choice) {
       case 1: { // Make appointment
            int numPatients = 0;
            int arraySize = sizeof(doctors) / sizeof(doctors[0]);
            string name, gender, phoneNumber;
            int age, appointmentID;

            cout << "Enter your name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter your gender: ";
            getline(cin, gender);

            cout << "Enter your phone number: ";
            getline(cin, phoneNumber);

            cout << "Enter your age: ";
            cin >> age;

            cout << "Enter your appointment ID: ";
            cin >> appointmentID;

            cout << "Available Doctors and their slots:" << endl;
            for (int i = 0; i < arraySize; ++i) {
                cout << i + 1 << ". " << doctors[i].getName() << "'s ";
                doctors[i].displaySlots();
            }

            int doctorIndex;
            string selectedSlot;

            cout << "Choose a doctor (enter the number): ";
            cin >> doctorIndex;
            doctorIndex--;

            cout << "Choose a slot: ";
            cin.ignore();
            getline(cin, selectedSlot);

            if (doctorIndex >= 0 && doctorIndex < arraySize) {
                patients[numPatients] = Patient(Appointment(appointmentID, doctors[doctorIndex], selectedSlot), name, age, gender, phoneNumber);
                numPatients++;
                cout<<"--------------------------------------------------------------"<<endl;
                cout << "Appointment made with Dr. " << doctors[doctorIndex].getName() << " at slot: " << selectedSlot << endl;
                cout<<"--------------------------------------------------------------"<<endl;


                cout << "Available Doctors and their slots (excluding the chosen slot):" << endl;
                for (int i = 0; i < arraySize; ++i) {
                    cout << i + 1 << ". " << doctors[i].getName() << "'s ";
                    if (i == doctorIndex) {
                        doctors[i].displaySlots(selectedSlot);
                    }
                    else {
                        doctors[i].displaySlots();
                    }
                }
            }
            else {
                cout << "Invalid doctor selection." << endl;
            }
            break;
        }


  case 2: { // Take diagnosis
    float appointmentPrice = 150.0;
    string symptom;
    cout << "How do you feel? : ";
    cin >> symptom;

    string sickness;
    if (symptom == "not good" || symptom == "bad" || symptom == "not well" || symptom == "tired" || symptom == "sick" || symptom == "not feeling good") {
        cout << "What sickness do you feel(fever,pain,headache)? ";
        cin >> sickness;
    }

    string medication;
    float medicinePrice = 0.0;
    int days;


    cout << "How many days have you been sick? ";
    while (!(cin >> days) || days < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a valid number: ";
    }

    if (sickness == "fever") {
        if (days >= 1 && days <= 3) {
            medication = "Flagyl";
            medicinePrice = medicines[2].getPrice();
        } else {
            medication = "Antibiotic";
            medicinePrice = medicines[1].getPrice();
        }
    } else if (sickness == "pain") {
        if (days >= 1 && days <= 3) {
            medication = "Flagyl Painkiller";
            medicinePrice = medicines[0].getPrice() + medicines[2].getPrice();
        } else {
            medication = "Antibiotic and Painkiller";
            medicinePrice = medicines[0].getPrice() + medicines[1].getPrice();
        }
    } else if (sickness == "headache") {
        if (days >= 1 && days <= 3) {
            medication = "Painkiller";
            medicinePrice = medicines[0].getPrice();
        } else {
            medication = "Antibiotic and Panadol";
            medicinePrice = medicines[0].getPrice() + medicines[3].getPrice();
        }
    }

    cout << "Doctor: Get well soon!" << endl;
    cout << "Doctor: Go buy the medicines: " << medication << endl;
    cout<<"--------------------------------------------------------------"<<endl;

    cout << "Receipt:" << endl;
    cout << "Appointment Payment: " << appointmentPrice << endl;
    cout << "Medicine: " << medication << " - Price: " << medicinePrice << endl;

    float totalPrice = appointmentPrice + medicinePrice;
    cout << "Total Price: " << totalPrice << endl;

    break;
}
case 3: { // Show patient details
    bool foundData = false;
    for (const Patient& patient : patients) {
        if (patient.getName() != "") {
            foundData = true;
            cout << "Patient Details: " << patient.getDetails() << endl;
        }
    }
    if (!foundData) {
        cout << "No patient details available." << endl;
    }
    break;
}




        case 4: { // Update patient
            int arraySize = sizeof(patients) / sizeof(patients[0]);
            string patientName;
            cout << "Enter patient name: ";
            cin.ignore();
            getline(cin, patientName);
            bool patientFound = false;
            for (int i = 0; i < arraySize; ++i) {
                if (patients[i].getName() == patientName) {
                    patientFound = true;
                    cout << "Patient found." << endl;
                    int choice;
                    cout << "Choose what details you want to change:" << endl;
                    cout << "1. Age\n2. Gender\n3. Phone number\nEnter your choice: ";
                    cin >> choice;
                    cin.ignore();
                    if (choice == 1) {
                        int newAge;
                        cout << "Enter new age: ";
                        cin >> newAge;
                        patients[i].setAge(newAge);
                        cout << "Details are updated successfully." << endl;
                        cout << "Updated details: " << patients[i].getDetails() << endl;
                    }
                    else if (choice == 2) {
                        string newGender;
                        cout << "Enter new gender: ";
                        cin >> newGender;
                        patients[i].setGender(newGender);
                        cout << "Details are updated successfully." << endl;
                        cout << "Updated details: " << patients[i].getDetails() << endl;
                    }
                    else if (choice == 3) {
                        string newPhoneNumber;
                        cout << "Enter new phone number: ";
                        cin.ignore();
                        getline(cin, newPhoneNumber);
                        patients[i].setPhoneNumber(newPhoneNumber);
                        cout << "Details are updated successfully." << endl;
                        cout << "Updated details: " << patients[i].getDetails() << endl;
                    }
                    else {
                        cout << "Invalid choice. Please try again." << endl;
                    }
                    break;
                }
            }
            if (!patientFound) {
                cout << "Patient's name is not found." << endl;
            }
            break;
        }

        case 5: { // Show doctor info
            for (const Doctor& doctor : doctors) {
                cout << "Dr information: " << doctor.getDetails() << endl;
            }
            break;
        }

        case 6: { // Show doctor slots
            for (const Doctor& doctor : doctors) {
                cout << doctor.getName() << "'s ";
                doctor.displaySlots();
            }
            break;
        }

case 7: { // Add a slot for a doctor
    int arraySize = sizeof(doctors) / sizeof(doctors[0]);
    string userEnteredName;
    cout << "Enter the doctor's name: ";
    cin.ignore();
    getline(cin, userEnteredName);

    bool found = false;
    for (int i = 0; i < arraySize; ++i) {
        if (doctors[i].name == userEnteredName) {
            found = true;
            if (doctors[i].getNumSlot() < 10) {
                string newSlot;
                cout << "Enter a slot in that format 2:00 AM: ";
                getline(cin, newSlot);
                doctors[i].addSlot(newSlot);
                cout << "Updated slots for Dr. " << doctors[i].name << ": ";
                doctors[i].displaySlots();
            } else {
                cout << "No slots available to add more." << endl;
            }
            break; // Move the break statement inside the if block
        }
    }

    if (!found) {
        cout << "Doctor not found." << endl;
    }
}


        case 8: { // Update doctor information
            int arraySize = sizeof(doctors) / sizeof(doctors[0]);
            string userEnteredName;
            cout << "Enter the doctor's name: ";
            cin >> userEnteredName;
            bool found = false;
            for (int i = 0; i < arraySize; ++i) {
                if (doctors[i].name == userEnteredName) {
                    found = true;
                    cout << "Enter the type of information you want to edit: \n 1. Phone number \n 2. Age \n 3. Specialization \n";
                    int numType;
                    cout << "Enter the number:";
                    cin >> numType;
                    if (numType == 1) {
                        string pn;
                        cout << "Enter a phone number: ";
                        cin >> pn;
                        doctors[i].setPhoneNumber(pn);
                        cout << "Data has been updated." << endl;
                        updatearray(doctors, arraySize);
                    }
                    else if (numType == 2) {
                        int newAge;
                        cout << "Enter the new age: ";
                        cin >> newAge;
                        doctors[i].setAge(newAge);
                        cout << "Data has been updated." << endl;
                        updatearray(doctors, arraySize);
                    }
                    else if (numType == 3) {
                        string spli;
                        cout << "Enter the new specialization: ";
                        cin >> spli;
                        doctors[i].specialization = spli;
                        cout << "Data has been updated." << endl;
                        updatearray(doctors, arraySize);
                    }
                    break;
                }
            }
            if (!found) {
                cout << "Doctor not found." << endl;
            }
            break;
        }

        case 9: { // Remove doctor slots
            int arraySize = sizeof(doctors) / sizeof(doctors[0]);
            string userEnteredName;
            cout << "Enter the doctor's name to remove a slot: ";
            cin.ignore();
            getline(cin, userEnteredName);
            bool found = false;
            for (int i = 0; i < arraySize; ++i) {
                if (doctors[i].name == userEnteredName) {
                    found = true;
                    string slot;
                    cout << "Enter the slot to remove: ";
                    getline(cin, slot);
                    doctors[i].removeSlot(slot);
                    cout<<"--------------------------------------------------------------"<<endl;
                    cout << "Slot has been removed." << endl;
                    cout<<"--------------------------------------------------------------"<<endl;
                    cout << "Available Slots for " << doctors[i].name << " after removal:" << endl;
                    doctors[i].displaySlots();
                    break;
                }
            }
            if (!found) {
                cout << "Doctor not found." << endl;
            }
            break;
        }

        case 10: { // Cancel appointment
            int numPatients = 10;
            int cancelAppointmentID;
            bool found = false;

            cout << "Enter the ID of the appointment you wish to cancel: ";
            cin >> cancelAppointmentID;

            for (int i = 0; i < numPatients; ++i) {
                if (patients[i].getAppointment().getId() == cancelAppointmentID) {
                    found = true;
                    patients[i].cancelAppointment();
                    cout<<"--------------------------------------------------------------"<<endl;
                    cout << "Appointment with ID " << cancelAppointmentID << " has been cancelled." << endl;
                    break;
                }
            }

            if (!found) {
                    cout<<"--------------------------------------------------------------"<<endl;
                cout << "Appointment with ID " << cancelAppointmentID << " is not valid." << endl;
            }
            break;
        }

        case 0:
            cout << "Exiting... Get well soon ;)" << endl;
            break;


        default:
            cout << "Invalid choice. Please try again." << endl;
        }
        cout<<"------------------------------"<<endl;
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
    } while (choice != 0);


    return 0;
}