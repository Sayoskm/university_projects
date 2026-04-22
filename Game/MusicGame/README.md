# MusicGame

## Overview

This is a **Java-based rhythm music game** implemented with **Java Swing**. The game challenges you to hit notes in time with the music, providing visual and audio feedback for your performance.

---

## Usage

1. Compile all Java files in the `src/LastSummer` and `src/Music_1` directories.
2. Ensure the `resource` folder (with images and music) is included in the classpath or copied to the correct output directory.
3. Run the main class:
   - `LastSummer.main` (entry point)
   - Example: `java -cp . LastSummer.main`
4. The game window will open. Follow the on-screen instructions to play.

---

## Features

* **Rhythm Gameplay** – Hit notes in time with the music for a high score.
* **Multiple Songs** – Easily add new tracks and backgrounds.
* **Visual Feedback** – Animated notes and backgrounds.
* **Audio Feedback** – Integrated music playback.
* **Customizable Resources** – Images and music can be replaced in the `resource` folder.
* **Simple UI** – Clean interface for easy play.

---

## Project Structure

- `src/LastSummer/` – Main game logic and UI classes
- `src/Music_1/` – Track and music management classes
- `src/resource/` – Images and music files used in the game

---

## Requirements

- Java 8 or above
- javazoom JLayer library (for MP3 playback)