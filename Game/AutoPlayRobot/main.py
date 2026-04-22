import pyautogui
from time import sleep

t = 1
tsleep = 4
url = "https://www.crazygames.com/game/wood-block-journey"
pyautogui.PAUSE = t

def drag_element(x1,y1,x2,y2):
    sleep(t)
    pyautogui.moveTo(x1,y1)
    pyautogui.mouseDown()
    pyautogui.moveTo(x2, y2)
    pyautogui.mouseUp()

def color_in_zone(color,wid,hgt,screenshot):
    for x in range(wid):
        for y in range(hgt):
            pixel = screenshot.getpixel((x, y))
            if is_color_similar(pixel, color):
                return False
    return True

def is_color_similar(color1, color2):
    return all(abs(a - b) <= 5 for a, b in zip(color1, color2))

def have_block(screenshot):
    for y in range(599):
        for x in range(249):
            pixel = screenshot.getpixel((x, y))
            if is_color_similar(pixel, (234,177,109)):
                return True,1670+x,620+y
    return False,0,0

def block_putted(block_x,block_y):
    screenshot = pyautogui.screenshot(region=((block_x,block_y, 20, 20)))
    pixel = screenshot.getpixel((0,0))
    if is_color_similar(pixel, (234,177,109)):
                return False
    return True

def check_picture(pic):
    try:
        location = pyautogui.locateOnScreen(pic, confidence=0.8)
        if location:
            return True
    except pyautogui.ImageNotFoundException:
        return False
# open the website
pyautogui.hotkey("win","r")
pyautogui.typewrite("chrome")
pyautogui.press("enter")
pyautogui.hotkey("ctrl","shift","n")

pyautogui.typewrite(url)
pyautogui.press("enter")

# start the game
sleep(tsleep)
pyautogui.click(1100, 1100)

# play 新手教學
sleep(tsleep)
drag_element(1745,693,1156,968)

drag_element(1745,719,994,1120)

drag_element(1759,734,1133,1050)

drag_element(1730,733,1136,1041)

# play game th rechieve 200
color = (234,177,109) #淺色
isGame = True
sleep(20)
while isGame:
    sleep(1)
    if (check_picture("failed.png")):
        pyautogui.click(1150, 1051)
        sleep(20)
    elif (check_picture("finish.png")):
        break
    screenshot = pyautogui.screenshot(region=((1670, 620, 250, 600)))
    isblock,block_x,block_y = have_block(screenshot)
    if (isblock):
        for i in range(9):
            for j in range(9):
                screenshot = pyautogui.screenshot(region=(830+j*80, 1240-i*80, 20, 20))
                wid,hgt = screenshot.size
                if (color_in_zone(color,wid,hgt,screenshot)):
                    drag_element(block_x,block_y,790+j*80,1280-i*80)
                if (block_putted(block_x,block_y)):
                    isblock=False
                    break
                sleep(0.2)
            if (not isblock): break





'''
規則:
先判斷是否還能繼續玩
if 出現廣告，按重來
if die again 按play
if rechieve 200  結束程式

遊戲過程:
找到深色區塊
由上往下檢查有沒有方塊可放

'''
