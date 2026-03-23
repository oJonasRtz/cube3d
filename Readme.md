<p align="center">
  <img src="https://github.com/ayogun/42-project-badges/raw/main/covers/cover-cub3d.png" alt="Cub3D cover" width="100%">
</p>

<h1 align="center">
  <a href="https://github.com/fernandoruanb/cub3d">
    <img src="https://github.com/ayogun/42-project-badges/raw/main/badges/cub3dm.png" alt="Cub3D badge" width="200">
  </a>
  <br>
  Cub3D
  <br>
</h1>

<h4 align="center">
  A raycasting project built in <a href="https://www.c-language.org/" target="_blank">C</a>, inspired by Wolfenstein 3D, focused on DDA, textures, map validation, and the illusion of 3D inside a 2D world.
</h4>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c" alt="Language C">
  <img src="https://img.shields.io/badge/Graphics-Raycasting-blueviolet?style=for-the-badge" alt="Raycasting">
  <img src="https://img.shields.io/badge/Status-Completed-brightgreen?style=for-the-badge" alt="Status Completed">
  <img src="https://img.shields.io/badge/Build-Makefile-lightgrey?style=for-the-badge" alt="Build Makefile">
</p>

<p align="center">
  <a href="#about-the-project">About</a> •
  <a href="#core-idea">Core Idea</a> •
  <a href="#map-validation">Map Validation</a> •
  <a href="#how-dda-works">How DDA Works</a> •
  <a href="#textures-colors-and-rendering">Textures, Colors & Rendering</a> •
  <a href="#possible-problems-and-bug-prevention">Bug Prevention</a> •
  <a href="#how-to-use">How To Use</a> •
  <a href="#team">Team</a>
</p>

---

## About the Project

**Cub3D** is a raycasting engine that creates the illusion of a 3D world from a 2D map using ray casting.

While the map itself still exists in **2D**, the project creates the **illusion of a 3D world** by using **raycasting**.  
That means the player is not walking inside a real 3D environment with true volumetric geometry, but inside a 2D map that is rendered in a way that visually simulates depth.

This is exactly what makes the project so interesting.

Inspired by the classic **Wolfenstein 3D**, the project introduces the idea that by casting rays, measuring distances, and projecting wall slices on screen, we can make a flat map feel like a real first-person world.

At the center of this illusion is the **DDA algorithm**, which allows the engine to move through the map grid efficiently and discover exactly where each ray collides with a wall.

**Core features implemented:**

- `.cub` parsing and validation with flood-fill
- Texture loading (`NO`, `SO`, `WE`, `EA`) from `.xpm`
- Floor/Ceiling RGB colors (`F`, `C`)
- Player spawn + orientation (`N`, `S`, `E`, `W`)
- Wall collision and movement (`W`, `A`, `S`, `D`)
- Rotation with arrow keys + mouse look
- Minimap with FOV and radius rendering
- Framebuffer-based rendering (off-screen buffer with single blit)
- FPS cap via frame pacing in `fps_control`
- Shadow/shading on wall sides for depth perception
- Texture projection according to wall orientation

More than just drawing walls, **Cub3D** becomes a project about:

- graphics programming
- heavy validation
- movement logic
- collision handling
- texture projection
- color parsing
- player orientation
- performance and visual stability

---

## Core Idea

The core idea of **Cub3D** is simple in theory:

- the world is a **2D map**
- the player has a **position** and a **direction**
- the engine casts rays forward across the screen
- each ray finds the distance to the nearest wall
- walls are drawn taller or shorter depending on that distance

That difference in wall height is what creates the sensation of **depth**.

So even though the map is not 3D, the player experiences it as if walking inside a three-dimensional maze.

This is why raycasting is such a beautiful concept:
it transforms a flat world into a first-person visual simulation.

---

## Tech Stack

- Language: C
- Graphics: MiniLibX (Linux variant)
- Build system: Makefile
- Utility library: custom `libft`
- Algorithm: DDA (Digital Differential Analyzer)
- Rendering: Framebuffer-based with hardware-accelerated blit

---

## Project Layout

```text
cube3d/
├── CUB3D_OFFICIAL/
│   ├── includes/              # headers (game structs, validation, render, input)
│   │   ├── cub3d.h
│   │   ├── structs.h
│   │   ├── dda.h
│   │   ├── ray_cast.h
│   │   ├── validation.h
│   │   ├── window.h
│   │   └── mouse.h
│   ├── srcs/
│   │   ├── cub3d/             # entrypoint + cleanup
│   │   ├── init_game/         # parsing, extraction, init of game state
│   │   ├── validation/        # security and map checks
│   │   ├── dda/               # DDA ray steps
│   │   ├── ray_cast/          # movement and camera plane
│   │   ├── the_cub_3d_powered/ # 3D rendering + textures
│   │   ├── set_window/        # events and loop
│   │   ├── free_game/         # cleanup and memory management
│   │   └── bonus/             # minimap and helper visuals
│   ├── maps/                  # valid and invalid sample maps
│   ├── images/                # `.xpm` textures and assets
│   ├── minilibx-linux/        # graphics library
│   ├── libft/                 # custom utility library
│   ├── Makefile
│   └── cub3d                  # compiled binary
└── Readme.md
```

