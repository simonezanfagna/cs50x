import sys
import random
from pyfiglet import Figlet

figlet = Figlet()

fonts = figlet.getFonts()

if len(sys.argv) == 1:
    text = input("Input: ")
    randomNumber = random.randint(0, len(fonts) - 1)
    figlet.setFont(font=fonts[randomNumber])
    print(figlet.renderText(text))

elif len(sys.argv) == 3 and (sys.argv[1] == "-f" or sys.argv[1] == "--font") and sys.argv[2] in fonts:
    text = input("Input: ")
    figlet.setFont(font=sys.argv[2])
    print(figlet.renderText(text))

else:
    sys.exit("Invalid usage")

