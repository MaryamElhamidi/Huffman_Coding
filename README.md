# Huffman Coding using Binary Trees 🌲📦

This project implements Huffman Coding in C++, a lossless data compression algorithm that assigns variable-length binary codes to characters based on their frequency of occurrence.

Developed as a group assignment for **Data Structures** at **Sheridan College**.

---

## 🛠 Features

* Build Huffman Tree using a priority queue (min-heap)
* Generate prefix-free binary codes for characters
* Encode text from a user-input file
* Decode encoded data to restore original text
* Verify decoding accuracy
* Print character codes and encoded/decoded results

---

## 🚀 How to Run

### 1. Clone the Repository

```bash
git clone https://github.com/MaryamElhamidi/Assignment_3_Group_MHJ.git
cd Assignment_3_Group_MHJ
```

### 2. Compile the Program

Make sure you have a C++ compiler (like `g++`) installed.

```bash
g++ main.cpp file_handling.cpp huffman_tree.cpp huffman_encoding.cpp -o huffman
```

### 3. Run the Program

```bash
./huffman
```

You'll be prompted to enter the full path of the input `.txt` file.

---

## 📂 File Structure

* `main.cpp` – Runs program, manages I/O, encoding, decoding
* `file_handling.*` – File reading/writing, error handling
* `huffman_tree.*` – Huffman Tree node structure & construction logic
* `huffman_encoding.*` – Encoding and decoding using tree traversal

---

## 🧪 Sample Output

```
Please input file name:
input.txt

Huffman Codes:
Character	Code
A           0
B           10
C           11

Encoded Text: 0100110
Decoded Text: ABC

Encoding and Decoding successful!
```

---

## ⌛ Complexity Summary

| Operation              | Time Complexity |
| ---------------------- | --------------- |
| Build Huffman Tree     | O(n log n)      |
| Generate Huffman Codes | O(n)            |
| Encode & Decode Text   | O(n log n)      |
| File Read/Write        | O(n)            |

---

## 👩‍💻 Team Members

* **Maryam Elhamidi** – Encoding logic, file handling, compiler/debugging fixes, README
* **Harsheta Sharma** – Huffman Tree construction, priority queue logic, complexity analysis
* **Janki Patel** – File I/O, decoding, program integration, testing

---

## ⚠️ Notes

* If file path errors occur, try hardcoding the path inside `main.cpp`.
* Place test files in the same folder as the executable for easiest access.
* This project was developed on different environments (Windows/macOS), so behavior may vary slightly.

---

## 📌 License

This project was created for academic use only and is not licensed for commercial distribution.

---

You can now copy this directly into your `README.md` file in GitHub or your local repo. Let me know if you want me to tailor it more or add screenshots, badges, or links!
