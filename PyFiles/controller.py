import time
import threading
import pyautogui
from pynput import keyboard

MOVE_SPEED = 20
SLOW_DOWN = .25
TICK = 0.0003

pressed = set()
state_lock = threading.Lock()


def moveloop():
    while True:
        with state_lock:
            keys = set(pressed)

        speed = MOVE_SPEED
        dx = dy = 0
        if keyboard.Key.shift_l in keys:
            speed = (MOVE_SPEED * SLOW_DOWN)
        
        if keyboard.Key.left in keys:
            dx -= speed
        if keyboard.Key.right in keys:
            dx += speed
        if keyboard.Key.up in keys:
            dy -= speed
        if keyboard.Key.down in keys:
            dy += speed

        if dx or dy:
            pyautogui.moveRel(dx, dy)

        time.sleep(TICK)


def on_press(key):
    with state_lock:
        pressed.add(key)


def on_release(key):
    with state_lock:
        pressed.discard(key)
    if key == keyboard.Key.esc:
        return False


if __name__ == "__main__":
    t = threading.Thread(target=moveloop, daemon=True)
    t.start()

    with keyboard.Listener(on_press=on_press, on_release=on_release) as listener:
        listener.join()
