from selenium import webdriver
import time

a = int(5)
b = int(4)
browser = webdriver.Chrome()
browser.get("https://www.google.com")
time.sleep(2)
browser.quit()

print("\n")
print(a, " + ", b, " = ", a+b)
print("\n")