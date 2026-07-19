# SDL2 Custom Graphics Engine & Editor Sandbox
## Post-Mortem Engineering Log & Architectural Troubleshooting Guide

This log serves as a permanent reference for the low-level systems and graphics programming hurdles resolved during the initial bootstrapping of the custom SDL2 text editor environment. Refer to this documentation to prevent regressions and lock in core environmental configurations.

---

## 🎨 The Signature Theme: Deep Ocean Teal
After rigorous hex-blitting experimentation, the optimal dark-mode aesthetic for the text editor background was isolated:

*   **Hex Code:** `0x0F647A`
*   **Hardware Mapping Layout (32-bit standard):**
    *   **Red (R):** `0x0F` (15 / 255) — Provides a subtle, deep warmth to prevent harsh backlighting.
    *   **Green (G):** `0x64` (100 / 255) — A muted, earthy forest green base.
    *   **Blue (B):** `0x7A` (122 / 255) — A prominent, cool steel-blue anchor.

This combination achieves a premium, eye-strain-resistant slate-teal environment perfect for long-duration terminal focus and text manipulation.

---

## 🛠️ Core Pitfalls & Architectural Solutions

### 1. OS Event Starvation (The Window Heartbeat)
*   **The Trap:** Spawning a graphical window frame and running a sequential execution loop (like standard `scanf` or `SDL_Delay`) without polling the window manager causes the screen to freeze, turn transparent, or flag a "Not Responding" status.
*   **The Sub-System Reality:** Modern operating systems require graphical applications to constantly communicate with the display server (X11/Wayland). If the application doesn't read incoming messages, the OS assumes the process is dead.
*   **The Fix:** Call `SDL_PumpEvents()` or run a robust `SDL_PollEvent` loop on every single state change. This flushes the internal queue, signs off on the window manager's health checks, and forces immediate pixel frame buffer updates.

### 2. Input Stream Buffer Cascade (Standard Input Traps)
*   **The Trap:** Using `scanf("%d", &color)` to read alphanumeric hex values (like `fff00`) causes `scanf` to reject the text completely. Because the non-decimal characters are rejected, they remain trapped inside the standard input buffer (`stdin`), causing all subsequent loop inputs to fail instantly without blocking.
*   **The Sub-System Reality:** `scanf` format specifiers strictly govern how data is stripped from the keyboard buffer. `%d` expects base-10 integers only.
*   **The Fix:** 
    1. Shift the scanner formatting string to **`%x`**, instructing the C runtime allocator to parse incoming text as base-16 hexadecimal structures.
    2. Add a fallback character flush routine to clear the buffer completely in the event of an invalid entry.

### 3. Toolchain Isolation (Header Pathways)
*   **The Trap:** Using explicit or absolute system path strings like `#include </usr/include/SDL2/SDL_video.h>` breaks portability and isolates the compilation unit from related graphics macros, event handles, and data types.
*   **The Sub-System Reality:** GCC handles dependencies via include path search arrays configured by the developer or automated query engines.
*   **The Fix:** Rely entirely on the master header inclusion `#include <SDL2/SDL.h>` and wire up the compiler utilizing shell command substitution:
    ```bash
    gcc editor.c $(pkg-config --cflags --libs sdl2) -o sam
    ```

---

## 🚀 Reference Code Blueprint

Use this bulletproof baseline template when reopening the sandbox to resume building the visual layer:

```c
#include <stdio.h>
#include <SDL2/SDL.h>

int main(int argc, char* argv[]) {
    // 1. Initialize Video Hardware Interface
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Graphics initialization failure: %s\n", SDL_GetError());
        return -1;
    }

    // 2. Instantiate Main Window Frame
    SDL_Window *pwindow = SDL_CreateWindow(
        "sam_editor",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        899, 766,
        0
    );

    if (!pwindow) {
        fprintf(stderr, "Window creation failure: %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    // 3. Acquire Hardware Accelerated Window Surface
    SDL_Surface *window_surface = SDL_GetWindowSurface(pwindow);
    if (!window_surface) {
        fprintf(stderr, "Surface mapping failure: %s\n", SDL_GetError());
        SDL_DestroyWindow(pwindow);
        SDL_Quit();
        return -1;
    }

    // 4. Bind Signature Theme (Deep Ocean Teal: 0x0F647A)
    Uint32 default_theme = SDL_MapRGB(window_surface->format, 15, 100, 122);
    
    int running = 1;
    int execution_cycles = 5; // Define bounds for loop testing

    printf("Booting editor engine with custom Slate-Teal layout...\n");

    for (int i = 0; i < execution_cycles; i++) {
        unsigned int input_hex_color;
        printf("\n[Cycle %d/%d] Enter new background hex (e.g., 0F647A) or signature will hold: ", i + 1, execution_cycles);
        
        // Scan with hexadecimal capability
        if (scanf("%x", &input_hex_color) != 1) {
            // Flush corrupt stdin entries immediately to prevent cascades
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Parsing mismatch. Applying default signature style.\n");
            input_hex_color = 0x0F647A; 
        }

        // Map colors & Paint Canvas Buffer
        Uint32 active_color = (input_hex_color == 0x0F647A) ? default_theme : 
                              SDL_MapRGB(window_surface->format, 
                                         (input_hex_color >> 16) & 0xFF, 
                                         (input_hex_color >> 8) & 0xFF, 
                                         input_hex_color & 0xFF);

        SDL_FillRect(window_surface, NULL, active_color);
        
        // Push buffer bits to physical screen
        SDL_UpdateWindowSurface(pwindow);

        // Keep OS Window Manager connectivity alive
        SDL_PumpEvents();

        SDL_Delay(2500);
    }

    // 5. Clean Resource Demolition
    SDL_DestroyWindow(pwindow);
    SDL_Quit();
    
    printf("\nEngine closed cleanly. Post-mortem rules verified.\n");
    return 0;
}
```
