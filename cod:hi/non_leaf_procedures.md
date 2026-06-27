## Advanced Mechanics: Deep Nesting in Non-Leaf Functions

When a function invokes another function, it is classified as a **Non-Leaf Function**. If a non-leaf function calls a child, which calls a grandchild, across multiple layers, it creates a deeply nested chain of **Stack Frames** in physical RAM.

### The Architectural Problem: Managing `$ra` Across 6 Layers
The CPU has only **one** physical Link Register (`$ra`). When `Function_1` executes a Jump and Link (`jal`) to `Function_2`, the hardware overwrites `$ra` with the return vector to `Function_1`. 

If `Function_2` wants to call `Function_3`, it **must spill the current `$ra` value into its own RAM stack frame** before making the call. If it fails to do this, the tracking link back to the parent is obliterated, causing an infinite execution loop or a system crash.

---

## 6-Level Deep MIPS Assembly Implementation Blueprint

Below is the concrete implementation tracking a computational value passed down through 6 distinct operational layers before walking all the way back up to the main logic stream.

```assembly
.text
.globl main

# =============================================================================
# ENTRY POINT: Main Program
# =============================================================================
main:
    li   $a0, 10                # Load initial argument value = 10
    jal  function_1             # Call the first non-leaf function (PC+4 saved in $ra)
    
    # Execution returns here after all 6 layers unwind perfectly
    add  $s0, $zero, $v0        # $s0 now contains the fully calculated final value
    
    li   $v0, 10                # System call for exit
    syscall

# =============================================================================
# LAYER 1: Non-Leaf Function 1
# =============================================================================
function_1:
    addi $sp, $sp, -4           # Allocate 4 bytes on stack
    sw   $ra, 0($sp)            # Spill Layer 1 return address (points back to main)

    addi $a0, $a0, 1            # Logic: Increment argument (10 + 1 = 11)
    jal  function_2             # Call Layer 2 (Overwrites CPU $ra register)

    lw   $ra, 0($sp)            # Fill: Restore Layer 1 return address
    addi $sp, $sp, 4            # Deallocate stack frame
    jr   $ra                    # Return to main

# =============================================================================
# LAYER 2: Non-Leaf Function 2
# =============================================================================
function_2:
    addi $sp, $sp, -4           # Allocate 4 bytes on stack
    sw   $ra, 0($sp)            # Spill Layer 2 return address (points back to func_1)

    addi $a0, $a0, 1            # Logic: Increment argument (11 + 1 = 12)
    jal  function_3             # Call Layer 3 (Overwrites CPU $ra register)

    lw   $ra, 0($sp)            # Fill: Restore Layer 2 return address
    addi $sp, $sp, 4            # Deallocate stack frame
    jr   $ra                    # Return to function_1

# =============================================================================
# LAYER 3: Non-Leaf Function 3
# =============================================================================
function_3:
    addi $sp, $sp, -4           # Allocate 4 bytes on stack
    sw   $ra, 0($sp)            # Spill Layer 3 return address (points back to func_2)

    addi $a0, $a0, 1            # Logic: Increment argument (12 + 1 = 13)
    jal  function_4             # Call Layer 4 (Overwrites CPU $ra register)

    lw   $ra, 0($sp)            # Fill: Restore Layer 3 return address
    addi $sp, $sp, 4            # Deallocate stack frame
    jr   $ra                    # Return to function_2

# =============================================================================
# LAYER 4: Non-Leaf Function 4
# =============================================================================
function_4:
    addi $sp, $sp, -4           # Allocate 4 bytes on stack
    sw   $ra, 0($sp)            # Spill Layer 4 return address (points back to func_3)

    addi $a0, $a0, 1            # Logic: Increment argument (13 + 1 = 14)
    jal  function_5             # Call Layer 5 (Overwrites CPU $ra register)

    lw   $ra, 0($sp)            # Fill: Restore Layer 4 return address
    addi $sp, $sp, 4            # Deallocate stack frame
    jr   $ra                    # Return to function_3

# =============================================================================
# LAYER 5: Non-Leaf Function 5
# =============================================================================
function_5:
    addi $sp, $sp, -4           # Allocate 4 bytes on stack
    sw   $ra, 0($sp)            # Spill Layer 5 return address (points back to func_4)

    addi $a0, $a0, 1            # Logic: Increment argument (14 + 1 = 15)
    jal  leaf_function_6        # Call the final leaf layer

    lw   $ra, 0($sp)            # Fill: Restore Layer 5 return address
    addi $sp, $sp, 4            # Deallocate stack frame
    jr   $ra                    # Return to function_4

# =============================================================================
# LAYER 6: LEAF FUNCTION (The Terminal Node)
# =============================================================================
leaf_function_6:
    # OPTIMIZATION: Because this is a leaf function, it does NOT call another function.
    # Therefore, the CPU's $ra register is safe and will not be overwritten. 
    # We completely bypass allocating stack space and spilling $ra to RAM.

    addi $v0, $a0, 5            # Final calculation: Return value = $a0 + 5 (15 + 5 = 20)
    jr   $ra                    # Return directly to function_5 using unchanged hardware register
