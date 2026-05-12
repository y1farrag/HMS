#include<iostream>
#include<string>
#include<chrono>
#include<cstring>
using namespace std;

class Person {
public:
    string name;
    int age;
    string gender;
    string phoneNumber;
    Person(string n = "", string gen = "", int ag = 0, string pn = "")
        : name(n), age(ag), gender(gen), phoneNumber(pn) {}

    string getName() const { return name; }
    string getGender() const { return gender; }
    int getAge() const { return age; }
    string getPhoneNumber() const { return phoneNumber; }

    void setName(const string& n) { name = n; }
    void setGender(const string& gen) { gender = gen; }
    void setAge(int ag) { age = ag; }
    void setPhoneNumber(const string& pn) { phoneNumber = pn; }
};

class Doctor : public Person {
public:
    string specialization;
    string slots[10];
    int slotCount;

    Doctor(string sp = "", string sl[] = NULL, int sc = 0, string n = "", int ag = 0, string gen = "", string pn = "")
        : Person(n, gen, ag, pn), specialization(sp), slotCount(sc) {
        if (sl != NULL) {
            for (int i = 0; i < sc; ++i) {
                slots[i] = sl[i];
            }
        }
    }

    string getSpecialization() const { return specialization; }

    void displaySlots(const string& excludeSlot = "") const {
        cout << "Slots: ";
        for (int i = 0; i < slotCount; ++i) {
            if (slots[i] != excludeSlot) {
                cout << slots[i] << " ";
            }
        }
        cout << endl;
    }

    void updateSlot(const string& oldSlot, const string& newSlot) {
        for (int i = 0; i < slotCount; ++i) {
            if (slots[i] == oldSlot) {
                slots[i] = newSlot;

                break;
            }
        }
    }

    void addSlot(const string& slot) {
        if (slotCount < 10) {
            slots[slotCount++] = slot;
        }
        else {
            cout << "Cannot add more slots, array is full." << endl;
        }
    }

    void removeSlot(const string& slot) {
        int newIndex = 0; // Index for the new position of slots
        for (int i = 0; i < slotCount; ++i) {
            if (slots[i] != slot) {
                // If the current slot is not the one to remove, keep it in the array
                slots[newIndex++] = slots[i];
            }
        }
        slotCount = newIndex; // Update slotCount to the new number of slots
    }

    string getDetails() const {
        return name + " " + to_string(age) + " " + gender + " " + phoneNumber + " " + specialization;
    }

    
    string getSlot() {
        for (int i = 0; i < 10; i++) {
            return slots[i];
        }
    }

    int getNumSlot() {
        return slotCount;
    }
};


class Appointment {
private:
    int id;
    Doctor doctor;
    string slot;

public:
    Appointment(int i = 0, const Doctor& d = Doctor(), string sl = "")
        : id(i), doctor(d), slot(sl) {}

    int getId() const { return id; }
    Doctor getDoctor() const { return doctor; }
    string getSlot() const { return slot; }
};

class Patient : public Person {
private:
    Appointment appointment;

public:
    Patient(const Appointment& app = Appointment(), const string& n = "", int ag = 0, const string& gen = "", const string& pn = "")
        : Person(n, gen, ag, pn), appointment(app) {}

    Appointment getAppointment() const { return appointment; }

    void makeAppointment(const Doctor& doctor, const string& slot, int id) {
        appointment = Appointment(id, doctor, slot);
        cout << "Appointment made with Dr. " << doctor.getName() << " at slot: " << slot << endl;
    }

    void cancelAppointment() {
        cout << "Appointment is cancelled" << endl;
        appointment = Appointment();
    }

    string getDetails() const {
        return name + " " + to_string(age) + " " + gender + " " + phoneNumber;
    }

    void updateDetails(const string& newSlot) {
        appointment = Appointment(appointment.getId(), appointment.getDoctor(), newSlot);
        cout << "Slot updated to: " << newSlot << endl;
    }
};

class Medicine {
private:
    string name;
    int quantity;
    float price;
    string manufacturer;

public:
    Medicine(string na = "", int qu = 0, float pri = 0, string manu = "")
        : name(na), quantity(qu), price(pri), manufacturer(manu) {}

    string getName() const { return name; }
    int getQuantity() const { return quantity; }
    float getPrice() const { return price; }
};

class Payment {
private:
    string amount;
    string method;
    string date;

public:
    Payment(string am = "", string meth = "", string da = "")
        : amount(am), method(meth), date(da) {}

    string getAmount() const { return amount; }
    string getMethod() const { return method; }
    string getDate() const { return date; }

    void display() const {
        cout << "Amount: " << amount << endl;
    }
};

void displayMenu() {
    cout << "1. Make Appointment\n";
    cout << "2. Take Diagnosis and Show Related Information\n";
    cout << "3. Show Patient Details\n";
    cout << "4. Update Patient Details\n";
    cout << "5. Show Doctor information\n";
    cout << "6. Show Doctor Slots\n";
    cout << "7. Add Doctor Slot\n";
    cout << "8. update doctor information\n";
    cout << "9. Remove Doctor Slot\n";
    cout << "10.Cancel Appointment\n";
    cout << "0. Exit\n";
}

void showMedicines(const Medicine medicines[], int size) {
    cout << "Available Medicines:\n";
    for (int i = 0; i < size; ++i) {
        cout << "Name: " << medicines[i].getName() << ", Price: $" << medicines[i].getPrice() << "\n";
    }
}

void updatearray(const Doctor doctors[], int arraySize) {
    for (int i = 0; i < arraySize; ++i) {
        cout << "Doctor " << i + 1 << " details:" << endl;
        cout << "Specialization: " << doctors[i].getSpecialization() << endl;
        cout << "Name: " << doctors[i].getName() << endl;
        cout << "Age: " << doctors[i].getAge() << endl;
        cout << "Gender: " << doctors[i].getGender() << endl;
        cout << "Phone Number: " << doctors[i].getPhoneNumber() << endl;
        doctors[i].displaySlots();
        cout << endl;
    }
}