---

## Map Validation

One of the first lessons that becomes obvious in a game project is this:

**a single validation failure can create a visible anomaly**.

And because of that, **Cub3D** requires a large amount of careful validation before the engine can even begin rendering.

The map may have:

- irregular shapes
- separated areas
- isolated islands
- diagonal structures
- open spaces that look harmless but actually break the game

That means validation cannot be superficial.

### Player validation

The player must appear correctly depending on the spawn marker present in the map.

The orientation can be:

- `N` for North
- `S` for South
- `W` for West
- `E` for East

Depending on which marker exists, the player must spawn at the right position and already be facing the correct initial direction.

### Structural validation

Much like **so_long**, the accessible play area must be fully protected.

It must never be possible for the player to reach a position that escapes the valid boundaries of the map.

So every accessible floor area must be checked carefully using **flood-fill**.

The player must also be prevented from spawning or moving into invalid regions such as:

- internal spaces
- tabs
- malformed gaps
- undefined cells

This becomes especially important in irregular maps, because a map does not need to be a perfect rectangle to be valid, but it must still be **closed where it matters**.

### File validation

The map file must also be validated by extension.

A useful detail here is that a file like:

```text
anything........cub
```

is still valid because it truly ends with `.cub`.

A classic way to validate that is by using something like `ft_strrchr()` to find the last `.` and check the suffix from that point onward.

### Color validation

The map also contains configuration for visual elements such as:

* ceiling color
* floor color
* wall textures

If a color component is smaller than `0` or larger than `255`, the map becomes invalid immediately.

In this implementation, custom functions extract the values and convert them into hexadecimal, which is appropriate when assembling the final color value used to write pixels on screen.

---

## How DDA Works

The **DDA (Digital Differential Analyzer)** algorithm is one of the most important parts of **Cub3D**.

Without it, the raycasting would be much less reliable and far more difficult to manage.

### Why DDA is needed

When a ray is cast from the player into the world, we need to know:

* where that ray goes
* which wall it hits first
* whether it hit a vertical or horizontal side
* how far that wall is from the player

A naive approach would be to move forward little by little and keep checking collisions.

But that would be inefficient and unstable.

Instead, DDA advances through the **grid cell by cell**, in a smart and structured way.

### The intuition

Imagine the map as a grid of squares.

The player stands somewhere inside one square.

For each vertical stripe of the screen, the engine casts one ray.

That ray has a direction.

Now the engine asks:

* how far is the next vertical grid line?
* how far is the next horizontal grid line?

Then it compares both distances.

Whichever one is smaller is the next boundary the ray will cross.

So the algorithm jumps directly to the next map cell instead of moving pixel by pixel through space.

### The DDA process

For each ray, the logic is essentially:

1. define the ray direction
2. determine the current map cell where the player is
3. calculate the distance needed to cross one grid cell on X and Y
4. calculate the first side distances
5. choose whether the next step will be in X or Y
6. move to the next cell
7. check if that cell is a wall
8. repeat until a wall is found

That repetition is the DDA loop.

### Why it is powerful

This method gives us precise information about:

* the exact wall hit
* the side that was hit
* the correct distance to use for projection

And that distance is what determines the wall height on screen:

* closer wall → taller slice
* farther wall → smaller slice

That is the visual heart of the fake 3D effect.

### Why side detection matters

DDA also tells us whether the wall hit was on:

* a vertical side
* or a horizontal side

This matters a lot because it allows us to:

* choose the correct wall texture
* apply light and shadow differences
* avoid visual inconsistencies

For example, in this implementation, one side of the wall is rendered slightly darker than the other to reinforce depth perception.

### Common problems if DDA is wrong

If the DDA calculations are not correct, many visual problems appear immediately:

* saw-like wall distortion
* broken wall edges
* gaps between walls
* seeing through borders
* incorrect wall proportions
* unstable collision perception

That is why understanding DDA is not optional in **Cub3D**.

It is the engine's core geometric logic.

---

## Textures, Colors and Rendering

After the map is validated, the project becomes heavily focused on rendering.

The engine must parse and use:

* wall textures (`.xpm` files)
* floor color
* ceiling color

The images are loaded, their pixel data is extracted, and then pixels are drawn to the screen during the raycasting pass.

That means the project is not just about finding walls, but also about **painting them correctly**.

### Framebuffer-Based Rendering

The 3D renderer uses an **off-screen framebuffer** created by `mlx_new_image()`:

