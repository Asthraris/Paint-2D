# 🎨 PikaDraw – Minimalist Cross-Platform Drawing App

PikaDraw is a **lightweight**, **cross-platform** 2D drawing application built using [raylib](https://www.raylib.com/). It emphasizes simplicity, speed, and smooth brush-based drawing — making it ideal for quick sketching, digital whiteboarding, or low-latency creative work.

---

## ✨ Features

- 🖌️ **Smooth Freehand Drawing** with continuous brush stroke interpolation  
- 🎨 **Color Picker**: Hold `C` to select from predefined color swatches  
- 🔁 **Canvas Reset**: Press `R` to instantly clear the canvas  
- 🔍 **Zoom & Pan**:
  - Hold `Ctrl` + scroll to zoom
  - Middle mouse drag to pan  
- 🧠 **Context Help**: Hold `Space` to show built-in control guide  
- 📸 **Screenshot Export**: Press `S` to save canvas as PNG with timestamp  
- ⚙️ **Brush Preview Cursor**: Always-visible pointer reflecting brush size & color  
- 💡 **Lightweight & Fast**: Minimal dependencies, instant load, and low resource usage  

---

## ⌨️ Controls

| Key / Action              | Function                         |
|---------------------------|----------------------------------|
| `Left Click`              | Draw with brush                  |
| `C` (hold)                | Show color picker                |
| `Click color`             | Select brush color               |
| `R`                      | Reset/clear canvas               |
| `Shift`                  | Adjust brush size                |
| `Ctrl + Scroll`          | Zoom in/out                      |
| `Middle Mouse Drag`      | Pan camera                       |
| `S`                      | Save canvas screenshot (PNG)     |
| `Space` (hold)           | Show help menu                   |
| `ESC`                    | Exit application                 |

---

## 🖼️ Screenshot Example

![Screenshot Placeholder](.screenshot.png)  
> Output files saved as `canvas_YYYY-MM-DD_HH-MM-SS.png`

---

## 📦 Building From Source

### Requirements:
- C++ compiler (GCC / Clang / MSVC)
- [raylib](https://github.com/raysan5/raylib) installed (v4.5+ recommended)

### Example (GCC / Linux):

```bash
g++ main.cpp Canvas.cpp Brush.cpp -o PikaDraw -lraylib -lGL -lm -ldl -lpthread -lrt -lX11
./PikaDraw
````

---

## 🔭 Roadmap

* 🖌️ More advanced brushes (texture, spray, gradient)
* 🖼️ Canvas resize and rescale support
* 💾 Manual save/load projects
* 🌈 HSV or palette-based color selector
* 🧠 Brush history / undo-redo
* 🪟 Export with transparent background (PNG alpha)

---

## ⚙️ Tech Stack

* Language: **C++**
* Framework: **[raylib](https://www.raylib.com/)** — a minimalist C library for graphics and input
* Built with: simplicity, speed, and full offline support in mind

---

## 📃 License

MIT License – use freely for personal, academic, or commercial projects.

---

## 🙌 Author

**AMAN GUPTA**
Inspired by simplicity. Powered by code.


