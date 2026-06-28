# Banking System

A simple **Banking System** developed in **C++** that demonstrates the use of **Object-Oriented Programming (OOP)**, **file handling**, **exception handling**, and the **STL map** container to manage bank accounts.

**Author:** Md Zayan

---

## 📌 Features

* Open a new bank account
* Deposit money
* Withdraw money
* Balance enquiry
* Close an existing account
* Display all accounts
* Persistent data storage using file handling
* Exception handling for insufficient balance and invalid account numbers

---

## 🛠 Technologies Used

* C++
* Object-Oriented Programming (OOP)
* STL (`map`)
* File Handling (`fstream`)
* Exception Handling

---

## 📂 Project Structure

### `Account` Class

The `Account` class represents a bank account and stores:

* Account Number
* First Name
* Last Name
* Account Balance

It provides methods to:

* Deposit money
* Withdraw money
* Retrieve account information
* Read and write account data using file streams

---

### `Bank` Class

The `Bank` class manages all customer accounts using an STL `map`.

It provides the following operations:

* Open Account
* Balance Enquiry
* Deposit
* Withdraw
* Close Account
* Show All Accounts

The class automatically saves updated account information to a file after every modification.

---

## 💾 Data Persistence

The application stores account information in a file named **`Bank.data`**.

* Existing account records are loaded automatically when the program starts.
* Every successful operation (opening, depositing, withdrawing, or closing an account) immediately updates the file.
* This ensures that account information is preserved even after the program is closed.

---

## ⚠ Exception Handling

The project uses custom and standard exceptions to improve reliability.

### `InsufficientFunds`

Thrown when a withdrawal would reduce the account balance below the minimum balance of **₹500**.

### `runtime_error`

Used for situations such as:

* Account not found
* Invalid operations
* Opening an account with a balance below the minimum required amount

---

## 📋 Menu Operations

1. Open an Account
2. Balance Enquiry
3. Deposit Money
4. Withdraw Money
5. Close an Account
6. Show All Accounts
7. Exit

---

## 🎯 Concepts Demonstrated

* Object-Oriented Programming
* Classes and Objects
* Constructors
* Static Data Members
* Friend Functions
* Operator Overloading
* STL `map`
* File Handling
* Exception Handling
* Menu-Driven Programming

---

## 🚀 Future Improvements

* Password-protected accounts
* Transaction history
* Interest calculation
* Fund transfer between accounts
* Account search by customer name
* Input validation
* Graphical User Interface (GUI)

---

## 📖 Summary

This project is a console-based banking application that simulates basic banking operations while demonstrating important C++ concepts. It provides persistent storage using file handling, efficient account management using the STL `map`, and robust error handling through exceptions, making it an excellent beginner-to-intermediate C++ project.
