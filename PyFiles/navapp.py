import time
import threading
import pyautogui
from pynput import keyboard

pyautogui.FAILSAFE = True  # move mouse to top-left corner to abort

# ---- Settings ----
MOVE_STEP = 12            # pixels per tick
TICK = 0.003               # seconds between movement updates
CTRL_DOUBLE_TAP_WINDOW = 0.35  # seconds to count as "double press"

active = False
pressed = set()
state_lock = threading.Lock()

last_ctrl_tap = 0.0

def toggle_active():
    global active
    with state_lock:
        active = not active
        print(f"[mousekeys] {'ON' if active else 'OFF'}")

def movement_loop():
    """Continuously moves the mouse while arrow keys are held, but only when active."""
    while True:
        with state_lock:
            is_active = active
            keys = set(pressed)

        if is_active:
            dx = dy = 0
            if keyboard.Key.left in keys:
                dx -= MOVE_STEP
            if keyboard.Key.right in keys:
                dx += MOVE_STEP
            if keyboard.Key.up in keys:
                dy -= MOVE_STEP
            if keyboard.Key.down in keys:
                dy += MOVE_STEP

            if dx or dy:
                
                pyautogui.moveRel(dx, dy)

        time.sleep(TICK)

def on_press(key):
    global last_ctrl_tap

    # Track pressed keys
    with state_lock:
        pressed.add(key)

    # Double-tap Ctrl to toggle
    if key in (keyboard.Key.ctrl_l, keyboard.Key.ctrl_r):
        now = time.time()
        if now - last_ctrl_tap <= CTRL_DOUBLE_TAP_WINDOW:
            toggle_active()
            last_ctrl_tap = 0.0  # reset to avoid triple-tap weirdness
        else:
            last_ctrl_tap = now

    # Space to click (only when active)
    if key == keyboard.Key.space:
        with state_lock:
            is_active = active
        if is_active:
            pyautogui.click()

def on_release(key):
    with state_lock:
        pressed.discard(key)

    # Optional: quit with Esc
    if key == keyboard.Key.esc:
        print("[mousekeys] Exiting...")
        return False

def main():
    # Start movement thread
    t = threading.Thread(target=movement_loop, daemon=True)
    t.start()

    print("[mousekeys] Running. Double-tap Ctrl to toggle ON/OFF. Esc to quit.")
    print("[mousekeys] While ON: Arrow keys move, Space clicks.")
    with keyboard.Listener(on_press=on_press, on_release=on_release) as listener:
        listener.join()
def on_press(key):
    with state_lock:
        pressed.add(key)


def on_release(key):
    with state_lock:
        pressed.discard(key)
    # optional: press Esc to quit
    if key == keyboard.Key.esc:
        return False


if __name__ == "__main__":
    t = threading.Thread(target=moveloop, daemon=True)
    t.start()

    with keyboard.Listener(on_press=on_press, on_release=on_release) as listener:
        listener.join()