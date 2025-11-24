# Fractol 🎨

**Fractol** is a C project from the 42 curriculum that renders **fractal images** using the MiniLibX library.  
The goal is to display complex fractals like the Mandelbrot and Julia sets, allowing users to **zoom, pan, and explore fractal patterns interactively**.  

---

## 📚 Table of Contents
- [Extended Description](#extended-description)  
- [Installation & Make](#installation--make)  
- [Usage](#usage)  
- [Features](#features)  
- [License](#license)  

---

## 📝 Extended Description

Fractol teaches students the following concepts:

- **Fractal generation** – compute and render Mandelbrot and Julia sets using complex numbers.  
- **Graphics programming** – using MiniLibX to draw pixels efficiently in a window.  
- **User interaction** – zooming, panning, and real-time exploration of fractals.  
- **Mathematics** – understanding complex numbers, iteration, and escape-time algorithms.  
- **Modular code** – separating rendering, input handling, and math for maintainability.  

By completing Fractol, you gain experience in **low-level graphics, interactive programming, and mathematical visualization in C**.  

---

## 🛠 Installation & Make

Clone the repository and compile the project:

```bash
git clone https://github.com/algaboya/Fractol.git
cd Fractol
make
```
## ⚙️Usage

```bash
# Start the program
./fractol <fractal_name>
```
Runnig:
```
# Display the Mandelbrot set
./fractol mandelbrot

# Display the Julia set with custom parameters
./fractol julia <real_part> <imaginary_part>

# Example:
./fractol julia -0.7 0.27015
```
Controls:
```text
- Arrow keys: Move view
- Mouse scroll: Zoom in/out
- ESC: Exit
- Other keys may adjust colors or iterations depending on implementation
```

## 🔧 Features
```text
- Render Mandelbrot and Julia fractals
- Interactive zooming and panning
- Real-time updates while moving
- Customizable colors and iterations
- Modular and clean C code
```


## 📄License

This project is for educational purposes and follows the 42 school guidelines.
