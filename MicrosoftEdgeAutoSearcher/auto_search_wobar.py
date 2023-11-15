import cv2
import numpy as np
import pyautogui
import time
import random
import subprocess

def random_typing():
    characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_+"
    return random.choice(characters)

def find_search_bar():
    screenshot = pyautogui.screenshot()
    screenshot_np = np.array(screenshot)
    screenshot_rgb = cv2.cvtColor(screenshot_np, cv2.COLOR_BGR2RGB)

    lower_bound = np.array([250, 250, 250], dtype=np.uint8)
    upper_bound = np.array([255, 255, 255], dtype=np.uint8)

    mask = cv2.inRange(screenshot_rgb, lower_bound, upper_bound)
    contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    if contours:
        largest_contour = max(contours, key=cv2.contourArea)
        x, y, w, h = cv2.boundingRect(largest_contour)
        return x, y, x + w, y + h

    return None

def main():
    subprocess.Popen(["C:\\Program Files (x86)\\Microsoft\\Edge\\Application\\msedge.exe", "https://www.bing.com"])
    time.sleep(2)

    search_bar_coords = find_search_bar()

    print(search_bar_coords)
    pyautogui.moveTo(int((search_bar_coords[0]+search_bar_coords[2])/2), int((search_bar_coords[1]+search_bar_coords[3])/2), duration=2)
    pyautogui.click()

    text_to_type = random_typing()
    pyautogui.typewrite(text_to_type, interval=0.1)
    pyautogui.press('enter')
    time.sleep(random.uniform(3, 4))

    fixed_position_pc = (500, 150)
    fixed_position_mobile = (600, 200)
    fixed_position = fixed_position_pc

    search_counter = 35
    counter = 0

    print("Searching...")

    try:
        while counter < search_counter:
            pyautogui.moveTo(*fixed_position, duration=0.1)
            pyautogui.click()
            text_to_type = random_typing()
            pyautogui.typewrite(text_to_type, interval=0.1)
            pyautogui.press('enter')
            time.sleep(random.uniform(3, 4))
            counter += 1

    except KeyboardInterrupt:
        print("\nScript terminated by user.")

    pyautogui.press('F12')
    time.sleep(4)

    fixed_position = fixed_position_mobile
    search_counter = 25
    counter = 0

    try:
        while counter < search_counter:
            pyautogui.moveTo(*fixed_position, duration=0.1)
            pyautogui.click()
            text_to_type = random_typing()
            pyautogui.typewrite(text_to_type, interval=0.1)
            pyautogui.press('enter')
            time.sleep(random.uniform(3, 4))
            counter += 1

    except KeyboardInterrupt:
        print("\nScript terminated by user.")

    print("Searches finished! Goodbye")

if __name__ == "__main__":
    main()
