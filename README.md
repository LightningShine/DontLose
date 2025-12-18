# DontLose (DL) - Instant File Search Utility for Windows

[![Language](https://img.shields.io/badge/language-C%2B%2B-blue.svg)](https://isocpp.org/)
[![Platform](https://img.shields.io/badge/platform-Windows-0078D6.svg)](https://www.microsoft.com/windows)
[![License](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)

**DontLose (DL)** is a fast and lightweight command-line utility for Windows designed to recursively find files by name. If you're tired of the slow default search or complex commands, DL will become your go-to tool. Just type `DL <filename>` and instantly get a list of all matches in the current directory and its subfolders.

This utility is perfect for developers, system administrators, and anyone who works extensively with the command line and wants to save time.

---

### 🎬 Demo

https://github.com/user-attachments/assets/9cb08c8e-414a-42e2-bb24-097084aa2cce

---

### ✨ Key Features

*   **⚡ Lightning-Fast Search:** Recursively scans directories at high speed.
*   **🔎 Case-Insensitive:** It doesn't matter if you type `Document.txt` or `document`—DL will find it.
*   **🎨 Colored Output:** Results are highlighted for better readability: green for success, red for errors.
*   **🔗 Clickable Paths:** Outputs full file paths that become clickable in modern terminals (like Windows Terminal and VS Code).
*   **🚫 Safe & Secure:** The program safely skips directories it doesn't have permission to access, avoiding permission errors.

---

### 🚀 Installation

You can install **DontLose** in two ways: automatically (not created yet) or manually.

#### Manual Installation (Adding to PATH)

If you prefer to have full control, follow these steps:

1.  **Create a Folder:** Create a dedicated folder on your drive to store the utility, for example: `C:\Tools\DL`.
2.  **Copy the File:** Copy `DontLose.exe` into the folder you just created and rename it to `DL.exe`.
3.  **Open Environment Variables Settings:**
    *   Press `Win + R` and type "sysdm.cpl".
    *   In the window that opens, click the "Environment Variables..." button.
4.  **Edit the `Path` Variable:**
    *   In the "User variables" section (the top box), find and select the `Path` variable.
    *   Click "Edit...".
5.  **Add the New Path:**
    *   Click "New".
    *   Paste the path to your folder (e.g., `C:\Tools\`).
6.  **Save Changes:** Click "OK" on all the windows you opened.
7.  **Restart Your Terminal:** Just like with the automatic method, close and reopen any command prompt windows.

You are now ready to go!

---

### 💻 How to Use

Once installed, you can call the utility from any directory.

**To find a file:**
### 💻 How to Use

Once installed, you can call the utility from any directory.


### 🛠️ Building from Source

This is a Visual Studio project.

1.  Clone the repository: `git clone https://github.com/LightningShine/DontLose.git`
2.  Open the `DontLose.sln` file in Visual Studio.
3.  Select your build configuration (e.g., `Release`).
4.  Press `F7` or go to `Build > Build Solution`.
5.  The `DontLose.exe` executable will be located in the `x64\Release` folder (or similar).

---

### 📜 License

This project is licensed under the MIT License. See the `LICENSE` file for details.# DontLose
