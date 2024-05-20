greet = input("Greeting: ")

if "hello" in greet.lower():
    print("$0")
elif greet[0].lower() == "h":
    print("$20")
else:
    print("$100")
