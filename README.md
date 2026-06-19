# FdF — Fil de Fer

> A wireframe 3D terrain renderer with isometric projection, zoom, rotation, and mouse controls.

![Language](https://img.shields.io/badge/language-C-blue.svg)
![School](https://img.shields.io/badge/school-42%20Heilbronn-black.svg)
![Graphics](https://img.shields.io/badge/graphics-MiniLibX-orange.svg)
![Norm](https://img.shields.io/badge/norminette-passing-brightgreen.svg)

---

## About

**FdF** (French for *Fil de Fer* — "wireframe") reads a `.fdf` map file containing a grid of altitude values and renders it as a 3D wireframe mesh using an isometric projection. It is the introductory graphics project at 42, covering window management, pixel-level drawing, and 3D geometry.

---

## Features

- Reads `.fdf` map files with optional per-point hex colour values
- Isometric and top-down projection modes (togglable at runtime)
- Custom line drawing algorithm (DDA — no Bresenham)
- Per-pixel colour rendering directly into an MiniLibX image buffer
- Height-based automatic colouring (blue above zero, orange at/below zero)
- Full keyboard and mouse controls
- Validates map dimensions, file extension, integer values, and colour format
- Coloured error messages to stderr

---

## Structure

```
FdF/
├── fdf.h               # All structs, macros, and prototypes
├── main.c              # Entry point, window/image init, default values
├── read_file.c         # File parsing: get dimensions, parse each line into map
├── read_file_utils.c   # Validation, ft_malloc, colour trim helper
├── draw.c              # draw_map loop, draw_line, colour selection
├── draw_utils.c        # zoom, iso projection, color_pixel, push_img
├── key_hook.c          # Keyboard and mouse event handlers
├── error.c             # Error codes, memory cleanup, exit helpers
├── libft/              # Bundled libft (get_next_line, ft_split, ft_atoi, etc.)
└── minilibx_macos/     # MiniLibX (macOS)
```

---

## Requirements

- **macOS** (MiniLibX macOS version is bundled)
- Xcode Command Line Tools (`xcode-select --install`)

---

## Usage

### Build

```bash
make
```

### Run

```bash
./fdf test_maps/42.fdf
./fdf test_maps/mars.fdf
./fdf test_maps/elem-fdf.fdf
```

### Controls

**Keyboard**

| Key | Action |
|---|---|
| `ESC` | Exit |
| `↑ ↓ ← →` | Move map (pan) |
| `+` / `-` (numpad) | Zoom in / out |
| `[` / `]` (numpad) | Increase / decrease Z scale |
| Numpad `5` | Toggle isometric / top-down projection |
| Numpad `6` / `8` | Rotate angle |

**Mouse**

| Button | Action |
|---|---|
| Left click | Move map to click position |
| Middle click | Reset to default view |
| Right click | Toggle projection mode |
| Scroll up / down | Zoom in / out |

> Note: key codes are macOS-specific.

---

## Map Format

A `.fdf` map is a plain text grid of integers separated by spaces and newlines. Each integer is the altitude (z-value) of that point.

```
0  0  0  0  0
0  1  2  1  0
0  2  4  2  0
0  1  2  1  0
0  0  0  0  0
```

Per-point colours can be added with a `,0xRRGGBB` suffix:

```
0,0xFF0000  0,0x00FF00  0,0x0000FF
1,0xFFFFFF  2           1
```

Both `0xFF0000` and `FF0000` formats are accepted.

---

## Implementation

**Parsing** reads the file twice via `get_next_line` — first pass determines map dimensions and validates row widths, second pass fills the `t_point **map` 2D array with x, y, z, and colour values.

**Projection** is handled in `draw_utils.c`. The pipeline per line segment is: zoom → (optional) isometric transform → shift. The isometric formula used:
```
x' = (x - y) * cos(angle)
y' = (x + y) * sin(angle) - z
```

**Line drawing** uses the DDA algorithm — normalising the step vector by the longest axis so each pixel is visited exactly once.

**Rendering** writes directly to MiniLibX's image buffer via `color_pixel` rather than calling `mlx_pixel_put` per pixel, then flushes with `mlx_put_image_to_window`. The image is destroyed and recreated each frame for clean redraws.

**Colour** defaults to blue for positive altitude and orange for zero/negative. Per-point colours from the map file take priority over the defaults.

---

## Makefile Targets

| Target | Description |
|---|---|
| `make` / `make all` | Build `fdf` binary |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and binary |
| `make re` | `fclean` + `all` |

---

## Notes

- Written in compliance with the **42 Norm**.
- Bundled `minilibx_macos` — no external installation needed on macOS.
- Mouse controls and projection toggle are bonus features beyond the mandatory subject.

---

*42 Heilbronn — Core Curriculum*