- Pixel colors are written directly to `frame.addr` during the raycasting pass
- The frame is cleared once per tick using `ft_memset()`
- After all columns are rendered, the buffer is presented with a single `mlx_put_image_to_window()` call
- This replaces drawing pixels one-by-one directly to the window, improving performance and visual stability

### FPS Control

Frame pacing is handled by `fps_control()`:

- Uses `gettimeofday()` to measure elapsed time
- Sleeps in short intervals (`usleep(100)`) until the target frame duration is reached
- Respects a target FPS while preventing excessive CPU usage
- Calls `render_the_3d()` after frame pacing ensures stable visual refresh

### Texture Projection

Another interesting point is that DDA helps determine which wall side was hit:

* north
* south
* east
* west

With that information, the engine can choose the correct texture for that wall and create a more coherent visual experience.

In this implementation:

* Textures are stored as XPM images with pixel data extracted
* Wall slices are drawn column-by-column based on ray distance
* Colors are sampled from textures according to wall position
* Light and shadow behavior is applied per side for depth

---

## Rendering Pipeline

```mermaid
flowchart TD
	A[mlx loop hook] --> B[handle_no_event]
	B --> C[fps_control - wait for 1/FPS]
	C --> D[render_the_3d - main render pass]
	D --> E[for each screen column x]
	E --> F[init ray + DDA algorithm]
	F --> G[compute perpendicular distance]
	G --> H[calculate wall height]
	H --> I[draw ceiling strip]
	I --> J[draw textured wall slice]
	J --> K[draw floor strip]
	K --> L[write pixels to framebuffer]
	L --> M[mlx_put_image_to_window]
	M --> N[draw mouse target overlay]
	N --> O[loop to next frame]
```

---

## Possible Problems and Bug Prevention

**Cub3D** is one of those projects where many small mistakes can become very visible.

Some of the problems that may appear are:

* accessing invalid positions in memory
* incorrect ray calculation causing saw-shaped walls
* broken wall rendering
* visible borders exposing what should be hidden
* wrong wall proportions
* slow or inaccurate player movement
* incorrect spawn position
* wrong initial orientation
* the player being partially inside a wall
* attempts to cross invalid borders
* framebuffer not initialized before rendering
* invalid memory writes in texture projection

Because this is a first-person experience, even a small bug can strongly affect the player's perception.

That is why game validation is much more than checking whether the program compiles.

It is about protecting the logic of the simulation.

---

## How To Use

### Build

From the repository root:

```bash
cd CUB3D_OFFICIAL
make
```

### Run

Execute the program with a valid map:

```bash
./cub3d maps/example.cub
```

The engine will load:

* the map
* the player position
* the textures
* the floor and ceiling colors

After that, the game window opens and the player can explore the map from a first-person perspective.

### Make Targets

```bash
make        # build cub3d
make clean  # remove object files
make fclean # clean + remove binary
make re     # rebuild from scratch
make run    # build and run with valgrind (debug)
```

---

## Controls

- `W` / `A` / `S` / `D`: move forward/left/backward/right
- `Left Arrow` / `Right Arrow`: rotate camera
- `Mouse`: rotate camera (mouse is hidden and re-centered)
- `ESC`: exit

---

## `.cub` Format

### Expected elements:

- `NO path_to_north_texture.xpm`
- `SO path_to_south_texture.xpm`
- `WE path_to_west_texture.xpm`
- `EA path_to_east_texture.xpm`
- `F R,G,B` floor color (0..255 each)
- `C R,G,B` ceiling color (0..255 each)
- Map grid using: `1` wall, `0` empty, `N/S/E/W` player spawn

### Validation rules:

- Input file must end with `.cub`
- Textures must use `.xpm`
- Duplicate texture/color declarations are rejected
- Exactly one player is required
- Invalid characters are rejected
- Flood-fill is used to reject open maps/leaks
- All texture files must exist and be valid XPM format
- RGB values must be in range [0, 255]

### Example:

```text
NO ./images/block.xpm
SO ./images/ruins.xpm
WE ./images/brickWall.xpm
EA ./images/wall1.xpm

F 50,10,50
C 0,0,100

1111111111
1000000001
1000E00001
1000000001
1111111111
```

---

## Team

**Cub3D** was developed as part of the 42 curriculum learning journey through graphics, validation, and raycasting.

**Contributors:**

- `fruan-ba`
- `jopereir`

---

## Final Note

**Cub3D** is much more than a graphics project. It demonstrates:

* transforming a 2D map into a 3D visual experience
* the practical power of the DDA algorithm
* validating complex map structures rigorously
* handling collisions and movement carefully
* extracting and projecting textures correctly
* managing memory safely in a performance-critical renderer
* framebuffer management for visual stability

What makes **Cub3D** special is that it shows how much can emerge from relatively simple building blocks:

A 2D grid.
A player position.
A direction vector.
A set of rays.
A distance calculation.

And from that, an entire interactive world appears.
