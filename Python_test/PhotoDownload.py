import csv
from selenium import webdriver
from selenium.common.exceptions import NoSuchElementException
from selenium.common.exceptions import NoSuchWindowException
from selenium.common.exceptions import WebDriverException
from selenium.webdriver.support.ui import Select



with open('PhotoLink.csv', newline='') as csvfile:
    data = list(csv.reader(csvfile))

import urllib.request

for i in range(0, 246):
    #print(data[i][2])
    name = str(i) + ".jpg"
    urllib.request.urlretrieve(data[i][2], name)