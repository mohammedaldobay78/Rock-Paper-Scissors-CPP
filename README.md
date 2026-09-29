# Rock, Paper, Scissors Game (C++)

A clean, modular console-based implementation of the classic **Rock, Paper, Scissors** game built in C++.

> This project is the practical implementation of **Project 1** from **Course 05 (Algorithms & Problem Solving Level 2)** presented by **Dr. Mohammed Abu-Hadhoud** (ProgrammingAdvices). It demonstrates the transition from basic scripting to writing clean, modular, and procedural C++ code.

---

## 🎮 Features

- **Custom Rounds:** Choose how many rounds you want to play per session (1–10).
- **Randomized AI:** Computer moves are pseudo-randomly generated using seed initialization (`srand`).
- **Score Tracking:** Tracks Player wins, Computer wins, and Draws throughout each match.
- **Game Summary:** Displays an end-game score table declaring the overall winner.
- **Replayability:** Option to start a new match immediately without restarting the program.

---

## 🛠️ Architecture & Clean Code

- **Modular Design:** Divided into focused functions/procedures, adhering to the Single Responsibility Principle.
- **Pass-by-Reference:** Efficient state management using references (`int&`) to update match statistics.
- **Enumerations (`enum`):** Strongly typed choices (`Paper`, `Stone`, `Scissor`) and match results (`Win`, `Loss`, `Drow`).
- **Clean Game Loop:** The `main()` function only initializes the seed and launches the game engine.

---

## 🚀 Getting Started

### Prerequisites

- A C++ compiler supporting C++11 or higher (e.g., MSVC, GCC, Clang).
- (Optional) Visual Studio or any preferred IDE/text editor.

### Build and Run

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/mohammedaldobay78/Rock-Paper-Scissors-CPP.git](https://github.com/mohammedaldobay78/Rock-Paper-Scissors-CPP.git)
   cd Rock-Paper-Scissors-CPP

```

2. **Compile using g++:**
```bash
g++ -o PRS_Game PRS_Game.cpp

```


3. **Run the executable:**
* **Windows:**
```bash
.\PRS_Game.exe

```


* **Linux / macOS:**
```bash
./PRS_Game

```


---

## 🕹️ How to Play

1. Enter the total number of rounds.
2. For each round, choose your move:
* `[1]` Paper
* `[2]` Stone (Rock)
* `[3]` Scissor


3. View the outcome of each round and the final match summary.
4. Type `y` to play again or `n` to exit.

---

## 👨‍🏫 Instructor & Credits

Developed as part of the software engineering roadmap provided by **Dr. Mohammed Abu-Hadhoud**.

[![YouTube Channel](https://img.shields.io/badge/YouTube-ProgrammingAdvices-FF0000?style=for-the-badge&logo=youtube&logoColor=white)](https://www.youtube.com/@ProgrammingAdvices)
